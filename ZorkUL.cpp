#include <iostream>

using namespace std;
#include "ZorkUL.h"

int ma(int argc, char argv[]) {
	ZorkUL temp;
	temp.play();
    return 0;
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
void ZorkUL::play() {
	printWelcome();

	// Enter the main command loop.  Here we repeatedly read commands and
	// execute them until the ZorkUL game is over.

	bool finished = false;
	while (!finished) {
		// Create pointer to command and give it a command.
		Command* command = parser.getCommand();
		// Pass dereferenced command and check for end of game.
		finished = processCommand(*command);
		// Free the memory allocated by "parser.getCommand()"
		//   with ("return new Command(...)")
		delete command;
	}
	cout << endl;
	cout << "end" << endl;
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
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "[h] --- [f] --- [g]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
		cout << "[c] --- [a] --- [b]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
            cout << "index number " << + location << endl;
            cout << endl;
            cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
		if (command.hasSecondWord())
			cout << "overdefined input"<< endl;
		else
			return true; /**signal to quit*/
	}
	return false;
}
/** COMMANDS **/
void ZorkUL::printHelp() {
	cout << "valid inputs are; " << endl;
	parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
		return;
	}

	string direction = command.getSecondWord();

	// Try to leave current room.
	Room* nextRoom = currentRoom->nextRoom(direction);

	if (nextRoom == NULL)
		cout << "underdefined input"<< endl;
	else {
		currentRoom = nextRoom;
		cout << currentRoom->longDescription() << endl;
	}
}

string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
