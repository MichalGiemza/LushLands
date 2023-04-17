#pragma once
#include "Entity.h"
#include "RandomWalk.h"
#include "Appearance.h"
#include "GameElement.h"
#include "Destroyability.h"

class Animal : public Entity {
    /**
    * Representation of animal.
    *
    */
    GameElement gameElement;
    EntityUpdater entityUpdater;
    Appearance appearance;
    Body body;
    Collider collider;
    Mobility mobility;
    DynamicCollider dynamicCollider;
    RandomWalk randomWalk;
    Destroyability destroyability;
public:
    // Constructors and main methods
    Animal(InputEvents *inputEvents, const entitytype entityType, const std::string &description, Position &position, const Size &size, const Color &color, const int movementSpeed, const miliseconds walkInterval, int maxHealth, const tooltype requiredTool, const ItemDropChance *drops);
    Entity *clone() override;
    
    // Getters, Setters
    virtual void *getEntityUpdater() override;
    virtual void *getGameElement() override;

    virtual void *getColor() override;
    virtual void *getAppearance() override;

    virtual void *getMobility() override;
    virtual void *getCollider() override;
    virtual void *getDynamicCollider() override;
    virtual void *getRandomWalk() override;

    virtual void *getBody() override;
    virtual void *getSize() override;
    virtual void *getPosition() override;

    virtual void *getDestroyability() override;

    virtual void *getFirstName() override;
    virtual void *getLastName() override;

    virtual void *getInventory() override;
};

