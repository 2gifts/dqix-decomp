#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned int _Z34SetField0x1b2IfMatchOrFlag02053f7cP11Obj02053f7csi(unsigned int, unsigned int, unsigned int);

struct Evt021cbeec {
    unsigned char pad0[4];
    signed char member;
    unsigned char pad5;
    unsigned short value;
};

// USA: func_ov017_021cbeec  (semantic: Trans_021cbeec)
extern "C" ARM void func_ov017_021cbeec(int unused0, Evt021cbeec* evt, GameState* gameState, unsigned char* base) {
    unsigned int member = (unsigned int)gameState->GetPartyMemberByIndex(evt->member);
    if (member != 0) {
        _Z34SetField0x1b2IfMatchOrFlag02053f7cP11Obj02053f7csi(member, evt->value, 1);
    }
}
