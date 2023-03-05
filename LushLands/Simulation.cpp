#include "Simulation.h"

Simulation::Simulation(Controller *controller) {
    entityFactory = new EntityFactory();
    world = new World(FLATLAND, 42, entityFactory, controller->getEventHandler());
    loadPosition = new Position(0, world->getSeaLevel(), 0);
    keepPositionLoaded(*loadPosition);

    controller->getInputEvents()->subscribeTimerTPS(0, updateSimulation, this);

    Logger::log(ll::DEBUG_SIMULATION, "Simulation started; Chunks loaded: [%i]; Entities loaded: [%i].",
                world->getChunkLoadManager()->getChunksLoadedCount(),
                world->getChunkLoadManager()->getEntitiesCreatedCount());
}

World *Simulation::getWorld() {
    return world;
}

void Simulation::keepPositionLoaded(Position position) {
    world->getChunkLoadManager()->loadByPosition(position);
}

Position *Simulation::getWorldLoadingPosition() {
    return loadPosition;
}

void updateSimulation(ALLEGRO_EVENT *ae, void *obj) {
    auto *s = (Simulation *)obj;
    s->world->update();
}
