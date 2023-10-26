#include "JsonHandler.h"

std::size_t JSONValueHasher::operator()(const boost::json::value &value) const {
    std::size_t seed = 0;

    // Hash based on the value type
    boost::hash_combine(seed, value.kind());

    // Hash based on the actual value
    if (value.is_int64())
        boost::hash_combine(seed, value.get_int64());
    else if (value.is_uint64())
        boost::hash_combine(seed, value.get_uint64());
    else if (value.is_double())
        boost::hash_combine(seed, value.get_double());
    else if (value.is_string())
        boost::hash_combine(seed, value.get_string());
    // Add more cases for other value types as needed

    return seed;
}

json::value *JsonHandler::parseJson(const char *path) {
    std::ifstream jsonFile(path);
    return parseJson(jsonFile);
}

json::value *JsonHandler::parseJson(const std::filesystem::path &path) {
    std::ifstream jsonFile(path);
    return parseJson(jsonFile);
}

json::value *JsonHandler::parseJson(std::ifstream &jsonFile) {
    // Access file
    if (!jsonFile.is_open()) {
        Logger::log(lg::ERROR_, "Failed to open JSON file.");
        return nullptr;
    }

    // Read the contents of the JSON file
    std::string jsonString((std::istreambuf_iterator<char>(jsonFile)), std::istreambuf_iterator<char>());

    // Parse the JSON string
    json::error_code error;
    json::value *jsonValue = new json::value(json::parse(jsonString, error));
    if (error) {
        Logger::log(lg::ERROR_, "Failed to parse JSON: %s", error.message());
        return nullptr;
    }
    return jsonValue;
}

std::size_t JsonHandler::hashEntityDrops(const boost::json::array &arr) {
    std::size_t seed = 0;

    // Iterate over each element and add its hash to the seed
    for (const auto &element : arr) {
        auto &o = element.as_object();
        boost::hash_combine(seed, JSONValueHasher()(o.at("EntityType")));
        boost::hash_combine(seed, JSONValueHasher()(o.at("ChanceGuaranteed")));
        boost::hash_combine(seed, JSONValueHasher()(o.at("ChanceLow")));
        boost::hash_combine(seed, JSONValueHasher()(o.at("ChanceHigh")));
    }

    return seed;
}

json::string a_s(const json::object &d, const char *key) {
    if (not d.contains(key) or d.at(key).is_null())
        return json::string();
    return d.at(key).as_string();
}

char *a_c(const json::string &str) {
    int n = str.size() + 1;
    char *txt = new char[n];
    strncpy_s(txt, n, str.c_str(), str.size());
    return txt;
}
