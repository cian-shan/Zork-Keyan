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

double Food::getDam(){
    return this->damage;
}

int Food::getKey(){
    return this->keys;
}

void Food::operator ++(){
    this->healValue+=20;
}
