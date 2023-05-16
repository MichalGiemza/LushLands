#include "Simulation.h"

Simulation::Simulation(Controller *controller) :
    focus(controller->getFocus()) {
    // Systems
    entityFactory = new EntityFactory(controller->getInputEvents());
    itemFactory = new ItemFactory();
    // World
    world = new World(FLATLAND, 42, entityFactory, itemFactory, controller->getInputEvents());
    loadPosition = new Position(0, world->getSeaLevel(), 0);
    keepPositionLoaded(*loadPosition);
    // System
    Logger::log(lg::DEBUG_SIMULATION, "Simulation started; Chunks loaded: [%i]; Entities loaded: [%i].",
                world->getChunkLoadManager()->getChunksLoadedCount(),
                world->getChunkLoadManager()->getEntitiesCreatedCount());
    // Player
    addPlayer(controller->getInputEvents());
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

void Simulation::addPlayer(InputEvents *ie) {
    Position p = Position(0, world->getSeaLevel(), 0);
    Humanoid *human = (Humanoid *)entityFactory->buildEntity(e::HUMAN, p);
    player = new Player(human, ie);
    world->placePlayer(player);
    loadPosition = (Position *)human->getPosition();
    focus->setFocusedObject((GameElement *)human->getGameElement());
    // Tools
    Inventory *inv = (Inventory *)human->getInventory();
    inv->putItemAuto(itemFactory->buildItem(i::PICKAXE, 1));
    inv->putItemAuto(itemFactory->buildItem(i::SHOVEL, 1));
    inv->putItemAuto(itemFactory->buildItem(i::AXE, 1));
    inv->putItem(11, itemFactory->buildItem(i::SWORD, 1));
}

Player *Simulation::getPlayer() {
    return player;
}

ItemFactory *Simulation::getItemFactory() {
    return itemFactory;
}

