#include <globaldefs.h>

extern "C" int func_ov000_02171bc0(void*);

#if defined(jpn)
enum { pointerArrayOffset = 0x430, countOffset = 0xc6 };
#else
enum { pointerArrayOffset = 0x3f0, countOffset = 0x86 };
#endif

// USA: func_ov000_02171b68
// JPN: func_ov000_02173414
ARM void SetPointerField0x3f002171b68(void* obj, int idx, void* val) {
    if (idx < 0) return;
    if (idx >= 0x10) return;
    if (val == 0) return;
    *(void**)((char*)obj + idx * 4 + pointerArrayOffset) = val;
    *(unsigned char*)((char*)obj + countOffset) = (unsigned char)func_ov000_02171bc0(obj);
}
