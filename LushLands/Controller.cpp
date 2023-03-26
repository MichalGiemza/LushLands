#include "Controller.h"

Controller::Controller() {
    if (!al_init())
        throw std::logic_error(could_not_init_allegro);

    Logger::init();
    
    actionMap = new ActionMap();
    inputEvents = new InputEvents();
    
    keyboard = new Keyboard(inputEvents);
    mouse = new Mouse(inputEvents);
    
    focus = new Focus();
    eventHandler = new EventHandler(inputEvents, focus, actionMap);
}

void Controller::postInit(ALLEGRO_BITMAP *cursorBitmap) {
    mouse->addCursor(cursorBitmap);
}

InputEvents *Controller::getInputEvents() {
    return inputEvents;
}

EventHandler *Controller::getEventHandler() {
    return eventHandler;
}

Focus *Controller::getFocus() {
    return focus;
}

ActionMap *Controller::getActionMap() {
    return actionMap;
}

Mouse *Controller::getMouse() {
    return mouse;
}


