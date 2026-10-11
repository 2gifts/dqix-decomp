#include <globaldefs.h>

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

extern "C" int func_0202c508(struct SearchStruct0202c1a4* list);
extern "C" int func_ov017_021a23e4(char* c, int a0, unsigned int f8, unsigned int fc);

void EnqueueEventTag139_021d09cc(int a, int b, int c, int d);

struct EntryStruct021d0a18 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned char field6;
    unsigned char pad7;
    unsigned int field8;
    unsigned int fieldc;
};

struct Target021d0a18 {
    unsigned char pad0[0x10];
    unsigned char byte10;
    unsigned char pad11;
    unsigned short half12;
};

// JPN: func_ov017_021d0ec8
// USA: func_ov017_021d0a18
ARM void HandleEntryEvent_021d0a18(int a0, struct EntryStruct021d0a18* b, int unused, char* c, struct SearchStruct0202c1a4* list) {
#if defined(jpn)
 enum {regionalOffset0=0x98c};
#else
 enum {regionalOffset0=0xbac};
#endif
    if (func_0202c508(list) != 0) {
        int ret = func_ov017_021a23e4(c, a0, b->field8, b->fieldc);
        EnqueueEventTag139_021d09cc(ret, a0, 0, b->fieldc);
        return;
    }
    if (a0 != 0) return;
    signed char cur = GetSearchStructCurrentArrEntry(list);
    if (b->field6 != cur) return;
    struct Target021d0a18* t = *(struct Target021d0a18**)(c + 0x3000 + regionalOffset0);
    if (b->field4 != 0) {
        t->byte10 = 5;
        t->half12 = b->field4;
    } else {
        t->byte10 = 2;
    }
}
