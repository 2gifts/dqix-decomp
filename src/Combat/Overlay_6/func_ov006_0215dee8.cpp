#include <globaldefs.h>

struct Obj0208203c;
struct Obj0205eaa0;
struct Obj2081;
struct ClearFlag40_02157184Struct;
struct StructC28;

struct Recipe {
    short id_;
    short item_;
    char unk_4[0x18];
    Recipe* next_;
};

struct RecipeRecord {
    short id_;
    unsigned short known_ : 1;
    unsigned short made_ : 1;
    unsigned short unk_2_2 : 14;
};

struct AlchemyPot {
    char unk_0[0x1258];
    unsigned short windowFlags_;
};

struct Menu {
    char unk_0[0x36];
    short cursor_;
};

class GameState {
public:
    static GameState* GetInstance();
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

void CallFunc0204c804OnMatchingKey(Obj2081* menu, int group);
extern "C" void func_ov006_0215fa1c(AlchemyMenu* self, int total);
extern "C" void func_ov006_0215fb7c(AlchemyMenu* self);
extern "C" void func_ov006_0215fcf0(AlchemyMenu* self);
extern "C" void func_ov006_0215f7e8(AlchemyMenu* self);
void ResetWithSub0208203c(Obj0208203c* repeat);
Recipe* FindNodeOrMark_02158d8c(void* self, short index);
extern "C" RecipeRecord* func_ov006_02153c6c(void* ingredients, short id);
extern "C" void func_ov006_02153b9c(void* ingredients, short id, unsigned char* amounts);
extern "C" void func_ov006_021555b0(AlchemyPot* pot, Recipe* recipe, RecipeRecord* record, unsigned char* amounts);
extern "C" unsigned char func_ov006_02159bb0(AlchemyMenu* self);
extern "C" void func_ov006_02159c64(AlchemyMenu* self);
extern "C" void func_ov006_021570fc(AlchemyPot* pot, int shown);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0* sound, int, int);
extern "C" unsigned char func_ov006_02158a28(AlchemyMenu* self);
extern "C" unsigned char func_ov006_02158b78(AlchemyMenu* self);
extern "C" int func_ov006_021537d0(void* ingredients, short id);
void SetElementFlag0x40(Obj2081* menu, int group, int value);
void ClearFlag40_02157184(ClearFlag40_02157184Struct* pot);
void ClearField44IfSet_02158c28(StructC28* self);
extern "C" void func_ov006_02159db0(AlchemyMenu* self);
extern "C" signed char func_ov006_02159e50(AlchemyMenu* self);
extern "C" void _Z13Func_0215a33cP11Obj0215a33c(AlchemyMenu* self, int great);
extern "C" unsigned char func_ov006_0215a384(AlchemyMenu* self, int great);
extern "C" void func_ov006_0215fe34(AlchemyMenu* self, void* result);
extern "C" unsigned char func_ov006_0215fecc(AlchemyMenu* self);
int GetField0x3acValue(GameState* gameState);
extern "C" int func_020dd4c4(signed char member, void* results);
extern "C" int func_ov006_02153a78(void* ingredients, int times);
void SetEntryLowNibbleAndElement02080c68(void* menu, int id, int value);
extern "C" void func_ov006_0215f9e8(AlchemyMenu* self);
extern "C" unsigned char func_ov006_021599c0(AlchemyMenu* self);
int TestFlag0SetAndFlag1Clear(unsigned short* pad, int buttons);
extern "C" void func_ov006_0215a5dc(AlchemyMenu* self);
extern "C" unsigned char _Z26CheckFlagOrByte55_02158c70v(AlchemyMenu* self);

extern "C" char data_02108760[];
extern "C" unsigned short data_02114e30[];

// USA: func_ov006_0215dee8
extern "C" ARM void func_ov006_0215dee8(AlchemyMenu* self) {
    if (self->step_ == 0)
    {
        self->background_ = 1;
        CallFunc0204c804OnMatchingKey((Obj2081*)self->menu_, 0);
        CallFunc0204c804OnMatchingKey((Obj2081*)self->menu_, 1);
        func_ov006_0215fa1c(self, 0);
        func_ov006_0215fb7c(self);
        func_ov006_0215fcf0(self);
        self->group_ = 9;
        if (self->recipeCursor_ < 0)
            self->recipeCursor_ = 0x29;
        self->menu_->cursor_ = self->recipeCursor_;
        func_ov006_0215f7e8(self);
        ResetWithSub0208203c((Obj0208203c*)self->repeat_);
        self->cursor_ = 0;
        self->step_++;
    }
    else if (self->step_ == 1)
    {
        self->cursor_ = &self->recipeCursor_;
        int result = self->menuResult_;
        int pageChanged = 0;
        if (result & 0x10)
        {
            pageChanged = 1;
            self->page_++;
        }
        else if (result & 0x20)
        {
            pageChanged = 1;
            self->page_--;
        }
        if (self->page_ == 0xff)
            self->page_ = self->pages_ - 1;
        if (self->pages_ <= self->page_)
            self->page_ = 0;
        Recipe* recipe = FindNodeOrMark_02158d8c(self, self->recipeCursor_ - 0x29);
        RecipeRecord* record = 0;
        if (recipe != 0)
        {
            record = func_ov006_02153c6c(self->ingredients_, recipe->id_);
            func_ov006_02153b9c(self->ingredients_, recipe->id_, self->amounts_);
        }
        func_ov006_021555b0(self->pot_, recipe, record, self->amounts_);
        if (pageChanged)
        {
            func_ov006_0215f7e8(self);
            return;
        }
        unsigned char button = func_ov006_02159bb0(self);
        if (button == 1)
        {
            func_ov006_02159c64(self);
            return;
        }
        if (button == 4)
        {
            if (recipe != 0 && record != 0)
            {
                AlchemyPot* pot = self->pot_;
                int shown = (pot->windowFlags_ & 0x800) ? 1 : 0;
                func_ov006_021570fc(pot, shown == 0 ? 1 : 0);
                DispatchWithShortB4_0205eaa0((Obj0205eaa0*)data_02108760, 1, 0);
                return;
            }
            return;
        }
        if (func_ov006_02158a28(self) || button == 2)
        {
            if (recipe != 0 && record != 0)
            {
                if (!record->made_)
                    return;
                self->recipe_ = recipe;
                self->menu_->cursor_ = *self->cursor_;
                DispatchWithShortB4_0205eaa0((Obj0205eaa0*)data_02108760, 1, 0);
                ResetWithSub0208203c((Obj0208203c*)self->repeat_);
                self->cursor_ = 0;
                if (func_ov006_021537d0(self->ingredients_, recipe->id_))
                {
                    SetElementFlag0x40((Obj2081*)self->menu_, 9, 1);
                    self->message_ = 3;
                    self->messageStep_ = 0;
                    self->flags_ |= 0x20;
                    self->count_ = 1;
                    self->times_ = 1;
                    self->step_++;
                    return;
                }
                SetElementFlag0x40((Obj2081*)self->menu_, 9, 1);
                self->message_ = 2;
                self->messageStep_ = 0;
                self->flags_ |= 0x20;
                self->step_ = 0x64;
                return;
            }
        }
        else if (func_ov006_02158b78(self) || button == 3)
        {
            if (button == 3)
                DispatchWithShortB4_0205eaa0((Obj0205eaa0*)data_02108760, 1, 0);
            CallFunc0204c804OnMatchingKey((Obj2081*)self->menu_, self->group_);
            CallFunc0204c804OnMatchingKey((Obj2081*)self->menu_, 0xe);
            CallFunc0204c804OnMatchingKey((Obj2081*)self->menu_, 0xf);
            self->state_ = 9;
            self->step_ = 0;
            ResetWithSub0208203c((Obj0208203c*)self->repeat_);
            self->cursor_ = 0;
            ClearFlag40_02157184((ClearFlag40_02157184Struct*)self->pot_);
            self->background_ = 2;
            if (self->bookCursor_ == 0x25 || self->bookCursor_ == 0x26)
                self->step_ = 2;
            self->flags_ &= ~0x80;
        }
        ClearField44IfSet_02158c28((StructC28*)self);
    }
    else if (self->step_ == 2)
    {
        func_ov006_02159db0(self);
        self->step_++;
    }
    else if (self->step_ == 3)
    {
        signed char choice = func_ov006_02159e50(self);
        if (choice != -1)
        {
            if (choice != 1)
                return;
            _Z13Func_0215a33cP11Obj0215a33c(self, 0);
            self->step_++;
            return;
        }
        self->step_ = 0;
    }
    else if (self->step_ == 4)
    {
        self->arrowTimer_ = 0;
        if (self->resultTask_ == -1)
        {
            unsigned char done = func_ov006_0215a384(self, 0);
            if (done == 0)
                return;
            func_ov006_0215fe34(self, self->results_);
            return;
        }
        else
        {
            unsigned char done = func_ov006_0215fecc(self);
            if (done == 0)
                return;
            self->showResult_ = 0;
            if (!(func_020dd4c4(GetField0x3acValue(GameState::GetInstance()), self->results_) & 4))
            {
                self->step_ = 7;
                return;
            }
            self->message_ = self->female_ + 4;
            self->messageStep_ = 0;
            self->step_++;
        }
    }
    else if (self->step_ == 5)
    {
        func_ov006_02159db0(self);
        self->step_++;
    }
    else if (self->step_ == 6)
    {
        signed char choice = func_ov006_02159e50(self);
        if (choice != -1)
        {
            if (choice == 1)
                self->step_++;
            return;
        }
        self->step_ = 0;
    }
    else if (self->step_ == 7)
    {
        if (func_ov006_02153a78(self->ingredients_, 2))
        {
            self->message_ = 6;
            self->messageStep_ = 0;
            self->step_++;
            return;
        }
        self->message_ = 8;
        self->messageStep_ = 0;
        self->state_ = 0xb;
        ClearFlag40_02157184((ClearFlag40_02157184Struct*)self->pot_);
        self->step_ = 0;
    }
    else if (self->step_ == 8)
    {
        SetEntryLowNibbleAndElement02080c68(self->menu_, 9, 1);
        func_ov006_0215f9e8(self);
        self->flags_ |= 8;
        self->repeatDelay_ = 0;
        self->step_++;
    }
    else if (self->step_ == 9)
    {
        self->arrowTimer_ = 0;
        unsigned char result = func_ov006_021599c0(self);
        if (result == 1)
            return;
        if (TestFlag0SetAndFlag1Clear(data_02114e30, 1) || result == 2)
        {
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)data_02108760, 1, 0);
            ResetWithSub0208203c((Obj0208203c*)self->repeat_);
            self->cursor_ = 0;
            self->times_ = self->count_;
            CallFunc0204c804OnMatchingKey((Obj2081*)self->menu_, 0xa);
            self->state_ = 0xb;
            ClearFlag40_02157184((ClearFlag40_02157184Struct*)self->pot_);
            self->step_ = 0;
            self->message_ = 7;
            self->messageStep_ = 0;
            self->flags_ &= ~8;
            return;
        }
        unsigned char cancelled = func_ov006_02158b78(self);
        if (cancelled == 0 && result != 3)
            return;
        CallFunc0204c804OnMatchingKey((Obj2081*)self->menu_, 0xa);
        self->step_ = 0;
        self->flags_ &= ~8;
        self->count_ = 1;
        func_ov006_0215a5dc(self);
    }
    else if (self->step_ == 0x64)
    {
        unsigned char advanced = _Z26CheckFlagOrByte55_02158c70v(self);
        if (advanced == 0)
            return;
        self->message_ = 1;
        self->messageStep_ = 0;
        self->flags_ |= 0x20;
        self->step_++;
    }
    else if (self->step_ == 0x65)
    {
        unsigned char advanced = _Z26CheckFlagOrByte55_02158c70v(self);
        if (advanced != 0)
        {
            advanced = 0;
            self->step_ = 0;
        }
    }
}
