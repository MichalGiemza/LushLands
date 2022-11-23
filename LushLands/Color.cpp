#include "Color.h"

Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) : red(red), green(green), blue(blue), alpha(alpha) {}

uint8_t Color::r() { return red; }

uint8_t Color::g() { return green; }

uint8_t Color::b() { return blue; }

uint8_t Color::a() { return alpha; }

uint8_t *Color::getRGBA() {
    return new uint8_t[red, green, blue, alpha];
}

uint8_t *Color::getRGB() {
    return new uint8_t[red, green, blue];
}

ALLEGRO_COLOR Color::getAllegroColor() {
    return ALLEGRO_COLOR(red, green, blue, alpha);
}
