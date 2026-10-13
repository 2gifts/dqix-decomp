#include <globaldefs.h>

extern "C" void func_ov012_02185a24(void* p);

// USA: func_ov017_021c19f8
ARM void CallIfField20_021c19f8(void* obj) {
    void* p = *(void**)((char*)obj + 0x20);
    if (p) func_ov012_02185a24(p);
}
