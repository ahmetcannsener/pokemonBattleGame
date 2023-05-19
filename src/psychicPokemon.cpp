#include "psychicPokemon.h"

// constructor of PsychicPokemon class
PsychicPokemon::PsychicPokemon(string name, int hp, int damage) : Pokemon{name, hp, damage, 0.3, 5}
{}

// setter for m_charge method definition
void PsychicPokemon::set_charge(int charge) {
    m_charge = charge;
}

// increment_charge method definition
void PsychicPokemon::increment_charge() {
    m_charge++;
}

// attack method definition
void PsychicPokemon::attack(ElectricPokemon& elecP, string terrain) {
    
        if(get_isPowerUp()) {
            elecP.set_hp(elecP.get_hp() - get_damage());
            if(!elecP.ownTerrain(terrain))
                elecP.set_Confused();
        }else {
            elecP.set_hp(elecP.get_hp() - get_damage());
        }
        if(ownTerrain(terrain)) 
            elecP.set_hp(elecP.get_hp() - get_damage());
            
}

// powerUp_attempt method definition
bool PsychicPokemon::powerUp_attempt() {
    if(get_charge() >= 5) {
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

// ownTerrain method definition
bool PsychicPokemon::ownTerrain(string terrain) const{
    if(m_terrain == terrain) {
        return true;
    }
    else {
        return false;
    }
}