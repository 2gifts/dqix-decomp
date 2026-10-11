#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

void* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);
void ZeroInit020de848(void* obj);
void ClearFields_021e20c0(void* p);
void FilterSlotsWithFlag0x800020dc4d0(signed char* out, signed char* outCount);

// JPN: func_ov023_021e3138
// USA: func_ov023_021e2dd8
extern "C" ARM void func_ov023_021e2dd8(unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x124, regionalOffset1=0x128, regionalOffset2=0x130, regionalOffset3=0x4e2, regionalOffset4=0x4e3, regionalOffset5=0x11c, regionalOffset6=0x120, regionalOffset7=0x4e4, regionalOffset8=0x4e8, regionalOffset9=0x4e0, regionalOffset10=0x568, regionalOffset11=0x56c, regionalOffset12=0x56e, regionalOffset13=0x570, regionalOffset14=0x574};
#else
 enum {regionalOffset0=0x128, regionalOffset1=0x12c, regionalOffset2=0x134, regionalOffset3=0x4e6, regionalOffset4=0x4e7, regionalOffset5=0x120, regionalOffset6=0x124, regionalOffset7=0x4e8, regionalOffset8=0x4ec, regionalOffset9=0x4e4, regionalOffset10=0x630, regionalOffset11=0x634, regionalOffset12=0x636, regionalOffset13=0x638, regionalOffset14=0x63c};
#endif
    void* p;
    GameState* battle;
    signed char buf[4];
    signed char outCount;
    int i;
    int j;

    p = GetDataPtr02114e04_020d6c00();
    OrBitsIntoField0((unsigned int*)p, 0xf);

    *(unsigned int*)(obj + 0x0) = 0;
    *(unsigned int*)(obj + 0x4) = 0;
    *(unsigned int*)(obj + 0xc) = 0;
    *(unsigned int*)(obj + 0x10) = 0;
    *(unsigned int*)(obj + 0x14) = 0;

    ((SafeAllocator*)(obj + 0x2c))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x40))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x54))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x68))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x7c))->ResetAllocatorPointer();
    ((SafeAllocator*)(obj + 0x90))->ResetAllocatorPointer();

    ZeroInit020de848(obj + 0xa4);

    *(unsigned short*)(obj + 0xbc) = 0;
    *(unsigned short*)(obj + 0xbe) = 0;
    *(unsigned int*)(obj + 0xc0) = 0;
    *(unsigned int*)(obj + 0xc4) = 0;
    *(unsigned int*)(obj + 0xc8) = 0;
    *(unsigned int*)(obj + 0xcc) = 0;
    *(unsigned int*)(obj + 0xd0) = 0;

    ClearFields_021e20c0(obj + 0xd4);

    *(unsigned int*)(obj + regionalOffset0) = 0;
    *(unsigned int*)(obj + regionalOffset1) = 0;
    *(unsigned int*)(obj + regionalOffset2) = 0;
    *(unsigned char*)(obj + regionalOffset3) = 0;
    *(unsigned char*)(obj + regionalOffset4) = 0;
    *(unsigned int*)(obj + regionalOffset5) = 0;
    *(unsigned int*)(obj + regionalOffset6) = 0;
    *(unsigned int*)(obj + regionalOffset7) = 0;

    battle = GameState::GetInstance();
    outCount = 0;
    for (i = 0; i < 4; i++) buf[i] = -1;
    FilterSlotsWithFlag0x800020dc4d0(buf, &outCount);
    for (j = 0; j < 4; j++) {
        signed char v = buf[j];
        *(int*)((char*)obj + j * 4 + regionalOffset8) = v;
        GetCombatantWithFlag0x100(battle, v);
    }

    *(int*)(obj + regionalOffset7) = outCount;
    *(unsigned char*)(obj + regionalOffset9) = 1;
    *(unsigned int*)(obj + regionalOffset10) = 0;
    memset(obj + regionalOffset11, 0, 2);
    *(unsigned char*)(obj + regionalOffset12) = 0;
    *(unsigned int*)(obj + regionalOffset13) = 0;
    *(unsigned int*)(obj + regionalOffset14) = 0;
#if defined(jpn)

#else
    *(unsigned int*)(obj + 0x640) = 0;
    *(unsigned int*)(obj + 0x644) = 0;
#endif

}
