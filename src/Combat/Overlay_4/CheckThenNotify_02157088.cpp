#include <globaldefs.h>

extern "C" void* func_ov004_02157054(void* object, int key);
extern "C" void* func_ov023_021fbdec(void* node);

// USA: func_ov004_02157088
ARM void* CheckThenNotify_02157088(void* object, int key) {
    void* node = func_ov004_02157054(object, key);
    if (!node) return NULL;
    return func_ov023_021fbdec(node);
}
