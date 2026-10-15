#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Combat/MapDisplay.h"

struct InitTarget0205cfd4 { char pad[0xbc]; };
struct Struct_0205bef8 { char pad[0x40]; };
struct Obj02092aa4 { char pad[0x3c]; };
struct State0xc0cc { char pad[0x18]; };

void ZeroInit020de848(void* obj);
void ResetList0204af64(struct List0204af64* obj);
void InitStruct0205cfd4(struct InitTarget0205cfd4* obj);
void Init0205bef8(struct Struct_0205bef8* obj);
extern "C" void func_0204c684(void* obj);
void InitObj02092aa4(Obj02092aa4* obj, int mode);
void InitStruct0205a444(char* obj);
extern "C" void* func_0202ae18(GameState* gs);
int GetField0x3acValue_020100a8(GameState* gs);
void InitFields0x0_0203c0cc(struct State0xc0cc* obj);

struct Battle021723a8;
extern "C" void func_ov000_0217228c(struct Battle021723a8* obj);
extern "C" void func_ov000_0216ff28(void* entry);
extern "C" void func_ov000_0217feb0(struct Battle021723a8* obj, unsigned char value, int id);
extern "C" void func_ov000_02174b14(struct Battle021723a8* obj);

struct Entry021723a8 {
    void* f0;
    void* f4;
    char pad8[0x38 - 0x8];
    void* f38;
    char pad3c[0x44 - 0x3c];
    int f44;
    int f48;
    char pad4c[0x448 - 0x4c];
};

struct Battle021723a8 {
    char pad0[0x20];
    int f20;
    char pad24[0x68 - 0x24];
    int f68;
    signed char order[4];
    char pad70[0x7c - 0x70];
    struct Obj02092aa4 obj7c;
    char padb8[0xd0 - 0xb8];
    char listD0[0xe8 - 0xd0];
    char listE8[0x11c - 0xe8];
    char obj11c[0x170 - 0x11c];
    int f170;
    int f174;
    int f178;
    int f17c;
    volatile unsigned short savedBg0Cnt;
    volatile unsigned short savedBg1Cnt;
    int f184;
    struct InitTarget0205cfd4 obj188;
    char pad244[0x244 - 0x188 - sizeof(struct InitTarget0205cfd4)];
    struct Struct_0205bef8 obj244;
    char pad284[0x284 - 0x244 - sizeof(struct Struct_0205bef8)];
    char slots284[7][0xe0];
    struct List0204af64 lists[3];
    char pad904[4];
    int f908;
    int f90c;
    int f910;
    int f914;
    int f918;
    int f91c;
    int f920;
    int f924;
    int f928;
    int f92c;
    char pad930[4];
    int f934;
    char pad938[4];
    int f93c;
    int f940;
    int f944;
    char pad948[0x950 - 0x948];
    int f950;
    unsigned char f954;
    unsigned char f955;
    unsigned char f956;
    char pad957;
    struct Entry021723a8 entries[4];
    SafeAllocator alloc1a78;
    SafeAllocator alloc1a8c;
    SafeAllocator alloc1aa0;
    SafeAllocator alloc1ab4;
    SafeAllocator alloc1ac8;
    SafeAllocator alloc1adc;
    int f1af0;
    char pad1af4[4];
    SafeAllocator alloc1af8;
    struct State0xc0cc states1b0c[3];
    struct State0xc0cc state1b54;
    struct State0xc0cc state1b6c;
    struct State0xc0cc states1b84[9];
    struct State0xc0cc states1c5c[8];
    char pad1d1c[0x1d5c - 0x1d1c];
    unsigned char f1d5c;
    char pad1d5d;
    unsigned short f1d5e;
    unsigned char flags1d60[8];
    signed char sel1d68;
    unsigned char f1d69;
    char pad1d6a;
    signed char f1d6b;
    signed char f1d6c;
    char pad1d6d;
    signed char f1d6e;
    signed char f1d6f;
    unsigned char f1d70;
    char pad1d71;
    unsigned short f1d72;
    char pad1d74[4];
    unsigned char f1d78;
    unsigned char f1d79;
    unsigned char f1d7a;
    char pad1d7b;
    int f1d7c;
    unsigned char f1d80;
    unsigned char f1d81;
};

struct BattleRef021723a8 {
    int f0;
    int limit;
    struct Battle021723a8* battle;
};
extern struct BattleRef021723a8 data_ov000_02184288;

// USA: func_ov000_021723a8
extern "C" ARM void func_ov000_021723a8(struct Battle021723a8* self, int arg) {
    self->f20 = -1;
    self->alloc1a78.ResetAllocatorPointer();
    self->alloc1a8c.ResetAllocatorPointer();
    self->alloc1ab4.ResetAllocatorPointer();
    self->alloc1aa0.ResetAllocatorPointer();
    self->alloc1ac8.ResetAllocatorPointer();
    self->alloc1adc.ResetAllocatorPointer();
    self->alloc1af8.ResetAllocatorPointer();
    ZeroInit020de848(self->listD0);
    ZeroInit020de848(self->listE8);
    data_ov000_02184288.battle = self;
    self->f68 = 0;
    self->f178 = 0;
    self->f17c = -1;
    self->f1d72 = 0;
    self->f1d72 |= 2;
    self->f184 = 0;
    {
        volatile unsigned short* reg = (volatile unsigned short*)0x4001008;
        volatile short v0, v1;
        {
            unsigned short raw = reg[0];
            v0 = raw;
            self->savedBg0Cnt = raw;
            v0;
        }
        {
            unsigned short raw = reg[1];
            v1 = raw;
            self->savedBg1Cnt = raw;
            v1;
        }
    }
    ResetList0204af64(&self->lists[0]);
    ResetList0204af64(&self->lists[1]);
    ResetList0204af64(&self->lists[2]);
    InitStruct0205cfd4(&self->obj188);
    Init0205bef8(&self->obj244);
    for (int i = 0; i < 7; i++) {
        func_0204c684(self->slots284[i]);
    }
    self->f1af0 = arg;
    InitObj02092aa4(&self->obj7c, 0);
    InitStruct0205a444(self->obj11c);
    self->f170 = 0;
    self->f174 = 0;
    self->f910 = 0;
    self->f934 = 0;
    self->f908 = 0;
    self->f90c = -1;
    self->f914 = 0;
    self->f918 = 0;
    self->f91c = 0;
    self->f920 = 0x100;
    self->f924 = 0x100;
    self->f928 = 0x100;
    self->f92c = 0;
    self->f1d5e = 0x10;
    self->f93c = 0;
    self->f940 = 0;
    self->f944 = 0;
    memset(self->flags1d60, 0, 8);
    self->sel1d68 = 0;
    self->flags1d60[self->sel1d68] = 1;
    self->f1d69 = 0;
    self->f1d6b = -1;
    self->f1d6c = -1;
    self->f1d6e = -1;
    self->f1d6f = -1;
    self->f1d70 = 0;
    self->f1d79 = 1;
    self->f1d80 = 0;
    self->f1d81 = 0;
    self->f1d5c = 0;
    self->f1d7a = 0;
    GameState* gs = GameState::GetInstance();
    func_0202ae18(gs);
    int id = GetField0x3acValue_020100a8(gs);
    if (id < 0) {
        id = 0;
    }
    self->f17c = id;
    func_ov000_0217228c(self);
    InitFields0x0_0203c0cc(&self->state1b54);
    InitFields0x0_0203c0cc(&self->state1b6c);
    for (int i = 0; i < 9; i++) {
        InitFields0x0_0203c0cc(&self->states1b84[i]);
    }
    for (int i = 0; i < 3; i++) {
        InitFields0x0_0203c0cc(&self->states1b0c[i]);
    }
    for (int i = 0; i < 8; i++) {
        InitFields0x0_0203c0cc(&self->states1c5c[i]);
    }
    struct Entry021723a8* e;
    for (int i = 0; i < 4; i++) {
        e = &self->entries[self->order[i]];
        func_ov000_0216ff28(e);
        e->f44 = 0;
        e->f48 = 0;
        e->f38 = &self->obj188;
        e->f4 = self->padb8;
        e->f0 = self->listD0;
    }
    func_ov000_0217feb0(self, 0, -1);
    func_ov000_0217feb0(self, 1, GetField0x3acValue_020100a8(gs));
    func_ov000_02174b14(self);
    self->f1d7c = 0;
    self->f1d78 = 0;
    self->f950 = 0;
    self->f954 = 0;
    self->f955 = 0;
    self->f956 = 0;
}
