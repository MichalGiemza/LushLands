#pragma once
#include "stdafx.h"
#include "UIElement.h"

class StaticUIElement : public UIElement {
    /**
    * Base for static User Interface elements.
    */

public:
    StaticUIElement(objecttype objectType, priority clickPriority);
};

