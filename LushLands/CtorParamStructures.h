#pragma once
#include "DataTypes.h"
#include "Position.h"
#include "Size.h"
#include "Color.h"
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
    const tooltype requiredTool;
    const EntityDrops *drops;
    const TextureLocalization *textureLocalization;
};


struct StructureCtorParams {
    InputEvents *inputEvents;
    const entitytype entityType;
    const std::string *description;
    Position *position;
    const Size *size;
    const Color *color;
    int maxHealth;
    const tooltype requiredTool;
    const EntityDrops *drops;
    const updatetype updateType = no_update;
    const TextureLocalization *textureLocalization;
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
    const tooltype requiredTool;
    const EntityDrops *drops;
    const TextureLocalization *textureLocalization;
};


struct GroundCtorParams {
    InputEvents *inputEvents;
    const entitytype entityType;
    const std::string *description;
    Position *position;
    const Size *size;
    const Color *color;
    int maxHealth;
    const tooltype requiredTool;
    const EntityDrops *drops;
    const updatetype updateType = no_update;
    const TextureLocalization *textureLocalization;
};
