#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include <System/Cache.h>

#define REG_DISPCNT_SUB (*(volatile unsigned int*)0x04001000)
#define REG_BG0CNT_SUB (*(volatile unsigned short*)0x04001008)
#define REG_BG1CNT_SUB (*(volatile unsigned short*)0x0400100a)
#define REG_BG0OFS_SUB (*(volatile unsigned int*)0x04001010)
#define REG_BG1OFS_SUB (*(volatile unsigned int*)0x04001014)
#define REG_BLDCNT_SUB (*(volatile unsigned short*)0x04001050)

struct BackgroundGraphics_021e76c4 {
    char unk_0[0x1c];
    unsigned char unk_1c_0_ : 4;
    unsigned char unk_1c_4_ : 4;
    unsigned char unk_1d;
    char unk_1e[2];
};

struct Canvas_021e76c4 {
    Canvas_021e76c4* unk_0;
    BackgroundGraphics_021e76c4* background_;
    char unk_8[0xe0 - 8];
};

struct TextWindow_021e76c4 {
    char base_[0x98];
    BackgroundGraphics_021e76c4* background_;
    char unk_9c[0xb2 - 0x9c];
    unsigned char unk_b2;
    char unk_b3[0xbc - 0xb3];
};

struct ScreenData_021e76c4 {
    char unk_0[8];
    unsigned int size_;
    void* data_;
};

struct MessageSystem_021e76c4 {
#if defined(jpn)
    char unk_0[0x28];
#else
    char unk_0[0x5c];
#endif
    void* unk_5c;
};

struct ProfileCard_021e76c4 {
    SafeAllocator allocators_[3];
    int mode_;
    unsigned int subBGBanks_;
    unsigned int subObjBanks_;
    unsigned int subLayers_;
    char cardTexts_[0x18];
    char unk_64[0x10];
    unsigned char unk_74;
    unsigned char unk_75;
    char unk_76[2];
    TextWindow_021e76c4 window_;
    BackgroundGraphics_021e76c4 backgrounds_[2];
    Canvas_021e76c4 canvases_[5];
    void* pixels_;
    char* text_;
    int loaded_;
    int step_;
    int task_;
};

struct AllocTarget0204b12c;
struct Obj0204b5e8;
struct Foo0204af38;
struct ActiveEntry02046900;
struct Rec020467f0;
struct List0204b0e8;
struct EntryList0204af14;
struct Obj0204c7a8;
struct Struct_0205cf78;
struct Elem_0205cf78;

extern "C" MessageSystem_021e76c4* _Z26GetGlobalField0x1c020421a0v();
void SetWord0x18ClearByte0x1f(unsigned char* obj, int value);
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(AllocTarget0204b12c* obj, SafeAllocator* alloc);
extern "C" int _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(Obj0204b5e8* obj, int a, int b);
extern "C" void _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(Foo0204af38* obj, int count, SafeAllocator* alloc);
int CountActiveEntries(ActiveEntry02046900* entry);
void* FindRecordByIndex(Rec020467f0* rec, int index, void** out, int* out44);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(List0204b0e8* obj, void* buf);
ScreenData_021e76c4* GetEntryByIndexStride0x10(EntryList0204af14* list, unsigned int index);
extern "C" void _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(Obj0204c7a8* obj, SafeAllocator* alloc, int val, unsigned int len);
extern "C" void _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h(Struct_0205cf78* s, Elem_0205cf78* arr, unsigned char count);

extern "C" {
void __clear(void* buffer, unsigned long size);
void func_020dfec0(void* texts, SafeAllocator* allocator, void* file, unsigned int size);
void func_0204b5b4(BackgroundGraphics_021e76c4* background, int index);
void DisableSubBGVRAMBanks();
void MapVRAMBanksToSubBG(int banks);
void func_0204b174(BackgroundGraphics_021e76c4* background, void* file, SafeAllocator* allocator, unsigned int size);
void func_0204bc74(BackgroundGraphics_021e76c4* background, int a, int b, int c, int d, int e, int f);
void LoadToSubBG1ScreenData(void* data, int offset, unsigned int size);
void func_020dc7e8(int a, int b);
void LoadToSubBGStandardPalette(const void* data, int offset, unsigned int size);
}

extern const char data_ov023_021fdd6e[];
#if defined(jpn)
extern const char data_ov023_021fd018[];
#endif
extern const char data_ov023_021fdd88[];
extern const char data_ov023_021fdd99[];
extern const unsigned short data_ov023_021fd760;

// JPN: func_ov023_021e78b4
// USA: func_ov023_021e76c4
extern "C" ARM int func_ov023_021e76c4(ProfileCard_021e76c4* self)
{
    void* files[4];
    unsigned int sizes[4];
    void* file;
    unsigned int size;
    int screens[2];
    char name[4];
    void* archive;
    unsigned int archiveSize;
    if (self->loaded_ != 0)
        return 1;
    int result = 1;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->step_ == 0)
    {
        REG_BG0OFS_SUB = 0;
        REG_BG1OFS_SUB = 0;
#if defined(jpn)
        self->task_ = loader->QueueLoadFile(data_ov023_021fd018, NULL);
#else
        self->task_ = loader->QueueLoadFileInGP2(data_ov023_021fdd6e, data_ov023_021fdd88, NULL);
#endif
        result = 0;
        self->step_++;
    }
    else if (self->step_ == 1)
    {
        if (loader->GetTaskStatus(self->task_))
        {
            loader->GetLoadedFileByID(self->task_, &file, &size);
            self->allocators_[2].Reset();
            func_020dfec0(self->cardTexts_, &self->allocators_[2], file, size);
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            self->step_++;
        }
        result = 0;
    }
    else if (self->step_ == 2)
    {
        self->allocators_[0].Reset();
        self->text_ = (char*)_Z26GetGlobalField0x1c020421a0v()->unk_5c;
        __clear(screens, sizeof(screens));
        BackgroundGraphics_021e76c4* background;
        int i;
        for (i = 0; i < 2; i++)
        {
            background = &self->backgrounds_[i];
            SetWord0x18ClearByte0x1f((unsigned char*)background, screens[i]);
            background->unk_1c_0_ = 1;
            background->unk_1c_4_ = i;
            func_0204b5b4(background, i);
            _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator((AllocTarget0204b12c*)background, &self->allocators_[1]);
            _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii((Obj0204b5e8*)background, 0, 0);
        }
        _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator((Foo0204af38*)&self->backgrounds_[1], 1, &self->allocators_[1]);
        DisableSubBGVRAMBanks();
        MapVRAMBanksToSubBG(0x80);
        REG_BG0CNT_SUB = (REG_BG0CNT_SUB & 0x43) | 0xe00;
        REG_BG1CNT_SUB = (REG_BG1CNT_SUB & 0x43) | 0xf00;
        REG_BLDCNT_SUB = 0;
        loader->MaybeFreeAllocations();
        self->task_ = loader->QueueLoadFile(data_ov023_021fdd99, NULL);
        result = 0;
        self->step_++;
    }
    else if (self->step_ == 3)
    {
        if (loader->GetTaskStatus(self->task_))
        {
            loader->GetLoadedFileByID(self->task_, &archive, &archiveSize);
            int count = CountActiveEntries((ActiveEntry02046900*)archive);
            for (int i = 0; i < count; i++)
                files[i] = FindRecordByIndex((Rec020467f0*)archive, i, (void**)name, (int*)&sizes[i]);
            BackgroundGraphics_021e76c4* background = &self->backgrounds_[0];
            for (int i = 0; i < count; i++)
            {
                if (files[i] != NULL)
                    func_0204b174(background, files[i], &self->allocators_[1], sizes[i]);
                background = &self->backgrounds_[1];
            }
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            func_0204bc74(&self->backgrounds_[0], 0, 0, 0, 0x20, 0x19, 0);
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((List0204b0e8*)&self->backgrounds_[0], 0);
            ScreenData_021e76c4* screen = GetEntryByIndexStride0x10((EntryList0204af14*)&self->backgrounds_[1], 0);
            if (screen != NULL)
            {
                void* data;
                unsigned int screenSize;
                screenSize = screen->size_;
                data = screen->data_;
                CleanInvalidateCacheRange(data, screenSize);
                LoadToSubBG1ScreenData(data, 0, screenSize);
            }
            self->pixels_ = self->allocators_[0].Allocate(0x4e00);
            Canvas_021e76c4* canvas;
            int j;
            for (j = 0; j < 4; j++)
            {
                canvas = &self->canvases_[j];
                _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij((Obj0204c7a8*)canvas, &self->allocators_[1], (int)self->pixels_, 0x600);
                canvas->background_ = &self->backgrounds_[0];
            }
            canvas = &self->canvases_[4];
            _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij((Obj0204c7a8*)canvas, &self->allocators_[1], (int)self->pixels_, 0x40);
            canvas->background_ = &self->backgrounds_[0];
            self->window_.background_ = &self->backgrounds_[0];
            self->window_.unk_b2 = 1;
            _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h((Struct_0205cf78*)&self->window_, (Elem_0205cf78*)self->canvases_, 5);
            self->step_++;
        }
        result = 0;
    }
    else if (self->step_ == 4)
    {
        REG_DISPCNT_SUB = (REG_DISPCNT_SUB & ~0x1f00) | 0x1300;
        self->loaded_ = result;
        self->step_ = 0;
        func_020dc7e8(2, -1);
        CleanInvalidateCacheRange(&data_ov023_021fd760, 2);
        LoadToSubBGStandardPalette(&data_ov023_021fd760, 2, 2);
        CleanCacheRange(&data_ov023_021fd760, 2);
        CleanInvalidateCacheRange(&data_ov023_021fd760, 2);
        LoadToSubBGStandardPalette(&data_ov023_021fd760, 0x22, 2);
        CleanCacheRange(&data_ov023_021fd760, 2);
    }
    return result;
}
