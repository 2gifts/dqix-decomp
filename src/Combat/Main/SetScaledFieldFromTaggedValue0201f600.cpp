#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"

#if defined(jpn)
#define SetScaledFieldFromTaggedValue0201f600 func_0201f38c
#endif

struct TaggedValue02030b44;

#if defined(jpn)
extern "C" int func_0201f38c(struct TaggedValue02030b44* v);
#endif

// USA: func_0201f600
ARM int SetScaledFieldFromTaggedValue0201f600(struct TaggedValue02030b44* v) {
    const Script::Parameter* parameters = reinterpret_cast<const Script::Parameter*>(v);
    float scaled = 4096.0f * parameters[0].ToFloat();
    *(int*)(data_020fdc4c.currentObject + 0x38) = (int)scaled;
    return 1;
}
