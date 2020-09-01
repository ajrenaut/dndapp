#include "adventurer.h"
#include <math.h>
#include "dice.h"
#include <QDebug>


using namespace std;

Adventurer::Adventurer()
{
    name = "";
    experience = 0;
    stealthMod = 0;
    perceptionMod = 0;
    proficiencyMod = 0;
    level = 0;
    percentXp = 0;
}

Adventurer::~Adventurer()
{

}

Adventurer::Adventurer(int slot, QSqlDatabase db)
{
    if (!db.open()) qDebug() <<"Unable to open database";
    QSqlQuery query;
    QString queryString = "SELECT Name, Experience, StealthMod, PerceptionMod FROM Adventurers WHERE Slot=" + QString::number(slot);
    query.exec(queryString);
    query.first();
    name = query.value(0).toString();
    experience = query.value(1).toInt();
    stealthMod = query.value(2).toInt();
    perceptionMod = query.value(3).toInt();
    if (query.value(4).toInt() == 1) isStealthProficient = true;
    if (query.value(5).toInt() == 1) isPerceptionProficient = true;

    calculateLevel(experience);
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

int Adventurer::getXpProgress() {
    return percentXp;
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

QString Adventurer::getName() {
    return name;
}

void Adventurer::setName(QString name) {
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

bool Adventurer:: getStealthProf() {
    return isStealthProficient;
}

bool Adventurer:: getPerceptionProf() {
    return isPerceptionProficient;
}

// Ideally this wouldn't be hardcoded, maybe one day
void Adventurer::calculateLevel(int experience)
{
    if (experience < 300) {
        level = 1;
        percentXp = 100*experience/300;
        proficiencyMod = 2;
    }
    else if (experience < 900) {
        level = 2;
        percentXp = 100*(experience-300)/600;
    }
    else if (experience < 2700) {
        level = 3;
        percentXp = 100*(experience-900)/1800;
    }
    else if (experience < 6500) {
        level = 4;
        percentXp = 100*(experience-2700)/3800;
    }
    else if (experience < 14000) {
        level = 5;
        percentXp = 100*(experience-6500)/7500;
    }
    else if (experience < 23000) {
        level = 6;
        percentXp = 100*(experience-14000)/9000;
    }
    else if (experience < 34000) {
        level = 7;
        percentXp = 100*(experience-23000)/11000;
    }
    else if (experience < 48000) {
        level = 8;
        percentXp = 100*(experience-34000)/14000;
    }
    else if (experience < 64000) {
        level = 9;
        percentXp = 100*(experience-48000)/16000;
    }
    else if (experience < 85000) {
        level = 10;
        percentXp = 100*(experience-64000)/21000;
    }
    else if (experience < 100000) {
        level = 11;
        percentXp = 100*(experience-85000)/15000;
    }
    else if (experience < 120000) {
        level = 12;
        percentXp = 100*(experience-100000)/20000;
    }
    else if (experience < 140000) {
        level = 13;
        percentXp = 100*(experience-120000)/20000;
    }
    else if (experience < 165000) {
        level = 14;
        percentXp = 100*(experience-140000)/25000;
    }
    else if (experience < 195000) {
        level = 15;
        percentXp = 100*(experience-165000)/30000;
    }
    else if (experience < 225000) {
        level = 16;
        percentXp = 100*(experience-195000)/30000;
    }
    else if (experience < 265000) {
        level = 17;
        percentXp = 100*(experience-225000)/40000;
    }
    else if (experience < 305000) {
        level = 18;
        percentXp = 100*(experience-265000)/40000;
    }
    else if (experience < 355000) {
        level = 19;
        percentXp = 100*(experience-305000)/50000;
    }
    else if (experience >= 355000) {
        level = 20;
        percentXp = 100;
    }

    this->proficiencyMod = static_cast<int>(ceil(static_cast<double>(level / 4))) + 1;
}

