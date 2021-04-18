#ifndef FOOD_H
#define FOOD_H

#include "item.h"


class Food : public Item
{
public:
    Food(string, int, double, int);
    virtual int getValue();
    virtual double getSodium();
    virtual int getKey();
    void operator ++();
private:
    int healValue;
    double sodium;
    int keys;
};

#endif // FOOD_H
