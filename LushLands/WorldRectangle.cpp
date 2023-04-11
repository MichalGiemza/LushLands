#include "WorldRectangle.h"

WorldRectangle::WorldRectangle(int x, int z, int w, int l, bool accurate, bool asCenter) {
	p = new Position(x, 0, z, accurate);
	s = new Size(w, 0, l, accurate);
	asCtr = asCenter;
}

int WorldRectangle::accurateLeft() const {
	return p->getPX() - asCtr * s->getPW() / 2;
}

int WorldRectangle::accurateRight() const {
	return p->getPX() + s->getPW() - asCtr * s->getPW() / 2;
}

int WorldRectangle::accurateTop() const {
	return p->getPZ() - asCtr * s->getPL() / 2;
}

int WorldRectangle::accurateBottom() const {
	return p->getPZ() + s->getPL() - asCtr * s->getPL() / 2;
}

int WorldRectangle::left() const {
	return accurateLeft() / representationComaValue;
}

int WorldRectangle::right() const {
	return accurateRight() / representationComaValue;
}

int WorldRectangle::top() const {
	return accurateTop() / representationComaValue;
}

int WorldRectangle::bottom() const {
	return accurateBottom() / representationComaValue;
}

void WorldRectangle::setPosition(Position *newPosition) {
	p = newPosition;
}

void WorldRectangle::setSize(Size *newSize) {
	s = newSize;
}

Position *WorldRectangle::getPosition() {
	return p;
}

Size *WorldRectangle::getSize() {
	return s;
}

bool WorldRectangle::isOverlapping(const WorldRectangle *other) const {
	// find the x and y distances between the centers of the two rectangles
	int dx = std::abs(accurateLeft() + s->getPW() / 2 - other->accurateLeft() - other->s->getPW() / 2);
	int dy = std::abs(accurateTop() + s->getPL() / 2 - other->accurateTop() - other->s->getPL() / 2);

	return dx <= (s->getPW() + other->s->getPW()) / 2 && dy <= (s->getPL() + other->s->getPL()) / 2;
}

bool WorldRectangle::pointBelongs(const Position &point) const {
	bool belongsX = accurateLeft() <= point.getPX() and point.getPX() <= accurateRight();
	bool belongsZ = accurateTop() <= point.getPY() and point.getPY() <= accurateBottom();
	return belongsX and belongsZ;
}

int WorldRectangle::accurateDistanceTo2D(const WorldRectangle *other) const {
	// find the x and y distances between the centers of the two rectangles
	int dx = std::abs(accurateLeft() + s->getPW() / 2 - other->accurateLeft() - other->s->getPW() / 2);
	int dy = std::abs(accurateTop() + s->getPL() / 2 - other->accurateTop() - other->s->getPL() / 2);

	// if the rectangles intersect, return 0
	if (dx <= (s->getPW() + other->s->getPW()) / 2 && dy <= (s->getPL() + other->s->getPL()) / 2)
		return 0;

	// otherwise, find the x and y distances between the edges of the rectangles
	int xDist = (dx < (s->getPW() + other->s->getPW()) / 2) ? 0 : dx - (s->getPW() + other->s->getPW()) / 2;
	int yDist = (dy < (s->getPL() + other->s->getPL()) / 2) ? 0 : dy - (s->getPL() + other->s->getPL()) / 2;

	// return the distance between the edges
	return std::sqrt(xDist * xDist + yDist * yDist);
}

int WorldRectangle::accurateDistanceFromCenter2D(Position &otherPosition) const {
	int x = accurateLeft() + s->getPW() / 2 - otherPosition.getPX();
	int z = accurateTop() + s->getPL() / 2 - otherPosition.getPZ();
	return (int)sqrt(x * x + z * z);
}

bool WorldRectangle::isCollidingTop(const WorldRectangle *other) const {
	return std::abs(accurateTop() - (other->accurateTop() + other->s->getPL())) < collisionEpsilon;
}

bool WorldRectangle::isCollidingBottom(const WorldRectangle *other) const {
	return std::abs(other->accurateTop() - (accurateTop() + s->getPL())) < collisionEpsilon;
}

bool WorldRectangle::isCollidingLeft(const WorldRectangle *other) const {
	return std::abs(accurateLeft() - (other->accurateLeft() + other->s->getPW())) < collisionEpsilon;
}

bool WorldRectangle::isCollidingRight(const WorldRectangle *other) const {
	return std::abs(other->accurateLeft() - (accurateLeft() + s->getPW())) < collisionEpsilon;
}
