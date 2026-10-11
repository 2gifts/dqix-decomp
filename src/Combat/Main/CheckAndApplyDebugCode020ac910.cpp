#include <globaldefs.h>
#if defined(jpn)
enum { kRegionalFieldOffset = 0x5a68 };
#else
enum { kRegionalFieldOffset = 0x5cc8 };
#endif

#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" int func_02075910(int a, void* p, unsigned int size, int c);
extern "C" int func_02075acc(int a, void* p, unsigned int size, int c);
extern "C" void func_020abb64(void);
struct StateBits5ccc_11544;
extern void SetFlag0x5cccBit0(StateBits5ccc_11544* state);
extern char data_020f1bf8[];

// USA: func_020ac910
ARM int CheckAndApplyDebugCode020ac910() {
    char buf[0x10];
    memset(buf, 0, 0x10);
    int result = func_02075910(0, buf, 0x10, 0);
    if (result == 0) {
        GameState* bs = GameState::GetInstance();
        *(unsigned char*)((char*)bs + kRegionalFieldOffset) = 0;
        SetFlag0x5cccBit0((StateBits5ccc_11544*)bs);
        return 0;
    }
    if (strcmp(buf, data_020f1bf8) != 0) {
        func_020abb64();
        memcpy(buf, data_020f1bf8, 0x10);
        func_02075acc(0, buf, 0x10, 0);
    }
    return 1;
}
