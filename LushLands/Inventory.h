#pragma once
#include "Item.h"
#include "ConstantRepository.h"


class Inventory {
    /**
    * Represents inventory of a character or storage entity.
    */
    Item **inventory;
    int size;
    Position *position;
    std::vector<SimpleSubscription *> contChangeSubs;
private:
    void updateContentChange();
public:
    Inventory(int size, Position *position);
    // Actions
    void onContentChangeSubscribe(SimpleSubscription *subscription);
    void onContentChangeUnsubscribe(SimpleSubscription *subscription);
    // Getters, Setters
    int getSuitableSpace(Item *item);
    Item *getItem(int i);
    Item *putItem(int i, Item *item);
    Item *putItemAuto(Item *item);
    Item *takeItem(int i);
    Item **getSlot(int i);
    int getItemCount(name itemType);
    int getSize();
};

