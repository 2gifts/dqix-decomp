#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_02012fe4(void);
extern "C" void* func_0202ae18(void);
struct Entry_02028bd0;
struct Entry_02028bd0* FindEntryInGlobalTable02027ccc(int key);
int CheckField0NonZero(int* obj);
extern "C" int func_0202c508(void* obj);
extern "C" void func_02076a8c(void* obj);
void EnqueueEventTag134_021c9544(int a0, int a1, int a2, int a3);

struct EntryField8_021a33e0 { unsigned char pad0[2]; unsigned short field2 : 2; unsigned short pad3 : 14; };

// USA: func_ov017_021a33e0
ARM void EnqueueEventForFlaggedCombatants_021a33e0(void* unused, int key) {
    GameState* battleStruct = GameState::GetInstance();
    func_02012fe4();
    void* search = func_0202ae18();
    struct Entry_02028bd0* entry = FindEntryInGlobalTable02027ccc(key);
    if (entry == NULL) return;

    *(int*)((char*)entry + 8) = 0;

    int i;
    for (i = 0; i < 0xc; i++) {
        int idx = ((struct EntryField8_021a33e0*)entry)->field2;
        int base = idx * 0xc + 0x70;
        GameObject* combatant = battleStruct->GetMaybeFieldMonsterByIndex(i + base);
        if (combatant) {
            func_02076a8c(combatant);
            ((Object3D*)((unsigned char*)combatant))->MakeHidden();
            if (CheckField0NonZero((int*)search) && func_0202c508(search)) {
                EnqueueEventTag134_021c9544(key, i, *(short*)((char*)combatant + 0x2), -1);
            }
        }
    }
}
