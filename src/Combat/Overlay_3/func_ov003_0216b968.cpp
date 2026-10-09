#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/ColorEffects.h"

struct Container0205a330;
struct Struct_0205c570;
struct Obj_0205da38;
struct Obj0205eaa0;
struct Entry_0205d6a0;

struct Global0216b968 {
    char unk_0[0x2e0];
    struct Container0205a330* entries_;
    char unk_2e4[0x6bc];
    int mode_;
    char unk_9a4[0x100a];
    unsigned char field_0x19ae;
};

struct Self0216b968 {
    char unk_0[0x4];
    short result_;
    short step_;
    char unk_8[0x8];
    int field_0x10;
    char unk_14[0x12ac];
    void* list_;
    char unk_12c4[0x126];
    unsigned char field_0x13ea;
    char unk_13eb;
    unsigned char flags_;
    char unk_13ed;
    unsigned char field_0x13ee;
};

extern "C" Global0216b968* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void func_0205d7a0(void* list, int index);
extern "C" void func_ov003_0216da90(Self0216b968* self);
extern "C" void _Z22IterateEntries0205a330P17Container0205a330i(struct Container0205a330* c, int arg);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570* list);
extern "C" void func_ov003_0216dc58(Self0216b968* self);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(struct Obj_0205da38* list, int key);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" int func_0205d97c(void* list);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(struct Entry_0205d6a0* list, int value);

extern unsigned short data_02114e30;
extern struct Obj0205eaa0 data_02108760;

// USA: func_ov003_0216b968
extern "C" ARM void func_ov003_0216b968(Self0216b968* self) {
    Global0216b968* global = _Z26GetGlobalField0x1c020421a0v();

    if (self->step_ == 0) {
        if (global->mode_ == 3) {
            self->field_0x13ea = 1;
            self->step_ = 1;
        }
    } else if (self->step_ == 1) {
        if (self->flags_ & 1) {
            return;
        }
        func_0205d7a0(self->list_, 0);
        func_ov003_0216da90(self);
        ColorEffect_ConfigureAlphaBlend(0x04000050, 4, 1, 10, 6);
        self->step_ = 2;
    } else if (self->step_ == 2) {
        GameState* gameState = GameState::GetInstance();
        struct Container0205a330* entries = global->entries_;
        _Z22IterateEntries0205a330P17Container0205a330i(entries, gameState->GetTickCount());
        global->field_0x19ae = 0;
        self->field_0x13ee = 0;
        _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570*)self->list_);
        if (self->field_0x10 != 0) {
            func_ov003_0216dc58(self);
        }

        int selection = -1;
        if (_Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38((struct Obj_0205da38*)self->list_, 0x14) != 0) {
            selection = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570*)self->list_);
        } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x401) != 0) {
            selection = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570*)self->list_);
        } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2) != 0 || func_0205d97c(self->list_) == 2) {
            selection = -2;
        }

        int result;
        int dispatch = 1;
        switch (selection) {
        case 0:
            result = 3;
            break;
        case 1:
            result = 5;
            break;
        case 2:
            result = 4;
            break;
        case 3:
            result = 6;
            break;
        case -2:
            result = 6;
            dispatch = 0;
            break;
        default:
            return;
        }

        self->result_ = result;
        self->step_ = 0;
        if (dispatch) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
        }
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0*)self->list_, 0);
    }
}
