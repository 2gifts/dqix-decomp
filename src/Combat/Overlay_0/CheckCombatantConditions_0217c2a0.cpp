#include <globaldefs.h>
#include "GameState/GameState.h"

struct Outer_02054000;
void* GetActiveSub_02054000(struct Outer_02054000* p);
extern "C" int func_ov000_0217538c(void* objRaw);

struct Data0217c2a0 {
#if defined(jpn)
    void* field8;
    int field0;
    int field4;
#else
    int field0;
    int field4;
    void* field8;
#endif
};
extern Data0217c2a0 data_ov000_02184294;

// USA: func_ov000_0217c2a0  (semantic: CheckCombatantConditions_0217c2a0)
extern "C" ARM int func_ov000_0217c2a0(void* objRaw) {
    char* obj = (char*)objRaw;
    int result = 0;
    GameState* battleStruct = GameState::GetInstance();
    int combId = *(int*)(obj + 0x4c);
    GameObject* combatant = GetCombatantWithFlag0x100(battleStruct, combId);
    if (combatant != 0) {
        void* sub = GetActiveSub_02054000((struct Outer_02054000*)combatant);
        if (sub != 0) {
            short val = *(short*)((char*)sub + 0x18);
            if (val > 0) {
                struct Bits02f4 { unsigned int bit0 : 1; unsigned int bit1 : 1; unsigned int hi : 30; };
#if defined(jpn)
                enum { extraOffset = 0x144 };
#else
                enum { extraOffset = 0x150 };
#endif
                struct Bits02f4* bits = (struct Bits02f4*)(*(int*)((char*)combatant + extraOffset) + 0x2f4);
                if (bits->bit1) {
                    result = 1;
                } else {
                    if (bits->bit0) {
                        if (func_ov000_0217538c(data_ov000_02184294.field8) == 1) {
                            result = 1;
                        }
                    }
                }
            }
        }
        if (data_ov000_02184294.field0 == 1) {
            result = 1;
        }
    }
    return result;
}
