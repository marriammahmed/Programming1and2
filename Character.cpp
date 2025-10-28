#include "Character.hpp"

using namespace std;

Character::Character() : m_weapon("Rusty Sword", 10)
{
    m_name="Unkown";
    m_life=100;
    m_mana=100;
}

Character::Character(string name, string nameWeapon, int weaponDamage) : m_weapon(nameWeapon, weaponDamage)
{
    m_name=name;
    m_life=100;
    m_mana=100;
   
}

void Character::display() const
{

    cout << "Life: " << m_life << endl;
    cout << "Mana: " << m_mana << endl;
    m_weapon.display();
    cout << endl;
}

bool Character::isAlive() const
{
    return m_life > 0;
}

void Character::receiveDamage(int nbDamage)
{
    m_life -= nbDamage;

    if (m_life < 0)
    {
        m_life = 0;
    }
}

void Character::attack(Character& target)
{
    cout << m_name << " attacks " << target.m_name << " with " << m_weapon.getName() << " for " << m_weapon.getDamage() << " damage." << endl;
    target.receiveDamage(m_weapon.getDamage());
}

void Character::drinkLifePotion(int quantityPotion)
{
    m_life += quantityPotion;
    if(m_life>200)
    {
        m_life=200;
    }
    cout << m_name << " drinks a potion which gives him extra " << quantityPotion << " life points." << endl;
}

void Character::changeWeapon(string nameNewWeapon, int damageNewWeapon)
{
    m_weapon.change(nameNewWeapon, damageNewWeapon);
    cout << m_name << " changes their weapon to " << m_weapon.getName() << " with damage: " << m_weapon.getDamage() << endl;
}

void Character::useMana(int amount)
{
    m_mana -= amount;
    cout << m_name << " uses " << amount << " mana" << endl;
}

void Character::displayState() const
{
    cout << "The data of " <<m_name <<" is "<< endl;
    display();
}

Character::~Character()
{
}
