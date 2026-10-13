#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"

#include "std_library_functions.h"

struct Struct02030b7c;

// USA: func_0201f634
ARM int CopyStringToBuffer0201f634(Struct02030b7c* s) {
    const Script::Parameter* parameters = reinterpret_cast<const Script::Parameter*>(s);
    strcpy(data_020fdc4c.currentObject + 0x548, parameters[0].ToString());
    return 1;
}
