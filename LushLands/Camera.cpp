#include "Camera.h"

int Camera::level() {
    return getFrame()->getPosition()->getY();
}

Camera::Camera(Position *startingPosition, Focus *focus, InputEvents *inputEvents) : GameElement(ft::CAMERA, fp::DEFAULT, fg::STATIC_UI) {
    int inGameScreenW = displayWidth / tileSizePx;
    int inGameScreenH = displayHeight / tileSizePx;
    independentFrame = new WorldRectangle(0, 0, inGameScreenW, inGameScreenH, false, true);

    this->independentFrame->setPosition(startingPosition);
    if (not focus->getCurrentlyActiveGameElement())
        focus->setFocusedObject(this);

    inputEvents->subscribeSystemEvent(camera_move, handleMovementAttempt, this);
    inputEvents->subscribeTimerFPS(0, handleMovement, this);
}

WorldRectangle *Camera::getFrame() {
    if (followedFrame)
        return followedFrame;
    return independentFrame;
}

Position *Camera::getPosition() {
    return getFrame()->getPosition();
}

void Camera::setFollowedPosition(Position *position) {
    followedFrame = new WorldRectangle(
        0, 0, independentFrame->getSize()->getPW(), 
        independentFrame->getSize()->getPL(), true, true);
    followedFrame->setPosition(position);
}

bool Camera::isAreaVisible(WorldRectangle *area) {
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
    return (accurateWorldX - getPosition()->getPX()) * tileSizePx / representationComaValue + displayWidth / 2;
}

pxint Camera::shiftToScreenPosZ(int accurateWorldZ) {
    /**
    * Position of object -> shift by position of camera -> convert position to pixels
    */
    return (accurateWorldZ - getPosition()->getPZ()) * tileSizePx / representationComaValue + displayHeight / 2;
}

void handleMovementAttempt(ALLEGRO_EVENT *ae, void *obj) {
    Camera *c = (Camera *)obj;
    keycode key = 0;
    EventFactory::unpackKeyboardLetter(ae, &key);

    switch (key) {
    case ALLEGRO_KEY_W:
    case ALLEGRO_KEY_UP:
        c->pN = true;
        break;
    case ALLEGRO_KEY_S:
    case ALLEGRO_KEY_DOWN:
        c->pS = true;
        break;
    case ALLEGRO_KEY_A:
    case ALLEGRO_KEY_LEFT:
        c->pW = true;
        break;
    case ALLEGRO_KEY_D:
    case ALLEGRO_KEY_RIGHT:
        c->pE = true;
        break;
    default:
        break;
    }
}

void handleMovement(ALLEGRO_EVENT *ae, void *obj) {
    Camera *c = (Camera *)obj;
    radian direction = NumTools::directionToRadian(c->pN, c->pS, c->pE, c->pW);
    
    c->pN = false;
    c->pS = false;
    c->pE = false;
    c->pW = false;

    if (isnan(direction))
        return;

    c->getPosition()->setPX(c->getPosition()->getPX() - std::sin(direction) * c->scrollSpeed);
    c->getPosition()->setPZ(c->getPosition()->getPZ() + std::cos(direction) * c->scrollSpeed);
}
