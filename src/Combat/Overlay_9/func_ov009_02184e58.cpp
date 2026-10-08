#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "System/Graphics.h"

struct BackgroundGraphics {
    char unk_0[0x1c];
    unsigned char unk_1c_0_ : 4;
    unsigned char unk_1c_4_ : 4;
    unsigned char unk_1d;
    char unk_1e[2];
};

struct BackgroundPart {
    char unk_0[0xc];
    void* unk_c;
};

struct List0204af64;
struct Obj0204b5e8;
struct AllocTarget0204b12c;
struct Foo0204af38;
struct Rec020467f0;
struct ActiveEntry02046900;
struct Obj0204b8d0;
struct List0204b0e8;
struct SelfTag0204b3a0;
struct EntryList0204af14;
struct Struct0200fb08;

void ResetList0204af64(List0204af64* background);
void SetWord0x18ClearByte0x1f(unsigned char* background, int value);
extern "C" void func_0204b5b4(BackgroundGraphics* background, int screen);
void DispatchViaTable0204b5e8(Obj0204b5e8* background, int a, int b);
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c* background, SafeAllocator* allocator);
void AllocateArray0204af38(Foo0204af38* background, int count, SafeAllocator* allocator);
int CountActiveEntries(ActiveEntry02046900* archive);
void* FindRecordByIndex(Rec020467f0* archive, int index, void** name, int* size);
extern "C" void func_0204b174(BackgroundGraphics* background, void* file, SafeAllocator* allocator, unsigned int size);
void DispatchEntry0204b8d0(Obj0204b8d0* background, unsigned int a, int b, int c, short d, short e, short f, short g,
                           unsigned short h);
void FlushAndDispatchList0204b0e8(List0204b0e8* background, void* a);
extern "C" void func_0204bc74(BackgroundGraphics* background, int a, int b, int c, int d, int e, int f);
extern "C" int func_02001aec(const void* a, const void* b, unsigned int length);
void DispatchByTag0204b2e0(void* background, char* file);
void DispatchByTagLookup0204b3a0(SelfTag0204b3a0* background, char* file);
void* GetEntryByIndexStride0x10(EntryList0204af14* background, unsigned int index);
extern "C" void func_0204b620(BackgroundGraphics* graphics, void* a, void* b, int c, int d, int e, int f, int g, int h,
                              int i);
int NormalizeField5_0200fb08(Struct0200fb08* state);
extern "C" void func_ov023_021da274(void* self);
void RefreshFieldIfFlag4000_021d9d34(char* self);
void BuildFieldTag_021d9e60(char* self);

extern const unsigned char data_ov009_0218a95d[];
extern const unsigned char data_ov009_0218a95f[];
extern const signed char data_ov009_0218a961[];
extern const unsigned char data_ov009_0218a963[];
extern const signed char data_ov009_0218a966[];
extern const signed char data_ov009_0218a969[];
extern const signed char data_ov009_0218aa54[];
extern char data_ov009_0218aca6[];
extern char data_ov009_0218acab[];

struct CharacterCreation {
    SafeAllocator allocators_[9];
    char unk_b4[0x138 - 0xb4];
    BackgroundGraphics backgrounds_[6];
    char unk_1f8[0xc58 - 0x1f8];
    signed char state_;
    unsigned char step_;
    char unk_c5a[0xd90 - 0xc5a];
    int task_;
    unsigned char loadStep_;
    unsigned char mode_;
    char unk_d96[0xd9c - 0xd96];
    unsigned int flags_;
    char unk_da0[0xdb6 - 0xda0];
    unsigned char unk_db6;
};

// USA: func_ov009_02184e58
extern "C" ARM void func_ov009_02184e58(CharacterCreation* self)
{
    int firstEnd;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int first;
    int last;
    signed char state = self->state_;
    if (self->loadStep_ != 2)
        return;

    if (state == 10)
    {
        self->allocators_[0].Reset();
        BackgroundGraphics* backgrounds[] = {&self->backgrounds_[0], &self->backgrounds_[1], &self->backgrounds_[2]};
        for (int i = 0; i < 3; i++)
        {
            BackgroundGraphics* background = backgrounds[i];
            ResetList0204af64((List0204af64*)background);
            SetWord0x18ClearByte0x1f((unsigned char*)background, 0);
            background->unk_1c_0_ = 0;
            background->unk_1c_4_ = data_ov009_0218a963[i];
            func_0204b5b4(background, data_ov009_0218a969[i]);
            DispatchViaTable0204b5e8((Obj0204b5e8*)background, 0, 0);
            AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)background, &self->allocators_[0]);
            if (data_ov009_0218a966[i] > 0)
                AllocateArray0204af38((Foo0204af38*)background, (unsigned char)data_ov009_0218a966[i], &self->allocators_[0]);
        }
        char name[4];
        void* archive;
        unsigned int archiveSize;
        loader->GetLoadedFileByID(self->task_, &archive, &archiveSize);
        int count = CountActiveEntries((ActiveEntry02046900*)archive);
        if (self->mode_ == 1)
            count--;
        for (int i = 0; i < count; i++)
        {
            unsigned int size;
            void* file = FindRecordByIndex((Rec020467f0*)archive, i, (void**)name, (int*)&size);
            if (file != NULL)
            {
                if (i == 2)
                {
                    func_0204b174(&self->backgrounds_[1], file, &self->allocators_[0], size);
                    func_0204b174(&self->backgrounds_[2], file, &self->allocators_[0], size);
                }
                else
                {
                    func_0204b174(&self->backgrounds_[0], file, &self->allocators_[0], size);
                }
            }
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        DispatchEntry0204b8d0((Obj0204b8d0*)&self->backgrounds_[0], 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
        FlushAndDispatchList0204b0e8((List0204b0e8*)&self->backgrounds_[0], 0);
        func_0204bc74(&self->backgrounds_[1], 0, 0, 0, 0x20, 0x19, 0);
        FlushAndDispatchList0204b0e8((List0204b0e8*)&self->backgrounds_[1], 0);
        func_0204bc74(&self->backgrounds_[2], 0, 0, 0, 0x20, 0x19, 0);
        FlushAndDispatchList0204b0e8((List0204b0e8*)&self->backgrounds_[2], 0);
        self->flags_ &= ~0x80;
        self->loadStep_ = 0;
        return;
    }

    DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1500;
    self->allocators_[1].Reset();
    first = 0;
    BackgroundGraphics* backgrounds[] = {&self->backgrounds_[3], &self->backgrounds_[4]};
    for (int i = 0; i < 2; i++)
    {
        BackgroundGraphics* background = backgrounds[i];
        ResetList0204af64((List0204af64*)background);
        SetWord0x18ClearByte0x1f((unsigned char*)background, 0);
        background->unk_1c_0_ = 1;
        background->unk_1c_4_ = data_ov009_0218a95f[i];
        func_0204b5b4(background, data_ov009_0218a961[i]);
        DispatchViaTable0204b5e8((Obj0204b5e8*)background, 0, 0);
        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)background, &self->allocators_[1]);
        unsigned char screen = 0;
        for (int j = 0; data_ov009_0218aa54[j] >= 0; j += 3)
        {
            if (state == data_ov009_0218aa54[j])
            {
                screen = data_ov009_0218aa54[j + i + 1];
                if (i == 0)
                    first = screen;
                break;
            }
        }
        if (screen != 0)
            AllocateArray0204af38((Foo0204af38*)background, screen, &self->allocators_[1]);
    }

    char name[4];
    void* archive;
    unsigned int archiveSize;
    unsigned int size;
    loader->GetLoadedFileByID(self->task_, &archive, &archiveSize);
    int count = CountActiveEntries((ActiveEntry02046900*)archive);
    if (state == 8)
        self->unk_db6 = self->unk_db6 == 0 ? 1 : 0;
    unsigned char palette = 0;
    last = count - 1;
    firstEnd = first + 1;
    void* file;
    for (int i = 0; i < count; i++)
    {
        file = FindRecordByIndex((Rec020467f0*)archive, i, (void**)name, (int*)&size);
        if (file == NULL)
            continue;
        char type[5] = {};
        memcpy(type, file, 4);
        if (func_02001aec(type, data_ov009_0218aca6, 4) == 0 && data_ov009_0218a95d[palette++] == self->mode_)
            continue;
        if (state == 8)
        {
            BackgroundGraphics* background = &self->backgrounds_[4];
            if (i < first)
                background = &self->backgrounds_[3];
            if (i == last)
                background = &self->backgrounds_[3];
            if (self->unk_db6 != 0)
            {
                if (i != last)
                    DispatchByTag0204b2e0(background, (char*)file);
            }
            else
            {
                if (i != last)
                    DispatchByTagLookup0204b3a0((SelfTag0204b3a0*)background, (char*)file);
                if (func_02001aec(type, data_ov009_0218acab, 4) == 0)
                    func_0204b174(background, file, &self->allocators_[1], size);
            }
        }
        else if (i < firstEnd)
        {
            func_0204b174(&self->backgrounds_[3], file, &self->allocators_[1], size);
        }
        else
        {
            func_0204b174(&self->backgrounds_[4], file, &self->allocators_[1], size);
        }
    }

    if (self->unk_db6 != 0)
        return;
    loader->RemoveTask(self->task_);
    self->task_ = -1;
    int unk = 0;
    if (self->mode_ == 0 && state == 1)
        unk = 1;
    if (state == 8 && self->mode_ == 1)
    {
        void* palettes = GetEntryByIndexStride0x10((EntryList0204af14*)&self->backgrounds_[3], 4);
        for (int i = 0; i < 4; i++)
        {
            BackgroundPart* part = (BackgroundPart*)GetEntryByIndexStride0x10((EntryList0204af14*)&self->backgrounds_[3], (unsigned char)i);
            BackgroundGraphics graphics;
            ResetList0204af64((List0204af64*)&graphics);
            func_0204b620(&graphics, part->unk_c, palettes, 0, 0, 0x13, 0x11, 4, 2, 1);
        }
    }
    DispatchEntry0204b8d0((Obj0204b8d0*)&self->backgrounds_[3], unk, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
    if (self->backgrounds_[3].unk_1d == 5)
    {
        int type = NormalizeField5_0200fb08((Struct0200fb08*)GameState::GetInstance());
        int unk2 = 0;
        switch (type)
        {
        case 2:
            unk2 = 1;
            break;
        case 4:
            unk2 = 2;
            break;
        case 3:
            unk2 = 3;
            break;
        case 5:
            unk2 = 4;
            break;
        }
        if (unk2 != 0)
            DispatchEntry0204b8d0((Obj0204b8d0*)&self->backgrounds_[3], unk2, 0, 0, 1, 1, 0xd, 3, 0xffff);
    }
    func_0204bc74(&self->backgrounds_[4], 0, 0, 0, 0x20, 0x19, 0);
    self->flags_ |= 0x2000;
    if (self->backgrounds_[4].unk_1d != 0)
        func_ov023_021da274(self);
    self->flags_ &= ~0x2000;
    FlushAndDispatchList0204b0e8((List0204b0e8*)&self->backgrounds_[3], 0);
    FlushAndDispatchList0204b0e8((List0204b0e8*)&self->backgrounds_[4], 0);
    self->flags_ |= 0x4000;
    RefreshFieldIfFlag4000_021d9d34((char*)self);
    self->flags_ &= ~0x4000;
    self->flags_ |= 0x8000;
    BuildFieldTag_021d9e60((char*)self);
    self->flags_ &= ~0x8000;
    self->flags_ &= ~0x80;
    self->loadStep_ = 0;
    DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1700;
}
