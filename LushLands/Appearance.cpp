#include "Appearance.h"

Appearance::Appearance(const Color &color) : color(&color) {}

const Color *Appearance::getColor() const {
    return color;
}
