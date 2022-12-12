#include "Scene.h"

Scene::Scene(scenename sceneName, World *world, Display *display, Position *followedPosition, InputEvents *inputEvents, TextureManager *textureManager, Focus *focus) 
    : camera(followedPosition, focus, inputEvents), chunkRepresentationManager(world, display, &camera, textureManager) {
    this->textureManager = textureManager;
    this->world = world;
    this->display = display;
    this->inputEvents = inputEvents;
    name = sceneName;
    inputEvents->subscribeTimerFPS(1, draw, this);
}

void Scene::drawChunkGround(ChunkRepresentation &chunkRepresentation, int level) {
    Position pos = Position(*chunkRepresentation.getChunkPosition());
    al_draw_bitmap(chunkRepresentation.getBitmap(level), pos.x(), pos.y(), 0);
}

void draw(ALLEGRO_EVENT *ae, void *scene) {
    Scene *s = (Scene *)scene;
    al_clear_to_color(al_map_rgb_f(0, 0, 0));
    s->chunkRepresentationManager.draw();
    al_flip_display();
}
