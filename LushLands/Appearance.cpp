#include "stdafx.h"
#include "Appearance.h"

Appearance::Appearance(const Color &color, const TextureLocalization *textureLocalization) : 
    color(&color), textureLocalization(textureLocalization) {}

const Color *Appearance::getColor() const {
    return color;
}

const TextureLocalization *Appearance::getTextureLocalization() const {
    return textureLocalization;
}
