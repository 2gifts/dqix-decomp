#include "Resource/Brightness.h"
#include <globaldefs.h>

struct FlagWord02046708;
struct List0209497c;
struct List020949bc;
struct Obj020235c8;
struct AxisFloats0203b5a0;
struct AxisFloats0203b5f8;
struct ScrollState02027438;

extern "C" void *_Z27GetDataPtr02114e04_020d6c00v();
extern "C" int _Z17TestFlags02046708P16FlagWord02046708j(FlagWord02046708 *flags, unsigned int mask);
int *GetGlobal02109030();
extern "C" int _Z22ListContainsId0209497cP12List0209497ci(List0209497c *list, int key);
extern "C" int _Z22ListContainsId020949bcP12List020949bci(List020949bc *list, int key);
void MoveValue3cbTo3cc(char *list);
void MoveValue3ccTo3cb(char *list);
extern "C" int func_020e0a78(void *receiver);
extern "C" void func_020e0f74(void *receiver);
extern "C" void func_02026f34(void *receiver);
extern "C" void _Z29ProcessCombatantState020235c8P11Obj020235c8(Obj020235c8 *receiver);
int IsAxisIntWithin16(AxisFloats0203b5a0 *resources, int axis);
extern "C" int _Z26IsChannelValueZero0203b5e0Pvi(void *resources, int axis);
int IsAxisIntZero(AxisFloats0203b5f8 *resources, int axis);
extern "C" void func_02027438(ScrollState02027438 *receiver);

struct CombatUpdateReceiverView {
    unsigned char unknown0[0x764];
    unsigned char field764;
    unsigned char unknown765[0x778 - 0x765];
    unsigned char field778;
    unsigned char unknown779[0x9c2 - 0x779];
    signed char loadState;
    unsigned char field9c3;
    unsigned char brightnessPending;
    unsigned char unknown9c5;
    unsigned char field9c6;
    unsigned char field9c7;
    unsigned char brightnessDelay;
};

// USA: func_0202343c
extern "C" ARM void func_0202343c(void *receiver) {
    CombatUpdateReceiverView *state = static_cast<CombatUpdateReceiverView *>(receiver);
    if (_Z17TestFlags02046708P16FlagWord02046708j(static_cast<FlagWord02046708 *>(_Z27GetDataPtr02114e04_020d6c00v()), 0x41)) return;

    GameResources *resources = func_ov017_0218b5b0();
    int *list                = GetGlobal02109030();
    if (state->field9c3 || state->loadState <= 0) {
        if (_Z22ListContainsId0209497cP12List0209497ci(reinterpret_cast<List0209497c *>(list), 4)) {
            MoveValue3cbTo3cc(reinterpret_cast<char *>(list));
        }
        return;
    }
    if (_Z22ListContainsId020949bcP12List020949bci(reinterpret_cast<List020949bc *>(list), 4)) {
        MoveValue3ccTo3cb(reinterpret_cast<char *>(list));
    }
    if (state->field764) {
        if (state->field778) {
            func_020e0a78(receiver);
            state->field778 = 0;
        }
        func_020e0f74(receiver);
    } else {
        func_02026f34(receiver);
        _Z29ProcessCombatantState020235c8P11Obj020235c8(static_cast<Obj020235c8 *>(receiver));
    }
    if (_Z22ListContainsId0209497cP12List0209497ci(reinterpret_cast<List0209497c *>(list), 4)) {
        state->field9c6          = 0;
        state->field9c7          = 0;
        state->brightnessPending = 1;
        state->brightnessDelay   = 0;
    }
    if (IsAxisIntWithin16(reinterpret_cast<AxisFloats0203b5a0 *>(resources), 0) && _Z26IsChannelValueZero0203b5e0Pvi(resources, 1)) {
        if (state->field9c6 || state->field9c7) return;
        if (!state->brightnessPending) return;
        if (state->brightnessDelay) {
            state->brightnessDelay--;
            return;
        }
        func_02027438(static_cast<ScrollState02027438 *>(receiver));
        SetSubBrightness(resources, 0, 25);
        state->brightnessPending = 0;
    } else {
        if (IsAxisIntZero(reinterpret_cast<AxisFloats0203b5f8 *>(resources), 1)) state->brightnessPending = 0;
    }
}
