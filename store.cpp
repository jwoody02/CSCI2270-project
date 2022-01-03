// CS1300 Fall 2020
// Author: Jordan Wood
// Recitation: 318 - Maria Stull
// Project 3 
#include <string> 
#include "player.h"
#include "item.h"
#include "player.h"
#include "store.h"
using namespace std;
Store::Store() {
    Item oxen;
    oxen.setName("Oxen");
    // $200 for 2 oxen
    oxen.setPrice(200);
    Item foodItem;
    foodItem.setName("Food");
    // $2 for 4lbs of food
    foodItem.setPrice(2);
    Item bullets;
    bullets.setName("Bullets");
    // $2 for 20
    bullets.setPrice(2);

    Item wagonRepair;
    wagonRepair.setName("Wagon Replacement Parts");
    wagonRepair.setPrice(20);
    Item medkit;
    medkit.setName("One use Medkit");
    medkit.setPrice(25);
    // set available items to these 5 items
    Store::availableItems[0] = oxen;
    Store::availableItems[1] = foodItem;
    Store::availableItems[2] = bullets;
    Store::availableItems[3] = wagonRepair;
    Store::availableItems[4] = medkit;

    // Store::availableItems = {oxen, foodItem, bullets, wagonRepair, medkit};
}
string Store::getNameAtIndex(int ind) {
    // gets the name of an item at index ind, from available items array
    return Store::availableItems[ind].getName(); 
}
int Store::getPriceAtIndex(int ind) {
    return Store::availableItems[ind].getPrice();
}
Item* Store::getAvailableItems() {
    return Store::availableItems;
}
int Store::getNumItems() {
    return sizeof(Store::availableItems);
}