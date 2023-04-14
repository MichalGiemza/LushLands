#include "Item.h"

Item::Item(itemtype itemType, std::string description, const stack maxStack, stack amount, tooltype toolType) :
    itemType(itemType), description(description), maxStack(maxStack), amount(amount), toolType(toolType) { }

itemtype Item::getType() {
    return itemType;
}

const stack Item::getMaxStack() {
    return maxStack;
}

stack Item::getAmount() {
    return amount;
}

Position *Item::getPosition() {
    return &position;
}

void Item::setAmount(stack newA) {
    amount = newA;
}

std::string Item::getDescription() {
    return description;
}

tooltype Item::getToolType() {
    return toolType;
}
