#include "EntityFactory.h"

std::unordered_map<entitytype, Entity *> EntityFactory::prefabs = std::unordered_map<entitytype, Entity *>();

void EntityFactory::setupPrefabs() {
    prefabs[SOIL] = new Ground(SOIL, SOIL_DESCRIPTION, Position(), Size(1, 1, 1), SOIL_TEXTURE, SOIL_COLOR);
    prefabs[GRASS] = new Ground(GRASS, GRASS_DESCRIPTION, Position(), Size(1, 1, 1), GRASS_TEXTURE, GRASS_COLOR);
    prefabs[WATER] = new Ground(WATER, WATER_DESCRIPTION, Position(), Size(1, 1, 1), WATER_TEXTURE, WATER_COLOR);
    prefabs[SAND] = new Ground(SAND, SAND_DESCRIPTION, Position(), Size(1, 1, 1), SAND_TEXTURE, SAND_COLOR);
    prefabs[ROCK] = new Ground(ROCK, ROCK_DESCRIPTION, Position(), Size(1, 1, 1), ROCK_TEXTURE, ROCK_COLOR);
    prefabs[COBBLE] = new Ground(COBBLE, COBBLE_DESCRIPTION, Position(), Size(1, 1, 1), COBBLE_TEXTURE, COBBLE_COLOR);
    prefabs[FARMLAND] = new Ground(FARMLAND, FARMLAND_DESCRIPTION, Position(), Size(1, 1, 1), FARMLAND_TEXTURE, FARMLAND_COLOR);
    prefabs[GRAVEL] = new Ground(GRAVEL, GRAVEL_DESCRIPTION, Position(), Size(1, 1, 1), GRAVEL_TEXTURE, GRAVEL_COLOR);
    prefabs[SNOW] = new Ground(SNOW, SNOW_DESCRIPTION, Position(), Size(1, 1, 1), SNOW_TEXTURE, SNOW_COLOR);
}

void EntityFactory::init() {
    setupPrefabs();
}

Entity *EntityFactory::buildEntity(entitytype entityType) {
    return prefabs[entityType]->clone();
}
