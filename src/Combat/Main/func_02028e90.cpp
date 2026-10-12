#include <globaldefs.h>

#if defined(jpn)
#define func_02028e90 func_020286e0
#endif
#include "std_library_functions.h"
#include "System/Cache.h"

extern "C" void LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);
extern "C" void LoadToSubBG0CharacterData(int arg0, int arg1, unsigned int arg2);

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

struct GfxModeState02028e90 {
    char pad[0xc];
    int mode;
};
extern struct GfxModeState02028e90 data_020ef74c;

// USA: func_02028e90  (semantic: FlushBg1TileMapByMode_02028e90)
extern "C" ARM void func_02028e90(void) {
    if (data_020fe9a4 == 0) {
        return;
    }
    if (data_020fe9a4 != 0) {
        memset(data_020fe9a4, 0, 0x6000);
    }
    int mode = data_020ef74c.mode;
    CleanInvalidateCacheRange(data_020fe9a4, 0x6000);
    if (mode == 3) {
        LoadToMainBG1CharacterData((int)data_020fe9a4, 0, 0x6000);
        return;
    }
    if (mode == 4) {
        LoadToSubBG0CharacterData((int)data_020fe9a4, 0, 0x6000);
        return;
    }
    if (mode == 5) {
        LoadToMainBG1CharacterData((int)data_020fe9a4, 0, 0x6000);
        return;
    }
    if (mode == 6) {
        LoadToSubBG0CharacterData((int)data_020fe9a4, 0, 0x6000);
        return;
    }
}
