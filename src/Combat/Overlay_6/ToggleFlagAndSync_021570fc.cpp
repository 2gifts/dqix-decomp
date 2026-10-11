#include <globaldefs.h>

#if defined(jpn)
#define func_ov006_021570fc func_ov006_02158704
#endif

extern "C" void func_ov023_021dd404(void* obj);
extern "C" void func_ov023_021dd344(void* obj);
extern "C" void _Z23ClearBg1Screen_021dcd78v(void* p);

struct ToggleFlagAndSync_021570fcStruct {
    unsigned char pad[0x1258];
    unsigned short flags;
};

// USA: func_ov006_021570fc  (semantic: ToggleFlagAndSync_021570fc)
extern "C" ARM int func_ov006_021570fc(struct ToggleFlagAndSync_021570fcStruct* s, int flag) {
    int wasSet = (s->flags & 0x800) != 0;
    if (flag) {
        s->flags |= 0x800;
    } else {
        s->flags &= ~0x800;
    }
    if (!wasSet && flag) {
        func_ov023_021dd404((char*)s + 0x2e4 + 0x800);
        func_ov023_021dd344((char*)s + 0x2e4 + 0x800);
    }
    if (wasSet && !flag) {
        _Z23ClearBg1Screen_021dcd78v((char*)s + 0x2e4 + 0x800);
    }
    return wasSet;
}
