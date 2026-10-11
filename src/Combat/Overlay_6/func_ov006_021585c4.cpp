#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215ffb4 data_ov006_02161318
#define data_ov006_0215ffc0 data_ov006_0216131b
#define data_ov006_0215ffc4 data_ov006_02161328
#define data_ov006_0215ffca data_ov006_02161336
#define data_ov006_0215ffe2 data_ov006_0216132e
#define data_ov006_0215fff4 data_ov006_02161346
#define func_ov006_021547c8 func_ov006_02155f30
#define func_ov006_021570fc func_ov006_02158704
#define func_ov006_0215f4dc func_ov006_021608fc
#define func_ov006_0215f740 func_ov006_02160b08
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Obj2081;
struct Outer020e28dc;
struct Ctx020e263c;
struct WinObj020e28f0;
struct AlchemyPot;

struct Sprite {
    char unk_0[0x28];
};

struct Unknown_02075cdc {
    int unk_0[0x70 / 4];
};

struct Canvas;

Canvas* FindElementByByte0xc4(Obj2081*, int);
int CheckField0x9cSetWhenField0xd4Present(unsigned char*);
extern "C" int _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(Outer020e28dc*);
extern "C" void _Z29GetLookAndTurnOffsets020809c4PviiPsS0_(void*, int, int, short*, short*);
void UpdateEntryStateAndPosition(Ctx020e263c*, int);
void SetEntryPositionFromObject(WinObj020e28f0*, short, short);
extern "C" void func_0205ae8c(void*);

struct AlchemyMenu {
#if !defined(jpn)
    int textPosition_;
    char** texts_;
#endif
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
#if defined(jpn)
    char regionalPad[8];
#endif
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

// USA: func_ov006_021585c4
extern "C" ARM void func_ov006_021585c4(AlchemyMenu* self)
{
    if (self->state_ == 0 || self->cursor_ == 0)
        return;
    if (self->group_ < 0)
        return;
    Canvas* canvas = FindElementByByte0xc4((Obj2081*)self->menu_, self->group_);
    if (canvas == 0)
        return;
    if (!CheckField0x9cSetWhenField0xd4Present((unsigned char*)canvas) || self->choice_ == 0)
        return;
    if (_Z24GetInnerFlagBit0020e28dcP13Outer020e28dc((Outer020e28dc*)self->choice_))
        return;
    short x;
    short y;
    _Z29GetLookAndTurnOffsets020809c4PviiPsS0_(self->menu_, self->group_, *self->cursor_, &x, &y);
    UpdateEntryStateAndPosition((Ctx020e263c*)self->choice_, self->ticks_);
    x -= 0x10;
    y -= 3;
    SetEntryPositionFromObject((WinObj020e28f0*)self->choice_, x, y);
    func_0205ae8c(self->renderer_);
}
