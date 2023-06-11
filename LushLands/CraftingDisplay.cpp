#include "CraftingDisplay.h"

CraftingDisplay::CraftingDisplay(Display *display, TextureManager *textureManager, CraftingManager *craftingManager, pxint x_, pxint y_) :
    StaticBaseWindow(x_, y_, invWidth, invHeight), cm(craftingManager), dsp(display),
    textureManager(textureManager) {
    // Ctor
    setHidden(true);
    font = al_load_ttf_font(fontNormaleste, 10, 0);
}

void CraftingDisplay::interact(pxint x, pxint y) {
    // TODO
}

void CraftingDisplay::openContextMenu(pxint x, pxint y) {
    // TODO
}

void CraftingDisplay::draw() {
    if (hidden)
        return;
    auto backbuffer = al_get_backbuffer(dsp->getDisplay());
    // Window bg
    al_draw_filled_rounded_rectangle(x, y, x + invWidth, y + invHeight, roundingRadiusBig, roundingRadiusBig, bg->getAllegroColor());
    // Draw content
    const int buffSize = 16;
    char buffer[buffSize];
    int s = 0;
    if (not selectedCategory) {
        // List recipe categories
        s = cm->getCategories()->size();
        int i = 0;
        for (auto &ci : *cm->getCategories()) {
            int x_el = x + margin;
            int y_el = y + margin + (tileSizePx + margin) * i;
            // Recipe bg
            al_draw_rounded_rectangle(x_el - margin, y_el - margin,
                x_el + (tileSizePx + margin) * 4, y_el + tileSizePx + margin,
                roundingRadiusSmall, roundingRadiusSmall,
                fg->getAllegroColor(), 2.0f);
            // Category icon
            // TODO
            sprintf_s(buffer, buffSize, "%15s", ci);
            al_draw_text(font, fg->getAllegroColor(), x_el + tileSizePx * 2, y_el + tileSizePx * 3 / 5, ALLEGRO_ALIGN_RIGHT, buffer);
            i++;
        }
    } else {
        // List recipes
        s = cm->getRecipes(selectedCategory)->size();
        s = cm->getCategories()->size();
        int i = 0;
        for (auto &recipe : *cm->getRecipes(selectedCategory)) {
            int x_el = x + margin;
            int y_el = y + margin + (tileSizePx + margin*3) * i;
            // Recipe bg
            al_draw_rounded_rectangle(x_el - margin, y_el - margin,
                x_el + (tileSizePx + margin) * 4, y_el + tileSizePx + margin,
                roundingRadiusSmall, roundingRadiusSmall,
                fg->getAllegroColor(), 2.0f);
            // Recipe icons
            for (int it_in = 0; it_in < recipe.nIng; it_in++) {
                auto &ing = recipe.ingredients[it_in];
                // Icon
                if (ing.ingredient) {
                    // Specific
                    ALLEGRO_BITMAP *itemTex = textureManager->getNamedTexture(ing.ingredient);
                    al_draw_bitmap(itemTex, x_el + (tileSizePx + margin) * it_in, y_el, 0);
                } else {
                    // General
                    // TODO
                }
                // Text
                sprintf_s(buffer, buffSize, "%3d", ing.amount);
                al_draw_text(font, fg->getAllegroColor(), x_el + (tileSizePx + margin) * it_in + tileSizePx - 2, y_el + tileSizePx * 3 / 5, ALLEGRO_ALIGN_RIGHT, buffer);
            }
            // Product icon
            x_el = x + margin + (tileSizePx + margin) * 3;
            ALLEGRO_BITMAP *itemTex = textureManager->getNamedTexture(recipe.product.productType);
            al_draw_bitmap(itemTex, x_el, y_el, 0);
            sprintf_s(buffer, buffSize, "%3d", recipe.product.amount);
            al_draw_text(font, fg->getAllegroColor(), x_el + tileSizePx - 2, y_el + tileSizePx * 3 / 5, ALLEGRO_ALIGN_RIGHT, buffer);
            i++;
        }
    }
}

