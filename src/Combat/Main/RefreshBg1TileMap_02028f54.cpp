#include <globaldefs.h>

#if defined(jpn)
#define func_02028f54 func_020287a4
#endif
#include "std_library_functions.h"

#if defined(jpn)
struct GfxBufferHolder {
    char pad[4];
    void* buffer;
};
extern GfxBufferHolder data_020fe6fc;
#define data_020fe9a4 data_020fe6fc.buffer
#else
extern void* data_020fe9a4;
#endif
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" void LoadToMainBG1ScreenData(int src, int offset, unsigned int size);
extern "C" int LoadToSubBG0ScreenData(int arg0, int arg1, unsigned int arg2);

struct GfxModeState02028f54 {
    char pad[0xc];
    int mode;
};
extern struct GfxModeState02028f54 data_020ef74c;

// USA: func_02028f54  (semantic: RefreshBg1TileMap_02028f54)
extern "C" ARM void func_02028f54(void) {
    if (data_020fe9a4 == 0) {
        return;
    }
    if (data_020fe9a4 != 0) {
        memset(data_020fe9a4, 0, 0x6000);
    }
    unsigned short* p = (unsigned short*)data_020fe9a4;
    unsigned short tile = 0;
    int row;
    int col;
    for (row = 0; row < 0x18; row++) {
        for (col = 0; col < 0x20; col++) {
            *p = tile;
            p++;
            tile++;
        }
    }
    int mode = data_020ef74c.mode;
    CleanInvalidateCacheRange(data_020fe9a4, 0x600);
    if (mode == 3) {
        LoadToMainBG1ScreenData((int)data_020fe9a4, 0, 0x600);
        return;
    }
    if (mode == 4) {
        LoadToSubBG0ScreenData((int)data_020fe9a4, 0, 0x600);
        return;
    }
    if (mode == 5) {
        LoadToMainBG1ScreenData((int)data_020fe9a4, 0, 0x600);
        return;
    }
    if (mode == 6) {
        LoadToSubBG0ScreenData((int)data_020fe9a4, 0, 0x600);
        return;
    }
}
