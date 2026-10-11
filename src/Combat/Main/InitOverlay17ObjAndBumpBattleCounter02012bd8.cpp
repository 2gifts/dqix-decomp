#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "Resource/GameResources.h"
#include "System/OverlayId.h"

extern "C" int _Z27IsIndexMappedToSelf020a18f4j(unsigned int idx);
extern char data_027e0000;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_02012bd8
ARM void InitOverlay17ObjAndBumpBattleCounter02012bd8() {
    if (_Z27IsIndexMappedToSelf020a18f4j(OVERLAY_ID(17))) {
        func_ov017_0218b5b0();
        if (func_ov017_0218b5b0() != NULL) {
            ApplyBrightness(func_ov017_0218b5b0());
        }
    }
    (*(int*)((char*)GameState::GetInstance() + 0x3c8))++;
    *(unsigned int*)((char*)&data_027e0000 + 0x3ff8) |= 1;
}

// JPN: 0x020129a0
