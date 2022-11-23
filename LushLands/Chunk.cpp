#include "Chunk.h"

Chunk::Chunk(ChunkPosition &chunkPosition, ChunkPlan chunkPlan) {
    this->chunkPosition = chunkPosition;
    groundTiles = std::unordered_map<TilePosition, Entity *>();
    structures = std::unordered_map<TilePosition, Entity *>();
    Logger::log("Created Chunk [%i, %i]", chunkPosition.x, chunkPosition.z);
}

Entity *Chunk::getGround(TilePosition tilePosition) {
    return groundTiles[tilePosition];
}

Entity *Chunk::getStructure(TilePosition tilePosition) {
    return structures[tilePosition];
}

