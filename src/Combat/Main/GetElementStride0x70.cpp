#include <globaldefs.h>
#include "World/ZoneFeatures.h"

// USA: func_0201e548
ARM void* GetElementStride0x70_0201e548(ZoneFeatures* features, int index) {
    if (index < 0 || features->arraySize68_ <= index) {
        return NULL;
    }
    return &features->entries68_[index];
}
