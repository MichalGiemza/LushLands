#include "stdafx.h"
#include "FieldCursor.h"


FieldCursor::FieldCursor(Camera *camera, InputEvents *inputEvents) :
    camera(camera), WorldUIElement(ft::WORLD_CURSOR, fp::UI) {
    inputEvents->subscribeMouseAxis(updatePosition, this); // TODO: Czêœciej updateowaæ ni¿ tylko na ruch myszy? Co z ruchem postaci i "zostawaniem" kwadracika?
}

void FieldCursor::draw() {
    pxint x1 = camera->shiftToScreenPosX((cursorInWorld.getX()) * representationComaValue);
    pxint z1 = camera->shiftToScreenPosZ((cursorInWorld.getZ()) * representationComaValue);
    pxint x2 = camera->shiftToScreenPosX((cursorInWorld.getX() + 1) * representationComaValue);
    pxint z2 = camera->shiftToScreenPosZ((cursorInWorld.getZ() + 1) * representationComaValue);
    
    al_draw_rectangle(x1, z1, x2, z2, WORLD_CURSOR_COLOR.getAllegroColor(), 3.0f);
}

Position *FieldCursor::getPrecisePosition() {
    return &precisePos;
}

Position *FieldCursor::getTilePosition() {
    return &cursorInWorld;
}

void updatePosition(ALLEGRO_EVENT *allegroEvent, void *caller) {
    FieldCursor *fc = (FieldCursor *)caller;
    Camera *c = fc->camera;
    // Tile position update
    fc->cursorInWorld.setPX(NumTools::customFloor((c->getPosition()->getPX() * tileSizePx + (allegroEvent->mouse.x - displayWidth / 2) * representationComaValue) / tileSizePx, representationComaValue));
    fc->cursorInWorld.setPZ(NumTools::customFloor((c->getPosition()->getPZ() * tileSizePx + (allegroEvent->mouse.y - displayHeight /2) * representationComaValue) / tileSizePx, representationComaValue));
    fc->cursorInWorld.setY(c->getPosition()->getY());
    // Precise position update
    fc->precisePos.setPX((c->getPosition()->getPX() * tileSizePx + (allegroEvent->mouse.x - displayWidth / 2) * representationComaValue) / tileSizePx);
    fc->precisePos.setPZ((c->getPosition()->getPZ() * tileSizePx + (allegroEvent->mouse.y - displayHeight / 2) * representationComaValue) / tileSizePx);
    fc->precisePos.setY(c->getPosition()->getY());
}
