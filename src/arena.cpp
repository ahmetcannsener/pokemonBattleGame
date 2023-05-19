#include "arena.h"
using std::string;

// constructor of Arena class
Arena::Arena() {
    this->m_elecPokemon = nullptr;
    this->m_psyPokemon = nullptr;
}

// destructor of Arena class
Arena::~Arena() {
    delete this->m_elecPokemon;
    delete this->m_psyPokemon;
}

// addPokemon method definition
void Arena::addPokemon(char type, string name, int hp, int damage) {
    if(type == 'e') {
        if(m_elecPokemon != nullptr) {
            return;
        }else {
            m_elecPokemon = new ElectricPokemon(name, hp, damage);
        }
        std::cout << std::endl;
        std::cout << "Electric Pokemon " << get_elecP()->get_name() << " has entered the arena." << std::endl;
        std::cout << "Class: Electric" << std::endl;
        std::cout << "         " << "Name: " << get_elecP()->get_name() << std::endl;
        std::cout << "         " << "HP: " << get_elecP()->get_hp() << std::endl;
        std::cout << "         " << "Damage: " << get_elecP()->get_damage() << std::endl;
    }
    else if(type == 'p') {
        if(m_psyPokemon != nullptr) {
            return;
        }else{
            m_psyPokemon = new PsychicPokemon(name, hp, damage);
        }
        std::cout << std::endl;
        std::cout << "Psychic Pokemon " << get_psyP()->get_name() << " has entered the arena." << std::endl;
        std::cout << "Class: Psychic" << std::endl;
        std::cout << "         " << "Name: " << get_psyP()->get_name() << std::endl;
        std::cout << "         " << "HP: " << get_psyP()->get_hp() << std::endl;
        std::cout << "         " << "Damage: " << get_psyP()->get_damage() << std::endl;
    }
    
}

// set_terrain method definition
void Arena::set_terrain(string terrain) {
    m_terrain = terrain;
}

// spawnTerrain method definition
void Arena::spawnTerrain() {
    int x = rand() % 10 + 1;

    if( x >= 1 && x <= 2) {
        set_terrain("electric");
    }
    else if( x >= 3 && x <= 4) {
        set_terrain("psychic");
    }
    else {
        set_terrain("none");
    }
}

// restartTerrain method definition
void Arena::restartTerrain() {
    set_terrain("none");
}

// checkFaint method definition
bool Arena::checkFaint() const {
    if(get_elecP()->isFainted() || get_psyP()->isFainted()) {
        return true;
    }else {
        return false;
    }
}


// printRoundStats method definition
void Arena::printRoundStats(int round, int heads) const{
    string elecPokemon_name = get_elecP()->get_name();
    string psyPokemon_name = get_psyP()->get_name();
    int elecPokemon_hp = get_elecP()->get_hp();
    int psyPokemon_hp = get_psyP()->get_hp();

    string firstPokemon;
    if(heads == 0) {
        firstPokemon = elecPokemon_name;
    }else if(heads == 1) {
        firstPokemon = psyPokemon_name;
    }
    
    std::cout << std::endl;
    std::cout << "Round: " << round << std::endl;
    std::cout << "Current Terrain: " << get_terrain() << std::endl;
    std::cout << firstPokemon << " goes first." << std::endl;
    // !!!!!!!!!!!!!!!!!!!!!!! powerUp case
    if(get_elecP()->get_isPowerUp()) {
        std::cout << elecPokemon_name << " has initiated a power up." << std::endl;
    }
    if(get_psyP()->get_isPowerUp()) {
        std::cout << psyPokemon_name << " has initiated a power up." << std::endl;
    }
    if(elecPokemon_hp <= 0) {
        std::cout << elecPokemon_name << " HP: 0" << std::endl;
    }else{
        std::cout << elecPokemon_name << " HP: " << elecPokemon_hp << std::endl;
    }
    if(psyPokemon_hp <= 0) {
        std::cout << psyPokemon_name << " HP: 0" << std::endl;
    }else{
        std::cout << psyPokemon_name << " HP: " << psyPokemon_hp << std::endl;
    }
    if(elecPokemon_hp > psyPokemon_hp) {
        std::cout << elecPokemon_name << " is in the lead!" << std::endl;
    }
    else if(psyPokemon_hp > elecPokemon_hp) {
        std::cout << psyPokemon_name << " is in the lead!" << std::endl;
    }else {
        std::cout << "Current condition is draw! HP's are equal." << std::endl;
    }
    std::cout << std::endl;
}

// printMatchResults method definition
void Arena::printMatchResults() const{
    std::cout << std::endl;
    std::cout << "Match Results:" << std::endl;
    if(get_elecP()->isFainted()) {
        std::cout << get_psyP()->get_name() << " has won the match!" << std::endl;
    }else if(get_psyP()->isFainted()) {
        std::cout << get_elecP()->get_name() << " has won the match!" << std::endl;
    }
    std::cout << std::endl;
}

// simulateBattle method definition
void Arena::simulateBattle() {
    if(get_elecP() == nullptr || get_psyP() == nullptr) {
        return;
    }

    restartTerrain();
    int round = 1;
    int terrain_counter = 5;
    while(!get_elecP()->isFainted() && !get_psyP()->isFainted()) {
        int heads = rand() % 2; // if heads = 0 electric pokemon goes first. if heads = 1 psychic pokemon goes first.
        if(get_terrain() == "none" || terrain_counter == 5) {
            spawnTerrain();
            if(get_terrain() != "none") {
                terrain_counter = 0;
            }
        }

        if(heads == 0) {
            get_elecP()->powerUp_attempt();
            get_elecP()->attack(*get_psyP(), get_terrain());
            if(checkFaint()){
                printRoundStats(round, heads);
                printMatchResults();
                break;
            }
            get_psyP()->powerUp_attempt();
            get_psyP()->attack(*get_elecP(), get_terrain());
            if(checkFaint()){
                printRoundStats(round, heads);
                printMatchResults();
                break;
            }
            printRoundStats(round, heads);
            round++;
            terrain_counter++;
            continue;
        }
        else if(heads == 1) {
            get_psyP()->powerUp_attempt();
            get_psyP()->attack(*get_elecP(), get_terrain());
            if(checkFaint()){
                printRoundStats(round, heads);
                printMatchResults();
                break;
            }
            get_elecP()->powerUp_attempt();
            get_elecP()->attack(*get_psyP(), get_terrain());
            if(checkFaint()){
                printRoundStats(round, heads);
                printMatchResults();
                break;
            }
            printRoundStats(round, heads);
            round++;
            terrain_counter++;
            continue;
        }
    }
    
    this->m_elecPokemon = nullptr;
    this->m_psyPokemon = nullptr;
}

