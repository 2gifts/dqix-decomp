#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct LocalEvt021c8b78 {
    unsigned char tag;
    unsigned char pad0[3];
    unsigned short field4;
    unsigned char pad1[14];
};

// USA: func_ov017_021c8b78
ARM void EnqueueEventTag122_021c8b78(unsigned short param) {
    GameState::GetInstance();
    void* p = GetData02100044_0202ae24();

    LocalEvt021c8b78 buf;
    buf.tag = 0x7a;
    buf.field4 = param;
    func_0205e330(p, &buf, 0);
}
