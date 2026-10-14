#include <globaldefs.h>

struct Obj2081;
struct Elem2081;
extern struct Elem2081* FindElementByByte0xc4_02081da8(struct Obj2081*, int);
extern int CheckField0x9cSetWhenField0xd4Present_0204c7e0(unsigned char*);
extern void GetLookAndTurnOffsets020809c4(void*, int, int, short*, short*);

struct Container0205a3d0;
struct Container0205a330;

struct Elem02186e2c {
    char unk0[4];
    unsigned short unk4;
    unsigned short unk6;
    char unk8[0x15 - 0x8];
    unsigned char flags15;
};

extern struct Elem02186e2c* FindEntryByHalfword0205a3d0(struct Container0205a3d0*, int);
extern void SetEntryFlag2ByKey0205a370(struct Container0205a3d0*, int);
extern void IterateEntries0205a330(struct Container0205a330*, int);
extern "C" void func_0205ae8c(void*);

struct Obj02186e2c {
    char pad0[0xc0];
    void* field0xc0;
    char pad1[0xd0 - 0xc4];
    short* field0xd0;
    char pad2[0xd8 - 0xd4];
    struct Container0205a3d0* field0xd8;
    char pad3[0xf8 - 0xdc];
    char field0xf8[0x164 - 0xf8];
    int field0x164;
    char pad4[0x170 - 0x168];
    short field0x170;
};

// USA: func_ov014_02186e2c
extern "C" ARM void func_ov014_02186e2c(struct Obj02186e2c* self) {
    struct Elem2081* elem;
    struct Elem02186e2c* e;
    short outB, outA;
    short unk4val, unk6val;

    if (self->field0xd0 == NULL) return;
    if (self->field0x170 < 0) return;
    elem = FindElementByByte0xc4_02081da8((struct Obj2081*)self->field0xc0, self->field0x170);
    if (elem == NULL) return;
    if (CheckField0x9cSetWhenField0xd4Present_0204c7e0((unsigned char*)elem) == 0) return;

    GetLookAndTurnOffsets020809c4(self->field0xc0, self->field0x170, *self->field0xd0, &outB, &outA);
    outB -= 0x10;
    outA -= 3;

    SetEntryFlag2ByKey0205a370(self->field0xd8, 0);
    e = FindEntryByHalfword0205a3d0(self->field0xd8, 0);
    if (e != NULL) {
        e->flags15 |= 8;
    }
    IterateEntries0205a330((struct Container0205a330*)self->field0xd8, self->field0x164);
    unk6val = outA;
    unk4val = outB;
    e = FindEntryByHalfword0205a3d0(self->field0xd8, 0);
    if (e != NULL) {
        e->unk4 = unk4val;
        e->unk6 = unk6val;
    }
    func_0205ae8c(&self->field0xf8);
}
