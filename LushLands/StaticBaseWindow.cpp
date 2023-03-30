#include "StaticBaseWindow.h"

StaticBaseWindow::StaticBaseWindow(pxint x, pxint y, pxint w, pxint h, const Color *bgColor, const Color *fgColor, bool movable, bool resizeable) :
    StaticUIElement(ft::UI_WINDOW, fp::UI),
    bg(bgColor), fg(fgColor), movable(movable), resizeable(resizeable),
    x(x), y(y), w(w), h(h) {

}

bool StaticBaseWindow::screenPositionWithinBorders(pxint nx, pxint ny) {
    return nx >= x and nx <= x + w 
        && ny >= y and ny <= y + h;
}

void StaticBaseWindow::setHidden(bool hdn) {
    hidden = hdn;
}
