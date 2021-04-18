#ifndef FOOD_H
#define FOOD_H

#include "item.h"


class Food : public Item
{
public:
    Food(string, int, int, int);
    virtual int getValue();
    virtual int getDam();
    virtual int getKey();
    void operator ++();
private:
    int healValue;
    int damage;
    int keys;
};

#endif // FOOD_H
