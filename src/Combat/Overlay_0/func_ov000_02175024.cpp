#include <globaldefs.h>

struct S02170460 {
    char pad0[0x24];
    unsigned char flags;
    char pad1[0x4c - 0x25];
    int field4c;
    char pad2[0x448 - 0x50];
};

struct Obj02175024 {
    char pad0[0x6c];
    signed char order[4];
    char pad1[0x93c - 0x70];
    int phase;
    int waveX;
    int waveY;
    char pad2[0x958 - 0x948];
    struct S02170460 entries[1];
};

extern "C" void func_ov000_02170460(struct S02170460* obj, int count);
extern "C" void func_ov000_02174e50(struct Obj02175024* obj, int cid);

extern const int data_ov000_021833f8[];
extern const int data_ov000_02183408[];

// USA: func_ov000_02175024
extern "C" ARM void func_ov000_02175024(struct Obj02175024* obj, int count) {
    struct S02170460* entry;
    int i;
    for (i = 0; i < 4; i++) {
        entry = &obj->entries[obj->order[i]];
        int cid = entry->field4c;
        int valid = (cid >= 0 && cid <= 3) ? 1 : 0;
        if (!valid) continue;
        func_ov000_02170460(entry, count);
        if (entry->flags & 8) {
            func_ov000_02174e50(obj, cid);
        }
    }

    obj->phase += count;
    obj->phase &= 0xf;
    int slot = obj->phase >> 2;
    obj->waveX = data_ov000_021833f8[slot];
    obj->waveY = data_ov000_02183408[slot];
}
