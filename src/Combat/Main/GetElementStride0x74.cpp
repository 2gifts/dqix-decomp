#include <globaldefs.h>
#include "World/ZoneFeatures.h"

// USA: func_0201e664
ARM ZoneFeatures::Opcode6aEntry* GetElementStride0x74_0201e664(ZoneFeatures* features, int index) {
    if (index < 0 || features->arraySize6a_ <= index) return NULL;
    return &features->entries6a_[index];
}
