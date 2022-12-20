#include "Camera.h"

int Camera::level() {
    return getFrame()->getPosition()->getY();
}

Camera::Camera(Position *startingPosition, Focus *focus, InputEvents *inputEvents) : GameElement(f::CAMERA, INT_MAX, f::STATIC_UI) {
    int inGameScreenW = displayWidth / tileSizePx;
    int inGameScreenH = displayHeight / tileSizePx;
    independentFrame = new Rectangle_(0, 0, inGameScreenW, inGameScreenH);

    this->independentFrame->setPosition(startingPosition);
    focus->setFocusedObject(this);
    inputEvents->subscribeSystemEvent(camera_move_north, handleMovement, this);
}

Rectangle_ *Camera::getFrame() {
    if (followedFrame)
        return followedFrame;
    return independentFrame;
}

Position *Camera::getPosition() {
    return getFrame()->getPosition();
}

void Camera::setFollowedPosition(Position *position) {
    followedFrame = new Rectangle_(
        0, 0, independentFrame->getSize()->getAccurateWidth(), 
        independentFrame->getSize()->getAccurateLength(), true);
    followedFrame->setPosition(position);
}

bool Camera::isAreaVisible(Rectangle_ *area) {
    /** 
    * Tells if area visible at least partially on camera.
    * Calculated in standard position metric, not pixels. 
    */
    return getFrame()->isOverlapping(area);
}

pxint Camera::shiftToScreenPosX(int accurateWorldX) {
    /**
    * Position of object -> shift by position of camera -> convert position to pixels
    */
    return (accurateWorldX - getPosition()->getAccurateX()) * tileSizePx / representationComaValue;
}

pxint Camera::shiftToScreenPosZ(int accurateWorldZ) {
    /**
    * Position of object -> shift by position of camera -> convert position to pixels
    */
    return (accurateWorldZ - getPosition()->getAccurateZ()) * tileSizePx / representationComaValue;
}

void handleMovement(ALLEGRO_EVENT *ae, void *obj) {
    Camera *c = (Camera *)obj;
    Position *p = c->getPosition();
    switch (ae->type) {
    case camera_move_north:
        p->setAccurateZ(p->getAccurateZ() - c->scrollSpeed);
        break;
    case camera_move_south:
        p->setAccurateZ(p->getAccurateZ() + c->scrollSpeed);
        break;
    case camera_move_east:
        p->setAccurateX(p->getAccurateX() - c->scrollSpeed);
        break;
    case camera_move_west:
        p->setAccurateX(p->getAccurateX() + c->scrollSpeed);
        break;
    default:
        break;
    }
}
