#include <globaldefs.h>

#if defined(jpn)
#define func_ov008_02184968 func_ov008_02185a64
#endif
extern "C" void func_ov008_02184968(void* p);

// USA: func_ov017_021c1220
ARM void CallIfField1c_021c1220(void* obj) {
    void* p = *(void**)((char*)obj + 0x1c);
    if (p) func_ov008_02184968(p);
}
