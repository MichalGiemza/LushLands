#pragma once
#include <iostream>
#include <fstream>
#include <boost/json.hpp>
#include <boost/container_hash/hash.hpp>
#include "Logger.h"

using namespace boost;


struct JSONValueHasher {
    std::size_t operator()(const boost::json::value &value) const;
};

class JsonHandler {
    /**
    * Class for handling JSON text files. Uses boost.
    */
public:
    static json::value *parseJson(const char *path);
    static json::value *parseJson(const std::filesystem::path &path);
    static json::value *parseJson(std::ifstream &ifstr);

    static std::size_t hashEntityDrops(const boost::json::array &arr);
};

json::string a_s(const json::object &d, const char *key);
char *a_c(const json::string &str);
