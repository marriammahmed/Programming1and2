#pragma
#include <iostream>
#include "Character.hpp"


using namespace std;

int main()
{
    Character goliath("Goliath", "Sharp sword", 20);
    Character david("David", "Wooden sword", 10);
    Character warrior("warrior", "Magic wand", 15);

    while (david.isAlive() && goliath.isAlive() && warrior.isAlive())
    {
        david.displayState();
        goliath.displayState();
        warrior.displayState();

        david.attack(warrior);
        goliath.attack(warrior);
        david.attack(goliath);

        goliath.drinkLifePotion(10);
        warrior.useMana(15);
    }

    if (david.isAlive())
        cout << "David wins" << endl;
    else if (goliath.isAlive())
        cout << "Goliath wins" << endl;
    else if (warrior.isAlive())
        cout << "warrior wins" << endl;

    return 0;
}



