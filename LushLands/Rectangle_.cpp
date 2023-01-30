#include "Rectangle_.h"

Rectangle_::Rectangle_(int x, int z, int w, int l, bool accurate) {
	p = new Position(x, 0, z, accurate);
	s = new Size(w, 0, l, accurate);
}

int Rectangle_::accurateLeft() const {
	return p->getAccurateX();
}

int Rectangle_::accurateRight() const {
	return p->getAccurateX() + s->getAccurateWidth();
}

int Rectangle_::accurateTop() const {
	return p->getAccurateZ();
}

int Rectangle_::accurateBottom() const {
	return p->getAccurateZ() - s->getAccurateLength();
}

int Rectangle_::left() const {
	return p->x();
}

int Rectangle_::right() const {
	return p->x() + s->w();
}

int Rectangle_::top() const {
	return p->z();
}

int Rectangle_::bottom() const {
	return p->z() - s->l();
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
	// Determine left-right and top-bottom pairs
	const Rectangle_ *lRect = p->getAccurateX() < other->p->getAccurateX() ? this : other;
	const Rectangle_ *rRect = p->getAccurateX() >= other->p->getAccurateX() ? this : other;
	const Rectangle_ *bRect = p->getAccurateZ() >= other->p->getAccurateZ() ? this : other;
	const Rectangle_ *tRect = p->getAccurateZ() < other->p->getAccurateZ() ? this : other;

	bool x_overlapping = lRect->accurateRight() > rRect->accurateLeft();
	bool y_overlapping = bRect->accurateTop() > tRect->accurateBottom();

	return x_overlapping and y_overlapping;
}

int Rectangle_::accurateDistanceTo2D(const Rectangle_ *other) const {
	// Determine left-right and top-bottom pairs
	const Rectangle_ *lRect = p->getAccurateX() < other->p->getAccurateX() ? this : other;
	const Rectangle_ *rRect = p->getAccurateX() >= other->p->getAccurateX() ? this : other;
	const Rectangle_ *bRect = p->getAccurateZ() >= other->p->getAccurateZ() ? this : other;
	const Rectangle_ *tRect = p->getAccurateZ() < other->p->getAccurateZ() ? this : other;

	int x_diff = std::max(rRect->accurateLeft() - lRect->accurateRight(), 0);
	int y_diff = std::max(tRect->accurateBottom() - bRect->accurateTop(), 0);

	return sqrt(x_diff * x_diff + y_diff * y_diff);
}

int Rectangle_::accurateDistanceFromCenter2D(Position &otherPosition) const {
	int x = p->getAccurateX() + s->getAccurateWidth() / 2 - otherPosition.getAccurateX();
	int z = p->getAccurateZ() + s->getAccurateLength() / 2 - otherPosition.getAccurateZ();
	return (int)sqrt(x * x + z * z);
}
