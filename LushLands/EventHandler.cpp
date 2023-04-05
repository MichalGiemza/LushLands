#include "EventHandler.h"

EventHandler::EventHandler(InputEvents *inputEvents, Focus *focus, ActionMap *actionMap) {
    this->inputEvents = inputEvents;
    this->focus = focus;
    this->actionMap = actionMap;
    this->chunkEvents = 0;

    inputEvents->subscribeKeyBeingPressed(handleKeyboardKey, this);
    inputEvents->subscribeKeyTyped(handleKeyboardLetter, this);
    inputEvents->subscribeMouseClick(handleMouseClick, this);
}


void EventHandler::registerChunkEvents(std::unordered_map<ChunkPosition, ISimulationEvents *> *chunkEvents) {
    this->chunkEvents = chunkEvents;
}

void handleKeyboardKey(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    auto agel = eh->focus->getCurrentlyActiveGameElement();

    simulationevent sep = eh->actionMap->mapKeyboardToWorldPressAction(ae->keyboard.keycode);
    if (sep > 0 and agel->getObjGroup() == fg::SIMULATION) {
        ALLEGRO_EVENT *newEvent = EventFactory::packKeyboardLetter(sep, ae->keyboard.keycode);
        al_emit_user_event(eh->inputEvents->getEventSource(), newEvent, NULL);
        return;
    }
}

void handleKeyboardLetter(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    auto agel = eh->focus->getCurrentlyActiveGameElement();

    systemevent sye = eh->actionMap->mapKeyboardToSystemAction(ae->keyboard.keycode);
    if (sye > 0 && agel->getObjType() != ft::CONSOLE) {
        ALLEGRO_EVENT *newEvent = EventFactory::packKeyboardLetter(sye, ae->keyboard.keycode);
        al_emit_user_event(eh->inputEvents->getEventSource(), newEvent, NULL);
        return;
    }

    systemevent sel = letter_typed;
    if (agel->getObjGroup() == fg::STATIC_UI || agel->getObjGroup() == fg::WORLD_UI) {
        ALLEGRO_EVENT *newEvent = EventFactory::packKeyboardLetter(sel, ae->keyboard.keycode);
        al_emit_user_event(eh->inputEvents->getEventSource(), newEvent, NULL);
        return;
    }
}

void handleMouseClick(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    auto agel = eh->focus->getCurrentlyActiveGameElement();
    if (agel->getObjGroup() == fg::SIMULATION) {
        ALLEGRO_EVENT *newEvent = EventFactory::packMouseAction(
            eh->actionMap->mapMouseToWorldAction(ae->mouse.button), 
            ae->mouse.x, ae->mouse.y);
        al_emit_user_event(eh->inputEvents->getEventSource(), newEvent, NULL);
    }
    if (agel->getObjGroup() == fg::STATIC_UI || agel->getObjGroup() == fg::WORLD_UI) {
        ALLEGRO_EVENT *newEvent = EventFactory::packMouseAction(
            eh->actionMap->mapMouseToSystemAction(ae->mouse.button),
            ae->mouse.x, ae->mouse.y);
        al_emit_user_event(eh->inputEvents->getEventSource(), newEvent, NULL);
    }
}
