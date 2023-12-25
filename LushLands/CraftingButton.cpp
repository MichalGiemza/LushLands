#include "CraftingButton.h"

CraftingButton::CraftingButton(Recipe *recipe) : recipe(recipe) {
    setFontColor(agui::UI_FG_COLOR);
    setBackColor(agui::UI_HIGHLIGHT_COLOR);
    setSize(craftBtnW, craftBtnH + 2);
    setMargins(2, 2, 2, 2);
}

void CraftingButton::paintComponent(const agui::PaintEvent &pe) {
    pxint px = 0;
    const int buffSize = 4;
    char buffer[buffSize];
    // Recipe icons
    for (int it_in = 0; it_in < recipe->nIng; it_in++) {
        auto &ing = recipe->ingredients[it_in];
        px = it_in * iconSizePx;
        // Item icon
        if (ing.ingredient) {
            // Specific
            pe.graphics()->drawImage(TextureManager::getImage(ing.ingredient), agui::Point(px, 0));
        } else {
            // General
            pe.graphics()->drawImage(TextureManager::getImage(ing.ingredientType), agui::Point(px, 0));
        }
        // Item amount
        if (ing.amount > 1) {
            sprintf_s(buffer, buffSize, "%3d", ing.amount);
            pe.graphics()->drawText(agui::Point(px + amountPosX, amountPosY), buffer, agui::COLOR_WHITE, Widget::getGlobalFont(), agui::ALIGN_RIGHT);
        }
    }
    // Separator
    px = 3 * iconSizePx;
    pe.graphics()->drawLine(agui::Point(px + 4, craftBtnH / 2), agui::Point(px + iconSizePx - 4, craftBtnH / 2), getFontColor(), 2.0f);
    float secondsTime = (float)recipe->time / 1000;
    sprintf_s(buffer, buffSize, "%2.1f", secondsTime);
    pe.graphics()->drawText(agui::Point(px + amountPosX, amountPosY), buffer, agui::COLOR_WHITE, Widget::getGlobalFont(), agui::ALIGN_RIGHT);
    // Product icon
    auto &prod = recipe->product;
    px = 4 * iconSizePx;
    // Item icon
    pe.graphics()->drawImage(TextureManager::getImage(prod.productType), agui::Point(px, 0));
    // Item amount
    if (prod.amount > 1) {
        sprintf_s(buffer, buffSize, "%3d", prod.amount);
        pe.graphics()->drawText(agui::Point(px + amountPosX, amountPosY), buffer, agui::COLOR_WHITE, Widget::getGlobalFont(), agui::ALIGN_RIGHT);
    }
}

void CraftingButton::paintBackground(const agui::PaintEvent &pe) {
    // Background
    if (getButtonState() == HOVERED)
        pe.graphics()->drawFilledRoundedRectangle(getInnerRectangle(), roundingRadiusSmall, getBackColor());
    // Frame
    pe.graphics()->drawRoundedRectangle(getInnerRectangle(), roundingRadiusSmall, getFontColor(), thinLineThickness);
}

// List recipes
//        s = cm->getRecipes(selectedCategory)->size();
//        s = cm->getCategories()->size();
//        int i = 0;
//        for (auto &recipe : *cm->getRecipes(selectedCategory)) {
//            int x_el = x + margin;
//            int y_el = y + margin + (tileSizePx + margin*3) * i;
//            // Recipe bg
//            //al_draw_rounded_rectangle(x_el - margin, y_el - margin,
//            //    x_el + (tileSizePx + margin) * 4, y_el + tileSizePx + margin,
//            //    roundingRadiusSmall, roundingRadiusSmall,
//            //    fg->getAllegroColor(), 2.0f);
//            // Recipe icons
//            for (int it_in = 0; it_in < recipe.nIng; it_in++) {
//                auto &ing = recipe.ingredients[it_in];
//                // Icon
//                if (ing.ingredient) {
//                    // Specific
//                    ALLEGRO_BITMAP *itemTex = TextureManager::getTexture(ing.ingredient);
//                    al_draw_bitmap(itemTex, x_el + (tileSizePx + margin) * it_in, y_el, 0);
//                } else {
//                    // General
//                    // TODO
//                }
//                // Text
//                sprintf_s(buffer, buffSize, "%3d", ing.amount);
//                al_draw_text(font, fg->getAllegroColor(), x_el + (tileSizePx + margin) * it_in + tileSizePx - 2, y_el + tileSizePx * 3 / 5, ALLEGRO_ALIGN_RIGHT, buffer);
//            }
//            // Product icon
//            x_el = x + margin + (tileSizePx + margin) * 3;
//            ALLEGRO_BITMAP *itemTex = TextureManager::getTexture(recipe.product.productType);
//            al_draw_bitmap(itemTex, x_el, y_el, 0);
//            sprintf_s(buffer, buffSize, "%3d", recipe.product.amount);
//            al_draw_text(font, fg->getAllegroColor(), x_el + tileSizePx - 2, y_el + tileSizePx * 3 / 5, ALLEGRO_ALIGN_RIGHT, buffer);
//            i++;
//        }
