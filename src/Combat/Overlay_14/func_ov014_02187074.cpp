#if defined(jpn)
#define R(j,u) (j)
#define data_ov015_02193d14 data_ov015_02194844
#define data_ov015_02193d2c data_ov015_0219485c
#define data_ov015_02193d38 data_ov015_02194868
#define data_ov027_021dd8e0 data_ov027_021de1a0
#define func_ov003_021594c4 func_ov003_0215a990
#define func_ov003_0215a740 func_ov003_0215bbc0
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_0219050c func_ov015_021910b0
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

struct Canvas {
    Canvas* unk_0;
    void* background_;
    char unk_8[0xa0];
    short width_;
    short height_;
    short x_;
    short y_;
    char unk_b0[0x30];
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
    void* menu_;
    void* backgrounds_;
    Canvas* canvases_;
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

Canvas* FindElementByByte0xc4(Obj2081*, int);
bool CheckField0x9cSetWhenField0xd4Present(unsigned char*);
void SelectCoordsByFlag0x24(unsigned char*, int*, int*);
bool TestFlag0SetAndFlag1Clear(unsigned short*, int);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0*, int, int);
void ClearSublistEntriesFlag4(void*, int);

extern "C" {
MonsterListEntry* func_ov014_021873a0(MonsterListScreen* self);
MonsterListEntry* func_020974b0(MonsterList* list, int family, int, bool sort, int, short* outCount);
void func_ov014_02187228(MonsterListScreen* self, MonsterListEntry* entry);
void func_ov014_0218854c(MonsterListScreen* self);
void func_ov014_021885bc(MonsterListScreen* self);
}

extern unsigned char data_02114e54[];
extern unsigned short data_02114e30[];
extern char data_02108760[];

inline short TilesToPixels(short tiles)
{
    return tiles * 8;
}

// USA: func_ov014_02187074
extern "C" ARM bool func_ov014_02187074(MonsterListScreen* self)
{
    bool toggle = false;
    Canvas* canvas = FindElementByByte0xc4((Obj2081*)self->menu_, 4);
    if (canvas != NULL && CheckField0x9cSetWhenField0xd4Present((unsigned char*)canvas))
    {
        short y = canvas->y_;
        short height = canvas->height_;
        y--;
        height++;
        short left = TilesToPixels(canvas->x_);
        short top = TilesToPixels(y);
        short right = left + TilesToPixels(canvas->width_);
        short bottom = top + TilesToPixels(height);
        if (data_02114e54[0x55])
        {
            int x;
            int y;
            SelectCoordsByFlag0x24(data_02114e54, &x, &y);
            if (left <= x && x < right && top <= y && y < bottom)
                toggle = true;
        }
    }
    if (TestFlag0SetAndFlag1Clear(data_02114e30, 4))
        toggle = true;
    if (toggle)
    {
        MonsterListEntry* entry = func_ov014_021873a0(self);
        if (entry == NULL)
            return false;
        if (!entry->known_)
        {
            self->monsterCursor_ = -1;
            self->prevCursor_ = -1;
            entry = NULL;
        }
        if (self->listFlags_ & 8)
            self->listFlags_ &= ~8;
        else
            self->listFlags_ |= 8;
        short count = 0;
        self->entries_ = func_020974b0(&self->list_, self->family_, -1, (self->listFlags_ & 8) != 0, 0x10, &count);
        func_ov014_02187228(self, entry);
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
        ClearSublistEntriesFlag4(self->menu_, 5);
        func_ov014_0218854c(self);
        func_ov014_021885bc(self);
    }
    return toggle;
}
