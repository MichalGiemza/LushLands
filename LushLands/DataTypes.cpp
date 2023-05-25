#include "DataTypes.h"

std::size_t std::hash<char *>::operator()(const char *p) const {
    std::size_t hash_ = 0;
    for (int i = 0; p[i] != 0; i++) {
        hash_ = 33 * hash_ + p[i];
    }
    return hash_;
}

std::size_t std::hash<TextureLocalization>::operator()(const TextureLocalization &p) const {
    size_t seed = 0;
    boost::hash_combine(seed, p.x);
    boost::hash_combine(seed, p.y);
    boost::hash_combine(seed, p.w);
    boost::hash_combine(seed, p.h);
    boost::hash_combine(seed, std::string(p.path));
    return seed;
}

bool operator==(const std::tuple<float, float, float> &lhs, const std::tuple<float, float, float> &rhs) {
    return std::get<0>(lhs) == std::get<0>(rhs) &&
        std::get<1>(lhs) == std::get<1>(rhs) &&
        std::get<2>(lhs) == std::get<2>(rhs);
}

std::size_t std::hash<std::tuple<float, float, float>>::operator()(const std::tuple<float, float, float> &p) const {
    return
        hash<float>()(std::get<0>(p)) ^
        hash<float>()(std::get<1>(p)) ^
        hash<float>()(std::get<2>(p));

}

bool operator==(const std::tuple<uint8_t, uint8_t, uint8_t> &lhs, const std::tuple<uint8_t, uint8_t, uint8_t> &rhs) {
    return std::get<0>(lhs) == std::get<0>(rhs) &&
        std::get<1>(lhs) == std::get<1>(rhs) &&
        std::get<2>(lhs) == std::get<2>(rhs);
}

std::size_t std::hash<std::tuple<uint8_t, uint8_t, uint8_t>>::operator()(const std::tuple<uint8_t, uint8_t, uint8_t> &p) const {
    return
        hash<uint8_t>()(std::get<0>(p)) ^
        hash<uint8_t>()(std::get<1>(p)) ^
        hash<uint8_t>()(std::get<2>(p));
}

