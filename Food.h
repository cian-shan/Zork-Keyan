#ifndef FOOD_H
#define FOOD_H

#include "Item.h"
#include <vector>

//Abstract Classes
//Inheritance
class Food : public Item
{
public:
    //Food(string, int, int, int);

    virtual int getValue();
    virtual int getDam();
    virtual int getKey();

    //Operator overloading
    void operator ++();

protected:
    int healValue;
    int damage;
    int keys;
    };

class Apple: public Food {
public:
Apple();
//Copy Constructor
//C++ Reference
Apple(const Apple &a1){
      this->description = a1.description;
      this->healValue = a1.healValue;
      this->damage = a1.damage;
      this->keys = a1.keys;
};
//Friendship
friend Food;
};

class Banana: public Food {
public:
Banana();
friend Food;
};

class Pineapple: public Food {
public:
Pineapple();
friend Food;
};

class Key: public Food {
public:
Key();
friend Food;
};


#endif // FOOD_H
