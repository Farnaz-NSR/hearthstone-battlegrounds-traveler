#pragma once
#include "Card.h"
#include <vector>

class Minion : public Card {
private:
    bool taunt;
    bool divineShield;
    bool poisonous;
    bool windfury;
    int tier;
    bool golden;

public:
    Minion();
    Minion(const std::string& name, int attack, int health, 
           const std::string& race, int tier = 1);

    ~Minion();

    // Keyword abilities getters
    bool hasTaunt() const;
    bool hasDivineShield() const;
    bool hasPoisonous() const;
    bool hasWindfury() const;
    bool isGolden() const;
    int getTier() const;

    // Keyword abilities setters
    void setTaunt(bool value);
    void setDivineShield(bool value);
    void setPoisonous(bool value);
    void setWindfury(bool value);
    void setGolden(bool value);
    void setTier(int newTier);

    // Combat mechanics
    void takeDamage(int amount) override;
    
    // Create a golden version of this minion
    Minion makeGolden() const;
    
    // Display minion info
    void display() const override;
};
