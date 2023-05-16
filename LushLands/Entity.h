#pragma once
#include <map>
#include <string>
#include <vector>
#include <unordered_set>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "DataTypes.h"
#include "Logger.h"
#include "EntityUpdater.h"
#include "InputEvents.h"

extern boost::uuids::random_generator uuidGenerator;

class Entity {
    /**
    * Definicja najbardziej podstawowego elementu œwiata.
    */
    boost::uuids::uuid id;
    entitytype entityType;
    std::string description;
    updatetype updateType;
    InputEvents *inputEvents;
    std::vector<std::pair<defaultfn *, void *>> onChunkReg; // FIXME: Jeœli nie zadzia³a to zrobiæ vector<pair>
    std::vector<std::pair<defaultfn *, void *>> onChunkUnreg; // FIXME: Jeœli nie zadzia³a to zrobiæ vector<pair>
private:
    void handleChunkRegister();
    void handleChunkUnregister();
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
    virtual void *getTilePosition() = 0;

    virtual void *getDestroyability() = 0;

    virtual void *getFirstName() = 0;
    virtual void *getLastName() = 0;
    
    virtual void *getInventory() = 0;

    // Operators
    friend bool operator== (const Entity &e1, const Entity &e2);
};

bool operator== (const Entity &e1, const Entity &e2);
