#pragma once
#include "Agui/Color.hpp"

namespace agui {

    // Default agui::Color s
    const Color COLOR_WHITE = Color(255, 255, 255, 255);
    const Color COLOR_RED = Color(255, 0, 20, 255);
    const Color COLOR_DARK_RED = Color(128, 0, 10, 255);
    const Color COLOR_FUXIA = Color(255, 0, 255, 255);
    const Color COLOR_CYAN = Color(0, 255, 255, 255);
    const Color BLACK_COLOR = Color(0, 0, 0, 255);

    // UI colors
    const Color TRANSPARENT_COLOR = Color(0, 0, 0, 0);
    const Color CHAT_GRAY_COLOR = Color(220, 220, 220, 255);
    const Color WORLD_CURSOR_COLOR = Color(0, 100, 100, 100);

    const Color UI_BG_COLOR = Color(20, 30, 32, 30);
    const Color UI_BG_DIM_COLOR = Color(20, 30, 32, 60);
    const Color UI_FG_COLOR = Color(160, 240, 250, 255);
    const Color UI_HIGHLIGHT_COLOR = Color(140, 220, 230, 255);

    // Debug colors
    const Color DEBUG_CHUNK_BORDER_COLOR = COLOR_RED;
    const Color DEBUG_STRUCTURE_BORDER_COLOR = COLOR_DARK_RED;
    const Color DEBUG_ANIMAL_BORDER_COLOR = COLOR_FUXIA;
    const Color DEBUG_ITEM_BORDER_COLOR = COLOR_CYAN;

    // World Colors // FIXME: Czy to powinno tutaj byc?
    const Color ITEM_SHADOW_COLOR = Color(0, 0, 0, 64);
}
