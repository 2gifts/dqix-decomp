#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021cdaa0 {
    float valA;
};

struct LocalEvt021cdaa0 {
    unsigned char tag;
    unsigned char pad0[3];
    Sub021cdaa0 sub;
    unsigned char pad2[12];
};

// USA: func_ov017_021cdaa0
ARM void EnqueueEventTag147_021cdaa0(void) {
    GameState* battleStruct = GameState::GetInstance();
    LocalEvt021cdaa0 buf;
    void* p = GetData02100044_0202ae24();
    buf.tag = 0x93;
    Sub021cdaa0* s = &buf.sub;
    s->valA = battleStruct->GetDayTimer();
    func_0205e330(p, &buf, 0);
}
