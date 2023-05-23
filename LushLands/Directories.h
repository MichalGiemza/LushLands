#pragma once
#include <filesystem>
#include "DataTypes.h"
#include "Logger.h"


class Directories {

public:
    static std::filesystem::directory_iterator listDir(rawpath path);
};

