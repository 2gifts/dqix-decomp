#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"

struct Variant02030b0c;

// USA: func_0201f4cc
ARM int StoreTwoDecodedIntsAt0x18_0201f4cc(Variant02030b0c* args) {
    const Script::Parameter* parameters = reinterpret_cast<const Script::Parameter*>(args);
    int v1 = parameters[0].ToInt();
    int v2 = parameters[1].ToInt();
    char* obj = data_020fdc4c.currentObject;
    *(int*)(obj + 0x18) = v1;
    *(int*)(obj + 0x1c) = v2;
    return 1;
}
