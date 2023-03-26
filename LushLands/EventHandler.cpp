#include "EventHandler.h"

EventHandler::EventHandler(InputEvents *inputEvents, Focus *focus, ActionMap *actionMap) {
    this->inputEvents = inputEvents;
    this->focus = focus;
    this->actionMap = actionMap;
    this->worldEvents = 0;
    this->chunkEvents = 0;

    inputEvents->subscribeKeyBeingPressed(handleKeyboardKey, this);
    inputEvents->subscribeKeyTyped(handleKeyboardLetter, this);
    inputEvents->subscribeMouseClick(handleMouseClick, this);
}

void EventHandler::registerWorldEvents(ISimulationEvents *worldEvents) {
    this->worldEvents = worldEvents;
}

void EventHandler::registerChunkEvents(std::unordered_map<ChunkPosition, ISimulationEvents *> *chunkEvents) {
    this->chunkEvents = chunkEvents;
}

void handleKeyboardKey(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    auto agel = eh->focus->getCurrentlyActiveGameElement();
    if (agel->getObjGroup() == fg::SIMULATION && eh->worldEvents) {
        ALLEGRO_EVENT newEvent {};
        newEvent.user.type = eh->actionMap->mapKeyboardToWorldAction(ae->keyboard.keycode);
        al_emit_user_event(eh->worldEvents->getEventSource(), &newEvent, NULL);
    }
    if (agel->getObjType() == ft::CAMERA) {
        ALLEGRO_EVENT newEvent {};
        newEvent.user.type = eh->actionMap->mapKeyboardToSystemAction(ae->keyboard.keycode);
        al_emit_user_event(eh->inputEvents->getEventSource(), &newEvent, NULL);
    }
}

void handleKeyboardLetter(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    auto agel = eh->focus->getCurrentlyActiveGameElement();
    if (agel->getObjGroup() == fg::STATIC_UI || agel->getObjGroup() == fg::WORLD_UI) {
        ALLEGRO_EVENT newEvent {};
        newEvent.user.type = letter_typed;
        al_emit_user_event(eh->inputEvents->getEventSource(), &newEvent, NULL);
    }
}

void handleMouseClick(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    auto agel = eh->focus->getCurrentlyActiveGameElement();
    if (agel->getObjGroup() == fg::SIMULATION && eh->worldEvents) {
        ALLEGRO_EVENT newEvent {};
        newEvent.user.type = eh->actionMap->mapMouseToWorldAction(ae->mouse.button);
        al_emit_user_event(eh->worldEvents->getEventSource(), &newEvent, NULL);
    }
    if (agel->getObjGroup() == fg::STATIC_UI || agel->getObjGroup() == fg::WORLD_UI) {
        ALLEGRO_EVENT newEvent {};
        newEvent.user.type = eh->actionMap->mapMouseToSystemAction(ae->mouse.button);
        al_emit_user_event(eh->inputEvents->getEventSource(), &newEvent, NULL);
    }
}
