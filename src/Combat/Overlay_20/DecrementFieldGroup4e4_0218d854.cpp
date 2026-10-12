#include <globaldefs.h>

#if defined(jpn)
enum { kTimerOffset = 0x474 };
#else
enum { kTimerOffset = 0x4e4 };
#endif


#if defined(jpn)
#define func_ov020_0218d854 func_ov020_0218e0a4
#endif
#include "GameState/GameState.h"


struct FieldGroup4e4_0218d854 {
    char pad[kTimerOffset];
    int f4e4;
};

// USA: func_ov020_0218d854  (semantic: DecrementFieldGroup4e4_0218d854)
extern "C" ARM void func_ov020_0218d854(struct FieldGroup4e4_0218d854* obj) {
    int delta = GameState::GetInstance()->GetEffectiveDeltaTime();
    int active = obj->f4e4 > 0;
    if (!active) {
        return;
    }
    obj->f4e4 -= delta;
    if (obj->f4e4 <= 0) {
        obj->f4e4 = 0;
    }
}
