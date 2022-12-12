#include "Controller_.h"

Controller_::Controller_() {
    if (!al_init())
        throw std::logic_error(could_not_init_allegro);

    Logger::init();

    actionMap = new ActionMap();
    inputEvents = new InputEvents();
    inputController = new InputController(inputEvents);
    focus = new Focus();
    eventHandler = new EventHandler(inputEvents, focus, actionMap);
}

InputEvents *Controller_::getInputEvents() {
    return inputEvents;
}

InputController *Controller_::getInputController() {
    return inputController;
}

EventHandler *Controller_::getEventHandler() {
    return eventHandler;
}

Focus *Controller_::getFocus() {
    return focus;
}

ActionMap *Controller_::getActionMap() {
    return actionMap;
}
