#include <globaldefs.h>
#include "GameState/GameState.h"

int RegisterSlotA020cf0fc(int a);
extern "C" void func_ov017_021d6134(void* obj, int v);

struct Flags69c_021e9a9c {
    unsigned int pad0 : 12;
    unsigned int field1 : 4;
    unsigned int field2 : 5;
    unsigned int pad1 : 11;
};

// JPN: func_ov023_021e9a00
// USA: func_ov023_021e9a9c
ARM int CheckSlotMatchesBitfield_021e9a9c(void* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x43c};
#else
 enum {regionalOffset0=0x69c};
#endif
    void* bs = GameState::GetInstance();
    int buf[4];
    RegisterSlotA020cf0fc((int)buf);

    Flags69c_021e9a9c* flags = (Flags69c_021e9a9c*)((char*)bs + 0x5000 + regionalOffset0);

    if (buf[1] == (int)flags->field1 && buf[2] == (int)flags->field2) {
        func_ov017_021d6134(obj, 1);
    } else {
        func_ov017_021d6134(obj, 0);
    }
    return 1;
}
