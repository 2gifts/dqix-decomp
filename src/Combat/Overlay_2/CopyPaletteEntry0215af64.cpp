#include <globaldefs.h>
#include "std_library_functions.h"
#include "System/Cache.h"

extern void* GetData02109dcc_020a6084(void);
extern "C" int LoadToMainObjStandardPalette(int arg0, int arg1, unsigned int arg2);

// USA: func_ov002_0215af64
ARM void CopyPaletteEntry0215af64(char* p) {
    short idx = *(short*)(p + 0x1c00 + 0x6);
    void* buf = *(void**)(p + 0x1000 + 0xbd8);
    unsigned char idxb = (unsigned char)idx;
    int base = (int)GetData02109dcc_020a6084();
    memcpy(buf, (void*)(base + (idxb << 5) + 0x1e), 2);
    CleanInvalidateCacheRange(buf, 2);
    LoadToMainObjStandardPalette((int)buf, 0x11e, 2);
}
