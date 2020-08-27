#ifndef DICE_H
#define DICE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class Dice
{
public:
    Dice();
    Dice(int, int);
    ~Dice();
    int* getResults();

private:
    int diceAmount;
    int diceValue;
    int *results;
};

#endif // DICE_H
