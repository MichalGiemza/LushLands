#pragma once
#include "DataTypes.h"
#include "ConstantSets.h"

class EntityContainer {
    /**
    * Base for entity data, flags, etc.
    * Meant to be accessible from every entity module and higher classes.
    * Functionalities and constructors not allowed, protected fields and public getters only.
    */
protected:
    updatetype updateType = no_update;
public:
    updatetype getUpdateType() { return updateType; }
};
