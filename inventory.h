// CS1300 Fall 2020
// Author: Jordan Wood
// Recitation: 318 - Maria Stull
// Project 3 
#include <iostream>
#include <string>
#include "item.h"
#ifndef INVENTORY_H
#define INVENTORY_H
using namespace std;
class Inventory 
{
    public:
        Inventory();
        Item* getInventory();
        void addItemToInventory(Item item);
    private:
        Item items[50];
};
#endif