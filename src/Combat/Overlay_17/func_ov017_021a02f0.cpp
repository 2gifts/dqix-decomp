#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
void BackupPairTableToBuffer(int* out);
extern "C" void _Z22ReadGlobalPair020bb910Pi(int* dst);
extern "C" int func_020bb588(unsigned int size, int a, int b);
extern "C" void func_0207de48(void* pObj, int a, int b);
extern "C" void func_020542b4(void* a, void* b, void* c);

extern AllocatorUnion data_02114e20;

struct AllocEntry021a02f0 {
    int index;
    unsigned int size;
};
extern AllocEntry021a02f0 data_ov017_021d6984[];

struct SlotEntry021a02f0 {
    int index;
    int a;
    int b;
};
extern SlotEntry021a02f0 data_ov017_021d6924[];

struct Slot021a02f0 {
    char data[0x70];
};

struct Group021a02f0 {
    short field_0x0;
    short id;
    char data[0x5ec - 0x4];
};

struct PairBackup021a02f0 {
    int table[10];
    int pair[2];
};

struct Battle021a02f0 {
    char pad0[0x38];
    SafeAllocator allocators[33];
    Slot021a02f0 slots[36];
    char pad128c[0x12c8 - 0x128c];
    Group021a02f0 groups[4];
    PairBackup021a02f0 backups[3];
};

// USA: func_ov017_021a02f0
extern "C" ARM void func_ov017_021a02f0(Battle021a02f0* self) {
    int i;
    unsigned int size;

    for (i = 0; (size = data_ov017_021d6984[i].size) != 0; i++) {
        void* buf = AllocateAligned4(&data_02114e20, size);
        self->allocators[data_ov017_021d6984[i].index].CreateTypeA(buf, size);
    }

    BackupPairTableToBuffer(self->backups[0].table);
    _Z22ReadGlobalPair020bb910Pi(self->backups[0].pair);
    func_020bb588(0x20000, 0, 0);
    func_020bb588(0x20000, 0, 0);

    for (i = 0; data_ov017_021d6924[i].a != 0; i++) {
        func_0207de48(&self->slots[data_ov017_021d6924[i].index], data_ov017_021d6924[i].a,
                      data_ov017_021d6924[i].b);
        if (i == 1) {
            BackupPairTableToBuffer(self->backups[2].table);
            _Z22ReadGlobalPair020bb910Pi(self->backups[2].pair);
        }
    }

    BackupPairTableToBuffer(self->backups[1].table);
    _Z22ReadGlobalPair020bb910Pi(self->backups[1].pair);

    for (int j = 0; j < 4; j++) {
        func_020542b4(&self->groups[j], &self->allocators[j + 1], &self->slots[j + 1]);
        self->groups[j].id = j;
    }
}
