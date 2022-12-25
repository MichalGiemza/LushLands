#include "Controller.h"

Controller::Controller() {
    if (!al_init())
        throw std::logic_error(could_not_init_allegro);

    Logger::init();

    actionMap = new ActionMap();
    inputEvents = new InputEvents();
    inputController = new Keyboard(inputEvents);
    focus = new Focus();
    eventHandler = new EventHandler(inputEvents, focus, actionMap);
}

InputEvents *Controller::getInputEvents() {
    return inputEvents;
}

Keyboard *Controller::getInputController() {
    return inputController;
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
