#include <globaldefs.h>

struct Obj2081;
struct SetFieldsAndCall02158054Struct;
struct Obj0204b010;
struct EntryList0204af14;
struct Struct0200fb08;
struct Obj0204b8d0;
struct Obj0207fcb8;
struct Obj0207fd00;
struct Cont0207fd44;
struct Container0205a3d0;
struct Container0205a330;
struct Outer020e28dc;
struct Struct020e2794;
struct Struct02075db0;
struct AlchemyPot;
struct AlchemyMenu;

struct Sprite {
    char unk_0[0x14];
    int x_;
    int y_;
    char unk_1c[6];
    unsigned char unk_22;
    char unk_23[2];
    unsigned char unk_25;
    unsigned char unk_26;
    char unk_27;
};

struct SpriteAnimation {
    char unk_0[4];
    short x_;
    short y_;
    char unk_8[0xd];
    unsigned char flags_;
};

struct Unknown_02075cdc {
    char unk_0[0x14];
    unsigned int unk_14;
    char unk_18[0x44 - 0x18];
    int unk_44;
    char unk_48[4];
    int unk_4c;
    char unk_50[0x70 - 0x50];
};

class GameState {
public:
    static GameState* GetInstance();
};

int CheckElementFlag_02158080_02158080(Obj2081*, int);
void SetFieldsAndCall02158054(void*, SetFieldsAndCall02158054Struct*, int, int, unsigned char, unsigned char);
extern "C" void func_ov006_02154a60(AlchemyPot*);
void ClearBuffer0204b010(Obj0204b010*, void*);
void* GetEntryByIndexStride0x10(EntryList0204af14*, unsigned int);
void CallFunc0204b620IfField0x14_0204b938(void*, void*, int, int, unsigned short);
int NormalizeField5_0200fb08(Struct0200fb08*);
void DispatchEntry0204b8d0(Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
void ClearAllBuffers0207fcb8(Obj0207fcb8*);
void CallFunc0204c8f0OverEntries0207fd00(Obj0207fd00*);
extern "C" void func_0207fe80(void*, int, int, int);
extern "C" void func_0204b04c(void*, int);
void CallFunc0204b04cOverList0x2c(Cont0207fd44*);
void SetEntryFlag2ByKey0205a370(Container0205a3d0*, int);
SpriteAnimation* FindEntryByHalfword0205a3d0(Container0205a3d0*, int);
void IterateEntries0205a330(Container0205a330*, int);
extern "C" void func_0205ae8c(void*);
int GetInnerFlagBit0020e28dc(Outer020e28dc*);
void UpdateEntryIfActive020e2794(Struct020e2794*, void*);
extern "C" void func_ov006_021585c4(AlchemyMenu*);
extern "C" void func_ov006_0215868c(AlchemyMenu*);
extern "C" void func_ov006_021587d0(AlchemyMenu*);
extern "C" void func_ov006_02158914(AlchemyMenu*);
void GetSublistEntryScaledXY_020807c4(void*, int, short*, short*);
extern "C" void func_0205ac40(void*, Sprite*);
extern "C" void* func_0203bd08();
extern "C" unsigned int func_0203be4c(void*);
void SetFieldsAt0x28And0x2c02076988(int*, int, int);
void ForwardTableValue02075db0(Struct02075db0*, int, int);

struct AlchemyMenu {
    int textPosition_;
    char** texts_;
    void* canvasBuffer_;
    void* allocators_;
    AlchemyPot* pot_;
    void* menu_;
    void* choice_;
    void* backgrounds_;
    void* canvases_;
    Sprite* sprites_;
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
    Unknown_02075cdc resultSprite_;
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

// USA: func_ov006_021580b8
extern "C" ARM void func_ov006_021580b8(AlchemyMenu* self)
{
    if (self->state_ != 0)
    {
        if (CheckElementFlag_02158080_02158080((Obj2081*)self->menu_, 0))
            SetFieldsAndCall02158054(self->renderer_, (SetFieldsAndCall02158054Struct*)&self->sprites_[26], 2, 0x61, 0x64, 1);
        if (CheckElementFlag_02158080_02158080((Obj2081*)self->menu_, 1))
        {
            SetFieldsAndCall02158054(self->renderer_, (SetFieldsAndCall02158054Struct*)&self->sprites_[27], 2, 0x74, 0x66, 1);
            if (self->arrowTimer_ > 0x1f)
                SetFieldsAndCall02158054(self->renderer_, (SetFieldsAndCall02158054Struct*)&self->sprites_[28], 0x78, 0xb6, 0x63, 1);
        }
        else
        {
            self->arrowTimer_ = 0;
        }
        func_ov006_02154a60(self->pot_);
        ClearBuffer0204b010((Obj0204b010*)self->subBackground_, 0);
        void* layer = GetEntryByIndexStride0x10((EntryList0204af14*)self->subBackground_, self->background_);
        if (layer != 0)
            CallFunc0204b620IfField0x14_0204b938(self->subBackground_, layer, 0, 0, 0xffff);
        if (self->background_ == 1)
        {
            unsigned int kind = NormalizeField5_0200fb08((Struct0200fb08*)GameState::GetInstance());
            unsigned char tiles = 1;
            switch (kind)
            {
            case 2:
                tiles = 3;
                break;
            case 4:
                tiles = 4;
                break;
            case 3:
                tiles = 5;
                break;
            case 5:
                tiles = 6;
                break;
            }
            if (tiles > 1)
                DispatchEntry0204b8d0((Obj0204b8d0*)self->subBackground_, tiles, 0, 0, 0x16, 2, 9, 2, 0xffff);
        }
        void* menu = self->menu_;
        ClearAllBuffers0207fcb8((Obj0207fcb8*)menu);
        CallFunc0204c8f0OverEntries0207fd00((Obj0207fd00*)menu);
        func_0207fe80(menu, 2, 1, 1);
        func_0204b04c(self->subBackground_, 0);
        CallFunc0204b04cOverList0x2c((Cont0207fd44*)menu);
        if (self->flags_ & 0x200)
        {
            self->arrowTimer_ = 0;
            SetEntryFlag2ByKey0205a370((Container0205a3d0*)self->animations_, 1);
            SpriteAnimation* animation = FindEntryByHalfword0205a3d0((Container0205a3d0*)self->animations_, 0);
            if (animation != 0)
                animation->flags_ &= ~8;
            animation = FindEntryByHalfword0205a3d0((Container0205a3d0*)self->animations_, 1);
            if (animation != 0)
                animation->flags_ |= 8;
            IterateEntries0205a330((Container0205a330*)self->animations_, self->ticks_);
            animation = FindEntryByHalfword0205a3d0((Container0205a3d0*)self->animations_, 1);
            if (animation != 0)
            {
                animation->x_ = 0xd7;
                animation->y_ = 0x96;
            }
            func_0205ae8c(self->renderer_);
        }
        else
        {
            SpriteAnimation* animation = FindEntryByHalfword0205a3d0((Container0205a3d0*)self->animations_, 1);
            if (animation != 0)
                animation->flags_ &= ~8;
        }
        if (self->message_ < 0)
        {
            if (self->choice_ != 0 && GetInnerFlagBit0020e28dc((Outer020e28dc*)self->choice_))
                UpdateEntryIfActive020e2794((Struct020e2794*)self->choice_, self->renderer_);
            else
                func_ov006_021585c4(self);
        }
        func_ov006_0215868c(self);
        func_ov006_021587d0(self);
        func_ov006_02158914(self);
        self->arrowDown_ = 0;
        self->arrowUp_ = 0;
    }
    if (self->showResult_ != 0)
    {
        unsigned char state = self->state_;
        if (state != 8 && state != 11)
            return;
        short x;
        short y;
        GetSublistEntryScaledXY_020807c4(self->menu_, 0x12, &x, &y);
        Sprite* sprite = &self->sprites_[17];
        if (sprite != 0)
        {
            sprite->x_ = (x + 4) << 12;
            sprite->y_ = (y + 4) << 12;
            sprite->unk_22 = 0x32;
            sprite->unk_26 = 1;
            func_0205ac40(self->renderer_, sprite);
        }
        unsigned int vram = func_0203be4c(func_0203bd08());
        self->resultSprite_.unk_4c = 0;
        self->resultSprite_.unk_14 = vram + 0x1b8;
        self->resultSprite_.unk_44 = 0x37;
        SetFieldsAt0x28And0x2c02076988((int*)&self->resultSprite_, 0x1000, 0x1000);
        ForwardTableValue02075db0((Struct02075db0*)&self->resultSprite_, x + 8, y + 8);
    }
}
