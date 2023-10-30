#include "ItemFactory.h"

void ItemFactory::loadItemCtorParams(const fs::path fp) {
    auto data = JsonHandler::parseJson(fp);
    auto &d = data->as_object();

    auto et = a_s(d, "EntityType");
    auto des = a_s(d, "Description");
    auto &cl = d.at("Color").as_object();
    auto ms = a_s(d, "Stack");
    auto rt = a_s(d, "ToolType");

    float cr = cl.at("R").as_int64();
    float cg = cl.at("G").as_int64();
    float cb = cl.at("B").as_int64();

    entitytype entityType = CR::selectEntityType(et, true);

    ItemCtorParams *params = new ItemCtorParams {
        inputEvents,
        entityType,
        new std::string(des.c_str()),
        nullptr,
        CR::selectColor(cr, cg, cb),
        (stack)0,
        CR::selectMaxStack(ms),
        CR::selectToolType(rt, true)
    };

    itemParams[entityType] = params;
    itemToTemplateMap[entityType] = tc::ITEM_SIMPLE;
}

ItemFactory::ItemFactory(InputEvents *inputEvents) : inputEvents(inputEvents) {
    // All Items
    auto filesI = Directories::listDir(ctorParamsItem);
    for (auto &fp : filesI)
        loadItemCtorParams(fp);
}

Item *ItemFactory::buildItem(entitytype entityType, stack amount, Position *position) {
	Item *newItem = 0;
	if (entityType == 0) 
		return 0;
    entityType = CR::selectEntityType(entityType);
    auto it = itemToTemplateMap.find(entityType);
    if (it != itemToTemplateMap.end()) {
        if (it->second == tc::ITEM_SIMPLE) {
            itemParams[entityType]->position = position;
            itemParams[entityType]->amount = amount;
            newItem = new Item(*itemParams[entityType]);
        }
    } else {
        Logger::log(lg::ERROR_, "Could not create entity '%s'. Unknown entity type!", entityType);
    }
    return newItem;
}

Item *ItemFactory::buildItem(ItemDropChance &idc, Position *position) {
	stack amount = std::min(idc.chanceGuaranteed, Random_::random(idc.chanceLow, idc.chanceHigh));
	return buildItem(idc.item, amount, position);
}
