// CS1300 Fall 2020
// Author: Jordan Wood
// Recitation: 318 - Maria Stull
// Project 3 
#include <iostream>
#include <string>
#include "item.h"
#ifndef PLAYER_H
#define PLAYER_H
using namespace std;
class Player 
{
    public:
        Player();
        int getHealth();
        void setHealth(int health);
        bool purchaseItem(int index);
        Item * getItems();
        int getAmountOfItems();
        string getName();
        void setName(string name);
        int getMilesToGo();
        void setMilesToGo(int mile);
        int getAmountOfFood();
        void setAmountOfFood(int amt);
        void setBalance(int bal);
        int getBalance();
        string getDate();
        void setDate(string dat);
        int getCurrentDay();
        void setCurrentDay(int dat);
        int getCurrentMonth();
        void setCurrentMonth(int dat);
        void addToHuntingAbility();
        int getHuntingAbility();
        void setPersonAtIndex(string name, int index);
        string getPersonAtIndex(int index);
        // void setInventory(Inventory inv);
        // Inventory getInventory();
    private:
        int balance;
        string name;
        int currentHealth;
        int food;
        int milesToGo;
        int amountOfRepairParts;
        int amountOfMedkits;
        Item items[50];
        string currentDate;
        string startDate;
        int currentMonth;
        int currentDay;
        int huntingAbility;
        // Inventory inv;
        string otherMembers[4];
};
#endif