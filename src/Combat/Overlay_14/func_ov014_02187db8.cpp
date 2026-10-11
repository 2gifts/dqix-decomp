#if defined(jpn)
#define R(j,u) (j)
#define _Z24IssueBattleCommandSlot25ii func_020d84e0
#define data_ov001_02164ca4 data_ov001_02166270
#define data_ov028_021d9aa0 data_ov028_021da400
#define func_ov014_02188330 func_ov014_02189234
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_02191f04 func_ov015_02192a48
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct MonsterListEntry {
    MonsterListEntry* next_;
};

struct Menu {
    char unk_0[0x2c];
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

struct Obj2081;
struct Obj0205eaa0;
struct Obj0208203c;
struct ListHeadStruct021874f8;

short FindMappedMemberId02080468(void* obj, int id);
void ResetWithSub0208203c(Obj0208203c*);
void CallFunc0204c804OnMatchingKey(Obj2081*, int);
int CheckFlagAndPointInElement_02186ff0(char*);
bool TestFlag0SetAndFlag1Clear(unsigned short*, int);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
short CountLinkedListNodes_021874f8(ListHeadStruct021874f8*);

extern "C" {
MonsterListEntry* func_020974b0(MonsterList* list, int family, int, bool sort, int, short* outCount);
void func_ov014_02188330(MonsterListScreen* self);
void func_020813ec(Menu* menu, short group);
bool func_ov014_02186f10(MonsterListScreen* self);
}

extern unsigned short data_02114e30[];
extern char data_02108760[];

// USA: func_ov014_02187db8
extern "C" ARM void func_ov014_02187db8(MonsterListScreen* self)
{
    if (self->listStep_ == 0)
    {
        if (!(self->listFlags_ & 0x10))
        {
            self->group_ = 2;
            if (self->familyCursor_ < 0)
                self->familyCursor_ = FindMappedMemberId02080468(self->menu_, self->group_);
            func_020813ec(self->menu_, self->group_);
            self->family_ = self->familyCursor_ - 0xb;
            short count = 0;
            self->entries_ = func_020974b0(&self->list_, self->family_, -1, (self->listFlags_ & 8) != 0, 0x10, &count);
            self->pageEntry_ = self->entries_;
            func_ov014_02188330(self);
            self->listStep_++;
        }
    }
    else if (self->listStep_ == 1)
    {
        self->cursor_ = &self->familyCursor_;
        self->family_ = self->familyCursor_ - 0xb;
        if (self->menuEvents_ != 0 || self->prevCursor_ != *self->cursor_)
        {
            short count = 0;
            self->entries_ = func_020974b0(&self->list_, self->family_, -1, (self->listFlags_ & 8) != 0, 0x10, &count);
            self->pageEntry_ = self->entries_;
            func_ov014_02188330(self);
        }
        if (func_ov014_02186f10(self))
        {
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)data_02108760, 1, 0);
            ResetWithSub0208203c((Obj0208203c*)self->repeat_);
            if (CountLinkedListNodes_021874f8((ListHeadStruct021874f8*)self) != 0)
            {
                CallFunc0204c804OnMatchingKey((Obj2081*)self->menu_, self->group_);
                self->cursor_ = NULL;
                self->listState_ = 4;
                self->listStep_ = 0;
                self->listFlags_ |= 0x10;
            }
        }
        else if (CheckFlagAndPointInElement_02186ff0((char*)self))
        {
            CallFunc0204c804OnMatchingKey((Obj2081*)self->menu_, self->group_);
            self->familyCursor_ = -1;
            self->family_ = -1;
            self->listState_ = 2;
            self->listStep_ = 0;
        }
        else if (TestFlag0SetAndFlag1Clear(data_02114e30, 0x800))
        {
            CallFunc0204c804OnMatchingKey((Obj2081*)self->menu_, self->group_);
            self->familyCursor_ = -1;
            self->family_ = -1;
            self->listState_ = 5;
            self->listStep_ = 0;
        }
    }
}
