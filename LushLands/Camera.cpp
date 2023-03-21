#include "Camera.h"

int Camera::level() {
    return getFrame()->getPosition()->getY();
}

Camera::Camera(Position *startingPosition, Focus *focus, InputEvents *inputEvents) : GameElement(ft::CAMERA, fp::DEFAULT, fg::STATIC_UI) {
    int inGameScreenW = displayWidth / tileSizePx;
    int inGameScreenH = displayHeight / tileSizePx;
    independentFrame = new Rectangle_(0, 0, inGameScreenW, inGameScreenH);

    this->independentFrame->setPosition(startingPosition);
    if (not focus->getFocusedObject())
        focus->setFocusedObject(this);

    inputEvents->subscribeSystemEvent(camera_move_north, handleMovement, this);
    inputEvents->subscribeSystemEvent(camera_move_south, handleMovement, this);
    inputEvents->subscribeSystemEvent(camera_move_east, handleMovement, this);
    inputEvents->subscribeSystemEvent(camera_move_west, handleMovement, this);
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
        0, 0, independentFrame->getSize()->getPW(), 
        independentFrame->getSize()->getPL(), true);
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
    return (accurateWorldX - getPosition()->getPX()) * tileSizePx / representationComaValue;
}

pxint Camera::shiftToScreenPosZ(int accurateWorldZ) {
    /**
    * Position of object -> shift by position of camera -> convert position to pixels
    */
    return (accurateWorldZ - getPosition()->getPZ()) * tileSizePx / representationComaValue;
}

void handleMovement(ALLEGRO_EVENT *ae, void *obj) {
    Camera *c = (Camera *)obj;
    Position *p = c->getPosition();
    switch (ae->type) {
    case camera_move_north:
        p->setPZ(p->getPZ() - c->scrollSpeed);
        break;
    case camera_move_south:
        p->setPZ(p->getPZ() + c->scrollSpeed);
        break;
    case camera_move_east:
        p->setPX(p->getPX() - c->scrollSpeed);
        break;
    case camera_move_west:
        p->setPX(p->getPX() + c->scrollSpeed);
        break;
    default:
        break;
    }
}
