#pragma once
#include <map>
#include <string>
#include <vector>
#include <unordered_set>
#include "DataTypes.h"
#include "Logger.h"
#include "EntityUpdater.h"
#include "InputEvents.h"


class Entity {
    /**
    * Definicja najbardziej podstawowego elementu œwiata.
    */
    entitytype entityType;
    std::string description;
    updatetype updateType;
    InputEvents *inputEvents;
public:
    // Constructors and main methods
    Entity(entitytype entityType, std::string description, updatetype updateType, InputEvents *inputEvents);
    virtual Entity *clone() = 0;

    // Getters, Setters
    entitytype getType();
    updatetype getUpdateType();
    std::string getDescription();

    // Virtual getters
    virtual void *getEntityUpdater() = 0;
    virtual void *getGameElement() = 0;

    virtual void *getColor() = 0;
    virtual void *getAppearance() = 0;

    virtual void *getMobility() = 0;
    virtual void *getCollider() = 0;
    virtual void *getDynamicCollider() = 0;
    virtual void *getRandomWalk() = 0;

    virtual void *getBody() = 0;
    virtual void *getSize() = 0;
    virtual void *getPosition() = 0;

    virtual void *getDestroyability() = 0;

    virtual void *getFirstName() = 0;
    virtual void *getLastName() = 0;
    
    virtual void *getInventory() = 0;
};
