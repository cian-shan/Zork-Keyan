#include "Food.h"

/*
Food::Food(string desc, int val, int dam, int key)
    : Item(desc){
    this->healValue = val;
    this->damage = dam;
    this->keys = key;
}
*/

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

Apple::Apple(){
this->description = "Apple";
this->healValue = 20;
this->damage = 0;
this->keys = 0;
}

Apple apple;
