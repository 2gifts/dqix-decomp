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
#if defined(jpn)
extern "C" void func_020437b4(char*);
extern "C" void func_02043824(char*);
#define InitCombatSlots02043040 func_020437b4
#define ResetControllerState020430b0 func_02043824
#define func_02043224 func_02043998
#else
void InitCombatSlots02043040(char*);
#endif
void ReinitEightSubStructsAndAllocator(char*);

extern "C" void func_02043224(void* self);
extern "C" void func_02043124(void* self);
#if !defined(jpn)
void ResetControllerState020430b0(char* self);
#endif

// JPN: func_02043774
// USA: func_02043000
ARM void InitControllerObject(char* self) {
    ReinitEightSubStructsAndAllocator((char*)(self + CONTROLLER_SUBOBJECT_OFFSET));
    func_02043224(self);
    InitCombatSlots02043040((char*)(self));
    func_02043124(self);
    ResetControllerState020430b0(self);
    *(int*)(self + CONTROLLER_STATE_OFFSET) = 0;
}
