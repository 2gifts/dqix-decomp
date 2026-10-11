#include <globaldefs.h>
#include "System/Interrupts.h"

struct Struct0223bfa0;
extern "C" ARM int func_ov031_0223bfa0(Struct0223bfa0* p);
extern "C" ARM void func_ov031_0223d8d8(void* list, void* node);

extern char* data_ov031_02290d9c;

// USA: func_ov031_0223e22c
extern "C" ARM void* func_ov031_0223e22c(int index, int arg1, int arg2, unsigned char arg3, unsigned char arg4) {
    Struct0223bfa0* p = *(Struct0223bfa0**)(data_ov031_02290d9c + (index << 6));
    void* obj = (void*)func_ov031_0223bfa0(p);
    *(int*)((char*)obj + 0x8) = arg1;
    *(int*)((char*)obj + 0xc) = arg2;
    *(unsigned char*)((char*)obj + 0x10) = arg3;
    *(unsigned char*)((char*)obj + 0x11) = arg4;

    unsigned int state = DisableSpecificInterrupts(1);
    char* node = *(char**)(data_ov031_02290d9c + (index << 6) + 0x10);
    while (1) {
        unsigned char t = *(unsigned char*)(node + 0x10);
        if (arg3 < t) {
            func_ov031_0223d8d8(node, obj);
            break;
        }
        node = *(char**)(node + 0x4);
    }
    EnableSpecificInterrupts(state);
    return obj;
}
