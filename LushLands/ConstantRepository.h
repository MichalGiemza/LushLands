#pragma once
#include <unordered_map>
#include <string>
#include <exception>
#include <tuple>
#include <cstring>
#include "DataTypes.h"
#include "Size.h"
#include "Agui/Color.hpp"
#include "Logger.h"
#include "JsonHandler.h"


class ConstantRepository {
    /** 
    * Allows to select specified constant (const char*) by reading provided text content.
    * This is central repository of constants.
    */
    static std::unordered_map<size_t, TextureLocalization *> textureLocalizationMap;
    static std::unordered_map<entitytype, TextureLocalization *> textureLocalizationEntityMap;
    static std::unordered_map<std::string, entitytype> entityTypeMap;
    static std::unordered_map<std::string, tag> tagMap;
    static std::unordered_map<std::tuple<float, float, float>, Size *> sizeMap;
    static std::unordered_map<std::tuple<uint8_t, uint8_t, uint8_t>, agui::Color *> colorMap;
    static std::unordered_map<std::string, gendertype> genderTypeMap;
    static std::unordered_map<std::string, tag> toolTypeMap;
    static std::unordered_map<size_t, EntityDrops *> entityDropsMap;
    static std::unordered_map<std::string, updatetype> updateTypeMap;
    static std::unordered_map<std::string, entitytype> entitytypeMap;
    static std::unordered_map<std::string, stack> maxStackMap;
private:
    static EntityDrops *buildEntityDrops(const json &entityDropsData);
public:
    static void init();
    static const entitytype selectEntityType(const std::string &entityType, bool create = false);
    static const entitytype selectEntityType(entitytype entityType, bool create = false);
    static const tag selectTag(const std::string &tag_, bool create = false);
    static const tag selectTag(tag tag_);
    static const Size *selectSize(float w, float h, float l);
    static const agui::Color *selectColor(uint8_t r, uint8_t g, uint8_t b);
    static const gendertype selectGenderType(std::string &genderType, bool create = false);
    static const tag selectToolType(std::string &toolType, bool create = false);
    static const EntityDrops *selectEntityDrops(const json &entityDropsData);
    static const updatetype selectUpdateType(std::string &updateType);
    static const stack selectMaxStack(const std::string &stackLabel);
    static const std::vector<entitytype> getAllEntityTypes();
};

using CR = ConstantRepository;
