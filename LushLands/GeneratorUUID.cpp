#include "GeneratorUUID.h"

std::random_device GeneratorUUID::rd;
std::mt19937_64 GeneratorUUID::gen = std::mt19937_64(rd());
std::uniform_int_distribution<uint64_t> GeneratorUUID::dis;

uuid GeneratorUUID::generateUUID() {
    return dis(gen);
}
