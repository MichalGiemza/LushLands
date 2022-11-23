#include "Body.h"

Body::Body(Position position, Size size) : position(position), size(size) {}

Position Body::getCenter() {
    return Position(
        position.x() + size.w() / 2, 
        position.y() + size.h() / 2, 
        position.z() + size.l() / 2
    );
}

Position Body::getTopLeft() {
    return Position(position);
}

Position Body::getBottomRight() {
    return Position(
        position.x() + size.w(),
        position.y() + size.h(),
        position.z() + size.l()
    );
}

Size Body::getSize() {
    return Size(size);
}
