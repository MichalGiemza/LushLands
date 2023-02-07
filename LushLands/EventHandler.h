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
#include "ChunkLoadManager.h"


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
    miliseconds lastTimeUpdated;
    ChunkLoadManager *chunkLoadManager;
private:
    Time *worldTime;
    ISimulationEvents *worldEvents;
    std::unordered_map<ChunkPosition, ISimulationEvents *> chunkEvents;
public:
    EventHandler(InputEvents *inputEvents, Focus *focus, ActionMap *actionMap, ChunkLoadManager *chunkLoadManager);
    void registerWorldTime(Time *worldTime);
    void registerWorldEvents(ISimulationEvents *worldEvents);
    void registerChunkEvents(ChunkPosition &cPos, ISimulationEvents *chunkEvents);
    friend void updateSimulation(ALLEGRO_EVENT *ae, void *obj);
    friend void handleKeyboardKey(ALLEGRO_EVENT *ae, void *obj);
    friend void handleKeyboardLetter(ALLEGRO_EVENT *ae, void *obj);
};

void updateSimulation(ALLEGRO_EVENT *ae, void *obj);
void handleKeyboardKey(ALLEGRO_EVENT *ae, void *obj);
void handleKeyboardLetter(ALLEGRO_EVENT *ae, void *obj);
