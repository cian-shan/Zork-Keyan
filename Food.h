#ifndef FOOD_H
#define FOOD_H

#include "Item.h"

//Abstract Classes
//Inheritance
class Food : public Item
{
public:
    Food(string, int, int, int);
    virtual int getValue();
    virtual int getDam();
    virtual int getKey();
    //Operator overloading
    void operator ++();
    //Friendship
    friend Item;
    Food(const Food &a1);
protected:
    int healValue;
    int damage;
    int keys;
    };

#endif // FOOD_H
