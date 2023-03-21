#include "Rectangle_.h"

Rectangle_::Rectangle_(int x, int z, int w, int l, bool accurate, bool asCenter) {
	p = new Position(x, 0, z, accurate);
	s = new Size(w, 0, l, accurate);
	asCtr = asCenter;
}

int Rectangle_::accurateLeft() const {
	return p->getPX() - asCtr * s->getPW() / 2;
}

int Rectangle_::accurateRight() const {
	return p->getPX() + s->getPW() - asCtr * s->getPW() / 2;
}

int Rectangle_::accurateTop() const {
	return p->getPZ() - asCtr * s->getPL() / 2;
}

int Rectangle_::accurateBottom() const {
	return p->getPZ() + s->getPL() - asCtr * s->getPL() / 2;
}

int Rectangle_::left() const {
	return accurateLeft() / representationComaValue;
}

int Rectangle_::right() const {
	return accurateRight() / representationComaValue;
}

int Rectangle_::top() const {
	return accurateTop() / representationComaValue;
}

int Rectangle_::bottom() const {
	return accurateBottom() / representationComaValue;
}

void Rectangle_::setPosition(Position *newPosition) {
	p = newPosition;
}

void Rectangle_::setSize(Size *newSize) {
	s = newSize;
}

Position *Rectangle_::getPosition() {
	return p;
}

Size *Rectangle_::getSize() {
	return s;
}

bool Rectangle_::isOverlapping(const Rectangle_ *other) const {
	// find the x and y distances between the centers of the two rectangles
	int dx = std::abs(accurateLeft() + s->getPW() / 2 - other->accurateLeft() - other->s->getPW() / 2);
	int dy = std::abs(accurateTop() + s->getPL() / 2 - other->accurateTop() - other->s->getPL() / 2);

	return dx <= (s->getPW() + other->s->getPW()) / 2 && dy <= (s->getPL() + other->s->getPL()) / 2;
}

int Rectangle_::accurateDistanceTo2D(const Rectangle_ *other) const {
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

int Rectangle_::accurateDistanceFromCenter2D(Position &otherPosition) const {
	int x = accurateLeft() + s->getPW() / 2 - otherPosition.getPX();
	int z = accurateTop() + s->getPL() / 2 - otherPosition.getPZ();
	return (int)sqrt(x * x + z * z);
}

bool Rectangle_::isCollidingTop(const Rectangle_ *other) const {
	return std::abs(accurateTop() - (other->accurateTop() + other->s->getPL())) < collisionEpsilon;
}

bool Rectangle_::isCollidingBottom(const Rectangle_ *other) const {
	return std::abs(other->accurateTop() - (accurateTop() + s->getPL())) < collisionEpsilon;
}

bool Rectangle_::isCollidingLeft(const Rectangle_ *other) const {
	return std::abs(accurateLeft() - (other->accurateLeft() + other->s->getPW())) < collisionEpsilon;
}

bool Rectangle_::isCollidingRight(const Rectangle_ *other) const {
	return std::abs(other->accurateLeft() - (accurateLeft() + s->getPW())) < collisionEpsilon;
}
