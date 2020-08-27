#ifndef DATA_H
#define DATA_H
#include "adventurer.h"

class Data
{
public:
    Data();
    Adventurer getAdventurer(int);
    int getXPForLevel(int);

private:
    Adventurer *adventurers;
    int *xpTable;
};

#endif // DATA_H
