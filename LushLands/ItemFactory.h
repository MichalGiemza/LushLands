#pragma once
#include "DataTypes.h"
#include "Item.h"
#include "ConstantSets.h"
#include "Random_.h"
#include "JsonHandler.h"
#include "CtorParamStructures.h"
#include <unordered_map>
#include "Directories.h"
#include "ConstantRepository.h"


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

