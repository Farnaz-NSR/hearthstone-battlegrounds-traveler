#include "Card.h"
#include "Minion.h"
#include <cassert>
#include <iostream>

void testCard() {
    std::cout << "Testing Card class..." << std::endl;
    
    Card c("TestCard", 5, 10, "Card", "None");
    assert(c.getName() == "TestCard");
    assert(c.getAttack() == 5);
    assert(c.getHealth() == 10);
    assert(c.isAlive());

    c.takeDamage(3);
    assert(c.getHealth() == 7);

    c.heal(4);
    assert(c.getHealth() == 11);

    c.buff(2, -5);
    assert(c.getAttack() == 7);
    assert(c.getHealth() == 6);

    c.takeDamage(100);
    assert(c.getHealth() == 0);
    assert(!c.isAlive());
    
    std::cout << "Card tests passed!" << std::endl;
}

void testMinion() {
    std::cout << "Testing Minion class..." << std::endl;
    
    Minion m("TestMinion", 2, 3, "Beast", 1);
    assert(m.getCardType() == "Minion");
    assert(m.getRace() == "Beast");
    assert(m.getAttack() == 2);
    assert(m.getHealth() == 3);
    assert(m.getTier() == 1);

    m.buff(-5, 10);
    assert(m.getAttack() == 0);
    assert(m.getHealth() == 13);
    
    // Test Divine Shield
    Minion shielded("Shielded", 3, 4, "Mech", 2);
    shielded.setDivineShield(true);
    assert(shielded.hasDivineShield());
    
    shielded.takeDamage(5);
    assert(!shielded.hasDivineShield());
    assert(shielded.getHealth() == 4); // Shield blocked the damage
    
    shielded.takeDamage(2);
    assert(shielded.getHealth() == 2); // Now takes actual damage
    
    // Test Golden
    Minion regular("Dragon", 4, 5, "Dragon", 3);
    Minion golden = regular.makeGolden();
    assert(golden.isGolden());
    assert(golden.getAttack() == 8);
    assert(golden.getHealth() == 10);
    
    // Test keywords
    Minion powerful("Powerful", 6, 6, "Demon", 4);
    powerful.setTaunt(true);
    powerful.setPoisonous(true);
    powerful.setWindfury(true);
    
    assert(powerful.hasTaunt());
    assert(powerful.hasPoisonous());
    assert(powerful.hasWindfury());
    
    std::cout << "Minion tests passed!" << std::endl;
}

int main() {
    try {
        testCard();
        testMinion();
        
        std::cout << "\n=== All tests passed successfully! ===" << std::endl;
        
        // Display examples
        std::cout << "\n=== Example Minions ===" << std::endl;
        Minion demon("Wrath Weaver", 1, 3, "Demon", 1);
        demon.display();
        
        Minion beast("Alleycat", 1, 1, "Beast", 1);
        beast.display();
        
        Minion mech("Micro Machine", 1, 2, "Mech", 1);
        mech.setDivineShield(true);
        mech.display();
        
        Minion golden = mech.makeGolden();
        golden.display();
        
    } catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
