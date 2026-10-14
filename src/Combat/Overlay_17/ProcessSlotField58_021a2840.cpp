#include <globaldefs.h>
#include "GameState/GameState.h"

struct GameResources;
extern "C" int _ZN7Model3D7GetTEX0Ev(void* obj);
void StageTexFilePaletteData(NSBXXTex volatile*, bool);
struct NSBXXTex;
void StageTexFileImageData(NSBXXTex volatile*, bool);

// USA: func_ov017_021a2840
ARM void ProcessSlotField58_021a2840(GameResources*) {
    GameState* battleStruct = GameState::GetInstance();

    int i;
    for (i = 0; i < 0xc; i++) {
        GameObject* combatant = battleStruct->GetGameObjectByIndex(i + 7);
        if (combatant == NULL) {
            continue;
        }

        void* ptr = *(void**)((char*)combatant + 0x8);
        if (ptr == NULL) {
            continue;
        }

        int field58 = _ZN7Model3D7GetTEX0Ev(ptr);
        if (field58 != 0) {
            StageTexFilePaletteData((NSBXXTex volatile*)field58, 0);
            StageTexFileImageData((NSBXXTex volatile*)field58, 0);
        }
    }
}
