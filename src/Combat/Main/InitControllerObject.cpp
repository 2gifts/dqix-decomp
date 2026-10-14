#if defined(jpn)
#define CONTROLLER_STATE_OFFSET 0x4
#else
#define CONTROLLER_STATE_OFFSET 0x38
#endif
#if defined(jpn)
#define CONTROLLER_SUBOBJECT_OFFSET 0x1804
#else
#define CONTROLLER_SUBOBJECT_OFFSET 0x19e0
#endif
#include <globaldefs.h>
#include "Resource/MessageUpdate.h"
#if defined(jpn)
#define func_02043224 func_02043998
#endif
void ReinitEightSubStructsAndAllocator_0202f1dc(char*);

extern "C" void func_02043224(void* self);
extern "C" void func_02043124(void* self);

// USA: func_02043000
ARM void InitControllerObject_02043000(char* self) {
    ReinitEightSubStructsAndAllocator_0202f1dc((char*)(self + CONTROLLER_SUBOBJECT_OFFSET));
    func_02043224(self);
    MessageSystem* window = (MessageSystem*)self;
    InitCombatSlots02043040(window);
    func_02043124(self);
    ResetControllerState020430b0(window);
    *(int*)(self + CONTROLLER_STATE_OFFSET) = 0;
}
