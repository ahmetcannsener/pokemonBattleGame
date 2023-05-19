#ifndef ELECTRICPOKEMON_H
#define ELECTRICPOKEMON_H


#include "psychicPokemon.h"
using std::string;

// forward declaration of PsychicPokemon class
class PsychicPokemon;

// declaration of ElectricPokemon class
class ElectricPokemon : public Pokemon{
    public:
        ElectricPokemon(string, int, int);  // constructor
        bool isConfused() const;  // method for checking if ElectricPokemon is confused
        void set_notConfused();  // setter method for m_isConfused to be set as not confused
        void set_Confused();    // setter method for m_isConfused to be set as confused
        int get_charge() const {return m_charge;} // getter for m_charge
        void set_charge(int);   // setter for m_charge
        void increment_charge();    // method for m_charge to be incremented by 1 
        int get_breakConfuse() const {return m_breakConfuse;} // getter for m_breakConfuse
        void set_breakConfuse(int); // setter for m_breakConfuse
        void increment_breakConfuse();  // method for m_breakConfuse to be incremented by 1
        void attack(PsychicPokemon&, string);   // attack method for ElectricPokemon
        bool powerUp_attempt(); // method for Power Up Attempt
        bool ownTerrain(string) const; // method for checking if the terrain is its own terrain
    private:
        bool m_isConfused = false; // m_isConfused attribute keeps the info if it is confused or not
        int m_charge = 3;   // charge counter attribute for checking if it reaches the required recharge amonut 
        int m_breakConfuse = 0; // counter for ElectricPokemon to wait for 3 rounds in order to get rid of confusion
        string m_terrain = "electric"; // m_terrain attribute holds its terrain name
};

#endif