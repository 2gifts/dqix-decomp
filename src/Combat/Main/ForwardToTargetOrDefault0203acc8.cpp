#include <globaldefs.h>

void* SetGlobalContext02110370(void* value);
void* CallFunc020bc548OnField0(void* obj, int arg);

// USA: func_0203acc8
ARM void ForwardToTargetOrDefault0203acc8(void* obj, void* target, int arg) {
    if (*(int*)obj == 0) return;
    SetGlobalContext02110370((char*)obj + 4);
    if (target != NULL) {
        CallFunc020bc548OnField0(target, arg);
    } else {
        CallFunc020bc548OnField0((char*)obj + 0x98, arg);
    }
}
