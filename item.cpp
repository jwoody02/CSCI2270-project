// CS1300 Fall 2020
// Author: Jordan Wood
// Recitation: 318 - Maria Stull
// Project 3 
#include <string> 
#include "player.h"
#include "item.h"
using namespace std;

Item::Item() {
    Item::price = 0;
    Item::name = "";
}
Item::Item(string nam, int pric) {
    Item::price = pric;
    Item::name = nam;
}
string Item::getName() {
    return Item::name;
}
int Item::getPrice() {
    return Item::price;
}
void Item::setName(string nam) {
    Item::name = nam;
}
void Item::setPrice(int pric) {
    Item::price = pric;
}