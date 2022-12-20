#pragma once
#include "Position.h"
#include "Size.h"

class Rectangle_ {
	/**
	* Represents geometric rectangle.
	* - uses X and Z coordinates.
	* - uses accurate values by default.
	*/
private:
	Position *p;
	Size *s;
public:
	Rectangle_(int x, int z, int w, int l, bool accurate = false);
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
	bool isOverlapping(const Rectangle_ *other) const;
};

