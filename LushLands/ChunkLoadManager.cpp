#include "ChunkLoadManager.h"

ChunkLoadManager::ChunkLoadManager(std::unordered_map<ChunkPosition, Chunk *> chunks, BaseWorldPlanner *worldPlanner) {
    this->chunks = chunks;
    this->worldPlanner = worldPlanner;
    followedLoadingPositions = std::vector<Position>();
}

void ChunkLoadManager::loadByPosition(Position &position) {
    followedLoadingPositions.push_back(position);
    updateLoadedChunkList();
}

void ChunkLoadManager::generateChunksByPosition(Position &pos) {
    auto ncps = pos.getNeighbouringChunkPositions();
    for (int i = 0; i < ncps.n; i++) {
        ChunkPosition cpos = ncps.chunkPositions[i];
        if (!chunks.contains(cpos))
            chunks[cpos] = generateChunk(cpos);
    }
}

void ChunkLoadManager::updateLoadedChunkList() {
    for (auto &pos : followedLoadingPositions) {
        generateChunksByPosition(pos);
    }
}

Chunk *ChunkLoadManager::generateChunk(ChunkPosition &chunkPosition) {
    ChunkPlan *cp = worldPlanner->getChunkPlan(chunkPosition);
    return new Chunk(chunkPosition, *cp);
}

Chunk *ChunkLoadManager::getChunk(ChunkPosition chunkPosition) {
    return chunks[chunkPosition];
}
