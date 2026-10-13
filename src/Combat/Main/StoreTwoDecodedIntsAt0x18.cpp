#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"

#if defined(jpn)
#define StoreTwoDecodedIntsAt0x18 func_0201f258
#endif

struct Variant02030b0c;

#if defined(jpn)
extern "C" ARM int func_0201f258(Variant02030b0c* args);
#endif

// USA: func_0201f4cc
ARM int StoreTwoDecodedIntsAt0x18(Variant02030b0c* args) {
    const Script::Parameter* parameters = reinterpret_cast<const Script::Parameter*>(args);
    int v1 = parameters[0].ToInt();
    int v2 = parameters[1].ToInt();
    char* obj = data_020fdc4c.currentObject;
    *(int*)(obj + 0x18) = v1;
    *(int*)(obj + 0x1c) = v2;
    return 1;
}
