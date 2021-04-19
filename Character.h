#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "Item.h"
#include "Food.h"

#include <string>
#include <sstream>
using namespace std;
#include <vector>
using std::vector;

//Private, Public and Protected
class Character {
private:
    string description;
    //Pointers
    vector <Item *> itemsInCharacter;

public:
    int health;
    void addItem(Item *item);
    void addItem(Item &item);

public:
    Character();
    //Bit Structures
    unsigned int keycount: 6;
    void damageMove();
    //Destructor & Memory Management
    ~Character();
    Character(string description);
	string shortDescription();
	string longDescription();
    string name;
    void setName(string name);
    string getName();
    string getHealth();
};

#endif
