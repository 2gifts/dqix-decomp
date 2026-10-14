#include <globaldefs.h>
#include "GameState/GameState.h"

void SetBits0x40000AndFlag0x2_02033fec(unsigned char* obj);
void ClearStateFlags0203400c(unsigned char* obj);
int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);

struct Param021e7520 {
    char pad[8];
    unsigned short field8;
    unsigned short pad2;
    int field_c;
};

// USA: func_ov025_021e7520
ARM int DispatchAndUpdateFlag_021e7520(struct Param021e7520* p, int unused, int unusedR2, void* obj) {
    GameState* bs = GameState::GetInstance();
    int ids[8];
    int count = DispatchByIndex021820bc(obj, unused, p->field8, (int)&ids[0]);
    for (int i = 0; i < count; i++) {
        GameObject* c = bs->GetMaybeWanderingMonsterByIndex(ids[i]);
        if (c) {
            if (p->field_c != 0) {
                SetBits0x40000AndFlag0x2_02033fec((unsigned char*)c);
            } else {
                ClearStateFlags0203400c((unsigned char*)c);
            }
        }
    }
    return 1;
}
