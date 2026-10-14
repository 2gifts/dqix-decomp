#include <globaldefs.h>
#include "Resource/MonsterDefinition.h"

// USA: func_0206f110
ARM int InvokeCallbackForEachEntry_0206f110(List0206f170* table, MonsterDefinitionVisitor visit) {
    int count;
    MonsterDefinition* definition = table->table.arr;
    int index;
    if (definition == NULL || (count = table->table.header.count) == 0 || visit == NULL) {
        return 0;
    }
    for (index = 0; index < count; index++, definition++) {
        visit(table, definition);
    }
    return 1;
}
