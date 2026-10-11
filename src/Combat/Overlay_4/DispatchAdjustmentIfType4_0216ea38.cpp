#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" unsigned int func_ov023_021f6f10(void* self);
extern "C" int func_ov023_021fa598(void*);

// USA: func_ov004_0216ea38  (semantic: DispatchAdjustmentIfType4_0216ea38)
extern "C" ARM int func_ov004_0216ea38(void* a, int key) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), key);
    if (!node) goto ret0;
    if (func_ov023_021f6f10(node) != 0x4) goto ret0;
    return func_ov023_021fa598(node);
ret0:
    return 0;
}
