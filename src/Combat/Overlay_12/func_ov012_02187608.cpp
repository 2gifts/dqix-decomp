#include <globaldefs.h>
#include "GameState/GameState.h"

struct Profile02187608
{
    unsigned int year_ : 12;
    unsigned int month_ : 4;
    unsigned int day_ : 5;
    unsigned int unk_0_21 : 4;
    unsigned int female_ : 1;
    unsigned int initialized_ : 1;
    unsigned int designChosen_ : 1;
    unsigned int birthdayChosen_ : 1;
    unsigned int accoladeChosen_ : 1;
    unsigned int vocationAccolade_ : 1;
    unsigned int showBirthday_ : 1;
    unsigned int unk_4_0 : 9;
    int title_ : 10;
    int accolade_ : 11;
    int edited_ : 1;
    unsigned int unk_4_31 : 1;
};

struct ProfileEditor02187608
{
    char unk_0[0xac];
    char window_[0x1370 - 0xac];
    unsigned char step_;
    unsigned char state_;
    char unk_1372[0x13a0 - 0x1372];
    unsigned char unk_13a0;
    char unk_13a1[0x13a8 - 0x13a1];
    signed char unk_13a8;
    signed char unk_13a9;
    unsigned char unk_13aa;
    unsigned char unk_13ab;
    char unk_13ac[0x13fc - 0x13ac];
    unsigned short year_;
    unsigned char month_;
    unsigned char day_;
};

struct Entry_0205d6a0;
struct Obj0205eaa0;
struct Obj021e6e20;

extern "C" int func_ov023_021e63bc(ProfileEditor02187608* self);
extern "C" int func_0201248c(unsigned short* pad, int buttons);
extern "C" void func_ov023_021e61f4(ProfileEditor02187608* self);
int TestFlag0SetAndFlag1Clear(unsigned short* pad, int buttons);
extern "C" void func_ov012_02185bf0(ProfileEditor02187608* self, unsigned char item, int selected);
extern "C" int func_0205df38(void* window, int item);
extern "C" void _Z30SetThreeElementFields_021e6378Pviiih(void* self, int state, int year, int month, unsigned char day);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* sound, int effect, int a);
extern "C" int func_ov023_021e6de4(ProfileEditor02187608* self);
int CalculateAge(int year, int month, int day);
extern "C" void func_ov012_0218adac(ProfileEditor02187608* self, int animate, int design, int keepPage);
extern "C" int _Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20(Obj021e6e20* self);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(Entry_0205d6a0* window, int a);
extern "C" void func_ov023_021e6e60(ProfileEditor02187608* self);
extern "C" void func_ov012_0218943c(ProfileEditor02187608* self);

extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];

static inline Profile02187608* GetProfile02187608(GameState* gameState)
{
    return (Profile02187608*)((char*)gameState + 0x569c);
}

// USA: func_ov012_02187608
extern "C" ARM void func_ov012_02187608(ProfileEditor02187608* self)
{
    if (self->step_ == 4)
    {
        int changed = 0;
        int canCancel = 1;
        int scroll = func_ov023_021e63bc(self);
        if (func_0201248c(data_02114e30, 0x80) || scroll < 0)
        {
            if (self->unk_13aa != 0)
                self->unk_13a8 = 1;
            if (self->unk_13a9 > -3)
                self->unk_13a9--;
        }
        else if (func_0201248c(data_02114e30, 0x40) || scroll > 0)
        {
            if (self->unk_13aa != 0)
                self->unk_13a8 = 0;
            if (self->unk_13a9 < 3)
                self->unk_13a9++;
        }
        else
        {
            self->unk_13a9 = 0;
        }
        func_ov023_021e61f4(self);
        if (TestFlag0SetAndFlag1Clear(data_02114e30, 0x80) || self->unk_13a9 <= -3)
        {
            if (self->unk_13ab & 2)
            {
                changed = 1;
                self->year_--;
                self->unk_13a8 = 1;
                self->unk_13aa = 1;
                if (self->year_ % 4 != 0 && self->month_ == 2 && self->day_ == 29)
                {
                    self->day_ = 28;
                    func_ov012_02185bf0(self, 9, 1);
                }
            }
            else
            {
                self->unk_13aa = 0;
            }
            self->unk_13a9 = 0;
        }
        else if (TestFlag0SetAndFlag1Clear(data_02114e30, 0x40) || self->unk_13a9 >= 3)
        {
            if (self->unk_13ab & 1)
            {
                changed = 1;
                self->year_++;
                self->unk_13a8 = 0;
                self->unk_13aa = 1;
                if (self->year_ % 4 != 0 && self->month_ == 2 && self->day_ == 29)
                {
                    self->day_ = 28;
                    func_ov012_02185bf0(self, 9, 1);
                }
            }
            else
            {
                self->unk_13aa = 0;
            }
            self->unk_13a9 = 0;
        }
        else if (TestFlag0SetAndFlag1Clear(data_02114e30, 0x20) || func_0205df38(self->window_, 8))
        {
            _Z30SetThreeElementFields_021e6378Pviiih(self, 8, 1, 0, 1);
            changed = 1;
            canCancel = 0;
            func_ov012_02185bf0(self, 7, 1);
        }
        else if (func_0205df38(self->window_, 9))
        {
            _Z30SetThreeElementFields_021e6378Pviiih(self, 9, 1, 1, 0);
            changed = 1;
            canCancel = 0;
            func_ov012_02185bf0(self, 7, 1);
        }
        else if (func_0205df38(self->window_, 7))
        {
            canCancel = 0;
        }
        if (changed)
        {
            func_ov012_02185bf0(self, self->state_, 1);
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 2, 0);
        }

        int close = 0;
        if (func_ov023_021e6de4(self) || func_0205df38(self->window_, 0x10))
        {
            GameState* gameState = GameState::GetInstance();
            Profile02187608* profile = GetProfile02187608(gameState);
            func_ov012_02185bf0(self, self->state_, 1);
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
            profile->year_ = self->year_;
            profile->month_ = self->month_;
            profile->day_ = self->day_;
            profile->birthdayChosen_ = 1;
            profile->unk_4_0 = CalculateAge(self->year_, self->month_, self->day_);
            func_ov012_0218adac(self, 0, -1, 0);
            self->state_ = 6;
            self->step_ = 0;
        }
        else if (_Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20((Obj021e6e20*)self) && canCancel)
        {
            close = 1;
        }
        if (!close)
            return;
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)self->window_, 1);
        self->step_++;
        return;
    }
    else if (self->step_ == 5)
    {
        self->step_++;
        return;
    }
    else if (self->step_ == 6)
    {
        self->step_++;
        return;
    }
    else if (self->step_ == 7)
    {
        self->state_ = 1;
        func_ov023_021e6e60(self);
        func_ov012_0218943c(self);
        self->unk_13a0 = 1;
        self->unk_13a8 = -1;
        self->unk_13a9 = 0;
        self->unk_13aa = 0;
        self->step_ = 1;
        return;
    }
}
