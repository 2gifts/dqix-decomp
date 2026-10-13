#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_02185ab8 func_ov012_02186118
#endif


extern "C" void func_ov012_02185ab8(void* p);

// USA: func_ov017_021c19e0
ARM void CallIfField20_021c19e0(void* obj) {
    void* p = *(void**)((char*)obj + 0x20);
    if (p) func_ov012_02185ab8(p);
}
