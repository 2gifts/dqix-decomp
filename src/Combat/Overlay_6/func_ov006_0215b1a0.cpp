#include <globaldefs.h>

struct Obj0208203c;
struct Obj0205eaa0;
struct Obj2081;
struct Container02071ffc;
struct StructC28;
struct AlchemyPot;
struct Recipe;

struct Menu {
    char unk_0[0x36];
    short cursor_;
};

struct RecipeTable {
    Recipe* unk_0;
    int unk_4[2];
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
    Recipe* recipes_;
    Recipe* pageStart_;
    Recipe* recipe_;
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
    RecipeTable table_;
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

extern "C" void func_ov006_0215fa1c(AlchemyMenu* self, int total);
extern "C" void func_020813ec(void* menu, int group);
void ResetWithSub0208203c(Obj0208203c* repeat);
extern "C" unsigned char func_ov006_02158a28(AlchemyMenu* self);
extern "C" unsigned char func_ov006_02158b78(AlchemyMenu* self);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0* sound, int, int);
void SetFlagsSequence_0215729c(void* layout);
void FilterAndSortEntries02071ffc(Container02071ffc* table, int category, int kind, int sort, short max, short* count);
void ComputeField_02158cac_02158cac(void* self);
void CallFunc0204c804OnMatchingKey(Obj2081* menu, int group);
int TestFlag0SetAndFlag1Clear(unsigned short* pad, int buttons);
extern "C" void func_ov006_0215745c(short filter, signed char* category, signed char* kind);
void ClearField44IfSet_02158c28(StructC28* self);

extern "C" char data_02108760[];
extern "C" unsigned short data_02114e30[];

// USA: func_ov006_0215b1a0
extern "C" ARM void func_ov006_0215b1a0(AlchemyMenu* self) {
    if (self->step_ == 0)
    {
        self->background_ = 2;
        func_ov006_0215fa1c(self, 1);
        self->group_ = 8;
        if (self->bookCursor_ < 0)
            self->bookCursor_ = 0x24;
        self->menu_->cursor_ = self->bookCursor_;
        func_020813ec(self->menu_, self->group_);
        ResetWithSub0208203c((Obj0208203c*)self->repeat_);
        self->cursor_ = 0;
        self->step_++;
    }
    else if (self->step_ == 1)
    {
        self->cursor_ = &self->bookCursor_;
        if (func_ov006_02158a28(self))
        {
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)data_02108760, 1, 0);
            ResetWithSub0208203c((Obj0208203c*)self->repeat_);
            int open = 0;
            self->cursor_ = 0;
            self->filterCursor_ = -1;
            self->recipeCursor_ = -1;
            self->filterCategory_ = -1;
            self->filterKind_ = -1;
            switch (self->bookCursor_)
            {
            case 0x24:
                open = 1;
                break;
            case 0x25:
                self->filterCategory_ = 0;
                self->step_++;
                break;
            case 0x26:
                self->step_++;
                break;
            case 0x27:
                self->filterCategory_ = 7;
                open = 1;
                break;
            case 0x28:
                self->filterCategory_ = 8;
                open = 1;
                break;
            }
            if (open)
            {
                self->state_ = 3;
                self->step_ = 0;
                SetFlagsSequence_0215729c(self->layout_);
                self->flags_ |= 0x80;
            }
            short count = 0;
            FilterAndSortEntries02071ffc((Container02071ffc*)&self->table_, self->filterCategory_, self->filterKind_, self->sort_, 0x10, &count);
            Recipe* recipes = self->table_.unk_0;
            self->recipes_ = recipes;
            self->pageStart_ = recipes;
            ComputeField_02158cac_02158cac(self);
            CallFunc0204c804OnMatchingKey((Obj2081*)self->menu_, 8);
            return;
        }
        if (func_ov006_02158b78(self) || TestFlag0SetAndFlag1Clear(data_02114e30, 0x800))
        {
            *self->cursor_ = -1;
            self->cursor_ = 0;
            self->state_ = 0xc;
            self->step_ = 0;
        }
    }
    else if (self->step_ == 2)
    {
        self->background_ = 2;
        func_ov006_0215fa1c(self, 0);
        short book = self->bookCursor_;
        if (book == 0x25)
        {
            self->group_ = 0xc;
            if (self->filterCursor_ < 0)
                self->filterCursor_ = 0x48;
        }
        else if (book == 0x26)
        {
            self->group_ = 0xb;
            if (self->filterCursor_ < 0)
                self->filterCursor_ = 0x40;
        }
        self->menu_->cursor_ = self->filterCursor_;
        func_020813ec(self->menu_, self->group_);
        ResetWithSub0208203c((Obj0208203c*)self->repeat_);
        self->cursor_ = 0;
        self->step_++;
    }
    else if (self->step_ == 3)
    {
        self->cursor_ = &self->filterCursor_;
        if (func_ov006_02158a28(self))
        {
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)data_02108760, 1, 0);
            self->state_ = 3;
            self->step_ = 0;
            self->cursor_ = 0;
            self->recipeCursor_ = -1;
            func_ov006_0215745c(self->filterCursor_, &self->filterCategory_, &self->filterKind_);
            short count = 0;
            FilterAndSortEntries02071ffc((Container02071ffc*)&self->table_, self->filterCategory_, self->filterKind_, self->sort_, 0x10, &count);
            Recipe* recipes = self->table_.unk_0;
            self->recipes_ = recipes;
            self->pageStart_ = recipes;
            ComputeField_02158cac_02158cac(self);
            CallFunc0204c804OnMatchingKey((Obj2081*)self->menu_, self->group_);
            self->state_ = 3;
            self->step_ = 0;
            SetFlagsSequence_0215729c(self->layout_);
            self->flags_ |= 0x80;
            return;
        }
        if (func_ov006_02158b78(self))
        {
            self->filterCursor_ = -1;
            CallFunc0204c804OnMatchingKey((Obj2081*)self->menu_, self->group_);
            self->step_ = 0;
        }
        ClearField44IfSet_02158c28((StructC28*)self);
    }
}
