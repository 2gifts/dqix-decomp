#include <globaldefs.h>

struct Pair020bf658 { unsigned int a; unsigned int b; };

struct Obj020bf658 {
    char pad0[0xc0];
    unsigned char state;
    char pad1[0xc4 - 0xc1];
    unsigned short field0xc4;
    char pad2[0x110 - 0xc6];
    unsigned int flags0x110;
    char pad3[0x13c - 0x114];
    int (*fn0x13c)(int, Pair020bf658*, Pair020bf658*, int);
    int field0x140;
    int field0x144;
    int field0x148;
    char pad4[0x160 - 0x14c];
    int field0x160;
    int (*fn0x164)(void*, unsigned int);
    void (*fn0x168)(void*);
};

void* GetOffsetEntry0x24_020bd5e4(int index);
void InitActionHandlers020bffc4(void* obj, unsigned int id);

// USA: func_020bf658
#pragma optimize_for_size off
ARM void UpdateAndDispatch020bf658(struct Obj020bf658* obj) {
    Pair020bf658 p1, p2;
    unsigned int oldC0;
    unsigned short oldC4, newC4;
    unsigned int* entry;
    unsigned int id;
    unsigned long long prod;

    p1.a = obj->field0x148;
    p1.b = obj->field0x144;
    p2.a = obj->field0x144;
    p2.b = 0;
    if (!obj->fn0x13c(0, &p1, &p2, obj->field0x140)) return;

    entry = (unsigned int*)GetOffsetEntry0x24_020bd5e4(p2.a);
    if (entry == 0) return;

    oldC0 = obj->state;
    oldC4 = obj->field0xc4;
    obj->fn0x168(obj);

    id = *entry;
    InitActionHandlers020bffc4(obj, id);

    id = *entry;
    if (!obj->fn0x164(obj, id)) return;

    newC4 = obj->field0xc4;
    if (oldC4 != newC4) return;

    if (oldC0 == 0) {
        if (obj->state != 0) return;
    }
    if (oldC0 != 0) {
        if (obj->state == 0) return;
    }

    obj->field0x144 = p2.a;
    prod = (unsigned long long)obj->field0xc4 * (unsigned long long)p2.b;
    obj->field0x160 = (int)(prod / 1000);

    if (obj->field0x160 != 0 && obj->state == 2) {
        obj->flags0x110 |= 0x10;
    } else {
        obj->flags0x110 &= ~0x10;
    }
    obj->flags0x110 &= ~0x20;
}
