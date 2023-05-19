#include "pokemon.h"

// constructor of Pokemon class
Pokemon::Pokemon(string name, int hp, int damage, double powerUp_chance, int recharge) : m_damage{damage}, m_powerUp_chance{powerUp_chance} {
    set_name(name);
    set_hp(hp);
    m_recharge = recharge;
}

// getter for m_name method definition
string Pokemon::get_name() const{
    return m_name;
}

// setter for m_name method definition
void Pokemon::set_name(string name) {
    m_name = name;
}

// getter for m_hp method definition
int Pokemon::get_hp() const{
    return m_hp;
}

// setter for m_hp method definition
void Pokemon::set_hp(int hp) {
    m_hp = hp;
}

// getter for m_damage method definition
int Pokemon::get_damage() const{
    return m_damage;
}

// getter for m_recharge method definition
int Pokemon::get_recharge() const{
    return m_recharge;
}

// isFainted method definition
bool Pokemon::isFainted() const{
    if(this->m_hp <= 0)
        return true;
    return false;
}

// getter for m_isPowerUp method definition
bool Pokemon::get_isPowerUp() const{
    return m_isPowerUp;
}

// setter for m_isPowerUp method definition
void Pokemon::set_isPowerUp(bool value) {
    m_isPowerUp = value;
}


