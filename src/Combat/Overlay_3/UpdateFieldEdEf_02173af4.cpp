#include <globaldefs.h>
#if defined(jpn)
enum { kRegioned = 0xe9 };
#else
enum { kRegioned = 0xed };
#endif


struct Obj02173af4 {
    char pad0[kRegioned];
    unsigned char fed;
    unsigned char pad1;
    unsigned char fef;
};

extern "C" void* func_ov017_0218b5b0(struct Obj02173af4*);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void*, int, int);
extern "C" int _Z31IsSubBrightnessTransitionActiveP13GameResources(int* obj);

// JPN: func_ov003_02172c58
// USA: func_ov003_02173af4
ARM void UpdateFieldEdEf_02173af4(struct Obj02173af4* p) {
    void* x = func_ov017_0218b5b0(p);
    if (p->fef == 0) {
        _Z16SetSubBrightnessP13GameResourcesii(x, -16, 0x18);
        p->fef = 1;
        return;
    }
    if (p->fef != 1) return;
    if (!_Z31IsSubBrightnessTransitionActiveP13GameResources((int*)x)) {
        p->fed = 6;
        p->fef = 0;
    }
}
