#pragma once
#include "Entity.h"
#include "Body.h"
#include "Appearance.h"
#include "GameElement.h"
#include "Destroyability.h"
#include "CtorParamStructures.h"


class Ground : public Entity {
    /**
    * Ground
    */
    GameElement gameElement;
    EntityUpdater entityUpdater; // Zamieni� to potem na strategi� mo�e? EntityUpdater/RandomTickUpdater/Nic
    Appearance appearance;
    Body body;
    Destroyability destroyability;
public:
    // Constructors and main methods
    Ground(GroundCtorParams &params);
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

