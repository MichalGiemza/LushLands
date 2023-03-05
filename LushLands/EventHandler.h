#pragma once
#include "DataTypes.h"
#include "GameElement.h"
#include "Focus.h"
#include "ConstantSets.h"
#include "InputEvents.h"
#include "ActionMap.h"
#include "ISimulationEvents.h"
#include "ActionMap.h"
#include "Events.h"
#include "PositionStructures.h"
#include "Time.h"


class EventHandler {
    /**
    * Handles default events and passes them down after processing
    * them through context.
    * 
    * EventHandler is part of Controller and cannot be part of Simulation.
    */
    InputEvents *inputEvents;
    Focus *focus;
    ActionMap *actionMap;
    ISimulationEvents *worldEvents;
    std::unordered_map<ChunkPosition, ISimulationEvents *> *chunkEvents;
public:
    EventHandler(InputEvents *inputEvents, Focus *focus, ActionMap *actionMap);
    void registerWorldEvents(ISimulationEvents *worldEvents);
    void registerChunkEvents(std::unordered_map<ChunkPosition, ISimulationEvents *> *chunkEvents);
    friend void handleKeyboardKey(ALLEGRO_EVENT *ae, void *obj);
    friend void handleKeyboardLetter(ALLEGRO_EVENT *ae, void *obj);
};

void handleKeyboardKey(ALLEGRO_EVENT *ae, void *obj);
void handleKeyboardLetter(ALLEGRO_EVENT *ae, void *obj);
