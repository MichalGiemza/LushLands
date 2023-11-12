#include "Simulation.h"

Simulation::Simulation(Controller *controller) :
    focus(controller->getFocus()) {
    // Systems
    itemFactory = new ItemFactory(controller->getInputEvents());
    entityFactory = new EntityFactory(controller->getInputEvents());
    craftingManager = new CraftingManager();
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
    Humanoid *human = (Humanoid *)entityFactory->buildEntity("human", p);
    player = new Player(human, ie);
    world->placePlayer(player);
    loadPosition = (Position *)human->getPosition();
    focus->setFocusedObject((GameElement *)human->getGameElement());
    // Tools
    Inventory *inv = (Inventory *)human->getInventory();
    inv->putItemAuto(itemFactory->buildItem("pickaxe", 1, &p));
    inv->putItemAuto(itemFactory->buildItem("shovel", 1, &p));
    inv->putItemAuto(itemFactory->buildItem("axe", 1, &p));
    inv->putItemAuto(itemFactory->buildItem("wood", 30, &p));
    inv->putItem(11, itemFactory->buildItem("sword", 1, &p));
}

Player *Simulation::getPlayer() {
    return player;
}

ItemFactory *Simulation::getItemFactory() {
    return itemFactory;
}

CraftingManager *Simulation::getCraftingManager() {
    return craftingManager;
}

