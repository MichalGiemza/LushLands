#pragma once
#include "DataTypes.h"
#include "Item.h"
#include "ItemConstants.h"
#include "ConstantSets.h"
#include "Random_.h"


class ItemFactory {
    /** 
    * Class responsible for creation of items.
    */

public:
    ItemFactory();
    Item *buildItem(itemtype itemType, stack amount);
    Item *buildItem(ItemDropChance &itemDropChance);
};

