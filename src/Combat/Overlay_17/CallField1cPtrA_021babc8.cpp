#include <globaldefs.h>

extern "C" void func_ov003_02159078(void*);

// USA: func_ov017_021babc8
ARM void CallField1cPtrA_021babc8(void* obj) {
    void* p = *(void**)((char*)obj + 0x1c);
    if (p) func_ov003_02159078(p);
}
