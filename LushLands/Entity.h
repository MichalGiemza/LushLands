#pragma once
#include <map>
#include <string>
#include <vector>
#include <unordered_set>
#include "DataTypes.h"
#include "Logger.h"
#include "EntityUpdater.h"
#include "EntityContainer.h"


class Entity : public EntityContainer {
    /**
    * Definicja najbardziej podstawowego elementu �wiata.
    */
    entitytype entityType;
    std::string description;
public:
    Entity(entitytype entityType, std::string description);
    entitytype getType();
    std::string getDescription();
    virtual Entity *clone() = 0;
};
