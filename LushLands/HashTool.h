#pragma once
#include <functional>

class HashTool {
public:
    template <typename T>
    static void hashCombine(std::size_t &seed, const T &value) {
        seed ^= std::hash<T>{}(value)+0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
};

