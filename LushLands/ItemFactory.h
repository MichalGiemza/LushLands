#pragma once
#include "stdafx.h"
#include "Item.h"
#include "CtorParamStructures.h"


class ItemFactory {
    /** 
    * Class responsible for creation of items.
    */
    InputEvents *inputEvents;
    std::unordered_map<entitytype, templateclass> itemToTemplateMap;

    std::unordered_map<entitytype, ItemCtorParams *> itemParams;
private:
    void loadItemCtorParams(const fs::path fp);
public:
    ItemFactory(InputEvents *inputEvents);
    Item *buildItem(entitytype entityType, stack amount, Position *position);
    Item *buildItem(ItemDropChance &itemDropChance, Position *position);
};

