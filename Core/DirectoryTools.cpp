#include "DirectoryTools.h"

void listDirectoryContents(const std::string &path) {
    namespace fs = std::filesystem;
    return fs::directory_iterator(path);
}

