#include "Controller.h"

Controller::Controller(Core *core) {
    if (!al_init())
        throw std::logic_error(could_not_init_allegro);

    Logger::init();
    
    actionMap = new ActionMap();
    inputEvents = new InputEvents(core);
    
    keyboard = new Keyboard(inputEvents);
    mouse = new Mouse(inputEvents);
    
    focus = new Focus();
}

InputEvents *Controller::getInputEvents() {
    return inputEvents;
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


