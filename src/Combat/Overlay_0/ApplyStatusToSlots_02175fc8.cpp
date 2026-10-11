#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x8b4
#define REGION_OFFSET_1 0x483
#else
#define REGION_OFFSET_0 0x94c
#define REGION_OFFSET_1 0x443
#endif

#include "GameState/GameState.h"

extern "C" void* func_ov000_02161318(void* obj, int index);
GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);

// USA: func_ov000_02175fc8  (semantic: ApplyStatusToSlots_02175fc8)
extern "C" ARM void func_ov000_02175fc8(void* obj) {
    char* e;
    int i;
    for (i = 0; i < 4; i++) {
        e = (char*)func_ov000_02161318(obj, i);
        if (e == NULL) continue;
        GameState* bs = GameState::GetInstance();
        GameObject* c = GetCombatantWithFlag0x100(bs, *(int*)(e + 0x4c));
        if (c == NULL) continue;
        int* p = *(int**)((char*)c + 0x130);
        if (*p & 4) {
            *(int*)(e + 0x28) |= 4;
        }
        int val150 = GetFieldAt0x150((unsigned char*)c);
        if (val150 != 0) {
            *(unsigned char*)(e + REGION_OFFSET_1) = (unsigned char)*(int*)(val150 + REGION_OFFSET_0);
        }
    }
}
