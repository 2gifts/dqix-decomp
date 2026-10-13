#include <globaldefs.h>
#include "Resource/MonsterDefinition.h"

// USA: func_0206ef48
// KEEP-NAME
ARM int RelocateThreeFields(List0206f170* table, MonsterDefinition* definition) {
    definition->name = func_0206ef94(table, definition->name, 0);
#if !defined(jpn)
    definition->localizedText = func_0206ef94(table, definition->localizedText, 0);
#endif
    definition->modelName = func_0206ef94(table, definition->modelName, 0);
    return 1;
}
