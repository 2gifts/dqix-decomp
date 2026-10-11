// JPN: func_ov017_021b23cc
#if defined(jpn)
enum { RegionOffset26c = 0xc };
#else
enum { RegionOffset26c = 0x26c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "System/Memory.h"

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);

struct BitField5d00c_021b1d44 { char pad[0xc]; unsigned short lo13 : 13; unsigned short hi3 : 3; };
struct Outer26c_021b1d44 { char pad[0x5d00]; struct BitField5d00c_021b1d44 area; };

struct Obj021b1d44 { unsigned char pad0[0x3c]; int arr[8]; };

// USA: func_ov017_021b1d44
extern "C" ARM int func_ov017_021b1d44(unsigned char* self, int flags, int clearSlots) {
    ResetByteHeader((struct ByteHeader0204693c*)self);
    self[0] = 0x2c;
    *(int*)(self + 8) = 0;
    self[0x20] = 0;
    self[0x21] = (unsigned char)flags;
    *(int*)(self + 0x24) = 0;
    ((SafeAllocator*)(self + 0xc))->ResetAllocatorPointer();
    self[0x32] = 0;
    if (clearSlots != 0) {
        self[0x28] = 0;
        self[0x29] = 0;
        VectorizedMemset(self + 0x2a, 0, 8);
    }
    *(int*)(self + 0x34) = 0;
    *(int*)(self + 0x38) = 0;
    if ((self[0x21] & 0x40) != 0) {
        struct Obj021b1d44* obj = (struct Obj021b1d44*)self;
        for (int i = 0; i < 8; i++) {
            obj->arr[i] = -1;
        }
        return 0;
    }
    struct Outer26c_021b1d44* outer =
        (struct Outer26c_021b1d44*)((char*)GameState::GetInstance() + RegionOffset26c);
    if ((outer->area.lo13 & 8) == 0) {
        unsigned char f = self[0x21];
        if ((f & 4) == 0 && (f & 2) == 0 && (f & 0x20) == 0) {
            self[0x21] = f | 0x10;
        }
    }
    return 1;
}
