#include "Destroyability.h"

Destroyability::Destroyability(int maxHealth, tooltype requiredTool, const ItemDropChance *drops) :
    maxHealth(maxHealth), health(maxHealth), tool(requiredTool), drops(drops) {}

int Destroyability::getHealth() {
    return 0;
}

int Destroyability::getMaxHealth() {
    return 0;
}

bool Destroyability::takeDamage(int damage, tooltype usedTool) {
    health = std::min(0, (health - damage) * (tool == usedTool));
    return tool == usedTool;
}

const ItemDropChance *Destroyability::getDropChances() {
    return drops;
}
