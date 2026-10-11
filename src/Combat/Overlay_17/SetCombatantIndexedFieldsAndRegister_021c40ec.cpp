// JPN: func_ov017_021c45b4
#if defined(jpn)
enum { RegionOffset3734 = 0x3524, RegionOffset180 = 0x17c };
#else
enum { RegionOffset3734 = 0x3734, RegionOffset180 = 0x180 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern void* GetPtrField0x2a04(GameState* battleStruct);
GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
extern "C" void func_02052d7c(void* obj, int index, short value);
extern "C" void func_ov017_0218f5a4(void* self, int combatantId, int flag2, int flag3, int flag4);

struct Info_021c40ec {
    char pad0[4];
    unsigned char idNibble : 4;
    unsigned char bit4 : 1;
    signed char arr1[5];
    short arr2[5];
};

// USA: func_ov017_021c40ec  (semantic: SetCombatantIndexedFieldsAndRegister_021c40ec)
extern "C" ARM void func_ov017_021c40ec(void* unused, struct Info_021c40ec* info, GameState* battleStruct, void* ov) {
    int id = info->idNibble;
    char* p = (char*)GetPtrField0x2a04(battleStruct);
    if (p != NULL) {
        int i;
        for (i = 0; i < *(unsigned char*)(p + 0xf7c); i++) {
            if (*(unsigned char*)(p + i + 0xf78) == id) return;
        }
    }

    GameObject* combatant = GetCombatantWithFlag0x100(battleStruct, id);
    if (combatant == NULL) return;

    char* s = *(char**)((char*)ov + RegionOffset3734);

    int j;
    for (j = 0; j < 5; j++) {
        int elemId = info->arr1[j];
        int value = info->arr2[j];
        if (elemId >= 0 && elemId < 0xa) {
            func_02052d7c(combatant, elemId, value);
        }
        if (*(unsigned char*)(s + 3) != 0) {
            if (id == 0 && elemId == 6) {
                signed char v = *(signed char*)(s + RegionOffset180);
                if (v < 0) {
                    *(unsigned char*)(s + RegionOffset180) = 6;
                }
            }
        }
    }

    if (info->bit4) {
        func_ov017_0218f5a4(ov, id, 0, 0, 0);
    }
}
