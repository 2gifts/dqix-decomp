#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#if defined(jpn)
extern char data_ov013_02188de0[];
extern char data_ov013_02188dfa[];
#define data_ov013_02187db8 data_ov013_02188ce0
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "System/Graphics.h"
#include "GameState/GameState.h"

void InitStruct0205a444(char* renderer);
struct Struct0205a198;
void Init0205a198(Struct0205a198* sprite);
struct ActiveEntry02046900;
int CountActiveEntries(ActiveEntry02046900* pac);
struct Rec020467f0;
void* FindRecordByIndex(Rec020467f0* pac, int index, void** outName, int* outSize);
extern "C" void func_0205a528(void* renderer, void* file, unsigned int size, SafeAllocator* allocator);
extern "C" void func_020728ac(void* texts, SafeAllocator* allocator, void* file, unsigned int size, int, int, int);
struct List0208df10;
void ClearList0208df10(List0208df10* table);
void* GetFieldAt0x150_02053c6c(unsigned char* member);
signed char GetTableByte020dd11c(unsigned int vocation, unsigned int index);
struct Struct0208df20;
void InitAndRunScript0208df20(Struct0208df20* table, void* allocator, int file, int size, int skills, void* count);
struct List0204af64;
void ResetList0204af64(List0204af64* graphics);
extern "C" void func_0204b5b4(void* graphics, int priority);
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char* graphics, int value);
struct Obj0204b5e8;
void DispatchViaTable0204b5e8(Obj0204b5e8* graphics, int a, int b);
struct AllocTarget0204b12c;
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c* graphics, SafeAllocator* allocator);
struct Foo0204af38;
void AllocateArray0204af38(Foo0204af38* graphics, int count, SafeAllocator* allocator);
extern "C" void func_0204c684(void* canvas);
extern "C" void func_ov013_02187a58(void* self, void* canvas);
extern "C" void func_0204b174(void* graphics, void* file, SafeAllocator* allocator, unsigned int size);
struct EntryList0204af14;
void* GetEntryByIndexStride0x10(EntryList0204af14* graphics, unsigned int index);
struct Tilemap0204ae44;
void FillTilemapPalette0204ae44(Tilemap0204ae44* layer, int member);
struct Obj0204b988;
void DispatchIndexedEntry0204b988(Obj0204b988* graphics, unsigned int a, int b, int c, unsigned short d);
struct List0204b0e8;
void FlushAndDispatchList0204b0e8(List0204b0e8* graphics, void* characters);
extern "C" void func_020dc7e8(int a, int b);

extern char data_ov013_02187e48[];
extern char data_ov013_02187e61[];
extern char data_ov013_02187e77[];
extern char data_ov013_02187e89[];
extern char data_ov013_02187e9e[];
extern char data_ov013_02187eaf[];
extern const unsigned char data_ov013_02187db8[2];

#define BLDCNT (*(volatile unsigned short*)0x04000050)
#define BLDCNTSUB (*(volatile unsigned short*)0x04001050)

struct Sprite021870f0 {
    char unk_0[0x28];
};

struct SpriteRenderer021870f0 {
    char unk_0[0x40];
    Sprite021870f0* sprites_;
    char unk_44[4];
    unsigned int unk_48;
    short numSprites_;
    unsigned short capacity_;
    unsigned char unk_50;
    char unk_51[3];
};

struct BackgroundGraphics021870f0 {
    char unk_0[0x1c];
    unsigned char unk_1c_0_ : 4;
    unsigned char unk_1c_4_ : 4;
    unsigned char unk_1d;
    char unk_1e[2];
};

struct Canvas021870f0 {
    void* unk_0;
    void* background_;
    void* pixels_;
    char unk_c[0xa8 - 0xc];
    short width_;
    short height_;
    char unk_ac[0xb4 - 0xac];
    short unk_b4;
    short unk_b6;
    char unk_b8[0xe0 - 0xb8];
};

struct PartyMemberData021870f0 {
#if defined(jpn)
    char unk_0[0x8b8];
#else
    char unk_0[0x950];
#endif
    int vocation_;
};

struct SkillAbilityList021870f0 {
    SafeAllocator* allocators_;
    char names_[8];
    char abilities_[8];
    char unk_14[0x10];
    unsigned char unk_24;
    unsigned char unk_25;
    char unk_26[2];
    BackgroundGraphics021870f0 background_;
#if !defined(jpn)
    SpriteRenderer021870f0* spriteRenderer_;
    Sprite021870f0* sprites_;
    short* markerX_;
    short* markerY_;
    unsigned char* markerPalettes_;
#endif
    int task_;
    unsigned int planes_;
    unsigned char screen_;
    bool loaded_;
    unsigned char step_;
    signed char member_;
};

// USA: func_ov013_021870f0
extern "C" ARM bool func_ov013_021870f0(SkillAbilityList021870f0* self) {
    SafeAllocator* allocators;
    if (self->loaded_)
        return true;
    bool result = true;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->step_ == 0)
    {
#if defined(jpn)
        FontBankLoader* manager = GetGlobal02109400_02094a00();
        BlankFunction02094b3c(manager, 10);
        BlankFunction02094b30(manager, 0x68, 0);
#else
        SafeAllocator* allocators = self->allocators_;
        allocators[4].Reset();
        self->spriteRenderer_ = (SpriteRenderer021870f0*)allocators[4].Allocate(sizeof(SpriteRenderer021870f0));
        self->sprites_ = (Sprite021870f0*)allocators[4].Allocate(13 * sizeof(Sprite021870f0));
        self->markerX_ = (short*)allocators[4].Allocate(13 * sizeof(short));
        self->markerY_ = (short*)allocators[4].Allocate(13 * sizeof(short));
        self->markerPalettes_ = (unsigned char*)allocators[4].Allocate(13);
        InitStruct0205a444((char*)self->spriteRenderer_);
        self->spriteRenderer_->unk_50 = self->screen_;
        SpriteRenderer021870f0* renderer = self->spriteRenderer_;
        renderer->sprites_ = self->sprites_;
        renderer->numSprites_ = 13;
        for (int i = 0; i < 13; i++)
        {
            Init0205a198((Struct0205a198*)&self->sprites_[i]);
        }
        for (int i = 0; i < 10; i++)
        {
            self->markerX_[i] = -1;
            self->markerY_[i] = -1;
            self->markerPalettes_[i] = 2;
        }
        self->task_ = loader->QueueLoadFile(data_ov013_02187e48, NULL);
#endif
        result = false;
        self->step_++;
    }
    else if (self->step_ == 1)
    {
#if defined(jpn)
        if (AlwaysTrue02094b4c(GetGlobal02109400_02094a00())) {
            self->step_++;
        }
#else
        if (loader->GetTaskStatus(self->task_))
        {
            SafeAllocator* allocators = self->allocators_;
            void* name;
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            int numFiles = CountActiveEntries((ActiveEntry02046900*)file);
            for (int i = 0; i < numFiles; i++)
            {
                unsigned int dataSize;
                void* data = FindRecordByIndex((Rec020467f0*)file, i, &name, (int*)&dataSize);
                func_0205a528(self->spriteRenderer_, data, dataSize, &allocators[4]);
            }
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            self->step_++;
        }
#endif
        result = false;
    }
    else if (self->step_ == 2)
    {
        loader->MaybeFreeAllocations();
#if defined(jpn)
        self->task_ = loader->QueueLoadFile(data_ov013_02188de0, NULL);
#else
        self->task_ = loader->QueueLoadFileInGP2(data_ov013_02187e61, data_ov013_02187e77, NULL);
#endif
        result = false;
        self->step_++;
    }
    else if (self->step_ == 3)
    {
        if (loader->GetTaskStatus(self->task_))
        {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            SafeAllocator* allocators = self->allocators_;
            allocators[3].Reset();
            func_020728ac(self->names_, &allocators[3], file, size, 0, 0, 0);
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            self->step_++;
        }
        result = false;
    }
    else if (self->step_ == 4)
    {
        ClearList0208df10((List0208df10*)self->abilities_);
        loader->MaybeFreeAllocations();
#if defined(jpn)
        self->task_ = loader->QueueLoadFile(data_ov013_02188dfa, NULL);
#else
        self->task_ = loader->QueueLoadFileInGP2(data_ov013_02187e89, data_ov013_02187e9e, NULL);
#endif
        result = false;
        self->step_++;
    }
    else if (self->step_ == 5)
    {
        if (loader->GetTaskStatus(self->task_))
        {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            SafeAllocator* allocators = self->allocators_;
            allocators[2].Reset();
            short* skills = NULL;
            short vocationSkills[5] = {};
            GameObject* member = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), self->member_);
            if (member != NULL)
            {
                PartyMemberData021870f0* data = (PartyMemberData021870f0*)GetFieldAt0x150_02053c6c((unsigned char*)member);
                if (data != NULL)
                {
                    for (unsigned char i = 0; i < 5; i++)
                    {
                        vocationSkills[i] = GetTableByte020dd11c((unsigned char)data->vocation_, i);
                    }
                    skills = vocationSkills;
                }
            }
            InitAndRunScript0208df20((Struct0208df20*)self->abilities_, &allocators[2], (int)file, size, (int)skills, (void*)5);
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            self->step_++;
        }
        result = false;
    }
    else if (self->step_ == 6)
    {
        SafeAllocator* allocator = self->allocators_;
        allocator->Reset();
        unsigned char palettes[2];
        palettes[0] = data_ov013_02187db8[0];
        palettes[1] = data_ov013_02187db8[1];
        ResetList0204af64((List0204af64*)&self->background_);
        self->background_.unk_1c_0_ = self->screen_;
        self->background_.unk_1c_4_ = palettes[self->screen_];
        func_0204b5b4(&self->background_, 0);
        SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)&self->background_, 0);
        DispatchViaTable0204b5e8((Obj0204b5e8*)&self->background_, 0, 0);
        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)&self->background_, allocator);
        AllocateArray0204af38((Foo0204af38*)&self->background_, 1, allocator);
        if (self->screen_ == 0)
        {
            DISPCNT = (DISPCNT & ~0x1f00) | 0x1200;
            BLDCNT = 0;
        }
        else
        {
            BG0CNTSUB = (BG0CNTSUB & (3 | 0x40)) | (0xf << 8);
            BLDCNTSUB = 0;
        }
        result = false;
        self->step_++;
    }
    else if (self->step_ == 7)
    {
        loader->MaybeFreeAllocations();
        self->task_ = loader->QueueLoadFile(data_ov013_02187eaf, NULL);
        result = false;
        self->step_++;
    }
    else if (self->step_ == 8)
    {
        if (loader->GetTaskStatus(self->task_))
        {
            void* data;
            void* name;
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            int numFiles = CountActiveEntries((ActiveEntry02046900*)file);
            allocators = self->allocators_;
            allocators[1].Reset();
            for (int i = 0; i < numFiles; i++)
            {
                unsigned int dataSize;
                data = FindRecordByIndex((Rec020467f0*)file, i, &name, (int*)&dataSize);
                if (data != NULL)
                {
                    if (i == 0)
                    {
                        Canvas021870f0 canvas;
                        func_0204c684(&canvas);
                        canvas.unk_b4 = 0xa;
                        canvas.unk_b6 = 0xb;
                        canvas.width_ = 0x20;
                        canvas.height_ = 0x18;
                        canvas.pixels_ = (char*)data + 0x10;
                        func_ov013_02187a58(self, &canvas);
                    }
                    func_0204b174(&self->background_, data, &allocators[1], dataSize);
                }
            }
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            void* layer = GetEntryByIndexStride0x10((EntryList0204af14*)&self->background_, 0);
            if (layer != NULL)
                FillTilemapPalette0204ae44((Tilemap0204ae44*)layer, self->member_);
            DispatchIndexedEntry0204b988((Obj0204b988*)&self->background_, 0, 0, 0, 0xffff);
            FlushAndDispatchList0204b0e8((List0204b0e8*)&self->background_, NULL);
            self->loaded_ = true;
            self->step_ = 0;
            if (self->screen_ == 0)
                func_020dc7e8(4, -1);
            else
                func_020dc7e8(3, -1);
        }
        result = false;
    }
    return result;
}
