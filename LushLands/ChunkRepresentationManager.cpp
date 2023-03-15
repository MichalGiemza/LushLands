#include "ChunkRepresentationManager.h"

void ChunkRepresentationManager::updateVisibleChunkRepresentations() {
    int level = camera->getPosition()->y();
    auto cPositions = camera->getPosition()->getNeighbouringChunkPositions();

    for (auto i = 0; i < cPositions.n; i++) {
        auto cPos = cPositions.chunkPositions[i];
        if (!chunkRepresentations[cPos]) {
            auto chunk = world->getChunkLoadManager()->getChunk(cPos);
            if (!chunk) { // TODO: Dodaæ ³adowanie chunków
                Logger::log(ll::DEBUG_CHUNK, "Chunk [%i, %i] was not loaded yet!", cPos.x, cPos.z);
                continue;
            }
            chunkRepresentations[cPos] = new ChunkRepresentation(display, cPos, *chunk->getGround(), *chunk->getStructures(), *chunk->getAnimals(), textureManager);
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
    int level = camera->getPosition()->y();
    auto cPositions = camera->getPosition()->getNeighbouringChunkPositions();
    Size chunkSize = Size(chunkSizeByTiles, 0, chunkSizeByTiles);

    updateVisibleChunkRepresentations();
    for (auto i = 0; i < cPositions.n; i++) {
        auto cPos = cPositions.chunkPositions[i];
        auto cRep = chunkRepresentations[cPos];
        if (!cRep) // TODO: Obs³uga braku reprezentacji chunku
            continue;
        if (camera->isAreaVisible(cRep->getArea())) {
            drawGround(cRep, level);
            drawStructures(cRep, level);
            drawAnimals(cRep, level);
            if (DEBUG) {
                drawAnimalOutlines(cRep, level);
                drawStructureOutlines(cRep, level);
                drawChunkBorders(cRep);
            }
        }
    }
}

void ChunkRepresentationManager::drawGround(ChunkRepresentation *cRep, int level) {
    auto groundBitmap = cRep->getBitmap(level);
    // TODO: Dodaæ zoom przez dzielenie wielkoœci bitmapy + manipulacja pozycjami
    pxint x = camera->shiftToScreenPosX(cRep->getPosition()->getPX());
    pxint z = camera->shiftToScreenPosZ(cRep->getPosition()->getPZ());
    al_draw_bitmap(groundBitmap, x, z, 0);
}

void ChunkRepresentationManager::drawStructures(ChunkRepresentation *cRep, int level) {
    auto structures = cRep->getStructures();
    for (auto sPair = structures->begin(); sPair != structures->end(); ++sPair) {
        if (sPair->first.y != level)
            continue;
        auto str = (Structure *)sPair->second;
        // TODO: Dodaæ zoom przez dzielenie wielkoœci bitmapy + manipulacja pozycjami
        auto sBitmap = textureManager->getEntityTexture(sPair->second->getType());
        pxint x = shiftTexturePositionX(
            camera->shiftToScreenPosX(str->getPosition()->getPX()),
            al_get_bitmap_width(sBitmap));
        pxint z = shiftTexturePositionZ(
            camera->shiftToScreenPosZ(str->getPosition()->getPZ()),
            al_get_bitmap_height(sBitmap));
        al_draw_bitmap(sBitmap, x, z, 0);
    }
}

void ChunkRepresentationManager::drawAnimals(ChunkRepresentation *cRep, int level) { // TODO: Uogólniæ to i struktury do draw independent structure i póŸniej jednoliniowe metody o tych nazwach dobieraj¹ce w³aœciwy zestaw do rysowania do uogólnionej metody
    auto animals = cRep->getAnimals();
    for (auto sPair = animals->begin(); sPair != animals->end(); ++sPair) {
        if (sPair->first.y != level)
            continue;
        auto anm = (Animal *)sPair->second;
        // TODO: Dodaæ zoom przez dzielenie wielkoœci bitmapy + manipulacja pozycjami
        auto sBitmap = textureManager->getEntityTexture(sPair->second->getType());
        pxint x = shiftTexturePositionX(
            camera->shiftToScreenPosX(anm->getPosition()->getPX()),
            al_get_bitmap_width(sBitmap));
        pxint z = shiftTexturePositionZ(
            camera->shiftToScreenPosZ(anm->getPosition()->getPZ()),
            al_get_bitmap_height(sBitmap));
        al_draw_bitmap(sBitmap, x, z, 0);
    }
}

void ChunkRepresentationManager::drawChunkBorders(ChunkRepresentation *cRep) {
    // TODO: Dodaæ zoom przez dzielenie wielkoœci bitmapy + manipulacja pozycjami
    pxint x1 = camera->shiftToScreenPosX(cRep->getPosition()->getPX());
    pxint z1 = camera->shiftToScreenPosZ(cRep->getPosition()->getPZ());
    pxint x2 = camera->shiftToScreenPosX(cRep->getPosition()->getPX()) + chunkSizeByTiles * chunkSizeByTiles;
    pxint z2 = camera->shiftToScreenPosZ(cRep->getPosition()->getPZ()) + chunkSizeByTiles * chunkSizeByTiles;
    al_draw_rectangle(x1, z1, x2, z2, DEBUG_CHUNK_BORDER_COLOR.getAllegroColor(), 1.0f);
}

void ChunkRepresentationManager::drawStructureOutlines(ChunkRepresentation *cRep, int level) {
    auto structures = cRep->getStructures();
    for (auto sPair = structures->begin(); sPair != structures->end(); ++sPair) {
        if (sPair->first.y != level)
            continue;
        auto str = (Structure *)sPair->second;
        // TODO: Dodaæ zoom przez dzielenie wielkoœci bitmapy + manipulacja pozycjami
        auto sBitmap = textureManager->getEntityTexture(sPair->second->getType());
        pxint x1 = shiftTexturePositionX(
            camera->shiftToScreenPosX(str->getPosition()->getPX()), 
            str->getSize()->getCameraW());
        pxint z1 = shiftTexturePositionZ(
            camera->shiftToScreenPosZ(str->getPosition()->getPZ()), 
            str->getSize()->getCameraL());
        pxint x2 = shiftTexturePositionX(
            camera->shiftToScreenPosX(str->getPosition()->getPX()) + str->getSize()->getCameraW(),
            str->getSize()->getCameraW());
        pxint z2 = shiftTexturePositionZ(
            camera->shiftToScreenPosZ(str->getPosition()->getPZ()) + str->getSize()->getCameraL(),
            str->getSize()->getCameraL());
        al_draw_rectangle(x1, z1, x2, z2, str->getColor()->getAllegroColor(), 1.0f);
    }
}

void ChunkRepresentationManager::drawAnimalOutlines(ChunkRepresentation *cRep, int level) { // TODO: To te¿ uogólniæ
    auto animals = cRep->getAnimals();
    for (auto sPair = animals->begin(); sPair != animals->end(); ++sPair) {
        if (sPair->first.y != level)
            continue;
        auto anm = (Animal *)sPair->second;
        // TODO: Dodaæ zoom przez dzielenie wielkoœci bitmapy + manipulacja pozycjami
        auto sBitmap = textureManager->getEntityTexture(sPair->second->getType());
        pxint x1 = shiftTexturePositionX(
            camera->shiftToScreenPosX(anm->getPosition()->getPX()),
            anm->getSize()->getCameraW());
        pxint z1 = shiftTexturePositionZ(
            camera->shiftToScreenPosZ(anm->getPosition()->getPZ()),
            anm->getSize()->getCameraL());
        pxint x2 = shiftTexturePositionX(
            camera->shiftToScreenPosX(anm->getPosition()->getPX()) + anm->getSize()->getCameraW(),
            anm->getSize()->getCameraW());
        pxint z2 = shiftTexturePositionZ(
            camera->shiftToScreenPosZ(anm->getPosition()->getPZ()) + anm->getSize()->getCameraL(),
            anm->getSize()->getCameraL());
        al_draw_rectangle(x1, z1, x2, z2, anm->getColor()->getAllegroColor(), 1.0f);
    }
}

pxint ChunkRepresentationManager::shiftTexturePositionX(pxint screenPositionX, pxint bitmapWidth) {
    if (bitmapWidth >= 32) // Fixme: Magic number, but which one?
        return tileSizePx - bitmapWidth + screenPositionX;
    else
        return tileSizePx / 2 - bitmapWidth / 2 + screenPositionX;
}

pxint ChunkRepresentationManager::shiftTexturePositionZ(pxint screenPositionZ, pxint bitmapHeight) {
    if (bitmapHeight >= 32)
        return tileSizePx - bitmapHeight + screenPositionZ;
    else
        return tileSizePx / 2 - bitmapHeight / 2 + screenPositionZ;
}
