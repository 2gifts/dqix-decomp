#include <globaldefs.h>

extern int data_02109bf4;
void ResetAndDispatchActorContext0209c6d8(void*, int);

// USA: func_ov025_021e8008  (semantic: Trans_021e8008)
extern "C" ARM int func_ov025_021e8008(void* self) {
    ResetAndDispatchActorContext0209c6d8(&data_02109bf4, *(int*)((char*)self + 0x8));
    return 1;
}
