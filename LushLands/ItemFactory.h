#pragma once
#include "DataTypes.h"
#include "Item.h"
#include "ItemConstants.h"
#include "ConstantSets.h"


class ItemFactory {
    /** 
    * Class responsible for creation of items.
    */

public:
    ItemFactory();
    Item *buildItem(itemtype itemType, stack amount);
};

