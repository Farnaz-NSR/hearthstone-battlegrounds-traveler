#include "Card.h"
#include <algorithm>
#include <iostream>

Card::Card()
    : name(""), attack(0), health(0), cardType(""), race("") {
}

Card::Card(const std::string& name, int attack, int health,
           const std::string& cardType, const std::string& race)
    : name(name), attack(std::max(0, attack)), health(std::max(0, health)), 
      cardType(cardType), race(race) {
}

Card::~Card() {
}

// Getters
std::string Card::getName() const {
    return name;
}

int Card::getAttack() const {
    return attack;
}

int Card::getHealth() const {
    return health;
}

std::string Card::getCardType() const {
    return cardType;
}

std::string Card::getRace() const {
    return race;
}

// Setters
void Card::setName(const std::string& newName) {
    name = newName;
}

void Card::setAttack(int newAttack) {
    attack = std::max(0, newAttack);
}

void Card::setHealth(int newHealth) {
    health = std::max(0, newHealth);
}

void Card::setRace(const std::string& newRace) {
    race = newRace;
}

// Take damage
void Card::takeDamage(int amount) {
    if (amount < 0) return;
    health = std::max(0, health - amount);
}

// Heal
void Card::heal(int amount) {
    if (amount < 0) return;
    health += amount;
}

void Card::buff(int attackDelta, int healthDelta) {
    attack += attackDelta;
    if (attack < 0) attack = 0;
    
    health += healthDelta;
    if (health < 0) health = 0;
}

bool Card::isAlive() const {
    return health > 0;
}

void Card::display() const {
    std::cout << "Card: " << name << " | " 
              << attack << "/" << health 
              << " | Type: " << cardType 
              << " | Race: " << race << std::endl;
}
