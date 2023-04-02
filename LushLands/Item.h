#pragma once
#include "DataTypes.h"
#include "Position.h"


class Item {
    /** 
    * Base for items in world.
    */
    itemtype itemType;
    std::string description;
    const stack maxStack;
    stack amount;
    Position position;
public:
    Item(itemtype itemType, std::string description, const stack maxStack, stack amount);
    itemtype getType();
    const stack getMaxStack();
    stack getAmount();
    Position *getPosition();
    void setAmount(stack amount);
    std::string getDescription();
};

