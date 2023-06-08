#pragma once
#include "DataTypes.h"
#include "InputEvents.h"
#include "EventFactory.h"
#include "Random_.h"


class Destroyability {
    /** 
    * Module responsible for handling destruction and damages on static object.
    */
    int health;
    int maxHealth;
    tag tool;
    const EntityDrops *drops;
    void *entity;
    InputEvents *inputEvents;
public:
    // Constructors and main methods
    Destroyability(void *entity, InputEvents *inputEvents, int maxHealth, tag requiredTool, const EntityDrops &drops);
    // Methods
    void takeDamage(int damage);
    // Getters, Setters
    int getHealth();
    int getMaxHealth();
    const EntityDrops *getDropChances();
    tag getToolAffecting();
};

