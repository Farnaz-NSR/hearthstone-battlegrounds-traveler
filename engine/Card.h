#pragma once
#include <string>
#include <iostream>

class Card {
protected:
    std::string name;
    int attack;
    int health;
    std::string cardType;  
    std::string race;      

public:
    // Constructors
    Card();
    Card(const std::string& name, int attack, int health,
         const std::string& cardType, const std::string& race);

    // Virtual destructor for proper polymorphism
    virtual ~Card();

    // Getters
    std::string getName() const;
    int getAttack() const;
    int getHealth() const;
    std::string getCardType() const;
    std::string getRace() const;

    // Setters
    void setName(const std::string& newName);
    void setAttack(int newAttack);
    void setHealth(int newHealth);
    void setRace(const std::string& newRace);

    // Game mechanics
    virtual void takeDamage(int amount);
    virtual void heal(int amount);
    virtual void buff(int attackDelta, int healthDelta);
    
    // Check if card is alive
    bool isAlive() const;
    
    // Display card info
    virtual void display() const;
};
