#include "Size.h"

Size::Size(int width, int height, int length) {
    setWidth(width);
    setHeight(height);
    setLength(length);
}

int Size::getWidth() {
    return width / representationComaValue;
}

int Size::getHeight() {
    return height / representationComaValue;
}

int Size::getLength() {
    return length / representationComaValue;
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
    return width / representationComaValue;
}

int Size::h() {
    return height / representationComaValue;
}

int Size::l() {
    return length / representationComaValue;
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
