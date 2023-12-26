#include "CraftingDisplay.h"

CraftingDisplay::CraftingDisplay(Core *core, CraftingManager *craftingManager, Inventory *inventory) : cm(craftingManager), inv(inventory) {
    nCategories = cm->getCategories()->size();
    tab = new agui::Tab[nCategories];
    flow = new agui::FlowLayout[nCategories];
    // Tab pane
    setLocation(craftMenuX, craftMenuY);
    setSize(craftMenuW, craftMenuH);
    setVisibility(false);
    add(&tabPane);
    tabPane.setSize(craftMenuW - 8, craftMenuH - 8);
    tabPane.setLocation(2, 2);
    tabPane.setResizeTabContent(true);
    setMargins(2, 2, 2, 2);
    tabPane.setMargins(2, 2, 2, 2);
    tabPane.setFontColor(agui::UI_FG_COLOR);
    tabPane.setBackColor(agui::UI_BG_COLOR);
    // Tab choices
    for (int i = 0; i < nCategories; i++) {
        tab[i].setText(cm->getCategories()->at(i));
        tab[i].setBackColor(agui::UI_BG_COLOR);
        tabPane.addTab(&tab[i], &flow[i]);
        flow[i].setHorizontallyCentered(true);
        flow[i].setHorizontalSpacing(0);
        flow[i].setVerticalSpacing(0);
        flow[i].setMargins(2, 2, 2, 2);
    }
    tabPane.setSelectedTab(-1);
    // Build Tab Contents
    for (int i = 0; i < nCategories; i++) {
        std::string ctg = cm->getCategories()->at(i);
        for (auto rcp = cm->getRecipes(ctg)->begin(); rcp < cm->getRecipes(ctg)->end(); ++rcp) {
            CraftingButton *cb = new CraftingButton(&(*rcp));
            flow[i].add(cb);
        }
    }
    // Crafting button refreshing
    auto sub = new SimpleSubscription();
    sub->caller = this;
    sub->func = refreshAvailabilities;
    inv->onContentChangeSubscribe(sub);
    refreshAvailabilities(this);
}

void refreshAvailabilities(void *craftingDisplay) {
    CraftingDisplay *cd = (CraftingDisplay *)craftingDisplay;

    for (int i = 0; i < cd->nCategories; i++) {
        // Per crafting tab (category)
        auto &fl = cd->flow[i];
        for (auto btn = fl.getChildBegin(); btn != fl.getChildEnd(); btn++) {
            // Per crafting button
            auto b = (CraftingButton *)*btn;
            auto r = b->getRecipe();
            int maxCraft = INT32_MAX;
            for (int i = 0; i < r->nIng; i++) {
                // Per ingredient
                auto ing = r->ingredients[i];
                int maxCurr = 0;
                if (ing.ingredientType == igt::specific)
                    maxCurr = cd->inv->getItemCount(ing.ingredient) / ing.amount;
                if (ing.ingredientType == igt::general)
                    maxCurr = cd->inv->getItemCount(ing.ingredient) / ing.amount; // TODO: General types - not working yet
                maxCraft = std::min(maxCraft, maxCurr);
            }
            // Handle crafting button
            b->maxCraft = maxCraft; // TODO: Determine max stack and `% maxStack(itemType)`
            if (maxCraft <= 0) 
                b->setEnabled(false);
        }
    }
}

