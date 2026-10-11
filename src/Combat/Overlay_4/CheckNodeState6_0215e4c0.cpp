#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov004_0215e47c(void* a, int key);
extern "C" short func_ov023_021f6f10(void* obj);

// USA: func_ov004_0215e4c0
ARM void* CheckNodeState6_0215e4c0(void* a, int key) {
    void* node = func_ov004_0215e47c(a, key);
    if (node == NULL) return NULL;
    if (func_ov023_021f6f10(node) != 6) return NULL;
    return node;
}
