#pragma once
#include "stdafx.h"
#include "InputEvents.h"


struct HumanoidCtorParams {
    InputEvents *inputEvents;
    const entitytype entityType;
    const std::string *description;
    Position *position;
    const Size *size;
    const Color *color;
    const int movementSpeed;
    name firstName;
    name lastName;
    gendertype gender;
    const int invSize;
    int maxHealth;
    const tag requiredTool;
    const EntityDrops *drops;
};


struct StructureCtorParams {
    InputEvents *inputEvents;
    const entitytype entityType;
    const std::string *description;
    Position *position;
    const Size *size;
    const Color *color;
    int maxHealth;
    const tag requiredTool;
    const EntityDrops *drops;
    const updatetype updateType = no_update;
};


struct AnimalCtorParams {
    InputEvents *inputEvents;
    const entitytype entityType;
    const std::string *description;
    Position *position;
    const Size *size;
    const Color *color;
    const int movementSpeed;
    const miliseconds walkInterval;
    int maxHealth;
    const tag requiredTool;
    const EntityDrops *drops;
};


struct GroundCtorParams {
    InputEvents *inputEvents;
    const entitytype entityType;
    const std::string *description;
    Position *position;
    const Size *size;
    const Color *color;
    int maxHealth;
    const tag requiredTool;
    const EntityDrops *drops;
    const updatetype updateType = no_update;
};


struct ItemCtorParams {
    InputEvents *inputEvents;
    const entitytype entityType;
    const std::string *description;
    Position *position;
    const Color *color;
    stack amount;
    stack maxStack;
    const tag toolType;
};
