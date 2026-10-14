#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
enum { kRegionValue3EC_27C = 0x27c };
#else
enum { kRegionValue3EC_27C = 0x3ec };
#endif

// USA: func_ov003_0216d84c  (semantic: UpdateFlagByte3ecState_0216d84c)
extern "C" ARM void func_ov003_0216d84c(void* p) {
    char* obj = (char*)p;
    if (!(*(unsigned char*)(obj + 0x1000 + kRegionValue3EC_27C) & 1)) return;
    short state = *(short*)(obj + 8);
    if (state == 0) {
        FontBankLoader* g = GetGlobal02109400_02094a00();
        BlankFunction02094b34(g, 0x1f5, 0x66, 0, 0);
        *(short*)(obj + 8) = 1;
    } else if (state == 1) {
        if (AlwaysTrue02094b4c(GetGlobal02109400_02094a00()) != 0) {
            *(unsigned char*)(obj + 0x1000 + kRegionValue3EC_27C) &= ~1;
            *(short*)(obj + 8) = -1;
        }
    }
}
