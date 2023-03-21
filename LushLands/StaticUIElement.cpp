#include "StaticUIElement.h"

StaticUIElement::StaticUIElement(objecttype objectType, priority clickPriority) 
    : UIElement(objectType, clickPriority, fg::STATIC_UI) {}
