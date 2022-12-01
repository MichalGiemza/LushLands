#include "Simulation.h"

World *Simulation::world = 0;
Position *Simulation::loadPosition = 0;

void Simulation::init() {
    EntityFactory::init();

    Simulation::world = new World(FLATLAND, 42);
    Simulation::loadPosition = new Position(0, Simulation::world->getSeaLevel(), 0);
    Simulation::keepPositionLoaded(*Simulation::loadPosition);

    Logger::log("Simulation started; Chunks loaded: [%i]; Entities loaded: [%i].",
                world->getChunkLoadManager()->getChunksLoadedCount(),
                world->getChunkLoadManager()->getEntitiesCreatedCount());
}

void Simulation::keepPositionLoaded(Position position) {
    world->getChunkLoadManager()->loadByPosition(position);
}
