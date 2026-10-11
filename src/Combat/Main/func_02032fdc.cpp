#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Flags0xc4_02032fdc {
    unsigned short low : 15;
    unsigned short hi : 1;
};

struct ScaledObject : Object3D {
    char pad_ac[0xe];
    short field_ba;
    unsigned short field_bc;
    char pad_be[6];
    struct Flags0xc4_02032fdc flagsC4;
    char pad_c6[0x5e];
    int field_124;
};

extern int data_0210a05c[];

// USA: func_02032fdc
extern "C" ARM bool func_02032fdc(ScaledObject* obj, bool applyClipping, Vector3fix* out) {
    int scale;
    int savedY;
    unsigned int lowFlags = obj->flagsC4.low;
    int hasLow = lowFlags != 0;
    savedY = obj->position_.y;
    if (hasLow) {
        scale = 0x1000;
        if (lowFlags > 0x1324) {
            scale = (int)(4096.0f * ((float)(int)(0x1388 - lowFlags) / 100.0f));
        } else if (lowFlags < 100) {
            scale = (int)(4096.0f * ((float)lowFlags / 100.0f));
        }
        Vector3fix tmp = obj->position_;
        int twice = (obj->GetHeight() / 3) * 2;
        scale = (int)((((long long)twice) * scale + 0x800) >> 12);
        tmp.y -= scale;
        obj->position_ = tmp;
    }
    if (obj->field_124 != 0) {
        Vector3fix tmp = obj->position_;
        tmp.y = obj->field_124;
        obj->position_ = tmp;
    }
    bool result;
    if (obj->field_bc != 0) {
        GameState* gs = GameState::GetInstance();
        unsigned int dt = gs->GetEffectiveDeltaTime();
        Vector3fix v = {data_0210a05c[0], data_0210a05c[3], data_0210a05c[6]};
        Vector3fixMultiplyScalar(&v, obj->field_ba, &v);
        Vector3fix w;
        Vector3fix_Add(&obj->position_, &v, &w);
        obj->position_ = w;
        if (out) *out = w;
        result = obj->Draw(applyClipping);
        obj->position_ = obj->position_;
        if (obj->field_bc < dt) {
            obj->field_bc = 0;
            obj->field_ba = 0;
        } else {
            short absBa = (short)fix32abs(obj->field_ba);
            float f = (float)dt * (((float)absBa / 4096.0f) / (float)obj->field_bc);
            int dec = (int)(4096.0f * f);
            short mag = (short)(absBa - dec);
            if (obj->field_ba > 0) {
                obj->field_ba = -mag;
            } else {
                obj->field_ba = mag;
            }
            obj->field_bc = obj->field_bc - dt;
        }
    } else {
        result = obj->Draw(applyClipping);
        if (out) *out = obj->position_;
    }
    int stillLow = obj->flagsC4.low != 0;
    if (stillLow || obj->field_124 != 0) {
        Vector3fix tmp = obj->position_;
        tmp.y = savedY;
        obj->position_ = tmp;
    }
    return result;
}
