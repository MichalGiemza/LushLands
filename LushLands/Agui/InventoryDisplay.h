#pragma once
#include "Agui/Base/BaseWindow.h"
#include "Agui/TextureManager.h"
#include "Agui/InventorySlot.hpp"
#include "Agui/Widgets/Slider/Slider.hpp"
#include "Agui/FlowLayout.hpp"
#include "Inventory.h"


namespace agui {
    const int inventoryWidth = 12;
    const int tileSizePx = 36;
    const int invX = 50;
    const int invY = 50;

    class SimpleActionListener : public agui::ActionListener {
    public:
        virtual void actionPerformed(const agui::ActionEvent &evt) {
            // TODO
        }
    };

    class InventoryDisplay : public BaseWindow {
        /**
        * Represents Static UI window with provided inventory.
        */
    protected:
        SimpleActionListener simpleAL;
        agui::FlowLayout frame;
        agui::InventorySlot *buttons;
        Inventory *inv;
    protected:
        int determineRows(int n);
        int determineHeight(int elements);
        int determineWidth();
        void prepareGUI();
    public:
        InventoryDisplay(Inventory *inventory);

    };
}
