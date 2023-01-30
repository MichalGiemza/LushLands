#pragma once
#include "ConstantSets.h"

#define CHAR_ID(a, b, c, d) (((a) << 24) | ((b) << 16) | ((c) << 8) | (d))


// Chunk event types
const simulationevent mob_attempt_go = CHAR_ID('M', 'A', 'G', 0); //data1: DynamicCollider, data2:(desired)Position;


// World event types
const simulationevent player_attempt_go_north = CHAR_ID('P', 'A', 'G', 0);
const simulationevent player_attempt_go_south = player_attempt_go_north + 1;
const simulationevent player_attempt_go_east = player_attempt_go_north + 2;
const simulationevent player_attempt_go_west = player_attempt_go_north + 3;
const simulationevent player_attempt_use = CHAR_ID('P', 'A', 'U', 0);

// System Event Types
const systemevent letter_typed = CHAR_ID('U', 'L', 'T', 0);
const systemevent camera_move_north = CHAR_ID('U', 'A', 'G', 0);
const systemevent camera_move_south = camera_move_north + 1;
const systemevent camera_move_east = camera_move_north + 2;
const systemevent camera_move_west = camera_move_north + 3;
