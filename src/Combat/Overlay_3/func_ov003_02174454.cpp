#include <globaldefs.h>
#if defined(jpn)
enum { kRegionfec = 0xf68 };
enum { kRegionff4 = 0xf70 };
enum { kRegion2d8 = 0x228 };
enum { kRegion2e6 = 0x236 };
#else
enum { kRegionfec = 0xfec };
enum { kRegionff4 = 0xff4 };
enum { kRegion2d8 = 0x2d8 };
enum { kRegion2e6 = 0x2e6 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

int GetGlobalField0x1c020421a0();

struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);

// JPN: func_ov003_0217359c
// USA: func_ov003_02174454
extern "C" ARM void func_ov003_02174454(char* self) {
    unsigned char i;

    int data4 = (int)BackgroundLoader::GetInstance();
    if (*(int*)(self + kRegionfec) >= 0) {
        ((BackgroundLoader*)(data4))->RemoveTask((int)(*(int*)(self + kRegionfec)));
        *(int*)(self + kRegionfec) = -1;
    }

    unsigned char* g = (unsigned char*)GetGlobalField0x1c020421a0();
    *(int*)(g + kRegion2d8) = 0;
    g[kRegion2e6] = 1;

    unsigned int* reg = (unsigned int*)0x4000000;
    *reg = (*reg & ~0x1f00) | 0x100;
    *(unsigned short*)0x4000050 = 0;
    ClearFlag0x10IfSet((struct Struct02074bd0*)(self + 0x24));

#if !defined(jpn)
    if (*(void**)(self + kRegionff4) != 0)
#endif
    {
        memset(*(void**)(self + kRegionff4), 0, 0x20);
        CleanInvalidateCacheRange(*(void**)(self + kRegionff4), 0x20);
        LoadToMainBG1CharacterData((int)*(void**)(self + kRegionff4), 0, 0x20);
    }
    *(void**)(self + kRegionff4) = 0;

    if (*(void**)(self + 4) == 0) return;

    for (i = 0; i < 6; i++) {
        ((SafeAllocator*)(*(char**)(self + 4) + i * 0x14))->Destroy();
    }
}
