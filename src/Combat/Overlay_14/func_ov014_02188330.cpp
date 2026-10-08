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

struct Container02080fa8;
struct StatusOwner02081164;

void ClearSublistEntriesFlag1(void* obj, int id);
void SetEntryHalfword0xe(void* obj, int id, int value);
extern "C" void _Z26SetEntryFirstField02080fa8P17Container02080fa8ii(Container02080fa8* obj, int id, int value);
extern "C" int _Z24SetEntryFlagById02080b2cPvi(void* obj, int id);
void SetEntryFlag0x2ByShortId(StatusOwner02081164* owner, int id, int enable);

extern "C" {
void func_020806d8(Menu* menu, int, int, int, int);
void func_020813ec(Menu* menu, short group);
}

extern const short data_ov014_021894cc[3][11];

// USA: func_ov014_02188330
extern "C" ARM void func_ov014_02188330(MonsterListScreen* self)
{
    int hidden = 0;
    if (self->listState_ == 4)
        hidden = 1;
    if (self->listState_ == 3)
        hidden = 2;
    func_020806d8(self->menu_, 0, 2, 1, 4);
    ClearSublistEntriesFlag1(self->menu_, 0);
    if (self->family_ >= 0)
        SetEntryHalfword0xe(self->menu_, 0x2f, (short)(self->family_ + 0x1e));

    short numKnown = 0;
    MonsterListEntry* entry = self->entries_;
    if (entry != NULL)
    {
        for (; entry != NULL; entry = entry->next_)
            numKnown += entry->known_;
    }

    short numMonsters = self->numMonsters_;
    short completion = 0;
    if (numMonsters != 0)
    {
        float value = (float)numKnown / (float)numMonsters;
        value *= 10000.0f;
        if (value < 100.0f)
            value = 100.0f;
        if (numKnown == 0)
            value = 0.0f;
        short percent = value;
        completion = percent / 100;
    }
    _Z26SetEntryFirstField02080fa8P17Container02080fa8ii((Container02080fa8*)self->menu_, 4, completion);
    _Z26SetEntryFirstField02080fa8P17Container02080fa8ii((Container02080fa8*)self->menu_, 5, numKnown);
    for (unsigned char i = 0;; i++)
    {
        short item = data_ov014_021894cc[hidden][i];
        if (item < 0)
            break;
        _Z24SetEntryFlagById02080b2cPvi(self->menu_, item);
    }
    SetEntryFlag0x2ByShortId((StatusOwner02081164*)self->menu_, 0, 1);
    func_020813ec(self->menu_, 0);
}
