#include "Logger.h"

ALLEGRO_FONT *Logger::font;
ALLEGRO_TEXTLOG *Logger::textlog;

void Logger::openLogMonospace(void) {
    if (al_init_native_dialog_addon()) {
        textlog = al_open_native_text_log("Log", ALLEGRO_TEXTLOG_MONOSPACE);
    }
}

void Logger::logPrintf(char const *format, ...) {
    char str[1024];
    va_list args;
    va_start(args, format);
    vsnprintf(str, sizeof str, format, args);
    va_end(args);
    al_append_native_text_log(textlog, "%s", str);
}

void Logger::logKey(char const *how, int keycode, int unichar, int modifiers) {
    char multibyte[5] = { 0, 0, 0, 0, 0 };
    const char *key_name;

    al_utf8_encode(multibyte, unichar <= 32 ? ' ' : unichar);
    key_name = al_keycode_to_name(keycode);
    logPrintf("Key: %-8s  code=%03d, char='%s' (%4d), modifiers=%08x, [%s]\n",
        how, keycode, multibyte, unichar, modifiers, key_name);
}

void Logger::logAction(actioncode acode) {
    logPrintf("Action: %s\n", acode);
}

void Logger::closeLog(bool wait_for_user) {
    if (textlog && wait_for_user) {
        ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
        al_register_event_source(queue, al_get_native_text_log_event_source(
            textlog));
        al_wait_for_event(queue, NULL);
        al_destroy_event_queue(queue);
    }

    al_close_native_text_log(textlog);
    textlog = NULL;
}

void Logger::init() {
    textlog = NULL;
    openLogMonospace();

    al_init_font_addon();
    al_init_ttf_addon();

    font = al_load_ttf_font("fonts/James Stroker.ttf", 64, 0);
    al_clear_to_color(al_map_rgb_f(0, 0, 0)); // Display
    al_flip_display(); // Display TODO
}

void Logger::destruct() {
    closeLog(false);
}
