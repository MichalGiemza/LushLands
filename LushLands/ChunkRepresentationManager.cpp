#include "ChunkRepresentationManager.h"

void ChunkRepresentationManager::updateVisibleChunkRepresentations() {
    int level = camera->getFollowedPosition()->y();
    auto cPositions = camera->getFollowedPosition()->getNeighbouringChunkPositions();

    for (auto i = 0; i < cPositions.n; i++) {
        auto cPos = cPositions.chunkPositions[i];
        if (!chunkRepresentations[cPos]) {
            auto chunk = world->getChunkLoadManager()->getChunk(cPos);
            chunkRepresentations[cPos] = new ChunkRepresentation(display, cPos, *chunk->getGround(), *chunk->getStructures(), textureManager);
        }
    }
}

ChunkRepresentationManager::ChunkRepresentationManager(World *world, Display *display, Camera *camera, TextureManager *textureManager) {
    this->textureManager = textureManager;
    this->camera = camera;
    this->world = world;
    this->display = display;
    chunkRepresentations = std::unordered_map<ChunkPosition, ChunkRepresentation *>();
}

void ChunkRepresentationManager::draw() {
    int level = camera->getFollowedPosition()->y();
    auto cPositions = camera->getFollowedPosition()->getNeighbouringChunkPositions();
    Size chunkSize = Size(chunkSizeByTiles, 0, chunkSizeByTiles);

    updateVisibleChunkRepresentations();
    for (auto i = 0; i < cPositions.n; i++) {
        auto cPos = cPositions.chunkPositions[i];
        auto cRep = chunkRepresentations[cPos];
        if (camera->isAreaVisible(cRep->getPosition(), &chunkSize)) {
            auto chunkBitmap = cRep->getBitmap(level);
            Position chunkDrawPos = (*cRep->getPosition()) - *(camera->getFollowedPosition());
            // TODO: Dodaæ zoom przez dzielenie wielkoœci bitmapy + manipulacja pozycjami
            al_draw_bitmap(chunkBitmap, chunkDrawPos.getCameraX(), chunkDrawPos.getCameraZ(), 0);
        }
    }
}


