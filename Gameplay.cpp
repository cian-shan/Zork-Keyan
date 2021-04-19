#include "Gameplay.h"

Gameplay::Gameplay()
{
    srand (time(0));
    createRooms();
}

QString Gameplay::printWelcome(string name) {
    string output =
           string("\nWelcome, ") + (name) + "!" +
           (this->currentRoom->longDescription());
    return QString::fromStdString(output);
}

void Gameplay::createRooms()  {
    Room *n1, *n2, *n3, *s1, *s2, *s3, *s4, *e1, *e2, *e3, *e4, *e5, *c1, *exit;

    c1 = new Room("c1 -- You stand in the middle of a damp room, lit by the sunlight emerging from a grate above you. There is an exit to the north, south and east of you. There is a noticeably large door to the east..", "NA");
                c1->addItem(new Food("Red Potion", 25, 0, 0));
                c1->addItem(new Food("Blue Potion", -15, 15, 0));
            n1 = new Room("n1 -- A humid heat hits you as you step into a room full of vegetation. There are exits to the north, west and south of the room.", "NA");
                n1->addItem(new Food("Purple Potion", -50, 50, 0));
                n1->addItem(new Food("Orange Potion", 40, 0, 0));
            n2 = new Room("n2 -- There is a lantern hanging on the other side of the room. There are 2 potions, Red and Blue on a table with a note reading 'Red Isn't Dead'", "NA");
                n2->addItem(new Food("Red Potion", 25, 0, 0));
                n2->addItem(new Food("Blue Potion", -15, 15, 0));
            n3 = new Room("n3 -- A writing mass of vines and bones writhes across the entirety of the floor in front of you, except for under the dimly lit torch at the other side of the room where a peculiar empty circle of floor remains. There is a key hanging at the other side of the room.", "NA");
                n3->addItem(new Food("Key", 0, 0, 1));
            e1 = new Room("e1 -- A loud cascade of pistons shakes the room and blood drips from the vents above. There is an exit to the west and north. ", "NA");
            e2 = new Room("e2 -- Blood filled pipes line the walls and a stench of rotting flesh invades your nostrils. There is a pale figure standing under a ceiling light, his grin stretches ear to ear as he notices your presence. There is an exit to the south and east.", "NA");
            e3 = new Room("e3 -- You stand in a white tiled room, illuminated by a light hanging from the ceiling. There is an exit to the west, south and north.", "NA");
            e4 = new Room("e4 -- The room that greets you with warmth as the soothing heat warms your body. There is a slingshot and a key hanging on the wall across from you. On a table you notice 2 potions, Red and Blue with a note reading 'Blues got a Flu' There is an exit to the south.", "NA");
                e4->addItem(new Food("Red Potion", 25, 0, 0));
                e4->addItem(new Food("Blue Potion", -15, 15, 0));
            e5= new Room("e5 -- You enter an office space lit by desk lamps. Theres a key hanging from one of the desks", "NA");
                e5->addItem(new Food("Key", 0, 0, 1));
            s1 = new Room("s1 -- You feel a cold grip around your body as you enter the room. All surfaces of the room are covered in a layer of ice, most concerning is the floor.[Now a 50% chance to slip when walking or attacking].  ", "NA");
            s2 = new Room("s2 -- There is a stench in the air as an ice troll stands in front of you menacingly. There is an exit to the east south and north ", "NA");
            s3 = new Room("s3 -- An ominous sound reverberates around the room. 2 potions hang in front of you, Red and Blue, with a sign that reads “Recently cured of the flu”. ", "NA");
                s3->addItem(new Food("Blue Potion", 25, 0, 0));
                s3->addItem(new Food("Red Potion", -15, 15, 0));
            s4 = new Room("s4 -- A wolf stands in front of you, he bares his fangs and looks quite hungry, perhaps you are his next meal? Behind him, a key hangs on the wall. There is an exit to the east.", "NA");
                s4->addItem(new Food("Key", 0, 0, 1));
            exit = new Room("exit -- You notice three keyholes on the door, you have a strange feeling like you must find these. Strange. ", "win");


//             (N, E, S, W)

    // Centre
    c1->setExits(n1, e1, s1, exit);
    // North Set
    n1->setExits(n3,NULL,c1,n2);
    n2->setExits(NULL,n1,NULL,NULL);
    n3->setExits(NULL,NULL,n1,NULL);
    //East Set
    e1->setExits(e2,NULL,NULL,c1);
    e2->setExits(NULL,e3,e1,NULL);
    e3->setExits(e5,NULL,e4,e2);
    e4->setExits(e3,NULL,NULL,NULL);
    e5->setExits(NULL,NULL,e3,NULL);
    //South Set
    s1->setExits(c1,s2,s3,NULL);
    s2->setExits(NULL,NULL,NULL,n1);
    s3->setExits(s1,NULL,s4,NULL);
    s4->setExits(s3,NULL,NULL,NULL);
    //Exit
    exit->setExits(NULL,c1,NULL,NULL);

        currentRoom = c1;
}

void Gameplay::teleport(){
    int randomIndex=0;
    do
        randomIndex = rand() % (this->rooms).size();
    while((*(this->currentRoom)).equals(*((this->rooms)[randomIndex])));
    this->currentRoom = (this->rooms)[randomIndex];
}

QString Gameplay::go(string direction) {
    Room* nextRoom = this->currentRoom->nextRoom(direction);
    string output;
    if (nextRoom == NULL)
        output = ("You can't go this way");
    else{
        output = ("Moving " + direction);
        this->currentRoom = nextRoom;
        output += "\n" + (this->currentRoom->longDescription());

    }
    return QString::fromStdString(output);
}

QString Gameplay::map(){
    string output =
        string  ("            [j]        ") +
                ("\n             |         ") +
                ("\n             |         ") +
                ("\n[h] --- [f] --- [g]") +
                ("\n             |         ") +
                ("\n             |         ") +
                ("\n[c] --- [a] --- [b]") +
                ("\n             |         ") +
                ("\n             |         ") +
                ("\n[i] --- [d] --- [e]");
    return QString::fromStdString(output);
}
