#include <globaldefs.h>

#if defined(jpn)
enum { kFlagOffset = 0x5a68, kBufferOffset = 0x6120 };
#else
enum { kFlagOffset = 0x5cc8, kBufferOffset = 0x6380 };
#endif

#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" int func_02075910(int a0, void* out, int a1, int a2);
extern "C" int func_01ff85b8(void* buf, int size);
extern "C" void func_02075acc(int id, void* buf, int size, int flag);
struct StateBits5ccc_11544;
extern void SetFlag0x5cccBit0(StateBits5ccc_11544* state);

struct Buf020ac7b4 {
    int hdr;
    char data[0x5c];
};

// USA: func_020ac7b4
ARM int SendBattleSaveBufferOrSetFlag020ac7b4(int flag) {
    GameState* bs = GameState::GetInstance();
    int local0;
    if (!func_02075910(0, &local0, 1, 0)) {
        *(unsigned char*)((char*)bs + kFlagOffset) = 1;
        SetFlag0x5cccBit0((StateBits5ccc_11544*)bs);
        return 0;
    }

    struct Buf020ac7b4 buf;
    memset(&buf, 0, 0x60);
    memcpy(&buf, (char*)bs + kBufferOffset, 0x54);
    buf.hdr = func_01ff85b8((char*)&buf + 4, 0x5c);
    func_02075acc(flag ? 0x8024 : 0x24, &buf, 0x60, 0);
    return 1;
}
