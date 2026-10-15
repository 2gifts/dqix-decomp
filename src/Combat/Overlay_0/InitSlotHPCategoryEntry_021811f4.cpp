#include <globaldefs.h>

int GetHPCategory02174e34(int a, int b);
extern "C" void func_0205ac40(void* dst, void* src);

struct Entry021811f4 {
    char pad0[0x14];
    int field14;
    int field18;
    char pad1[0x6];
    unsigned char field22;
    char pad2[0x2];
    unsigned char field25;
    unsigned char field26;
};

// USA: func_ov000_021811f4
ARM void InitSlotHPCategoryEntry_021811f4(void* obj, int idx, short a2, int a3, short, short) {
    struct Entry021811f4* base = *(struct Entry021811f4**)((char*)obj + 0x170);
    struct Entry021811f4* e = base + (idx + 0x24);
    e->field14 = a2 << 0xc;
    e->field18 = a3 << 0xc;
    e->field22 = (unsigned char)(idx + 0x48);
    e->field26 = 1;
    e->field25 = (unsigned char)GetHPCategory02174e34((int)obj, (signed char)idx);
    func_0205ac40((char*)obj + 0x11c, e);
}
