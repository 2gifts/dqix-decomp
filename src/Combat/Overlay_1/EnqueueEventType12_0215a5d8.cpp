#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov001_02159f94(void*);

// USA: func_ov001_0215a5d8
ARM void* EnqueueEventType12_0215a5d8(void* ctx) {
    void* node = func_ov001_02159f94(ctx);
    if (node != NULL) *(int*)node = 12;
    return node;
}
