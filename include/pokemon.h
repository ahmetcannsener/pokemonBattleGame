#ifndef POKEMON_H
#define POKEMON_H


#include <iostream>
using std::string;

// declaration of Pokemon class
class Pokemon{
    public:
        Pokemon(string, int, int, double, int); // constructor
        string get_name() const;  // getter for m_name
        void set_name(string); // setter for m_name
        int get_hp() const;   // getter for m_hp
        void set_hp(int);   // setter for m_hp
        int get_damage() const;   // getter for m_damage
        int get_recharge() const; // getter for m_recharge
        double get_powerUp_chance() const{return m_powerUp_chance;} // getter for m_powerUp_chance
        bool isFainted() const;   // method for the info of pokemon is fainted or not
        bool get_isPowerUp() const;   // getter for m_isPowerUp
        void set_isPowerUp(bool); // setter for m_isPowerUp
    private:
        string m_name; // name attribute
        int m_hp;   // hp attribute (hit point)
        const int m_damage; // damage attribute
        int m_recharge; // recharge attribute: holds the info of the duration that pokemon waits for another power up attempt
        const double m_powerUp_chance;  // holds the chance of pokemon to be able to power up
        bool m_isPowerUp; // isPowerUp attribute: holds the info of if pokemon initiated power up or not
};

#endif