#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct Messages02184acc
{
    char unk_0[0x998];
    int busy_;
};

struct Profile02184acc
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

struct ProfileEditor02184acc
{
    char unk_0[0xac];
    char window_[0xd28 - 0xac];
    char card_[0x60c];
    unsigned char cardUnk_60c;
    char unk_1335[0x1370 - 0x1335];
    unsigned char step_;
    unsigned char state_;
    char unk_1372[0x1380 - 0x1372];
    int tasks_[6];
    int unk_1398;
    int result_;
    unsigned char unk_13a0;
    char unk_13a1[3];
    int unk_13a4;
    char unk_13a8[0x13d0 - 0x13a8];
    char* message_;
    unsigned int selection_;
    char unk_13d8[0x13f4 - 0x13d8];
    unsigned int design_;
    char unk_13f8[0x1480 - 0x13f8];
    unsigned char checker_[0x3c];
    unsigned char finished_;
    unsigned char unk_14bd;
    char unk_14be[2];
};

typedef void (ProfileEditor02184acc::*StateFn02184acc)();

struct StateTable02184acc
{
    StateFn02184acc states[17];
};

struct Struct_0205def8;
struct Entry_0205d6a0;

extern "C" void func_ov023_021e7404(void* card, int input);
extern "C" int func_0205d0e0(void* window, int input);
extern "C" void func_ov012_02185cf8(ProfileEditor02184acc* self);
extern "C" Messages02184acc* _Z26GetGlobalField0x1c020421a0v();
int TestFlag0SetAndFlag1Clear(unsigned short* pad, int buttons);
extern "C" void func_ov012_0218adac(ProfileEditor02184acc* self, int animate, int design, int keepPage);
extern "C" int func_ov017_021959b4();
extern "C" void func_ov012_021845f8(void* checker);
extern "C" int func_ov012_02184d80(void* checker, char* text);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(Struct_0205def8* window, int a, int b);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(Entry_0205d6a0* window, int a);
extern "C" void _Z24ReinitController02043204Pc(char* messages);

extern "C" const StateTable02184acc data_ov012_0218b188;
extern "C" StateFn02184acc data_020e6d5c;
extern "C" unsigned short data_02114e30[];

static inline Profile02184acc* GetProfile02184acc(GameState* gameState)
{
    return (Profile02184acc*)((char*)gameState + 0x569c);
}

// USA: func_ov012_02184acc
extern "C" ARM int func_ov012_02184acc(ProfileEditor02184acc* self, int input)
{
    self->unk_13a4 = input;
    func_ov023_021e7404(self->card_, input);
    self->unk_1398 = func_0205d0e0(self->window_, input);
    StateTable02184acc states = data_ov012_0218b188;
    states.states[16] = data_020e6d5c;
    if (states.states[self->state_] != 0)
        (self->*states.states[self->state_])();
    func_ov012_02185cf8(self);

    Messages02184acc* messages = _Z26GetGlobalField0x1c020421a0v();
    GameState* gameState = GameState::GetInstance();
    if ((self->state_ != 0 && self->state_ < 15) || (self->state_ == 0 && messages->busy_ != 0))
    {
        if (messages->busy_ == 0 && TestFlag0SetAndFlag1Clear(data_02114e30, 0x800))
        {
            self->unk_14bd = ++self->unk_14bd & 1;
            self->cardUnk_60c = self->unk_14bd;
            if (self->state_ == 13 && self->step_ == 3)
                func_ov012_0218adac(self, 0, GetProfile02184acc(gameState)->female_ + self->design_ * 2, 1);
            else
                func_ov012_0218adac(self, 0, -1, 1);
        }

        if (func_ov017_021959b4())
        {
            if (self->state_ == 14 && self->step_ == 4 && *self->message_ != 0)
            {
                GameState::GetInstance();
                BackgroundLoader::AddLockGlobal();
                BackgroundLoader::FreeAllocationsGlobal();
                func_ov012_021845f8(self->checker_);
                int forbidden = func_ov012_02184d80(self->checker_, self->message_);
                BackgroundLoader::RemoveLockGlobal();
                if (forbidden)
                {
                    _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((Struct_0205def8*)self->window_, 0, 14);
                    self->step_ = 10;
                    return 0;
                }
            }

            self->finished_ = 1;
            self->unk_13a0 = 0;
            self->selection_ = 0;
            _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)self->window_, 1);
            self->state_ = 15;
            self->step_ = 0;
            if (messages->busy_ != 0)
                _Z24ReinitController02043204Pc((char*)messages);

            BackgroundLoader* loader = BackgroundLoader::GetInstance();
            for (int i = 0; i < 6; i++)
            {
                if (self->tasks_[i] > -1)
                {
                    loader->RemoveTask(self->tasks_[i]);
                    self->tasks_[i] = -1;
                }
            }
        }
    }
    return self->result_;
}
