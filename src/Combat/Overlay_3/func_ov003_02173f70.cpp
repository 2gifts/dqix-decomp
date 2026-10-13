#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct EntryManager020e2490;
struct Struct0205a198;

struct Node0207f7f0 {
    struct Node0207f7f0* prev;
    char pad[0xe0 - 4];
};

struct Manager0207f7f0 {
    char pad[0x30];
    struct Node0207f7f0* nodes;
};

struct Obj0207f84c {
    int field0;
    unsigned char sub4[8];
    unsigned char arrC[8];
    int field14;
    int field18;
    int field1c;
    int field20;
    int field24;
    int field28;
    void* field2c;
    int field30;
    short field34;
    short field36;
    unsigned char field38;
    unsigned char field39;
    unsigned char field3a;
    unsigned char field3b;
    unsigned char field3c;
};

extern "C" void _Z24InitEntryManager020e2490P20EntryManager020e2490iiPvP13SafeAllocatorih(struct EntryManager020e2490* obj, int arg1, int arg2, void* arg3, SafeAllocator* alloc, int count, unsigned char flag);
extern "C" void _Z21InitNodeChain0207f7f0P15Manager0207f7f0P12Node0207f7f0i(struct Manager0207f7f0* mgr, struct Node0207f7f0* nodes, int count);
extern "C" void _Z12Init0205a198P14Struct0205a198(struct Struct0205a198*);
extern "C" void func_0207f84c(Obj0207f84c*);

extern unsigned int data_ov003_02180cc8[];
extern unsigned int data_ov003_02180a8c[];
extern unsigned int data_ov003_02180a8c_dup[];


struct Sub80002173f70 {
    char pad[0x14];
    void* f814;
    void* f818;
    char pad81c[0x24 - 0x1c];
    unsigned short f824;
    char pad826[2];
    unsigned char f828;
    char pad829[3];
};

struct Obj02173f70 {
    EntryManager020e2490* mgr;
    SafeAllocator* allocs;
    char pad8[0x800 - 0x8];
    Sub80002173f70 sub;
    void* f82c;
    Struct0205a198* f830;
    char pad834[0x89c - 0x834];
    Obj0207f84c* f89c;
    void* f8a0;
    char pad8a4[0x8e0 - 0x8a4];
    struct Node0207f7f0 nodes[8];
};

// USA: func_ov003_02173f70
extern "C" ARM void func_ov003_02173f70(Obj02173f70* self, SafeAllocator* alloc) {
    if (alloc != 0) {
        self->allocs = (SafeAllocator*)alloc->Allocate(0x78);
        self->f830 = (struct Struct0205a198*)alloc->Allocate(0x528);
        self->f89c = (Obj0207f84c*)alloc->Allocate(0x40);
        self->f82c = alloc->Allocate(8);
        self->mgr = (struct EntryManager020e2490*)alloc->Allocate(0x24);
        _Z24InitEntryManager020e2490P20EntryManager020e2490iiPvP13SafeAllocatorih(self->mgr, 0, 1, self->f82c, alloc, 4, 0x40);

        unsigned int flag = data_ov003_02180cc8[1];
        if (!(flag & 1)) {
            data_ov003_02180a8c[0] = 0x16a66;
            data_ov003_02180cc8[1] |= 1;
        }

        unsigned char i;
        for (i = 0; i < 6; i++) {
            unsigned int size = data_ov003_02180a8c_dup[i];
            SafeAllocator* allocs = self->allocs;
            allocs[i].ResetAllocatorPointer();
            allocs[i].CreateTypeA(alloc->Allocate(size), size);
            allocs[i].Reset();
        }

        func_0207f84c(self->f89c);
        Obj0207f84c* o = self->f89c;
        o->field2c = (void*)&self->f8a0;
        o->field38 = 2;
        _Z21InitNodeChain0207f7f0P15Manager0207f7f0P12Node0207f7f0i((Manager0207f7f0*)self->f89c, self->nodes, 8);
        self->f89c->field3a = 2;

        unsigned char j;
        for (j = 0; j < 0x21; j++) {
            _Z12Init0205a198P14Struct0205a198((struct Struct0205a198*)((char*)self->f830 + j * 0x28));
        }

        self->sub.f828 = 0;
        self->sub.f818 = self->f830;
        self->sub.f824 = 0x21;
        self->sub.f814 = self->f82c;
    }
}