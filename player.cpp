// CS1300 Fall 2020
// Author: Jordan Wood
// Recitation: 318 - Maria Stull
// Project 3 
#include <string> 
#include "player.h"
#include "item.h"
#include "item.cpp"

using namespace std;

Player::Player() {
    Player::balance = 1600;
    Player::name = "";
    Player::currentHealth = 100;
    Player::milesToGo = 2040;
    // Player::items = [];
    Player::food = 500;
    Player::currentDate = "03/28/1847";
    Player::startDate = "03/28/1847";
    Player::huntingAbility = 5;
    Player::currentMonth = 3;
    Player::currentDay = 28;
    Player::amountOfMedkits = 0;
    Player::amountOfRepairParts = 0;
}
int Player::getCurrentDay() {
    return Player::currentDay;
}
int Player::getCurrentMonth() {
    return Player::currentMonth;
}
void Player::setCurrentDay(int dat) {
    Player::currentDay = dat;
}
void Player::setCurrentMonth(int dat) {
    Player::currentMonth = dat;
}
int Player::getHealth() {
    return Player::currentHealth;
}
Item* Player::getItems() {
    return Player::items;
}
string Player::getName() {
    return Player::name;
}
int Player::getMilesToGo() {
    return Player::milesToGo;
}
int Player::getAmountOfItems() {
    // gets length of arr: {1,2,3,4,5} will return 5
    // return sizeof(Player::items)/sizeof(Player::items[0]);
    return 0;
}
// Item Player::getItemAtIndex(int index) {
//     return Player::items[index];
// }
void Player::setHealth(int health) {
    Player::currentHealth = health;
}
void Player::setName(string nam) {
    Player::name = nam;
}
void Player::setMilesToGo(int mile) {
    Player::milesToGo = mile;
}
void Player::setBalance(int bal) {
    Player::balance = bal;
}
int Player::getBalance() {
    return Player::balance;
}
int Player::getAmountOfFood() {
    return Player::food;
}
void Player::setAmountOfFood(int amt) {
    Player::food = amt;
}
// bool Player::purchaseItem(Item item) {
//     //buys item and subtracts the price from the users current ballence (default 1600)
//     //returns true or false if purchased (false if balance to low)
//     if(Player::balance - item.getPrice() > 0) {
//         Player::balance = Player::balance-item.getPrice();
//         Player::items.push_back(item);
//         ofstream gamefile;
//         gamefile.open ("playerdata.txt");
//         string finalString = "";
//     // write name and other data to file
//         for(int i = 0; i < sizeof(Player::items)/sizeof(Player::items[0]); i ++) {
//             finalString = finalString + "\n"+item.getName();
//         }
//         gamefile << finalString;
//         gamefile.close();   
//         return true;
//     } else {
//         return false;
//     }
    
    
// }
void Player::setDate(string dat) {
    Player::currentDate = dat;
}
string Player::getDate() {
    return Player::currentDate;
}
void Player::addToHuntingAbility() {
    Player::huntingAbility = Player::huntingAbility +5;
}
int Player::getHuntingAbility() {
    return Player::huntingAbility;
}
void Player::setPersonAtIndex(string name, int index) {
    Player::otherMembers[index] = name;
}
string Player::getPersonAtIndex(int index) {
    return Player::otherMembers[index];
}