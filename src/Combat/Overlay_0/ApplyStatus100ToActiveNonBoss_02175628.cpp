#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetPtrField0x2a04(GameState* battleStruct);
void* GetFieldAt0x150(unsigned char* obj);
extern "C" void* func_ov000_02161318(void* obj, int id);

// USA: func_ov000_02175628  (semantic: ApplyStatus100ToActiveNonBoss_02175628)
extern "C" ARM void func_ov000_02175628(void* obj) {
    GameState* battleStruct = GameState::GetInstance();
    unsigned char* field2a04 = (unsigned char*)GetPtrField0x2a04(battleStruct);
    unsigned char count = field2a04[0xf7c];
    unsigned char i;
    for (i = 0; i < count; i++) {
        signed char combIdx = *(signed char*)(field2a04 + i + 0xf00 + 0x78);
        GameObject* combatant = battleStruct->GetPartyMemberByIndex(combIdx);
        if (combatant == 0) {
            continue;
        }
        void* p = GetFieldAt0x150((unsigned char*)combatant);
#if defined(jpn)
        enum { statusOffset = 0x8b4 };
#else
        enum { statusOffset = 0x94c };
#endif
        signed char statusVal = (signed char)*(int*)((char*)p + statusOffset);
        if (statusVal == 5) {
            continue;
        }
        char* entry = (char*)func_ov000_02161318(obj, combIdx);
        if (entry) {
            signed char off = *(signed char*)(entry + 0x18);
            *(entry + off + 0x10) = 0x64;
        }
    }
}
