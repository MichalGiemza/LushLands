#pragma once
#include <cstdint>
#include <allegro5/color.h>


class Color {
    const uint8_t red, green, blue, alpha;
public:
    Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
    uint8_t r();
    uint8_t g();
    uint8_t b();
    uint8_t a();
    uint8_t *getRGBA() const;
    uint8_t *getRGB() const;
    ALLEGRO_COLOR getAllegroColor() const;
};

