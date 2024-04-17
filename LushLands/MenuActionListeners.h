#pragma once
#include "Agui/ActionListener.hpp"
#include "InputEvents.h"
#include "EventFactory.h"
#include "allegro5/events.h"

class ResumeActionListener : public agui::ActionListener {
    InputEvents *ie;
public:
    ResumeActionListener(InputEvents *inputEvents) : ie(inputEvents) {}
    virtual void actionPerformed(const agui::ActionEvent &ev);
};

class SaveActionListener : public agui::ActionListener {
    InputEvents *ie;
public:
    SaveActionListener(InputEvents *inputEvents) : ie(inputEvents) {}
    virtual void actionPerformed(const agui::ActionEvent &ev);
};

class LoadActionListener : public agui::ActionListener {
    InputEvents *ie;
public:
    LoadActionListener(InputEvents *inputEvents) : ie(inputEvents) {}
    virtual void actionPerformed(const agui::ActionEvent &ev);
};

class SettingsActionListener : public agui::ActionListener {
    InputEvents *ie;
public:
    SettingsActionListener(InputEvents *inputEvents) : ie(inputEvents) {}
    virtual void actionPerformed(const agui::ActionEvent &ev);
};

class ExitActionListener : public agui::ActionListener {
    InputEvents *ie;
public:
    ExitActionListener(InputEvents *inputEvents) : ie(inputEvents) {}
    virtual void actionPerformed(const agui::ActionEvent &ev);
};