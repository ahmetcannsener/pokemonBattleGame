#include "electricPokemon.h"

// constructor of ElectricPokemon class
ElectricPokemon::ElectricPokemon(string name, int hp, int damage) : Pokemon{name, hp, damage, 0.2, 3}
{}

// isConfused method definition
bool ElectricPokemon::isConfused() const{
    return m_isConfused;
}

// setter as not confused method definition
void ElectricPokemon::set_notConfused() {
    m_isConfused = false;
}

// setter as confused method definition
void ElectricPokemon::set_Confused() {
    m_isConfused = true;
}

// setter for m_charge method definition
void ElectricPokemon::set_charge(int charge) {
    m_charge = charge;
} 

// increment_charge method definition
void ElectricPokemon::increment_charge() {
    m_charge++;
}

// setter for m_breakConfuse method definition
void ElectricPokemon::set_breakConfuse(int breakConfuse) {
    m_breakConfuse = breakConfuse;
}

// increment_breakConfuse method definition
void ElectricPokemon::increment_breakConfuse() {
    m_breakConfuse++;
}

// attack method definition
void ElectricPokemon::attack(PsychicPokemon& psyP, string terrain) {
    if(ownTerrain(terrain) || get_breakConfuse() >= 3){
        set_notConfused();
        set_breakConfuse(0);
    } else{
        increment_breakConfuse();
    }

    if(get_isPowerUp() && !isConfused()) {
        psyP.set_hp(psyP.get_hp() - (3 * get_damage()));
    }
    else if(!get_isPowerUp() && !isConfused()) {
        psyP.set_hp(psyP.get_hp() - (get_damage()));
    }
    else if(isConfused()) {
        return;
    }
    return;
}

// powerUp_attempt method definition
bool ElectricPokemon::powerUp_attempt() {
    if(get_charge() >= 3) {
        int x = rand() % 10 + 1;

        if((double(x)) / 10 <= get_powerUp_chance()) {
            set_isPowerUp(true);
            set_charge(0);
            return true;
        }else {
            set_isPowerUp(false);
            return false;
        }
    }else {
        increment_charge();
        set_isPowerUp(false);
        return false;
    }   
}

bool ElectricPokemon::ownTerrain(string terrain) const{
    if(terrain == m_terrain) {
        return true;
    }
    else {
        return false;
    }
}
