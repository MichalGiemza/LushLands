#pragma once
#include <map>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Entity {
    /**
    * Definicja najbardziej podstawowego elementu œwiata.
    */
    string typeName;
    string description;
public:
    Entity(string typeName, string description);
    string getTypeName();
    string getDescription();
};
