#include <globaldefs.h>

struct GXOamAttr02225c90 { unsigned int attr01; unsigned short attr2; unsigned short attr3; };

struct Entity02225c90 { unsigned char pad[0x10]; GXOamAttr02225c90* field10; };

extern Entity02225c90* data_ov031_02250c00;
extern "C" void func_ov031_022266b0(int a, int b);
extern "C" void func_ov031_0223e2b8(void* obj, int v);
extern "C" void func_ov031_02225d14(void* obj);

static inline void G2_GetOBJPosition(GXOamAttr02225c90* oam, unsigned int* x, unsigned int* y) {
    *x = (oam->attr01 & 0x1ff0000) >> 16;
    *y = oam->attr01 & 0xff;
}

#pragma optimize_for_size off
// USA: func_ov031_02225c90  (semantic: CheckThreshold4cThenChain_02225c90)
extern "C" ARM void func_ov031_02225c90(void* obj) {
    Entity02225c90* e = data_ov031_02250c00;
    int x, y;
    G2_GetOBJPosition(e->field10, (unsigned int*)&x, (unsigned int*)&y);
    y -= 0xc;
    if (y > 0x4c) {
        func_ov031_022266b0(0, y);
        return;
    }
    func_ov031_022266b0(0, 0x4c);
    func_ov031_022266b0(1, 0xc0);
    func_ov031_0223e2b8(obj, (int)func_ov031_02225d14);
}
