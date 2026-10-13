#include <globaldefs.h>
#include "Resource/MessageUpdate.h"

extern "C" void func_02043124(char* obj);

// USA: func_02043204
ARM void ReinitController02043204(char* obj) {
    MessageSystem* window = (MessageSystem*)obj;
    InitCombatSlots02043040(window);
    func_02043124(obj);
    ResetControllerState020430b0(window);
}
