#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "System/ColorEffects.h"
#include "System/Graphics.h"

#if defined(jpn)
enum { kRegionValue998_868 = 0x868 };
enum { kRegionValue9A0_870 = 0x870 };
#else
enum { kRegionValue998_868 = 0x998 };
enum { kRegionValue9A0_870 = 0x9a0 };
#endif

struct BackgroundGraphics {
    char unk_0[0x1c];
    unsigned char unk_1c_0_ : 4;
    unsigned char unk_1c_4_ : 4;
    unsigned char unk_1d;
    char unk_1e[2];
};

struct BackgroundLayer {
    char unk_0[4];
    BackgroundGraphics* graphics;
    char unk_8[0xe0 - 8];
};

struct BackgroundPair {
    unsigned char v[2];
};

struct BackgroundConfig {
    BackgroundPair screen;
    BackgroundPair priority;
};

struct Container020e0310;
struct Obj0204b5e8;
struct AllocTarget0204b12c;
struct Rec020467f0;
struct ActiveEntry02046900;
struct List0204b0e8;
struct Obj0204c7a8;
struct Struct_0205cf78;
struct Elem_0205cf78;
struct QueueStruct0215917c;

int GetGlobalField0x1c020421a0();
extern "C" void func_ov017_021d243c(int a);
extern "C" void func_020dfec0(void* container, SafeAllocator* alloc, void* data, unsigned int size);
const char* GetFieldByKey020e0434(Container020e0310* container, int key);
extern "C" int func_02005a94(const char* string);
extern "C" void func_ov003_02159250(void* self, void* text);
extern "C" void func_ov003_02159464(void* self);
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char* background, int value);
extern "C" void func_0204b5b4(BackgroundGraphics* background, int screen);
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c* background, SafeAllocator* allocator);
void DispatchViaTable0204b5e8(Obj0204b5e8* background, int a, int b);
int CountActiveEntries(ActiveEntry02046900* archive);
void* FindRecordByIndex(Rec020467f0* archive, int index, void** name, int* size);
extern "C" void func_0204b174(BackgroundGraphics* background, void* file, SafeAllocator* allocator, unsigned int size);
extern "C" void func_0204bc74(BackgroundGraphics* background, int a, int b, int c, int d, int e, int f);
void FlushAndDispatchList0204b0e8(List0204b0e8* background, void* a);
void AllocateBuffer0204c7a8(Obj0204c7a8* obj, SafeAllocator* alloc, int val, unsigned int len);
void LinkArrayPrevPointers0205cf78(Struct_0205cf78* s, Elem_0205cf78* arr, unsigned char count);
extern "C" void func_0205a528(void* table, void* file, int size, SafeAllocator* alloc);
int CompareStrings_020d3018(const char* a, const char* b);
void AppendFlagEvents_0215917c(QueueStruct0215917c* obj, int flags);
unsigned char CopyOutRegion0x5718_02011494(char* obj, void* dst);

extern char data_ov003_0217fe2d[];
extern char data_ov003_0217fe48[];
extern char data_ov003_0217fe5a[];
extern const BackgroundConfig data_ov003_0217f380;
extern char data_ov003_0217fe6b[];
extern char data_ov003_0217fe7e[];

struct BattleMessageScene {
    SafeAllocator allocators_[4];
    char unk_50[0x64 - 0x50];
    char strings_[0x7c - 0x64];
    void* text_;
    char unk_80[0x98 - 0x80];
    char table_[0xd4 - 0x98];
    int unk_d4;
    int unk_d8;
    char unk_dc[0xe4 - 0xdc];
    short unk_e4;
    char unk_e6[2];
    unsigned char unk_e8;
    char unk_e9[3];
    int unk_ec;
    int unk_f0;
    char list_[0x18c - 0xf4];
    BackgroundGraphics* graphics_;
    char unk_190[0x1a6 - 0x190];
    unsigned char unk_1a6;
    char unk_1a7[0x1b0 - 0x1a7];
    BackgroundGraphics backgrounds_[2];
    BackgroundLayer layers_[4];
    char unk_570[0x578 - 0x570];
    int task_;
    void* buffer_;
    unsigned char state_;
    char unk_581[0x587 - 0x581];
    unsigned char unk_587;
    unsigned char next_;
    char unk_589[0x590 - 0x589];
    unsigned char memberCount_;
    char members_[0x59d - 0x591];
    unsigned char unk_59d;
    unsigned char unk_59e;
    char unk_59f;
    unsigned char mode_;
    char unk_5a1[0x5b1 - 0x5a1];
    unsigned char unk_5b1;
    unsigned char unk_5b2;
    char unk_5b3;
    unsigned char unk_5b4;
};

// USA: func_ov003_021594c4
extern "C" ARM void func_ov003_021594c4(BattleMessageScene* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int g = GetGlobalField0x1c020421a0();
    unsigned char state = self->state_;

    if (state == 0) {
        self->text_ = *(void**)(GetGlobalField0x1c020421a0() + 0x5c);
        func_ov017_021d243c(1);
        char archive[0x40];
        char file[0x18];
        sprintf(archive, data_ov003_0217fe2d, self->mode_);
        sprintf(file, data_ov003_0217fe48, self->mode_);
        self->task_ = loader->QueueLoadFileInGP2(archive, file, NULL);
        self->state_++;
    }

    if (state == 1) {
        if (loader->GetTaskStatus(self->task_) == 0) return;
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->task_, &data, &size);
        self->allocators_[0].Reset();
        func_020dfec0(self->strings_, &self->allocators_[0], data, size);
        loader->RemoveTask(self->task_);
        self->task_ = -1;
        const char* str = GetFieldByKey020e0434((Container020e0310*)self->strings_, 0x32);
        if (str != NULL) {
            self->unk_5b1 = func_02005a94(str);
        }
        if (self->unk_5b1 == 3) {
            self->unk_5b1 = 0;
            self->unk_5b2 = 0;
        }
        *(int*)(g + kRegionValue998_868) = 1;
        *(unsigned char*)(g + 0x19bf) = 1;
        *(unsigned char*)(g + 0x19cf) = 1;
        func_ov003_02159250(self, self->text_);
        if (self->mode_ == 2 || self->unk_587 == 1 || self->unk_587 == 2) {
            if (self->mode_ == 2) {
                self->unk_5b4 = 1;
                self->state_ = 3;
                self->task_ = loader->QueueLoadFile(data_ov003_0217fe5a, NULL);
                *(int*)(GetGlobalField0x1c020421a0() + kRegionValue998_868) = 1;
            } else {
                self->next_ = 10;
                self->state_ = 0;
            }
            self->unk_59d = 1;
            self->unk_59e = 0;
            func_ov003_02159464(self);
            return;
        }
        BackgroundPair priority = data_ov003_0217f380.priority;
        BackgroundPair screen = data_ov003_0217f380.screen;
        BackgroundGraphics* background;
        for (int i = 0; i < 2; i++) {
            background = &self->backgrounds_[i];
            SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)background, 0);
            background->unk_1c_0_ = 0;
            background->unk_1c_4_ = priority.v[i];
            func_0204b5b4(background, screen.v[i]);
            AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)background, &self->allocators_[1]);
            DispatchViaTable0204b5e8((Obj0204b5e8*)background, 0, 0);
        }
        BG1CNT = (BG1CNT & 0x43) | 0x1d00;
        BG2CNT = (BG2CNT & 0x43) | 0x1e00;
        ColorEffect_ConfigureAlphaBlend(0x4000050, 2, 1, 10, 6);
        self->task_ = loader->QueueLoadFile(data_ov003_0217fe6b, NULL);
        self->state_++;
    }

    if (state == 2) {
        BackgroundLoader* loader2 = BackgroundLoader::GetInstance();
        if (loader2->GetTaskStatus(self->task_) != 0) {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            void* files[2];
            int sizes[2];
            loader2->GetLoadedFileByID(self->task_, &archive, &archiveSize);
            int count = CountActiveEntries((ActiveEntry02046900*)archive);
            for (int i = 0; i < count; i++) {
                files[i] = FindRecordByIndex((Rec020467f0*)archive, i, (void**)name, &sizes[i]);
            }
            for (int i = 0; i < count; i++) {
                if (files[i] != NULL) {
                    func_0204b174(&self->backgrounds_[1], files[i], &self->allocators_[1], sizes[i]);
                }
            }
            loader2->RemoveTask(self->task_);
            self->task_ = -1;
            BackgroundGraphics* background;
            for (int i = 0; i < 2; i++) {
                background = &self->backgrounds_[i];
                func_0204bc74(background, 0, 0, 0, 0x20, 0x19, 0);
                FlushAndDispatchList0204b0e8((List0204b0e8*)background, 0);
            }
            self->allocators_[2].Reset();
            self->buffer_ = self->allocators_[2].Allocate(0x4000);
            for (int i = 0; i < 4; i++) {
                BackgroundLayer* layer = &self->layers_[i];
                AllocateBuffer0204c7a8((Obj0204c7a8*)layer, &self->allocators_[1], (int)self->buffer_, 0x400);
                layer->graphics = &self->backgrounds_[1];
            }
            self->graphics_ = &self->backgrounds_[0];
            self->unk_1a6 = 2;
            LinkArrayPrevPointers0205cf78((Struct_0205cf78*)self->list_, (Elem_0205cf78*)self->layers_, 4);
            self->task_ = loader2->QueueLoadFile(data_ov003_0217fe5a, NULL);
            self->state_++;
        }
    }

    if (state == 3) {
        if (loader->GetTaskStatus(self->task_) != 0) {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            int size;
            self->unk_e8 = 0;
            self->unk_d8 = self->unk_ec;
            self->unk_e4 = 0xe;
            self->unk_d4 = self->unk_f0;
            loader->GetLoadedFileByID(self->task_, &archive, &archiveSize);
            int count = CountActiveEntries((ActiveEntry02046900*)archive);
            self->allocators_[3].Reset();
            for (int i = 0; i < count; i++) {
                void* file = FindRecordByIndex((Rec020467f0*)archive, i, (void**)name, &size);
                func_0205a528(self->table_, file, size, &self->allocators_[3]);
            }
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            if (self->unk_5b4 != 0) {
                self->next_ = 3;
                self->state_ = 0;
                return;
            }
            self->unk_59d = 1;
            self->unk_59e = 0;
            func_ov003_02159464(self);
            self->state_++;
        }
    }

    if (state == 4 && *(int*)(g + kRegionValue9A0_870) == 3) {
        self->unk_59d = 1;
        BG0CNT = (BG0CNT & ~3) | 2;
        BG1CNT = (BG1CNT & ~3) | 1;
        BG2CNT = (BG2CNT & ~3);
        BG3CNT = (BG3CNT & ~3) | 3;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        unsigned char flags = 0x3f;
        for (int i = 0; i < 6; i++) {
            const char* str = GetFieldByKey020e0434((Container020e0310*)self->strings_, (short)i);
            if (CompareStrings_020d3018(data_ov003_0217fe7e, str) == 0) {
                flags &= ~(1 << i);
            }
        }
        AppendFlagEvents_0215917c((QueueStruct0215917c*)self, flags);
        self->memberCount_ = CopyOutRegion0x5718_02011494((char*)GameState::GetInstance(), self->members_);
        self->next_ = 1;
        self->state_ = 1;
    }
}
