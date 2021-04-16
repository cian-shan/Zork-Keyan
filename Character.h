#ifndef CHARACTER_H_
#define CHARACTER_H_
#include "ZorkUL.h"
#include <string>
using namespace std;
#include <vector>
using std::vector;


class Character {
public:
    Character();
    string description;
    vector <Item> itemsInCharacter;
    void addItems(string Item);
    void addItem(Item *item);
    int hp;
    int dmgdlt;
    Character(string description);
    string shortDescription();
    string longDescription();
    virtual ~Character();
    void setHitPoints(int &HP);
    int getHitPoints();
    int getDamage();
    void weaponOn(int initemid);
    int findItemInInv(string itemname);
    void foodConsumed();

};

#endif /*CHARACTER_H_*/
