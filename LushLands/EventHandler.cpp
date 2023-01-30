#include "EventHandler.h"

EventHandler::EventHandler(InputEvents *inputEvents, Focus *focus, ActionMap *actionMap) {
    this->inputEvents = inputEvents;
    this->focus = focus;
    this->actionMap = actionMap;
    this->worldEvents = 0;
    this->worldTime = 0;
    this->lastTimeUpdated = 0;

    inputEvents->subscribeKeyBeingPressed(handleKeyboardKey, this);
    inputEvents->subscribeKeyTyped(handleKeyboardLetter, this);
}

void EventHandler::registerWorldTime(Time *worldTime) {
    this->worldTime = worldTime;
}

void EventHandler::registerWorldEvents(ISimulationEvents *worldEvents) {
    this->worldEvents = worldEvents;
}

void EventHandler::registerChunkEvents(ChunkPosition &cPos, ISimulationEvents *chunkEvents) {
    this->chunkEvents[cPos] = chunkEvents;
}

void EventHandler::updateSimulation(ChunkPositionsSet activeChunks) {
    miliseconds timeNow = worldTime->getAsMiliseconds();
    miliseconds dt = std::min((int)(timeNow - lastTimeUpdated), maxMilisecondsPerTick);
    lastTimeUpdated = timeNow;
    // Chunks
    for (int i = 0; i < activeChunks.n; i++) {
        ChunkPosition cPos = activeChunks.chunkPositions[i];
        chunkEvents[cPos]->update(dt);
    }
    // World
    worldEvents->update(dt);
}

void handleKeyboardKey(ALLEGRO_EVENT *ae, void *obj) {
    EventHandler *eh = (EventHandler *)obj;
    auto fo = eh->focus->getFocusedObject();
    if (fo->getObjGroup() == f::SIMULATION && eh->worldEvents) {
        simulationevent we = eh->actionMap->mapToWorldAction(ae->keyboard.keycode);
        eh->worldEvents->emitEvent(we, 0);
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
