#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"

struct TaggedValue02030b44;

// USA: func_0201f600
ARM int SetScaledFieldFromTaggedValue0201f600(struct TaggedValue02030b44* v) {
    const Script::Parameter* parameters = reinterpret_cast<const Script::Parameter*>(v);
    float scaled = 4096.0f * parameters[0].ToFloat();
    *(int*)(data_020fdc4c.currentObject + 0x38) = (int)scaled;
    return 1;
}
