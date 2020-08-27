#include "data.h"

Data::Data()
{
    adventurers = new Adventurer[4];
    //Temp hard-coding of adventurers
    adventurers[0] = Adventurer("Valtr", 1100, 6, 1);
    adventurers[1] = Adventurer("Magni Stonecheeks", 9000, 1, 3);
    adventurers[2] = Adventurer("Dick Hickock", 250, 12, 4);
    adventurers[3] = Adventurer("Krick Wickersnick", 20069, 2, -1);

    xpTable = new int[20];
    xpTable[0] =    0;
    xpTable[1] =    300;
    xpTable[2] =    900;
    xpTable[3] =    2700;
    xpTable[4] =    6500;
    xpTable[5] =    14000;
    xpTable[6] =    23000;
    xpTable[7] =    34000;
    xpTable[8] =    48000;
    xpTable[9] =    64000;
    xpTable[10] =   85000;
    xpTable[11] =   100000;
    xpTable[12] =   120000;
    xpTable[13] =   140000;
    xpTable[14] =   165000;
    xpTable[15] =   195000;
    xpTable[16] =   225000;
    xpTable[17] =   265000;
    xpTable[18] =   305000;
    xpTable[19] =   355000;
}


Adventurer Data::getAdventurer(int advNum) {
    return adventurers[advNum];
}

int Data::getXPForLevel(int tLevel)
{
    int level = tLevel - 1; // Level inputs range from 1-20, but table is 0 indexed
    return xpTable[level];
}
