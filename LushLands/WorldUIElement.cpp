#include "stdafx.h"
#include "WorldUIElement.h"

WorldUIElement::WorldUIElement(objecttype objectType, priority clickPriority) :
    UIElement(objectType, clickPriority, fg::WORLD_UI) { }
