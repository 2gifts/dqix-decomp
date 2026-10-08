#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "System/Graphics.h"
#include "System/Cache.h"
#include "System/LoadToVRAM.h"
#include "std_library_functions.h"

struct Messages021863fc
{
    char unk_0[0x5c];
    void* unk_5c;
    char unk_60[0x998 - 0x60];
    int busy_;
};

struct Appearance021863fc
{
    short models_[10];
    unsigned char female_ : 1;
    unsigned char eyeColor_ : 3;
    unsigned char skinColor_ : 4;
};

struct Party021863fc
{
    char unk_0[0x488];
    Appearance021863fc appearance_;
};

struct Member021863fc
{
    char unk_0[0x150];
    Party021863fc* partyData_;
};

struct Profile021863fc
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

struct Card021863fc
{
    char unk_0[0x5f4];
    void* strings_;
    void* texts_;
    char* unk_5fc;
    char unk_600[4];
    void* renderer_;
    void* sprites_;
    char unk_60c[0x614 - 0x60c];
};

struct ProfileEditor021863fc
{
    char unk_0[0x20];
    SafeAllocator allocators_[7];
    char unk_ac[0xd28 - 0xac];
    Card021863fc card_;
    char strings_[8];
    char texts_[0x18];
    void* renderer_;
    void* unk_1360;
    void* sprites_;
    void* renderer2_;
    void* sprites2_;
    unsigned char step_;
    unsigned char state_;
    char unk_1372[2];
    char* text_;
    const char* unk_1378;
    void* pixels_;
    int tasks_[6];
    char unk_1398[0x13bc - 0x1398];
    char* unk_13bc;
    signed char* unk_13c0;
    unsigned short unk_13c4_0 : 5;
    unsigned short unk_13c4_5 : 11;
    char unk_13c6[2];
    unsigned short* unk_13c8;
    unsigned int* unk_13cc;
};

struct TableA68;

int GetWord0x0(int* gameState);
void* GetGlobal02109400();
int IsField0Null(void** p);
void SetBitsInWord(unsigned int* word, unsigned int bits);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v();
void OrBitsIntoField0(unsigned int* word, unsigned int bits);
extern "C" Messages021863fc* _Z26GetGlobalField0x1c020421a0v();
void OrGlobalFlag0x40();
extern "C" void func_ov012_02185e18(ProfileEditor021863fc* self);
extern "C" void _Z26ClearAndCopyEntry_02185ea8Pc(char* self);
extern "C" void _Z29ResetAndRebuildEntry_02185f04Pc(char* self);
extern "C" void func_ov012_02185f74(ProfileEditor021863fc* self);
extern "C" void func_ov012_021861e0(ProfileEditor021863fc* self);
extern "C" void func_ov012_021862fc(ProfileEditor021863fc* self);
extern "C" void func_ov012_02184654(ProfileEditor021863fc* self);
extern "C" void func_02094ab0();
extern "C" void _Z21BlankFunction02094b34v(void* music, int a, int b, int c, int d);
void SetSubBrightness(GameResources* resources, int brightness, int frames);
extern "C" int _Z18AlwaysTrue02094b4cv();
int IsSubBrightnessTransitionActive(GameResources* resources);
extern "C" void func_ov023_021e7220(void* card, int mode);
extern "C" void _Z30CreateThreeAllocators_021e71b4PvP13SafeAllocator(void* card, SafeAllocator* allocator);
extern "C" int func_ov023_021e76c4(void* card);
int GetField0x3acValue(GameState* gameState);
extern "C" void func_ov023_021e7b34(void* card, int design);
extern "C" void func_ov012_0218adac(ProfileEditor021863fc* self, int animate, int design, int keepPage);
extern "C" void* func_0205ec34();
int TestBitInByteArray(int a, unsigned char* bits, int index);
const char* FindEntryByKey(TableA68* table, int key);
extern "C" void func_0204500c(Messages021863fc* messages, const char* text, int a, int b);

extern "C" const char data_ov012_0218b224[];
extern "C" const char data_ov012_0218b23b[];
extern "C" const char data_ov012_0218b24e[];
extern "C" const char data_ov012_0218b263[];
extern "C" const char data_ov012_0218b274[];
extern "C" const char data_ov012_0218b289[];
extern "C" const char data_ov012_0218b29a[];
extern "C" const char data_ov012_0218b2ad[];
extern "C" const char data_ov012_0218b2c2[];
extern "C" const char data_ov012_0218b2d3[];

static inline Profile021863fc* GetProfile021863fc(GameState* gameState)
{
    return (Profile021863fc*)((char*)gameState + 0x569c);
}

// USA: func_ov012_021863fc
extern "C" ARM void func_ov012_021863fc(ProfileEditor021863fc* self)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = (GameResources*)GetWord0x0((int*)gameState);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GetGlobal02109400();
    if (self->step_ == 0)
    {
        if (IsField0Null(*(void***)((char*)resources + 0x3700)))
        {
            SetBitsInWord((unsigned int*)resources, 0x10);
            OrBitsIntoField0((unsigned int*)_Z27GetDataPtr02114e04_020d6c00v(), 0xf);
            self->text_ = (char*)_Z26GetGlobalField0x1c020421a0v()->unk_5c;
            unsigned int female = 0;
            Member021863fc* protagonist = (Member021863fc*)gameState->GetProtagonist();
            if (protagonist != 0)
                female = protagonist->partyData_->appearance_.female_;
            char archive[0x40];
            char file[0x20];
            sprintf(archive, data_ov012_0218b224, female);
            sprintf(file, data_ov012_0218b23b, female);
            self->tasks_[0] = loader->QueueLoadFileInGP2(data_ov012_0218b24e, data_ov012_0218b263, 0);
            self->tasks_[1] = loader->QueueLoadFileInGP2(data_ov012_0218b274, data_ov012_0218b289, 0);
            self->tasks_[2] = loader->QueueLoadFileInGP2(archive, file, 0);
            self->tasks_[3] = loader->QueueLoadFile(data_ov012_0218b29a, 0);
            self->tasks_[4] = loader->QueueLoadFileInGP2(data_ov012_0218b2ad, data_ov012_0218b2c2, 0);
            self->tasks_[5] = loader->QueueLoadFile(data_ov012_0218b2d3, 0);
            OrGlobalFlag0x40();
            self->step_++;
        }
        return;
    }
    else if (self->step_ == 1)
    {
        int i;
        int done = 0;
        for (i = 0; i < 6; i++)
        {
            if (self->tasks_[i] == -1)
            {
                done++;
            }
            else if (loader->GetTaskStatus(self->tasks_[i]))
            {
                switch (i)
                {
                    case 0:
                        func_ov012_02185e18(self);
                        break;
                    case 1:
                        _Z26ClearAndCopyEntry_02185ea8Pc((char*)self);
                        break;
                    case 2:
                        _Z29ResetAndRebuildEntry_02185f04Pc((char*)self);
                        break;
                    case 3:
                        func_ov012_02185f74(self);
                        break;
                    case 4:
                        func_ov012_021861e0(self);
                        break;
                    case 5:
                        func_ov012_021862fc(self);
                        break;
                }
                break;
            }
        }
        if (done == 6)
            self->step_++;
        return;
    }
    else if (self->step_ == 2)
    {
        func_ov012_02184654(self);
        BG0CNT = (BG0CNT & ~3) | 3;
        BG1CNT = (BG1CNT & ~3) | 2;
        BG2CNT = (BG2CNT & ~3) | 1;
        BG3CNT = (BG3CNT & ~3) | 0;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1f00;
        void* music = GetGlobal02109400();
        func_02094ab0();
        _Z21BlankFunction02094b34v(music, 0x6e, 0x1ff, 0, 0);
        SetSubBrightness(resources, -16, 15);
        self->step_++;
        return;
    }
    else if (self->step_ == 3)
    {
        GetGlobal02109400();
        if (_Z18AlwaysTrue02094b4cv() && !IsSubBrightnessTransitionActive(resources))
        {
            OrGlobalFlag0x40();
            self->allocators_[2].Reset();
            func_ov023_021e7220(&self->card_, 2);
            _Z30CreateThreeAllocators_021e71b4PvP13SafeAllocator(&self->card_, &self->allocators_[2]);
            self->card_.strings_ = &self->strings_;
            self->card_.texts_ = &self->texts_;
            self->card_.unk_5fc = self->unk_13bc;
            self->card_.renderer_ = self->renderer2_;
            self->card_.sprites_ = self->sprites2_;
            self->step_++;
            return;
        }
    }
    else if (self->step_ == 4)
    {
        if (func_ov023_021e76c4(&self->card_))
        {
            func_ov023_021e7b34(&self->card_, GetField0x3acValue(gameState));
            func_ov012_0218adac(self, 1, -1, 0);
            SetSubBrightness(resources, 0, 15);
            void* unk = func_0205ec34();
            for (int i = 0; i < 0x12; i++)
            {
                if (TestBitInByteArray((int)unk, (unsigned char*)unk + 0x8c, i + 0x200))
                {
                    self->unk_13c0[self->unk_13c4_0] = i;
                    self->unk_13c4_0++;
                }
            }
            for (int i = 0; i < 0x1e0; i++)
            {
                if (self->unk_13cc[i / 32] & (1 << (i % 32)))
                {
                    self->unk_13c8[self->unk_13c4_5] = i;
                    self->unk_13c4_5++;
                }
            }
            Profile021863fc* profile = GetProfile021863fc(gameState);
            if (profile->edited_ == 0)
            {
                self->step_++;
            }
            else
            {
                self->state_ = 1;
                self->step_ = 0;
            }
            unsigned short color = 0x294a;
            void* pixels = self->pixels_;
            memcpy(pixels, &color, sizeof(color));
            CleanInvalidateCacheRange(pixels, sizeof(color));
            LoadToMainBGStandardPalette(pixels, 4, sizeof(color));
            CleanCacheRange(pixels, sizeof(color));
            unsigned short color2 = 0x1ce7;
            void* pixels2 = self->pixels_;
            memcpy(pixels2, &color2, sizeof(color2));
            CleanInvalidateCacheRange(pixels2, sizeof(color2));
            LoadToMainBGStandardPalette(pixels2, 8, sizeof(color2));
            CleanCacheRange(pixels2, sizeof(color2));
            return;
        }
    }
    else if (self->step_ == 5)
    {
        Messages021863fc* messages = _Z26GetGlobalField0x1c020421a0v();
        func_0204500c(messages, FindEntryByKey((TableA68*)self->strings_, 500), 0, 0xe3);
        messages->busy_ = 1;
        self->step_++;
        return;
    }
    else if (self->step_ == 6)
    {
        if (_Z26GetGlobalField0x1c020421a0v()->busy_ == 0)
        {
            GetProfile021863fc(gameState)->edited_ = 1;
            self->state_ = 1;
            self->step_ = 0;
        }
    }
}
