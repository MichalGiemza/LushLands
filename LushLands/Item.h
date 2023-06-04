#pragma once
#include "DataTypes.h"
#include "Position.h"
#include "CtorParamStructures.h"


class Item {
    /** 
    * Base for items in world.
    */
    entitytype entityType;
    std::string description;
    const stack maxStack;
    stack amount;
    Position position;
    tooltype toolType;
public:
    Item(ItemCtorParams &params);
    entitytype getType();
    const stack getMaxStack();
    stack getAmount();
    Position *getPosition();
    void setAmount(stack amount);
    std::string getDescription();
    tooltype getToolType();
};

