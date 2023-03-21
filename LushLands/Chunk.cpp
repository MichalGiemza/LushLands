#include "Chunk.h"

void Chunk::generateTiles(ChunkPlan &chunkPlan) {
    auto referencePosition = Position(chunkPosition);
    auto pos = Position(referencePosition);

    for (int i = 0; i < chunkSizeByTiles; i++) {
        for (int j = 0; j < chunkSizeByTiles; j++) {
            for (int k = 0; k < worldHeight; k++) {
                pos.setX(referencePosition.getX() + i);
                pos.setZ(referencePosition.getZ() + j);
                pos.setY(referencePosition.getY() + k);
                auto plannedEntityType = chunkPlan.fieldPlans[i][j][k].ground;
                Ground *ground = (Ground *)entityFactory->buildEntity(plannedEntityType, pos);
                if (ground == 0)
                    continue;
                //randomTickEntities.insert((Entity *)ground); // Fixme: Przywr�ci� metod� przydzielaj�c�!
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
                pos.setPX(referencePosition.getPX() + i * meter + meter / 2);
                pos.setPZ(referencePosition.getPZ() + j * meter + meter / 2);
                pos.setPY(referencePosition.getPY() + k * meter);
                auto plannedEntityType = chunkPlan.fieldPlans[i][j][k].structure;
                auto structure = addStructure(plannedEntityType, pos);
                if (structure == 0)
                    continue;
                randomTickEntities.insert((Entity *)structure); // Fixme: Przywr�ci� metod� przydzielaj�c�!
                structures[pos.getTilePosition()] = structure;
            }
        }
    }
}

Structure *Chunk::addStructure(entitytype entityType, Position &position) {
    Structure *structure = (Structure *)entityFactory->buildEntity(entityType, position);
    if (structure == 0)
        return 0;
    collisionManager.addCollider(structure->getCollider());
    return structure;
}

void Chunk::generateAnimals(ChunkPlan &chunkPlan) {
    auto referencePosition = Position(chunkPosition);
    auto pos = Position(referencePosition);

    for (int i = 0; i < chunkSizeByTiles; i++) {
        for (int j = 0; j < chunkSizeByTiles; j++) {
            for (int k = 0; k < worldHeight; k++) {
                pos.setPX(referencePosition.getPX() + i * meter + meter / 2);
                pos.setPZ(referencePosition.getPZ() + j * meter + meter / 2);
                pos.setPY(referencePosition.getPY() + k * meter);
                auto plannedEntityType = chunkPlan.fieldPlans[i][j][k].animal;
                Animal *animal = addAnimal(plannedEntityType, pos);
                if (animal == 0)
                    continue;
                animals.insert(animal);
                toUpdateEntities.insert(animal->getEntityUpdater()); // Fixme: Przywr�ci� metod� przydzielaj�c�!
            }
        }
    }
}

Animal *Chunk::addAnimal(entitytype entityType, Position &position) {
    Animal *animal = (Animal *)entityFactory->buildEntity(entityType, position);
    if (animal == 0)
        return 0;
    collisionManager.addCollider(animal->getCollider());
    animal->getEntityUpdater()->registerParentEventSource(chunkEvents.getEventSource());
    return animal;
}

void Chunk::placeHumanoid(Humanoid *humanoid) {
    humanoids.insert(humanoid);
    humanoid->getEntityUpdater()->registerParentEventSource(chunkEvents.getEventSource());
}

Chunk::Chunk(ChunkPosition chunkPosition, ChunkPlan &chunkPlan, EntityFactory *entityFactory) :
    collisionManager(),
    chunkEvents(&chunkPosition, &collisionManager, &randomTickEntities, &toUpdateEntities) {
    this->entityFactory = entityFactory;
    this->chunkPosition = chunkPosition;
    // Entities
    generateTiles(chunkPlan);
    generateStructures(chunkPlan);
    generateAnimals(chunkPlan);

    Logger::log(lg::DEBUG_CHUNK, "Created Chunk [%i, %i]", chunkPosition.x, chunkPosition.z);
}

Entity *Chunk::getGround(TilePosition &tilePosition) {
    return groundTiles[tilePosition];
}

Entity *Chunk::getStructure(TilePosition &tilePosition) {
    return structures[tilePosition];
}

ChunkEvents *Chunk::getChunkEvents() {
    return &chunkEvents;
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

std::unordered_set<Entity *> *Chunk::getAnimals() {
    return &animals;
}

std::unordered_set<Entity *> *Chunk::getHumanoids() {
    return &humanoids;
}

ChunkPosition *Chunk::getChunkPosition() {
    return &chunkPosition;
}

int Chunk::entitiesLoadedCount() {
    return groundTiles.size() + structures.size();
}

