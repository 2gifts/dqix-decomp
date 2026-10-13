#include <globaldefs.h>
#include "Graphics/LightingManager.h"

struct LightingFadeCommand {
    char unknown0[8];
    fix16_t targetBrightness;
    unsigned short duration;
};
struct CombatLightingWork {
#if defined(jpn)
    char unknown0[0x71c4];
#else
    char unknown0[0x6fd4];
#endif
    unsigned char lightingFadeStarted;
};
#if defined(jpn)
#define func_ov025_021e74f4 func_ov025_021e79a4
#endif
CombatLightingWork* GetActiveCombatWork();

// USA: func_ov025_021e74f4
extern "C" ARM int func_ov025_021e74f4(LightingFadeCommand* command) {
    LightingManager::GetInstance()->BeginFade(command->targetBrightness, command->duration);
    GetActiveCombatWork()->lightingFadeStarted = 1;
    return 1;
}
