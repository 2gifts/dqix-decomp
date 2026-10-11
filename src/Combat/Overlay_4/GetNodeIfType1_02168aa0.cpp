#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" unsigned int func_ov023_021f6f10(void* self);

// USA: func_ov004_02168aa0
ARM void* GetNodeIfType1_02168aa0(void* a, int id) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), id);
    if (node) {
        if (func_ov023_021f6f10(node) == 1) return node;
    }
    return NULL;
}
