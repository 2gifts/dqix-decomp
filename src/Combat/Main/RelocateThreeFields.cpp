#include <globaldefs.h>
#include "Resource/MonsterDefinition.h"

// USA: func_0206ef48
ARM int RelocateThreeFields(List0206f170* table, MonsterDefinition* definition) {
    definition->name = reinterpret_cast<char*>(func_0206ef94(reinterpret_cast<Struct0206ef94*>(table), definition->name, 0));
#if !defined(jpn)
    definition->localizedText = reinterpret_cast<char*>(func_0206ef94(reinterpret_cast<Struct0206ef94*>(table), definition->localizedText, 0));
#endif
    definition->modelName = reinterpret_cast<char*>(func_0206ef94(reinterpret_cast<Struct0206ef94*>(table), definition->modelName, 0));
    return 1;
}
