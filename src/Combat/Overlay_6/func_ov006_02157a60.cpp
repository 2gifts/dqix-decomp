#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct List0204af64;
struct StructInit36e0;
struct Obj02081ee4;
struct Sub02081ee4;
struct Struct02071be8;
struct Struct020dfc40;
struct Obj02157c78;

extern "C" void* func_0205ec34();
int TestBitInByteArray(int, unsigned char*, int);
void SetOrClearBitInArray(void*, unsigned char*, int, int);
extern "C" void _Z17ResetList0204af64P12List0204af64(List0204af64*);
extern "C" void _Z19InitStruct_021536e0P14StructInit36e0(StructInit36e0*);
extern "C" void _Z19InitWithSub02081ee4P11Obj02081ee4P11Sub02081ee4(Obj02081ee4*, Sub02081ee4*);
extern "C" void _Z18InitStruct0205a444Pc(char*);
extern "C" void _Z20ClearFields_021e20c0Pv(void*);
void ClearListHeader(Struct02071be8*);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(Struct020dfc40*);
extern "C" void _Z16InitObj_02157c78P11Obj02157c78(Obj02157c78*);

struct PartyMemberData {
    char unk_0[0x49c];
    unsigned char female_ : 1;
};

class GameObject {
public:
    char unk_0[R(0x144, 0x150)];
    PartyMemberData* partyData_;
};

class GameState {
public:
    static GameState* GetInstance();
    GameObject* GetProtagonist();
};

struct BackgroundGraphics {
    int unk_0[0x20 / 4];
};

struct PotIngredient {
    int unk_0[0x74 / 4];
};

struct AlchemyMenu {
#if !defined(jpn)
    int textPosition_;
    char** texts_;
#endif
    void* canvasBuffer_;
    void* allocators_;
    void* pot_;
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
    BackgroundGraphics subBackground_;
    int ingredients_[0x28 / 4];
    int repeat_[0xc / 4];
    unsigned short buttons_;
    unsigned char unk_aa;
    int renderer_[0x54 / 4];
    int layout_[R(0x48, 0x4c) / 4];
    int table_[0xc / 4];
    int menuTexts_[0x18 / 4];
    char itemNames_[R(0x18, 0xc)];
    PotIngredient results_[4];
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

// USA: func_ov006_02157a60
extern "C" ARM void func_ov006_02157a60(AlchemyMenu* self)
{
    char* flags = (char*)func_0205ec34();
    if (!TestBitInByteArray((int)flags, (unsigned char*)(flags + 0x8c), 0x777))
        SetOrClearBitInArray(flags, (unsigned char*)(flags + 0x8c), 0x777, 1);
#if !defined(jpn)
    self->textPosition_ = 0;
#endif
    self->showResult_ = 0;
    self->resultTask_ = -1;
    self->fadeTimer_ = 0;
    self->nextStep_ = 0;
    self->canvasBuffer_ = 0;
    self->allocators_ = 0;
    self->pot_ = 0;
    self->menu_ = 0;
    self->choice_ = 0;
    self->backgrounds_ = 0;
    self->canvases_ = 0;
    self->sprites_ = 0;
    self->animations_ = 0;
    self->recipes_ = 0;
    self->pageStart_ = 0;
    self->recipe_ = 0;
    self->records_ = 0;
    self->cursor_ = 0;
    self->items_ = 0;
    self->counts_ = 0;
    self->sizes_ = 0;
    _Z17ResetList0204af64P12List0204af64((List0204af64*)&self->subBackground_);
    _Z19InitStruct_021536e0P14StructInit36e0((StructInit36e0*)self->ingredients_);
    _Z19InitWithSub02081ee4P11Obj02081ee4P11Sub02081ee4((Obj02081ee4*)self->repeat_, (Sub02081ee4*)&self->buttons_);
    _Z18InitStruct0205a444Pc((char*)self->renderer_);
    _Z20ClearFields_021e20c0Pv(self->layout_);
    ClearListHeader((Struct02071be8*)self->table_);
    _Z19ResetStruct020dfc40P14Struct020dfc40((Struct020dfc40*)self->menuTexts_);
    for (unsigned char i = 0; i < 4; i++)
        _Z16InitObj_02157c78P11Obj02157c78((Obj02157c78*)&self->results_[i]);
    self->menuResult_ = 0;
    self->task_ = -1;
    self->unk_358 = -1;
    self->unk_35c = 0;
    self->previousCursor_ = -1;
    self->mainCursor_ = -1;
    self->categoryCursor_ = -1;
    self->itemCursor_ = -1;
    self->bookCursor_ = -1;
    self->filterCursor_ = -1;
    self->recipeCursor_ = -1;
    self->choiceCursor_ = -1;
    self->group_ = -1;
    self->item_ = -1;
    self->categories_[2] = 0;
    self->categories_[1] = 0;
    self->categories_[0] = 0;
    self->chosenItems_[2] = -1;
    self->chosenItems_[1] = self->chosenItems_[2];
    self->chosenItems_[0] = self->chosenItems_[1];
    self->message_ = -1;
    self->messageLength_ = 0;
    self->successRate_ = 0;
    self->filterCategory_ = -1;
    self->filterKind_ = -1;
    self->sort_ = 0;
    self->times_ = 0;
    self->page_ = 0;
    self->pages_ = 0;
    self->category_ = 0;
    self->count_ = 0;
    self->chosenCounts_[2] = 0;
    self->chosenCounts_[1] = 0;
    self->chosenCounts_[0] = 0;
    self->state_ = 0;
    self->step_ = 0;
    self->unk_391 = 0;
    self->messageStep_ = 0;
    self->repeatDelay_ = 0;
    self->flags_ = 0;
    self->female_ = 0;
    self->background_ = 0;
    self->female_ = GameState::GetInstance()->GetProtagonist()->partyData_->female_;
    self->textSound_ = 0;
    self->textSoundOn_ = 1;
    self->textSoundTimer_ = 0;
    self->textSoundPlaying_ = 0;
    self->textSoundState_ = -1;
    self->saved_ = 0;
    self->arrowUp_ = self->arrowDown_ = 0;
    self->resetBlend_ = 0;
    self->closing_ = 0;
    self->closeRequested_ = 0;
    self->arrowTimer_ = 0;
}
