// CS1300 Fall 2020
// Author: Jordan Wood
// Recitation: 318 - Maria Stull
// Project 3 
#include <string> 
#include "player.h"
#include "item.h"
#include "item.cpp"
#include "inventory.h"

using namespace std;

Inventory::Inventory() {
    
}
Item* Inventory::getInventory() {
    return Inventory::items;
}