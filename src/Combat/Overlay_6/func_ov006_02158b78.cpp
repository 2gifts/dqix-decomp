#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215fffe data_ov006_02161350
#define func_ov006_0215f3d8 func_ov006_021607f8
#define func_ov006_0215f4dc func_ov006_021608fc
#define func_ov006_0215f740 func_ov006_02160b08
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Outer020e28dc;
struct Obj2081;

struct Sprite {
    char unk_0[0x28];
};

struct Unknown_02075cdc {
    int unk_0[0x70 / 4];
};

struct AlchemyPot;

extern "C" {
extern unsigned short data_02114e30[];
extern unsigned char data_02114e54[];
}

int TestFlag0SetAndFlag1Clear(unsigned short*, int);
extern "C" int _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(Outer020e28dc*);
extern "C" int _Z23IsFlag0x2Active020e2984v();
void SelectCoordsByFlag0x24(unsigned char*, int*, int*);
extern "C" int _Z28IsPointInsideElement02080d54P7Obj2081iii(Obj2081*, int, int, int);

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
#if defined(jpn)
    char regionalPad[8];
#endif
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

// USA: func_ov006_02158b78
extern "C" ARM unsigned char func_ov006_02158b78(AlchemyMenu* self)
{
    unsigned char cancelled = 0;
    if (TestFlag0SetAndFlag1Clear(data_02114e30, 2))
        cancelled = 1;
    if (self->choice_ != 0 && _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc((Outer020e28dc*)self->choice_))
    {
        if (((int (*)(void*))_Z23IsFlag0x2Active020e2984v)(self->choice_))
            cancelled = 1;
    }
    else if (data_02114e54[0x55])
    {
        int x;
        int y;
        SelectCoordsByFlag0x24(data_02114e54, &x, &y);
        if (!_Z28IsPointInsideElement02080d54P7Obj2081iii((Obj2081*)self->menu_, self->group_, (short)x, (short)y))
            cancelled = 1;
    }
    return cancelled;
}
