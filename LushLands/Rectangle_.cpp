#include "Rectangle_.h"

Rectangle_::Rectangle_(int x, int z, int w, int l, bool accurate) {
	p = new Position(x, 0, z, accurate);
	s = new Size(w, 0, l, accurate);
}

int Rectangle_::accurateLeft() const {
	return p->getPX();
}

int Rectangle_::accurateRight() const {
	return p->getPX() + s->getPW();
}

int Rectangle_::accurateTop() const {
	return p->getPZ();
}

int Rectangle_::accurateBottom() const {
	return p->getPZ() - s->getPL();
}

int Rectangle_::left() const {
	return p->getX();
}

int Rectangle_::right() const {
	return p->getX() + s->w();
}

int Rectangle_::top() const {
	return p->getZ();
}

int Rectangle_::bottom() const {
	return p->getZ() - s->l();
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
	/*// Determine left-right and top-bottom pairs
	const Rectangle_ *lRect = p->getPX() < other->p->getPX() ? this : other;
	const Rectangle_ *rRect = p->getPX() >= other->p->getPX() ? this : other;
	const Rectangle_ *bRect = p->getPZ() >= other->p->getPZ() ? this : other;
	const Rectangle_ *tRect = p->getPZ() < other->p->getPZ() ? this : other;

	bool x_overlapping = lRect->accurateRight() > rRect->accurateLeft();
	bool y_overlapping = bRect->accurateTop() < tRect->accurateBottom();

	return x_overlapping and y_overlapping;*/

	// find the x and y distances between the centers of the two rectangles
	int dx = std::abs(p->getPX() + s->getPW() / 2 - other->p->getPX() - other->s->getPW() / 2);
	int dy = std::abs(p->getPZ() + s->getPL() / 2 - other->p->getPZ() - other->s->getPL() / 2);

	return dx < (s->getPW() + other->s->getPW()) / 2 && dy < (s->getPL() + other->s->getPL()) / 2;
}

int Rectangle_::accurateDistanceTo2D(const Rectangle_ *other) const {
	/*// Determine left-right and top-bottom pairs
	const Rectangle_ *lRect = p->getPX() < other->p->getPX() ? this : other;
	const Rectangle_ *rRect = p->getPX() >= other->p->getPX() ? this : other;
	const Rectangle_ *bRect = p->getPZ() >= other->p->getPZ() ? this : other;
	const Rectangle_ *tRect = p->getPZ() < other->p->getPZ() ? this : other;

	int x_diff = std::max(rRect->accurateLeft() - lRect->accurateRight(), 0);
	int y_diff = std::max(tRect->accurateBottom() - bRect->accurateTop(), 0);

	return sqrt(x_diff * x_diff + y_diff * y_diff);*/

	// find the x and y distances between the centers of the two rectangles
	int dx = std::abs(p->getPX() + s->getPW() / 2 - other->p->getPX() - other->s->getPW() / 2);
	int dy = std::abs(p->getPZ() + s->getPL() / 2 - other->p->getPZ() - other->s->getPL() / 2);

	// if the rectangles intersect, return 0
	if (dx < (s->getPW() + other->s->getPW()) / 2 && dy < (s->getPL() + other->s->getPL()) / 2) {
		return 0;
	}

	// otherwise, find the x and y distances between the edges of the rectangles
	int xDist = (dx < (s->getPW() + other->s->getPW()) / 2) ? 0 : dx - (s->getPW() + other->s->getPW()) / 2;
	int yDist = (dy < (s->getPL() + other->s->getPL()) / 2) ? 0 : dy - (s->getPL() + other->s->getPL()) / 2;

	// return the distance between the edges
	return std::sqrt(xDist * xDist + yDist * yDist);
}

int Rectangle_::accurateDistanceFromCenter2D(Position &otherPosition) const {
	int x = p->getPX() + s->getPW() / 2 - otherPosition.getPX();
	int z = p->getPZ() + s->getPL() / 2 - otherPosition.getPZ();
	return (int)sqrt(x * x + z * z);
}
