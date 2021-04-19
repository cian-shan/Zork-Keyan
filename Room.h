#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include <QMainWindow>
#include "Item.h"
#include "foodlist.h"
#include "Food.h"
using namespace std;
using std::vector;

class Room {

private:
	map<string, Room*> exits;
    string exitString();
    vector <Food> Foods;


public:
    int numberOfItems();
    string type;
    Room(string description, string type);
	void setExits(Room *north, Room *east, Room *south, Room *west);
    const string shortDescription();
    string longDescription();
	Room* nextRoom(string direction);
    void addItem(Item *inItem);
    string displayItem();
    void removeItemFromRoom(string inString);
    void addItems(int foodindex);

    //(Array)s and pointers
    vector <Item*> itemsInRoom;

    //Arrays and (pointer)s
    Item* getItemFromString(string itemDesc);
    string description;
    bool equals(Room r2);
};

#endif
