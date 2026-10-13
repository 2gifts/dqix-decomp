#include <globaldefs.h>

#if defined(jpn)
enum { kTimerOffset = 0x474 };
#else
enum { kTimerOffset = 0x4e4 };
#endif

#include "GameState/GameState.h"

struct FieldGroup4e4_0218d854 {
    char pad[kTimerOffset];
    int remainingMilliseconds;

    int IsTimerActive() const { return remainingMilliseconds > 0; }
};

// USA: func_ov020_0218d854  (semantic: DecrementFieldGroup4e4_0218d854)
extern "C" ARM void func_ov020_0218d854(struct FieldGroup4e4_0218d854* obj) {
    int elapsedMilliseconds = GameState::GetInstance()->GetEffectiveDeltaTime();
    if (!obj->IsTimerActive()) {
        return;
    }
    obj->remainingMilliseconds -= elapsedMilliseconds;
    if (obj->remainingMilliseconds <= 0) {
        obj->remainingMilliseconds = 0;
    }
}
