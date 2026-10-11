#include <globaldefs.h>
#include "GameState/GameState.h"

void EncodeSignFlaggedHalfword(short* out, int value);

struct FadeFieldGroups_0218d644 {
#if defined(jpn)
    char pad[0x478];
#else
    char pad[0x4e8];
#endif

    float f4e8;
    int f4ec;
    int f4f0;
    float f4f4;
    int f4f8;
    int f4fc;
};

// JPN: func_ov020_0218de94
// USA: func_ov020_0218d644  (semantic: AdvanceFadeFieldGroups_0218d644)
extern "C" ARM void func_ov020_0218d644(struct FadeFieldGroups_0218d644* obj) {
    int step = GameState::GetInstance()->GetEffectiveDeltaTime();
    int hasFade1 = obj->f4f0 > 0;
    if (hasFade1) {
        obj->f4e8 = obj->f4e8 + (float)step * (((float)obj->f4ec - obj->f4e8) / (float)obj->f4f0);
        obj->f4f0 -= step;
        if (obj->f4f0 <= 0) {
            obj->f4e8 = (float)obj->f4ec;
            obj->f4f0 = 0;
        }
        EncodeSignFlaggedHalfword((short*)0x400006c, (int)obj->f4e8);
    }
    int hasFade2 = obj->f4fc > 0;
    if (!hasFade2) return;
    obj->f4f4 = obj->f4f4 + (float)step * (((float)obj->f4f8 - obj->f4f4) / (float)obj->f4fc);
    obj->f4fc -= step;
    if (obj->f4fc <= 0) {
        obj->f4f4 = (float)obj->f4f8;
        obj->f4fc = 0;
    }
    EncodeSignFlaggedHalfword((short*)0x400106c, (int)obj->f4f4);
}
