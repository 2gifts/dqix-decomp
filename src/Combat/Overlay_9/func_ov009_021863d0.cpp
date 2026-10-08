#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct AxisFloats0203b57c;

struct CharacterModel {
    char unk_0[0xc12];
    unsigned char loading_;
};

GameResources* GetWord0x0(int* gameState);
int GetAxisIntValue(AxisFloats0203b57c* resources, int screen);
extern "C" void func_ov009_02188c2c(void* self);
extern "C" void func_ov009_02188d9c(void* self);
extern "C" void func_ov009_02188e70(void* self, int choice);
extern "C" void func_ov009_02188944(void* self, int choice);
extern "C" int func_ov009_02188ee8(void* self);
extern "C" void func_ov023_021e6158(CharacterModel* character, int part);
extern "C" void _Z20SetStatValue021855dcPhi(unsigned char* self, int state);

struct CharacterCreation {
    char unk_0[0x7fc];
    CharacterModel* nextCharacter_;
    char unk_800[0xc58 - 0x800];
    signed char state_;
    unsigned char step_;
    char unk_c5a[0xd95 - 0xc5a];
    unsigned char mode_;
    char unk_d96[0xd9c - 0xd96];
    unsigned int flags_;
    signed char lastStates_[2];
    unsigned char vocation_;
    unsigned char sex_;
};

// USA: func_ov009_021863d0
extern "C" ARM void func_ov009_021863d0(CharacterCreation* self)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = GetWord0x0((int*)gameState);
    if (self->step_ == 0)
    {
        if (GetAxisIntValue((AxisFloats0203b57c*)resources, 0) == -16 &&
            GetAxisIntValue((AxisFloats0203b57c*)resources, 1) == -16)
        {
            if (self->flags_ & 0x80)
                return;
            SetBrightness(resources, 0, 15);
        }
        func_ov009_02188c2c(self);
        func_ov009_02188d9c(self);
        func_ov009_02188e70(self, self->sex_);
        self->step_++;
    }
    if (self->step_ == 1)
    {
        if (IsBrightnessTransitionActive(resources))
            return;
        self->flags_ |= 1;
        self->step_++;
    }
    else if (self->step_ == 2)
    {
        if (self->flags_ & 0x80)
            return;
        func_ov009_02188944(self, self->sex_);
        self->step_++;
    }
    else if (self->step_ == 3)
    {
        int result = func_ov009_02188ee8(self);
        if (result != self->state_)
        {
            CharacterModel* next = self->nextCharacter_;
            if (next->loading_ == 0)
            {
                func_ov023_021e6158(next, 0);
                func_ov023_021e6158(next, 2);
                func_ov023_021e6158(next, 3);
                func_ov023_021e6158(next, 4);
            }
        }
        if (result == -2)
        {
            _Z20SetStatValue021855dcPhi((unsigned char*)self, 2);
            return;
        }
        if (result == -3)
        {
            if (self->mode_ == 1)
                self->flags_ &= ~0x400;
            else if (self->mode_ == 0)
                *((unsigned char*)gameState + 0x63d4) = 0;
            _Z20SetStatValue021855dcPhi((unsigned char*)self, 11);
            return;
        }
        if (result >= 101 && result <= 108)
        {
            int state = result - 100;
            if (state <= self->lastStates_[self->sex_] && state != self->state_)
                _Z20SetStatValue021855dcPhi((unsigned char*)self, (unsigned char)state);
        }
    }
}
