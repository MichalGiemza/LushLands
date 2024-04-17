#include "MenuActionListeners.h"

void ResumeActionListener::actionPerformed(const agui::ActionEvent &ev) {
    ie->emitEvent(user_open_pause_menu);
}

void SaveActionListener::actionPerformed(const agui::ActionEvent &ev) {
    // TODO
}

void LoadActionListener::actionPerformed(const agui::ActionEvent &ev) {
    // TODO
}

void SettingsActionListener::actionPerformed(const agui::ActionEvent &ev) {
    // TODO
}

void ExitActionListener::actionPerformed(const agui::ActionEvent &ev) {
    ie->emitEvent(ALLEGRO_EVENT_DISPLAY_CLOSE);
}
