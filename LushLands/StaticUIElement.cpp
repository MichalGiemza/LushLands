#include "StaticUIElement.h"

StaticUIElement::StaticUIElement(objecttype objectType, priority clickPriority) 
    : UIElement(objectType, clickPriority, f::STATIC_UI) {}
