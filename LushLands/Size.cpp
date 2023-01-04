#include "Size.h"

Size::Size(int width, int height, int length, bool accurate) {
    if (accurate) {
        setAccurateWidth(width);
        setAccurateHeight(height);
        setAccurateLength(length);
    } else {
        setWidth(width);
        setHeight(height);
        setLength(length);
    }
}

Size::Size(float width, float height, float length, bool accurate) {
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

int Size::getAccurateWidth() const {
    return width;
}

int Size::getAccurateHeight() const {
    return height;
}

int Size::getAccurateLength() const {
    return length;
}

void Size::setAccurateWidth(int width) {
    this->width = width;
}

void Size::setAccurateHeight(int height) {
    this->height = height;
}

void Size::setAccurateLength(int length) {
    this->length = length;
}

void Size::setAccurateWidth(float width) {
    this->width = width;
}

void Size::setAccurateHeight(float height) {
    this->height = height;
}

void Size::setAccurateLength(float length) {
    this->length = length;
}

int Size::w() const {
    return width / representationComaValue;
}

int Size::h() const {
    return height / representationComaValue;
}

int Size::l() const {
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

void Size::setWidth(float width) {
    this->width = width * representationComaValue;
}

void Size::setHeight(float height) {
    this->height = height * representationComaValue;
}

void Size::setLength(float length) {
    this->length = length * representationComaValue;
}

pxint Size::getCameraW() {
    return (pxint)(w() * tileSizePx);
}

pxint Size::getCameraL() {
    return (pxint)(l() * tileSizePx);
}

bool Size::operator==(const Size &other) const {
    return width == other.width && height == other.height && length == other.length;
}
