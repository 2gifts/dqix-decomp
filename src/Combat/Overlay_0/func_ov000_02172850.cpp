#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0xbf0
#else
#define REGION_OFFSET_0 0xaf0
#endif

#include "Memory/SafeAllocator.h"

extern "C" void MapVRAMBanksToSubBG(int);
void ConfigureSubBg0Control_02172944(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
void ConfigureSubBg1Control_02172978(int screenSize, int colorMode, int screenBase, int charBase, int bit13);
extern "C" void MapVRAMBanksToSubObj(unsigned short value);

struct BgField0217 {
    unsigned short priority : 2;
    unsigned short charBase : 4;
    unsigned short pad1 : 1;
    unsigned short colorMode : 1;
    unsigned short screenBase : 5;
    unsigned short bit13 : 1;
    unsigned short screenSize : 2;
};

// USA: func_ov000_02172850  (semantic: ApplySubBgSettings_02172850)
extern "C" ARM void func_ov000_02172850(char* obj) {
    class SafeAllocator* alloc = *(class SafeAllocator**)(obj + 0x1000 + REGION_OFFSET_0);
    if (alloc) alloc->Reset();

    int f184 = *(int*)(obj + 0x184);
    if (f184) MapVRAMBanksToSubBG(f184);

    struct BgField0217* val2 = (struct BgField0217*)(obj + 0x180);
    struct BgField0217* val1 = (struct BgField0217*)(obj + 0x182);
    ConfigureSubBg0Control_02172944(val2->screenSize, val2->colorMode, val2->screenBase, val2->charBase, val1->bit13);
    ConfigureSubBg1Control_02172978(val1->screenSize, val1->colorMode, val1->screenBase, val1->charBase, val1->bit13);

    unsigned short* bgcnt = (unsigned short*)0x4001008;
    bgcnt[0] = (bgcnt[0] & ~3) | val2->priority;
    bgcnt[1] = (bgcnt[1] & ~3) | val1->priority;
    MapVRAMBanksToSubObj(0x100);
}
