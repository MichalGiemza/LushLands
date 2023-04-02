#include "Item.h"

Item::Item(itemtype itemType, std::string description, const stack maxStack, stack amount) :
    itemType(itemType), description(description), maxStack(maxStack), amount(amount) { }

itemtype Item::getType() {
    return itemType;
}

const stack Item::getMaxStack() {
    return maxStack;
}

stack Item::getAmount() {
    return amount;
}

void Item::setAmount(stack newA) {
    amount = newA;
}

std::string Item::getDescription() {
    return description;
}
