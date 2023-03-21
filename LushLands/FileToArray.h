#pragma once
#include "DataTypes.h"
#include <fstream>

class FileToArray {
    /** 
    * Tool for reading text files.
    * Tool reads lines and puts them into dynamic array.
    */
    static const int maxLineLength = 64;
public:
    static char **readFile(rawpath pathToFile);
};

