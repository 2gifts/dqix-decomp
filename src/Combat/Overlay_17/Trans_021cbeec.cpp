#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02053f7c;
unsigned int SetField0x1b2IfMatchOrFlag02053f7c(Obj02053f7c*, unsigned short, int);

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
        SetField0x1b2IfMatchOrFlag02053f7c((Obj02053f7c*)member, evt->value, 1);
    }
}
