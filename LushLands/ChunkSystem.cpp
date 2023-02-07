#include "ChunkSystem.h"

ChunkSystem::ChunkSystem(BaseWorldPlanner *worldPlanner, EntityFactory *entityFactory, EventHandler *eventHandler) {
    this->entityFactory = entityFactory;
    this->worldPlanner = worldPlanner;
    chunkLoadManager = new ChunkLoadManager(chunks, worldPlanner, entityFactory, eventHandler);
}

Chunk *ChunkSystem::getChunk(ChunkPosition chunkPosition) {
    return chunks[chunkPosition];
}

ChunkLoadManager *ChunkSystem::getChunkLoadManager() { return chunkLoadManager; }
