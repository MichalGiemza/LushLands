#include "Inventory.h"

Inventory::Inventory(int size, Position *position) :
    size(size), position(position) {
    // Items
    inventory = (Item **)malloc(sizeof(Item *) * size);
    for (int i = 0; i < size; i++)
        inventory[i] = 0;
}

int Inventory::getSuitableSpace(Item *item) {
    int emptySpace = -1;
    int fittingSpace = -1;

    for (int i = size - 1; i >= 0; i--) {
        Item *it = inventory[i];
        if (it and item->getType() == it->getType() and it->getAmount() < item->getMaxStack())
            fittingSpace = i;
        if (it == 0)
            emptySpace = i;
    }
    if (fittingSpace >= 0)
        return fittingSpace;
    if (emptySpace >= 0)
        return emptySpace;
    return -1;
}

Item *Inventory::getItem(int i) {
    return inventory[i];
}

Item *Inventory::putItem(int i, Item *item) {
    Item *invIt = inventory[i];
    int maxS = item->getMaxStack();
    // Space occupied by same type -> fill amount
    if (invIt and item->getType() == invIt->getType()) {
        int sumAm = (int)invIt->getAmount() + item->getAmount();
        int overflow = std::max(sumAm - maxS, 0);
        int newAm = std::min(sumAm, maxS);

        invIt->setAmount(newAm);
        item->setAmount(overflow);
        if (overflow == 0) {
            delete item;
            item = 0;
        }
        return item;
    }
    // Space occupied by other type -> swap items
    // Empty slot -> put item and return 0
    inventory[i] = item;
    if (invIt)
        invIt->getPosition()->updatePosition(*position);
    return invIt;
}

Item *Inventory::putItemAuto(Item *item) {
    while (item) {
        int space = getSuitableSpace(item);
        if (space < 0)
            return item;
        item = putItem(space, item);
    }
}

Item *Inventory::takeItem(int i) {
    auto item = getItem(i);
    if (item)
        item->getPosition()->updatePosition(*position);
    inventory[i] = 0;
    return item;
}

Item **Inventory::getSlot(int i) {
    return &inventory[i];
}

int Inventory::getSize() {
    return size;
}
