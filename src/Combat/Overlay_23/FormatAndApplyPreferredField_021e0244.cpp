#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int len);
struct StructDE234_020de234;
unsigned short GetPreferredPackedField020de234(struct StructDE234_020de234* p, int preferMid);
struct InitStruct2075;
void ClearStructFields(struct InitStruct2075* p);

extern char data_ov023_021fdc23[];
extern char data_ov023_021fdc36[];

// JPN: func_ov023_021e07ec
// USA: func_ov023_021e0244
ARM int FormatAndApplyPreferredField_021e0244(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x6f0, regionalOffset1=0x6b4};
#else
 enum {regionalOffset0=0x774, regionalOffset1=0x738};
#endif
    int listPtr = (int)BackgroundLoader::GetInstance();
    int ok = 0;

    if (*(void**)((char*)obj + 0x4c) != 0) {
        char buf[0x40];
        __clear(buf, 0x40);

        if ((*(unsigned short*)((char*)obj + regionalOffset0) & 0x1000) != 0) {
            struct StructDE234_020de234* sp2 = *(struct StructDE234_020de234**)((char*)obj + 0x4c);
            unsigned short val = GetPreferredPackedField020de234(sp2, 0);
            struct StructDE234_020de234* s2 = *(struct StructDE234_020de234**)((char*)obj + 0x4c);
            unsigned int raw10 = *(unsigned int*)((char*)s2 + 0x10);
            int percent = (raw10 << 4) >> 0x18;
            sprintf(buf, data_ov023_021fdc23, percent, val);
        } else {
            struct StructDE234_020de234* sp2 = *(struct StructDE234_020de234**)((char*)obj + 0x4c);
            unsigned short val = GetPreferredPackedField020de234(sp2, 0);
            struct StructDE234_020de234* s2 = *(struct StructDE234_020de234**)((char*)obj + 0x4c);
            unsigned int raw10 = *(unsigned int*)((char*)s2 + 0x10);
            int percent = (raw10 << 4) >> 0x18;
            sprintf(buf, data_ov023_021fdc36, percent, val);
        }

        int r = ((BackgroundLoader*)(listPtr))->QueueLoadFile((const char*)((int)buf), (SafeAllocator*)(0));
        *(int*)((char*)obj + regionalOffset1) = r;
        ok = 1;
    }

    if (ok != 0) return 4;

    *(unsigned short*)((char*)obj + regionalOffset0) |= 8;
    ClearStructFields(*(struct InitStruct2075**)((char*)obj + 0xc8));
    return 6;
}
