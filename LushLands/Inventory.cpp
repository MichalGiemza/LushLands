#include "Inventory.h"

Inventory::Inventory(int size) :
    size(size) {
    inventory = (Item **)malloc(sizeof(Item *) * size);
    for (int i = 0; i < size; i++)
        inventory[i] = 0;
}

Item *Inventory::getItem(int i) {
    return inventory[i];
}

Item *Inventory::putItem(int i, Item *putItem) {
    auto invItem = inventory[i];
    inventory[i] = putItem;
    return invItem;
}

Item *Inventory::takeItem(int i) {
    auto item = inventory[i];
    inventory[i] = 0;
    return item;
}

int Inventory::getSize() {
    return size;
}
