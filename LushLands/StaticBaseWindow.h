#pragma once
#include "StaticUIElement.h"
#include "WorldRectangle.h"
#include "Color.h"
#include "Colors.h"


class StaticBaseWindow : public StaticUIElement {
    /** 
    * Window base for implementing other, static windows.
    */
protected:
    pxint x, y, w, h;
    const Color *bg;
    const Color *fg;
    bool movable, resizeable;
    bool hidden = false;
public:
    StaticBaseWindow(pxint x, pxint y, pxint w, pxint h, const Color *bgColor = &UI_BG_COLOR, const Color *fgColor = &UI_FG_COLOR, bool movable = false, bool resizeable = false);
    bool screenPositionWithinBorders(pxint x, pxint y);
    virtual void interact(pxint x, pxint y) = 0;
    virtual void openContextMenu(pxint x, pxint y) = 0;
    virtual void draw() = 0;
    void setHidden(bool hdn);
};

