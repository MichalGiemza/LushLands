#include "Core.h"

bool Core::initAllegro() {
	// Allegro5 init
	if (!al_init())
		return false;
	if (!al_init_image_addon())
		return false;
	if (!al_init_font_addon())
		return false;
	if (!al_init_ttf_addon())
		return false;
	if (!al_init_primitives_addon())
		return false;
	if (!al_install_mouse())
		return false;
	if (!al_install_keyboard())
		return false;
	// Events
	queue = al_create_event_queue();
	userEventSource = new ALLEGRO_EVENT_SOURCE();
	al_init_user_event_source(userEventSource);
	al_register_event_source(queue, userEventSource);
	// Timers
	timerTPS = al_create_timer(1.0 / TicksPerSecond);
	timerFPS = al_create_timer(1.0 / FramesPerSecond);
	al_register_event_source(queue, al_get_timer_event_source(timerTPS));
	al_register_event_source(queue, al_get_timer_event_source(timerFPS));
	// Screen
	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	display = al_create_display(displayWidth, displayHeight);
	if (!display)
		return false;
	// Mouse
	al_show_mouse_cursor(display);
	al_set_new_bitmap_flags(ALLEGRO_VIDEO_BITMAP);
	// Window
	al_set_window_title(display, "Agui - Example");
	// Done
	return true;
}

void Core::initAgui() {
	// Loaders
	agui::Image::setImageLoader(new agui::Allegro5ImageLoader);
	agui::Font::setFontLoader(new agui::Allegro5FontLoader);
	// Handlers
	inputHandler = new agui::Allegro5Input();
	graphicsHandler = new agui::Allegro5Graphics();
	agui::Color::setPremultiplyAlpha(true);
	// GUI
	gui = new agui::Gui();
	gui->setInput(inputHandler);
	gui->setGraphics(graphicsHandler);
	// Font
	defaultFont = agui::Font::load(fontNormaleste, 10);
	agui::Widget::setGlobalFont(defaultFont);
}

Core::Core() {
	// Allegro
	if (not initAllegro())
		throw std::logic_error(could_not_init_allegro);
	// Agui
	initAgui();
	// TextureManager
	TextureManager::init();
}

void Core::processEvent(const ALLEGRO_EVENT &ev) {
	inputHandler->processEvent(ev);
}

agui::Gui *Core::getGUI() {
	return gui;
}

ALLEGRO_EVENT_QUEUE *Core::getQueue() {
	return queue;
}

ALLEGRO_TIMER *Core::getFPSTimer() {
	return timerFPS;
}

ALLEGRO_TIMER *Core::getTPSTimer() {
	return timerTPS;
}

ALLEGRO_EVENT_SOURCE *Core::getUserEventSource() {
	return userEventSource;
}

ALLEGRO_DISPLAY *Core::getDisplay() {
	return display;
}

