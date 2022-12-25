#include "EventHandler.h"

EventHandler::EventHandler(InputEvents *inputEvents, Focus *focus, ActionMap *actionMap) {
    this->inputEvents = inputEvents;
    this->focus = focus;
    this->actionMap = actionMap;
    this->worldEvents = 0;

    inputEvents->subscribeKeyBeingPressed(handleKeyboardKey, this);
    inputEvents->subscribeKeyTyped(handleKeyboardLetter, this);
}

void EventHandler::registerWorldEvents(IWorldEvents *worldEvents) {
    this->worldEvents = worldEvents;
}

void handleKeyboardKey(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    auto fo = eh->focus->getFocusedObject();
    if (fo->getObjGroup() == f::SIMULATION && eh->worldEvents) {
        worldevent we = eh->actionMap->mapToWorldAction(ae->keyboard.keycode);
        eh->worldEvents->emitWorldEvent(we, 0);
    }
    if (fo->getObjType() == f::CAMERA) {
        systemevent se = eh->actionMap->mapToSystemAction(ae->keyboard.keycode);
        eh->inputEvents->emitSystemEvent(se, 0);
    }
}

void handleKeyboardLetter(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    auto fo = eh->focus->getFocusedObject();
    if (fo->getObjGroup() == f::STATIC_UI || fo->getObjGroup() == f::WORLD_UI) {
        eh->inputEvents->emitSystemEvent(letter_typed, ae);
    }
}
