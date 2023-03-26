#pragma once
#include "Color.h"

// Default Colors
const Color COLOR_RED = Color(255, 0, 20, 255);
const Color COLOR_DARK_RED = Color(128, 0, 10, 255);
const Color COLOR_FUXIA = Color(255, 0, 255, 255);
const Color COLOR_CYAN = Color(0, 255, 255, 255);

// Debug colors
const Color DEBUG_CHUNK_BORDER_COLOR = COLOR_RED;
const Color DEBUG_STRUCTURE_BORDER_COLOR = COLOR_DARK_RED;
const Color DEBUG_ANIMAL_BORDER_COLOR = COLOR_FUXIA;

// System colors
const Color TRANSPARENT_COLOR = Color(0, 0, 0, 0);
const Color CHAT_GRAY_COLOR = Color(220, 220, 220, 255);
const Color BLACK_COLOR = Color(0, 0, 0, 255);
const Color WORLD_CURSOR_COLOR = COLOR_CYAN;
