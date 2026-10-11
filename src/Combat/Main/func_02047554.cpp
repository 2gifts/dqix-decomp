#include <globaldefs.h>

extern "C" void func_02047718(void* obj, void* entry, int something);

struct Entry02047554 {
    unsigned char byteAt0;
    unsigned char byteAt1;
    unsigned char count;
    unsigned char pad3;
    unsigned char* arrayPtr;
};

struct Flags02047554 {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char rest : 6;
};

struct Obj02047554 {
    char pad0[0x8];
    struct Entry02047554* entries;
    char pad1[0x1c - 0x8 - 4];
    int f1c;
    int f20;
    int f24;
    char pad2[0x34 - 0x28];
    int f34;
    int f38;
    int f3c;
    char pad3[0x82 - 0x40];
    short f82;
    struct Flags02047554 f84;
};

// USA: func_02047554
extern "C" ARM void func_02047554(struct Obj02047554* obj, int idx, int something) {
    if (!obj->f84.bit0) return;
    if (!obj->f84.bit1) return;
    if (obj->f82 <= 0) return;

    struct Entry02047554* entry = obj->entries + idx;
    if (entry->arrayPtr == 0 || entry->count == 0) return;

    volatile int* reg = (volatile int*)0x4000444;
    *reg = 0;
    *(volatile int*)((char*)reg + 0x7c) = 0x7fffffff;
    *(volatile int*)((char*)reg + 0x80) = 0x4210;

    int tx = obj->f1c;
    int ty = obj->f20 + entry->byteAt1 * obj->f38;
    int tz = obj->f24;
    *(volatile int*)((char*)reg + 0x2c) = tx;
    *(volatile int*)((char*)reg + 0x2c) = ty;
    *(volatile int*)((char*)reg + 0x2c) = tz;

    int sz = obj->f3c;
    int sx = obj->f34;
    int sy = -obj->f38;
    *(volatile int*)((char*)reg + 0x28) = sx;
    *(volatile int*)((char*)reg + 0x28) = sy;
    *(volatile int*)((char*)reg + 0x28) = sz;

    unsigned char* p = entry->arrayPtr;
    int i;
    for (i = 0; i < entry->count; ) {
        func_02047718(obj, p, something);
        i++;
        p += 8;
    }
    *(volatile int*)0x4000448 = 1;
}
