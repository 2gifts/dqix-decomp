#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "System/Graphics.h"
#include <globaldefs.h>

struct Background0216e2a4 {
    char unk_0[0x1c];
    unsigned char unk_1c_0_ : 4;
    unsigned char unk_1c_4_ : 4;
    unsigned char unk_1d;
    char unk_1e[2];
};

struct Canvas0216e2a4 {
    void *unk_0;
    Background0216e2a4 *background_;
    char unk_8[0xc4 - 8];
    unsigned char unk_c4;
    char unk_c5[0xe0 - 0xc5];
};

struct Window0216e2a4 {
    char unk_0[0x98];
    Background0216e2a4 *background_;
    char unk_9c[0xb2 - 0x9c];
    unsigned char unk_b2;
    char unk_b3[0xbc - 0xb3];
};

struct Menu0216e2a4 {
    char unk_0;
    char state_;
    char step_;
    char unk_3[0x14 - 3];
    void *pixels_;
    char unk_18[4];
    int task_;
    char unk_20[0x3c - 0x20];
    Window0216e2a4 *window_;
    Background0216e2a4 *backgrounds_;
    Canvas0216e2a4 *canvases_;
    char unk_48[0x60 - 0x48];
    int unk_60;
    int unk_64;
    char unk_68[0xa4 - 0x68];
    int unk_a4;
    int unk_a8;
    char unk_ac[0xb4 - 0xac];
    short unk_b4;
    char unk_b6[2];
    unsigned char unk_b8;
    char unk_b9[0xbc - 0xb9];
    SafeAllocator allocator_;
    SafeAllocator *allocatorPtr_;
    void *unk_d4;
    char unk_d8[4];
    char unk_dc[0x20];
};

struct AllocTarget0204b12c;
struct Obj0204b5e8;
struct ActiveEntry02046900;
struct Rec020467f0;
struct List0204b0e8;
struct Obj0204c7a8;
struct Struct_0205cf78;
struct Elem_0205cf78;

void SetWord0x18ClearByte0x1f(unsigned char *background, int a);
int CountActiveEntries(ActiveEntry02046900 *archive);
void *FindRecordByIndex(Rec020467f0 *archive, int index, void **name, int *size);
extern "C" void func_0204b5b4(Background0216e2a4 *background, int a);
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(AllocTarget0204b12c *background,
                                                                                         SafeAllocator *allocator);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(Obj0204b5e8 *background, int a, int b);
extern "C" void func_0204b174(Background0216e2a4 *background, void *file, SafeAllocator *allocator, unsigned int size);
extern "C" void func_0204bc74(Background0216e2a4 *background, int a, int b, int c, int d, int e, int f);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(List0204b0e8 *background, void *a);
extern "C" void _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(Obj0204c7a8 *canvas, SafeAllocator *allocator,
                                                                           int pixels, unsigned int size);
extern "C" void _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h(Struct_0205cf78 *window,
                                                                                     Elem_0205cf78 *canvases,
                                                                                     unsigned char count);
extern "C" void func_0205a528(void *renderer, void *file, unsigned int size, SafeAllocator *allocator);
extern "C" void func_020dfec0(void *texts, SafeAllocator *allocator, void *file, unsigned int size);
extern "C" void func_ov023_021e20f0(void *obj, SafeAllocator *allocator, void *file, unsigned int size);

extern const unsigned char data_ov003_0217f5ba[2];
extern const unsigned char data_ov003_0217f5b8[2];
extern char data_ov003_02180222[];
extern char data_ov003_02180235[];
extern char data_ov003_02180249[];
extern char data_ov003_02180260[];
extern char data_ov003_0218027a[];

// USA: func_ov003_0216e2a4
extern "C" ARM void func_ov003_0216e2a4(Menu0216e2a4 *self) {
    BackgroundLoader *loader = BackgroundLoader::GetInstance();

    if (self->step_ == 0) {
        Background0216e2a4 *background = self->backgrounds_;
        for (int i = 0; i < 2; i++) {
            SetWord0x18ClearByte0x1f((unsigned char *) background, 0);
            background->unk_1c_0_ = 0;
            background->unk_1c_4_ = data_ov003_0217f5ba[i];
            func_0204b5b4(background, data_ov003_0217f5b8[i]);
            _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator((AllocTarget0204b12c *) background,
                                                                                     self->allocatorPtr_);
            _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii((Obj0204b5e8 *) background, 0, 0);
            background++;
        }
        BG1CNT      = (BG1CNT & 0x43) | 0xd08;
        BG2CNT      = (BG2CNT & 0x43) | 0xe08;
        self->task_ = loader->QueueLoadFile(data_ov003_02180222, 0);
        self->step_ = 1;
    } else if (self->step_ == 1) {
        if (loader->GetTaskStatus(self->task_) != 0) {
            void *name;
            void *file;
            void *datas[2];
            unsigned int size;
            int sizes[2];
            loader->GetLoadedFileByID(self->task_, &file, &size);
            int count = CountActiveEntries((ActiveEntry02046900 *) file);
            for (int i = 0; i < count; i++)
                datas[i] = FindRecordByIndex((Rec020467f0 *) file, i, &name, &sizes[i]);
            for (int i = 0; i < count; i++) {
                if (datas[i] != 0) func_0204b174(self->backgrounds_, datas[i], self->allocatorPtr_, sizes[i]);
            }
            loader->RemoveTask(self->task_);
            self->task_                    = -1;
            Background0216e2a4 *background = self->backgrounds_;
            for (int i = 0; i < 2; i++) {
                func_0204bc74(background, 0, 0, 0, 0x20, 0x19, 0);
                _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((List0204b0e8 *) background, 0);
                background++;
            }
            self->pixels_          = self->allocatorPtr_->Allocate(0x2800);
            Canvas0216e2a4 *canvas = self->canvases_;
            for (int i = 0; i < 2; i++) {
                _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij((Obj0204c7a8 *) canvas, self->allocatorPtr_,
                                                                           (int) self->pixels_, 0x500);
                canvas->background_ = &self->backgrounds_[i];
                canvas->unk_c4      = 0;
                canvas++;
            }
            Window0216e2a4 *window = self->window_;
            window->background_    = self->backgrounds_;
            window->unk_b2         = 2;
            _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h((Struct_0205cf78 *) self->window_,
                                                                                 (Elem_0205cf78 *) self->canvases_, 2);
            self->unk_b8 = 0;
            self->unk_a8 = self->unk_60;
            self->unk_b4 = 0x16;
            self->unk_a4 = self->unk_64;
            self->task_  = loader->QueueLoadFile(data_ov003_02180235, 0);
            self->step_  = 2;
        }
    } else if (self->step_ == 2) {
        if (loader->GetTaskStatus(self->task_) != 0) {
            void *name;
            void *file;
            unsigned int size;
            int fileSize;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            int count = CountActiveEntries((ActiveEntry02046900 *) file);
            for (int i = 0; i < count; i++) {
                void *data = FindRecordByIndex((Rec020467f0 *) file, i, &name, &fileSize);
                func_0205a528((char *) self + 0x68, data, fileSize, &self->allocator_);
            }
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            self->task_ = loader->QueueLoadFile(data_ov003_02180249, 0);
            self->step_ = 3;
        }
    } else if (self->step_ == 3) {
        if (loader->GetTaskStatus(self->task_) != 0) {
            void *file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            func_ov023_021e20f0(self->unk_d4, self->allocatorPtr_, file, size);
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            self->task_ = loader->QueueLoadFileInGP2(data_ov003_02180260, data_ov003_0218027a, 0);
            self->step_ = 4;
        }
    } else if (self->step_ == 4) {
        if (loader->GetTaskStatus(self->task_) != 0) {
            void *file;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &file, &size);
            func_020dfec0(self->unk_dc, self->allocatorPtr_, file, size);
            loader->RemoveTask(self->task_);
            self->task_  = -1;
            self->state_ = 2;
            self->step_  = 0;
        }
    }
}
