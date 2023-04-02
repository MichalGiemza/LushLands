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
    // Tools
    human->getInventory()->putItemAuto(itemFactory->buildItem(PICKAXE, 1));
    human->getInventory()->putItemAuto(itemFactory->buildItem(SHOVEL, 1));
    human->getInventory()->putItemAuto(itemFactory->buildItem(AXE, 1));
}

Player *Simulation::getPlayer() {
    return player;
}

void updateSimulation(ALLEGRO_EVENT *ae, void *obj) {
    auto *s = (Simulation *)obj;
    miliseconds timeNow = al_get_timer_count(ae->timer.source);
    miliseconds dt = timeNow - s->lastUpdated;

    s->world->update(dt);

    s->lastUpdated = timeNow;
}
