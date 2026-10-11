#include <globaldefs.h>
#if defined(jpn)
enum { timerOffset = 0x792c, counterOffset = 0x7930 };
#else
enum { timerOffset = 0x773c, counterOffset = 0x7740 };
#endif
#include "GameState/GameState.h"

extern "C" void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* obj, void* member, int arg3);
extern char data_ov000_021838df[];

// USA: func_ov000_02163928  (semantic: TickTimers02163928)
extern "C" ARM void func_ov000_02163928(char* obj) {
    GameState* battle = GameState::GetInstance();
    int i;
    for (i = 0; i < 4; i++) {
        signed char timerId = *(signed char*)(obj + timerOffset + i);
        if (timerId < 0) continue;
        int counter = *(unsigned char*)(obj + counterOffset + i);
        counter--;
        if (counter <= 0) {
            *(signed char*)(obj + timerOffset + i) = -1;
            GameObject* c = GetCombatantWithFlag0x100(battle, timerId);
            if (c != 0) {
                _ZN8Object3D24MaybeSetRegularAnimationEPKci(c, data_ov000_021838df, 1);
            }
        } else {
            *(unsigned char*)(obj + counterOffset + i) = counter;
        }
    }
}
