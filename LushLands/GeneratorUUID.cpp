#include "GeneratorUUID.h"

std::string GeneratorUUID::generateUUID() {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<uint64_t> dis;

    uint64_t part1 = dis(gen);
    uint64_t part2 = dis(gen);

    std::ostringstream oss;
    oss << std::hex << std::setw(16) << std::setfill('0') << part1
        << std::hex << std::setw(16) << std::setfill('0') << part2;

    return oss.str();
}
