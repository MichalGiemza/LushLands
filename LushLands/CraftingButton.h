#pragma once
#include "Agui/Widgets/Button/Button.hpp"
#include "CraftingStructures.h"
#include <Agui/EventArgs.hpp>
#include "Agui/Base/Colors.h"
#include "ConstantsUI.h"
#include <Agui/TextureManager.h>
#include "Inventory.h"


class CraftingButton : public agui::Button {
    Recipe *recipe;
public:
    int maxCraft = 0;
public:
    CraftingButton(Recipe *recipe);
    virtual void paintComponent(const agui::PaintEvent &paintEvent) override;
    virtual void paintBackground(const agui::PaintEvent &paintEvent) override;
    Recipe *getRecipe();
};

