#pragma once
#include "stdafx.h"
#include "Inventory.h"
#include "StaticBaseWindow.h"
#include "TextureManager.h"
#include "Display.h"


class SimpleActionListener : public agui::ActionListener {
public:
    virtual void actionPerformed(const agui::ActionEvent &evt) {
        agui::Slider *slider = dynamic_cast<agui::Slider *>(evt.getSource());
        al_show_native_message_box(al_get_current_display(),
            "Agui Action Listener",
            "",
            "An Action Event has occured!",
            NULL, NULL);
    }
};


class InventoryDisplay : public StaticBaseWindow {
    /** 
    * Represents Static UI window with provided inventory.
    */
protected:
    const pxint margin = 4;
    const pxint invWidth;
    const pxint invHeight;
    bool displayBg = true;
    Inventory *inventory;

    SimpleActionListener simpleAL;
    //agui::Frame frame;
    agui::FlowLayout frame;
    agui::Button *buttons;

    Display *dsp;
    TextureManager *textureManager;
    ALLEGRO_FONT *font;
    Core *core;
protected:
    int determineRows(int n);
    pxint determineHeight(int elements);
    pxint determineWidth();
    void prepareGUI();
public:
    InventoryDisplay(Core *core, Display *display, Inventory *inv, pxint x, pxint y);
    virtual void interact(pxint x, pxint y) override;
    virtual void openContextMenu(pxint x, pxint y) override;
    virtual void draw() override;
};

