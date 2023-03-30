#include "Item.h"

Item::Item(itemtype itemType, std::string description) :
    itemType(itemType), description(description) {}

itemtype Item::getType() {
    return itemType;
}

std::string Item::getDescription() {
    return description;
}
