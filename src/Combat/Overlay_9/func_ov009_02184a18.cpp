#if defined(jpn)
#define R(j,u) (j)
#define _Z18UpdateFlag021885b8P14Struct021885b8 func_ov009_02189378
#define _Z29UpdateCombatantState_02184d70Pv func_ov009_02186098
#define data_ov009_0218ab9c data_ov009_0218bb04
#define func_ov009_02188454 func_ov009_02189214
#define func_ov009_02188604 func_ov009_021893c4
#else
#define R(j,u) (u)
#endif
#if defined(jpn)
extern "C" void func_ov009_02185c58(void*);
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205d81c;
struct Struct021885b8;

struct Canvas {
    char unk_0[0xc5];
    unsigned char flags_;
};

struct WindowBase {
    char unk_0[4];
    int frame_[0x14];
    int cursor_[0x10];
    unsigned char unk_94[4];
};

struct TextWindow {
    WindowBase base_;
    char unk_98[0xbc - 0x98];
};

extern "C" void _Z20AdvanceActor020a20d8Pv(void* camera);
Canvas* FindElementForFieldB0(Struct_0205d81c* window);
int IsField0x9cEqual3(unsigned char* canvas);
void SetFieldAt0x30(void* frame, int value);
extern "C" int func_0205d0e0(TextWindow* window, unsigned int ticks);
extern "C" void func_ov023_021e5020(void* character);
extern "C" void func_ov009_02188604(void* self, unsigned int ticks);
extern "C" void func_ov009_02188454(void* self);
extern "C" void _Z18UpdateFlag021885b8P14Struct021885b8(Struct021885b8* self);
extern "C" void _Z29UpdateCombatantState_02184d70Pv(void* self);

struct CharacterCreation {
    char unk_0[R(0x1bc, 0x1f8)];
    TextWindow windows_[2];
    char unk_370[0x7f8 - 0x370];
    void* character_;
    void* nextCharacter_;
    char unk_800[0x878 - 0x800];
    Object3D object_;
    char camera_[0x2c8];
    char unk_bec[0xc58 - 0xbec];
    signed char state_;
    unsigned char step_;
    char unk_c5a[0xcd8 - 0xc5a];
    Object3D object2_;
    unsigned char selection_;
    unsigned char unk_d85;
    char unk_d86[0xd9c - 0xd86];
    unsigned int flags_;

    void State();
};

typedef void (CharacterCreation::*StateFunc)();

struct StateTable {
    StateFunc states[13];
};

extern const StateTable data_ov009_0218ab9c;
extern const StateFunc data_020e6d5c;

// USA: func_ov009_02184a18
extern "C" ARM int func_ov009_02184a18(CharacterCreation* self)
{
    unsigned int ticks = GameState::GetInstance()->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    if (self->state_ != 0)
        _Z20AdvanceActor020a20d8Pv(self->camera_);
    if (self->state_ == 9 && self->step_ == 2)
    {
        Canvas* canvas = FindElementForFieldB0((Struct_0205d81c*)&self->windows_[1]);
        if (canvas != NULL && IsField0x9cEqual3((unsigned char*)canvas) != 0 && !(canvas->flags_ & 2))
            SetFieldAt0x30(&self->windows_[1].base_.frame_, -1);
    }
    func_0205d0e0(&self->windows_[0], ticks);
    self->unk_d85 = func_0205d0e0(&self->windows_[1], ticks);
    if (self->flags_ & 0x200)
    {
        self->object_.AdvanceEffects();
        self->object2_.AdvanceEffects();
    }
    if (self->character_ != NULL)
        func_ov023_021e5020(self->character_);
    if (self->nextCharacter_ != NULL)
        func_ov023_021e5020(self->nextCharacter_);
    func_ov009_02188604(self, ticks);
    func_ov009_02188454(self);
    _Z18UpdateFlag021885b8P14Struct021885b8((Struct021885b8*)self);

    StateTable table = data_ov009_0218ab9c;
    table.states[12] = data_020e6d5c;
    if (table.states[self->state_] == 0)
        return 0;
    (self->*table.states[self->state_])();
    _Z29UpdateCombatantState_02184d70Pv(self);
#if defined(jpn)
    func_ov009_02185c58((char*)self + 0xdc);
#endif
    return self->state_ == 12;
}
