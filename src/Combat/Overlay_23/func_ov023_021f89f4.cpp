#include <globaldefs.h>

struct ObjBase021f6ed8;
extern "C" ARM void func_ov023_021f6ed8(struct ObjBase021f6ed8* obj);

struct Nibbles44_021f89f4 { unsigned char lo : 4; unsigned char hi : 4; };
#if defined(jpn)
struct Flags45_021f89f4 { unsigned char bit0 : 1; unsigned char mid : 7; };
#else
struct Flags45_021f89f4 { unsigned char bit0 : 1; unsigned char mid : 6; unsigned char bit7 : 1; };
#endif


// JPN: func_ov023_021f7e8c
// USA: func_ov023_021f89f4
extern "C" ARM int func_ov023_021f89f4(char* obj, int unused, int arg2, int arg3, int pA, int pB, int pC, int pD, int pE, int pF, int pG) {
    func_ov023_021f6ed8((struct ObjBase021f6ed8*)obj);
    *(short*)(obj + 0x4) = 8;
    *(short*)(obj + 0x6) = arg2;
    *(short*)(obj + 0x8) = arg3;
    *(short*)(obj + 0xa) = 0;
    *(int*)(obj + 0x10) = 0;
    *(int*)(obj + 0x1c) = 2;

    struct Flags45_021f89f4* flags45 = (struct Flags45_021f89f4*)(obj + 0x45);
    flags45->mid = 0;
    *(short*)(obj + 0x42) = 0;
#if defined(jpn)

#else
    flags45->bit7 = 0;
#endif

    *(int*)(obj + 0x20) = 0;
    *(int*)(obj + 0x24) = -0x10000;
    *(int*)(obj + 0x28) = -0x3000;
    *(int*)(obj + 0x2c) = 0;
    *(short*)(obj + 0x30) = 0;
    *(short*)(obj + 0x32) = 0;
    *(short*)(obj + 0x34) = pA;
    *(short*)(obj + 0x36) = pB;
    *(short*)(obj + 0x38) = pC;
    *(short*)(obj + 0x3a) = pD;
    *(short*)(obj + 0x3c) = pE;

    struct Nibbles44_021f89f4* nibbles44 = (struct Nibbles44_021f89f4*)(obj + 0x44);
    nibbles44->lo = (unsigned char)pF;
    nibbles44->hi = (unsigned char)pG;

    flags45->bit0 = 0;
    *(short*)(obj + 0x46) = 0;
    *(short*)(obj + 0x48) = 0;
    *(short*)(obj + 0x4a) = 0;
    *(short*)(obj + 0x4c) = 0;
    return 1;
}
