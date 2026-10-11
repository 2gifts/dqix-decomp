#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_ov001_02159f94(void*);

// USA: func_ov001_0215a594
ARM void EnqueueEventType11_0215a594(void* ctx, char* str, int b, int c) {
    void* node = func_ov001_02159f94(ctx);
    if (node != NULL) {
        *(int*)node = 11;
        strcpy((char*)node + 0x1c, str);
        *(int*)((char*)node + 0x10) = b;
        *(int*)((char*)node + 0x14) = c;
        *(int*)((char*)node + 0x18) = 0;
    }
}
