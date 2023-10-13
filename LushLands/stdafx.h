#pragma once

#define ALLEGRO_UNSTABLE
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <allegro5/events.h>
#include <allegro5/keycodes.h>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <set>

#include "Color.h"
#include "Colors.h"
#include "ConstantRepository.h"
#include "ConstantSets.h"
#include "Constants.h"
#include "DataTypes.h"
#include "Directories.h"
#include "EventTypes.h"
#include "Events.h"
#include "FileToArray.h"
#include "GameElement.h"
#include "JsonHandler.h"
#include "Logger.h"
#include "NameGenerator.h"
#include "NumTools.h"
#include "Position.h"
#include "PositionStructures.h"
#include "Random_.h"
#include "Size.h"
#include "SystemConstants.h"
#include "WorldRectangle.h"
