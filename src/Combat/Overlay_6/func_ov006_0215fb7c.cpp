#include <globaldefs.h>

struct AlchemyPot;
struct StatusOwner02081164;
struct Obj2081;

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
    char subBackground_[0x20];
    char ingredients_[0x28];
    char repeat_[0xc];
    unsigned short buttons_;
    unsigned char unk_aa;
    char renderer_[0x54];
    char layout_[0x4c];
    char table_[0xc];
    char menuTexts_[0x18];
    char itemNames_[0xc];
    char results_[4][0x74];
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
    char resultSprite_[0x70];
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

void SetEntryHalfword0xe(void* menu, int id, int text);
void DispatchEntryOp0x8(void* menu, int id);
void SetEntryFlag0x2ByShortId(StatusOwner02081164* menu, int id, int flag);
extern "C" void func_020813ec(void* menu, int id);
extern "C" void _Z35SetEntryLowNibbleAndElement02080c68Pvii(void* menu, int id, int value);
void ClearElementFlag0x20(Obj2081* menu, int id);

// USA: func_ov006_0215fb7c
extern "C" ARM void func_ov006_0215fb7c(AlchemyMenu* self) {
    void* menu = self->menu_;
    short text = 0x2f;
    switch (self->bookCursor_)
    {
    case 0x28:
        text = 0x15;
        break;
    case 0x27:
        text = 0x14;
        break;
    }
    switch (self->filterCursor_)
    {
    case 0x48:
        text = 0x1d;
        break;
    case 0x49:
        text = 0x1e;
        break;
    case 0x4a:
        text = 0x1f;
        break;
    case 0x4b:
        text = 0x20;
        break;
    case 0x4c:
        text = 0x21;
        break;
    case 0x4d:
        text = 0x22;
        break;
    case 0x4e:
        text = 0x23;
        break;
    case 0x4f:
        text = 0x24;
        break;
    case 0x50:
        text = 0x25;
        break;
    case 0x51:
        text = 0x26;
        break;
    case 0x52:
        text = 0x27;
        break;
    case 0x53:
        text = 0x28;
        break;
    case 0x40:
        text = 0x17;
        break;
    case 0x41:
        text = 0x18;
        break;
    case 0x42:
        text = 0x19;
        break;
    case 0x43:
        text = 0x1a;
        break;
    case 0x44:
        text = 0x1b;
        break;
    case 0x45:
        text = 0x1c;
        break;
    }
    SetEntryHalfword0xe(menu, 0x59, text);
    DispatchEntryOp0x8(menu, 0x59);
    SetEntryFlag0x2ByShortId((StatusOwner02081164*)menu, 0xe, 1);
    func_020813ec(menu, 0xe);
    _Z35SetEntryLowNibbleAndElement02080c68Pvii(menu, 0xe, 2);
    ClearElementFlag0x20((Obj2081*)menu, 0xe);
}
