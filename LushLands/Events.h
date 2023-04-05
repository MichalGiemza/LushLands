#pragma once
#include "ConstantSets.h"

#define CHAR_ID(a, b, c, d) (((a) << 24) | ((b) << 16) | ((c) << 8) | (d))
#define IS_USER_EVENT(t) ((t) >= 'U' << 24 && (t) < 'V' << 24)


// Action Event Types
const simulationevent mobility_attempt_go = CHAR_ID('M', 'A', 'G', 0);
const simulationevent item_drop = CHAR_ID('I', 'D', 0, 0);

const simulationevent player_wills_go = CHAR_ID('P', 'A', 'G', 0);
const simulationevent player_wills_use = CHAR_ID('P', 'A', 'U', 0);
const simulationevent player_throws_item = CHAR_ID('P', 'A', 'T', 0);

const simulationevent player_hotbar = CHAR_ID('P', 'A', 'H', 0);
const cstint player_hotbar_keycount = 12;

// System Event Types
const systemevent user_interact = CHAR_ID('U', 'I', 0, 0); // UI stuff: settings, inventory
const systemevent user_open_pause_menu = CHAR_ID('U', 'M', 'P', 0);
const systemevent user_open_context_menu = CHAR_ID('U', 'M', 'C', 0);

const systemevent user_open_inventory = CHAR_ID('U', 'O', 'I', 0);
const systemevent user_open_map = CHAR_ID('U', 'O', 'M', 0);
const systemevent user_open_chat = CHAR_ID('U', 'O', 'C', 0);
const systemevent user_open_command_chat = user_open_chat + 1;
const systemevent user_open_status = CHAR_ID('U', 'O', 'S', 0);
const systemevent user_open_quests = CHAR_ID('U', 'O', 'Q', 0);
const systemevent user_open_build_menu = CHAR_ID('U', 'O', 'B', 0);

const systemevent user_quick_save = CHAR_ID('U', 'Q', 'S', 0);
const systemevent user_quick_load = CHAR_ID('U', 'Q', 'L', 0);

const systemevent letter_typed = CHAR_ID('U', 'I', 'L', 0);

const systemevent camera_move = CHAR_ID('U', 'A', 'G', 0);
