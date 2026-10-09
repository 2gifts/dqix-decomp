#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* _Z20GetField6b0_021b8470Pv(void* obj);

struct Owner021c62e4 {
    unsigned char pad0[8];
    unsigned short id;
};

struct Slot021c62e4 {
    unsigned char pad0[2];
    unsigned char values[8];
    unsigned char count : 4;
    unsigned char flags : 4;
    unsigned char pad0b[0xd];
};

struct Holder021c62e4 {
    unsigned char pad0[4];
    Slot021c62e4 slots[1];
};

struct Payload021c62e4 {
    unsigned short id;
    short slotIndex;
    unsigned char values[8];
};

struct Evt021c62e4 {
    unsigned char tag;
    unsigned char pad1[3];
    Payload021c62e4 payload;
};

// USA: func_ov017_021c62e4
extern "C" ARM void func_ov017_021c62e4(int unused0, Evt021c62e4* src, void* unused2, char* base) {
    Slot021c62e4* slot;
    int i;
    void* table = *(void**)(base + 0x3000 + 0x718);

    char* state = (char*)_Z20GetField6b0_021b8470Pv(table);
    if (!state) return;

    Owner021c62e4* owner = (Owner021c62e4*)func_ov017_021b8478(table);
    if (!owner) return;

    Payload021c62e4* p = &src->payload;
    if (owner->id != p->id) return;

    slot = &((Holder021c62e4*)(state + 0x1b0 + 0x8000))->slots[p->slotIndex];
    for (i = 0; i < slot->count; i++) {
        slot->values[i] = 0;
        slot->values[i] = p->values[i];
    }
}
