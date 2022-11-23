#include "ChunkSystem.h"

ChunkSystem::ChunkSystem(BaseWorldPlanner *worldPlanner) {
    this->worldPlanner = worldPlanner;
    chunkLoadManager = new ChunkLoadManager(chunks, worldPlanner);
}

Chunk *ChunkSystem::getChunk(ChunkPosition chunkPosition) {
    return chunks[chunkPosition];
}

ChunkLoadManager *ChunkSystem::getChunkLoadManager() { return chunkLoadManager; }
