#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

struct Battle0218db14 {
#if defined(jpn)
    unsigned char pad0[0x4188];
#else
    unsigned char pad0[0x4438];
#endif
    Vector3fix refDir;
};

// JPN: func_ov017_0218e6f4
// USA: func_ov017_0218db14
extern "C" ARM int func_ov017_0218db14(struct Battle0218db14* battle, const Vector3fix* dir, int scale, int threshold, unsigned char force) {
    GameObject* obj = GameState::GetInstance()->GetUnknownGameObject();
    if (obj == NULL) {
        return 0;
    }
    short* angle = (short*)((char*)obj + 0xb2);
    int value = *angle;
    value = (int)(((long long)value * scale + 0x800) >> 12);
    if (force) {
        *angle = value;
        return 1;
    }
    Vector3fix norm;
    Vector3fix_Normalize(dir, &norm);
    if (Vector3fix_InnerProduct(&norm, &battle->refDir) <= threshold) {
        *angle = value;
        return 1;
    }
    return 0;
}
