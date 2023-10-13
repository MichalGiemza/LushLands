#include "stdafx.h"
#include "ChunkLoadManager.h"

ChunkLoadManager::ChunkLoadManager(std::unordered_map<ChunkPosition, Chunk *> *chunks, BaseWorldPlanner *worldPlanner, EntityFactory *entityFactory, ItemFactory *itemFactory, InputEvents *inputEvents) :
    entityFactory(entityFactory), itemFactory(itemFactory), chunks(chunks), worldPlanner(worldPlanner), inputEvents(inputEvents) { }

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
    return new Chunk(chunkPosition, *cp, entityFactory, itemFactory, inputEvents);
}

Chunk *ChunkLoadManager::getChunk(ChunkPosition &chunkPosition) {
    auto result = (*chunks).find(chunkPosition);
    if (result != (*chunks).end())
        return result->second;
    return 0;
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

std::vector<Chunk *> ChunkLoadManager::getActiveChunks() {
    std::vector<Chunk *> activeChunks;
    for (auto &p : *chunks)
        activeChunks.push_back(p.second);
    return activeChunks;
}
