#include <globaldefs.h>

extern "C" int func_02012fe4(void);
extern "C" int func_0202c508(void* state);
extern "C" void func_ov017_021d0490(int a);
extern "C" void func_ov017_021c3e18(int a);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" void func_ov017_021bd2f0(void* table, void* localBuf);

struct ArgB021d069c {
    unsigned char pad0[4];
    unsigned char byte4;
    unsigned char byte5;
    unsigned char byte6;
    unsigned char fieldA : 2;
    unsigned char gap1 : 1;
    unsigned char fieldB : 2;
    unsigned char fieldC : 1;
    unsigned char gap2 : 2;
    unsigned short half8;
    unsigned short half0xa;
    unsigned short half0xc;
    unsigned short half0xe;
    unsigned short half0x10;
    unsigned short half0x12;
};

struct LocalBuf021d069c {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned short f4;
    unsigned short f6;
    unsigned char f8;
    unsigned char pad9;
    unsigned short fa;
    unsigned short fc;
    unsigned short fe;
    unsigned short f10;
};

// JPN: func_ov017_021d0b4c
// USA: func_ov017_021d069c
extern "C" ARM void func_ov017_021d069c(int a0, struct ArgB021d069c* a1, int unused2, unsigned char* a3, struct SearchStruct0202c1a4* a4) {
#if defined(jpn)
 enum {regionalOffset=0x524};
#else
 enum {regionalOffset=0x734};
#endif
    func_02012fe4();
    unsigned char* table = *(unsigned char**)((char*)a3 + 0x3000 + regionalOffset);
    if (func_0202c508(a4)) {
        func_ov017_021d0490(a0);
        func_ov017_021c3e18(1);
        return;
    }
    if (a0 != 0) {
        return;
    }
    if (GetSearchStructCurrentArrEntry(a4) != a1->fieldA) {
        return;
    }

    struct LocalBuf021d069c buf;
    unsigned char fieldBVal = a1->fieldB;
    buf.f0 = fieldBVal;
    buf.f1 = a1->byte4;
    buf.f2 = a1->byte5;
    buf.f3 = a1->byte6;
    buf.f4 = a1->half8;
    buf.f6 = a1->half0xa;
    buf.f8 = a1->fieldC;

    fieldBVal = fieldBVal & 0xff;
    if (fieldBVal == 0) {
        buf.fa = (unsigned short)*(short*)((char*)a1 + 0xc);
        buf.fc = a1->half0xe;
    } else if (fieldBVal == 1) {
        buf.fa = a1->half0xc;
        buf.fc = a1->half0xe;
        buf.fe = a1->half0x10;
        buf.f10 = a1->half0x12;
    }

    func_ov017_021bd2f0(table, &buf);
}
