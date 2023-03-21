#include "NameGenerator.h"

NameGenerator::NameGenerator(rawpath cmPath, rawpath cfPath, rawpath cnPath) {
    commonMaleNames = (name *)FileToArray::readFile(cmPath);
    commonFemaleNames = (name *)FileToArray::readFile(cfPath);
    commonNeutralNames = (name *)FileToArray::readFile(cnPath);
}

name NameGenerator::getCommonName(gendertype gender) {
    int r = rand();
    if (gender == gdr::male)
        return commonMaleNames[r % sizeof(commonMaleNames)];
    if (gender == gdr::female)
        return commonFemaleNames[r % sizeof(commonFemaleNames)];
    if (gender == gdr::other)
        return commonNeutralNames[r % sizeof(commonNeutralNames)];
    return 0;
}
