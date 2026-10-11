#if defined(jpn)
enum {regionalOffset0=0x600, regionalOffset1=0xf0, regionalOffset2=0x717, regionalOffset3=0x204, regionalOffset4=0x128};
#else
enum {regionalOffset0=0x700, regionalOffset1=0x74, regionalOffset2=0x79b, regionalOffset3=0x208, regionalOffset4=0x12c};
#endif
#include <globaldefs.h>

extern "C" void func_0205ac40(void* a, void* b, void* c, int d);

struct Bits79b021dd404 {
    unsigned char bit0:1;
    unsigned char bit1:1;
    unsigned char rest:6;
};

struct Sub700_021dd404 {
    char pad0[regionalOffset1];
    unsigned short flags74;
    char pad1[0x7b - 0x76];
    signed char mode7b;
    char pad2[0x7d - 0x7c];
    signed char mode7d;
};

// JPN: func_ov023_021ddbf4
// USA: func_ov023_021dd404  (semantic: ApplyModeSetupAndDispatch_021dd404)
extern "C" ARM void func_ov023_021dd404(char* obj) {
    if (((Sub700_021dd404*)(obj + regionalOffset0))->mode7b == 1) {
        if (!((Bits79b021dd404*)(obj + regionalOffset2))->bit1) return;
        Sub700_021dd404* s = (Sub700_021dd404*)(obj + regionalOffset0);
        if (!(s->flags74 & 0x2000)) return;
    }
    signed char mode = ((Sub700_021dd404*)(obj + regionalOffset0))->mode7d;
    if (mode == 1) {
        Sub700_021dd404* s2 = (Sub700_021dd404*)(obj + regionalOffset0);
        if (!(s2->flags74 & 0x800)) return;
        char* g = obj + regionalOffset3;
        *(unsigned char*)(g + 0x426) = 1;
        *(unsigned int*)(g + 0x414) = 0x10000;
        *(unsigned int*)(g + 0x418) = 0x68000;
        *(unsigned char*)(g + 0x422) = 0x58;
        func_0205ac40(obj + regionalOffset4, g + 0x400, g, 0x58);
        return;
    }
    if (mode == 2) {
        Sub700_021dd404* s2 = (Sub700_021dd404*)(obj + regionalOffset0);
        if (!(s2->flags74 & 0x800)) return;
        char* g = obj + regionalOffset3;
        *(unsigned char*)(g + 0x426) = 2;
        *(unsigned int*)(g + 0x414) = 0x10000;
        *(unsigned int*)(g + 0x418) = 0x68000;
        *(unsigned char*)(g + 0x422) = 0x58;
        func_0205ac40(obj + regionalOffset4, g + 0x400, g, 0x58);
        return;
    }
}
