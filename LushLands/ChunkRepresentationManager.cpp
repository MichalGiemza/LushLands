#include "ChunkRepresentationManager.h"

void ChunkRepresentationManager::updateVisibleChunkRepresentations(Camera &camera) {
    int level = camera.getFollowedPosition()->y();
    auto cPositions = camera.getFollowedPosition()->getNeighbouringChunkPositions();

    for (auto i = 0; i < cPositions.n; i++) {
        auto cPos = cPositions.chunkPositions[i];
        if (!chunkRepresentations[cPos]) {
            auto chunk = world->getChunkLoadManager()->getChunk(cPos);
            chunkRepresentations[cPos] = new ChunkRepresentation(display, cPos, *chunk->getGround(), *chunk->getStructures());
        }
    }
}

ChunkRepresentationManager::ChunkRepresentationManager(World *world, Display *display) {
    this->world = world;
    chunkRepresentations = std::unordered_map<ChunkPosition, ChunkRepresentation *>();
}

void ChunkRepresentationManager::draw(Camera &camera) {
    int level = camera.getFollowedPosition()->y();
    auto cPositions = camera.getFollowedPosition()->getNeighbouringChunkPositions();
    Size chunkSize = Size(chunkSizeByTiles, 0, chunkSizeByTiles);

    updateVisibleChunkRepresentations(camera);
    for (auto i = 0; i < cPositions.n; i++) {
        auto cPos = cPositions.chunkPositions[i];
        auto cRep = chunkRepresentations[cPos];
        if (camera.isAreaVisible(cRep->getPosition(), &chunkSize)) {
            auto chunkBitmap = cRep->getBitmap(level);
            Position chunkDrawPos = (*cRep->getPosition()) - *camera.getFollowedPosition();
            // TODO: Dodaæ zoom przez dzielenie wielkoœci bitmapy + manipulacja pozycjami
            al_draw_bitmap(chunkBitmap, chunkDrawPos.getCameraX(), chunkDrawPos.getCameraZ(), 0);
        }
    }
}


