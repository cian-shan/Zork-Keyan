#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
protected:
    string description;
private:
	string longDescription;
    double weightGrams;
    int value;
    string type;
	bool weaponCheck;

public:
    Item (string description, double inWeight);
    Item (string description);
    Item (string inDescription, string type, int value);
    Item ();
    virtual ~Item() = 0;
	string getShortDescription();
    string getLongDescription();
    double getWeight();
    void setWeight(double weightGrams);
    virtual int getValue() = 0;
    virtual int getDam() = 0;
    virtual int getKey() = 0;
    string getType();
    void setValue(int value);
	int getWeaponCheck();
    void setWeaponCheck(int weaponCheck);
};

#endif /*ITEM_H_*/
