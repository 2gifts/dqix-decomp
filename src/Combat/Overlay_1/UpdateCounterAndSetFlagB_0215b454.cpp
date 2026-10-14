#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);
void* GetWord0x0(int*);
struct GameResources;
void SetSubBrightness(GameResources*, int, int);

// USA: func_ov001_0215b454  (semantic: UpdateCounterAndSetFlagB_0215b454)
extern "C" ARM int func_ov001_0215b454(void* self, int mode) {
#if defined(jpn)
    enum { queueOffset = 0x524, flagOffset = 0xfe };
#else
    enum { queueOffset = 0x734, flagOffset = 0x102 };
#endif
    int value;
    int frames = func_ov017_021d60f4(self);
    value = -16;
    if (mode >= 2) {
        value = func_ov017_021d60f4((char*)self + 0x8);
    }
    void* battle = GameState::GetInstance();
    void* obj = GetWord0x0((int*)battle);
    if (obj != NULL) {
        SetSubBrightness((GameResources*)obj, value, frames);
        char* q = *(char**)(((char*)func_ov017_0218b5b0()) + 0x3000 + queueOffset);
        if (*(unsigned short*)(q + 0xa) <= 3) {
            *(unsigned char*)(q + flagOffset) = 1;
        }
    }
    return 1;
}
