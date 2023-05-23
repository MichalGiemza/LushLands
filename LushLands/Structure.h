#pragma once
#include "Entity.h"
#include "Body.h"
#include "Appearance.h"
#include "Collider.h"
#include "GameElement.h"
#include "Destroyability.h"
#include "CtorParamStructures.h"


class Structure : public Entity {
    /**
    * Structure
    */
    GameElement gameElement;
    EntityUpdater entityUpdater; // TODO Zamieniæ to potem na strategiê mo¿e? EntityUpdater/RandomTickUpdater/Nic
    Appearance appearance;
    Body body;
    Collider collider;
    Destroyability destroyability;
public:
    // Constructors and main methods
    Structure(StructureCtorParams &params);
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

