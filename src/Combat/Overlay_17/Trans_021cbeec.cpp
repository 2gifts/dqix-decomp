#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" unsigned int _Z34SetField0x1b2IfMatchOrFlag02053f7cP11Obj02053f7csi(unsigned int, unsigned int, unsigned int);

// USA: func_ov017_021cbeec  (semantic: Trans_021cbeec)
extern "C" ARM unsigned int func_ov017_021cbeec(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int member = (unsigned int)((GameState*)r2)->GetPartyMemberByIndex(*(signed char*)((char*)r1 + 0x4));
    if (member != 0) {
        member = _Z34SetField0x1b2IfMatchOrFlag02053f7cP11Obj02053f7csi(member, *(unsigned short*)((char*)r1 + 0x6), 1);
    }
    return member;
}
