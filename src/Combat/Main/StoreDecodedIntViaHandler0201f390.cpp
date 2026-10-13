#include <globaldefs.h>
#include "Resource/Script.h"
#include "Combat/CombatScriptContext.h"

struct Variant02030b0c;
extern "C" void func_02027b10(void* obj, int value);

// USA: func_0201f390
ARM int StoreDecodedIntViaHandler0201f390(Variant02030b0c* arg) {
    const Script::Parameter* parameters = reinterpret_cast<const Script::Parameter*>(arg);
    int value = parameters[0].ToInt();
    func_02027b10(data_020fdc4c.currentObject, value);
    return 1;
}
