#include "Camera.h"

int Camera::left() {
    return (followedPosition->getCameraX() - displayWidth / 2) * 100 / zoom;
}

int Camera::right() {
    return (followedPosition->getCameraX() + displayWidth / 2) * 100 / zoom;
}

int Camera::top() {
    return (followedPosition->getCameraZ() - displayHeight / 2) * 100 / zoom;
}

int Camera::bottom() {
    return (followedPosition->getCameraZ() + displayHeight / 2) * 100 / zoom;
}

Camera::Camera(Position *followedPosition) {
    this->followedPosition = followedPosition;
    // TODO: Add to update
}

Position *Camera::getFollowedPosition() {
    return followedPosition;
}

bool Camera::isAreaVisible(Position *position, Size *size) {
    /** Calculated in standard position metric, not pixels. */
    return position->x() + size->w() <= right() && position->x() >= left()
        && position->z() + size->l() <= bottom() && position->z() >= top();
}
