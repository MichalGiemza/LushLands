#pragma once
#include "DataTypes.h"


class Item {
    /** 
    * Base for items in world.
    */
    itemtype itemType;
    std::string description;
    const stack maxStack;
    stack amount;
public:
    Item(itemtype itemType, std::string description, const stack maxStack, stack amount);
    itemtype getType();
    const stack getMaxStack();
    stack getAmount();
    void setAmount(stack amount);
    std::string getDescription();
};

