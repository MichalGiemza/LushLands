#pragma once
#include "DataTypes.h"
#include "FileToArray.h"
#include "ConstantSets.h"

class NameGenerator {
    /** 
    * Tool for name generation.
    */
    name *commonMaleNames;
    name *commonFemaleNames;
    name *commonNeutralNames;
public:
    NameGenerator(rawpath commonMaleNamesPath, rawpath commonFemaleNamesPath, rawpath commonNeutralNamesPath);
    name getCommonName(gendertype gender);
};

