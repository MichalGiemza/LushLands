#pragma once
#include "Agui/Widget.hpp"
#include "Agui/Base/Colors.h"
#include "ConstantsUI.h"


namespace agui {
    class BaseWindow : public Widget {
        /**
        * Window base 
        */
    public:
        BaseWindow();
		virtual void paintComponent(const PaintEvent &paintEvent);
		virtual void paintBackground(const PaintEvent &paintEvent);
        virtual void setSize(const Dimension &size);
        virtual void setSize(int width, int height);
    };
}
