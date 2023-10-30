#include "BaseWindow.h"

namespace agui {

    BaseWindow::BaseWindow() {
        setBackColor(UI_BG_COLOR);
        setMargins(3, 3, 3, 3);
    }

    void BaseWindow::paintComponent(const PaintEvent &paintEvent) {}

    void BaseWindow::paintBackground(const PaintEvent &paintEvent) {
        paintEvent.graphics()->drawRoundedRectangle(getSizeRectangle(), 8.0f, getBackColor(), 2.0f);
    }

    void BaseWindow::setSize(const Dimension &size) {
        Widget::setSize(size);
    }

    void BaseWindow::setSize(int width, int height) {
        Widget::setSize(width, height);
    }
}
