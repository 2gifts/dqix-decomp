#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

struct GameResources;
struct ActiveEntry02046900;
struct Rec020467f0;
struct List0204af64;
struct Obj0204b5e8;
struct SelfTag0204b3a0;
struct Zone02172a14;

extern "C" void *func_ov017_0218b5b0(void);
int CountActiveEntries(ActiveEntry02046900 *archive);
void *FindRecordByIndex(Rec020467f0 *archive, int index, void **name, int *size);
extern "C" void func_0205a528(void *renderer, void *file, unsigned int size, void *allocator);
extern "C" void func_0204c684(void *canvas);
extern "C" Zone02172a14 *func_02012fe4(void);
extern "C" void __clear(void *dst, int count);
extern "C" void func_0204f41c(void *canvas, int a, int b, char *text, int c, int d, short *outA, short *outB, int e);
void ResetList0204af64(List0204af64 *obj);
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char *obj, int a);
void DispatchViaTable0204b5e8(Obj0204b5e8 *obj, int a, int b);
void DispatchByTag0204b2e0(void *obj, char *str);
void DispatchByTagLookup0204b3a0(SelfTag0204b3a0 *self, char *str);
extern "C" void ColorEffect_ConfigureAlphaBlend(int control, int a, int b, int c, int d);
void SetMainBrightness(GameResources *resources, int a, int b);
extern "C" void func_020728ac(void *a, void *b, void *file, unsigned int size, int c, int d, int e);

extern char data_ov003_021809b0[];
extern char data_ov003_021809c4[];
extern char data_ov003_021809d4[];
extern char data_ov003_021809e6[];
extern char data_ov003_021809f4[];
extern char data_ov003_021809f8[];
extern char data_ov003_02180a0d[];
extern char data_ov003_02180a1e[];
extern char data_ov003_02180a38[];

struct Progress02172a14 {
    unsigned char pad0[0xb34];
    int value_;
};

struct Zone02172a14 {
    unsigned char pad0[0x1840];
    Progress02172a14 progress_;
};

static inline Progress02172a14 *GetProgress(Zone02172a14 *zone) { return &zone->progress_; }
static inline int GetValue(Progress02172a14 *progress) { return progress->value_; }

struct List02172a14 {
    unsigned char pad0[0x1c];
    unsigned char lo_ : 4;
    unsigned char hi_ : 4;
    unsigned char pad1d[3];
};

struct Canvas02172a14 {
    void *unk_0;
    void *background_;
    void *pixels_;
    char unk_c[0xa8 - 0xc];
    short width_;
    short height_;
    char unk_ac[0xb4 - 0xac];
    short unk_b4;
    short unk_b6;
    char unk_b8[0xe0 - 0xb8];
};

struct Self02172a14 {
    char pad0_[0xec];
    unsigned char unk_ec;
    char pad_ed;
    unsigned char step_;
    char pad_ef;
    int task_;
    char pad_f4[0x128 - 0xf4];
    int w128_;
    int w12c_;
    char pad_130[0x16c - 0x130];
    int w16c_;
    int w170_;
    char pad_174[0x17c - 0x174];
    short h17c_;
    char pad_17e[2];
    unsigned char b180_;
    char pad_181[0x1d8 + 8 - 0x181];
};

// USA: func_ov003_02172a14
extern "C" ARM void func_ov003_02172a14(Self02172a14 *self) {
    GameResources *res       = (GameResources *) func_ov017_0218b5b0();
    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    FontBankLoader* global = GetGlobal02109400_02094a00();
    if (self->step_ == 0) {
        self->b180_ = 0;
        self->w170_ = self->w128_;
        self->h17c_ = 0xd;
        self->w16c_ = self->w12c_;
        self->task_ = loader->QueueLoadFileInGP2(data_ov003_021809b0, data_ov003_021809c4, 0);
        self->step_ = 1;
    }
    if (self->step_ == 1) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        void *name;
        void *file;
        unsigned int size;
        int fileSize;
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int count = CountActiveEntries((ActiveEntry02046900 *) file);
        for (int i = 0; i < count; i++) {
            void *data = FindRecordByIndex((Rec020467f0 *) file, i, &name, &fileSize);
            func_0205a528((char *) self + 0x130, data, fileSize, (char *) self + 0x1ac);
        }
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        self->task_ = loader->QueueLoadFileInGP2(data_ov003_021809d4, data_ov003_021809e6, 0);
        self->step_ = 2;
    }
    if (self->step_ == 2) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        void *name;
        void *file;
        unsigned int size;
        void *datas[3];
        int sizes[3];
        Canvas02172a14 canvas;
        char text[0x40];
        List02172a14 list;
        short outA;
        short outB;
        loader->GetLoadedFileByID(self->task_, &file, &size);
        int count = CountActiveEntries((ActiveEntry02046900 *) file);
        for (int i = 0; i < count; i++) {
            datas[i] = FindRecordByIndex((Rec020467f0 *) file, i, &name, &sizes[i]);
        }
        func_0204c684(&canvas);
        canvas.pixels_ = (char *) datas[0] + 0x10;
        canvas.width_  = 0x20;
        canvas.height_ = 0x18;
        canvas.unk_b4  = 8;
        canvas.unk_b6  = 8;
        Zone02172a14 *zone = func_02012fe4();
        __clear(text, 0x40);
        int v = GetValue(GetProgress(zone));
        if (v > 9999) v = 9999;
        sprintf(text, data_ov003_021809f4, v);
        func_0204f41c(&canvas, 0xb0, 0x48, text, 8, 1, &outA, &outB, 0);
        ResetList0204af64((List0204af64 *) &list);
        list.lo_ = 0;
        list.hi_ = 1;
        SetWord0x18ClearByte0x1f_0204b11c((unsigned char *) &list, 0);
        DispatchViaTable0204b5e8((Obj0204b5e8 *) &list, 0, 0);
        for (int i = 0; i < count; i++) {
            DispatchByTag0204b2e0(&list, (char *) datas[i]);
            DispatchByTagLookup0204b3a0((SelfTag0204b3a0 *) &list, (char *) datas[i]);
        }
        ColorEffect_ConfigureAlphaBlend(0x04000050, 1, 0x12, 0x1f, 0x1f);
        SetMainBrightness(res, 0, 0x18);
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        self->task_ = loader->QueueLoadFileInGP2(data_ov003_021809f8, data_ov003_02180a0d, 0);
        self->step_ = 3;
    }
    if (self->step_ == 3) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        void *file;
        unsigned int size;
        loader->GetLoadedFileByID(self->task_, &file, &size);
        func_020728ac((char *) self + 0x1d0, (char *) self + 0x184, file, size, 0, 0, 0);
        loader->RemoveTask(self->task_);
        self->task_ = loader->QueueLoadFileInGP2(data_ov003_02180a1e, data_ov003_02180a38, 0);
        self->step_ = 4;
    }
    if (self->step_ == 4) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        void *file;
        unsigned int size;
        loader->GetLoadedFileByID(self->task_, &file, &size);
        func_020728ac((char *) self + 0x1d8, (char *) self + 0x198, file, size, 0, 0, 0);
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        self->step_ = 5;
    }
    if (self->step_ == 5) {
        BlankFunction02094b30(global, 0x1ff, 0);
        if (AlwaysTrue02094b4c(global) != 0) {
            self->unk_ec = 2;
            self->step_  = 0;
        }
    }
}
