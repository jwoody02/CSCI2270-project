// CS1300 Fall 2020
// Author: Jordan Wood
// Recitation: 318 - Maria Stull
// Project 3 
#include <iostream>
#include <string>
#ifndef ITEM_H
#define ITEM_H
using namespace std;
class Item 
{
    public:
        Item();
        Item(string name, int price);
        string getName();
        void setName(string nam);
        int getPrice();
        void setPrice(int pric);
    private:
        int price;
        string name;
};
#endif