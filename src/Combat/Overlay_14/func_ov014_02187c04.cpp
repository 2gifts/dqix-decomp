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

short FindMappedMemberId02080468(void* obj, int id);
void ResetWithSub0208203c(Obj0208203c*);
void CallFunc0204c804OnMatchingKey(Obj2081*, int);
int CheckFlagAndPointInElement_02186ff0(char*);
bool TestFlag0SetAndFlag1Clear(unsigned short*, int);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);

extern "C" {
MonsterListEntry* func_020974b0(MonsterList* list, int family, int, bool sort, int, short* outCount);
void func_ov014_02188330(MonsterListScreen* self);
void func_020813ec(Menu* menu, short group);
bool func_ov014_02186f10(MonsterListScreen* self);
}

extern unsigned short data_02114e30[];
extern char data_02108760[];

// USA: func_ov014_02187c04
extern "C" ARM void func_ov014_02187c04(MonsterListScreen* self)
{
    if (self->listStep_ == 0)
    {
        if (!(self->listFlags_ & 0x10))
        {
            short count = 0;
            self->entries_ = func_020974b0(&self->list_, self->family_, -1, (self->listFlags_ & 8) != 0, 0x10, &count);
            self->pageEntry_ = self->entries_;
            func_ov014_02188330(self);
            self->group_ = 1;
            if (self->modeCursor_ < 0)
                self->modeCursor_ = FindMappedMemberId02080468(self->menu_, self->group_);
            self->menu_->cursor_ = self->modeCursor_;
            func_020813ec(self->menu_, self->group_);
            ResetWithSub0208203c((Obj0208203c*)self->repeat_);
            self->cursor_ = NULL;
            self->listStep_++;
        }
    }
    else if (self->listStep_ == 1)
    {
        self->cursor_ = &self->modeCursor_;
        if (func_ov014_02186f10(self))
        {
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)data_02108760, 1, 0);
            ResetWithSub0208203c((Obj0208203c*)self->repeat_);
            switch (*self->cursor_)
            {
            case 8:
                self->listFlags_ |= 0x10;
                self->listState_ = 4;
                self->listStep_ = 0;
                break;
            case 9:
                self->listState_ = 3;
                self->listStep_ = 0;
                break;
            }
            CallFunc0204c804OnMatchingKey((Obj2081*)self->menu_, self->group_);
            self->cursor_ = NULL;
        }
        else if (CheckFlagAndPointInElement_02186ff0((char*)self) || TestFlag0SetAndFlag1Clear(data_02114e30, 0x800))
        {
            self->listState_ = 5;
            self->listStep_ = 0;
        }
    }
}
