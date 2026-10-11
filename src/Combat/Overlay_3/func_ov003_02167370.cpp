#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kRegionValue64_34 = 0x34 };
enum { kRegionValue60_30 = 0x30 };
#else
enum { kRegionValue64_34 = 0x64 };
enum { kRegionValue60_30 = 0x60 };
#endif


struct NotifyEntriesStruct0207f8bc;
void FlushNotifyEntries(struct NotifyEntriesStruct0207f8bc* p);
struct Struct02074bf4;
void ClearFlag0x11IfSet(struct Struct02074bf4* obj);
extern "C" int DisableSubBGVRAMBanks(void);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void MapVRAMBanksToSubObj(int value);
struct List0204afb4;
void ResetRecordList0204afb4(struct List0204afb4* obj);
struct Obj0204c754;
void ResetObject0204c754(struct Obj0204c754* obj);

// USA: func_ov003_02167370
// JPN: func_ov003_02167250
extern "C" ARM void func_ov003_02167370(char* obj) {
    int data4 = (int)BackgroundLoader::GetInstance();
    if (*(int*)(obj + kRegionValue64_34) >= 0) {
        ((BackgroundLoader*)(data4))->RemoveTask((int)(*(int*)(obj + kRegionValue64_34)));
        *(int*)(obj + kRegionValue64_34) = -1;
    }

    volatile unsigned int* p1 = (volatile unsigned int*)0x4001010;
    p1[0] = 0;
    p1[1] = 0;

    if (*(void**)(obj + 0x10) != 0) {
        FlushNotifyEntries(*(struct NotifyEntriesStruct0207f8bc**)(obj + 0x10));
    }
    ClearFlag0x11IfSet((struct Struct02074bf4*)(obj + 0x1c));

    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4001000;
    *dispcnt = (*dispcnt & ~0x1f00) | (*(int*)(obj + kRegionValue60_30) << 8);

    DisableSubBGVRAMBanks();
    MapVRAMBanksToSubBG(*(int*)(obj + 0x14));
    MapVRAMBanksToSubObj(*(int*)(obj + 0x18));

    if (*(void**)(obj + 8) != 0) {
        ResetRecordList0204afb4(*(struct List0204afb4**)(obj + 8));
        *(int*)(obj + 8) = 0;
    }
    if (*(void**)(obj + 0xc) != 0) {
        ResetObject0204c754(*(struct Obj0204c754**)(obj + 0xc));
        *(int*)(obj + 0xc) = 0;
    }
    if (*(void**)(obj + 0x10) != 0) {
        FlushNotifyEntries(*(struct NotifyEntriesStruct0207f8bc**)(obj + 0x10));
        *(int*)(obj + 0x10) = 0;
    }
    if (*(int*)obj != 0) {
        *(int*)obj = 0;
    }
    if (*(int*)(obj + 4) == 0) return;

    for (int i = 0; i < 3; i++) {
        if (((SafeAllocator*)(*(char**)(obj + 4) + i * 0x14))->GetSignedAllocator() != 0) {
            ((SafeAllocator*)(*(char**)(obj + 4) + i * 0x14))->Destroy();
        }
    }
}
