#include "Size.h"

Size::Size(int width, int height, int length) {
    setWidth(width);
    setHeight(height);
    setLength(length);
}

int Size::getWidth() {
    return width;
}

int Size::getHeight() {
    return height;
}

int Size::getLength() {
    return length;
}

int Size::getAccurateWidth() {
    return width;
}

int Size::getAccurateHeight() {
    return height;
}

int Size::getAccurateLength() {
    return length;
}

int Size::w() {
    return width;
}

int Size::h() {
    return height;
}

int Size::l() {
    return length;
}

void Size::setWidth(int width) {
    this->width = width * representationComaValue;
}

void Size::setHeight(int height) {
    this->height = height * representationComaValue;
}

void Size::setLength(int length) {
    this->length = length * representationComaValue;
}
