#if defined(jpn)
#define R(j,u) (j)
#define data_ov014_02189692 data_ov014_0218a4a3
#define data_ov014_021896a7 data_ov014_0218a4b8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

#define BG0CNT (*(volatile unsigned short*)(0x04000008))
#define BG1CNT (*(volatile unsigned short*)(0x0400000a))
#define BG2CNT (*(volatile unsigned short*)(0x0400000c))
#define BG3CNT (*(volatile unsigned short*)(0x0400000e))
#define DISPCNT (*(volatile unsigned int*)0x04000000)
#define BGCNT_MASK_PRIORITY 3
#define BGCNT_MASK_MOSAIC 0x40

struct LayoutElement {
    short id_;
    unsigned short count_;
    short* items_;
    short x_;
    short y_;
    short parent_;
    short child_;
    short previous_;
    short next_;
    short unk_14;
    unsigned char flags_;
    unsigned char unk_17;
};

struct Sprite {
    char unk_0[0x14];
    int x_;
    int y_;
    char unk_1c[6];
    unsigned char unk_22;
    char unk_23[2];
    unsigned char unk_25;
    unsigned char unk_26;
    char unk_27;
};

struct SpriteRenderer;
struct ActiveEntry02046900;
struct Rec020467f0;
class GameState {
public:
    static GameState* GetInstance();
};
struct GameResources;

struct LightingManager {
    char unk_0[0x85];
    bool fogEnabled_;
    static LightingManager* GetInstance();
};

struct MonsterInfoScreen {
    void** buffers_;
    SpriteRenderer* spriteRenderer_;
    Sprite* sprites_;
    char unk_c[0x3c - 0xc];
    SafeAllocator* allocators_;
    void* model_;
    void* camera_;
    char unk_48[0x58 - 0x48];
    void* layout_;
    char unk_5c[0x6c - 0x5c];
    int taskID_;
    int backgroundTaskID_;
    int animationIndex_;
    int unk_78;
    unsigned char state_;
    unsigned char initStep_;
    unsigned char backgroundStep_;
    unsigned char loadStep_;
    unsigned char page_;
    unsigned char flags_;
};

struct Statics_02189800 {
    char unk_0[0xc];
    void* previousCamera;
};
extern Statics_02189800 data_ov014_02189800;
extern char data_ov014_02189692[];
extern char data_ov014_021896a7[];

extern "C" void _Z20ClearFields_021e20c0Pv(void* layout);
extern "C" int func_ov023_021e20f0(void* layout, SafeAllocator* allocator, void* file, unsigned int size);
extern "C" LayoutElement* func_ov014_021842a0(void* layout, short id);
int CountActiveEntries(ActiveEntry02046900* pac);
void* FindRecordByIndex(Rec020467f0* pac, int index, void** outName, int* outSize);
extern "C" void func_0205a528(SpriteRenderer* renderer, void* file, unsigned int size, SafeAllocator* allocator);
extern "C" void _Z25ComputeShortPair_021e2bdcPviPsS0_(void* layout, int id, short* x, short* y);
void* GetFieldIfFlag4(char* gameState);
extern "C" void _Z28InitCombatController020a2010Pv(void* camera);
void SetFields0x10To0x18(unsigned char* camera, int x, int y, int z);
extern "C" void func_0202e5d8(void* camera, int x, int y, int z);
extern "C" void func_0202e0a4(void* camera);
void SetField0x238False(void* camera);
void SetField0x3b0Value(GameState* gameState, int camera);
extern "C" GameResources* func_ov017_0218b5b0();
void SetBitsInField4(unsigned int* resources, unsigned int bits);
void ClearBitsInField4(unsigned int* resources, unsigned int bits);
void SetFogState(int, unsigned int, unsigned int, unsigned short);
void Set3DClearColor(int, int, int, int, int);

#define HIDE_ELEMENT(layout, id)                                        \
    {                                                                   \
        LayoutElement* element = func_ov014_021842a0(layout, id);       \
        if (element != NULL)                                            \
            element->flags_ &= ~1;                                      \
    }

// USA: func_ov014_0218580c
extern "C" ARM void func_ov014_0218580c(MonsterInfoScreen* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->initStep_ == 0) {
        BG1CNT = (BG1CNT & (BGCNT_MASK_PRIORITY | BGCNT_MASK_MOSAIC)) | (0x1f << 8);
        self->flags_ |= 0x10;
        self->initStep_++;
    }

    if (self->initStep_ == 1) {
        _Z20ClearFields_021e20c0Pv(self->layout_);
        self->taskID_ = loader->QueueLoadFile(data_ov014_02189692, NULL);
        self->initStep_++;
    }

    if (self->initStep_ == 2 && loader->GetTaskStatus(self->taskID_)) {
        void* file;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskID_, &file, &size);
        if (file != NULL) {
            SafeAllocator* allocators = self->allocators_;
            allocators[3].Reset();
            func_ov023_021e20f0(self->layout_, &allocators[3], file, size);
            HIDE_ELEMENT(self->layout_, 1);
        }
        loader->RemoveTask(self->taskID_);
        self->taskID_ = -1;
        self->taskID_ = loader->QueueLoadFile(data_ov014_021896a7, NULL);
        self->initStep_++;
    }

    if (self->initStep_ == 3 && loader->GetTaskStatus(self->taskID_)) {
        void* name;
        void* file;
        unsigned int size;
        int cellsSize;
        loader->GetLoadedFileByID(self->taskID_, &file, &size);
        int numFiles = CountActiveEntries((ActiveEntry02046900*)file);
        self->allocators_[5].Reset();
        for (int i = 0; i < numFiles; i++) {
            void* cells = FindRecordByIndex((Rec020467f0*)file, i, &name, &cellsSize);
            if (cells != NULL)
                func_0205a528(self->spriteRenderer_, cells, cellsSize, &self->allocators_[5]);
        }

        short x = 0;
        short y = 0;
        Sprite* sprite;
        HIDE_ELEMENT(self->layout_, 0x1a);
        _Z25ComputeShortPair_021e2bdcPviPsS0_(self->layout_, 0x1a, &x, &y);
        sprite = &self->sprites_[0];
        sprite->x_ = x << 12;
        sprite->y_ = y << 12;
        sprite->unk_22 = 0x21;
        sprite->unk_26 = 0;
        HIDE_ELEMENT(self->layout_, 0x1b);
        _Z25ComputeShortPair_021e2bdcPviPsS0_(self->layout_, 0x1b, &x, &y);
        sprite = &self->sprites_[1];
        sprite->x_ = x << 12;
        sprite->y_ = y << 12;
        sprite->unk_22 = 0x22;
        sprite->unk_26 = 0;
        _Z25ComputeShortPair_021e2bdcPviPsS0_(self->layout_, 0x14, &x, &y);
        sprite = &self->sprites_[2];
        sprite->x_ = x << 12;
        sprite->y_ = y << 12;
        sprite->unk_22 = 0x20;
        sprite->unk_26 = 0;
        loader->RemoveTask(self->taskID_);
        self->taskID_ = -1;
        self->initStep_++;
    }

    if (self->initStep_ == 4) {
        BG0CNT = (BG0CNT & ~BGCNT_MASK_PRIORITY);
        BG1CNT = (BG1CNT & ~BGCNT_MASK_PRIORITY) | 1;
        BG2CNT = (BG2CNT & ~BGCNT_MASK_PRIORITY) | 2;
        BG3CNT = (BG3CNT & ~BGCNT_MASK_PRIORITY) | 3;
        DISPCNT = (DISPCNT & ~0x1f00) | (0x13 << 8);
        GameState* gameState = GameState::GetInstance();
        data_ov014_02189800.previousCamera = GetFieldIfFlag4((char*)gameState);
        _Z28InitCombatController020a2010Pv(self->camera_);
        SetFields0x10To0x18((unsigned char*)self->camera_, 0, 0, 0);
        func_0202e5d8(self->camera_, 0, 0, 0xa000);
        func_0202e0a4(self->camera_);
        SetField0x238False(self->camera_);
        SetField0x3b0Value(gameState, (int)self->camera_);
        GameResources* resources = func_ov017_0218b5b0();
        SetBitsInField4((unsigned int*)resources, 0x6093e);
        ClearBitsInField4((unsigned int*)resources, 0x20);
        SetFogState(0, 0, 0, 0);
        Set3DClearColor(0, 0, 0x7fff, 0, 0);
        LightingManager::GetInstance()->fogEnabled_ = false;
        self->state_ = 1;
        self->initStep_ = 0;
    }
}
