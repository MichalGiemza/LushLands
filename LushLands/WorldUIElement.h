#pragma once
#include "UIElement.h"


class WorldUIElement : public UIElement {
    /**
    * Base for static User Interface elements.
    */

public:
    WorldUIElement(objecttype objectType, priority clickPriority);
};
