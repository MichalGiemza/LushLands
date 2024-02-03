#pragma once
#include <nlohmann/json.hpp>
#include "HashTool.h"
#include "DataTypes.h"
#include <iostream>
#include <fstream>
#include "Logger.h"


using json = nlohmann::json;

struct JSONValueHasher {
    std::size_t operator()(const json &value) const;
};

class JsonHandler {
    /**
    * Class for handling JSON text files. Uses boost.
    */
public:
    static json parseJson(const char *path);
    static json parseJson(const std::filesystem::path &path);
    static json parseJson(std::ifstream &ifstr);

    static std::size_t hashEntityDrops(const json &arr);
};

std::string a_s(const json &d, const char *key);
char *a_c(const std::string &str);
