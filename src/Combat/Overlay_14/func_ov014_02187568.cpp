#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "System/ColorEffects.h"
#include "System/Graphics.h"

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

struct BackgroundGraphics;
struct Canvas;

struct Menu {
    char unk_0[0x2c];
    BackgroundGraphics* backgrounds_;
    char unk_30[6];
    short cursor_;
    unsigned char unk_38;
    char unk_39;
    unsigned char unk_3a;
    char unk_3b[5];

    void SetBackgrounds(BackgroundGraphics* backgrounds)
    {
        backgrounds_ = backgrounds;
        unk_38 = 2;
    }
};

struct MonsterList {
    char unk_0[0x10];
};

struct TextTable {
    char unk_0[0x18];
};

struct SpriteRenderer {
    char unk_0[0x3c];
    void* animations_;
    void* sprites_;
    char unk_44[4];
    unsigned int unk_48;
    short numSprites_;
    unsigned short capacity_;
    unsigned char unk_50;
    char unk_51[3];

    void SetSprites(void* sprites, short numSprites)
    {
        sprites_ = sprites;
        numSprites_ = numSprites;
    }
};

struct MonsterListScreen {
    char unk_0[0xa4];
    MonsterList list_;
    SafeAllocator* listAllocators_;
    MonsterListEntry* entries_;
    MonsterListEntry* pageEntry_;
    Menu* menu_;
    BackgroundGraphics* backgrounds_;
    Canvas* canvases_;
    void* canvasBuffer_;
    short* cursor_;
    void* listSprites_;
    void* animations_;
    void* records_;
    TextTable textTable_;
    SpriteRenderer spriteRenderer_;
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

struct Field4Low12_02097420;
struct BufferField8_02097418;
struct Obj0207f914;
struct ActiveEntry02046900;
struct Rec020467f0;
struct Struct020dfc40;
struct Manager0207f7f0;
struct Node0207f7f0;

int* GetWord0x0(int*);
void SetBitsInField4(unsigned int*, unsigned int);
void SetFogState(int, unsigned int, unsigned int, unsigned short);
void Set3DClearColor(int, int, int, int, int);
void* GetGlobal02109400();
int GetField4Low12(Field4Low12_02097420*);
MonsterListEntry* GetBufferField8(BufferField8_02097418*);
extern "C" void _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(const char*, char*, int);
extern "C" void _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii(Obj0207f914*, int, int, int);
extern "C" void _Z38SetSublistEntryField14LowBits_02080798Pvii(void*, int, int);
int CountActiveEntries(ActiveEntry02046900*);
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(Struct020dfc40*);
void CopyOutBattleRegion0x75f0(void*);
extern "C" void _Z21InitNodeChain0207f7f0P15Manager0207f7f0P12Node0207f7f0i(Manager0207f7f0*, Node0207f7f0*, int);

extern "C" {
void _Z21BlankFunction02094b40v(void* music);
void _Z21BlankFunction02094b30v(void* music, int id, int);
bool _Z18AlwaysTrue02094b4cv(void* music);
void func_02094ab0(void* music);
void func_020972e0(MonsterList* list, SafeAllocator* allocator, void* file, unsigned int size);
int func_0207f9f4(Menu* menu);
void func_0205a528(SpriteRenderer* renderer, void* file, unsigned int size, SafeAllocator* allocator);
void func_020dfec0(TextTable* texts, SafeAllocator* allocator, void* file, unsigned int size);
void func_020abf60(MonsterList* list);
void func_ov014_02187488(MonsterListScreen* self);
MonsterListEntry* func_020974b0(MonsterList* list, int family, int, bool sort, int, short* outCount);
}

extern const char data_ov014_0218970c[];
extern const char data_ov014_02189722[];
extern const char data_ov014_02189734[];
extern const char data_ov014_0218974d[];
extern const char data_ov014_02189754[];
extern const char data_ov014_0218976a[];
extern const char data_ov014_02189784[];

// USA: func_ov014_02187568
extern "C" ARM void func_ov014_02187568(MonsterListScreen* self)
{
    int* resources = GetWord0x0((int*)GameState::GetInstance());
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->listStep_ == 0)
    {
        SetBitsInField4((unsigned int*)func_ov017_0218b5b0(), 0x609fe);
        SetFogState(0, 0, 0, 0);
        Set3DClearColor(0, 0, 0x7fff, 0, 0);
        void* music = GetGlobal02109400();
        func_02094ab0(music);
        _Z21BlankFunction02094b40v(music);
        _Z21BlankFunction02094b30v(music, 0x6a, 0);
        self->listStep_++;
    }
    else if (self->listStep_ == 1)
    {
        if (_Z18AlwaysTrue02094b4cv(GetGlobal02109400()))
            self->listStep_++;
    }
    else if (self->listStep_ == 2)
    {
        self->listTaskID_ = loader->QueueLoadFileInGP2(data_ov014_0218970c, data_ov014_02189722, NULL);
        self->listStep_++;
    }
    else if (self->listStep_ == 3)
    {
        if (loader->GetTaskStatus(self->listTaskID_))
        {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->listTaskID_, &file, &size);
            if (file != NULL)
            {
                self->listAllocators_[0].Reset();
                func_020972e0(&self->list_, &self->listAllocators_[0], file, size);
            }
            loader->RemoveTask(self->listTaskID_);
            self->listTaskID_ = -1;
            self->listStep_++;
        }
    }
    else if (self->listStep_ == 4)
    {
        int count = GetField4Low12((Field4Low12_02097420*)&self->list_);
        MonsterListEntry* entry = GetBufferField8((BufferField8_02097418*)&self->list_);
        for (int i = 0; i < count; i++, entry++)
        {
            char name[0x80] = {};
            _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(entry->name_, name, 0);
            sprintf((char*)entry->name_, name);
        }
        BG0CNTSUB = (BG0CNTSUB & (3 | 0x40)) | (0x1d << 8);
        BG1CNTSUB = (BG1CNTSUB & (3 | 0x40)) | (0x1e << 8);
        BG2CNTSUB = (BG2CNTSUB & (3 | 0x40)) | (0x1f << 8) | (2 << 2);
        self->listFlags_ |= 0x10;
        self->listStep_++;
    }
    else if (self->listStep_ == 5)
    {
        if (!(self->listFlags_ & 0x10))
        {
            SafeAllocator* allocators = self->listAllocators_;
            allocators[2].Reset();
            _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii((Obj0207f914*)self->menu_, (int)&allocators[2], (int)data_ov014_02189734, (int)data_ov014_0218974d);
            self->listStep_++;
        }
    }
    else if (self->listStep_ == 6)
    {
        int status = func_0207f9f4(self->menu_);
        if (status == 0)
            self->listStep_++;
        if (status < 0)
            self->listState_ = 6;
    }
    else if (self->listStep_ == 7)
    {
        _Z38SetSublistEntryField14LowBits_02080798Pvii(self->menu_, 6, 1);
        self->spriteRenderer_.unk_50 = 1;
        self->spriteRenderer_.SetSprites(self->listSprites_, 8);
        self->spriteRenderer_.animations_ = self->animations_;
        self->listTaskID_ = loader->QueueLoadFile(data_ov014_02189754, NULL);
        self->listStep_++;
    }
    else if (self->listStep_ == 8)
    {
        if (loader->GetTaskStatus(self->listTaskID_))
        {
            void* name;
            void* file;
            unsigned int size;
            unsigned int cellsSize;
            SafeAllocator* allocators;
            int numFiles;
            loader->GetLoadedFileByID(self->listTaskID_, &file, &size);
            numFiles = CountActiveEntries((ActiveEntry02046900*)file);
            allocators = self->listAllocators_;
            allocators[3].Reset();
            for (int i = 0; i < numFiles; i++)
            {
                void* cells = FindRecordByIndex((Rec020467f0*)file, i, &name, (int*)&cellsSize);
                if (cells != NULL)
                    func_0205a528(&self->spriteRenderer_, cells, cellsSize, &allocators[3]);
            }
            loader->RemoveTask(self->listTaskID_);
            self->listTaskID_ = -1;
            self->listStep_++;
        }
    }
    else if (self->listStep_ == 9)
    {
        _Z19ResetStruct020dfc40P14Struct020dfc40((Struct020dfc40*)&self->textTable_);
        self->listTaskID_ = loader->QueueLoadFileInGP2(data_ov014_0218976a, data_ov014_02189784, NULL);
        self->listStep_++;
    }
    else if (self->listStep_ == 10)
    {
        if (loader->GetTaskStatus(self->listTaskID_))
        {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->listTaskID_, &file, &size);
            if (file != NULL)
            {
                SafeAllocator* allocators = self->listAllocators_;
                allocators[4].Reset();
                func_020dfec0(&self->textTable_, &allocators[4], file, size);
            }
            loader->RemoveTask(self->listTaskID_);
            self->listTaskID_ = -1;
            self->listStep_ += 3;
        }
    }
    else if (self->listStep_ == 11)
        self->listStep_++;
    else if (self->listStep_ == 12)
        self->listStep_++;
    else if (self->listStep_ == 13)
    {
        func_020abf60(&self->list_);
        CopyOutBattleRegion0x75f0(self->records_);
        func_ov014_02187488(self);
        BG0CNTSUB = (BG0CNTSUB & ~3);
        BG1CNTSUB = (BG1CNTSUB & ~3) | 1;
        BG2CNTSUB = (BG2CNTSUB & ~3) | 2;
        BG3CNTSUB = (BG3CNTSUB & ~3) | 3;
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | (0x17 << 8);
        ColorEffect_ConfigureAlphaBlend(0x04001050, BLEND_TARGET_BG1, 4, 10, 6);
        self->menu_->SetBackgrounds(self->backgrounds_);
        _Z21InitNodeChain0207f7f0P15Manager0207f7f0P12Node0207f7f0i((Manager0207f7f0*)self->menu_, (Node0207f7f0*)self->canvases_, 4);
        self->menu_->unk_3a = 0;
        func_020974b0(&self->list_, -1, -1, false, 0, &self->numMonsters_);
        short count = 0;
        self->entries_ = func_020974b0(&self->list_, self->family_, -1, (self->listFlags_ & 8) != 0, 0x10, &count);
        self->pageEntry_ = self->entries_;
        self->listState_ = 1;
        self->listStep_ = 0;
    }
}
