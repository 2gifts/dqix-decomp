#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "Graphics/AtmosphericEffect.h"
#include "Memory/SafeAllocator.h"
#include "World/ZoneFeatures.h"

void ZeroInit020de848(void* obj);
struct Struct0207a5b8;
void ResetFourSubStructs_02012fa4(char* base);

struct AllocAt0x54_02013750 {
    char pad[(IS_JPN ? 0x74 : 0x54)];
    SafeAllocator alloc;
};

struct AllocAt0x2730_02013750 {
    char pad[(IS_JPN ? 0x770 : 0x730) + 0x2000];
    SafeAllocator alloc;
};

#pragma optimize_for_size off

// USA: func_02013750
ARM void ResetBigStruct02013750(void* obj, int flag) {
    *(int*)((char*)obj + (IS_JPN ? 0x858 : 0x838)) = 0;
    *(int*)((char*)obj + (IS_JPN ? 0x85c : 0x83c)) = 0;
    *(int*)((char*)obj + (IS_JPN ? 0x444 : 0x424)) = 0;
    *(int*)((char*)obj + (IS_JPN ? 0x43c : 0x41c)) = 0;
    *(int*)((char*)obj + (IS_JPN ? 0x438 : 0x418)) = 0;
    *(unsigned char*)((char*)obj + (IS_JPN ? 0x496 : 0x476)) = 0;
    *(unsigned char*)((char*)obj + (IS_JPN ? 0x497 : 0x477)) = 0;
    *(int*)((char*)obj + (IS_JPN ? 0x84c : 0x82c)) = 0;
    *(unsigned short*)((char*)obj + (IS_JPN ? 0x494 : 0x474)) = 0;
    *(int*)((char*)obj + (IS_JPN ? 0x84c : 0x82c)) = 0;
    *(unsigned char*)((char*)obj + (IS_JPN ? 0x44c : 0x42c)) = 0;
    *(int*)((char*)obj + (IS_JPN ? 0x450 : 0x430)) = -1;
    *(int*)((char*)obj + (IS_JPN ? 0x454 : 0x434)) = -1;
    *(int*)((char*)obj + (IS_JPN ? 0x458 : 0x438)) = -1;
    *(int*)((char*)obj + (IS_JPN ? 0x45c : 0x43c)) = -1;
    *(int*)((char*)obj + (IS_JPN ? 0x460 : 0x440)) = -1;
    *(int*)((char*)obj + (IS_JPN ? 0x498 : 0x478)) = 0;
    *(int*)((char*)obj + (IS_JPN ? 0x49c : 0x47c)) = 0;
    *(unsigned char*)((char*)obj + 0x2000 + (IS_JPN ? 0x3dc : 0x3bc)) = 0;
    *(unsigned char*)((char*)obj + 0x2000 + (IS_JPN ? 0x3dd : 0x3bd)) = 0;
    *(unsigned char*)((char*)obj + (IS_JPN ? 0x854 : 0x834)) = 0;
    ((ZoneFeatures*)((char*)obj + (IS_JPN ? 0x8c : 0x6c)))->Reset_0201e248();
    ZeroInit020de848((char*)obj + (IS_JPN ? 0x394 : 0x354) + 0x2400);
    ((AtmosphericEffectSet*)((struct Struct0207a5b8*)((char*)obj + (IS_JPN ? 0x114 : 0xf4))))->Reset();
    ResetFourSubStructs_02012fa4((char*)obj + (IS_JPN ? 0x620 : 0x600));
    if (!flag) {
        return;
    }
    AllocAt0x2730_02013750* b = (AllocAt0x2730_02013750*)obj;
    if (b->alloc.GetSignedAllocator() != NULL) {
        b->alloc.Destroy();
        b->alloc.ResetAllocatorPointer();
    }
    AllocAt0x54_02013750* a = (AllocAt0x54_02013750*)obj;
    if (a->alloc.GetSignedAllocator() == NULL) {
        return;
    }
    a->alloc.Destroy();
    a->alloc.ResetAllocatorPointer();
}
