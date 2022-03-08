#include "Character.h"

//Constructor
Character::Character(string _name, string _type, int _attack, int _defense, int _remainingHealth, int _nMaxRounds) {

    this->name = _name; //Name (Identifier) of the character
    this->type = _type; //Type of the character
    this->attack = _attack; //Attack point of the character
    this->defense = _defense; //Defense point of the character
    this->remainingHealth = _remainingHealth;   //Remaining health of the character, initial health as the input
    this->nMaxRounds = _nMaxRounds; //Number of maximum rounds
    this->nRoundsSinceSpecial = 0;  //Initially a newly created character is yet to use their special skill

    int* healthHistory = new int[_nMaxRounds + 1];  //Records the health history of the character
    int* healthHistory_ptr = healthHistory; //Pointer
    *healthHistory_ptr = _remainingHealth;  //Initial health is stored as the first element

}

//Copy constructor
Character::Character(const Character& character) {

    this->name = character.name;
    this->type = character.type;
    this->attack = character.attack;
    this->defense = character.defense;
    this->remainingHealth = character.remainingHealth;
    this->nMaxRounds = character.nMaxRounds;
    this->nRoundsSinceSpecial = character.nRoundsSinceSpecial;

    this->healthHistory = new int[character.nMaxRounds + 1];
    for (int i = 0; i < (character.nMaxRounds + 1); ++i) {
        *(healthHistory + i) = *(character.healthHistory + i);
    }

}

//Assignment operator
Character& Character::operator=(const Character& character) {

    if (this == &character) {
        return *this;
    }

    if (this->healthHistory != NULL) {
        delete[] this->healthHistory;
    }

    this->name = character.name;
    this->type = character.type;
    this->attack = character.attack;
    this->defense = character.defense;
    this->remainingHealth = character.remainingHealth;
    this->nMaxRounds = character.nMaxRounds;
    this->nRoundsSinceSpecial = character.nRoundsSinceSpecial;

    this->healthHistory = new int[character.nMaxRounds + 1];
    for (int i = 0; i < (character.nMaxRounds + 1); i++) {
        *(healthHistory + i) = *(character.healthHistory + i);
    }

    return *this;

}

bool Character::operator<(const Character& other) {

    char initCharacter = this->name.at(0);
    char initOther = other.name.at(0);

    return (initCharacter < initOther);

}

Character::~Character() {
    if (this->healthHistory != NULL) {
        delete[] this->healthHistory;
    }
}