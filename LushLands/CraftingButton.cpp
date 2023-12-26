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
    auto frm = getFontColor();
    if (not isEnabled())
        frm = agui::Color(frm.getR() * 0.5, frm.getG() * 0.5, frm.getB() * 0.5, frm.getA());
    if (getButtonState() == HOVERED)
        pe.graphics()->drawFilledRoundedRectangle(getInnerRectangle(), roundingRadiusSmall, getBackColor());
    // Frame
    pe.graphics()->drawRoundedRectangle(getInnerRectangle(), roundingRadiusSmall, frm, thinLineThickness);
}

Recipe *CraftingButton::getRecipe() {
    return recipe;
}
