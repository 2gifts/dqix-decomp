#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Struct020dfc40;
void ResetStruct020dfc40(struct Struct020dfc40* p);
void* Zero16Bytes020df828(void* dst);
void ClearFields_021e20c0(void* p);
void InitStruct0205a444(char* obj);
struct Struct0205a198;
void Init0205a198(struct Struct0205a198* p);
void InitFields_021db0d4(void* obj, int flag);
void ClearField784Array3_021dce88(void* obj);

struct DataBlob_021dc134 {
#if defined(jpn)
    void* field14;
    void* field0;
    int field18;
    int regional7;
    int fieldc;
    int field4;
    char pad18[4];
    void* field20;
    void* field24;
    void* field8;
    void* field28;

#else
    void* field0;   // 0x0
    int field4;     // 0x4
    void* field8;   // 0x8
    int fieldc;     // 0xc
    int field10;    // 0x10
    void* field14;  // 0x14
    int field18;    // 0x18
    unsigned char pad1c[0x20 - 0x1c];
    void* field20;  // 0x20
    void* field24;  // 0x24
    void* field28;  // 0x28

#endif
};
extern struct DataBlob_021dc134 data_ov023_021ff9e0;
extern char data_ov023_021ffa0c;

struct Flags79bByte_021dc134 {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char rest : 6;
};

// JPN: func_ov023_021dca2c
// USA: func_ov023_021dc134
extern "C" ARM void func_ov023_021dc134(void* objRaw, short key, int flag) {
#if defined(jpn)
 enum {regionalOffset0=0x124, regionalOffset1=0x125, regionalOffset2=0x128, regionalOffset3=0x17c, regionalOffset4=0x62c, regionalOffset5=0x80, regionalOffset6=0x6ac, regionalOffset7=0x6b0, regionalOffset8=0x6b4, regionalOffset9=0x6d4, regionalOffset10=0x6d8, regionalOffset11=0x6dc, regionalOffset12=0x6e0, regionalOffset13=0x6e4, regionalOffset14=0x6e8, regionalOffset15=0x6ec, regionalOffset16=0x6ee, regionalOffset17=0x6f0, regionalOffset18=0x6f2, regionalOffset19=0x6f3, regionalOffset20=0x6f4, regionalOffset21=0x6f5, regionalOffset22=0x6f6, regionalOffset23=0x6f7, regionalOffset24=0x6f8, regionalOffset25=0x6f9, regionalOffset26=0x6fa, regionalOffset27=0x6fc, regionalOffset28=0x715, regionalOffset29=0x716, regionalOffset30=0x717};
#else
 enum {regionalOffset0=0x128, regionalOffset1=0x129, regionalOffset2=0x12c, regionalOffset3=0x180, regionalOffset4=0x630, regionalOffset5=0x100, regionalOffset6=0x730, regionalOffset7=0x734, regionalOffset8=0x738, regionalOffset9=0x758, regionalOffset10=0x75c, regionalOffset11=0x760, regionalOffset12=0x764, regionalOffset13=0x768, regionalOffset14=0x76c, regionalOffset15=0x770, regionalOffset16=0x772, regionalOffset17=0x774, regionalOffset18=0x776, regionalOffset19=0x777, regionalOffset20=0x778, regionalOffset21=0x779, regionalOffset22=0x77a, regionalOffset23=0x77b, regionalOffset24=0x77c, regionalOffset25=0x77d, regionalOffset26=0x77e, regionalOffset27=0x780, regionalOffset28=0x799, regionalOffset29=0x79a, regionalOffset30=0x79b};
#endif
    char* obj = (char*)objRaw;

    data_ov023_021ff9e0.field4 = 0;

    ((SafeAllocator*)(obj + 0x0))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x14))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x28))->ResetAllocatorPointer();

    *(int*)(obj + 0x3c) = 0;
    *(int*)(obj + 0x40) = 0;
    *(int*)(obj + 0x44) = 0;
    *(int*)(obj + 0x48) = 0;
    *(int*)(obj + 0x4c) = 0;
    *(int*)(obj + 0x50) = 0;
    ResetStruct020dfc40((struct Struct020dfc40*)(obj + 0x54));

    Zero16Bytes020df828(obj + 0x6c);
    Zero16Bytes020df828(obj + 0x7c);

    ResetStruct020dfc40((struct Struct020dfc40*)(obj + 0x8c));
    ResetStruct020dfc40((struct Struct020dfc40*)(obj + 0xa4));

    *(int*)(obj + 0xc4) = 0;
    *(int*)(obj + 0xc8) = 0;
    ClearFields_021e20c0(obj + 0xcc);

    *(unsigned char*)(obj + regionalOffset0) = 0;
    *(unsigned char*)(obj + regionalOffset1) = 0;
    InitStruct0205a444(obj + regionalOffset2);

    for (unsigned char i = 0; i < 30; i++) {
        Init0205a198((struct Struct0205a198*)(obj + regionalOffset3 + i * 0x28));
    }

    memset(obj + regionalOffset4, 0, regionalOffset5);

    *(int*)(obj + regionalOffset6) = 0;
    *(int*)(obj + regionalOffset7) = -1;
    for (int i = 0; i < 7; i++) {
        *(int*)(obj + regionalOffset8 + i * 4) = -1;
    }

    *(int*)(obj + regionalOffset9) = 0;
    *(int*)(obj + regionalOffset10) = 0;

    *(short*)(obj + regionalOffset15) = key;
    *(short*)(obj + regionalOffset16) = key;
    *(short*)(obj + regionalOffset17) = 0;

    *(unsigned char*)(obj + regionalOffset18) = 0;
    *(unsigned char*)(obj + regionalOffset19) = 0;
    *(unsigned char*)(obj + regionalOffset20) = 0;
    *(signed char*)(obj + regionalOffset21) = -1;
    *(signed char*)(obj + regionalOffset22) = -1;
    *(signed char*)(obj + regionalOffset29) = -1;

    ((Flags79bByte_021dc134*)(obj + regionalOffset30))->bit0 = 0;
    ((Flags79bByte_021dc134*)(obj + regionalOffset30))->bit1 = 0;

    *(signed char*)(obj + regionalOffset25) = -1;
    *(unsigned char*)(obj + regionalOffset26) = 1;
    *(int*)(obj + regionalOffset27) = -1;

    ClearField784Array3_021dce88(obj);

    *(int*)(obj + regionalOffset11) = 0;
    *(int*)(obj + regionalOffset12) = 0;
    *(unsigned char*)(obj + regionalOffset28) = 1;
    *(int*)(obj + regionalOffset13) = 0;
    *(int*)(obj + regionalOffset14) = 0;

#if defined(jpn)
    data_ov023_021ff9e0.field18 = 5;
    data_ov023_021ff9e0.regional7 = 7;
#else
    data_ov023_021ff9e0.field18 = 5;
#endif

    data_ov023_021ff9e0.fieldc = 9;
#if defined(jpn)

#else
    data_ov023_021ff9e0.field10 = 0;
#endif


    *(signed char*)(obj + regionalOffset23) = (signed char)flag;
    *(unsigned char*)(obj + regionalOffset24) = 1;

    if (flag == 1) {
        *(unsigned char*)(obj + regionalOffset24) = 0;
        *(unsigned short*)(obj + regionalOffset17) |= 0x800;
    }

    *(short*)(obj + 0xc2) = 0;
    memset(obj + 0xbc, 0, 6);

    data_ov023_021ff9e0.field14 = obj + 0x54;
    data_ov023_021ff9e0.field24 = obj + 0x6c;
    data_ov023_021ff9e0.field0 = obj + 0x7c;
    data_ov023_021ff9e0.field8 = obj + 0x8c;
    data_ov023_021ff9e0.field28 = obj + 0xa4;
    data_ov023_021ff9e0.field20 = obj;

    *(unsigned short*)(obj + regionalOffset17) |= 8;

    InitFields_021db0d4(&data_ov023_021ffa0c, 0);
}
