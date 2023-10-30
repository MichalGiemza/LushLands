#pragma once
#include "Agui/Widgets/Button/Button.hpp"
#include "Agui/Constants.h"
#include "Agui/Base/Colors.h"
#include "Agui/TextureManager.h"
#include "Item.h"


namespace agui {
    class AGUI_CORE_DECLSPEC InventrySlotListener;

	/**
    * Class that represents a Inventory Slot that shows state of inventory slot.
    *
    * ActionEvent when:
    *
    * Clicked.
    *
    * @author Micha³ Giemza
    */
    class AGUI_CORE_DECLSPEC InventorySlot : public Button {
        Item **slot = 0;
    public:
        InventorySlot();
        void setItemSlot(Item **slot);
        virtual void paintComponent(const PaintEvent &paintEvent) override;
        virtual void paintBackground(const PaintEvent &paintEvent) override;
    };
}

