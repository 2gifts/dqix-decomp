#include <globaldefs.h>

struct AlchemyPot;

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

struct CategorySprites {
    int sprites_[9];
};

extern "C" short* _Z29GetArrEntry_0215919c_0215919cPv(void* self);
extern "C" void func_ov006_02155710(AlchemyPot* pot, short item, signed char sprites);

extern "C" const CategorySprites data_ov006_02160030;

// USA: func_ov006_0215f740
extern "C" ARM void func_ov006_0215f740(AlchemyMenu* self) {
    short* items = _Z29GetArrEntry_0215919c_0215919cPv(self);
    if (items == 0)
        return;
    unsigned short position = (unsigned short)(self->page_ * 8);
    position += self->itemCursor_ - 0x64;
    CategorySprites sprites = data_ov006_02160030;
    short category = self->categoryCursor_ - 0x5b;
    if (category < 0)
        category = 0;
    if (category > 8)
        category = 8;
    func_ov006_02155710(self->pot_, items[position], sprites.sprites_[category]);
}
