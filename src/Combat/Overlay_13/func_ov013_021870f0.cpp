#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "System/Graphics.h"

struct GameState {
    static GameState* GetInstance();
};

extern "C" void _Z18InitStruct0205a444Pc(char* renderer);
struct Struct0205a198;
extern "C" void _Z12Init0205a198P14Struct0205a198(Struct0205a198* sprite);
struct ActiveEntry02046900;
int CountActiveEntries(ActiveEntry02046900* pac);
struct Rec020467f0;
void* FindRecordByIndex(Rec020467f0* pac, int index, void** outName, int* outSize);
extern "C" void func_0205a528(void* renderer, void* file, unsigned int size, SafeAllocator* allocator);
extern "C" void func_020728ac(void* texts, SafeAllocator* allocator, void* file, unsigned int size, int, int, int);
struct List0208df10;
extern "C" void _Z17ClearList0208df10P12List0208df10(List0208df10* table);
void* GetCombatantWithFlag0x100(GameState* gameState, int member);
void* GetFieldAt0x150(unsigned char* member);
extern "C" signed char _Z20GetTableByte020dd11cjj(unsigned int vocation, unsigned int index);
struct Struct0208df20;
extern "C" void _Z24InitAndRunScript0208df20P14Struct0208df20PviiiS1_(Struct0208df20* table, void* allocator, int file, int size, int skills, void* count);
struct List0204af64;
extern "C" void _Z17ResetList0204af64P12List0204af64(List0204af64* graphics);
extern "C" void func_0204b5b4(void* graphics, int priority);
void SetWord0x18ClearByte0x1f(unsigned char* graphics, int value);
struct Obj0204b5e8;
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(Obj0204b5e8* graphics, int a, int b);
struct AllocTarget0204b12c;
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(AllocTarget0204b12c* graphics, SafeAllocator* allocator);
struct Foo0204af38;
extern "C" void _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(Foo0204af38* graphics, int count, SafeAllocator* allocator);
extern "C" void func_0204c684(void* canvas);
extern "C" void func_ov013_02187a58(void* self, void* canvas);
extern "C" void func_0204b174(void* graphics, void* file, SafeAllocator* allocator, unsigned int size);
struct EntryList0204af14;
void* GetEntryByIndexStride0x10(EntryList0204af14* graphics, unsigned int index);
struct Tilemap0204ae44;
extern "C" void _Z26FillTilemapPalette0204ae44P15Tilemap0204ae44i(Tilemap0204ae44* layer, int member);
struct Obj0204b988;
extern "C" void _Z28DispatchIndexedEntry0204b988P11Obj0204b988jiit(Obj0204b988* graphics, unsigned int a, int b, int c, unsigned short d);
struct List0204b0e8;
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(List0204b0e8* graphics, void* characters);
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
    char unk_0[0x950];
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
    SpriteRenderer021870f0* spriteRenderer_;
    Sprite021870f0* sprites_;
    short* markerX_;
    short* markerY_;
    unsigned char* markerPalettes_;
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
        SafeAllocator* allocators = self->allocators_;
        allocators[4].Reset();
        self->spriteRenderer_ = (SpriteRenderer021870f0*)allocators[4].Allocate(sizeof(SpriteRenderer021870f0));
        self->sprites_ = (Sprite021870f0*)allocators[4].Allocate(13 * sizeof(Sprite021870f0));
        self->markerX_ = (short*)allocators[4].Allocate(13 * sizeof(short));
        self->markerY_ = (short*)allocators[4].Allocate(13 * sizeof(short));
        self->markerPalettes_ = (unsigned char*)allocators[4].Allocate(13);
        _Z18InitStruct0205a444Pc((char*)self->spriteRenderer_);
        self->spriteRenderer_->unk_50 = self->screen_;
        SpriteRenderer021870f0* renderer = self->spriteRenderer_;
        renderer->sprites_ = self->sprites_;
        renderer->numSprites_ = 13;
        for (int i = 0; i < 13; i++)
        {
            _Z12Init0205a198P14Struct0205a198((Struct0205a198*)&self->sprites_[i]);
        }
        for (int i = 0; i < 10; i++)
        {
            self->markerX_[i] = -1;
            self->markerY_[i] = -1;
            self->markerPalettes_[i] = 2;
        }
        self->task_ = loader->QueueLoadFile(data_ov013_02187e48, NULL);
        result = false;
        self->step_++;
    }
    else if (self->step_ == 1)
    {
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
        result = false;
    }
    else if (self->step_ == 2)
    {
        loader->MaybeFreeAllocations();
        self->task_ = loader->QueueLoadFileInGP2(data_ov013_02187e61, data_ov013_02187e77, NULL);
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
        _Z17ClearList0208df10P12List0208df10((List0208df10*)self->abilities_);
        loader->MaybeFreeAllocations();
        self->task_ = loader->QueueLoadFileInGP2(data_ov013_02187e89, data_ov013_02187e9e, NULL);
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
            void* member = GetCombatantWithFlag0x100(GameState::GetInstance(), self->member_);
            if (member != NULL)
            {
                PartyMemberData021870f0* data = (PartyMemberData021870f0*)GetFieldAt0x150((unsigned char*)member);
                if (data != NULL)
                {
                    for (unsigned char i = 0; i < 5; i++)
                    {
                        vocationSkills[i] = _Z20GetTableByte020dd11cjj((unsigned char)data->vocation_, i);
                    }
                    skills = vocationSkills;
                }
            }
            _Z24InitAndRunScript0208df20P14Struct0208df20PviiiS1_((Struct0208df20*)self->abilities_, &allocators[2], (int)file, size, (int)skills, (void*)5);
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
        _Z17ResetList0204af64P12List0204af64((List0204af64*)&self->background_);
        self->background_.unk_1c_0_ = self->screen_;
        self->background_.unk_1c_4_ = palettes[self->screen_];
        func_0204b5b4(&self->background_, 0);
        SetWord0x18ClearByte0x1f((unsigned char*)&self->background_, 0);
        _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii((Obj0204b5e8*)&self->background_, 0, 0);
        _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator((AllocTarget0204b12c*)&self->background_, allocator);
        _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator((Foo0204af38*)&self->background_, 1, allocator);
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
                _Z26FillTilemapPalette0204ae44P15Tilemap0204ae44i((Tilemap0204ae44*)layer, self->member_);
            _Z28DispatchIndexedEntry0204b988P11Obj0204b988jiit((Obj0204b988*)&self->background_, 0, 0, 0, 0xffff);
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((List0204b0e8*)&self->background_, NULL);
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
