#include <globaldefs.h>

extern int data_02109bf4;
extern "C" void _Z36ResetAndDispatchActorContext0209c6d8Pvs(void*, int);

// USA: func_ov025_021e8008  (semantic: Trans_021e8008)
extern "C" ARM int func_ov025_021e8008(void* self) {
    _Z36ResetAndDispatchActorContext0209c6d8Pvs(&data_02109bf4, *(int*)((char*)self + 0x8));
    return 1;
}
