#if defined(jpn)
#define R(j,u) (j)
#define _Z23EmptyDestructor0205cb60Pv func_0205deb8
#define _Z25ResetDisplayState02155480P11Obj02155480 func_ov006_02156b68
#define data_ov011_021889a0 data_ov011_02189700
#define data_ov013_02187dd8 data_ov013_02188cf0
#define func_ov006_02154fe4 func_ov006_02156730
#define func_ov006_021570fc func_ov006_02158704
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Obj2081;
struct List0204af64;
struct Obj0204b5e8;
struct Obj02155480;
struct Outer020e28dc;
struct Entry020e2cc4;
struct SelfState020e2834;
struct Cont0207fd88;
struct AlchemyPot;

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

struct Unknown_02075cdc {
    char unk_0[0x14];
    unsigned int unk_14;
    char unk_18[0x44 - 0x18];
    int unk_44;
    char unk_48[4];
    int unk_4c;
    char unk_50[0x70 - 0x50];
};

struct BackgroundGraphics {
    char unk_0[0x1c];
    unsigned char unk_1c_0_ : 4;
    unsigned char unk_1c_4_ : 4;
    unsigned char unk_1d;
    char unk_1e[2];
};

struct Canvas {
    char unk_0[0xac];
    short x_;
    short y_;
};

extern "C" void* GetSubBG0ScreenBase();
extern "C" void* memset(void*, int, unsigned int);
int CheckElementFlag_02158080_02158080(Obj2081*, int);
Canvas* FindElementByByte0xc4(Obj2081*, int);
void ResetList0204af64(List0204af64*);
int DispatchViaTable0204b5e8(Obj0204b5e8*, int, int);
void CallFunc0204b620IfField0x14_0204b938(void*, void*, int, int, unsigned short);
extern "C" void func_ov006_02154fe4(AlchemyPot*);
#if defined(jpn)
#define ResetDisplayState02155480 func_ov006_02156b68
extern "C" void ResetDisplayState02155480(Obj02155480*);
#else
void ResetDisplayState02155480(Obj02155480*);
#endif
extern "C" int func_ov006_021570fc(AlchemyPot*, int);
extern "C" void func_0204b088(void*, int);
int GetInnerFlagBit0020e28dc(Outer020e28dc*);
void SetEntryEnabled020e2cc4(Entry020e2cc4*, int);
void SetYesNoButtonPalette020e2834(SelfState020e2834*);
void CallFunc0204b088OverList0x2c(Cont0207fd88*);

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

// USA: func_ov006_02158478
extern "C" ARM void func_ov006_02158478(AlchemyMenu* self)
{
    if (self->state_ == 0)
        return;
    unsigned short* screen = (unsigned short*)GetSubBG0ScreenBase();
    memset(screen, 0, 0x800);
    if (CheckElementFlag_02158080_02158080((Obj2081*)R(*(void**)((char*)self+0xc),self->menu_), 1))
    {
        Canvas* canvas = FindElementByByte0xc4((Obj2081*)R(*(void**)((char*)self+0xc),self->menu_), 1);
        if (canvas == 0)
            return;
        short x;
        short y;
        void* layer = (char*)canvas + 0xc8;
        if (layer == 0)
            return;
        x = canvas->x_;
        y = canvas->y_;
        BackgroundGraphics background;
        ResetList0204af64((List0204af64*)&background);
        background.unk_1c_0_ = 1;
        background.unk_1c_4_ = 0;
        *(unsigned short**)&background.unk_0[0x14] = screen;
        DispatchViaTable0204b5e8((Obj0204b5e8*)&background, 0, 0);
        CallFunc0204b620IfField0x14_0204b938(&background, layer, x, y, 0xffff);
    }
    func_ov006_02154fe4(R(*(AlchemyPot**)((char*)self+8),self->pot_));
    if (self->resetBlend_ != 0)
    {
        ResetDisplayState02155480((Obj02155480*)R(*(AlchemyPot**)((char*)self+8),self->pot_));
        func_ov006_021570fc(R(*(AlchemyPot**)((char*)self+8),self->pot_), 1);
        self->resetBlend_ = 0;
    }
    func_0204b088(R((int*)((char*)self+0x4c),self->subBackground_), 0);
    if (R(*(void**)((char*)self+0x10),self->choice_) != 0)
    {
        void* window = *(void**)((char*)R(*(void**)((char*)self+0x10),self->choice_) + 0x10);
        SetEntryEnabled020e2cc4((Entry020e2cc4*)((char*)window + 0x28), GetInnerFlagBit0020e28dc((Outer020e28dc*)R(*(void**)((char*)self+0x10),self->choice_)));
        SetYesNoButtonPalette020e2834((SelfState020e2834*)R(*(void**)((char*)self+0x10),self->choice_));
    }
    if (R(*(void**)((char*)self+0xc),self->menu_) != 0)
        CallFunc0204b088OverList0x2c((Cont0207fd88*)R(*(void**)((char*)self+0xc),self->menu_));
}
