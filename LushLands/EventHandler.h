#pragma once
#include "DataTypes.h"
#include "GameElement.h"
#include "Focus.h"
#include "ConstantSets.h"
#include "InputEvents.h"
#include "ActionMap.h"
#include "IWorldEvents.h"
#include "ActionMap.h"


class EventHandler {
    /**
    * Handles default events and passes them down after processing
    * them through context.
    */
    InputEvents *inputEvents;
    Focus *focus;
    ActionMap *actionMap;
    IWorldEvents *worldEvents;
public:
    EventHandler(InputEvents *inputEvents, Focus *focus, ActionMap *actionMap);
    void registerWorldEvents(IWorldEvents *worldEvents);

    friend void handleKeyboardKey(ALLEGRO_EVENT *ae, void *obj);
    friend void handleKeyboardLetter(ALLEGRO_EVENT *ae, void *obj);
};

void handleKeyboardKey(ALLEGRO_EVENT *ae, void *obj);
void handleKeyboardLetter(ALLEGRO_EVENT *ae, void *obj);
