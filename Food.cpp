#include "Food.h"

Food::Food(string desc, int val, int dam, int key)
    : Item(desc){
    this->healValue = val;
    this->damage = dam;
    this->keys = key;
}

int Food::getValue(){
    return this->healValue;
}

int Food::getDam(){
    return this->damage;
}

int Food::getKey(){
    return this->keys;
}

void Food::operator ++(){
    this->healValue+=20;
}
//Copy Constructor
Food::Food(const Food &a1){
  this->description = a1.description;
  this->healValue = a1.healValue;
  this->damage = a1.damage;
  this->keys = a1.keys;
}
