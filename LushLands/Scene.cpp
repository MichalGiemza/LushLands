#include "Scene.h"

Scene::Scene(scenename sceneName, World *world, Display *display, Position *followedPosition) : chunkRepresentationManager(world, display), camera(followedPosition) {
    this->world = world;
    this->display = display;
    name = sceneName;
}

void Scene::draw() {
    chunkRepresentationManager.draw(camera);
}

void Scene::drawChunkGround(ChunkRepresentation &chunkRepresentation, int level) {
    Position pos = Position(*chunkRepresentation.getChunkPosition());
    al_draw_bitmap(chunkRepresentation.getBitmap(level), pos.x(), pos.y(), 0);
}
