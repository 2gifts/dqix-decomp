#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"

int TestFlagMask_02012430(unsigned short* obj, int mask);
void SetField0x238True_020a2794(void* obj);
void SetField0x238False_020a27a0(void* obj);

extern unsigned short data_02114e30;

// USA: func_ov015_021925a8  (semantic: UpdateField238FlagStateC00_021925a8)
extern "C" ARM int func_ov015_021925a8() {
    GameState* battle = GameState::GetInstance();
    if (!battle) return 0;
    void* field = GetField0x3b0Value_020100bc(battle);
    if (!field) return 0;
    if (TestFlagMask_02012430(&data_02114e30, 0xc00)) {
        SetField0x238True_020a2794(field);
        return 1;
    }
    SetField0x238False_020a27a0(field);
    return 0;
}
