#include "Logger.h"

ALLEGRO_FONT *Logger::font;
ALLEGRO_TEXTLOG *Logger::textlog;
std::vector<LoggerSubscription> Logger::logSubscribers;
loglevel Logger::logLevel;
const int Logger::textLogLength;

void Logger::openLogMonospace(void) {
    if (al_init_native_dialog_addon()) {
        textlog = al_open_native_text_log("Log", ALLEGRO_TEXTLOG_MONOSPACE);
    }
}

void Logger::logPrintf(loglevel logLevel, char const *format, ...) {
    char str[1024];
    va_list args;
    va_start(args, format);
    vsnprintf(str, sizeof str, format, args);
    va_end(args);
    al_append_native_text_log(textlog, "%s", str);
}

void Logger::log(loglevel logLevel, char const *format, ...) {
    consoleline str(new char[textLogLength]);
    va_list args;
    va_start(args, format);
    vsnprintf(str.get(), textLogLength, format, args);
    va_end(args);

    if (logLevel >= Logger::logLevel)
        al_append_native_text_log(textlog, "%s\n", str.get());
    for (auto &s : Logger::logSubscribers) {
        if (s.logLevel >= Logger::logLevel) {
            s.func(s.caller, str);
        }
    }
}

void Logger::subscribe(loglevel logLevel, std::function<void(void *caller, consoleline str)> func, void *caller) {
    LoggerSubscription ls = {
        logLevel,
        func,
        caller
    };
    Logger::logSubscribers.push_back(ls);
}

void Logger::logKey(loglevel logLevel, char const *how, int keycode, int unichar, int modifiers) {
    char multibyte[5] = { 0, 0, 0, 0, 0 };
    const char *key_name;

    al_utf8_encode(multibyte, unichar <= 32 ? ' ' : unichar);
    key_name = al_keycode_to_name(keycode);
    logPrintf(logLevel, "Key: %-8s  code=%03d, char='%s' (%4d), modifiers=%08x, [%s]\n",
        how, keycode, multibyte, unichar, modifiers, key_name);
}

void Logger::logAction(loglevel logLevel, actioncode acode) {
    logPrintf(logLevel, "Action: %s\n", acode);
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

void Logger::logAbort(char const *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
}

void Logger::init() {
    textlog = NULL;
    openLogMonospace();

    if (!al_init_font_addon())
        throw std::logic_error(could_not_init_allegro_font);
    if (!al_init_ttf_addon())
        throw std::logic_error(could_not_init_allegro_ttf);

    font = al_load_ttf_font(jamesStrokerFont, 64, 0);
    logSubscribers = std::vector<LoggerSubscription>();
    logLevel = ll::DEBUG_ALL;

}

void Logger::destruct() {
    closeLog(false);
}
