#include "Simulation.h"

Simulation::Simulation(Controller *controller) :
    focus(controller->getFocus()) {
    // Systems
    entityFactory = new EntityFactory();
    itemFactory = new ItemFactory();
    // World
    world = new World(FLATLAND, 42, entityFactory, itemFactory, controller->getEventHandler());
    loadPosition = new Position(0, world->getSeaLevel(), 0);
    keepPositionLoaded(*loadPosition);
    // Events
    controller->getInputEvents()->subscribeTimerFPS(0, updateSimulation, this);
    // System
    Logger::log(lg::DEBUG_SIMULATION, "Simulation started; Chunks loaded: [%i]; Entities loaded: [%i].",
                world->getChunkLoadManager()->getChunksLoadedCount(),
                world->getChunkLoadManager()->getEntitiesCreatedCount());
    // Player
    addPlayer();
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

void Simulation::addPlayer() {
    Position p = Position(0, world->getSeaLevel(), 0);
    Humanoid *human = (Humanoid *)entityFactory->buildEntity(HUMAN, p);
    player = new Player(human);
    world->placePlayer(player);
    loadPosition = human->getPosition();
    focus->setFocusedObject(human->getGameElement());
}

void updateSimulation(ALLEGRO_EVENT *ae, void *obj) {
    auto *s = (Simulation *)obj;
    miliseconds timeNow = ae->timer.count; // TODO: P�niej trzeba to zmieni� - �wiat z zapis�w i jego wiek
    miliseconds dt = timeNow - s->lastUpdated;

    s->world->update(dt);

    s->lastUpdated = timeNow;
}
