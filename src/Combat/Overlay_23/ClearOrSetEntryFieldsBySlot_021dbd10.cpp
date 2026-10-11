#include <globaldefs.h>

extern "C" void* func_ov023_021db4e4(void* obj, int key);
void SetEntryFields_021e23d0(void* obj, int val, int f0xc, unsigned char lowNib, unsigned char highNib);
struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310*, int);

struct Elem021dbd10 {
    char pad[0x16];
    unsigned char flags;
};

struct Param021dbd10 {
    char pad[8];
    unsigned int low4 : 4;
};

struct DataStruct021dbd10 {
#if !defined(jpn)
    unsigned char pad[0x14];
#endif
    struct Container020e0310* field14;
};
extern struct DataStruct021dbd10 data_ov023_021ff9e0;

// JPN: func_ov023_021dc608
// USA: func_ov023_021dbd10  (semantic: ClearOrSetEntryFieldsBySlot_021dbd10)
extern "C" ARM void func_ov023_021dbd10(void* obj, struct Param021dbd10* p) {
    struct Elem021dbd10* e;
    if (!obj || !p) return;

    int cond = (p->low4 <= 7) ? 1 : 0;
    if (cond) {
        e = (struct Elem021dbd10*)func_ov023_021db4e4(obj, 0x9);
        if (e) e->flags &= ~1;
        e = (struct Elem021dbd10*)func_ov023_021db4e4(obj, 0x1c);
        if (e) e->flags &= ~1;
        e = (struct Elem021dbd10*)func_ov023_021db4e4(obj, 0x1b);
        if (e) e->flags &= ~1;
        e = (struct Elem021dbd10*)func_ov023_021db4e4(obj, 0xb);
        if (e) e->flags &= ~1;
        e = (struct Elem021dbd10*)func_ov023_021db4e4(obj, 0x2a);
        if (e) e->flags &= ~1;
        e = (struct Elem021dbd10*)func_ov023_021db4e4(obj, 0x2c);
        if (e) e->flags &= ~1;
        return;
    }

    e = (struct Elem021dbd10*)func_ov023_021db4e4(obj, 0x14);
    if (e) e->flags &= ~1;
    e = (struct Elem021dbd10*)func_ov023_021db4e4(obj, 0x13);
    if (e) e->flags &= ~1;
    e = (struct Elem021dbd10*)func_ov023_021db4e4(obj, 0x10);
    if (e) e->flags &= ~1;
    e = (struct Elem021dbd10*)func_ov023_021db4e4(obj, 0x12);
    if (e) e->flags &= ~1;
    e = (struct Elem021dbd10*)func_ov023_021db4e4(obj, 0xf);
    if (e) e->flags &= ~1;
    e = (struct Elem021dbd10*)func_ov023_021db4e4(obj, 0xe);
    if (e) e->flags &= ~1;

    SetEntryFields_021e23d0(obj, 0x19, GetFieldByKey020e0434(data_ov023_021ff9e0.field14, 0x24), 0xa, 0xf);
    SetEntryFields_021e23d0(obj, 0x17, GetFieldByKey020e0434(data_ov023_021ff9e0.field14, 0x23), 0x8, 0xf);
    SetEntryFields_021e23d0(obj, 0x1a, GetFieldByKey020e0434(data_ov023_021ff9e0.field14, 0x25), 0xa, 0xf);
    SetEntryFields_021e23d0(obj, 0x18, GetFieldByKey020e0434(data_ov023_021ff9e0.field14, 0x23), 0x8, 0xf);
    SetEntryFields_021e23d0(obj, 0x15, GetFieldByKey020e0434(data_ov023_021ff9e0.field14, 0x26), 0xa, 0xf);
    SetEntryFields_021e23d0(obj, 0x16, GetFieldByKey020e0434(data_ov023_021ff9e0.field14, 0x27), 0xa, 0xf);
}
