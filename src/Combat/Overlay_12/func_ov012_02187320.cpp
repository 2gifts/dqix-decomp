#if defined(jpn)
#define R(j,u) (j)
#define _Z22BuildMessageD_02189f38Pc func_ov012_0218aa30
#define _Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20 func_ov023_021e7184
#define func_0204500c func_02045d88
#define func_ov012_02185bf0 func_ov012_02186248
#define func_ov012_0218943c func_ov012_02189d18
#define func_ov012_0218adac func_ov012_0218bba0
#define func_ov023_021e6de4 func_ov023_021e7148
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Messages02187320
{
    char unk_0[R(0x868,0x998)];
    int busy_;
    int unk_99c;
    int unk_9a0;
    char unk_9a4[R(0x17de,0x19ae) - R(0x874,0x9a4)];
    unsigned char unk_19ae;
};

struct Profile02187320
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
};

struct ProfileEditor02187320
{
    char unk_0[R(0x90,0xac)];
    char window_[R(0x1314,0x133c) - R(0x90,0xac)];
    char strings_[R(0x1340,0x1370) - R(0x1314,0x133c)];
    unsigned char step_;
    unsigned char state_;
    char unk_1372[R(0x1368,0x13a0) - R(0x1342,0x1372)];
    unsigned char unk_13a0;
    char unk_13a1[R(0x1370,0x13a8) - R(0x1369,0x13a1)];
    signed char unk_13a8;
    signed char unk_13a9;
    char unk_13aa[R(0x1450,0x13f8) - R(0x1372,0x13aa)];
    unsigned int unk_13f8;
};

struct TableA68;
struct Entry_0205d6a0;
struct Struct0205de24;
struct Obj0205eaa0;
struct Struct_0205c570;
struct Obj021e6e20;

extern "C" Messages02187320* _Z26GetGlobalField0x1c020421a0v();
const char* FindEntryByKey(TableA68* table, int key);
#if defined(jpn)
extern "C" void func_0204500c(Messages02187320* messages, const char* text, int a);
#else
extern "C" void func_0204500c(Messages02187320* messages, const char* text, int a, int b);
#endif
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(Entry_0205d6a0* window, int a);
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(Struct0205de24* window, unsigned char a, unsigned char b);
extern "C" void func_ov023_021e6e60(ProfileEditor02187320* self);
extern "C" void _Z22BuildMessageD_02189f38Pc(char* self);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* sound, int effect, int a);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(Struct_0205c570* window);
extern "C" int func_ov023_021e6de4(ProfileEditor02187320* self);
extern "C" int _Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20(Obj021e6e20* self);
extern "C" void func_ov012_02185bf0(ProfileEditor02187320* self, unsigned char item, int selected);
#if defined(jpn)
extern "C" void func_ov012_0218adac(ProfileEditor02187320* self, int animate, int design);
#else
extern "C" void func_ov012_0218adac(ProfileEditor02187320* self, int animate, int design, int keepPage);
#endif
extern "C" void _Z24ReinitController02043204Pc(char* messages);
extern "C" void func_ov012_0218943c(ProfileEditor02187320* self);
extern "C" int func_020457e0(Messages02187320* messages);

extern "C" char data_02108760[];

static inline Profile02187320* GetProfile02187320(GameState* gameState)
{
    return (Profile02187320*)((char*)gameState + R(0x543c,0x569c));
}

// USA: func_ov012_02187320
extern "C" ARM void func_ov012_02187320(ProfileEditor02187320* self)
{
    Messages02187320* messages = _Z26GetGlobalField0x1c020421a0v();
    int windowState = messages->unk_9a0;
    if (windowState == 3)
        messages->unk_19ae = 0;
    if (self->step_ == 0)
    {
#if defined(jpn)
        func_0204500c(messages, FindEntryByKey((TableA68*)self->strings_, 0xf), 0);
#else
        func_0204500c(messages, FindEntryByKey((TableA68*)self->strings_, 0xf), 0, 0xe3);
#endif
        messages->busy_ = 1;
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)self->window_, 1);
        self->step_ = 10;
        return;
    }
    else if (self->step_ == 1)
    {
        if (windowState == 0 || windowState == 3)
            self->step_++;
        return;
    }
    else if (self->step_ == 2)
    {
        self->unk_13a0 = 0;
        self->unk_13f8 = 0;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((Struct0205de24*)self->window_, 0, 2);
        func_ov023_021e6e60(self);
        _Z22BuildMessageD_02189f38Pc((char*)self);
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 5, 0);
        self->step_++;
        return;
    }
    else if (self->step_ == 3)
    {
        self->unk_13a0 = 1;
        self->unk_13f8 = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)self->window_);
        int done = 0;
        if (func_ov023_021e6de4(self) || _Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20((Obj021e6e20*)self))
        {
            func_ov012_02185bf0(self, self->state_, 1);
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
            Profile02187320* profile = GetProfile02187320(GameState::GetInstance());
            switch (self->unk_13f8)
            {
                case 1:
                    profile->showBirthday_ = 1;
                    break;
                case 0:
                    profile->showBirthday_ = 0;
                    break;
            }
            if (_Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20((Obj021e6e20*)self))
                profile->showBirthday_ = 1;
#if defined(jpn)
            func_ov012_0218adac(self, 0, -1);
#else
    #if defined(jpn)
        func_ov012_0218adac(self, 0, -1);
#else
        func_ov012_0218adac(self, 0, -1, 0);
#endif
#endif
            done = 1;
        }
        if (!done)
            return;
        Messages02187320* system = _Z26GetGlobalField0x1c020421a0v();
        int busy = system->busy_ == 0 ? 1 : 0;
        if (!busy)
            _Z24ReinitController02043204Pc((char*)system);
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)self->window_, 1);
        self->step_++;
        return;
    }
    else if (self->step_ == 4)
    {
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
        self->state_ = 1;
        func_ov023_021e6e60(self);
        func_ov012_0218943c(self);
        self->unk_13a0 = 1;
        self->unk_13a8 = -1;
        self->unk_13a9 = 0;
        self->step_ = 1;
        return;
    }
    else if (self->step_ == 10 && messages->busy_ == 0)
    {
        Profile02187320* profile = GetProfile02187320(GameState::GetInstance());
        if (func_020457e0(messages) == 0)
            profile->showBirthday_ = 0;
        else
            profile->showBirthday_ = 1;
#if defined(jpn)
        func_ov012_0218adac(self, 0, -1);
#else
        func_ov012_0218adac(self, 0, -1, 0);
#endif
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)self->window_, 1);
        self->step_ = 5;
    }
}
