#include <globaldefs.h>
#include "Memory/HMRFAllocator.h"
#include "Filesystem/LowNitroHandle.h"

struct SelfObj020bc8d0;
void InitAllocatorObj020bc8d0(struct SelfObj020bc8d0* obj);

struct FourWords;
struct Mutex;
void ZeroInitializeMutex(Mutex*);

extern "C" void func_020beaec(void* arg);
extern "C" void func_020bf2f8(void* a, void* b);

struct Ctx021103b0_020be9e8 {
    int initialized;
    void* f4;
    void* field8;
};
extern struct Ctx021103b0_020be9e8 data_021103b0;

extern SignedAllocatorList data_021103bc;
extern HMRFAllocator data_021103e0[8];
extern struct FourWords data_021103c8;
extern int data_02111020;
extern int data_02110560;

struct Elem02110a4c {
    char pad0[0x5c];
    NitroVM vm;
    char pad_a4[0x110 - 0xa4];
    int field110;
    char pad114[0x120 - 0x114];
    int field120;
    unsigned char field124;
    char pad125[0x12c - 0x125];
    int field12c;
    int field130;
    char pad134[0x148 - 0x134];
    int field148;
    char pad14c[0x174 - 0x14c];
};
extern Elem02110a4c data_02110a4c[4];

// USA: func_020be9e8
ARM void InitAllocatorsAndVmPoolOnce_020be9e8(void* arg0, void* arg1) {
    int i;
    int j;

    if (data_021103b0.initialized != 0) {
        func_020beaec(arg1);
        return;
    }

    data_021103b0.initialized = 1;
    data_021103bc.Initialize(0);

    for (i = 0; i < 8; i++) {
        data_021103bc.InsertAtEnd(&data_021103e0[i].header);
    }

    ZeroInitializeMutex((Mutex*)&data_021103c8);

    data_021103b0.field8 = &data_02111020;

    for (j = 0; j < 4; j++) {
        Elem02110a4c* elem = &data_02110a4c[j];
        elem->field110 &= ~1;
        NitroVM_Initialize(&elem->vm);
        InitAllocatorObj020bc8d0((struct SelfObj020bc8d0*)elem);
        elem->field148 = j;
        elem->field124 = 0;
        elem->field12c = 0;
        elem->field130 = 0;
        elem->field120 = 0;
    }

    func_020beaec(arg1);
    func_020bf2f8(&data_02110560, arg0);
}
