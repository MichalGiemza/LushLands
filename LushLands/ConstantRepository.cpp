#include "ConstantRepository.h"

std::unordered_map<size_t, TextureLocalization *> CR::textureLocalizationMap;
std::unordered_map<entitytype, TextureLocalization *> CR::textureLocalizationEntityMap;
std::unordered_map<std::string, entitytype> CR::entityTypeMap;
std::unordered_map<std::string, tag> CR::tagMap;
std::unordered_map<std::tuple<float, float, float>, Size *> CR::sizeMap;
std::unordered_map<std::tuple<uint8_t, uint8_t, uint8_t>, agui::Color *> CR::colorMap;
std::unordered_map<std::string, gendertype> CR::genderTypeMap = {
	{ std::string(gdr::male), gdr::male },
	{ std::string(gdr::female), gdr::female },
	{ std::string(gdr::none), gdr::none },
	{ std::string(gdr::other), gdr::other },
};
std::unordered_map<std::string, tag> CR::toolTypeMap = {
	{ std::string(tg::axe), tg::axe},
	{ std::string(tg::pickaxe), tg::pickaxe },
	{ std::string(tg::shovel), tg::shovel },
	{ std::string(tg::weapon), tg::weapon },
	{ std::string(tg::bucket), tg::bucket },
	{ std::string(tg::harvesting_tool), tg::harvesting_tool }
};
std::unordered_map<size_t, EntityDrops *> CR::entityDropsMap;
std::unordered_map<std::string, updatetype> CR::updateTypeMap;
std::unordered_map<std::string, entitytype> CR::entitytypeMap;
std::unordered_map<std::string, stack> CR::maxStackMap = {
	{ std::string("maxStack"), mst::maxStack },
	{ std::string("mediumStact"), mst::mediumStact },
	{ std::string("smallStack"), mst::smallStack },
	{ std::string("singleItemStack"), mst::singleItemStack }
};


EntityDrops *ConstantRepository::buildEntityDrops(const json &entityDropsData) {
	int n = entityDropsData.size();
	ItemDropChance *idc = (ItemDropChance *)malloc(sizeof(ItemDropChance) * n);
	for (int i = 0; i < n; i++) {
		auto &add = entityDropsData.at(i);
 		auto &im = add.at("EntityType"); 
		idc[i].item = CR::selectEntityType(im);
		idc[i].chanceGuaranteed = add.at("ChanceGuaranteed");
		idc[i].chanceLow = add.at("ChanceLow");
		idc[i].chanceHigh = add.at("ChanceHigh");
	}
	return new EntityDrops { n, idc };
}

void ConstantRepository::init() {
	//try {
	//	for (const auto &entry : fs::directory_iterator(path)) {
	//		std::cout << entry.path().string() << std::endl;
	//	}
	//}
	//catch (const std::exception &e) {
	//	std::cerr << "Error: " << e.what() << std::endl;
	//}
}

const entitytype ConstantRepository::selectEntityType(const std::string &entityType, bool create) {
    auto it = entityTypeMap.find(entityType);
	if (it != entityTypeMap.end()) {
		return it->second;
	} else {
		if (create) {
			entityTypeMap[entityType] = a_c(entityType);
			return entityTypeMap[entityType];
		} else {
			Logger::log(lg::ERROR_, "EntityType '%s' not found!", entityType.c_str());
			return 0;
		}
	}
}

const entitytype ConstantRepository::selectEntityType(entitytype entityType, bool create) {
	auto str = std::string(entityType);
	return selectEntityType(str, create);
}

const tag ConstantRepository::selectTag(const std::string &tag_, bool create) {
	auto it = tagMap.find(tag_);
	if (it != tagMap.end()) {
		return it->second;
	} else {
		if (create) {
			tagMap[tag_] = a_c(tag_);
			return tagMap[tag_];
		} else {
			Logger::log(lg::ERROR_, "Tag '%s' not found!", tag_.c_str());
			return 0;
		}
	}
}

const tag ConstantRepository::selectTag(tag tag_) {
	auto str = std::string(tag_);
	return selectTag(str, false);
}

const Size *ConstantRepository::selectSize(float w, float h, float l) {
	auto key = std::tuple(w, h, l);
	auto it = sizeMap.find(key);
	if (it != sizeMap.end()) {
		return it->second;
	} else {
		sizeMap[key] = new Size(w, h, l);
		return sizeMap[key];
	}
}

const agui::Color *ConstantRepository::selectColor(uint8_t r, uint8_t g, uint8_t b) {
	auto key = std::tuple(r, g, b);
	auto it = colorMap.find(key);
	if (it != colorMap.end()) {
		return it->second;
	} else {
		colorMap[key] = new agui::Color(r, g, b, 255);
		return colorMap[key];
	}
}

const gendertype ConstantRepository::selectGenderType(std::string &genderType, bool create) {
	auto it = genderTypeMap.find(genderType);
	if (it != genderTypeMap.end()) {
		return it->second;
	} else {
		if (create) {
			genderTypeMap[genderType] = a_c(genderType);
			return genderTypeMap[genderType];
		} else {
			Logger::log(lg::ERROR_, "GenderType '%s' not found!", genderType.c_str());
			return 0;
		}
	}
}

const tag ConstantRepository::selectToolType(std::string &toolType, bool create) {
	if (toolType.empty()) {
		return 0;
	}
	auto it = toolTypeMap.find(toolType);
	if (it != toolTypeMap.end()) {
		return it->second;
	} else {
		if (create) {
			toolTypeMap[toolType] = a_c(toolType);
			return toolTypeMap[toolType];
		} else {
			Logger::log(lg::ERROR_, "ToolType '%s' not found!", toolType.c_str());
			return 0;
		}
	}
}

const EntityDrops *ConstantRepository::selectEntityDrops(const json &entityDropsData) {
	size_t key = JsonHandler::hashEntityDrops(entityDropsData);
	auto it = entityDropsMap.find(key);
	if (it != entityDropsMap.end()) {
		return it->second;
	} else {
		entityDropsMap[key] = buildEntityDrops(entityDropsData);
		return entityDropsMap[key];
	}
}

const updatetype ConstantRepository::selectUpdateType(std::string &updateType) {
	auto it = updateTypeMap.find(updateType);
	if (it != updateTypeMap.end()) {
		return it->second;
	} else {
		Logger::log(lg::ERROR_, "UpdateType '%s' not found!", updateType.c_str());
		return 0;
	}
}

const stack ConstantRepository::selectMaxStack(const std::string &stackLabel) {
	auto it = maxStackMap.find(stackLabel);
	if (it != maxStackMap.end()) {
		return it->second;
	} else {
		Logger::log(lg::ERROR_, "StackLabel '%s' not found!", stackLabel.c_str());
		return 0;
	}
}

const std::vector<entitytype> ConstantRepository::getAllEntityTypes() {
	std::vector<entitytype> values;
	for (const auto &pair : entityTypeMap) {
		values.push_back(pair.second);
	}
	return values;
}
