#include <globaldefs.h>

#include "Resource/MonsterDefinition.h"

// USA: func_0206ef94
extern "C" ARM char* func_0206ef94(List0206f170* table, char* relativeAddress, char* fallback) {
    int missing = 1;
    int offset = relativeAddress - (char*)0;
    if (offset != -1) {
        if (table->strings != 0) {
            missing = 0;
        }
    }
    if (!missing) {
        return table->strings + offset;
    }
    return fallback;
}
