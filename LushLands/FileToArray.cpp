#include "FileToArray.h"

char **FileToArray::readFile(rawpath path) {
    // Prepare file
    std::ifstream file {};
    file.open(path);
    // Count lines
    int n = std::count(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), '\n');
    // Prepare file
    file.clear();
    file.seekg(0);
    // Load file content to array
    char **arr = (char **)malloc(n * sizeof(char *));
    char line[maxLineLength];
    if (file.is_open()) {
        for (int i = 0; i < n; i++) {
            file.getline(line, maxLineLength);
            int l = strlen(line) + 1;
            char *lineToSave = new char[l];
            lineToSave[0] = 0;
            strcpy_s(lineToSave, l, line);
            arr[i] = lineToSave;
        }
        file.close();
    }
    return arr;
}
