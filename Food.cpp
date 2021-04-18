#include "Food.h"

Food::Food(string desc, int val, double sod, int key)
    : Item(desc){
    this->healValue = val;
    this->sodium = sod;
    this->keys = key;
}
int Food::getValue(){
    return this->healValue;
}

double Food::getSodium(){
    return this->sodium;
}

int Food::getKey(){
    return this->keys;
}

void Food::operator ++(){
    this->healValue+=20;
}
