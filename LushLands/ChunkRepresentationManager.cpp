#include "ChunkRepresentationManager.h"

void ChunkRepresentationManager::updateVisibleChunkRepresentations() {
    int level = camera->getPosition()->getY();
    auto cPositions = camera->getPosition()->getNeighbouringChunkPositions();

    for (auto i = 0; i < cPositions.n; i++) {
        auto cPos = cPositions.chunkPositions[i];
        if (!chunkRepresentations[cPos]) {
            auto chunk = world->getChunkLoadManager()->getChunk(cPos);
            if (!chunk) { // TODO: Dodaæ ³adowanie chunków
                Logger::log(lg::DEBUG_CHUNK, "Chunk [%i, %i] was not loaded yet!", cPos.x, cPos.z);
                continue;
            }
            chunkRepresentations[cPos] = new ChunkRepresentation(display, cPos, chunk->getChunkElements(), textureManager);
        }
    }
}

ChunkRepresentationManager::ChunkRepresentationManager(World *world, Display *display, Camera *camera, TextureManager *textureManager) :
    textureManager(textureManager), camera(camera), world(world), display(display) {
    chunkRepresentations = std::unordered_map<ChunkPosition, ChunkRepresentation *>();
}

void ChunkRepresentationManager::draw(miliseconds time, bool showDebug) {
    int level = camera->getPosition()->getY();
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
            drawItems(cRep, level, time);
            drawStructures(cRep, level);
            drawAnimals(cRep, level);
            drawHumanoids(cRep, level);
            if (showDebug) {
                drawAnimalDebug(cRep, level);
                drawItemsDebug(cRep, level);
                drawStructureDebug(cRep, level);
                drawHumanoidDebug(cRep, level);
                drawChunkDebug(cRep);
            }
        }
    }
}

void ChunkRepresentationManager::drawGround(ChunkRepresentation *cRep, int level) {
    auto groundBitmap = cRep->getBitmap(level);
    // TODO: Dodaæ zoom przez dzielenie wielkoœci bitmapy + manipulacja pozycjami
    pxint x = camera->shiftToScreenPosX(cRep->getPosition()->getPX());
    pxint z = camera->shiftToScreenPosZ(cRep->getPosition()->getPZ());
    if (groundBitmap)
        al_draw_bitmap(groundBitmap, x, z, 0);
}

void ChunkRepresentationManager::drawItems(ChunkRepresentation *cRep, int level, miliseconds t) { // TODO: Uogólniæ to i struktury do draw independent structure i póŸniej jednoliniowe metody o tych nazwach dobieraj¹ce w³aœciwy zestaw do rysowania do uogólnionej metody
    auto items = &cRep->getChunkElements()->items;
    std::hash<void *> ptr_hash;
    for (auto item = items->begin(); item != items->end(); ++item) {
        Item *it = (Item *)(*item);
        Position *p = it->getPosition();
        if (p->getY() != level)
            continue;
        // TODO: Dodaæ zoom przez dzielenie wielkoœci bitmapy + manipulacja pozycjami
        auto sBitmap = textureManager->getNamedTexture(it->getType());

        int randomDelay = ptr_hash(it) % 100000;
        float bumpingPosZ = std::sinf((t + randomDelay) / 200.0f) * meter / 10.0f;

        pxint x1 = shiftTexturePositionX(camera->shiftToScreenPosX(p->getPX() + meter * 2 / 5), al_get_bitmap_width(sBitmap), 0);
        pxint z1 = shiftTexturePositionZ(camera->shiftToScreenPosZ(p->getPZ() + meter * 9 / 10), al_get_bitmap_height(sBitmap), 0);
        al_draw_filled_ellipse(x1, z1, 10.0f, 4.0f, ITEM_SHADOW_COLOR.getAllegroColor());

        x1 = shiftTexturePositionX(camera->shiftToScreenPosX(p->getPX()), al_get_bitmap_width(sBitmap), 0);
        z1 = shiftTexturePositionZ(camera->shiftToScreenPosZ(p->getPZ() - bumpingPosZ), al_get_bitmap_height(sBitmap), 0);
        al_draw_bitmap(sBitmap, x1, z1, 0);

    }
}

void ChunkRepresentationManager::drawStructures(ChunkRepresentation *cRep, int level) {
    auto structures = &cRep->getChunkElements()->structures;
    for (auto sPair = structures->begin(); sPair != structures->end(); ++sPair) {
        if (sPair->first.y != level)
            continue;
        auto str = (Structure *)sPair->second;
        auto ctr = str->getBody()->getCenter();
        auto size = str->getSize();
        // TODO: Dodaæ zoom przez dzielenie wielkoœci bitmapy + manipulacja pozycjami
        auto sBitmap = textureManager->getNamedTexture(sPair->second->getType());

        pxint x1 = shiftTexturePositionX(camera->shiftToScreenPosX(ctr->getPX()), al_get_bitmap_width(sBitmap), size->getCameraW());
        pxint z1 = shiftTexturePositionZ(camera->shiftToScreenPosZ(ctr->getPZ()), al_get_bitmap_height(sBitmap), size->getCameraL());

        al_draw_bitmap(sBitmap, x1, z1, 0);
    }
}

void ChunkRepresentationManager::drawAnimals(ChunkRepresentation *cRep, int level) { // TODO: Uogólniæ to i struktury do draw independent structure i póŸniej jednoliniowe metody o tych nazwach dobieraj¹ce w³aœciwy zestaw do rysowania do uogólnionej metody
    auto animals = &cRep->getChunkElements()->animals;
    for (auto entity = animals->begin(); entity != animals->end(); ++entity) {
        auto anm = (Animal *)(*entity);
        if (anm->getPosition()->getY() != level)
            continue;
        auto ctr = anm->getBody()->getCenter();
        auto size = anm->getSize();
        // TODO: Dodaæ zoom przez dzielenie wielkoœci bitmapy + manipulacja pozycjami
        auto sBitmap = textureManager->getNamedTexture(anm->getType());

        pxint x1 = shiftTexturePositionX(camera->shiftToScreenPosX(ctr->getPX()), al_get_bitmap_width(sBitmap), size->getCameraW());
        pxint z1 = shiftTexturePositionZ(camera->shiftToScreenPosZ(ctr->getPZ()), al_get_bitmap_height(sBitmap), size->getCameraL());

        al_draw_bitmap(sBitmap, x1, z1, 0);
    }
}

void ChunkRepresentationManager::drawHumanoids(ChunkRepresentation *cRep, int level) { // TODO: Uogólniæ to i struktury do draw independent structure i póŸniej jednoliniowe metody o tych nazwach dobieraj¹ce w³aœciwy zestaw do rysowania do uogólnionej metody
    auto humanoids = &cRep->getChunkElements()->humanoids;
    for (auto entity = humanoids->begin(); entity != humanoids->end(); ++entity) {
        auto hmn = (Humanoid *)(*entity);
        if (hmn->getPosition()->getY() != level)
            continue;
        auto ctr = hmn->getBody()->getCenter();
        auto size = hmn->getSize();
        // TODO: Dodaæ zoom przez dzielenie wielkoœci bitmapy + manipulacja pozycjami
        auto sBitmap = textureManager->getNamedTexture(hmn->getType());

        pxint x1 = shiftTexturePositionX(camera->shiftToScreenPosX(ctr->getPX()), al_get_bitmap_width(sBitmap), size->getCameraW());
        pxint z1 = shiftTexturePositionZ(camera->shiftToScreenPosZ(ctr->getPZ()), al_get_bitmap_height(sBitmap), size->getCameraL());

        al_draw_bitmap(sBitmap, x1, z1, 0);
    }
}

void ChunkRepresentationManager::drawChunkDebug(ChunkRepresentation *cRep) {
    // TODO: Dodaæ zoom przez dzielenie wielkoœci bitmapy + manipulacja pozycjami
    pxint x1 = camera->shiftToScreenPosX(cRep->getPosition()->getPX());
    pxint z1 = camera->shiftToScreenPosZ(cRep->getPosition()->getPZ());
    pxint x2 = camera->shiftToScreenPosX(cRep->getPosition()->getPX()) + chunkSizeByTiles * chunkSizeByTiles;
    pxint z2 = camera->shiftToScreenPosZ(cRep->getPosition()->getPZ()) + chunkSizeByTiles * chunkSizeByTiles;
    al_draw_rectangle(x1, z1, x2, z2, DEBUG_CHUNK_BORDER_COLOR.getAllegroColor(), 1.0f);
}

void ChunkRepresentationManager::drawStructureDebug(ChunkRepresentation *cRep, int level) {
    auto structures = &cRep->getChunkElements()->structures;
    for (auto sPair = structures->begin(); sPair != structures->end(); ++sPair) {
        if (sPair->first.y != level)
            continue;
        auto str = (Structure *)sPair->second;
        auto ctr = str->getBody()->getCenter();
        auto size = str->getSize();
        // Draw outline
        pxint x1 = camera->shiftToScreenPosX(ctr->getPX()) - size->getCameraW() / 2;
        pxint z1 = camera->shiftToScreenPosZ(ctr->getPZ()) - size->getCameraL() / 2;
        pxint x2 = camera->shiftToScreenPosX(ctr->getPX()) + size->getCameraW() / 2;
        pxint z2 = camera->shiftToScreenPosZ(ctr->getPZ()) + size->getCameraL() / 2;
        al_draw_rectangle(x1, z1, x2, z2, DEBUG_STRUCTURE_BORDER_COLOR.getAllegroColor(), 1.0f);
    }
}

void ChunkRepresentationManager::drawItemsDebug(ChunkRepresentation *cRep, int level) {
    auto items = &cRep->getChunkElements()->items;
    for (auto item = items->begin(); item != items->end(); ++item) {
        auto it = (Item *)(*item);
        if (it->getPosition()->getY() != level)
            continue;
        auto ctr = it->getPosition();
        // Draw magnet radius
        pxint x1 = camera->shiftToScreenPosX(ctr->getPX());
        pxint z1 = camera->shiftToScreenPosZ(ctr->getPZ());
        al_draw_circle(x1, z1, itemMagnetRadius * tileSizePx, DEBUG_ITEM_BORDER_COLOR.getAllegroColor(), 1.0f);
    }
}

void ChunkRepresentationManager::drawAnimalDebug(ChunkRepresentation *cRep, int level) { // TODO: To te¿ uogólniæ
    auto animals = &cRep->getChunkElements()->animals;
    for (auto entity = animals->begin(); entity != animals->end(); ++entity) {
        auto anm = (Animal *)(*entity);
        if (anm->getPosition()->getY() != level)
            continue;
        auto ctr = anm->getBody()->getCenter();
        auto size = anm->getSize();
        // Draw outline
        pxint x1 = camera->shiftToScreenPosX(ctr->getPX()) - size->getCameraW() / 2;
        pxint z1 = camera->shiftToScreenPosZ(ctr->getPZ()) - size->getCameraL() / 2;
        pxint x2 = camera->shiftToScreenPosX(ctr->getPX()) + size->getCameraW() / 2;
        pxint z2 = camera->shiftToScreenPosZ(ctr->getPZ()) + size->getCameraL() / 2;
        al_draw_rectangle(x1, z1, x2, z2, DEBUG_ANIMAL_BORDER_COLOR.getAllegroColor(), 1.0f);
        // Draw collision indicators
        if (anm->getCollider()->isInCollisionLeft())
            al_draw_line(x1, z1, x1, z2, DEBUG_ANIMAL_BORDER_COLOR.getAllegroColor(), 3.0f);
        if (anm->getCollider()->isInCollisionRight())
            al_draw_line(x2, z1, x2, z2, DEBUG_ANIMAL_BORDER_COLOR.getAllegroColor(), 3.0f);
        if (anm->getCollider()->isInCollisionTop())
            al_draw_line(x1, z1, x2, z1, DEBUG_ANIMAL_BORDER_COLOR.getAllegroColor(), 3.0f);
        if (anm->getCollider()->isInCollisionBottom())
            al_draw_line(x1, z2, x2, z2, DEBUG_ANIMAL_BORDER_COLOR.getAllegroColor(), 3.0f);
        // Draw direction vector
        if (not std::isnan(anm->getMobility()->getDirection())) {
            x1 = camera->shiftToScreenPosX(ctr->getPX());
            z1 = camera->shiftToScreenPosZ(ctr->getPZ());
            x2 = camera->shiftToScreenPosX(ctr->getPX() - std::sin(anm->getMobility()->getDirection()) * sqrt(anm->getMobility()->getMovementSpeed() * meter) * 3);
            z2 = camera->shiftToScreenPosZ(ctr->getPZ() + std::cos(anm->getMobility()->getDirection()) * sqrt(anm->getMobility()->getMovementSpeed() * meter) * 3);
            al_draw_line(x1, z1, x2, z2, DEBUG_ANIMAL_BORDER_COLOR.getAllegroColor(), 1.0f);
        }
    }
}

void ChunkRepresentationManager::drawHumanoidDebug(ChunkRepresentation *cRep, int level) { // TODO: To te¿ uogólniæ
    auto humanoids = &cRep->getChunkElements()->humanoids;
    for (auto entity = humanoids->begin(); entity != humanoids->end(); ++entity) {
        auto hmn = (Humanoid *)(*entity);
        if (hmn->getPosition()->getY() != level)
            continue;
        auto ctr = hmn->getBody()->getCenter();
        auto size = hmn->getSize();
        // Draw outline
        pxint x1 = camera->shiftToScreenPosX(ctr->getPX()) - size->getCameraW() / 2;
        pxint z1 = camera->shiftToScreenPosZ(ctr->getPZ()) - size->getCameraL() / 2;
        pxint x2 = camera->shiftToScreenPosX(ctr->getPX()) + size->getCameraW() / 2;
        pxint z2 = camera->shiftToScreenPosZ(ctr->getPZ()) + size->getCameraL() / 2;
        al_draw_rectangle(x1, z1, x2, z2, DEBUG_ANIMAL_BORDER_COLOR.getAllegroColor(), 1.0f);
        // Draw collision indicators
        if (hmn->getCollider()->isInCollisionLeft())
            al_draw_line(x1, z1, x1, z2, DEBUG_ANIMAL_BORDER_COLOR.getAllegroColor(), 3.0f);
        if (hmn->getCollider()->isInCollisionRight())
            al_draw_line(x2, z1, x2, z2, DEBUG_ANIMAL_BORDER_COLOR.getAllegroColor(), 3.0f);
        if (hmn->getCollider()->isInCollisionTop())
            al_draw_line(x1, z1, x2, z1, DEBUG_ANIMAL_BORDER_COLOR.getAllegroColor(), 3.0f);
        if (hmn->getCollider()->isInCollisionBottom())
            al_draw_line(x1, z2, x2, z2, DEBUG_ANIMAL_BORDER_COLOR.getAllegroColor(), 3.0f);
        // Draw direction vector
        if (not std::isnan(hmn->getMobility()->getDirection())) {
            x1 = camera->shiftToScreenPosX(ctr->getPX());
            z1 = camera->shiftToScreenPosZ(ctr->getPZ());
            x2 = camera->shiftToScreenPosX(ctr->getPX() - std::sin(hmn->getMobility()->getDirection()) * sqrt(hmn->getMobility()->getMovementSpeed() * meter) * 3);
            z2 = camera->shiftToScreenPosZ(ctr->getPZ() + std::cos(hmn->getMobility()->getDirection()) * sqrt(hmn->getMobility()->getMovementSpeed() * meter) * 3);
            al_draw_line(x1, z1, x2, z2, DEBUG_ANIMAL_BORDER_COLOR.getAllegroColor(), 1.0f);
        }
    }
}

pxint ChunkRepresentationManager::shiftTexturePositionX(pxint screenPositionX, pxint bitmapWidth, pxint bbWidth) {
    return screenPositionX - bitmapWidth / 2;
}

pxint ChunkRepresentationManager::shiftTexturePositionZ(pxint screenPositionZ, pxint bitmapHeight, pxint bbHeight) {
    return screenPositionZ - bitmapHeight / 2 - (bitmapHeight - bbHeight) / 2;
}
