#include "stdafx.h"
#include "UIElement.h"

UIElement::UIElement(objecttype objectType, priority clickPriority, objectgroup objectGroup) 
    : GameElement(objectType, clickPriority, objectGroup) {
    if (clickPriority > fp::UI)
        throw std::logic_error(ui_element_priority);
}
