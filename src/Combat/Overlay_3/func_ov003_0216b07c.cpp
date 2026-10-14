#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "System/ColorEffects.h"
#include "System/Graphics.h"
#include <globaldefs.h>

struct Background0216b07c {
    char unk_0[0x1c];
    unsigned char unk_1c_0_ : 4;
    unsigned char unk_1c_4_ : 4;
    unsigned char unk_1d;
    char unk_1e[2];
};

struct Canvas0216b07c {
    void *unk_0;
    Background0216b07c *background_;
    char unk_8[0xc4 - 8];
    unsigned char unk_c4;
    char unk_c5[0xe0 - 0xc5];
};

struct Window0216b07c {
    char unk_0[0x98];
    Background0216b07c *background_;
    char unk_9c[0xb2 - 0x9c];
    unsigned char unk_b2;
    char unk_b3[0xbc - 0xb3];
};

struct Global0216b07c {
    char unk_0[0x5c];
    char *text_;
    char unk_60[0x998 - 0x60];
    int unk_998;
    int unk_99c;
    char unk_9a0[0x19b2 - 0x9a0];
    unsigned char unk_19b2;
};

struct Menu0216b07c {
    char unk_0[4];
    short state_;
    short step_;
    char unk_8[2];
    short mode_;
    char unk_c[0x1264 - 0xc];
    int unk_1264;
    int unk_1268;
    char unk_126c[0x12a8 - 0x126c];
    int unk_12a8;
    int unk_12ac;
    char unk_12b0[0x12b8 - 0x12b0];
    short unk_12b8;
    char unk_12ba[2];
    unsigned char unk_12bc;
    char unk_12bd[0x12c0 - 0x12bd];
    Window0216b07c *window_;
    Background0216b07c *backgrounds_;
    Canvas0216b07c *canvases_;
    void *pixels_;
    SafeAllocator *allocator_;
    char unk_12d4[0x12fc - 0x12d4];
    SafeAllocator allocators_[2];
    char unk_1324[0x13ea - 0x1324];
    unsigned char unk_13ea;
    char unk_13eb;
    unsigned char flags_13ec;
    char unk_13ed[0x13fc - 0x13ed];
    int tasks_[3];
};

struct Obj020397cc;
struct AllocTarget0204b12c;
struct Obj0204b5e8;
struct ActiveEntry02046900;
struct Rec020467f0;
struct List0204b0e8;
struct Obj0204c7a8;
struct Struct_0205cf78;
struct Elem_0205cf78;

void CancelPendingAction020397cc(Obj020397cc *obj, int a);
int AppendString02042058(char *dst, const char *src);
const char *CallFunc020e0434With02153694(int id);
void SetWord0x18ClearByte0x1f(unsigned char *background, int a);
int CountActiveEntries(ActiveEntry02046900 *archive);
void *FindRecordByIndex(Rec020467f0 *archive, int index, void **name, int *size);
int CheckField0NonZero(int *p);
extern "C" void *func_0202ae18();
extern "C" int func_0202c508();
extern "C" int func_0202c540(void *p);
extern "C" void func_02046380(void *p);
extern "C" void func_0204500c(void *p, const char *text, int a, int b);
extern "C" void func_0205a528(void *renderer, void *file, unsigned int size, SafeAllocator *allocator);
extern "C" void func_020dfec0(void *texts, SafeAllocator *allocator, void *file, unsigned int size);
extern "C" void func_0204b5b4(Background0216b07c *background, int a);
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c *background,
                                                                                         SafeAllocator *allocator);
void DispatchViaTable0204b5e8(Obj0204b5e8 *background, int a, int b);
extern "C" void func_0204b174(Background0216b07c *background, void *file, SafeAllocator *allocator, unsigned int size);
extern "C" void func_0204bc74(Background0216b07c *background, int a, int b, int c, int d, int e, int f);
void FlushAndDispatchList0204b0e8(List0204b0e8 *background, void *a);
void AllocateBuffer0204c7a8(Obj0204c7a8 *canvas, SafeAllocator *allocator,
                                                                           int pixels, unsigned int size);
void LinkArrayPrevPointers0205cf78(Struct_0205cf78 *window,
                                                                                     Elem_0205cf78 *canvases,
                                                                                     unsigned char count);
void *GetGlobalField0x1c020421a0();

struct Names0216b07c {
    const char *names_[3];
};
extern Names0216b07c data_ov003_0217f56c;
extern char data_ov003_02180198[];

struct BgCnt0216b07c {
    volatile unsigned short priority_ : 2;
    volatile unsigned short rest_ : 14;
};

// USA: func_ov003_0216b07c
extern "C" ARM void func_ov003_0216b07c(Menu0216b07c *self) {
    Global0216b07c *global   = (Global0216b07c *) GetGlobalField0x1c020421a0();
    GameState *state         = GameState::GetInstance();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();

    if (self->step_ == 0) {
        CancelPendingAction020397cc((Obj020397cc *) state->GetUnknownGameObject(), 1);
        ColorEffect_ConfigureAlphaBlend(0x4000050, 0x10, 1, 0x1f, 0);
        func_0202ae18();
        if (func_0202c508() != 0 && *(short *) ((char *) state->GetUnknownGameObject() + 4) == 0) {
            if (self->mode_ == 3) {
                global->unk_998 = 1;
                char *text      = global->text_;
                AppendString02042058(text, CallFunc020e0434With02153694(0x44));
                func_02046380(global);
                func_0204500c(global, global->text_, 0, 0xe3);
                global->unk_19b2 = 1;
                global->unk_99c  = 2;
                global->unk_998  = 1;
            }
        } else {
            self->unk_13ea = 1;
            self->flags_13ec |= 1;
            self->state_ = 3;
            self->step_  = 0;
            return;
        }
        self->allocators_[0].CreateTypeA(self->allocator_->Allocate(0x3800), 0x3800);
        self->allocators_[1].CreateTypeA(self->allocator_->Allocate(0xc00), 0xc00);
        self->allocators_[1].Reset();
        int i               = 0;
        self->unk_12bc      = 0;
        self->unk_12ac      = self->unk_1264;
        self->unk_12b8      = 0xf;
        self->unk_12a8      = self->unk_1268;
        Names0216b07c names = data_ov003_0217f56c;
        int zero            = 0;
        for (; i < 3; i++) {
            int id;
            if (i == 0)
                id = loader->QueueLoadFileInGP2(data_ov003_02180198, names.names_[i], (SafeAllocator *) zero);
            else
                id = loader->QueueLoadFile(names.names_[i], (SafeAllocator *) zero);
            self->tasks_[i] = id;
        }
        self->step_ = 1;
    }
    if (self->step_ == 1) {
        for (int i = 0; i < 3; i++) {
            if (self->tasks_[i] == -1) continue;
            if (loader->GetTaskStatus(self->tasks_[i]) != 0) {
                self->step_ = i + 2;
                break;
            }
        }
    }
    if (self->step_ == 4) {
        void *name;
        void *file;
        unsigned int size;
        int fileSize;
        int task = self->tasks_[2];
        loader->GetLoadedFileByID(task, &file, &size);
        int count            = CountActiveEntries((ActiveEntry02046900 *) file);
        SafeAllocator *alloc = &self->allocators_[1];
        for (int i = 0; i < count; i++) {
            void *data = FindRecordByIndex((Rec020467f0 *) file, i, &name, &fileSize);
            func_0205a528((char *) self + 0x126c, data, fileSize, alloc);
        }
        loader->RemoveTask(task);
        self->tasks_[2] = -1;
        self->step_     = 1;
    }
    if (self->step_ == 3) {
        Background0216b07c *background = self->backgrounds_;
        SetWord0x18ClearByte0x1f((unsigned char *) background, 0);
        background->unk_1c_0_ = 0;
        background->unk_1c_4_ = 1;
        func_0204b5b4(background, 0);
        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c *) background,
                                                                                 self->allocator_);
        DispatchViaTable0204b5e8((Obj0204b5e8 *) background, 0, 0);
        BG1CNT                     = (BG1CNT & 0x43) | 0xd08;
        Background0216b07c *second = self->backgrounds_;
        SetWord0x18ClearByte0x1f((unsigned char *) &second[1], 0);
        second[1].unk_1c_0_ = 0;
        second[1].unk_1c_4_ = 2;
        func_0204b5b4(&second[1], 1);
        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c *) &second[1],
                                                                                 self->allocator_);
        DispatchViaTable0204b5e8((Obj0204b5e8 *) &second[1], 0, 0);
        BG2CNT = (BG2CNT & 0x43) | 0xe08;
        void *name;
        void *file;
        void *datas[2];
        unsigned int size;
        int sizes[2];
        int task = self->tasks_[1];
        loader->GetLoadedFileByID(task, &file, &size);
        int count  = CountActiveEntries((ActiveEntry02046900 *) file);
        background = self->backgrounds_;
        for (int i = 0; i < count; i++) {
            datas[i] = FindRecordByIndex((Rec020467f0 *) file, i, &name, &sizes[i]);
        }
        for (int i = 0; i < count; i++) {
            if (datas[i] != 0) func_0204b174(background, datas[i], self->allocator_, sizes[i]);
        }
        loader->RemoveTask(task);
        self->tasks_[1] = -1;
        func_0204bc74(background, 0, 0, 0, 0x20, 0x19, 0);
        FlushAndDispatchList0204b0e8((List0204b0e8 *) background, 0);
        second = self->backgrounds_;
        func_0204bc74(&second[1], 0, 0, 0, 0x20, 0x19, 0);
        FlushAndDispatchList0204b0e8((List0204b0e8 *) &second[1], 0);
        self->pixels_          = self->allocator_->Allocate(0x2800);
        Canvas0216b07c *canvas = self->canvases_;
        AllocateBuffer0204c7a8((Obj0204c7a8 *) canvas, self->allocator_,
                                                                   (int) self->pixels_, 0x400);
        canvas->background_    = self->backgrounds_;
        canvas->unk_c4         = 0;
        Window0216b07c *window = self->window_;
        window->background_    = self->backgrounds_;
        window->unk_b2         = 2;
        LinkArrayPrevPointers0205cf78((Struct_0205cf78 *) self->window_,
                                                                             (Elem_0205cf78 *) self->canvases_, 1);
        ((BgCnt0216b07c *) 0x4000008)[0].priority_ = 3;
        ((BgCnt0216b07c *) 0x4000008)[1].priority_ = 1;
        ((BgCnt0216b07c *) 0x4000008)[2].priority_ = 2;
        ((BgCnt0216b07c *) 0x4000008)[3].priority_ = 0;
        ColorEffect_ConfigureAlphaBlend(0x4000050, 4, 1, 0xa, 6);
        self->step_ = 1;
    }
    if (self->step_ == 2) {
        int task = self->tasks_[0];
        void *file;
        unsigned int size;
        loader->GetLoadedFileByID(task, &file, &size);
        self->allocators_[0].Reset();
        func_020dfec0((char *) self + 0x1324, &self->allocators_[0], file, size);
        loader->RemoveTask(task);
        self->tasks_[0] = -1;
        self->step_     = 1;
    }
    int done = 1;
    for (int i = 0; i < 3; i++) {
        if (self->tasks_[i] != -1) {
            done = 0;
            break;
        }
    }
    if (done) {
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        self->flags_13ec |= 1;
        void *obj = func_0202ae18();
        if ((CheckField0NonZero((int *) obj) != 0 && func_0202c540(obj) != 0) ||
            *(short *) ((char *) state->GetUnknownGameObject() + 4) != 0)
        {
            self->state_ = 3;
            self->step_  = 0;
        } else if (self->mode_ != 1 && self->mode_ != 2) {
            self->state_ = 2;
            self->step_  = 0;
        } else {
            self->unk_13ea = 1;
            self->state_   = 5;
            self->step_    = 0;
        }
    }
}
