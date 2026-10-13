#include <globaldefs.h>
#include "Resource/MonsterDefinition.h"

// USA: func_0206ef40
ARM int GetShortAt0x8(void* entry) {
    return static_cast<MonsterDefinition*>(entry)->monsterId;
}
