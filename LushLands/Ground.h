#pragma once
#include "Entity.h"
#include "Body.h"
#include "Appearance.h"
#include "GameElement.h"
#include "Destroyability.h"


class Ground : public Entity {
    /**
    * Ground
    */
    GameElement gameElement;
    EntityUpdater entityUpdater; // Zamieniæ to potem na strategiê mo¿e? EntityUpdater/RandomTickUpdater/Nic
    Appearance appearance;
    Body body;
    Destroyability destroyability;
public:
    // Constructors and main methods
    Ground(InputEvents *inputEvents, const entitytype entityType, const std::string &description, Position &position, const Size &size, const Color &color, int maxHealth, const tooltype requiredTool, const EntityDrops &drops, const updatetype updateType = no_update);
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

