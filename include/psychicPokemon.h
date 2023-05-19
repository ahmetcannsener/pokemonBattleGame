#ifndef PSYCHICPOKEMON_H
#define PSYCHICPOKEMON_H

#include "pokemon.h"
#include "electricPokemon.h"
using std::string;

// forward declaration of ElectricPokemon class
class ElectricPokemon;

// declaration of PsychicPokemon class
class PsychicPokemon : public Pokemon{
    public:
        PsychicPokemon(string, int, int);   // constructor
        int get_charge() const{return m_charge;} // getter for m_charge
        void set_charge(int); // setter for m_charge
        void increment_charge();   // method for m_charge to be incremented by 1 
        void attack(ElectricPokemon&, string);  // attack method for PsychicPokemon
        bool powerUp_attempt();     // method for PowerUp attempt
        bool ownTerrain(string) const;    // method for checking if the terrain is its own terrain
    private:
        int m_charge = 5; // charge counter attribute for checking if it reaches the required recharge amonut 
        string m_terrain = "psychic";   // m_terrain attribute holds its terrain name
};

#endif