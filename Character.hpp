
#include <string>
#include <iostream>
#include "Weapon.hpp"

class Character
{
public:
    Character();
    Character(std::string name, std::string nameWeapon, int weaponDamage);
    void receiveDamage(int nbDamage);
    void attack(Character& target);
    void drinkLifePotion(int quantityPotion);
    void changeWeapon(std::string nameNewWeapon, int damageNewWeapon);
    void useMana(int amount);
    void displayState() const;
    void display() const;
    bool isAlive() const;
    ~Character();

private:
    std::string m_name;
    int m_life;
    int m_mana;
    Weapon m_weapon;
};
