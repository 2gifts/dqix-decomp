#include <globaldefs.h>
#include "Resource/GameResources.h"

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern unsigned short data_02114e30;

struct FlagPair_021b2698 { int a; int b; };
extern FlagPair_021b2698 data_ov017_021d83f0;
extern "C" int func_ov011_02184694(int a);
extern "C" int func_0202ae18(void);
extern "C" int func_0202c540(void);
extern "C" int func_ov017_0219bddc(unsigned char* p);
int* GetGlobal02109030(void);
extern "C" void func_02094030(int*, int, int, int);

struct SelfState_021b2698 {
    unsigned char pad0[0x8];
    int field8;
    unsigned char pad1[0x2c];
    int field0x38;
    unsigned char pad2[0xc];
    unsigned char field0x48;
};

// USA: func_ov017_021b2698  (semantic: CheckStateAndDispatchGlobal_021b2698)
extern "C" ARM int func_ov017_021b2698(SelfState_021b2698* self) {
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x2000) != 0) {
        return 3;
    }
    if (func_ov011_02184694(data_ov017_021d83f0.b) != 0) {
        return self->field8;
    }
    GameResources* ov = func_ov017_0218b5b0();
    #if defined(jpn)
    void* p = *(void**)((char*)ov + 0x3000 + 0x91c);
#else
    void* p = *(void**)((char*)ov + 0x3000 + 0xb3c);
#endif
    if (((unsigned char*)p)[2] != 0) {
        goto fail;
    }
    func_0202ae18();
    if (func_0202c540() == 0) {
        goto fail;
    }
    unsigned char local = 0;
    if (func_ov017_0219bddc(&local) == 0) {
        goto fail;
    }
    self->field0x38 = (self->field0x38 & ~1) | 1;
    self->field0x48 = 1;
    int* g = GetGlobal02109030();
    func_02094030(g, 0x4e23, -1, 0);
fail:
    return 3;
}
