#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov001_02159f94(void*);

// USA: func_ov001_0215a530
ARM void* EnqueueEventType9_0215a530(void* ctx, int a) {
    void* node = func_ov001_02159f94(ctx);
    if (node != NULL) {
        *(int*)node = 9;
        *(int*)((char*)node + 0x10) = a;
    }
    return node;
}
