#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "System/OverlayId.h"

#if defined(jpn)
#define func_ov000_02160da0 func_ov000_02162508
#endif

extern int data_ov000_02184220;

struct BattleWork {
#if defined(jpn)
    char unknown0[0xe24];
#else
    char unknown0[0xea8];
#endif
    int state;
    int substate;
#if defined(jpn)
    char unknownE2c[0x7920 - 0xe2c];
#else
    char unknownEb0[0x7730 - 0xeb0];
#endif
    short overlayLoadTask;
};

// USA: func_ov000_02160da0
extern "C" ARM void func_ov000_02160da0(BattleWork* battle) {
    battle->state = 0x12;
    battle->substate = 0;
    data_ov000_02184220 = 1;
    battle->overlayLoadTask = BackgroundLoader::GetInstance()->QueueLoadOverlay(OVERLAY_ID(24));
}
