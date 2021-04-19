#ifndef FOODLIST_H
#define FOODLIST_H

#include<vector>
#include"Food.h"
#include"Item.h"

class Foodlist
{
public:
    Foodlist();
    vector <Food> getFoods();
protected:
    vector <Food> Foods;
};

#endif // FOODLIST_H
