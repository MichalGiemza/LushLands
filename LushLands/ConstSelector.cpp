#include "ConstSelector.h"

std::unordered_map<size_t, TextureLocalization *> ConstSelector::textureLocalizationMap;

std::unordered_map<json::string, entitytype> ConstSelector::entityTypeMap;
std::unordered_map<std::tuple<float, float, float>, Size *> ConstSelector::sizeMap;
std::unordered_map<std::tuple<uint8_t, uint8_t, uint8_t>, Color *> ConstSelector::colorMap;
std::unordered_map<json::string, gendertype> ConstSelector::genderTypeMap;
std::unordered_map<json::string, tooltype> ConstSelector::toolTypeMap;
std::unordered_map<size_t, EntityDrops *> ConstSelector::entityDropsMap;
std::unordered_map<json::string, updatetype> ConstSelector::updateTypeMap;

std::unordered_map<json::string, itemtype> ConstSelector::itemTypeMap;


EntityDrops *ConstSelector::buildEntityDrops(const json::array &entityDropsData) {
	int n = entityDropsData.size();
	ItemDropChance *idc = (ItemDropChance *)malloc(sizeof(ItemDropChance) * n);
	for (int i = 0; i < n; i++) {
		auto &add = entityDropsData.at(i).as_object();
		auto &im = add.at("ItemType").as_string();
		idc[i].item = selectItemType(im);
		idc[i].chanceGuaranteed = add.at("ChanceGuaranteed").as_int64();
		idc[i].chanceLow = add.at("ChanceLow").as_int64();
		idc[i].chanceHigh = add.at("ChanceHigh").as_int64();
	}
	return new EntityDrops { n, idc };
}

const TextureLocalization *ConstSelector::selectTextureLocalization(const json::object &d) {
	// Control structure
	TextureLocalization tl = TextureLocalization();
	//   Position
	auto &tp = d.at("TexturePosition");
	if (not tp.is_null()) {
		tl.x = tp.as_object().at("X").as_int64();
		tl.x = tp.as_object().at("Y").as_int64();
	} else {
		tl.x = 0;
		tl.y = 0;
	}
	//   Size
	auto &ts = d.at("TextureSize");
	if (not ts.is_null()) {
		tl.w = ts.as_object().at("W").as_int64();
		tl.h = ts.as_object().at("H").as_int64();
	} else {
		tl.w = 0;
		tl.h = 0;
	}
	//   ImagePath
	auto &ti = d.at("TextureImage");
	tl.path = ti.as_string().c_str();

	// Actual checking
	size_t key = std::hash<TextureLocalization> {}(tl);
	auto it = textureLocalizationMap.find(key);
	if (it != textureLocalizationMap.end()) {
		return it->second;
	} else {
		textureLocalizationMap[key] = new TextureLocalization(tl);
		return textureLocalizationMap[key];
	}
}

const entitytype ConstSelector::selectEntityType(json::string &entityType) {
    auto it = entityTypeMap.find(entityType);
	if (it != entityTypeMap.end()) {
		return it->second;
	} else {
		Logger::log(lg::ERROR_, "EntityType '%s' not found!", entityType.c_str());
	}
}

const Size *ConstSelector::selectSize(float w, float h, float l) {
	auto key = std::tuple(w, h, l);
	auto it = sizeMap.find(key);
	if (it != sizeMap.end()) {
		return it->second;
	} else {
		sizeMap[key] = new Size(w, h, l);
		return sizeMap[key];
	}
}

const Color *ConstSelector::selectColor(uint8_t r, uint8_t g, uint8_t b) {
	auto key = std::tuple(r, g, b);
	auto it = colorMap.find(key);
	if (it != colorMap.end()) {
		return it->second;
	} else {
		colorMap[key] = new Color(r, g, b, 255);
		return colorMap[key];
	}
}

const gendertype ConstSelector::selectGenderType(json::string &genderType) {
	auto it = genderTypeMap.find(genderType);
	if (it != genderTypeMap.end()) {
		return it->second;
	} else {
		Logger::log(lg::ERROR_, "GenderType '%s' not found!", genderType.c_str());
	}
}

const tooltype ConstSelector::selectToolType(json::string &toolType) {
	auto it = toolTypeMap.find(toolType);
	if (it != toolTypeMap.end()) {
		return it->second;
	} else {
		Logger::log(lg::ERROR_, "ToolType '%s' not found!", toolType.c_str());
	}
}

const EntityDrops *ConstSelector::selectEntityDrops(const json::array &entityDropsData) {
	size_t key = JsonHandler::hash_array(entityDropsData);
	auto it = entityDropsMap.find(key);
	if (it != entityDropsMap.end()) {
		return it->second;
	} else {
		entityDropsMap[key] = buildEntityDrops(entityDropsData);
		return entityDropsMap[key];
	}
}

const updatetype ConstSelector::selectUpdateType(json::string &updateType) {
	auto it = updateTypeMap.find(updateType);
	if (it != updateTypeMap.end()) {
		return it->second;
	} else {
		Logger::log(lg::ERROR_, "UpdateType '%s' not found!", updateType.c_str());
	}
}

const itemtype ConstSelector::selectItemType(const json::string &itemType) {
	auto it = itemTypeMap.find(itemType);
	if (it != itemTypeMap.end()) {
		return it->second;
	} else {
		Logger::log(lg::ERROR_, "ItemType '%s' not found!", itemType.c_str());
	}
}
