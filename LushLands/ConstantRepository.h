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
#include <cstring>


class ConstantRepository {
    /** 
    * Allows to select specified constant (const char*) by reading provided text content.
    * This is central repository of constants.
    */
    static std::unordered_map<size_t, TextureLocalization *> textureLocalizationMap;
    static std::unordered_map<entitytype, TextureLocalization *> textureLocalizationEntityMap;
    static std::unordered_map<json::string, entitytype> entityTypeMap;
    static std::unordered_map<json::string, tag> tagMap;
    static std::unordered_map<std::tuple<float, float, float>, Size *> sizeMap;
    static std::unordered_map<std::tuple<uint8_t, uint8_t, uint8_t>, Color *> colorMap;
    static std::unordered_map<json::string, gendertype> genderTypeMap;
    static std::unordered_map<json::string, tag> toolTypeMap;
    static std::unordered_map<size_t, EntityDrops *> entityDropsMap;
    static std::unordered_map<json::string, updatetype> updateTypeMap;
    static std::unordered_map<json::string, entitytype> entitytypeMap;
    static std::unordered_map<json::string, stack> maxStackMap;
private:
    static EntityDrops *buildEntityDrops(const json::array &entityDropsData);
public:
    static const TextureLocalization *selectTextureLocalization(const json::object &data);
    static const TextureLocalization *selectTextureLocalization(entitytype entityType);
    static const entitytype selectEntityType(const json::string &entityType, bool create = false);
    static const entitytype selectEntityType(entitytype entityType);
    static const tag selectTag(const json::string &tag_, bool create = false);
    static const tag selectTag(tag tag_);
    static const Size *selectSize(float w, float h, float l);
    static const Color *selectColor(uint8_t r, uint8_t g, uint8_t b);
    static const gendertype selectGenderType(json::string &genderType, bool create = false);
    static const tag selectToolType(json::string &toolType, bool create = false);
    static const EntityDrops *selectEntityDrops(const json::array &entityDropsData);
    static const updatetype selectUpdateType(json::string &updateType);
    static const stack selectMaxStack(const json::string &stackLabel);
    static const std::vector<entitytype> getAllEntityTypes();
};

using CR = ConstantRepository;
