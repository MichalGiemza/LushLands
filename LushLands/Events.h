#pragma once
#include "ConstantSets.h"

#define CHAR_ID(a, b, c, d) (((a) << 24) | ((b) << 16) | ((c) << 8) | (d))
#define IS_USER_EVENT(t) ((t) >= 'U' << 24 && (t) < 'V' << 24)


// Chunk event types
const simulationevent mobility_attempt_go = CHAR_ID('M', 'A', 'G', 0); //data1: DynamicCollider, data2:desiredPosition;

// World event types
const simulationevent player_wills_go_north = CHAR_ID('P', 'A', 'G', 0);
const simulationevent player_wills_go_south = player_wills_go_north + 1;
const simulationevent player_wills_go_east = player_wills_go_north + 2;
const simulationevent player_wills_go_west = player_wills_go_north + 3;
const simulationevent player_wills_use = CHAR_ID('P', 'A', 'U', 0);

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

const systemevent camera_move_north = CHAR_ID('U', 'A', 'G', 0);
const systemevent camera_move_south = camera_move_north + 1;
const systemevent camera_move_east = camera_move_north + 2;
const systemevent camera_move_west = camera_move_north + 3;
