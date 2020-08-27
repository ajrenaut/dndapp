#include "adventurer.h"
#include <math.h>
#include "dice.h"

using namespace std;

//TODO: Add proficiency as stored data

Adventurer::Adventurer()
{
    name = "";
    experience = 0;
    stealthMod = 0;
    perceptionMod = 0;
    proficiencyMod = 0;
    level = 0;
}

Adventurer::~Adventurer()
{

}

Adventurer::Adventurer(string name, int experience, int stealthMod, int perceptionMod)
{
    this->name = name;
    this->experience = experience;
    this->stealthMod = stealthMod;
    this->perceptionMod = perceptionMod;

    calculateLevel(this->experience);
    this->proficiencyMod = static_cast<int>(floor(static_cast<double>(level / 5))) + 2;
}

int Adventurer::getLevel() {
    return level;
}

void Adventurer::setLevel(int level) {
    this->level = level;
}

int Adventurer::getExperience() {
    return experience;
}

void Adventurer::setExperience(int experience) {
    this->experience = experience;
}

int Adventurer::getStealthMod() {
    return stealthMod;
}

void Adventurer::setStealthMod(int stealthMod) {
    this->stealthMod = stealthMod;
}

int Adventurer::getPerceptionMod() {
    return perceptionMod;
}

void Adventurer::setPerceptionMod(int perceptionMod) {
    this->perceptionMod = perceptionMod;
}

int Adventurer::getProficiencyMod() {
    return proficiencyMod;
}

void Adventurer::setProficiencyMod(int proficiencyMod) {
    this->proficiencyMod = proficiencyMod;
}

string Adventurer::getName() {
    return name;
}

void Adventurer::setName(string name) {
    this->name = name;
}

int Adventurer::rollStealth(bool isProficient) {
    int* result;
    int totalModifier = stealthMod;
    if (isProficient) totalModifier += proficiencyMod;
    Dice d20roll(1, 20);
    result = d20roll.getResults();
    return result[0];
}

int Adventurer:: rollPerception(bool isProficient) {
    int* result;
    int totalModifier = perceptionMod;
    if (isProficient) totalModifier += proficiencyMod;
    Dice d20roll(1, 20);
    result = d20roll.getResults();
    return result[0];
}

void Adventurer::calculateLevel(int experience)
{
    int level = 0;
    if (experience < 300) {
        level = 1;
    }
    else if (experience < 900) {
        level = 2;
    }
    else if (experience < 2700) {
        level = 3;
    }
    else if (experience < 6500) {
        level = 4;
    }
    else if (experience < 14000) {
        level = 5;
    }
    else if (experience < 23000) {
        level = 6;
    }
    else if (experience < 34000) {
        level = 7;
    }
    else if (experience < 48000) {
        level = 8;
    }
    else if (experience < 64000) {
        level = 9;
    }
    else if (experience < 85000) {
        level = 10;
    }
    else if (experience < 100000) {
        level = 11;
    }
    else if (experience < 120000) {
        level = 12;
    }
    else if (experience < 140000) {
        level = 13;
    }
    else if (experience < 165000) {
        level = 14;
    }
    else if (experience < 195000) {
        level = 15;
    }
    else if (experience < 225000) {
        level = 16;
    }
    else if (experience < 265000) {
        level = 17;
    }
    else if (experience < 305000) {
        level = 18;
    }
    else if (experience < 355000) {
        level = 19;
    }
    else if (experience >= 355000) {
        level = 20;
    }

    this->proficiencyMod = static_cast<int>(floor(static_cast<double>(level / 5))) + 2;
    this->level = level;
}

