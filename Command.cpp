#include "Character.h"

Character::Character() {
    this->description = "Character Description";

    this->dmgdlt = 16;
    // change on weapon pick up **
    this->hp = 100;


}

//Destructor
Character::~Character() {
}

void Character::setHitPoints(int &HP){
   this->hp = HP;
}
int Character::getHitPoints(){
    return hp;
}
int Character::getDamage(){
    return dmgdlt;
}

void Character::addItem(Item item) {
    itemsInCharacter.push_back(item);
}

int Character::findItemInInv(string itemname)
{
    int sizeItems = (itemsInCharacter.size());
    if (itemsInCharacter.size() < 1) {
        return -1;
        }
    else if (itemsInCharacter.size() > 0) {
        for (int n = 0; n <= sizeItems; n++) {
            // compare inString with short description
            int tempFlag = itemname.compare(itemsInCharacter[n].getShortDescription());
            if (tempFlag == 0) {
                return n;
                break;
            }
            }
        }
    return -1;
}

//Deal Different damage depending on weapon used
void Character::weaponOn(int weapondmg) {
    int dmg = weapondmg;
    switch(dmg) {
    case 1:
    {
        dmgdlt = 40;
        break;
    }
    case 2:
    {
        dmgdlt = 50;
        break;
    }
    case 3:
    {
        dmgdlt = 60;
        break;
    }
    }
}

void Character::foodConsumed () {
    this->hp = hp + 50;
    if (hp > 100){
        hp = 100;
    }
    itemsInCharacter.erase(itemsInCharacter.begin()+findItemInInv("Food"));
}


string Character::longDescription()
{
  string ret = this->description;
  ret += "\n Item list:\n";
  for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
    ret += "\t"+ (*i).getLongDescription() + "\n";
  return ret;
}



