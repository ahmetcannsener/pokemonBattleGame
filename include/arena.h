#ifndef ARENA_H
#define ARENA_H


#include "psychicPokemon.h"
using std::string;

// declaration of Arena class
class Arena{
    public:
        Arena(); // Arena constructor
        ~Arena(); // Arena destructor
        void addPokemon(char, string, int, int); // method for adding pokemons to Arena
        void set_terrain(string);   // setter for m_terrain attribute
        void spawnTerrain();    // method for determine a terrain
        void restartTerrain();  // method for resetting terrain to "none"
        string get_terrain() const {return m_terrain;}    // getter for m_terrain attribute
        ElectricPokemon* get_elecP() const {return this->m_elecPokemon;}  // getter for ElectricPokemon 
        PsychicPokemon* get_psyP() const {return this->m_psyPokemon;} // getter for PsychicPokemon
        bool checkFaint() const; // method for checking whether there is a faint or not
        void printRoundStats(int, int) const; // method for printing the stats
        void printMatchResults() const;   // method for printing the result
        void simulateBattle();  // method for battle simulation
    private:
        string m_terrain = "none";  // current terrain attribute
        ElectricPokemon* m_elecPokemon; // ElectricPokemon
        PsychicPokemon* m_psyPokemon;   // PsychicPokemon
};

#endif