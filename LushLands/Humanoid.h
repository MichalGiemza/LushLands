#pragma once
#include "DynamicCollider.h"
#include "Entity.h"
#include "Appearance.h"
#include "Mobility.h"
#include "Inventory.h"
#include "Destroyability.h"
#include "CtorParamStructures.h"
#include "GameElement.h"


class Humanoid : public Entity {
    /** 
    * Represents humanoid creature.
    */
    GameElement gameElement;
    EntityUpdater entityUpdater;
    Appearance appearance;
    Body body;
    Collider collider;
    Mobility mobility;
    DynamicCollider dynamicCollider;
    Inventory inventory;
    Destroyability destroyability;

    name firstName;
    name lastName;
    gendertype gender;
public:
    // Constructors and main methods
    Humanoid(HumanoidCtorParams &params);
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

