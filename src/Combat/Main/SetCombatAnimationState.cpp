#include <globaldefs.h>

#include <World/Object3D.h>

struct AnimationFlags {
    int values[12];
};

struct AnimationStateRemap {
    signed char values[12];
};

struct IdleAnimationMap {
    unsigned char values[2][7];
};

extern const AnimationFlags data_020e77cc;
extern const AnimationStateRemap data_020e77b0;
extern const IdleAnimationMap data_020e77bc;
extern const char *const data_020ef978[7];
extern const char data_020efa40[];
extern const char *const data_020ef994[12];

struct CombatAnimationPrefix {
    Object3D object;
    unsigned char unknown_ac[0xc0 - 0xac];
    unsigned char currentState;
    unsigned char modeFlags : 4;
    unsigned char mode : 4;
    unsigned char unknown_c2[0xe0 - 0xc2];
    unsigned char flag0 : 1;
    unsigned char enableObjectFlag18 : 1;
};

// USA: func_02033ba0
extern "C" ARM void func_02033ba0(void *receiver, int value) {
    CombatAnimationPrefix *state = static_cast<CombatAnimationPrefix *>(receiver);
    if (value < 0) {
        return;
    }
    AnimationFlags flags      = data_020e77cc;
    AnimationStateRemap remap = data_020e77b0;
    if (value == 0) {
        unsigned int mode = state->mode;
        if (mode < 7) {
            IdleAnimationMap idle = data_020e77bc;
            int row               = 0;
            if (state->object.unknown_4_ >= 0xc0 && state->object.unknown_4_ <= 0xc7) {
                row = 1;
            }
            if (!state->object.MaybeSetRegularAnimation(data_020ef978[idle.values[row][mode]], 0x10)) {
                state->object.MaybeSetRegularAnimation(data_020efa40, 0);
            }
            if (state->enableObjectFlag18) {
                state->object.EnableFlag(0x40000);
            }
        }
    } else {
        state->object.MaybeSetRegularAnimation(data_020ef994[value], flags.values[value]);
        int mappedState = remap.values[value];
        if (mappedState > -1) {
            value = mappedState;
        }
    }
    state->currentState = value;
}
