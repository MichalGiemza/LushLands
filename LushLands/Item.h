#pragma once
#include "DataTypes.h"


class Item {
    /** 
    * Base for items in world.
    */
    itemtype itemType;
    std::string description;
public:
    Item(itemtype itemType, std::string description);
};

