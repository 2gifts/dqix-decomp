#include <globaldefs.h>
#include "GameState/GameState.h"

void* FindRecordByShortField020108f0(void* obj, int value);
void* FindSlotWithNegShort02010954(char* base);
void SetPointerFields02053c4c(char* obj, char* p);
extern "C" void func_020c9be0(void);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_02053c74
ARM void RegisterOrAllocateCombatant02053c74(char* obj, int idx) {
    GameState* bs = GameState::GetInstance();
    char* rec = (char*)FindRecordByShortField020108f0(bs, idx);
    if (!rec) {
        rec = (char*)FindSlotWithNegShort02010954((char*)bs);
        if (rec) {
            *(short*)(rec + 0x568) = idx;
        } else {
            func_020c9be0();
        }
    }
    SetPointerFields02053c4c(obj, rec);
}
