#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov001_02158dcc(void*);

// USA: func_ov001_021590c4
ARM void* EnqueueEventType9_021590c4(void* ctx) {
    void* node = func_ov001_02158dcc(ctx);
    if (node != NULL) *(int*)node = 9;
    return node;
}
