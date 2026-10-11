#if defined(jpn)
#define R(j,u) (j)
#define data_ov008_0218b490 data_ov008_0218c0f1
#define data_ov014_021896d4 data_ov014_0218a4e4
#define data_ov014_0218981c data_ov014_0218a5fc
#define data_ov015_02193d20 data_ov015_02194850
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194052 data_ov015_02194b92
#define data_ov015_02194078 data_ov015_02194bb8
#define data_ov015_0219415c data_ov015_02194c9c
#define data_ov015_02194160 data_ov015_02194ca0
#define data_ov015_02194167 data_ov015_02194ca7
#define func_ov008_02184968 func_ov008_02185a64
#define func_ov008_021895a8 func_ov008_0218a2b0
#define func_ov008_02189c70 func_ov008_0218a930
#define func_ov008_0218aee4 func_ov008_0218bb50
#define func_ov014_021886f8 func_ov014_021895c8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct MonsterListEntry {
    MonsterListEntry* next_;
};

struct Menu {
    char unk_0[R(0x20, 0x2c)];
    void* backgrounds_;
    char unk_30[6];
    short cursor_;
    unsigned char unk_38;
    char unk_39;
    unsigned char unk_3a;
    char unk_3b[5];
};

struct MonsterList {
    char unk_0[0x10];
};

struct MonsterListScreen {
    char unk_0[0xa4];
    MonsterList list_;
    void* listAllocators_;
    MonsterListEntry* entries_;
    MonsterListEntry* pageEntry_;
    Menu* menu_;
    void* backgrounds_;
    void* canvases_;
    void* canvasBuffer_;
    short* cursor_;
    void* listSprites_;
    void* animations_;
    void* records_;
    char textTable_[0x18];
    char spriteRenderer_[0x54];
    char repeat_[0xc];
    unsigned short repeatButtons_;
    unsigned char unk_15a;
    char unk_15b;
    int unk_15c;
    int menuEvents_;
    int ticks_;
    int listTaskID_;
    int listBackgroundTaskID_;
    short group_;
    short modeCursor_;
    short familyCursor_;
    short monsterCursor_;
    short prevCursor_;
    unsigned char listState_;
    unsigned char listStep_;
    unsigned char listBackgroundStep_;
    signed char family_;
    unsigned char listFlags_;
    bool closing_;
    short numMonsters_;
    short variantIDs_[8];
};

typedef void (MonsterListScreen::*ListStateFunc)();

struct Obj02186df0;
struct Obj0207fc6c;
struct ListHeadStruct021874f8;

void ResetBattlerNav_02186df0(Obj02186df0*);
void CallFunc0204c87cOverEntries0207fc6c(Obj0207fc6c*, int);
short CountLinkedListNodes_021874f8(ListHeadStruct021874f8*);
void ClearSublistEntriesFlag4(void*, int);

extern "C" {
bool func_ov017_021959b4();
void func_02081f20(void* repeat, int ticks);
int func_020800fc(Menu* menu, short* cursor, short prevCursor, unsigned short buttons, unsigned char, bool);
void func_020813ec(Menu* menu, short group);
void func_ov014_02184700(MonsterListScreen* self);
void func_ov014_021886f8(MonsterListScreen* self);
}

extern unsigned int data_ov014_0218981c;
extern ListStateFunc data_020e6d5c;
extern ListStateFunc data_ov014_021896d4[7];
extern ListStateFunc data_ov014_021896d4_dup[7];

// USA: func_ov014_02186bc8
extern "C" ARM bool func_ov014_02186bc8(MonsterListScreen* self, int ticks)
{
    if (ticks == 0)
        ticks = 1;
    self->ticks_ = ticks;
    if (func_ov017_021959b4())
        ResetBattlerNav_02186df0((Obj02186df0*)self);
    if (self->listState_ != 0)
    {
        CallFunc0204c87cOverEntries0207fc6c((Obj0207fc6c*)self->menu_, self->ticks_);
        if (self->cursor_ != NULL)
        {
            func_02081f20(self->repeat_, self->ticks_);
            self->prevCursor_ = *self->cursor_;
            bool scrolls = false;
            if (self->listState_ == 4)
                scrolls = CountLinkedListNodes_021874f8((ListHeadStruct021874f8*)self) > 16;
            self->menuEvents_ = func_020800fc(self->menu_, self->cursor_, self->prevCursor_, self->repeatButtons_, self->unk_15a, scrolls);
            self->menu_->cursor_ = *self->cursor_;
            if (self->menuEvents_ != 0)
                ClearSublistEntriesFlag4(self->menu_, self->group_);
            if (self->prevCursor_ != *self->cursor_)
                func_020813ec(self->menu_, self->group_);
        }
    }
    func_ov014_02184700(self);
    func_ov014_021886f8(self);

    if (!(data_ov014_0218981c & 1))
    {
        data_ov014_021896d4_dup[6] = data_020e6d5c;
        data_ov014_0218981c |= 1;
    }
    if (data_ov014_021896d4[self->listState_] == NULL)
        return true;
    (self->*data_ov014_021896d4[self->listState_])();
    return false;
}
