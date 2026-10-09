#include <globaldefs.h>
#include "Resource/GameResources.h"

struct T02054280;
struct ZoneWork;
struct ZoneState { unsigned short zoneId; unsigned short previousZoneId; };
struct ZoneResourceState {
    char pad0[0x1b3c];
    unsigned int progress;
    char pad1b40[0x1b58 - 0x1b40];
    T02054280* slots;
    ZoneWork* work;
    unsigned char entered;
};
extern "C" ZoneState* func_02012fe4();
extern "C" void* func_0202ae18();
extern "C" void func_0201bd3c(ZoneState*, int, int);
extern "C" void func_02082828(ZoneWork*);
extern "C" void func_020542b4(T02054280*, SafeAllocator*, char*);
GameResources* func_ov017_0218b5b0();
extern "C" int _Z19IsIdInRange020981e4ii(int, int);
extern "C" int _Z19IsIdInRange02098240ii(int, int);
extern "C" int _Z17IsIdInSet02098210ii(int, int);
extern "C" void _Z23ResetAllocators02054280P9T02054280(T02054280*);

static inline SafeAllocator& GetResourceAllocator(GameResources* resources, int index) {
    return resources->allocator_array_1a0[index];
}

static inline char& GetResourceBuffer(GameResources* resources, int offset) {
    return resources->unknown_2cc[offset];
}

// USA: func_02097ec8
extern "C" ARM void func_02097ec8(ZoneResourceState* state) {
    ZoneState* zone = func_02012fe4();
    int zoneId = zone->zoneId;
    int previousZoneId = zone->previousZoneId;
    if (!_Z19IsIdInRange020981e4ii((int)state, zoneId) &&
        !_Z19IsIdInRange020981e4ii((int)state, previousZoneId)) return;
    if (zoneId != 0xc3b5 && zoneId != 0xc419 && zoneId != 0xc47d && zoneId != 0xc4e1)
        state->entered = 1;
    func_0202ae18();
    if (zoneId == 0xc3b5 && state->progress >= 2) {
        func_0201bd3c(zone, 9, 0);
        func_0201bd3c(zone, 10, 0);
    } else if (zoneId == 0xc41b && state->progress >= 4) {
        func_0201bd3c(zone, 20, 0);
        func_0201bd3c(zone, 21, 0);
    }
    if (_Z19IsIdInRange020981e4ii((int)state, zoneId) &&
        !_Z19IsIdInRange02098240ii((int)state, zoneId) &&
        !_Z17IsIdInSet02098210ii((int)state, zoneId) && zoneId != 0xc3bb) {
        GameResources* resources = func_ov017_0218b5b0();
        SafeAllocator* allocator = &GetResourceAllocator(func_ov017_0218b5b0(), 2);
        allocator->Reset();
        state->slots = (T02054280*)allocator->Allocate(0x5ec);
        state->work = (ZoneWork*)allocator->Allocate(0x964);
        _Z23ResetAllocators02054280P9T02054280(state->slots);
        func_02082828(state->work);
        func_020542b4(state->slots, &resources->allocator_array_1a0[3], &GetResourceBuffer(resources, 0x930));
    }
}
