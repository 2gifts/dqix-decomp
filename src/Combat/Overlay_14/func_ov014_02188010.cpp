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
    const char* modelName_;
    const char* name_;
    short monsterID_;
    char unk_e[4];
    signed char familyTextID_;
    unsigned char unk_13_0_ : 1;
    unsigned char known_ : 1;
    unsigned char unk_13_2_ : 6;
    char unk_14[6];
    short number_;
    char unk_1c[4];
};

struct MonsterRecord;

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
    char unk_0[0x48];
    MonsterListEntry* monster_;
    MonsterListEntry* prevMonster_;
    char unk_50[0x31];
    unsigned char flags_;
    unsigned char rotating_ : 1;
    unsigned char unk_82_1_ : 1;
    unsigned char loadModel_ : 1;
    unsigned char unk_82_3_ : 1;
    unsigned char unk_82_4_ : 4;
    char unk_83[0x21];
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
struct Obj0208203c;
struct ObjStruct_02187450;
struct KeyStruct_02187450;
struct SoundState02184f10;

short FindMappedMemberId02080468(void* obj, int id);
void ResetWithSub0208203c(Obj0208203c*);
void CallFunc0204c804OnMatchingKey(Obj2081*, int);
int CheckFlagAndPointInElement_02186ff0(char*);
bool TestFlag0SetAndFlag1Clear(unsigned short*, int);
MonsterRecord* GetArrayEntryByField1a_02187450(ObjStruct_02187450*, KeyStruct_02187450*);
void UpdateSoundStateA_02184f10(SoundState02184f10*, int, int);
void ProcessEntry02184e3c(unsigned char*);

extern "C" {
void func_ov014_02188330(MonsterListScreen* self);
void func_ov014_021884cc(MonsterListScreen* self);
void func_ov014_0218854c(MonsterListScreen* self);
void func_ov014_021885bc(MonsterListScreen* self);
MonsterListEntry* func_ov014_021873a0(MonsterListScreen* self);
void func_ov014_02184f78(MonsterListScreen* self, MonsterListEntry* monster, MonsterRecord* record, bool loadModel);
bool func_ov014_02187074(MonsterListScreen* self);
void func_ov014_021872dc(MonsterListScreen* self, int pages);
bool func_ov014_02186f10(MonsterListScreen* self);
void func_ov014_02184dcc(MonsterListScreen* self);
void func_ov014_02184d08(MonsterListScreen* self);
}

extern unsigned short data_02114e30[];

static inline MonsterRecord* GetRecord(MonsterListScreen* self, MonsterListEntry* entry)
{
    return GetArrayEntryByField1a_02187450((ObjStruct_02187450*)self, (KeyStruct_02187450*)entry);
}

static inline void SetMonster(MonsterListScreen* self, MonsterListEntry* entry, MonsterRecord* record)
{
    UpdateSoundStateA_02184f10((SoundState02184f10*)self, (int)entry, (int)record);
}

// USA: func_ov014_02188010
extern "C" ARM void func_ov014_02188010(MonsterListScreen* self)
{
    if (self->listStep_ == 0)
    {
        if (self->listFlags_ & 0x10)
            return;
        self->pageEntry_ = self->entries_;
        func_ov014_02188330(self);
        func_ov014_021884cc(self);
        func_ov014_0218854c(self);
        self->group_ = 5;
        self->monsterCursor_ = FindMappedMemberId02080468(self->menu_, self->group_);
        func_ov014_021885bc(self);
        ResetWithSub0208203c((Obj0208203c*)self->repeat_);
        self->cursor_ = NULL;
        self->listStep_++;
        self->monster_ = NULL;
        self->prevMonster_ = NULL;
        MonsterListEntry* entry = func_ov014_021873a0(self);
        func_ov014_02184f78(self, entry, GetRecord(self, entry), true);
        self->unk_82_3_ = true;
    }
    else if (self->listStep_ == 1)
    {
        self->cursor_ = &self->monsterCursor_;
        if (func_ov014_02187074(self))
        {
            if (self->prevCursor_ < 0)
            {
                MonsterListEntry* entry = func_ov014_021873a0(self);
                if (entry->known_)
                    SetMonster(self, entry, GetRecord(self, entry));
                self->prevCursor_ = *self->cursor_;
            }
            return;
        }
        if (self->menuEvents_ != 0 || self->prevCursor_ != *self->cursor_)
        {
            if (self->menuEvents_ & 0x10)
                func_ov014_021872dc(self, 1);
            else if (self->menuEvents_ & 0x20)
                func_ov014_021872dc(self, -1);
            func_ov014_021885bc(self);
            MonsterListEntry* entry = func_ov014_021873a0(self);
            SetMonster(self, entry, GetRecord(self, entry));
        }
        if (func_ov014_02186f10(self))
        {
            if (self->listFlags_ & 0x40)
            {
                MonsterListEntry* entry = func_ov014_021873a0(self);
                SetMonster(self, entry, GetRecord(self, entry));
            }
            else
                ProcessEntry02184e3c((unsigned char*)self);
        }
        else if (TestFlag0SetAndFlag1Clear(data_02114e30, 0x800))
            func_ov014_02184dcc(self);
        else if (CheckFlagAndPointInElement_02186ff0((char*)self))
        {
            self->flags_ &= ~4;
            if (self->family_ >= 0)
                self->listState_ = 3;
            if (self->family_ < 0)
                self->listState_ = 2;
            self->monster_ = NULL;
            self->prevMonster_ = NULL;
            self->listFlags_ |= 0x10;
            CallFunc0204c804OnMatchingKey((Obj2081*)self->menu_, self->group_);
            self->listStep_ = 0;
            self->cursor_ = NULL;
            CallFunc0204c804OnMatchingKey((Obj2081*)self->menu_, 4);
            CallFunc0204c804OnMatchingKey((Obj2081*)self->menu_, 3);
            func_ov014_02184d08(self);
        }
    }
}
