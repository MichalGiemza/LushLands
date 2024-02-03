#include "JsonHandler.h"

std::size_t JSONValueHasher::operator()(const json &value) const {
    std::size_t seed = 0;

    // Hash based on the value type
    HashTool::hashCombine(seed, value); // TODO: Hashes jsons properly?

    // Hash based on the actual value
    //if (value.is_int64())
    //    hash_combine(seed, value.get_int64());
    //else if (value.is_uint64())
    //    hash_combine(seed, value.get_uint64());
    //else if (value.is_double())
    //    hash_combine(seed, value.get_double());
    //else if (value.is_string())
    //    hash_combine(seed, value.get_string());
    // Add more cases for other value types as needed

    return seed;
}

json JsonHandler::parseJson(const char *path) {
    std::ifstream jsonFile(path);
    return parseJson(jsonFile);
}

json JsonHandler::parseJson(const std::filesystem::path &path) {
    std::ifstream jsonFile(path);
    return parseJson(jsonFile);
}

json JsonHandler::parseJson(std::ifstream &jsonFile) {
    // Access file
    if (!jsonFile.is_open()) {
        Logger::log(lg::ERROR_, "Failed to open JSON file.");
        return nullptr;
    }

    // Parse the JSON string
    try {
        return json::parse(jsonFile);
    }
    catch (const std::exception &er) {
        Logger::log(lg::ERROR_, "Failed to parse JSON: %s", er.what());
        return nullptr;
    }
}

std::size_t JsonHandler::hashEntityDrops(const json &arr) {
    std::size_t seed = 0;

    // Iterate over each element and add its hash to the seed
    for (const auto &element : arr) {
        auto &o = element;
        HashTool::hashCombine(seed, JSONValueHasher()(o.at("EntityType")));
        HashTool::hashCombine(seed, JSONValueHasher()(o.at("ChanceGuaranteed")));
        HashTool::hashCombine(seed, JSONValueHasher()(o.at("ChanceLow")));
        HashTool::hashCombine(seed, JSONValueHasher()(o.at("ChanceHigh")));
    }

    return seed;
}

std::string a_s(const json &d, const char *key) {
    if (not d.contains(key) or d.at(key).is_null())
        return std::string();
    return d[key];
}

char *a_c(const std::string &str) {
    int n = str.size() + 1;
    char *txt = new char[n];
    strncpy_s(txt, n, str.c_str(), str.size());
    return txt;
}
