#pragma once
#include "DataTypes.h"
#include "Item.h"
#include "ItemConstants.h"


class ItemFactory {
    /** 
    * Class responsible for creation of items.
    */

public:
    ItemFactory();
    Item *buildItem(itemtype itemType);
};

