#ifndef ADVENTURER_H
#define ADVENTURER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

using namespace std;

class Adventurer
{
public:
    Adventurer();
    ~Adventurer();
    Adventurer(string, int, int, int);
    int getLevel();
    void setLevel(int);
    int getExperience();
    void setExperience(int);
    int getStealthMod();
    void setStealthMod(int);
    int getPerceptionMod();
    void setPerceptionMod(int);
    int getProficiencyMod();
    void setProficiencyMod(int);
    string getName();
    void setName(string);

    int rollStealth(bool);
    int rollPerception(bool);

    void calculateLevel(int);



private:
    int level;
    int experience;
    int stealthMod;
    int perceptionMod;
    int proficiencyMod;
    string name;
};

#endif // ADVENTURER_H
