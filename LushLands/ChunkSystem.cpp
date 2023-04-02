#include "ChunkSystem.h"

ChunkSystem::ChunkSystem(BaseWorldPlanner *worldPlanner, EntityFactory *entityFactory, ItemFactory *itemFactory) :
    itemFactory(itemFactory), entityFactory(entityFactory), worldPlanner(worldPlanner) {
    chunkLoadManager = new ChunkLoadManager(&chunks, worldPlanner, entityFactory, itemFactory);
}

Chunk *ChunkSystem::getChunk(ChunkPosition chunkPosition) {
    return chunks[chunkPosition];
}

ChunkLoadManager *ChunkSystem::getChunkLoadManager() { return chunkLoadManager; }
