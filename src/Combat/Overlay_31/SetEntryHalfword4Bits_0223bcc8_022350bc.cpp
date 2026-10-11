#include <globaldefs.h>

extern "C" void* func_ov031_0223cf4c(int size, int align);

struct TwoShorts0223cb10 { unsigned short a; unsigned short b; };
extern "C" void func_ov031_0223cb10(unsigned short a, unsigned short b, TwoShorts0223cb10* out);

extern "C" int func_ov031_0223be70(int, int, int);
extern unsigned char data_ov031_022491f0[];

extern "C" void func_ov031_0223bbd8(void*, int, int, int);

struct Obj0223bcc8;
ARM void SetEntryHalfword4Bits_0223bcc8(Obj0223bcc8*, int, int);

ARM void* CallWithZeroExtra_0223e218(void* a, void* b, void* c, int d);
extern "C" void func_ov031_02235234(void);

struct Alloc022350bc {
    int field0;
    unsigned char pad0[0xc - 0x4];
    int fieldc;
    unsigned char pad1[0x19 - 0x10];
    unsigned char field19;
    unsigned char field1a;
    unsigned char field1b;
};
extern Alloc022350bc* data_ov031_02290cf4;

// USA: func_ov031_022350bc  (semantic: AllocAndInitEntry_022350bc)
extern "C" ARM void func_ov031_022350bc(int a, int b, unsigned short c, unsigned short d, int e) {
    data_ov031_02290cf4 = (Alloc022350bc*)func_ov031_0223cf4c(0x20, 4);
    data_ov031_02290cf4->field1b = (unsigned char)a;
    data_ov031_02290cf4->field19 = (unsigned char)b;
    data_ov031_02290cf4->field1a = (unsigned char)e;
    func_ov031_0223cb10((unsigned short)c, (unsigned short)d, (TwoShorts0223cb10*)((char*)data_ov031_02290cf4 + 0x10));
    data_ov031_02290cf4->field0 = func_ov031_0223be70(0, data_ov031_022491f0[a], 1);
    func_ov031_0223bbd8((void*)data_ov031_02290cf4->field0, -1, c, d + e);
    SetEntryHalfword4Bits_0223bcc8((Obj0223bcc8*)data_ov031_02290cf4->field0, -1, 1);
    data_ov031_02290cf4->fieldc = (int)CallWithZeroExtra_0223e218(0, (void*)func_ov031_02235234, 0, 0x80);
}
