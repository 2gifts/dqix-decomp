#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"

struct Variant02030b0c;

// USA: func_0201f844
ARM int StoreDecodedIntAt0x14(Variant02030b0c* arg) {
    const Script::Parameter* parameters = reinterpret_cast<const Script::Parameter*>(arg);
    int v = parameters[0].ToInt();
    *(int*)(data_020fdc4c.currentObject + 0x14) = v;
    return 1;
}
