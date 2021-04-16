#include <iostream>
#include <QApplication>
#include "mainwindow.h"

#include "ZorkUL.h"
using namespace std;
int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

ZorkUL::ZorkUL() {
	createRooms();
}

void ZorkUL::createRooms()  {
    Room *n1, *n2, *n3, *n2e, *n2w, *n2e2, *n2w2, *s1, *s2, *s1e, *e1, *e2, *e3, *e1s, *e1n, *e2n, *c1, *w1;

    //North Set
    n1 = new Room("n1");
        n1->addItem(new Item("x", 1, 11));
        n1->addItem(new Item("y", 2, 22));
    n2 = new Room("n2");
    n3 = new Room("n3");
    n2e = new Room("n2e");
    n2e2 = new Room("n2e2");
    n2w = new Room("n2w");
    n2w2 = new Room("n2w2");
    //South Set
    s1 = new Room("s1");
    s2 = new Room("s2");
    s1e = new Room("s1e");
    //East Set
    e1 = new Room("e1");
    e2 = new Room("e2");
    e3 = new Room("e3");
    e1s = new Room("e1s");
    e1n = new Room("e1n");
    e2n = new Room("e2n");
    //Centre
    c1 = new Room("c1");
    //West
    w1 = new Room("w1");

//             (N, E, S, W)
    // Centre
    c1->setExits(n1, NULL, s1, e1);
    // North Set
    n1->setExits(n2, NULL, c1, NULL);
    n2->setExits(n3, n2e, n1, n2w);
    n3->setExits(NULL, NULL, n2, NULL);
    n2e->setExits(NULL, NULL, n2e2, n2);
    n2e2->setExits(n2e, NULL, NULL, NULL);
    n2w->setExits(NULL, n2, n2w2, NULL);
    n2w2->setExits(n1, NULL, NULL, NULL);
    // South Set
    s1->setExits(c1, s1e, s2, NULL);
    s1e->setExits(NULL, NULL, NULL, s1);
    s2->setExits(s1, NULL, NULL, NULL);
    // East Set
    e1->setExits(e1n, e2, e1s, c1);
    e1s->setExits(n1, NULL, NULL, NULL);
    e1n->setExits(NULL, NULL, e1, e2n);
    e2->setExits(e2n, e3, NULL, e1);
    e2n->setExits(NULL, NULL, e2, e1n);
    e3->setExits(NULL, NULL, NULL, e2);
    // West
    w1->setExits(NULL, NULL, NULL, NULL);


        currentRoom = c1;
}

/**
 *  Main play routine.  Loops until end of play.
 */
QString ZorkUL::play(Command incommand) {
    QString output;
    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

    bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        Command command = Command(incommand);
        // Pass dereferenced command and check for end of game.
        output = processCommand(command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        finished = true;
    }
    return output;
}

void ZorkUL::printWelcome() {
	cout << "start"<< endl;
	cout << "info for help"<< endl;
	cout << endl;
	cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
QString ZorkUL::processCommand(Command command) {
    string output;
    if (command.isUnknown()) {
        output = output +"\nInvalid input";

    }
    string commandWord = command.getCommandWord();

    if (commandWord.compare("go") == 0)
       output = output + goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
            if (!command.hasSecondWord()) {
            output = output + "incomplete input";
            }
            else if (command.hasSecondWord()) {
            output = output + "you're trying to take " + command.getSecondWord();
            int location = currentRoom->isItemInRoom(command.getSecondWord());
            if (location  < 0 )
                output = output + "item is not in room";
            else {
                output = output + "item is in room";
                output = output + "index number " + to_string(location);
                output = output + currentRoom->longDescription();
            }
        }
    }
        else if(commandWord.compare("start")==0){
            printWelcome();
        }

    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            output = output +"\nOverdefined input";
    }

     QString qstr = QString::fromStdString(output);
     return qstr;
}

/** COMMANDS **/
void ZorkUL::printHelp() {
    string output;
    output = output + "valid inputs are; ";
    parser.showCommands();

}

string ZorkUL::goRoom(Command command) {
    string output;
    if (!command.hasSecondWord()) {
        output = output + "incomplete input";
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        output = output + "you cannot go this way";
    else {
        currentRoom = nextRoom;
        output = output + currentRoom->longDescription();
    }
    return output;
}

