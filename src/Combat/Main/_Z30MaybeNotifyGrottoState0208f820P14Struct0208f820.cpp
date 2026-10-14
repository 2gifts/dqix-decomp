#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"

extern "C" void* func_02012fe4(void* unused);

struct Struct0208f820 {
    unsigned char pad_00[8];
    unsigned char pad_08[0xac];
    unsigned char flagB4;
    unsigned char flagB5;
    unsigned char flagB6;
};

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0208f820
ARM void MaybeNotifyGrottoState0208f820(struct Struct0208f820* p) {
    if (p->flagB4 != 0 && p->flagB6 != 0) {
        if (((Object3D*)((unsigned char*)p + 8))->IsVisible() == 0) {
            return;
        }
        GameState* battle = GameState::GetInstance();
        GrottoStruct* grotto = battle->GetGrottoStruct();
        unsigned short val = *(unsigned short*)func_02012fe4(grotto);
        if (val != *(int*)((char*)grotto + 0xc)) {
            return;
        }
        ((Object3D*)((unsigned char*)p + 8))->Draw(1);
    }
}
