#pragma once
#include "Item.h"
#include "DataTypes.h"


class Inventory {
    /**
    * Represents inventory of a character or storage entity.
    */
    Item **inventory;
    int size;
public:
    Inventory(int size);

    // Getters, Setters
    int getSuitableSpace(Item *item);
    Item *getItem(int i);
    Item *putItem(int i, Item *item);
    Item *putItemAuto(Item *item);
    Item *takeItem(int i);
    int getSize();
};

