#pragma once

#include "Agui/Widgets/Button/Button.hpp"
#define ALLEGRO_UNSTABLE
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include "Agui/Constants.h"


namespace agui {
    class AGUI_CORE_DECLSPEC InventrySlotListener;

	/**
    * Class that represents a Inventory Slot that shows state of inventory slot.
    *
    * ActionEvent when:
    *
    * Clicked.
    *
    * @author Micha� Giemza
    */
    class AGUI_CORE_DECLSPEC InventorySlot : public Button {
    public:
        InventorySlot();
        virtual void paintComponent(const PaintEvent &paintEvent) override;
        virtual void paintBackground(const PaintEvent &paintEvent) override;
    };
}

