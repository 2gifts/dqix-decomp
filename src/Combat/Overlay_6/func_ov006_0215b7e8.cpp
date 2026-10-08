#include <globaldefs.h>

struct Obj0208203c;
struct Obj0205eaa0;
struct Obj2081;
struct Obj0215f348;
struct Cont0207fe44;
struct AlchemyPot;

struct LayoutElement {
    char unk_0[0x16];
    unsigned char flags_;
};

struct Menu {
    char unk_0[0x36];
    short cursor_;
};

struct AlchemyMenu {
    int textPosition_;
    char** texts_;
    void* canvasBuffer_;
    void* allocators_;
    AlchemyPot* pot_;
    Menu* menu_;
    void* choice_;
    void* backgrounds_;
    void* canvases_;
    void* sprites_;
    void* animations_;
    void* recipes_;
    void* pageStart_;
    void* recipe_;
    void* records_;
    char save_[8];
    short* cursor_;
    short** items_;
    unsigned char** counts_;
    unsigned short* sizes_;
    int subBackground_[0x20 / 4];
    int ingredients_[0x28 / 4];
    int repeat_[0xc / 4];
    unsigned short buttons_;
    unsigned char unk_aa;
    int renderer_[0x54 / 4];
    int layout_[0x4c / 4];
    int table_[0xc / 4];
    int menuTexts_[0x18 / 4];
    char itemNames_[0xc];
    int results_[4][0x74 / 4];
    int ticks_;
    int menuResult_;
    int task_;
    int unk_358;
    short unk_35c;
    short previousCursor_;
    short mainCursor_;
    short categoryCursor_;
    short itemCursor_;
    short bookCursor_;
    short filterCursor_;
    short recipeCursor_;
    short choiceCursor_;
    short group_;
    short item_;
    unsigned short categories_[3];
    short chosenItems_[3];
    short message_;
    unsigned short messageLength_;
    short successRate_;
    signed char filterCategory_;
    signed char filterKind_;
    unsigned char sort_;
    unsigned char times_;
    unsigned char page_;
    unsigned char pages_;
    unsigned char category_;
    unsigned char count_;
    unsigned char chosenCounts_[3];
    unsigned char state_;
    unsigned char step_;
    unsigned char unk_391;
    unsigned char messageStep_;
    unsigned char repeatDelay_;
    unsigned short flags_;
    unsigned char female_;
    unsigned char background_;
    unsigned char amounts_[3];
    int textSound_;
    int unk_3a0;
    int textSoundOn_;
    unsigned int textSoundTimer_;
    int textSoundPlaying_;
    int textSoundState_;
    int showResult_;
    int resultSprite_[0x70 / 4];
    int resultTask_;
    signed char arrowTimer_;
    unsigned char fadeTimer_;
    unsigned char nextStep_;
    unsigned char saved_;
    unsigned char arrowUp_;
    unsigned char arrowDown_;
    unsigned char resetBlend_;
    unsigned char closing_;
    unsigned char closeRequested_;
};

extern "C" void func_ov006_021570fc(AlchemyPot* pot, int shown);
short FindMappedMemberId02080468(void* menu, int group);
extern "C" void func_020813ec(void* menu, int group);
void SyncEntries0215f348(Obj0215f348* self);
void SetElementFlag0x40(Obj2081* menu, int group, int value);
void ResetWithSub0208203c(Obj0208203c* repeat);
void SetElementFlag0x20(Obj2081* menu, int id);
void ClearElementFlag0x20(Obj2081* menu, int id);
extern "C" unsigned char func_ov006_02158a28(AlchemyMenu* self);
extern "C" unsigned char func_ov006_02158b78(AlchemyMenu* self);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0* sound, int, int);
void CallFunc0204c804OverAllElems(Cont0207fe44* menu);
extern "C" LayoutElement* func_ov006_02157368(void* layout, short id);
extern "C" void func_ov006_02158de0(AlchemyMenu* self);
void CallFunc0204c804OnMatchingKey(Obj2081* menu, int group);
int TestFlag0SetAndFlag1Clear(unsigned short* pad, int buttons);

extern "C" char data_02108760[];
extern "C" unsigned short data_02114e30[];

// USA: func_ov006_0215b7e8
extern "C" ARM void func_ov006_0215b7e8(AlchemyMenu* self) {
    Menu* menu = self->menu_;
    if (self->step_ == 0)
    {
        func_ov006_021570fc(self->pot_, 1);
        self->background_ = 0;
        self->group_ = 2;
        if (self->mainCursor_ < 0)
            self->mainCursor_ = FindMappedMemberId02080468(menu, self->group_);
        menu->cursor_ = self->mainCursor_;
        func_020813ec(menu, self->group_);
        SyncEntries0215f348((Obj0215f348*)self);
        SetElementFlag0x40((Obj2081*)menu, self->group_, 0);
        ResetWithSub0208203c((Obj0208203c*)self->repeat_);
        self->cursor_ = 0;
        self->step_++;
        if (self->mainCursor_ == 4)
            SetElementFlag0x20((Obj2081*)menu, 3);
        else
            ClearElementFlag0x20((Obj2081*)menu, 3);
    }
    else if (self->step_ == 1)
    {
        self->cursor_ = &self->mainCursor_;
        if (self->previousCursor_ != *self->cursor_)
        {
            if (self->mainCursor_ == 4)
                SetElementFlag0x20((Obj2081*)menu, 3);
            else
                ClearElementFlag0x20((Obj2081*)menu, 3);
            SyncEntries0215f348((Obj0215f348*)self);
        }
        self->arrowTimer_ = 0;
        if (func_ov006_02158a28(self))
        {
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)data_02108760, 1, 0);
            ResetWithSub0208203c((Obj0208203c*)self->repeat_);
            self->cursor_ = 0;
            switch (self->mainCursor_)
            {
            case 2:
                self->bookCursor_ = -1;
                CallFunc0204c804OverAllElems((Cont0207fe44*)menu);
                self->state_ = 9;
                self->step_ = 0;
                {
                    LayoutElement* element = func_ov006_02157368(self->layout_, 0x50);
                    if (element != 0)
                        element->flags_ &= ~1;
                }
                {
                    LayoutElement* element = func_ov006_02157368(self->layout_, 0x4f);
                    if (element != 0)
                        element->flags_ |= 1;
                }
                {
                    LayoutElement* element = func_ov006_02157368(self->layout_, 0xe);
                    if (element != 0)
                        element->flags_ &= ~1;
                }
                {
                    LayoutElement* element = func_ov006_02157368(self->layout_, 0xf);
                    if (element != 0)
                        element->flags_ |= 1;
                }
                {
                    LayoutElement* element = func_ov006_02157368(self->layout_, 0x15);
                    if (element != 0)
                        element->flags_ &= ~1;
                }
                break;
            case 3:
            {
                func_ov006_02158de0(self);
                unsigned short* sizes = self->sizes_;
                unsigned char i;
                int found = 0;
                if (sizes != 0)
                {
                    for (i = 0; i < 9; i++)
                    {
                        if (sizes[i] != 0)
                        {
                            found = 1;
                            break;
                        }
                    }
                    if (sizes[8] != 0)
                        found = 1;
                }
                if (found)
                {
                    self->categoryCursor_ = -1;
                    self->itemCursor_ = -1;
                    CallFunc0204c804OverAllElems((Cont0207fe44*)menu);
                    self->state_ = 5;
                    self->step_ = 0;
                    func_ov006_021570fc(self->pot_, 1);
                    self->message_ = 0x24;
                    self->messageStep_ = 0;
                    self->flags_ |= 0x20 | 0x100;
                    break;
                }
                self->flags_ |= 0x20;
                self->message_ = 0x35;
                self->messageStep_ = 0;
                SetElementFlag0x40((Obj2081*)menu, self->group_, 1);
                self->step_ = 0;
                ResetWithSub0208203c((Obj0208203c*)self->repeat_);
                self->cursor_ = 0;
                return;
            }
            case 4:
                self->state_ = 0xc;
                self->step_ = 0;
                break;
            }
            CallFunc0204c804OnMatchingKey((Obj2081*)menu, 3);
            CallFunc0204c804OnMatchingKey((Obj2081*)menu, self->group_);
            return;
        }
        if (func_ov006_02158b78(self) || TestFlag0SetAndFlag1Clear(data_02114e30, 0x800))
        {
            CallFunc0204c804OverAllElems((Cont0207fe44*)menu);
            self->state_ = 0xc;
            self->step_ = 0;
        }
    }
}
