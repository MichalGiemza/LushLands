#pragma once
#include "Entity.h"
#include "Body.h"
#include "Appearance.h"
#include "Collider.h"

class Structure : public Entity {
    /**
    * Structure
    */
    EntityUpdater entityUpdater; // Zamieniæ to potem na strategiê mo¿e? EntityUpdater/RandomTickUpdater/Nic
    Appearance appearance;
    Body body;
    Collider collider;
public:
    // Constructors and main methods
    Structure(const entitytype entityType, const std::string &description, Position &position, const Size &size, const Color &color, const updatetype updateType = no_update);
    Entity *clone() override;

    // Getters, Setters
    Position *getPosition();
    Size *getSize();
    const Color *getColor();
    Collider *getCollider();
};

