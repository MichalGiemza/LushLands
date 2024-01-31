#pragma once
#include "CraftingManager.h"
#include "Display.h"
#include "Agui/TextureManager.h"
#include "Agui/Base/BaseWindow.h"
#include "Agui/Widgets/Tab/TabbedPane.hpp"
#include "Agui/FlowLayout.hpp"
#include <Agui/Widgets/ListBox/ListBox.hpp>
#include "CraftingButton.h"
#include "ConstantsUI.h"
#include "Agui/Base/Colors.h"
#include "ConstantsUI.h"
#include <Inventory.h>
#include "CraftingManager.h"
#include <EventFactory.h>


class CraftingListener : public agui::ButtonListener {
    InputEvents *ie;
    Inventory *inv;
public:
    CraftingListener(InputEvents *ie, Inventory *inv);
    virtual void buttonStateChanged(agui::Button *btn, agui::Button::ButtonStateEnum enm);
};

class CraftingDisplay : public agui::BaseWindow {
    /** 
    * Represents crafting interface.
    */
protected:
    const pxint margin = 4;
    const pxint invWidth = tileSizePx * 4 + margin * 6;
    const pxint invHeight = 600;
    //name selectedCategory = rc::personal; // DEBUG, set to "0"!
    CraftingManager *cm;
    int nCategories = 0;
    agui::TabbedPane tabPane;
    agui::Tab *tab;
    agui::FlowLayout *flow;
    Inventory *inv;
    InputEvents *inpEv;
    CraftingListener cl;
protected:
public:
    CraftingDisplay(Core *core, CraftingManager *craftingManager, Inventory *inventory, InputEvents *inputEvents);
    friend void refreshAvailabilities(void *craftingDisplay);
};

void refreshAvailabilities(void *craftingDisplay);
