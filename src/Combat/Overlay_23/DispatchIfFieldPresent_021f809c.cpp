#include <globaldefs.h>

int CheckField0x9cSetWhenField0xd4Present(unsigned char* obj);
extern "C" void func_ov023_021f7eb8(void* obj, void* param2, int zero, int shortCC,
    int shortCE, int shortC8, int shortCA, unsigned char byteE2, int flagBit2, int flagBit4);

struct Obj021f809c {
    char pad1[0xc8];
    short f_c8;
    short f_ca;
    short f_cc;
    short f_ce;
    char pad2[0x12];
    unsigned short f_e2;
    char pad3;
    unsigned char f_e5;
};

// USA: func_ov023_021f809c  (semantic: DispatchIfFieldPresent_021f809c)
extern "C" ARM void func_ov023_021f809c(struct Obj021f809c* obj, void* param2) {
    if (CheckField0x9cSetWhenField0xd4Present((unsigned char*)obj + 0x20)) {
        unsigned char e5 = obj->f_e5;
        unsigned short e2 = obj->f_e2;
        int flagBit2 = (e5 & 4) ? 1 : 0;
        int flagBit4 = (e5 & 0x10) ? 1 : 0;
        short ce = obj->f_ce;
        unsigned char byteE2 = (unsigned char)e2;
        short c8 = obj->f_c8;
        short ca = obj->f_ca;
        short cc = obj->f_cc;
        func_ov023_021f7eb8(obj, param2, 0, cc, ce, c8, ca, byteE2, flagBit2, flagBit4);
    }
}
