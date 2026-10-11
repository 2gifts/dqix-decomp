#include <globaldefs.h>
#if defined(jpn)
extern "C" void func_020437b4(char*);
#define InitCombatSlots02043040 func_020437b4
#else
void InitCombatSlots02043040(char*);
#endif

extern "C" void func_02043124(char* obj);
#if defined(jpn)
extern "C" void func_02043824(char*);
#define ResetControllerState020430b0 func_02043824
#else
ARM void ResetControllerState020430b0(char* self);
#endif

// USA: func_02043204
ARM void ReinitController02043204(char* obj) {
    InitCombatSlots02043040((char*)(obj));
    func_02043124(obj);
    ResetControllerState020430b0(obj);
}
