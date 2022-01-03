// CS1300 Fall 2020
// Author: Jordan Wood
// Recitation: 318 - Maria Stull
// Project 3 
#include <iostream>
#include <string>
#ifndef ANIMAL_H
#define ANIMAL_H
using namespace std;
class Animal 
{
    public:
        Animal();
        Animal(int amountOfBulletsNeeded, int weight, string type);
        void setAmountOfBulletsNeeded(int bullets);
        int getAmountOfBulletsNeeded();
        void setWeight(int weight);
        int getWeight();
        void setType(string name);
        string getType();
    private:
        int weight;
        int bulletsNeeded;
        string type;
};
#endif