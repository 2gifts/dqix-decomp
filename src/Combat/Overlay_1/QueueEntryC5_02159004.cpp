#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_ov001_02158dcc(void** ctx);

// USA: func_ov001_02159004  (semantic: QueueEntryC5_02159004)
extern "C" ARM void func_ov001_02159004(void** ctx, int a1, int a2, int a3, int a4) {
    unsigned int* entry = (unsigned int*)func_ov001_02158dcc(ctx);
    if (entry != 0) {
        entry[0] = 5;
        memcpy((char*)entry + 0x4, &a1, 0xc);
        entry[7] = a4;
    }
}
