#pragma once
#include <algorithm>
#include "Position.h"
#include "Size.h"

class WorldRectangle {
	/**
	* Represents geometric rectangle.
	* - uses X and Z coordinates.
	* - uses accurate values by default.
	*/
	Position *p;
	Size *s;
	bool asCtr;
public:
	WorldRectangle(int x, int z, int w, int l, bool accurate = false, bool positionIsCenter = false);
	int accurateLeft() const;
	int accurateRight() const;
	int accurateTop() const;
	int accurateBottom() const;
	int left() const;
	int right() const;
	int top() const;
	int bottom() const;
	void setPosition(Position *newPosition);
	void setSize(Size *newSize);
	Position *getPosition();
	Size *getSize();
	bool isOverlapping(const WorldRectangle *other) const;
	bool pointBelongs(const Position &point) const;
	int accurateDistanceTo2D(const WorldRectangle *other) const;
	int accurateDistanceFromCenter2D(Position &otherPosition) const;
	bool isCollidingTop(const WorldRectangle *other) const;
	bool isCollidingBottom(const WorldRectangle *other) const;
	bool isCollidingLeft(const WorldRectangle *other) const;
	bool isCollidingRight(const WorldRectangle *other) const;
};

