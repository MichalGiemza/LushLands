#include "Item.h"

Item::Item(ItemCtorParams &p) :
    entityType(p.entityType), 
    description(*p.description),
    maxStack(p.maxStack),
    amount(p.amount),
    toolType(p.toolType),
    position(*p.position)
{ }

entitytype Item::getType() {
    return entityType;
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

tag Item::getToolType() {
    return toolType;
}
