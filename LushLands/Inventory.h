#pragma once
#include "Item.h"
#include "ConstantRepository.h"
#include <stack>


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
    Item *getItem(int idx);
    Item *putItem(int idx, Item *item);
    Item *putItemAuto(Item *item);
    Item *takeItem(int idx, int amount = 1);
    std::stack<Item *> *takeItemAuto(entitytype itemType, int amount);
    Item **getSlot(int idx);
    int getItemCount(name itemType);
    int getSize();
    Position *getPosition();
};

