#include <globaldefs.h>

#if defined(jpn)
#define func_ov014_021886f8 func_ov014_021895c8
#endif
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct BackgroundGraphics {
    char unk_0[0x1c];
    unsigned char unk_1c_0_ : 4;
    unsigned char unk_1c_4_ : 4;
    unsigned char unk_1d;
    char unk_1e[2];
};

struct Canvas {
    Canvas* unk_0;
    BackgroundGraphics* background_;
    char unk_8[0xd8];
};

struct MonsterListEntry;

struct MonsterList {
    char unk_0[0x10];
};

struct MonsterListScreen {
    char unk_0[0xa4];
    MonsterList list_;
    SafeAllocator* listAllocators_;
    MonsterListEntry* entries_;
    MonsterListEntry* pageEntry_;
    void* menu_;
    BackgroundGraphics* backgrounds_;
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

struct ActiveEntry02046900;
struct List0204af64;
struct AllocTarget0204b12c;
struct Obj0204b5e8;
struct Foo0204af38;
struct Rec020467f0;
struct Struct0200fb08;
struct Obj0204b010;
struct Obj0204b988;
struct Obj0204b8d0;
struct List0204b0e8;
struct Obj0204c7a8;

int CountActiveEntries(ActiveEntry02046900*);
void ResetList0204af64(List0204af64*);
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char*, int);
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c*, SafeAllocator*);
void DispatchViaTable0204b5e8(Obj0204b5e8*, int, int);
void AllocateArray0204af38(Foo0204af38*, int, SafeAllocator*);
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
int NormalizeField5_0200fb08(Struct0200fb08*);
void ClearBuffer0204b010(Obj0204b010*, void*);
void DispatchIndexedEntry0204b988(Obj0204b988*, unsigned int, int, int, unsigned short);
void DispatchEntry0204b8d0(Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
void FlushAndDispatchList0204b0e8(List0204b0e8*, void*);
void AllocateBuffer0204c7a8(Obj0204c7a8*, SafeAllocator*, int, unsigned int);

extern "C" {
void func_0204b5b4(BackgroundGraphics* graphics, int);
void func_0204b174(BackgroundGraphics* graphics, void* file, SafeAllocator* allocator, unsigned int size);
void func_0204c684(Canvas* canvas);
}

extern const char data_ov014_02189795[];
extern const char data_ov014_021897ac[];

// USA: func_ov014_021886f8
extern "C" ARM void func_ov014_021886f8(MonsterListScreen* self)
{
    SafeAllocator* allocators;
#if !defined(jpn)
    GameState* gameState = GameState::GetInstance();
#endif
    if (!(self->listFlags_ & 0x10))
        return;

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->listBackgroundStep_ == 0)
    {
        const char* file = data_ov014_02189795;
        if (self->listState_ == 4)
            file = data_ov014_021897ac;
        self->listBackgroundTaskID_ = loader->QueueLoadFile(file, NULL);
        self->listBackgroundStep_++;
    }
    else if (self->listBackgroundStep_ == 1)
    {
        if (!loader->GetTaskStatus(self->listBackgroundTaskID_))
            return;

        BackgroundGraphics graphics;
        void* name;
        void* file;
        unsigned int size;
        unsigned int dataSize;
        int numFiles;
        loader->GetLoadedFileByID(self->listBackgroundTaskID_, &file, &size);
        numFiles = CountActiveEntries((ActiveEntry02046900*)file);
        allocators = self->listAllocators_;
        allocators[1].Reset();
        ResetList0204af64((List0204af64*)&graphics);
        SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)&graphics, 0);
        graphics.unk_1c_0_ = 1;
        graphics.unk_1c_4_ = 2;
        func_0204b5b4(&graphics, 2);
        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)&graphics, &allocators[1]);
        DispatchViaTable0204b5e8((Obj0204b5e8*)&graphics, 0, 0);
#if defined(jpn)
        AllocateArray0204af38((Foo0204af38*)&graphics, 1, &allocators[1]);
#else
        AllocateArray0204af38((Foo0204af38*)&graphics, 5, &allocators[1]);
#endif
        for (int i = 1; i < numFiles; i++)
        {
            void* data = FindRecordByIndex((Rec020467f0*)file, i, &name, (int*)&dataSize);
            if (data != NULL)
                func_0204b174(&graphics, data, &allocators[1], dataSize);
        }
        loader->RemoveTask(self->listBackgroundTaskID_);
        self->listBackgroundTaskID_ = -1;

#if !defined(jpn)
        int language = NormalizeField5_0200fb08((Struct0200fb08*)gameState);
        int title = 0;
        switch (language)
        {
        case 2:
            title = 1;
            break;
        case 4:
            title = 2;
            break;
        case 3:
            title = 3;
            break;
        case 5:
            title = 4;
            break;
        }
#endif
        ClearBuffer0204b010((Obj0204b010*)&graphics, 0);
        DispatchIndexedEntry0204b988((Obj0204b988*)&graphics, 0, 0, 0, 0xffff);

#if !defined(jpn)
        if (title != 0)
            DispatchEntry0204b8d0((Obj0204b8d0*)&graphics, title, 0, 0, 0x16, 2, 9, 2, 0xffff);
#endif
        FlushAndDispatchList0204b0e8((List0204b0e8*)&graphics, 0);

        allocators[1].Reset();
        for (unsigned char i = 0; i < 2; i++)
        {
            BackgroundGraphics* background = &self->backgrounds_[i];
            ResetList0204af64((List0204af64*)background);
            background->unk_1c_0_ = 1;
            background->unk_1c_4_ = i;
            SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)background, 0);
            func_0204b5b4(background, i);
            AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)background, &allocators[1]);
            DispatchViaTable0204b5e8((Obj0204b5e8*)background, 0, 0);
        }
        void* data = FindRecordByIndex((Rec020467f0*)file, 0, &name, (int*)&dataSize);
        if (data != NULL)
            func_0204b174(self->backgrounds_, data, &allocators[1], dataSize);
        for (unsigned char i = 0; i < 2; i++)
        {
            BackgroundGraphics* background = &self->backgrounds_[i];
            ClearBuffer0204b010((Obj0204b010*)background, 0);
            FlushAndDispatchList0204b0e8((List0204b0e8*)background, 0);
        }
        for (unsigned char i = 0; i < 4; i++)
        {
            Canvas* canvas = &self->canvases_[i];
            func_0204c684(canvas);
            AllocateBuffer0204c7a8((Obj0204c7a8*)canvas, &allocators[1], (int)self->canvasBuffer_, 0x600);
            canvas->background_ = self->backgrounds_;
        }
        self->listBackgroundStep_ = 0;
        self->listFlags_ &= ~0x10;
    }
}
