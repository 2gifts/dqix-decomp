#include <globaldefs.h>

extern "C" unsigned int func_020937f0(int a);
int GetDisplayModeCode0209378c(int a);
extern "C" void func_0203bd08(int a);

int GetObjectValue020db2dc(int a, int b);

struct Struct020db9a8;
void SyncSwapBitState020db360(struct Struct020db9a8* obj, int b);

extern "C" void func_020db6e4(void* obj, int val);

struct Entity020db768;
void TickCounterAndProcessSlots020db768(struct Entity020db768* s, void* other);

void DMAMemsetSynchronous(int, unsigned int, unsigned int, unsigned int);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
void CleanCacheRange(const void* addr, unsigned int size);

struct Actor020db844;
void RunFlaggedCallback020db844(struct Actor020db844* a, int b, int c, int d);

typedef void (*DispatchFnA020db5ec)(int, int, int);
extern DispatchFnA020db5ec data_020f2904[];
typedef void (*DispatchFnB020db5ec)(int);
extern DispatchFnB020db5ec data_020f28f4[];

struct DisplayDispatchObj020db5ec {
    unsigned char pad0[0x3c];
    unsigned char field3c;
    unsigned char pad1[0x51 - 0x3c - 1];
    unsigned char field51;
    unsigned char pad2[0x53 - 0x51 - 1];
    unsigned char field53;
    unsigned char pad3[0x58 - 0x53 - 1];
    unsigned int field58;
};

// USA: func_020db5ec
ARM void ProcessDisplayDispatch020db5ec(struct DisplayDispatchObj020db5ec* obj) {
    if (obj->field51 == 0) return;
    unsigned int base = func_020937f0(obj->field3c);
    int shift = GetDisplayModeCode0209378c(obj->field3c);
    int offsetA = (base - 0xb80) >> shift;
    int offsetB = (base - 0x800) >> shift;
    func_0203bd08(shift);
    int handle = GetObjectValue020db2dc((int)obj, obj->field3c);
    SyncSwapBitState020db360((struct Struct020db9a8*)obj, 0);
    if (obj->field53 != 0) {
        func_020db6e4(obj, offsetB);
    }
    TickCounterAndProcessSlots020db768((struct Entity020db768*)obj, (void*)offsetA);
    CleanInvalidateCacheRange((const void*)handle, 0xe0);
    data_020f2904[obj->field3c](handle, 0, 0xe0);
    CleanCacheRange((const void*)handle, 0xe0);
    DMAMemsetSynchronous(3, handle + 0x20, 0xc0, 0x60);
    RunFlaggedCallback020db844((struct Actor020db844*)obj, obj->field3c, 0, 0);
    data_020f28f4[obj->field3c](obj->field58);
}
