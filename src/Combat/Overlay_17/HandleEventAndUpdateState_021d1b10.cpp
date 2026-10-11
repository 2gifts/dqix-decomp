// JPN: func_ov017_021d1f94
#if defined(jpn)
enum { RegionOffset70c = 0x4fc, RegionOffset734 = 0x524, RegionOffset2774 = 0x27b4 };
#else
enum { RegionOffset70c = 0x70c, RegionOffset734 = 0x734, RegionOffset2774 = 0x2774 };
#endif

#include <globaldefs.h>

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" void* func_02012fe4(void);
extern "C" void func_020a72ac(void* base, int val);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

union Field6_021d1b10 {
    signed short raw;
    struct { signed short main : 14; signed short sub : 2; } bits;
};

struct Src021d1b10 {
    unsigned char pad0[4];
    signed short field4;
    union Field6_021d1b10 field6;
    unsigned short field8;
    unsigned short fielda;
    unsigned short fieldc;
    signed short fielde;
    unsigned char field10;
};

struct PendingEvent021d1b10 {
    unsigned char pad0;
    unsigned char field1;
    unsigned char pad2;
    unsigned char field3;
    unsigned char pad4[0xe];
    short field12;
    short field14;
    unsigned short field16;
    unsigned short field18;
    unsigned short field1a;
    short field1c;
    unsigned char field1e;
};

struct LiveState_021d1b10 {
    unsigned char pad0[RegionOffset2774];
    int vec[3];
    int field2780;
    short field2784;
    short field2786;
    unsigned char field2788;
};

// USA: func_ov017_021d1b10  (semantic: HandleEventAndUpdateState_021d1b10)
extern "C" ARM void func_ov017_021d1b10(int unused0, Src021d1b10* b, int unused2, unsigned char* ov, struct SearchStruct0202c1a4* search) {
    if (GetSearchStructCurrentArrEntry(search) == 0) return;

    LiveState_021d1b10* live = (LiveState_021d1b10*)func_02012fe4();
    PendingEvent021d1b10* obj1 = *(PendingEvent021d1b10**)(ov + 0x3000 + RegionOffset70c);
    unsigned char* obj2 = *(unsigned char**)(ov + 0x3000 + RegionOffset734);

    if (obj1->field3 != 0 && obj1->field1 != 1) {
        obj1->field12 = b->field4;
        obj1->field14 = b->field6.raw;
        obj1->field16 = b->field8;
        obj1->field18 = b->fielda;
        obj1->field1a = b->fieldc;
        obj1->field1c = b->fielde;
        obj1->field1e = b->field10;
    } else {
        live->field2786 = b->field4;
        short mainVal = b->field6.bits.main;
        if (mainVal != -1) live->field2784 = mainVal;
        live->field2788 = (unsigned char)b->field6.bits.sub;
        int vecsrc[3] = { (short)b->field8 << 7, (short)b->fielda << 7, (short)b->fieldc << 7 };
        _ZN8Vector3iaSERKS_(live->vec, vecsrc);
        live->field2780 = b->fielde;
        if (obj2[3] == 0) {
            func_020a72ac(live, b->field10);
        }
    }
}
