
#include "Weapon.hpp"
#include<iostream>
using namespace std;

Weapon::Weapon()
{
    m_name="Rusty Sword";
    m_damage = 10;
}

Weapon::Weapon(string name, int damage)
{
    m_name = name;
    m_damage = damage;
}

void Weapon::change(string name, int damage)
{
    m_name = name;
    m_damage = damage;
}

void Weapon::display() const
{
    cout << "Weapon = " << m_name << " & damage: " << m_damage  << endl;
}

int Weapon::getDamage() const
{
    return m_damage;
}

std::string Weapon::getName() const
{
    return m_name;
}
