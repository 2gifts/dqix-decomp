#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
enum { kRegionValue464_28C = 0x28c };
enum { kRegionValue4A7_2CF = 0x2cf };
#else
enum { kRegionValue464_28C = 0x464 };
enum { kRegionValue4A7_2CF = 0x4a7 };
#endif

// USA: func_ov003_02160ec4  (semantic: UpdateFlag1000State_02160ec4)
extern "C" ARM void func_ov003_02160ec4(void* p) {
    char* obj = (char*)p;
    if (!(*(int*)(obj + kRegionValue464_28C) & 0x1000)) return;
    unsigned char state = *(unsigned char*)(obj + kRegionValue4A7_2CF);
    if (state == 0) {
        FontBankLoader* g = GetGlobal02109400_02094a00();
        BlankFunction02094b34(g, 0x1f5, 0x66, 0, 0);
        *(unsigned char*)(obj + kRegionValue4A7_2CF) = *(unsigned char*)(obj + kRegionValue4A7_2CF) + 1;
    } else if (state == 1) {
        if (AlwaysTrue02094b4c(GetGlobal02109400_02094a00()) != 0) {
            *(int*)(obj + kRegionValue464_28C) &= ~0x1000;
            *(unsigned char*)(obj + kRegionValue4A7_2CF) = *(unsigned char*)(obj + kRegionValue4A7_2CF) + 1;
        }
    }
}
