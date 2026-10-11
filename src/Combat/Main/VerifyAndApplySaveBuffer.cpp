#include <globaldefs.h>

#if defined(jpn)
enum { kFlagOffset = 0xa68, kBufferOffset = 0x6120 };
#else
enum { kFlagOffset = 0xcc8, kBufferOffset = 0x6380 };
#endif

#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" int func_02075910(int a, void* p, unsigned int size, int c);
extern "C" int func_01ff85b8(void* buf, int size);

struct Buf020ac864 {
    int hdr;
    char data[0x5c];
};

// USA: func_020ac864
ARM int VerifyAndApplySaveBuffer(int flag) {
    GameState* bs = GameState::GetInstance();
    unsigned char* flagAddr = (unsigned char*)bs + 0x5000;
    flagAddr[kFlagOffset] = 0;
    int ok = 1;
    int id = flag ? 0x8024 : 0x24;
    struct Buf020ac864 buf;
    if (!func_02075910(id, &buf, 0x60, 0)) {
        ok = 0;
    }
    if (ok) {
        if (func_01ff85b8((char*)&buf + 4, 0x5c) != buf.hdr) {
            ((unsigned char*)bs + 0x5000)[kFlagOffset] = flag ? 3 : 2;
            ok = 0;
        } else {
            memcpy((char*)bs + kBufferOffset, &buf, 0x54);
        }
    }
    return ok;
}
