#include <globaldefs.h>

extern "C" void* func_020bc548(void* p);

// USA: func_020bc018
ARM void* CallFunc020bc548OnField0_020bc018(void* obj, int) {
    return func_020bc548(*(void**)obj);
}
