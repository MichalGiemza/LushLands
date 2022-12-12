#include "Camera.h"

int Camera::left() {
    return (getPosition()->getCameraX() - displayWidth / 2) * 100 / zoom;
}

int Camera::right() {
    return (getPosition()->getCameraX() + displayWidth / 2) * 100 / zoom;
}

int Camera::top() {
    return (getPosition()->getCameraZ() - displayHeight / 2) * 100 / zoom;
}

int Camera::bottom() {
    return (getPosition()->getCameraZ() + displayHeight / 2) * 100 / zoom;
}

int Camera::level() {
    return getPosition()->y();
}
Camera::Camera(Position *startingPosition, Focus *focus, InputEvents *inputEvents) : GameElement(f::CAMERA, INT_MAX, f::STATIC_UI) {
    this->independentPosition = startingPosition;
    focus->setFocusedObject(this);
    inputEvents->subscribeSystemEvent(camera_move_north, handleMovement, this);
}

Position *Camera::getPosition() {
    if (followedPosition)
        return followedPosition;
    return independentPosition;
}

bool Camera::isAreaVisible(Position *position, Size *size) {
    /** Calculated in standard position metric, not pixels. */
    return position->x() + size->w() <= right() && position->x() >= left() 
        && position->z() + size->l() <= bottom() && position->z() >= top();
}

void handleMovement(ALLEGRO_EVENT *ae, void *obj) {
    Camera *c = (Camera *)obj;
    switch (ae->type) {
    case camera_move_north:
        c->independentPosition->setAccurateZ(c->independentPosition->getAccurateZ() - c->scrollSpeed);
        break;
    case camera_move_south:
        c->independentPosition->setAccurateZ(c->independentPosition->getAccurateZ() + c->scrollSpeed);
        break;
    case camera_move_east:
        c->independentPosition->setAccurateX(c->independentPosition->getAccurateX() - c->scrollSpeed);
        break;
    case camera_move_west:
        c->independentPosition->setAccurateX(c->independentPosition->getAccurateX() + c->scrollSpeed);
        break;
    default:
        break;
    }
}
