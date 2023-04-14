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
    tooltype toolType;
public:
    Item(itemtype itemType, std::string description, const stack maxStack, stack amount, tooltype toolType = 0);
    itemtype getType();
    const stack getMaxStack();
    stack getAmount();
    Position *getPosition();
    void setAmount(stack amount);
    std::string getDescription();
    tooltype getToolType();
};

