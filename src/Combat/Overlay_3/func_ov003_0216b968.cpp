#include <globaldefs.h>
#if defined(jpn)
#define REGION_LAYOUT(j,u) j
#define func_ov003_0216da90 func_ov003_0216d478
#else
#define REGION_LAYOUT(j,u) u
#endif

#include "GameState/GameState.h"
#include "System/ColorEffects.h"

struct Container0205a330;
struct Struct_0205c570;
struct Obj_0205da38;
struct Obj0205eaa0;
struct Entry_0205d6a0;

struct Global0216b968 {
    char unk_0[REGION_LAYOUT(0x230, 0x2e0)];
    struct Container0205a330* entries_;
    char unk_2e4[REGION_LAYOUT(0x63c, 0x6bc)];
    int mode_;
    char unk_9a4[REGION_LAYOUT(0xf6a, 0x100a)];
    unsigned char field_0x19ae;
};

struct Self0216b968 {
    char unk_0[0x4];
    short result_;
    short step_;
    char unk_8[0x8];
    int field_0x10;
    char unk_14[REGION_LAYOUT(0x113c, 0x12ac)];
    void* list_;
    char unk_12c4[0x126];
    unsigned char field_0x13ea;
    char unk_13eb;
    unsigned char flags_;
    char unk_13ed;
    unsigned char field_0x13ee;
};

Global0216b968* GetGlobalField0x1c020421a0(void);
extern "C" void func_0205d7a0(void* list, int index);
extern "C" void func_ov003_0216da90(Self0216b968* self);
void IterateEntries0205a330(struct Container0205a330* c, int arg);
int GetActiveScaledSum0205d794(struct Struct_0205c570* list);
extern "C" void func_ov003_0216dc58(Self0216b968* self);
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);
extern "C" int func_0205d97c(void* list);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
void ResetEntryList0205d6a0(struct Entry_0205d6a0* list, int value);

extern unsigned short data_02114e30;
extern struct Obj0205eaa0 data_02108760;

// USA: func_ov003_0216b968
extern "C" ARM void func_ov003_0216b968(Self0216b968* self) {
    Global0216b968* global = GetGlobalField0x1c020421a0();

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
        IterateEntries0205a330(entries, gameState->GetTickCount());
        global->field_0x19ae = 0;
        self->field_0x13ee = 0;
        GetActiveScaledSum0205d794((struct Struct_0205c570*)self->list_);
        if (self->field_0x10 != 0) {
            func_ov003_0216dc58(self);
        }

        int selection = -1;
        if (IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)self->list_, 0x14) != 0) {
            selection = GetActiveScaledSum0205d794((struct Struct_0205c570*)self->list_);
        } else if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x401) != 0) {
            selection = GetActiveScaledSum0205d794((struct Struct_0205c570*)self->list_);
        } else if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 2) != 0 || func_0205d97c(self->list_) == 2) {
            selection = -2;
        }

#if defined(jpn)
        switch (selection) {
        case 0:
            self->result_ = 3;
            self->step_ = 0;
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
            ResetEntryList0205d6a0((struct Entry_0205d6a0*)self->list_, 0);
            break;
        case 1:
            self->result_ = 5;
            self->step_ = 0;
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
            ResetEntryList0205d6a0((struct Entry_0205d6a0*)self->list_, 0);
            break;
        case 2:
            self->result_ = 4;
            self->step_ = 0;
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
            ResetEntryList0205d6a0((struct Entry_0205d6a0*)self->list_, 0);
            break;
        case 3:
            self->result_ = 6;
            self->step_ = 0;
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
            ResetEntryList0205d6a0((struct Entry_0205d6a0*)self->list_, 0);
            break;
        case -2:
            self->result_ = 6;
            self->step_ = 0;
            ResetEntryList0205d6a0((struct Entry_0205d6a0*)self->list_, 0);
            break;
        default:
            break;
        }
#else
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
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        }
        ResetEntryList0205d6a0((struct Entry_0205d6a0*)self->list_, 0);
#endif
    }
}
