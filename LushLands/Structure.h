#pragma once
#include "Entity.h"
#include "Body.h"
#include "Appearance.h"
#include "Collider.h"

class Structure : public Entity {
    /**
    * Structure
    */
    EntityUpdater entityUpdater; // Zamieni� to potem na strategi� mo�e? EntityUpdater/RandomTickUpdater/Nic
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

