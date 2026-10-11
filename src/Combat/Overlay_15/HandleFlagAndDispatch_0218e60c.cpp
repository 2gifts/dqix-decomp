#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
void ForwardField4To02057334(int* obj);
extern "C" void _ZN8Object3D14AdvanceEffectsEv(void*);

extern unsigned short data_02114e30;

struct SubP_0218e60c {
    char pad0xc[0xc];
    int field0xc;
};

struct S0218e60c {
    char pad0x24[0x24];
    void* field0x24;
    struct SubP_0218e60c* field0x28;
    char pad0x3a[0xe];
    unsigned char field0x3a;
};

// USA: func_ov015_0218e60c
ARM void HandleFlagAndDispatch_0218e60c(struct S0218e60c* obj) {
    int ok = 0;
    if (obj->field0x3a != 0) {
        if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x100) != 0) {
            ok = 1;
        }
    } else {
        ok = 1;
    }
    if (ok == 0) {
        return;
    }
    struct SubP_0218e60c* p = obj->field0x28;
    if (p->field0xc != 0) {
        ForwardField4To02057334((int*)p);
    } else {
        _ZN8Object3D14AdvanceEffectsEv(obj->field0x24);
    }
}
