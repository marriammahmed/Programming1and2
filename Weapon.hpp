#ifndef Weapon_hpp
#define Weapon_hpp
#include <string>


using namespace std;
class Weapon
{
public:
    Weapon();
    Weapon(string name, int damage);
    int getDamage() const;
    string getName() const;
    void change(string name, int damage);
    void display() const;



private:
    string m_name;
    int m_damage;
};
#endif 
