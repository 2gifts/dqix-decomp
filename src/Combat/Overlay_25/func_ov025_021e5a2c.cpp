#include <globaldefs.h>

#if defined(jpn)
enum { kWorkFlagBase = 0x7000, kWorkFlagOffset = 0x1c5 };
#else
enum { kWorkFlagBase = 0x6000, kWorkFlagOffset = 0xfd5 };
#endif


#if defined(jpn)
#endif
#include "GameState/GameState.h"

struct CombatCameraWork {
    char unknown0[kWorkFlagBase + kWorkFlagOffset];
    unsigned char cameraUpdated;
};
struct CameraState {
    int unknown0;
    Vector3i vector;
};
struct VectorCommand {
    char unknown0[8];
    Vector3i vector;
};
CombatCameraWork* GetActiveCombatWork(void);
CameraState* GetField0x3b0Value(GameState* battleStruct);

// USA: func_ov025_021e5a2c
extern "C" ARM int func_ov025_021e5a2c(VectorCommand* command) {
    GameState* bs = GameState::GetInstance();
    CameraState* f = GetField0x3b0Value(bs);
    if (f != 0) {
        f->vector = command->vector;
    }
    CombatCameraWork* w = GetActiveCombatWork();
    if (w) {
        w->cameraUpdated = 1;
    }
    return 1;
}
