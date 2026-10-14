#if !defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"
#include "System/Cache.h"

int GetGlobalField0x1c020421a0(void);
void DelayThenSyncBit0(void);
extern "C" void func_02023218(void* arg0, void* buf, int flag);
extern "C" int LoadToSubObjVRAM(void* buf, int a1, int a2);

// USA: func_020233b8
ARM int InitAndCopyBuffer020233b8(void* arg0, int flag1)
{
    void* base = (void*)GetGlobalField0x1c020421a0();
    int offset = 0;
    int i = offset;
    void* buf = *(void**)((char*)base + 0x60);
    int copySize = 0x40;
    while (i < 0x13)
    {
        memcpy((char*)buf + offset, (char*)arg0 + 0xbf0, copySize);
        offset += 0x40;
        i++;
    }

    func_02023218(arg0, buf, 0);
    if (flag1 != 0)
    {
        DelayThenSyncBit0();
    }

    CleanInvalidateCacheRange(buf, 0x4c0);
    LoadToSubObjVRAM(buf, 0x2c00, 0x4c0);

    return 1;
}

#endif
