// CS1300 Fall 2020
// Author: Jordan Wood
// Recitation: 318 - Maria Stull
// Project 3 
#include <iostream>
#include <string>
#include "item.h"
#ifndef STORE_H
#define STORE_H
using namespace std;
class Store 
{
    public:
        Store();
        string getNameAtIndex(int index);
        int getPriceAtIndex(int index);
        Item* getAvailableItems();
        int getNumItems();

    private:
        Item* availableItems;
};
#endif