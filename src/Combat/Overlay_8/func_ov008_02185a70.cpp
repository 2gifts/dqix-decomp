#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#if defined(jpn)
#define func_ov008_02188d74 func_ov008_02189a9c
#define func_ov008_0218712c func_ov008_02188008
#define func_ov008_02187f6c func_ov008_02188ccc
#endif

#include <Memory/SafeAllocator.h>
#include <World/Object3D.h>
#include <Resource/MessageSystem.h>
#include <Filesystem/BackgroundLoader.h>

struct PlayTime {
    unsigned short hours_;
    unsigned char minutes_;
    unsigned char seconds_;
};

struct TextTable {
    int pad_0[0x18 / 4];
};

struct BackgroundGraphics {
    int pad_0[0x20 / 4];
};

struct TextWindow {
    int pad_0[0xbc / 4];
};

struct Canvas {
    char pad_0[0xc2];
    unsigned short unk_c2;
    char pad_c4[0xe0 - 0xc4];
};

struct WindowCursor {
    int pad_0[0x40 / 4];
};

struct GuideWindow {
    char pad_0[0x438];
    unsigned short flags_;
    char pad_43a[0x44c - 0x43a];
};

struct BattleRecords {
    SafeAllocator allocator_;
    SafeAllocator backgroundAllocator_;
    SafeAllocator textAllocator_;
    SafeAllocator spriteAllocator_;
    SafeAllocator iconAllocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator titleAllocator_;
    SafeAllocator guideAllocator_;
    TextTable texts_;
    char* text_;
    char titleTable_[0x14];
    BackgroundGraphics backgrounds_[3];
    TextWindow window_;
    Canvas canvases_[6];
    void* pixels_;
    void* renderer_;
    void* sprites_;
    void* animations_;
    void* iconRenderer_;
    void* iconSprite_;
    unsigned char items_[8];
    unsigned char itemCount_;
    WindowCursor cursor_;
    Object3D model_;
    char camera_[0x2c8];
    void* titles_;
    GuideWindow* guide_;
    void* page_;
    signed char state_;
    unsigned char step_;
    unsigned char loadStep_;
    unsigned char exit_;
    short title_;
    short comment_;
    int flags_;
    int unk_b1c;
    int task_;
    int mode_;
    unsigned char kind_;
    unsigned char top_;
    unsigned char closed_;
    int titleX_;
    const void* guest_;
    void* guestRecords_;
    void* guestTexts_;
    void* guestTitles_;
    PlayTime times_[2];

    int IsFlagSet(int flag)
    {
        return flags_ & flag ? 1 : 0;
    }
};

struct TouchState {
    char pad_0[0x55];
    unsigned char touching_;
};

extern unsigned short data_02114e30[];
extern TouchState data_02114e54;

struct GameResources;
struct Entry_0205d6a0;
struct Manager02187664;
struct Struct_0205d81c;

MessageSystem* GetGlobalField0x1c020421a0();
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* pad, int buttons);
void ResetEntryList0205d6a0(Entry_0205d6a0* window, int value);
void SetMainBrightness(GameResources* resources, int screen, int brightness);
void InitConfig02187664(Manager02187664* self, int records);
Canvas* FindElementByC40205d81c(Struct_0205d81c* window, int canvas);
int IsBrightnessTransitionActive(GameResources* resources);

extern "C" {
GameResources* func_ov017_0218b5b0();
void func_ov023_021eb138(GuideWindow* guide, int value);
void func_ov023_021eb080(GuideWindow* guide, SafeAllocator* allocator);
void func_ov023_021eb564(GuideWindow* guide, void* pages, int count);
void func_ov023_021eb26c(GuideWindow* guide);
void func_ov008_02186964(BattleRecords* self);
int func_ov008_02188d74(BattleRecords* self);
int func_ov008_02188a54(BattleRecords* self, int lastClear);
void func_ov008_0218712c(BattleRecords* self, void* records);
void func_ov008_02187a70(BattleRecords* self, void* records);
void func_ov008_02187f6c(BattleRecords* self, void* records);
void func_ov008_02186cec(BattleRecords* self);
}

// USA: func_ov008_02185a70
extern "C" ARM void func_ov008_02185a70(BattleRecords* self, unsigned int ticks)
{
    MessageSystem* messages = GetGlobalField0x1c020421a0();
    GameResources* resources = func_ov017_0218b5b0();
    BackgroundLoader::GetInstance();
    FontBankLoader* music = GetGlobal02109400_02094a00();
    unsigned char step = self->step_;
    if (step >= 2)
        messages->b19ae = 0;
    if (step == 0)
    {
        if (messages->mode != 3)
            return;
        self->step_++;
    }
    if (step == 1 && (TestFlag0SetAndFlag1Clear_02012444(data_02114e30, 0xff3) || data_02114e54.touching_))
        self->step_++;
    if (step == 2)
    {
        self->guide_ = (GuideWindow*)self->titleAllocator_.Allocate(sizeof(GuideWindow));
        func_ov023_021eb138(self->guide_, 0);
        func_ov023_021eb080(self->guide_, &self->titleAllocator_);
        func_ov023_021eb564(self->guide_, self->page_, 1);
        {
            int set = self->IsFlagSet(0x8000);
            GuideWindow* guide = self->guide_;
            if (set)
                guide->flags_ |= 0x400;
            else
                guide->flags_ &= ~0x400;
        }
        {
            int set = self->IsFlagSet(2);
            GuideWindow* guide = self->guide_;
            if (set)
                guide->flags_ |= 0x800;
            else
                guide->flags_ &= ~0x800;
        }
        self->step_++;
    }
    if (step == 3 && (self->guide_->flags_ & 4))
        self->step_++;
    if (step == 4)
    {
        func_ov023_021eb26c(self->guide_);
        self->titleAllocator_.Reset();
        self->guide_ = NULL;
        self->page_ = NULL;
        self->flags_ &= ~0x200000;
        func_ov008_02186964(self);
        int flags = self->flags_;
        if ((flags & 0x8000) || (flags & 2))
            self->flags_ &= ~0x200;
        self->flags_ &= ~0x8000;
        self->step_++;
    }
    if (step == 5)
    {
        ResetEntryList0205d6a0((Entry_0205d6a0*)&self->window_, 1);
        BlankFunction02094b40(music);
        BlankFunction02094b34(music, 0x6b, 0x1fc, 0, 0);
        self->step_++;
    }
    if (step == 6)
    {
        if (!AlwaysTrue02094b4c(music))
            return;
        if (func_ov008_02188d74(self))
        {
            self->step_++;
            step++;
        }
    }
    if (step == 7 && func_ov008_02188a54(self, 0))
    {
        SetMainBrightness(resources, 0, 0xf);
        func_ov008_0218712c(self, NULL);
        InitConfig02187664((Manager02187664*)self, 0);
        func_ov008_02187a70(self, NULL);
        func_ov008_02187f6c(self, NULL);
        for (int i = 0; i < 6; i++)
        {
            Canvas* canvas = FindElementByC40205d81c((Struct_0205d81c*)&self->window_, (unsigned char)i);
            if (canvas != NULL)
                canvas->unk_c2 = 0;
        }
        self->step_++;
    }
    if (step == 8 && !IsBrightnessTransitionActive(resources))
    {
        self->flags_ |= 0x2000;
        func_ov008_02186cec(self);
        self->state_ = 3;
        self->step_ = 0;
        self->flags_ |= 0x20000;
        if (self->flags_ & 2)
            self->kind_ = 7;
        func_ov008_02186964(self);
        self->step_ = 1;
    }
}
