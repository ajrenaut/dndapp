#ifndef ADVENTURER_H
#define ADVENTURER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDir>
#include <QDebug>
#include <stdbool.h>

using namespace std;

class Adventurer
{
public:
    Adventurer();
    ~Adventurer();
    Adventurer(string, int, int, int);
    Adventurer(int, QSqlDatabase);
    int getLevel();
    void setLevel(int);
    int getExperience();
    void setExperience(int);
    int getXpProgress();
    int getStealthMod();
    void setStealthMod(int);
    int getPerceptionMod();
    void setPerceptionMod(int);
    int getProficiencyMod();
    void setProficiencyMod(int);
    bool getStealthProf();
    bool getPerceptionProf();
    QString getName();
    void setName(QString);

    int rollStealth(bool);
    int rollPerception(bool);

    void calculateLevel(int);



private:
    int level;
    int experience;
    int stealthMod;
    int perceptionMod;
    int proficiencyMod;
    int percentXp;
    bool isStealthProficient;
    bool isPerceptionProficient;
    QString name;
};

#endif // ADVENTURER_H
