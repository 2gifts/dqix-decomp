#include <globaldefs.h>

struct AlchemyPot;
struct Recipe;
struct Container02080fa8;

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
};

void SetEntryFirstField02080fa8(Container02080fa8* menu, int id, int value);
extern "C" void func_020813ec(void* menu, int id);

// USA: func_ov006_0215f9e8  (semantic: Trans_0215f9e8)
extern "C" ARM void func_ov006_0215f9e8(AlchemyMenu* self) {
    SetEntryFirstField02080fa8((Container02080fa8*)self->menu_, 0x3d, self->count_);
    func_020813ec(self->menu_, 10);
    self->group_ = 10;
}
