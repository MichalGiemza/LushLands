#include "ChunkSystem.h"

ChunkSystem::ChunkSystem(BaseWorldPlanner *worldPlanner, EntityFactory *entityFactory, ItemFactory *itemFactory, InputEvents *inputEvents) :
    itemFactory(itemFactory), entityFactory(entityFactory), worldPlanner(worldPlanner), inputEvents(inputEvents) {
    chunkLoadManager = new ChunkLoadManager(&chunks, worldPlanner, entityFactory, itemFactory, inputEvents);
}

Chunk *ChunkSystem::getChunk(ChunkPosition &chunkPosition) {
    return chunks[chunkPosition];
}

ChunkLoadManager *ChunkSystem::getChunkLoadManager() { return chunkLoadManager; }
