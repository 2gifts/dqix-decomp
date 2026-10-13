#include <globaldefs.h>
#include "Resource/MonsterDefinition.h"

// USA: func_0206f0f8
ARM int GetEntryArrayByteSize(Header0206f0f8* header) {
    return header->count * sizeof(MonsterDefinition);
}
