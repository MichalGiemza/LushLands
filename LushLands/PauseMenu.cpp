#include "PauseMenu.h"

PauseMenu::PauseMenu(Core *core, InputEvents *inputEvents) : core(core), inputEvents(inputEvents) {
    setSize(w, h);
    setLocation(displayWidth / 3, displayHeight / 8);
    setVisibility(false);
    setBackColor(agui::UI_BG_COLOR);
    setMargins(2, 2, 2, 2);
    menuFont = agui::Font::load(fontDiamonaire, 20);

    // Menu Buttons
    for (int i = 0; i < nBtns; i++) {
        add(&btn[i]);
        btn[i].setText(btnTxt[i]);
        btn[i].setSize(w / 2, h / 10);
        btn[i].setFontColor(agui::COLOR_WHITE);
        btn[i].setFont(menuFont);
        int x_el = hm;
        int y_el = (vm + btn[i].getHeight()) * (i + 1);
        btn[i].setLocation(x_el, y_el);
    }

    // Action Listeners
    btn[0].addActionListener(new ResumeActionListener(inputEvents));
    btn[1].addActionListener(new SaveActionListener(inputEvents));
    btn[2].addActionListener(new LoadActionListener(inputEvents));
    btn[3].addActionListener(new SettingsActionListener(inputEvents));
    btn[4].addActionListener(new ExitActionListener(inputEvents));
}

