#include <globaldefs.h>
#if defined(jpn)
enum { kMask = 8 };
enum { kTailOffset = 0x72be };
#else
enum { kMask = 0x48 };
enum { kTailOffset = 0x74fe };
#endif

#include "GameState/GameState.h"

// USA: func_0202c410
ARM void CopyBattleTailToObjField0x102c(void* obj) {
    *((unsigned char*)obj + 0x1029) |= kMask;
    GameState* battleStruct = GameState::GetInstance();
    unsigned char buf[6];
    unsigned char* dst = buf;
    unsigned char* src = (unsigned char*)battleStruct + kTailOffset;
    int n = 6;
    do {
        unsigned char* d = dst++;
        unsigned char t = *src++;
        *d = t;
    } while (--n);
    dst = (unsigned char*)obj + 0x102c;
    src = buf;
    n = 6;
    do {
        unsigned char* d = dst++;
        unsigned char t = *src++;
        *d = t;
    } while (--n);
}
