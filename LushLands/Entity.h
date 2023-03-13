#pragma once
#include <map>
#include <string>
#include <vector>
#include <unordered_set>
#include "DataTypes.h"
#include "Logger.h"
#include "EntityUpdater.h"


class Entity {
    /**
    * Definicja najbardziej podstawowego elementu œwiata.
    */
    entitytype entityType;
    std::string description;
    updatetype updateType;
public:
    Entity(entitytype entityType, std::string description, updatetype updateType);
    entitytype getType();
    updatetype getUpdateType();
    std::string getDescription();
    virtual Entity *clone() = 0;
};
