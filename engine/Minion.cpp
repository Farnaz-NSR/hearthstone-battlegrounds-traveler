#include "Minion.h"
#include <iostream>

// Default constructor
Minion::Minion()
    : Card("", 0, 0, "Minion", "None"), 
      taunt(false), divineShield(false), poisonous(false), 
      windfury(false), tier(1), golden(false) {
}

// Parameterized constructor
Minion::Minion(const std::string& name, int attack, int health, 
               const std::string& race, int tier)
    : Card(name, attack, health, "Minion", race),
      taunt(false), divineShield(false), poisonous(false),
      windfury(false), tier(tier), golden(false) {
}

// Destructor
Minion::~Minion() {
}

// Getters for keyword abilities
bool Minion::hasTaunt() const {
    return taunt;
}

bool Minion::hasDivineShield() const {
    return divineShield;
}

bool Minion::hasPoisonous() const {
    return poisonous;
}

bool Minion::hasWindfury() const {
    return windfury;
}

bool Minion::isGolden() const {
    return golden;
}

int Minion::getTier() const {
    return tier;
}

// Setters for keyword abilities
void Minion::setTaunt(bool value) {
    taunt = value;
}

void Minion::setDivineShield(bool value) {
    divineShield = value;
}

void Minion::setPoisonous(bool value) {
    poisonous = value;
}

void Minion::setWindfury(bool value) {
    windfury = value;
}

void Minion::setGolden(bool value) {
    golden = value;
}

void Minion::setTier(int newTier) {
    if (newTier >= 1 && newTier <= 6) {
        tier = newTier;
    }
}

// Take damage with Divine Shield
void Minion::takeDamage(int amount) {
    if (amount < 0) return;
    
    // Divine Shield blocks the first damage
    if (divineShield) {
        divineShield = false;
        std::cout << name << "'s Divine Shield is broken!" << std::endl;
        return;
    }
    
    // Regular damage
    Card::takeDamage(amount);
}

// Create a golden version
Minion Minion::makeGolden() const {
    Minion goldenMinion(name, attack * 2, health * 2, race, tier);
    goldenMinion.setGolden(true);
    goldenMinion.setTaunt(taunt);
    goldenMinion.setDivineShield(divineShield);
    goldenMinion.setPoisonous(poisonous);
    goldenMinion.setWindfury(windfury);
    return goldenMinion;
}

// Display minion information
void Minion::display() const {
    std::cout << (golden ? "★ " : "") << name << " (" << tier << "★)" 
              << " | " << attack << "/" << health 
              << " | " << race;
    
    if (taunt) std::cout << " [Taunt]";
    if (divineShield) std::cout << " [Divine Shield]";
    if (poisonous) std::cout << " [Poisonous]";
    if (windfury) std::cout << " [Windfury]";
    
    std::cout << std::endl;
}
