#pragma once
#include "Item.h"


class Inventory {
    /**
    * Represents inventory of a character or storage entity.
    */
    Item **inventory;
    int size;
    Position *position;
public:
    Inventory(int size, Position *position);

    // Getters, Setters
    int getSuitableSpace(Item *item);
    Item *getItem(int i);
    Item *putItem(int i, Item *item);
    Item *putItemAuto(Item *item);
    Item *takeItem(int i);
    Item **getSlot(int i);
    int getSize();
};

