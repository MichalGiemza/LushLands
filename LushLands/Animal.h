#pragma once
#include "stdafx.h"
#include "Entity.h"
#include "RandomWalk.h"
#include "Appearance.h"
#include "Destroyability.h"
#include "CtorParamStructures.h"


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
    Animal(AnimalCtorParams &params);
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
    virtual void *getTilePosition() override;

    virtual void *getDestroyability() override;

    virtual void *getFirstName() override;
    virtual void *getLastName() override;

    virtual void *getInventory() override;
};

