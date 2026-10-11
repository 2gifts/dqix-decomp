#include <globaldefs.h>
#if defined(jpn)
enum { kIdsOffset = 0x6ac, kCountOffset = 0x6b0, kMaskOffset = 0x6b1 };
#else
enum { kIdsOffset = 0x758, kCountOffset = 0x75c, kMaskOffset = 0x75d };
#endif
#include "GameState/GameState.h"

extern "C" void func_0203bd08(void);
int GetFieldAt0x150(unsigned char* obj);
void SubmitFlag0x800CombatantDataA0201fca0(void* p0, void* p1, int combatantId);
void SubmitFlag0x800CombatantDataB0201fd38(void* p0, void* p1, int combatantId);
void SetElementFields0202756c(void* obj, int p1, int p2, int idx,
        unsigned char p5, unsigned char p6, unsigned short p7, unsigned char p8, int p9, int p10);
extern int data_020fdc60;
extern int data_020fdcb0;

// USA: func_02027100
ARM void ProcessCombatantElements02027100(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    func_0203bd08();
    ((int)func_ov017_0218b5b0());
    for (int i = 0; i < obj[kCountOffset]; i++) {
        unsigned char* p = obj + i;
        int id = p[kIdsOffset];
        if (obj[kMaskOffset] & (1 << id)) {
            continue;
        }
        GameObject* combatant = GetCombatantWithFlag0x100(battle, id);
        if (combatant == NULL) {
            continue;
        }
        if (GetFieldAt0x150((unsigned char*)combatant) == 0) {
            continue;
        }
        if (*(int*)((char*)&data_020fdcb0 + (id << 5)) < 0) {
            continue;
        }
        SubmitFlag0x800CombatantDataA0201fca0((char*)&data_020fdc60 + i * 0x14, (void*)i, id);
        SubmitFlag0x800CombatantDataB0201fd38((char*)&data_020fdc60 + i * 0x14, (void*)i, id);
        int fx = (int)(*(float*)((char*)&data_020fdc60 + i * 0x14 + 0x10));
        SetElementFields0202756c(obj, i << 18, fx << 12, (id + 1) & 0xff,
            (id + 0x3c) & 0xff, 0, (unsigned short)id, 0xff, 0x1000, 0x1000);
    }
}
