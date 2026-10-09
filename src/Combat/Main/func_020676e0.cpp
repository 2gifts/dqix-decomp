#include <globaldefs.h>
#include "GameState/GameState.h"

struct IntField0x23c_020a27c4 {
    char pad0[0x23c];
    int value;
    char pad240[4];
    unsigned char flags;
};
struct ControlOwner { char pad0[0xda]; unsigned short flags; };
struct GameModeView { char pad0[0x5cc8]; unsigned char mode; };
struct ControlState {
    char pad0[0x8c];
    ControlOwner* owner;
    unsigned char controls[0x954 - 0x90];
    int value;
    char pad958[0x98c - 0x958];
    int mode;
    char pad990[0x9a0 - 0x990];
    int state;
    char pad9a4[0x19ba - 0x9a4];
    unsigned char enabled;
    char pad19bb[0x19d2 - 0x19bb];
    unsigned char alternateInput;
};
typedef void (ControlState::*ControlHandler)(int);
extern ControlHandler data_020f08b8[2];
extern unsigned short data_02114e30[];
void SetupAndDispatch0205c904(unsigned char*, int);
int CheckGlobalObjState2AndInit0205cde8(unsigned char*);
void InitGlobalObjAndSelfPointer0205cd94(unsigned char*);
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
int GetFieldIfFlag4(char*);
int GetWord0x0(int*);
int GetIntAt0x23c(IntField0x23c_020a27c4*);
int IsFieldNotPositive_021a4e70(unsigned char*);
int GetScaledSumIfActive0205cecc(void*);
int CallFunc0205c570AtField0x1c(void*);

// USA: func_020676e0
extern "C" ARM void func_020676e0(ControlState* state, int elapsed) {
    if (state->state != 6) return;
    if (!state->enabled) return;
    SetupAndDispatch0205c904(state->controls, elapsed);
    if (!CheckGlobalObjState2AndInit0205cde8(state->controls)) {
        InitGlobalObjAndSelfPointer0205cd94(state->controls);
        return;
    }
    int enabled = 1;
    bool pressed = TestFlag0SetAndFlag1Clear(data_02114e30, 0x401) != 0;
    bool cancelled = TestFlag0SetAndFlag1Clear(data_02114e30, 2) != 0;
    GameState* game;
    unsigned char* resource;
    int mode = state->mode;
    game = GameState::GetInstance();
    IntField0x23c_020a27c4* field = (IntField0x23c_020a27c4*)GetFieldIfFlag4((char*)game);
    resource = (unsigned char*)GetWord0x0((int*)game);
    if (mode != 1 && state->alternateInput) {
        if (field) {
            if ((field->flags & 2) || !GetIntAt0x23c(field))
                pressed |= TestFlag0SetAndFlag1Clear(data_02114e30, 0x200);
        } else {
            pressed |= TestFlag0SetAndFlag1Clear(data_02114e30, 0x200);
        }
    }
    int specialMode = 0;
    if (((GameModeView*)game)->mode == 2) specialMode = 1;
    if (!specialMode && resource && !IsFieldNotPositive_021a4e70(resource)) {
        pressed = 0;
        cancelled = 0;
        enabled = 0;
    }
    if (!specialMode && state->owner && (state->owner->flags & 0x20)) {
        pressed = 0;
        cancelled = 0;
        enabled = 0;
    }
    int value = -1;
    if (enabled) value = GetScaledSumIfActive0205cecc(state->controls);
    if (pressed) value = CallFunc0205c570AtField0x1c(state->controls);
    else if (cancelled) value = -2;
    state->value = value;
    (state->*data_020f08b8[mode])(value);
}
