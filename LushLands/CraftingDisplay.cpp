#include "CraftingDisplay.h"

CraftingDisplay::CraftingDisplay(Core *core, CraftingManager *craftingManager) : cm(craftingManager) {
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
    // TODO: TMP 
    for (int i = 0; i < nCategories; i++) {
        std::string ctg = cm->getCategories()->at(i);
        for (auto rcp = cm->getRecipes(ctg)->begin(); rcp < cm->getRecipes(ctg)->end(); ++rcp) {
            CraftingButton *cb = new CraftingButton(&(*rcp));
            flow[i].add(cb);
        }
    }
}

//void CraftingDisplay::draw() {
//    if (hidden)
//        return;
//    auto backbuffer = al_get_backbuffer(dsp->getDisplay());
//    // Window bg
//    //al_draw_filled_rounded_rectangle(x, y, x + invWidth, y + invHeight, roundingRadiusBig, roundingRadiusBig, bg->getAllegroColor());
//    // Draw content
//    const int buffSize = 16;
//    char buffer[buffSize];
//    int s = 0;
//    if (not selectedCategory) {
//        // List recipe categories
//        s = cm->getCategories()->size();
//        int i = 0;
//        for (auto &ci : *cm->getCategories()) {
//            int x_el = x + margin;
//            int y_el = y + margin + (tileSizePx + margin) * i;
//            // Recipe bg
//            //al_draw_rounded_rectangle(x_el - margin, y_el - margin,
//            //    x_el + (tileSizePx + margin) * 4, y_el + tileSizePx + margin,
//            //    roundingRadiusSmall, roundingRadiusSmall,
//            //    fg->getAllegroColor(), 2.0f);
//            // Category icon
//            // TODO
//            sprintf_s(buffer, buffSize, "%15s", ci);
//            al_draw_text(font, fg->getAllegroColor(), x_el + tileSizePx * 2, y_el + tileSizePx * 3 / 5, ALLEGRO_ALIGN_RIGHT, buffer);
//            i++;
//        }
//    } else {
//        
//    }
//}
//
