#include "Appearance.h"

Appearance::Appearance(const agui::Color &color) :
    color(&color) {}

const agui::Color *Appearance::getColor() const {
    return color;
}
