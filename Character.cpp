#include "Character.h"

Character::Character()
{
    health = 50;
}

Character::~Character(){}

Character::Character(string description) {
	this->description = description;
}
void Character::setName(string name){
    this->name = name;
}
string Character::getName(){
    return this->name;
}
string Character::getHealth(){
    std::ostringstream stm ;
    stm << this->health ;
    return stm.str();
}
void Character::addItem(Item &item) {
    itemsInCharacter.push_back(&item);
}
void Character::addItem(Item *item) {
    itemsInCharacter.push_back(item);
}

//Definition of Template Functions
template< typename T >
T larger(const T & val1, const T & val2){
    if(val1>val2)
        return val1;
    return val2;
}

string Character::longDescription(){
    string ret = this->description;
    for (vector<Item *>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
        ret += "\t"+ to_string((i-itemsInCharacter.begin())+1) + ": " + (*i)->getLongDescription();
    int bestHeal = 0;
    int highestDam = 0;
    int numkeys = 0;
    for (vector<Item *>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++){
        bestHeal = larger(bestHeal, (*i)->getValue());
        highestDam = larger(highestDam, (*i)->getDam());
        numkeys = larger(numkeys, (*i)->getKey());
    }
    ret += "\tBest Health Boost From Potion: " + to_string(bestHeal) + "\n";
    ret += "\tMost Damage From Potion: " + to_string(highestDam) + "\n";
    ret += "\tNumber of keys Collected = " + to_string(numkeys) + "\n";
    return ret;
}
