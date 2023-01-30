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

Chunk::Chunk(ChunkPosition chunkPosition, ChunkPlan &chunkPlan, EntityFactory *entityFactory) {
    this->entityFactory = entityFactory;
    this->chunkPosition = chunkPosition;
    groundTiles = std::unordered_map<TilePosition, Entity *>();
    structures = std::unordered_map<TilePosition, Entity *>();
    generateTiles(chunkPlan);
    generateStructures(chunkPlan);
    collisionManager = CollisionManager();
    
    Logger::log(ll::DEBUG_CHUNK, "Created Chunk [%i, %i]", chunkPosition.x, chunkPosition.z);
}

Entity *Chunk::getGround(TilePosition &tilePosition) {
    return groundTiles[tilePosition];
}

Entity *Chunk::getStructure(TilePosition &tilePosition) {
    return structures[tilePosition];
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

ChunkPosition *Chunk::getChunkPosition() {
    return &chunkPosition;
}

int Chunk::entitiesLoadedCount() {
    return groundTiles.size() + structures.size();
}

