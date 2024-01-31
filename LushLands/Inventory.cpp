#include "Inventory.h"

void Inventory::updateContentChange() {
    for (auto *sub : contChangeSubs) {
        sub->func(sub->caller);
    }
}

Inventory::Inventory(int size, Position *position) :
    size(size), position(position) {
    // Items
    inventory = (Item **)malloc(sizeof(Item *) * size);
    for (int i = 0; i < size; i++)
        inventory[i] = 0;
}

void Inventory::onContentChangeSubscribe(SimpleSubscription *subscription) {
    contChangeSubs.push_back(subscription);
}

void Inventory::onContentChangeUnsubscribe(SimpleSubscription *subscription) {
    auto it = std::find(contChangeSubs.begin(), contChangeSubs.end(), subscription);
    if (it != contChangeSubs.end())
        contChangeSubs.erase(it);
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
        updateContentChange();
        return item;
    }
    // Space occupied by other type -> swap items
    // Empty slot -> put item and return 0
    inventory[i] = item;
    if (invIt)
        invIt->getPosition()->updatePosition(*position);
    updateContentChange();
    return invIt;
}

Item *Inventory::putItemAuto(Item *item) {
    while (item) {
        int space = getSuitableSpace(item);
        if (space < 0) {
            updateContentChange();
            return item;
        }
        item = putItem(space, item);
    }
}

Item *Inventory::takeItem(int i, int amount) {
    auto item = getItem(i);
    if (not item)
        return 0;
    amount = std::min(amount, (int)inventory[i]->getAmount());
    if (item->getAmount() <= amount) {
        inventory[i] = 0;
    } else {
        inventory[i]->setAmount(inventory[i]->getAmount() - amount);
        item = new Item(*item);
        item->setAmount(amount);
    }
    item->getPosition()->updatePosition(*position);
    updateContentChange();
    return item;
}

std::stack<Item *> *Inventory::takeItemAuto(entitytype itemType, int amount) {
    itemType = CR::selectEntityType(itemType);
    std::stack<Item *> *takenItems = new std::stack<Item *>();
    for (int i = 0; i < size; i++) {
        if (inventory[i] and inventory[i]->getType() == itemType) {
            Item *takenItem = takeItem(i, amount);
            takenItems->push(takenItem);
            amount -= takenItem->getAmount();
        }
        if (amount <= 0)
            break;
    }
    return takenItems;
}

Item **Inventory::getSlot(int i) {
    return &inventory[i];
}

int Inventory::getItemCount(name itemType) {
    itemType = CR::selectEntityType(itemType);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (inventory[i] and inventory[i]->getType() == itemType)
            count += inventory[i]->getAmount();
    }
    return count;
}

int Inventory::getSize() {
    return size;
}

Position *Inventory::getPosition() {
    return new Position(*position);
}
