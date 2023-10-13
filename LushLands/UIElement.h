#pragma once
#include "stdafx.h"
#include "GameElement.h"

class UIElement : GameElement {
    /**
    * Base for User Interface element.
    */

public: 
    UIElement(objecttype objectType, priority clickPriority, objectgroup objectGroup);
};
