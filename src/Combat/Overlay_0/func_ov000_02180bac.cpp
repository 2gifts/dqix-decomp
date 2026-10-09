#include <globaldefs.h>

struct Obj0204bbb4;
void CallListEntry0204bbb4(struct Obj0204bbb4* obj, unsigned int idx, int a2, int a3,
                           short a4, short a5, short a6, short a7, unsigned short a8);
extern "C" void func_0205ac40(void* dst, void* src);
extern "C" int* func_0202ae18(void);
int CheckField0NonZero(int* obj);

extern const int data_ov000_021836a0[];

struct Entry02180bac {
    char pad0[0x14];
    int field14;
    int field18;
    char pad1[0x22 - 0x1c];
    unsigned char field22;
    char pad2[0x26 - 0x23];
    unsigned char field26;
    char pad3[0x28 - 0x27];
};

struct Obj02180bac {
    char pad0[0x1a];
    signed char field1a;
    char pad1[0x11c - 0x1b];
    char field11c[0x170 - 0x11c];
    struct Entry02180bac* entries;
    char pad2[0x8c4 - 0x174];
    char list8c4[0x930 - 0x8c4];
    int field930;
    int field934;
    char pad3[0x1d72 - 0x938];
    unsigned short flags1d72;
};

// USA: func_ov000_02180bac
extern "C" ARM void func_ov000_02180bac(struct Obj02180bac* obj) {
    CallListEntry0204bbb4((struct Obj0204bbb4*)obj->list8c4, 4, 1, 4, 0, 0, 0x20, 1, 0xffff);
    if (obj->field934 != 3) {
        struct Entry02180bac* e = &obj->entries[19];
        e->field14 = obj->field930 << 12;
        e->field18 = 0x2000;
        e->field22 = 0x48;
        e->field26 = 1;
        func_0205ac40(obj->field11c, e);
    }
    int flag = (obj->flags1d72 & 0x400) ? 1 : 0;
    if (flag & CheckField0NonZero(func_0202ae18())) {
        struct Entry02180bac* e = &obj->entries[6];
        int idx = obj->field1a - 2;
        if (obj->field1a < 0) {
            obj->field1a = 0;
        }
        e->field14 = 0xc8000;
        e->field18 = data_ov000_021836a0[idx] << 12;
        e->field22 = 0;
        e->field26 = 0;
        func_0205ac40(obj->field11c, e);
    }
}
