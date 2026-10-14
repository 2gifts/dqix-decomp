#include <globaldefs.h>

int ComputeMaskedIndexOffset_020d6884(void*, int, int, int);
extern "C" int func_020ca3b8(int, int, int);
extern "C" void func_020ca390(int, void*, unsigned int);
unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);

struct Block020d6610 {
    unsigned short flagsA;
    unsigned short flagsB;
    unsigned char pad[0x1fc];
};

struct Sub020d6610 {
    unsigned char pad0[8];
    unsigned short idx;
    unsigned char pad1[4];
    unsigned short flags;
    unsigned short field10;
    unsigned char pad2[6];
    unsigned short state;
};

struct Obj020d6610 {
    struct Block020d6610 blocks[4];
    struct Sub020d6610 sub;
};

// USA: func_020d6610
ARM void ClearAndSetBlockFlag020d6610(struct Obj020d6610* obj, int bit, int extra) {
    unsigned short mask = (unsigned short)(1 << bit);
    unsigned short flags = obj->sub.flags;
    if (!(flags & mask)) return;
    int idx = obj->sub.idx;
    if (!(obj->blocks[idx].flagsA & mask)) {
        if (obj->sub.state != 1) return;
        idx = (idx + 1) & 3;
        if (!(obj->blocks[idx].flagsA & mask)) return;
    }
    int val = ComputeMaskedIndexOffset_020d6884(obj, flags, (int)&obj->blocks[idx] + 4, bit);
    if (extra != 0) {
        func_020ca3b8(extra, val, obj->sub.field10);
    } else {
        func_020ca390(0, (void*)val, obj->sub.field10);
    }
    unsigned int state = DisableIRQInterrupts();
    obj->blocks[idx].flagsA &= ~mask;
    obj->blocks[idx].flagsB |= mask;
    SetIRQInterruptState(state);
}
