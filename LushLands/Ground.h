#pragma once
#include "Entity.h"
#include "Body.h"
#include "Appearance.h"
#include "GameElement.h"

class Ground : public Entity {
    /**
    * Ground
    */
    GameElement gameElement;
    EntityUpdater entityUpdater; // Zamieniæ to potem na strategiê mo¿e? EntityUpdater/RandomTickUpdater/Nic
    Appearance appearance;
    Body body;
public:
    Ground(const entitytype entityType, const std::string &description, Position &position, const Size &size, const Color &color, const updatetype updateType = no_update);
    Entity *clone() override;
    GameElement *getGameElement();
};

