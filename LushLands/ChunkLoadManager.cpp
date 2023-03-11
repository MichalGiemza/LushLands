#include "ChunkLoadManager.h"

ChunkLoadManager::ChunkLoadManager(std::unordered_map<ChunkPosition, Chunk *> *chunks, BaseWorldPlanner *worldPlanner, EntityFactory *entityFactory) :
    entityFactory(entityFactory),
    chunks(chunks),
    worldPlanner(worldPlanner) {
}

void ChunkLoadManager::loadByPosition(Position &position) {
    followedLoadingPositions.push_back(position);
    updateLoadedChunkList();
}

void ChunkLoadManager::generateChunksByPosition(Position &pos) {
    auto ncps = pos.getNeighbouringChunkPositions();
    for (int i = 0; i < ncps.n; i++) {
        ChunkPosition cpos = ncps.chunkPositions[i];
        if (!chunks->contains(cpos))
            (*chunks)[cpos] = generateChunk(cpos);
    }
}

void ChunkLoadManager::updateLoadedChunkList() {
    for (auto &pos : followedLoadingPositions) {
        generateChunksByPosition(pos);
    }
}

Chunk *ChunkLoadManager::generateChunk(ChunkPosition &chunkPosition) {
    ChunkPlan *cp = worldPlanner->getChunkPlan(chunkPosition);
    return new Chunk(chunkPosition, *cp, entityFactory);
}

Chunk *ChunkLoadManager::getChunk(ChunkPosition chunkPosition) {
    return (*chunks)[chunkPosition];
}

int ChunkLoadManager::getChunksLoadedCount() {
    return chunks->size();
}

int ChunkLoadManager::getEntitiesCreatedCount() {
    int sum = 0;
    for (auto &chunkPair : *chunks)
        sum += chunkPair.second->entitiesLoadedCount();
    return sum;
}

ChunkPositionsSet *ChunkLoadManager::getLoadedChunkList() {
    // TODO: Is this piece of code destined to be a cancer, or is there a way?
    int n = getChunksLoadedCount();
    ChunkPositionsSet *cps = new ChunkPositionsSet {
        new ChunkPosition[n], n
    };
    int i = 0;
    for (auto &p : *chunks) {
        cps->chunkPositions[i] = p.first;
        i += 1;
    }
    return cps;
}
