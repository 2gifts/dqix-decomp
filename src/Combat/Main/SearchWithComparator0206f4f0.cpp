#include <globaldefs.h>
#include "Resource/MonsterDefinition.h"

// USA: func_0206f4f0
ARM void* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct* table, int monsterId) {
    return BinarySearchByComparator(table, monsterId, GetShortAt0x8);
}
