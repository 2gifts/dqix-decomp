#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct ProfileAccolade {
    unsigned int year : 12;
    unsigned int month : 4;
    unsigned int day : 5;
    unsigned int design : 4;
    unsigned int female : 1;
    unsigned int initialized : 1;
    unsigned int designChosen : 1;
    unsigned int birthdayChosen : 1;
    unsigned int accoladeChosen : 1;
    unsigned int vocationAccolade : 1;
    unsigned int showBirthday : 1;
    unsigned int unknown : 9;
    int title : 10;
    int accolade : 11;
    int edited : 1;
    unsigned int unknownHigh : 1;
};
struct TableA68;
struct Obj0205eaa0;
struct Obj021e6e20;
struct Struct0205de24;
struct Struct_0205c570;
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(Struct0205de24*, unsigned char, unsigned char);
extern "C" void func_ov023_021e6e60(void*);
void SetupBattleTag0218a574(char*);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(Struct_0205c570*);
extern "C" int func_ov023_021e6448(void*);
extern "C" int func_ov023_021e7148(void*);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0*, int, int);
extern "C" void func_0202ae18();
int GetField5cb0Value(char*);
const char* FindEntryByKey(TableA68*, int);
extern "C" void func_ov012_0218bba0(void*, int, int);
extern "C" void func_ov012_02189be8(void*, int);
extern "C" int _Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20(Obj021e6e20*);
extern "C" char data_02108760[];

static inline ProfileAccolade* GetProfileAccolade(GameState* state) {
    return (ProfileAccolade*)((char*)state + 0x543c);
}

// JPN: func_ov012_02188cfc
extern "C" ARM void func_ov012_02188640(char* editor) {
    if (*(unsigned char*)(editor + 0x1340) == 0) {
        *(unsigned char*)(editor + 0x1368) = 0;
        GameState* state = GameState::GetInstance();
        ProfileAccolade* savedProfile = GetProfileAccolade(state);
        unsigned int index;
        if (!savedProfile->vocationAccolade && savedProfile->accolade >= 800 && savedProfile->accolade < 860)
            index = savedProfile->accolade - 799;
        else
            index = 0;
        *(unsigned int*)(editor + 0x1444) = index;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((Struct0205de24*)(editor + 0x90), 0, 3);
        func_ov023_021e6e60(editor);
        SetupBattleTag0218a574(editor);
        ++*(unsigned char*)(editor + 0x1340);
        return;
    } else if (*(unsigned char*)(editor + 0x1340) == 1) {
        *(unsigned char*)(editor + 0x1368) = 1;
        *(int*)(editor + 0x1444) = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)(editor + 0x90));
        if (func_ov023_021e6448(editor))
            *(int*)(editor + 0x1444) = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)(editor + 0x90));
        if (func_ov023_021e7148(editor)) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
            ProfileAccolade* profile = GetProfileAccolade(GameState::GetInstance());
            GameState* state = GameState::GetInstance();
            func_0202ae18();
            if (*(int*)(editor + 0x1444) == 0) {
                char* character = *(char**)((char*)state->GetProtagonist() + 0x144);
                int vocation = *(int*)(character + 0x8b8);
                profile->vocationAccolade = 1;
                profile->accolade = vocation + 700;
                if (GetField5cb0Value((char*)state) == 1)
                    profile->accolade = 713;
            } else {
                profile->accolade = *(int*)(editor + 0x1444) + 799;
                profile->vocationAccolade = 0;
            }
            const char* name = FindEntryByKey((TableA68*)(editor + 0x1314), (short)(profile->accolade + 20000));
            memset(editor + 0x1458, 0, 0x40);
            memcpy(editor + 0x1458, name, strlen(name));
            profile->accoladeChosen = 1;
            func_ov012_0218bba0(editor, 0, -1);
            func_ov012_02189be8(editor, 0);
            return;
        }
        if (_Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20((Obj021e6e20*)editor))
            func_ov012_02189be8(editor, 1);
        return;
    }
}

#else
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Profile02188640
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

struct Appearance02188640
{
    short models_[10];
    unsigned char female_ : 1;
    unsigned char eyeColor_ : 3;
    unsigned char skinColor_ : 4;
    char unk_15[0x1c - 0x15];
};

struct Party02188640
{
    char unk_0[0x488];
    Appearance02188640 appearance_;
    char unk_4a4[0x950 - 0x4a4];
    int vocation_;
};

struct Member02188640
{
    char unk_0[0x150];
    Party02188640* partyData_;
};

struct ProfileEditor02188640
{
    char unk_0[0xac];
    char window_[0x133c - 0xac];
    char strings_[0x1370 - 0x133c];
    unsigned char step_;
    unsigned char state_;
    char unk_1372[0x13a0 - 0x1372];
    unsigned char unk_13a0;
    char unk_13a1[0x13d8 - 0x13a1];
    int selections_[6];
    char unk_13f0[0x1400 - 0x13f0];
    char accoladeText_[0x40];
};

struct TableA68;
struct Obj0205eaa0;
struct Obj021e6e20;
struct Struct0205de24;
struct Struct_0205c570;

extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(Struct0205de24* window, unsigned char a, unsigned char b);
extern "C" void func_ov023_021e6e60(ProfileEditor02188640* self);
extern "C" void _Z22SetupBattleTag0218a574Pc(char* self);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(Struct_0205c570* window);
extern "C" int func_ov023_021e6448(ProfileEditor02188640* self);
extern "C" int func_ov023_021e6de4(ProfileEditor02188640* self);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* sound, int effect, int a);
extern "C" void func_0202ae18();
int GetField5cb0Value(char* gameState);
const char* FindEntryByKey(TableA68* table, int key);
extern "C" void func_ov012_0218adac(ProfileEditor02188640* self, int animate, int design, int keepPage);
extern "C" void func_ov012_0218930c(ProfileEditor02188640* self, int cancel);
extern "C" int _Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20(Obj021e6e20* self);

extern "C" char data_02108760[];

static inline Profile02188640* GetProfile02188640(GameState* gameState)
{
    return (Profile02188640*)((char*)gameState + 0x569c);
}

// USA: func_ov012_02188640
extern "C" ARM void func_ov012_02188640(ProfileEditor02188640* self)
{
    if (self->step_ == 0)
    {
        self->unk_13a0 = 0;
        GameState* gameState = GameState::GetInstance();
        unsigned int index;
        if (!GetProfile02188640(gameState)->vocationAccolade_)
        {
            int accolade = GetProfile02188640(gameState)->accolade_;
            if (accolade >= 800 && accolade < 900)
            {
                index = accolade - 799;
                goto found;
            }
            if (accolade >= 900 && accolade < 1000)
            {
                index = accolade - 899;
                goto found;
            }
        }
        index = 0;
    found:
        self->selections_[5] = index;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((Struct0205de24*)self->window_, 0, 3);
        func_ov023_021e6e60(self);
        _Z22SetupBattleTag0218a574Pc((char*)self);
        self->step_++;
        return;
    }
    else if (self->step_ == 1)
    {
        self->unk_13a0 = 1;
        self->selections_[5] = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)self->window_);
        if (func_ov023_021e6448(self))
            self->selections_[5] = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)self->window_);
        if (func_ov023_021e6de4(self))
        {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
            Profile02188640* profile = GetProfile02188640(GameState::GetInstance());
            GameState* gameState = GameState::GetInstance();
            func_0202ae18();
            Member02188640* protagonist = (Member02188640*)gameState->GetProtagonist();
            if (self->selections_[5] == 0)
            {
                Party02188640* data = protagonist->partyData_;
                int accolade = 0x50dc;
                if (data->appearance_.female_ == 1)
                    accolade = 0x510e;
                int vocation = data->vocation_;
                profile->vocationAccolade_ = 1;
                profile->accolade_ = accolade + vocation - 0x4e20;
                if (GetField5cb0Value((char*)gameState) == 1)
                    profile->accolade_ = accolade + 13 - 0x4e20;
            }
            else
            {
                int accolade = 0x5140;
                if (protagonist->partyData_->appearance_.female_ == 1)
                    accolade = 0x51a4;
                profile->accolade_ = accolade + self->selections_[5] - 0x4e21;
                profile->vocationAccolade_ = 0;
            }
            const char* text = FindEntryByKey((TableA68*)self->strings_, (short)(profile->accolade_ + 20000));
            memset(self->accoladeText_, 0, sizeof(self->accoladeText_));
            memcpy(self->accoladeText_, text, strlen(text));
            profile->accoladeChosen_ = 1;
            func_ov012_0218adac(self, 0, -1, 0);
            func_ov012_0218930c(self, 0);
            return;
        }
        if (_Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20((Obj021e6e20*)self))
            func_ov012_0218930c(self, 1);
        return;
    }
}

#endif
