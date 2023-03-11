#include "ChunkSystem.h"

ChunkSystem::ChunkSystem(BaseWorldPlanner *worldPlanner, EntityFactory *entityFactory) {
    this->entityFactory = entityFactory;
    this->worldPlanner = worldPlanner;
    chunkLoadManager = new ChunkLoadManager(&chunks, worldPlanner, entityFactory);
}

Chunk *ChunkSystem::getChunk(ChunkPosition chunkPosition) {
    return chunks[chunkPosition];
}

ChunkLoadManager *ChunkSystem::getChunkLoadManager() { return chunkLoadManager; }
