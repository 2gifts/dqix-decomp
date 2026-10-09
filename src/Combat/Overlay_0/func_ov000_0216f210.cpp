#include <globaldefs.h>
#include <Graphics/Vector.h>

struct PositionedObject0216f210 {
    int field_0x0;
    Vector3fix position;
};

// USA: func_ov000_0216f210
extern "C" ARM fix32_t func_ov000_0216f210(PositionedObject0216f210* obj, fix32_t* outDistance) {
    Vector3fix pos = obj->position;
    pos.y = 0;
    fix32_t dist = Vector3fix_Length(&pos);
    *outDistance = dist;
    if (dist < 0x8000) {
        return 0;
    }
    if (dist > 0x11000) {
        dist = 0x11000;
    }
    fix32_t t = fix32_Divide(dist - 0x8000, 0x9000);
    fix32_t scale = 0x1000 - fix32cos(FIX32_MULTIPLY(t, 0x1922));
    if (scale < 0) {
        scale = 0;
    }
    return FIX32_MULTIPLY(scale, 0x5000);
}
