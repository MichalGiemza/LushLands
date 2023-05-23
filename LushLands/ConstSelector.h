#pragma once
#include "DataTypes.h"
#include "Size.h"
#include "Color.h"
#include <unordered_map>
#include <string>
#include <exception>
#include "Logger.h"
#include <tuple>
#include <boost/json.hpp>
#include "JsonHandler.h"

using namespace boost;


class ConstSelector {
    /** 
    * Allows to select specified constant (const char*) by reading provided text content.
    * This is central repository of constants.
    */
    static std::unordered_map<size_t, TextureLocalization *> textureLocalizationMap;

    static std::unordered_map<json::string, entitytype> entityTypeMap;
    static std::unordered_map<std::tuple<float, float, float>, Size *> sizeMap;
    static std::unordered_map<std::tuple<uint8_t, uint8_t, uint8_t>, Color *> colorMap;
    static std::unordered_map<json::string, gendertype> genderTypeMap;
    static std::unordered_map<json::string, tooltype> toolTypeMap;
    static std::unordered_map<size_t, EntityDrops *> entityDropsMap;
    static std::unordered_map<json::string, updatetype> updateTypeMap;

    static std::unordered_map<json::string, itemtype> itemTypeMap;
private:
    static EntityDrops *buildEntityDrops(const json::array &entityDropsData);
public:
    static const TextureLocalization *selectTextureLocalization(const json::object &data);

    static const entitytype selectEntityType(json::string &entityType);
    static const Size *selectSize(float w, float h, float l);
    static const Color *selectColor(uint8_t r, uint8_t g, uint8_t b);
    static const gendertype selectGenderType(json::string &genderType);
    static const tooltype selectToolType(json::string &toolType);
    static const EntityDrops *selectEntityDrops(const json::array &entityDropsData); // TODO - argument
    static const updatetype selectUpdateType(json::string &updateType);

    static const itemtype selectItemType(const json::string &itemType);
};

