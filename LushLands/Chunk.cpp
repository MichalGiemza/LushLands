#include "Chunk.h"

void Chunk::generateTiles(ChunkPlan &chunkPlan) {
    auto referencePosition = Position(chunkPosition);
    auto pos = Position(referencePosition);

    for (int i = 0; i < chunkSizeByTiles; i++) {
        for (int j = 0; j < chunkSizeByTiles; j++) {
            for (int k = 0; k < worldHeight; k++) {
                pos.setX(referencePosition.x() + i);
                pos.setZ(referencePosition.z() + j);
                pos.setY(referencePosition.y() + k);
                auto plannedEntityType = chunkPlan.fieldPlans[i][j][k].ground;
                Ground *ground = (Ground *)entityFactory->buildEntity(plannedEntityType);
                if (ground == 0)
                    continue;
                ground->setPosition(pos);
                groundTiles[pos.getTilePosition()] = ground;
            }
        }
    }
}

void Chunk::generateStructures(ChunkPlan &chunkPlan) {
    auto referencePosition = Position(chunkPosition);
    auto pos = Position(referencePosition);

    for (int i = 0; i < chunkSizeByTiles; i++) {
        for (int j = 0; j < chunkSizeByTiles; j++) {
            for (int k = 0; k < worldHeight; k++) {
                pos.setX(referencePosition.x() + i);
                pos.setZ(referencePosition.z() + j);
                pos.setY(referencePosition.y() + k);
                auto plannedEntityType = chunkPlan.fieldPlans[i][j][k].structure;
                auto structure = addStructure(plannedEntityType, pos);
                if (structure)
                    structures[pos.getTilePosition()] = structure;
            }
        }
    }
}

Structure *Chunk::addStructure(entitytype entityType, Position &position) {
    Structure *structure = (Structure *)entityFactory->buildEntity(entityType);
    if (structure == 0)
        return 0;
    structure->setPosition(position);
    collisionManager.addCollider((Collider *)structure);
    return structure;
}

void Chunk::generateAnimal(ChunkPlan &chunkPlan) {
    auto referencePosition = Position(chunkPosition);
    auto pos = Position(referencePosition);

    for (int i = 0; i < chunkSizeByTiles; i++) {
        for (int j = 0; j < chunkSizeByTiles; j++) {
            for (int k = 0; k < worldHeight; k++) {
                pos.setX(referencePosition.x() + i);
                pos.setZ(referencePosition.z() + j);
                pos.setY(referencePosition.y() + k);
                auto plannedEntityType = chunkPlan.fieldPlans[i][j][k].animal;
                auto animal = addAnimal(plannedEntityType, pos);
                if (animal)
                    animals[pos.getTilePosition()] = animal;
            }
        }
    }
}

Animal *Chunk::addAnimal(entitytype entityType, Position &position) {
    Animal *animal = (Animal *)entityFactory->buildEntity(entityType);
    if (animal == 0)
        return 0;
    animal->setPosition(position);
    collisionManager.addCollider((Collider *)animal);
    return animal;
}

Chunk::Chunk(ChunkPosition chunkPosition, ChunkPlan &chunkPlan, EntityFactory *entityFactory, EventHandler *eventHandler) :
    collisionManager(),
    chunkEvents(eventHandler, &chunkPosition, &collisionManager) {
    this->entityFactory = entityFactory;
    this->chunkPosition = chunkPosition;
    // Entities
    groundTiles = std::unordered_map<TilePosition, Entity *>();
    structures = std::unordered_map<TilePosition, Entity *>();
    animals = std::unordered_map<TilePosition, Entity *>();
    generateTiles(chunkPlan);
    generateStructures(chunkPlan);
    generateAnimal(chunkPlan);
    // Events
    TimerSubscription *ts = new TimerSubscription {0, 0, updateEntities, this};
    chunkEvents.subscribeUpdate(ts);

    Logger::log(ll::DEBUG_CHUNK, "Created Chunk [%i, %i]", chunkPosition.x, chunkPosition.z);
}

Entity *Chunk::getGround(TilePosition &tilePosition) {
    return groundTiles[tilePosition];
}

Entity *Chunk::getStructure(TilePosition &tilePosition) {
    return structures[tilePosition];
}

Entity *Chunk::getAnimal(TilePosition &tilePosition) {
    return animals[tilePosition];
}

CollisionManager *Chunk::getCollisionManager() {
    return &collisionManager;
}

std::unordered_map<TilePosition, Entity *> *Chunk::getGround() {
    return &groundTiles;
}

std::unordered_map<TilePosition, Entity *> *Chunk::getStructures() {
    return &structures;
}

std::unordered_map<TilePosition, Entity *> *Chunk::getAnimals() {
    return &animals;
}

ChunkPosition *Chunk::getChunkPosition() {
    return &chunkPosition;
}

int Chunk::entitiesLoadedCount() {
    return groundTiles.size() + structures.size();
}

void updateEntities(ALLEGRO_EVENT *allegroEvent, void *caller) {
    Chunk *c = (Chunk *)caller;
    for (auto &p : c->groundTiles)
        p.second->updateEntity(allegroEvent);
    for (auto &p : c->structures)
        p.second->updateEntity(allegroEvent);
    for (auto &p : c->animals)
        p.second->updateEntity(allegroEvent);
}

