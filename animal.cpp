// CS1300 Fall 2020
// Author: Jordan Wood
// Recitation: 318 - Maria Stull
// Project 3 
#include <string>
#include "animal.h"
using namespace std;

Animal::Animal() {
    Animal::weight = 0;
    Animal::type = "";
    Animal::bulletsNeeded = 0;
}
Animal::Animal(int amountOfBulletsNeeded, int weightz, string typez) {
    Animal::weight = weightz;
    Animal::type = typez;
    Animal::bulletsNeeded = amountOfBulletsNeeded;
}
void Animal::setAmountOfBulletsNeeded(int bullets) {
    Animal::bulletsNeeded = bullets;
}
int Animal::getAmountOfBulletsNeeded() {
    return Animal::bulletsNeeded;
}
void Animal::setWeight(int weightz) {
    Animal::weight = weightz;
}
int Animal::getWeight() {
    return Animal::weight;
}
void Animal::setType(string name) {
    Animal::type = name;
}
string Animal::getType() {
    return Animal::type;
}