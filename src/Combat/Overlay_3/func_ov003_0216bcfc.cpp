#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "System/Cache.h"
#include "System/LoadToVRAM.h"
#include "System/Memory.h"
#include <globaldefs.h>

struct Global0216bcfc {
    char unk_0[0x5c];
    char *text_;
    char unk_60[0x998 - 0x60];
    int unk_998;
    char unk_99c[4];
    int unk_9a0;
};

struct Menu0216bcfc {
    char unk_0[4];
    short state_;
    short step_;
    char unk_8[4];
    int task_;
    char unk_10[0x410 - 0x10];
    char sub_410[0x4e8 - 0x410];
    void *unk_4e8;
    char unk_4ec[0x1264 - 0x4ec];
    int unk_1264;
    int unk_1268;
    char unk_126c[0x12a8 - 0x126c];
    int unk_12a8;
    int unk_12ac;
    char unk_12b0[0x12b8 - 0x12b0];
    short unk_12b8;
    char unk_12ba[2];
    unsigned char unk_12bc;
    char unk_12bd[0x12d4 - 0x12bd];
    SafeAllocator allocator_;
    char unk_12e8[0x1310 - 0x12e8];
    SafeAllocator allocators_[1];
    char unk_1324[0x1334 - 0x1324];
};

struct AllocatorUnion;
struct S021700bc;
struct ActiveEntry02046900;
struct Rec020467f0;

int CheckField0NonZero(int *p);
int CountActiveEntries(ActiveEntry02046900 *archive);
void *FindRecordByIndex(Rec020467f0 *archive, int index, void **name, int *size);
void *AllocateAligned4(AllocatorUnion *alloc, unsigned int size);
void TailForward02012da4(AllocatorUnion *alloc, void *p);
void EmptyDestructor0205a494(void *p);
void InitField170_021700bc(S021700bc *p);
extern "C" void *func_0202ae18();
extern "C" void func_0202c288();
extern "C" void func_02043124(void *p);
extern "C" void func_0205a528(void *renderer, void *file, unsigned int size, SafeAllocator *allocator);
extern "C" void func_ov003_0216d8d4(void *self, int a, int b, int c, int d);
extern "C" void func_ov003_0216e02c(void *sub, SafeAllocator *allocator);
extern "C" int func_ov003_0216e124(void *sub);
extern "C" void func_ov003_021700dc(void *sub);
void *GetGlobalField0x1c020421a0();
extern "C" void *memset(void *dst, int value, unsigned int length);

extern char data_02114e20;
extern char data_ov003_021801c9[];

// USA: func_ov003_0216bcfc
extern "C" ARM void func_ov003_0216bcfc(Menu0216bcfc *self) {
    Global0216bcfc *global   = (Global0216bcfc *) GetGlobalField0x1c020421a0();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    void *obj                = func_0202ae18();

    if (self->step_ == 0) {
        func_0202c288();
        if (CheckField0NonZero((int *) obj) != 0 && (int) *((unsigned char *) obj + 0x100d) > 1) {
            func_ov003_0216d8d4(self, 0x5d, -1, -1, -1);
            self->step_  = 0;
            self->state_ = 2;
            self->step_  = 0;
            return;
        }
        Global0216bcfc *global2 = (Global0216bcfc *) GetGlobalField0x1c020421a0();
        memset(global2->text_, 0, 0x960);
        void *buffer = AllocateAligned4((AllocatorUnion *) &data_02114e20, 0x8000);
        VectorizedMemset(buffer, 0, 0x8000);
        self->allocator_.CreateTypeA(buffer, 0x8000);
        self->allocator_.Reset();
        InitField170_021700bc((S021700bc *) self->sub_410);
        func_ov003_0216e02c(self->sub_410, &self->allocator_);
        self->unk_4e8 = &self->unk_1324;
        char pixels[0x20];
        memset(pixels, 0, 0x20);
        CleanInvalidateCacheRange(pixels, 0x20);
        LoadToMainBG1CharacterData(pixels, 0, 0x20);
        self->step_ = 1;
        func_02043124(global2);
    }
    if (self->step_ == 1) {
        if (func_ov003_0216e124(self->sub_410) == 0) self->step_ = 2;
    }
    if (self->step_ == 2) {
        func_ov003_021700dc(self->sub_410);
        SignedAllocatorHeader *signedAlloc = self->allocator_.GetSignedAllocator();
        if (signedAlloc != 0) {
            self->allocator_.Destroy();
            TailForward02012da4((AllocatorUnion *) &data_02114e20, signedAlloc);
        }
        EmptyDestructor0205a494((char *) self + 0x126c);
        self->unk_12bc = 0;
        self->unk_12ac = self->unk_1264;
        self->unk_12b8 = 0xf;
        self->unk_12a8 = self->unk_1268;
        self->allocators_[0].Reset();
        self->task_ = loader->QueueLoadFile(data_ov003_021801c9, 0);
        self->step_ = 3;
    }
    if (self->step_ == 3 && loader->GetTaskStatus(self->task_) != 0) {
        void *name;
        void *file;
        unsigned int size;
        int fileSize;
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int count            = CountActiveEntries((ActiveEntry02046900 *) file);
        SafeAllocator *alloc = &self->allocators_[0];
        for (int i = 0; i < count; i++) {
            void *data = FindRecordByIndex((Rec020467f0 *) file, i, &name, &fileSize);
            func_0205a528((char *) self + 0x126c, data, fileSize, alloc);
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        func_ov003_0216d8d4(self, 0x29, -1, -1, -1);
        global->unk_998 = 1;
        self->step_     = 0;
        self->state_    = 2;
        self->step_     = 0;
    }
    if (self->step_ == 0xc8 && global->unk_9a0 == 0) {
        func_ov003_0216d8d4(self, 0x29, -1, -1, -1);
        self->step_  = 0;
        self->state_ = 2;
        self->step_  = 0;
    }
}
