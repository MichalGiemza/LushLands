#pragma once
#include "DataTypes.h"


class Destroyability {
    /** 
    * Module responsible for handling destruction and damages on static object.
    */
    int health;
    int maxHealth;
    tooltype tool;
    const ItemDropChance *drops;
public:
    // Constructors and main methods
    Destroyability(int maxHealth, tooltype requiredTool, const ItemDropChance *drops);
    // Methods
    bool takeDamage(int damage, tooltype tool);
    // Getters, Setters
    int getHealth();
    int getMaxHealth();
    const ItemDropChance* getDropChances();
    tooltype getToolAffecting();
};

