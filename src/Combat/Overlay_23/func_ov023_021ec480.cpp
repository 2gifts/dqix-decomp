#include <globaldefs.h>
#include <std_library_functions.h>
#include <System/ColorEffects.h>

#define GUIDE_WINDOW_MAIN_SCREEN 8
#define GUIDE_WINDOW_NO_DIMMING 0x20
#define GUIDE_WINDOW_OPENING 0x40
#define GUIDE_WINDOW_TITLE_SCROLLING 0x80
#define GUIDE_WINDOW_SHOWN 0x100
#define GUIDE_WINDOW_UNK_400 0x400
#define GUIDE_WINDOW_UNK_800 0x800

#define REG_BLDCNT 0x04000050
#define REG_BLDCNT_SUB 0x04001050

struct GameResources;
struct Struct_0205d81c;
struct Struct0209c830;
struct Entry_0205d6a0;
struct Container020e0310;

struct BackgroundGraphics_021ec480 {
    char unk_0[0x1c];
    unsigned char unk_1c_0_ : 4;
    unsigned char unk_1c_4_ : 4;
    unsigned char unk_1d;
    char unk_1e[2];
};

struct MessageSystem_021ec480 {
#if defined(jpn)
    char unk_0[0x868];
#else
    char unk_0[0x998];
#endif
    int busy_;
#if defined(jpn)
    char unk_99c[0x17de - 0x86c];
#else
    char unk_99c[0x19ae - 0x99c];
#endif
    unsigned char unk_19ae;
    char unk_19af[0x19b2 - 0x19af];
    unsigned char unk_19b2;
#if defined(jpn)
    char unk_19b3[0x17f9 - 0x17e3];
#else
    char unk_19b3[0x19c8 - 0x19b3];
#endif
    unsigned char unk_19c8;
};

struct GuideWindow_021ec480 {
    void* allocators_;
    char texts_[0x18];
    char* text_;
    void* pages_;
    int count_;
    unsigned char page_;
    char unk_29;
    char unk_2a[0x10];
    unsigned char unk_3a;
    unsigned char unk_3b;
    unsigned int mainLayers_;
    unsigned int subLayers_;
    BackgroundGraphics_021ec480 backgrounds_[2];
    BackgroundGraphics_021ec480 subBackgrounds_[2];
    char window_[0xbc];
    char canvases_[3][0xe0];
    void* pixels_;
    void* renderer_;
    void* sprites_;
    void* animations_;
    unsigned char type_;
    unsigned char state_;
    unsigned char step_;
    unsigned char titleStep_;
    int task_;
    unsigned short flags_;
};

struct Bytes2_021ec480 {
    unsigned char b[2];
};

extern unsigned char data_ov023_021fd844[];
extern char data_02108760[];
extern char data_02109bf4[];

MessageSystem_021ec480* GetGlobalField0x1c020421a0();
int IsBrightnessTransitionActive(GameResources* resources);
void SetForwardAndStore0205ebc0(void* sound, int a, int b);
void DispatchIfField0xc4NonNeg_0205ebfc(void* sound, int a, int b);
void SetElementFieldC2(Struct_0205d81c* window, int item, int value);
void SetValueAndActivate0209c830(Struct0209c830* obj, int value);
int TestBitInByteArray(int a, unsigned char* b, int flag);
int IsAnimationActive0209ca2c(void* obj);
int DispatchIfFlagsOrByteSet_021ed014(struct GuideWindow_021ec480* window);
void ResetEntryList0205d6a0(Entry_0205d6a0* window, int value);
void ForwardField0xc0_0205ebec(void* sound);
const char* GetFieldByKey020e0434(Container020e0310* texts, int id);
void AppendString02042058(char* text, const char* append);
void ReinitController02043204(char* messages);

extern "C" {
GameResources* func_ov017_0218b5b0();
int func_ov023_021ed064(GuideWindow_021ec480* self);
void func_ov023_021ecbbc(GuideWindow_021ec480* self);
void func_ov023_021ed194(GuideWindow_021ec480* self);
void func_ov023_021ed354(GuideWindow_021ec480* self);
void func_ov023_021ed4b8(GuideWindow_021ec480* self);
void func_ov023_021ed600(GuideWindow_021ec480* self);
void* func_0205ec34();
#if defined(jpn)
void func_0204500c(MessageSystem_021ec480* messages, const char* text, int a);
#else
void func_0204500c(MessageSystem_021ec480* messages, const char* text, int a, int b);
#endif
}

static inline int WasButtonPressed(GuideWindow_021ec480* self)
{
    return DispatchIfFlagsOrByteSet_021ed014(self);
}

// USA: func_ov023_021ec480
extern "C" ARM void func_ov023_021ec480(GuideWindow_021ec480* self)
{
#if defined(jpn)
 enum {regionalOffset0=0x800};
#else
 enum {regionalOffset0=0x960};
#endif
    GameResources* resources = func_ov017_0218b5b0();
    MessageSystem_021ec480* messages = GetGlobalField0x1c020421a0();
    if (self->step_ >= 1 && self->step_ <= 3 && func_ov023_021ed064(self))
    {
        self->step_ = 4;
        return;
    }
    unsigned char step = self->step_;
    if (step == 0)
    {
        if (IsBrightnessTransitionActive(resources))
            return;
        if (!(self->flags_ & GUIDE_WINDOW_NO_DIMMING))
        {
            if (self->subBackgrounds_[1].unk_1c_0_ == 0)
                ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT, 0x17, -8);
            else
                ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, 0x17, -8);
        }
        int volume = 0x8c;
        if (self->type_ == 2 || (self->type_ == 7 && (self->flags_ & GUIDE_WINDOW_MAIN_SCREEN)))
            volume = 0x1b4;
        SetForwardAndStore0205ebc0(data_02108760, volume, volume);
        func_ov023_021ecbbc(self);
        self->step_++;
    }
    if (step == 1)
    {
        if (self->flags_ & GUIDE_WINDOW_OPENING)
            return;
        func_ov023_021ed194(self);
        self->flags_ |= GUIDE_WINDOW_TITLE_SCROLLING;
        DispatchIfField0xc4NonNeg_0205ebfc(data_02108760, 0, 0);
        self->step_++;
    }
    if (step == 2)
    {
        if (self->flags_ & GUIDE_WINDOW_TITLE_SCROLLING)
            return;
        func_ov023_021ed354(self);
        func_ov023_021ed4b8(self);
        unsigned char items[2];
        *(Bytes2_021ec480*)items = *(Bytes2_021ec480*)&data_ov023_021fd844[0xa];
        for (int i = 0; i < 2; i++)
            SetElementFieldC2((Struct_0205d81c*)self->window_, items[i], 0);
        SetValueAndActivate0209c830((Struct0209c830*)data_02109bf4, 0x40);
        self->step_++;
    }
    if (step == 3)
    {
        self->flags_ |= GUIDE_WINDOW_SHOWN;
        step++;
        self->step_++;
    }
    if (step == 4)
    {
        if (!(self->flags_ & GUIDE_WINDOW_SHOWN))
            return;
        if (self->flags_ & GUIDE_WINDOW_UNK_400)
        {
            void* unknown = func_0205ec34();
            if (self->page_ == self->count_ - 1 && TestBitInByteArray((int)unknown, (unsigned char*)unknown + 0x8c, 0x119a) &&
                IsAnimationActive0209ca2c(data_02109bf4))
                return;
        }
        if (WasButtonPressed(self))
            self->step_++;
    }
    if (step == 5)
    {
        int next = self->page_ + 1;
        if (next < self->count_)
        {
            ResetEntryList0205d6a0((Entry_0205d6a0*)self->window_, 1);
            self->page_ = next;
            self->step_ = 1;
            func_ov023_021ecbbc(self);
            return;
        }
        self->step_++;
    }
    if (step == 6)
    {
        ResetEntryList0205d6a0((Entry_0205d6a0*)self->window_, 0);
        ForwardField0xc0_0205ebec(data_02108760);
        if (!(self->flags_ & GUIDE_WINDOW_NO_DIMMING))
        {
            if (self->subBackgrounds_[1].unk_1c_0_ == 0)
                ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT, 0x17, 0);
            else
                ColorEffect_ConfigureBrightnessAdjust(REG_BLDCNT_SUB, 0x17, 0);
        }
        if (self->type_ == 0 || self->type_ == 1)
            ColorEffect_ConfigureAlphaBlend(REG_BLDCNT, 1, 2, 0xf, 0x1f);
        if (self->flags_ & GUIDE_WINDOW_UNK_400)
        {
            void* unknown = func_0205ec34();
            if (TestBitInByteArray((int)unknown, (unsigned char*)unknown + 0x8c, 0x119a))
            {
                self->step_++;
                return;
            }
        }
        else if (self->flags_ & GUIDE_WINDOW_UNK_800)
        {
            self->step_ = 10;
            return;
        }
        self->state_ = 2;
        self->step_ = 0;
    }
    if (step == 7)
    {
        if (self->subBackgrounds_[1].unk_1c_0_ == 0)
        {
            memset(self->text_, 0, regionalOffset0);
            AppendString02042058(self->text_, GetFieldByKey020e0434((Container020e0310*)self->texts_, 1000));
            AppendString02042058(self->text_, GetFieldByKey020e0434((Container020e0310*)self->texts_, 1002));
            messages->busy_ = 1;
#if defined(jpn)
            func_0204500c(messages, self->text_, 0);
#else
            func_0204500c(messages, self->text_, 0, 0xe3);
#endif
            messages->unk_19b2 = 0;
            messages->unk_19c8 = 0;
            messages->unk_19ae = 0;
        }
        else
        {
            func_ov023_021ed600(self);
            unsigned char items2[2];
            *(Bytes2_021ec480*)items2 = *(Bytes2_021ec480*)&data_ov023_021fd844[4];
            for (int i = 0; i < 2; i++)
                SetElementFieldC2((Struct_0205d81c*)self->window_, items2[i], 0);
        }
        SetValueAndActivate0209c830((Struct0209c830*)data_02109bf4, 0x40);
        self->step_++;
    }
    if (step == 8)
    {
        messages->unk_19ae = 0;
        if (IsAnimationActive0209ca2c(data_02109bf4))
            return;
        self->step_++;
        step++;
    }
    if (step == 9)
    {
        if (self->flags_ & GUIDE_WINDOW_UNK_800)
        {
            if (WasButtonPressed(self))
            {
                self->step_++;
                step++;
            }
        }
        else
        {
            step = 11;
            self->step_ = 11;
        }
    }
    if (step == 10)
    {
        memset(self->text_, 0, regionalOffset0);
        AppendString02042058(self->text_, GetFieldByKey020e0434((Container020e0310*)self->texts_, 1001));
        AppendString02042058(self->text_, GetFieldByKey020e0434((Container020e0310*)self->texts_, 1002));
        messages->busy_ = 1;
#if defined(jpn)
        func_0204500c(messages, self->text_, 0);
#else
        func_0204500c(messages, self->text_, 0, 0xe3);
#endif
        messages->unk_19b2 = 0;
        messages->unk_19c8 = 0;
        messages->unk_19ae = 0;
        SetValueAndActivate0209c830((Struct0209c830*)data_02109bf4, 0x40);
        self->step_++;
    }
    if (step == 11)
    {
        messages->unk_19ae = 0;
        if (IsAnimationActive0209ca2c(data_02109bf4))
            return;
        if (!WasButtonPressed(self))
            return;
        if (self->subBackgrounds_[1].unk_1c_0_ == 0)
        {
            ReinitController02043204((char*)messages);
            self->state_ = 2;
            self->step_ = 0;
            return;
        }
        ResetEntryList0205d6a0((Entry_0205d6a0*)self->window_, 0);
        self->state_ = 2;
        self->step_ = 0;
    }
}
