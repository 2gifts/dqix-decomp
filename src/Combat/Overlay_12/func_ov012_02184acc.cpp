#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
#define func_ov012_02185cf8 func_ov012_0218634c
#define func_ov012_02184d80 func_ov012_02185db4
#define data_ov012_0218b188 data_ov012_0218bea8
#endif

struct Messages02184acc
{
#if defined(jpn)
    char unk_0[0x868];
#else
    char unk_0[0x998];
#endif
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

struct Save02184acc
{
    char unk_0[0x5400];
    Profile02184acc profile_;
};

struct GameStateSave02184acc
{
    char unk_0[0x29c];
    Save02184acc save_;
};

struct ProfileEditor02184acc
{
#if defined(jpn)
    char unk_0[0x90];
    char window_[0xd0c - 0x90];
    char card_[0x608];
    char unk_1314[0x1340 - 0x1314];
    unsigned char step_;
    unsigned char state_;
    char unk_1342[0x1350 - 0x1342];
    int tasks_[4];
    int unk_1398;
    int result_;
    unsigned char unk_13a0;
    char unk_1369[3];
    int unk_13a4;
    char unk_1370[0x1428 - 0x1370];
    char* message_;
    unsigned int selection_;
    char unk_1430[0x144c - 0x1430];
    unsigned int design_;
    char unk_1450[0x14d8 - 0x1450];
    unsigned char checker_[0x20];
    unsigned char finished_;
#else
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
#endif
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
Messages02184acc* GetGlobalField0x1c020421a0();
int TestFlag0SetAndFlag1Clear(unsigned short* pad, int buttons);
extern "C" void func_ov012_0218adac(ProfileEditor02184acc* self, int animate, int design, int keepPage);
extern "C" int func_ov017_021959b4();
extern "C" void func_ov012_021845f8(void* checker);
extern "C" int func_ov012_02184d80(void* checker, char* text);
#if defined(jpn)
struct SearchStruct;
extern "C" SearchStruct* func_0202ae18();
int TestFlagBitAt0xe(SearchStruct*, int);
#endif
void SetElementFlag0x20ByKey0205def8(Struct_0205def8* window, int a, int b);
void ResetEntryList0205d6a0(Entry_0205d6a0* window, int a);
void ReinitController02043204(char* messages);

extern "C" const StateTable02184acc data_ov012_0218b188;
extern "C" StateFn02184acc data_020e6d5c;
extern "C" unsigned short data_02114e30[];

static inline Profile02184acc* GetProfile02184acc(GameState* gameState)
{
    return &((GameStateSave02184acc*)gameState)->save_.profile_;
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

    Messages02184acc* messages = GetGlobalField0x1c020421a0();
#if !defined(jpn)
    GameState* gameState = GameState::GetInstance();
#endif
    if ((self->state_ != 0 && self->state_ < 15) || (self->state_ == 0 && messages->busy_ != 0))
    {
#if !defined(jpn)
        if (messages->busy_ == 0 && TestFlag0SetAndFlag1Clear(data_02114e30, 0x800))
        {
            self->unk_14bd = ++self->unk_14bd & 1;
            self->cardUnk_60c = self->unk_14bd;
            if (self->state_ == 13 && self->step_ == 3)
                func_ov012_0218adac(self, 0, GetProfile02184acc(gameState)->female_ + self->design_ * 2, 1);
            else
                func_ov012_0218adac(self, 0, -1, 1);
        }

#endif
#if defined(jpn)
        if ((messages->busy_ == 0 && TestFlag0SetAndFlag1Clear(data_02114e30, 0x800)) ||
            TestFlagBitAt0xe(func_0202ae18(), 0))
#else
        if (func_ov017_021959b4())
#endif
        {
#if defined(jpn)
            if (self->state_ == 14 && self->step_ == 4)
#else
            if (self->state_ == 14 && self->step_ == 4 && *self->message_ != 0)
#endif
            {
                GameState::GetInstance();
#if !defined(jpn)
                BackgroundLoader::AddLockGlobal();
                BackgroundLoader::FreeAllocationsGlobal();
                func_ov012_021845f8(self->checker_);
#endif
                int forbidden = func_ov012_02184d80(self->checker_, self->message_);
#if !defined(jpn)
                BackgroundLoader::RemoveLockGlobal();
#endif
                if (forbidden)
                {
                    SetElementFlag0x20ByKey0205def8((Struct_0205def8*)self->window_, 0, 14);
                    self->step_ = 10;
                    return 0;
                }
            }

            self->finished_ = 1;
            self->unk_13a0 = 0;
            self->selection_ = 0;
            ResetEntryList0205d6a0((Entry_0205d6a0*)self->window_, 1);
            self->state_ = 15;
            self->step_ = 0;
            if (messages->busy_ != 0)
                ReinitController02043204((char*)messages);

            BackgroundLoader* loader = BackgroundLoader::GetInstance();
            for (int i = 0; i < (int)(sizeof(self->tasks_) / sizeof(self->tasks_[0])); i++)
            {
                if (self->tasks_[i] > BackgroundLoader::TaskStatus_Invalid)
                {
                    loader->RemoveTask(self->tasks_[i]);
                    self->tasks_[i] = -1;
                }
            }
        }
    }
    return self->result_;
}
