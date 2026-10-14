#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int _ZN7Model3D7GetTEX0Ev(void* obj);
void DelayThenSyncBit0(void);
void StageTexFilePaletteData(NSBXXTex volatile*, bool);
struct NSBXXTex;
void StageTexFileImageData(NSBXXTex volatile*, bool);

struct SlotIdTable_0218f80c {
    int v[12];
};
extern struct SlotIdTable_0218f80c data_ov017_021d61fc;

// USA: func_ov017_0218f80c
extern "C" ARM void func_ov017_0218f80c(void* obj, int idx) {
    volatile unsigned short* dispstat = (volatile unsigned short*)0x4000004;
    if ((*dispstat & 1) == 0) {
        DelayThenSyncBit0();
    }

    GameState* battleStruct = GameState::GetInstance();

    struct SlotIdTable_0218f80c table = data_ov017_021d61fc;
    int base = idx * 12;
    table.v[0] = idx;
    table.v[1] = base + 0x13;
    table.v[2] = base + 0x14;
    table.v[3] = base + 0x16;
    table.v[4] = base + 0x17;
    table.v[5] = base + 0x18;
    table.v[6] = base + 0x19;
    table.v[7] = base + 0x1a;
    table.v[8] = base + 0x1b;
    table.v[9] = base + 0x1c;
    table.v[10] = base + 0x1d;

    int i;
    for (i = 0; table.v[i] > -1; i++) {
        GameObject* combatant = battleStruct->GetGameObjectByIndex(table.v[i]);
        if (combatant == NULL) {
            continue;
        }
        if (*(short*)((char*)combatant + 0x2) <= -1) {
            continue;
        }
        void* ptr = *(void**)((char*)combatant + 0x8);
        if (ptr == NULL) {
            continue;
        }
        int field58 = _ZN7Model3D7GetTEX0Ev(ptr);
        if (field58 == 0) {
            continue;
        }
        StageTexFilePaletteData((NSBXXTex volatile*)field58, 0);
        StageTexFileImageData((NSBXXTex volatile*)field58, 0);
    }
}
