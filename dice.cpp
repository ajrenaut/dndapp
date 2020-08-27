#include "dice.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

Dice::Dice()
{

}

Dice::~Dice() {

}


Dice::Dice(int amount, int value) {
    srand(static_cast<unsigned int>(time(nullptr)));
    this->diceAmount = amount;
    this->diceValue = value;
    results = new int [amount];

    for (int i = 0; i < diceAmount; i++) {
        results[i] = 1 + (rand() % diceValue);
    }

    //for (int i = 0; i < diceAmount; i++) {
    //    result += 1 + diceModifier + (rand() % diceValue);
    //}
}

int* Dice::getResults() {
    return results;
}
