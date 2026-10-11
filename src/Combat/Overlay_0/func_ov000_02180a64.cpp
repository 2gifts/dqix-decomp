#include <globaldefs.h>

extern "C" int _Z29HasAnyFlags_021719f8_021719f8Pi(int* obj);

struct Entry02180a64 {
    char pad0[0x10];
    signed char values[8];
    signed char valueIndex;
    char pad19[0x1c - 0x19];
    signed char state;
    char pad1d[0x4c - 0x1d];
    int field4c;
#if defined(jpn)
    char pad50[0x488 - 0x50];
#else
    char pad50[0x448 - 0x50];
#endif
};

struct Flags02180a64 {
    unsigned short bit0 : 1;
    unsigned short bit1 : 1;
    unsigned short bit2 : 1;
    unsigned short bit3 : 1;
    unsigned short bit4 : 1;
    unsigned short bit5 : 1;
    unsigned short rest : 10;
};

struct Obj02180a64 {
    char pad0[0x6c];
    signed char members[4];
    char pad70[0x910 - 0x70];
    int field910;
    int field914;
    int field918;
    int field91c;
    int field920;
    int field924;
    int field928;
    char pad92c[0x958 - 0x92c];
    Entry02180a64 entries[4];
#if defined(jpn)
    char pad1a78[0x1faa - 0x1b78];
#else
    char pad1a78[0x1d72 - 0x1a78];
#endif
    Flags02180a64 flags;
};

// USA: func_ov000_02180a64
extern "C" ARM void func_ov000_02180a64(Obj02180a64* self) {
    int count;
    int ready;
    Entry02180a64* e;
    int i;
    count = 0;
    ready = 0;
    for (i = 0; i < 4; i++) {
        e = &self->entries[self->members[i]];
        if (e->field4c < 0) continue;
        if (_Z29HasAnyFlags_021719f8_021719f8Pi((int*)e)) continue;
        count++;
        if (e->values[e->valueIndex] < 100) continue;
        if (e->state == 6) ready++;
    }
    if (count != ready) return;
    self->field920 = 0x100;
    self->field924 = 0x100;
    self->field928 = 0x100;
    self->field910 = 0;
    self->field914 = 0;
    self->field918 = 0;
    self->field91c = 0;
    self->flags.bit3 = 0;
    self->flags.bit4 = 0;
    self->flags.bit5 = 1;
}
