#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

extern "C" void func_ov023_021dd404(void* obj);
extern "C" void func_ov023_021dd344(void* obj);
void ClearBg1Screen_021dcd78(void* p);

struct ToggleFlagAndSync_021570fcStruct {
    unsigned char pad[LOW_REGION(0x1054, 0x1258)];
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
        func_ov023_021dd404((char*)s + LOW_REGION(0x164, 0x2e4) + 0x800);
        func_ov023_021dd344((char*)s + LOW_REGION(0x164, 0x2e4) + 0x800);
    }
    if (wasSet && !flag) {
        ClearBg1Screen_021dcd78((char*)s + LOW_REGION(0x164, 0x2e4) + 0x800);
    }
    return wasSet;
}
