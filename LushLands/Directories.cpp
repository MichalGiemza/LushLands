#include "Directories.h"

std::filesystem::directory_iterator Directories::listDir(rawpath path) {
    std::filesystem::path directoryPath(path);
    return listDir(directoryPath);
}

std::filesystem::directory_iterator Directories::listDir(std::filesystem::path directoryPath) {
    try {
        // Check if the path exists and is a directory
        if (std::filesystem::exists(directoryPath) && std::filesystem::is_directory(directoryPath)) {
            // Iterate over the directory entries
            return std::filesystem::directory_iterator(directoryPath);
        } else {
            Logger::log(lg::ERROR_, "Directory does not exist or is not a valid directory.");
        }
    }
    catch (const std::filesystem::filesystem_error &ex) {
        Logger::log(lg::ERROR_, "An error occurred: %s", ex.what());
    }
}
