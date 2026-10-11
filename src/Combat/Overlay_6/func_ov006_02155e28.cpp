#if defined(jpn)
#define R(j,u) (j)
#define _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii func_02080654
#define data_ov006_0215ff54 data_ov006_021612b8
#define data_ov006_0215ff64 data_ov006_021612c8
#define data_ov006_02160080 data_ov006_021613e0
#define data_ov006_021600af data_ov006_0216140f
#define data_ov006_021600c4 data_ov006_02161424
#define data_ov006_021600d7 data_ov006_02161437
#define data_ov006_021600f7 data_ov006_02161454
#define data_ov006_0216010b data_ov006_02161468
#define data_ov006_02160125 data_ov006_02161482
#define data_ov006_0216013d data_ov006_0216149a
#define data_ov006_02160156 data_ov006_021614b3
#define data_ov006_02160172 data_ov006_021614cf
#define data_ov006_0216018b data_ov006_021614e8
#define data_ov006_02160190 data_ov006_021614ed
#define data_ov006_02160195 data_ov006_021614f2
#define data_ov006_0216019a data_ov006_021614f7
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "World/Object3D.h"
#include "Resource/GameResources.h"

extern "C" void __clear(void* dst, int size);
extern "C" int sprintf(char* dst, const char* fmt, ...);

extern "C" void _Z18InitStruct0205a444Pc(char* obj);
struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* data);
struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* data, int index, void** outRec, int* outSize);
extern "C" void func_0205a528(void* a, void* ptr, int val, void* d);

struct List0204af64 {
    unsigned char pad0[0x1c];
    unsigned char kind : 4;
    unsigned char slot : 4;
    unsigned char pad1d[3];
};
extern "C" void _Z17ResetList0204af64P12List0204af64(struct List0204af64* list);
void SetWord0x18ClearByte0x1f(unsigned char* list, int value);
extern "C" void func_0204b5b4(void* list, int priority);
struct AllocTarget0204b12c;
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(struct AllocTarget0204b12c* list, SafeAllocator* alloc);
struct Obj0204b5e8;
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(struct Obj0204b5e8* list, int a, int b);
struct Obj0204b010;
extern "C" void _Z19ClearBuffer0204b010P11Obj0204b010Pv(struct Obj0204b010* list, void* buffer);
extern "C" void func_0204b174(void* list, void* data, void* alloc, int size);

struct Obj0204c7a8 {
    int field0;
    struct List0204af64* lists;
    unsigned char pad8[0xe0 - 8];
};
extern "C" void func_0204c684(void* node);
extern "C" void _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(struct Obj0204c7a8* node, SafeAllocator* alloc, int a, unsigned int size);

struct Manager0207f7f0 {
    unsigned char pad0[R(0x20,0x2c)];
    struct List0204af64* lists;
    unsigned char pad30[8];
    unsigned char mode;
    unsigned char pad39;
    unsigned char active;
};
struct Node0207f7f0;
extern "C" void func_0207f84c(void* mgr);
struct Obj0207f914;
#if defined(jpn)
extern "C" void _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii(struct Obj0207f914* mgr, int alloc, int nameA);
#else
extern "C" void _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii(struct Obj0207f914* mgr, int alloc, int nameA, int nameB);
#endif
extern "C" int func_0207f9f4(void* mgr);
extern "C" void _Z21InitNodeChain0207f7f0P15Manager0207f7f0P12Node0207f7f0i(struct Manager0207f7f0* mgr, struct Node0207f7f0* nodes, int count);

struct Entry021e20f0 {
    short id;
    unsigned char pad2[0x14];
    unsigned char enabled : 1;
    unsigned char pad17;
};
struct Table021e20f0 {
    unsigned char pad0[8];
    struct Entry021e20f0* entries;
    unsigned char padc[8];
    unsigned short count;
};
extern "C" void _Z20ClearFields_021e20c0Pv(void* table);
extern "C" void func_ov023_021e20f0(void* table, void* alloc, void* data, unsigned int size);

struct Progress02012fe4 {
    unsigned char pad0[0xb3c];
    int chapter;
};
extern "C" void* func_02012fe4(void);
static inline struct Progress02012fe4* GetProgress(void* run) {
    return (struct Progress02012fe4*)((char*)run + R(0x1860,0x1840));
}

char* GetWord0x0(int* gs);
int GetFieldIfFlag4(char* gs);
void SetField0x3b0Value(GameState* gs, int value);
struct Foo0207df50;
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(struct Foo0207df50* p);
extern "C" void _Z25RestorePairTables0207df90Pc(char* obj);
extern "C" void _Z24BackupPairTables0207dfacPc(char* obj);
struct Fields020407b4;
void SetFields0x44(struct Fields020407b4* dst, int a, int b, int c);
struct Target02059f38;
struct Vec3_02059f38;
void CopyVec3ToField0x44(struct Target02059f38* dst, struct Vec3_02059f38* src);
extern "C" void _Z23InitCombatEntry021542f4Pv(void* entry);
struct Obj0215426c;
extern "C" void _Z30ProcessPendingCommands0215426cP11Obj0215426c(struct Obj0215426c* obj);
void SetModelRenderContextRenderCommandHook(ModelRenderContext* context, void (*hook)(RenderCommandHandler*), int a, int b, int c);
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* reg, int planeA, int planeB, int evA, int evB);
struct BattleTask020dbf18 {
    unsigned char pad0[0x10];
    int status;
};
extern "C" void _Z17BeginTask020dbf18P18BattleTask020dbf18iiii(struct BattleTask020dbf18* task, int name, int alloc, int tables, int count);

struct Bytes3_0215ff54 { unsigned char v[3]; };
struct Bytes8_0215ff64 { signed char v[8]; };

extern const char data_ov006_021600af[];
extern struct Bytes3_0215ff54 data_ov006_0215ff54;
extern const char data_ov006_021600c4[];
extern const char data_ov006_021600d7[];
extern const char data_ov006_021600f0[];
extern const char data_ov006_021600f7[];
extern struct Bytes8_0215ff64 data_ov006_0215ff64;
extern const char data_ov006_0216010b[];
extern const char data_ov006_02160125[];
extern const char data_ov006_0216013d[];
extern const char data_ov006_02160156[];
extern const char data_ov006_02160172[];
extern const char data_ov006_02160080[];
extern int data_ov006_02160380[3];
extern int data_ov006_02160380_dup[3];
extern const char data_ov006_0216018b[];
extern const char data_ov006_02160190[];
extern const char data_ov006_02160195[];
extern const char data_ov006_0216019a[];

struct Records0205a444 {
    unsigned char pad0[0x40];
    int owner;
    unsigned char pad44[8];
    short capacity;
    unsigned char pad4e[2];
    unsigned char count;
    unsigned char pad51[3];
};

struct CombatLoader02155e28 {
#if !defined(jpn)
    unsigned char pad0[0x180];
#endif
    SafeAllocator* allocs;
    unsigned char pad184[8];
    SafeAllocator modelAlloc;
    int field1a0;
    int field1a4;
    unsigned char pad1a8[0x20];
    struct Table021e20f0* table;
    struct List0204af64* lists;
    struct Obj0204c7a8* nodes;
    struct Manager0207f7f0* mgr;
    unsigned char pad1d8[8];
    int field1e0;
    struct Records0205a444 records;
    Object3D objs[5];
    unsigned char pad594[0x5cc - 0x594];
    unsigned char entry[0xad4 - 0x5cc];
    int taskId;
    int taskB;
    unsigned char result;
    unsigned char state;
    unsigned char padade[4];
    unsigned short flags;
    unsigned char padae4[R(0x121c,0x12a0) - 0xae4];
    struct BattleTask020dbf18 task;
};

static inline SafeAllocator* GetAllocator(GameResources* res, int index) {
    return &res->allocator_array_38[index];
}

// USA: func_ov006_02155e28
extern "C" ARM void func_ov006_02155e28(struct CombatLoader02155e28* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned char state = self->state;

    if (state == 0) {
        _Z18InitStruct0205a444Pc((char*)&self->records);
        self->records.count = 0;
        self->records.owner = self->field1e0;
        self->records.capacity = 0x11;
        self->taskId = loader->QueueLoadFile(data_ov006_021600af, NULL);
        self->state++;
    } else if (state == 1) {
        if (loader->GetTaskStatus(self->taskId) == 0) return;
        void* rec;
        void* data;
        unsigned int size;
        int recSize;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        int count = CountActiveEntries((struct ActiveEntry02046900*)data);
        SafeAllocator* alloc = self->allocs;
        alloc->Reset();
        for (int i = 0; i < count; i++) {
            void* found = FindRecordByIndex((struct Rec020467f0*)data, i, &rec, &recSize);
            if (found != NULL) {
                func_0205a528(&self->records, found, recSize, alloc);
            }
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
    } else if (state == 2) {
        volatile unsigned short* bg = (volatile unsigned short*)0x400000a;
        bg[0] = (bg[0] & 0x43) | 0x1d00;
        bg[1] = (bg[1] & 0x43) | 0x1e00;
        bg[2] = (bg[2] & 0x43) | 0x1f08;
        SafeAllocator* alloc = &self->allocs[2];
        alloc->Reset();
        struct Bytes3_0215ff54 priority = data_ov006_0215ff54;
        for (unsigned char i = 0; i < 2; i++) {
            struct List0204af64* list = &self->lists[i];
            _Z17ResetList0204af64P12List0204af64(list);
            list->kind = 0;
            list->slot = i + 1;
            SetWord0x18ClearByte0x1f((unsigned char*)list, 0);
            func_0204b5b4(list, priority.v[i]);
            _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator((struct AllocTarget0204b12c*)list, alloc);
            _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii((struct Obj0204b5e8*)list, 0, 0);
        }
        _Z19ClearBuffer0204b010P11Obj0204b010Pv((struct Obj0204b010*)&self->lists[0], NULL);
        _Z19ClearBuffer0204b010P11Obj0204b010Pv((struct Obj0204b010*)&self->lists[1], NULL);
        SafeAllocator* nodeAlloc = self->allocs;
        nodeAlloc[3].Reset();
        for (unsigned char j = 0; j < 1; j++) {
            struct Obj0204c7a8* node = &self->nodes[j];
            func_0204c684(node);
            _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(node, &nodeAlloc[3], self->field1a4, 0x1c0);
            node->lists = self->lists;
        }
        self->taskId = loader->QueueLoadFile(data_ov006_021600c4, NULL);
        self->state++;
    } else if (state == 3) {
        if (loader->GetTaskStatus(self->taskId) == 0) return;
        void* rec;
        void* data;
        unsigned int size;
        int recSize;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        int count = CountActiveEntries((struct ActiveEntry02046900*)data);
        SafeAllocator* alloc = self->allocs;
        for (int i = 0; i < count; i++) {
            void* found = FindRecordByIndex((struct Rec020467f0*)data, i, &rec, &recSize);
            if (found != NULL) {
                func_0204b174(self->lists, found, &alloc[2], recSize);
            }
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
        self->flags |= 1;
    } else if (state == 4) {
        volatile unsigned short* bg = (volatile unsigned short*)0x4000008;
        bg[0] = (bg[0] & ~3) | 2;
        bg[1] = (bg[1] & ~3) | 0;
        bg[2] = (bg[2] & ~3) | 1;
        bg[3] = (bg[3] & ~3) | 3;
        SafeAllocator* alloc = self->allocs;
        alloc[4].Reset();
        func_0207f84c(self->mgr);
        _Z35SetFieldsFromFormattedValue0207f914P11Obj0207f914iii((struct Obj0207f914*)self->mgr, (int)&alloc[4],
#if defined(jpn)
                                            (int)data_ov006_021600d7);
#else
                                            (int)data_ov006_021600d7, (int)data_ov006_021600f0);
#endif
        self->state++;
    } else if (state == 5) {
        int r = func_0207f9f4(self->mgr);
        if (r == 0) {
            self->state++;
        }
        if (r < 0) {
            self->result = 2;
        }
    } else if (state == 6) {
        self->taskId = loader->QueueLoadFile(data_ov006_021600f7, NULL);
        self->state++;
    } else if (state == 7) {
        if (loader->GetTaskStatus(self->taskId) == 0) return;
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        if (data != NULL) {
            SafeAllocator* alloc = self->allocs;
            alloc[1].Reset();
            _Z20ClearFields_021e20c0Pv(self->table);
            func_ov023_021e20f0(self->table, &alloc[1], data, size);
            struct Entry021e20f0* entry;
            struct Entry021e20f0* arr = self->table->entries;
            if (arr == NULL) {
                entry = NULL;
            } else {
                unsigned short entryCount = self->table->count;
                if (entryCount == 0) {
                    entry = NULL;
                } else {
                    for (unsigned short k = 0; k < entryCount; k++) {
                        entry = &arr[(unsigned int)k];
                        if (entry->id == 1) {
                            goto found;
                        }
                    }
                    entry = NULL;
                }
            }
        found:
            if (entry != NULL) {
                entry->enabled = 0;
            }
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
        if (self->flags & 8) {
            self->state = 0x12;
        }
    } else if (state == 8) {
        int chapter = (signed char)GetProgress(func_02012fe4())->chapter;
        char path[0x20];
        __clear(path, 0x20);
        if (chapter < 1) {
            chapter = 1;
        }
        if (chapter > 6) {
            chapter = 6;
        }
        struct Bytes8_0215ff64 stages = data_ov006_0215ff64;
        sprintf(path, data_ov006_0216010b, stages.v[chapter]);
        self->taskId = loader->QueueLoadFile(path, NULL);
        self->state++;
    } else if (state == 9) {
        if (loader->GetTaskStatus(self->taskId) == 0) return;
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        if (data != NULL) {
            GameResources* res = (GameResources*)GetWord0x0((int*)GameState::GetInstance());
            SafeAllocator* alloc = GetAllocator(res, 0);
            alloc->Reset();
            _Z26CopyInternalFields0207df50P11Foo0207df50((struct Foo0207df50*)res->unknown_2cc);
            _Z25RestorePairTables0207df90Pc(res->unknown_2cc);
            ObjectArchiveLoadInfo info;
            info.fileData = data;
            info.unk_8 = size;
            info.allocator = alloc;
            info.unk_10 = 1;
            self->objs[0].LoadFromCHRArchive(&info);
            self->objs[0].MaybeSetBCFGAnimation(0, 0);
            _Z24BackupPairTables0207dfacPc(res->unknown_2cc);
            SetFields0x44((struct Fields020407b4*)&self->objs[0], -0x3800, -0xb3b, 0x60a3);
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
    } else if (state == 10) {
        self->taskId = loader->QueueLoadFile(data_ov006_02160125, NULL);
        self->state++;
    } else if (state == 11) {
        if (loader->GetTaskStatus(self->taskId) == 0) return;
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        if (data != NULL) {
            GameResources* res = (GameResources*)GetWord0x0((int*)GameState::GetInstance());
            SafeAllocator* alloc = GetAllocator(res, 0);
            _Z25RestorePairTables0207df90Pc(res->unknown_2cc);
            ObjectArchiveLoadInfo info;
            info.fileData = data;
            info.unk_8 = size;
            info.allocator = alloc;
            info.unk_10 = 1;
            self->objs[1].LoadFromCCHROrCMOTArchive(&info, NULL);
            self->objs[1].MaybeSetBCFGAnimation(0, 0);
            _Z24BackupPairTables0207dfacPc(res->unknown_2cc);
            self->objs[1].SetScale(0x10a, 0x10a, 0x10a);
            SetFields0x44((struct Fields020407b4*)&self->objs[1], -0x41, -0xaac, 0x61f3);
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
    } else if (state == 12) {
        self->taskId = loader->QueueLoadFile(data_ov006_0216013d, NULL);
        self->state++;
    } else if (state == 13) {
        if (loader->GetTaskStatus(self->taskId) == 0) return;
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        if (data != NULL) {
            GameResources* res = (GameResources*)GetWord0x0((int*)GameState::GetInstance());
            SafeAllocator* alloc = GetAllocator(res, 0);
            _Z25RestorePairTables0207df90Pc(res->unknown_2cc);
            ObjectArchiveLoadInfo info;
            info.fileData = data;
            info.unk_8 = size;
            info.allocator = alloc;
            info.unk_10 = 1;
            self->objs[2].LoadFromCCHROrCMOTArchive(&info, NULL);
            self->objs[2].MaybeSetBCFGAnimation(0, 0);
            _Z24BackupPairTables0207dfacPc(res->unknown_2cc);
            self->objs[2].SetScale(0x10a, 0x10a, 0x10a);
            CopyVec3ToField0x44((struct Target02059f38*)&self->objs[2], (struct Vec3_02059f38*)&self->objs[1].position_);
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
    } else if (state == 14) {
        self->taskId = loader->QueueLoadFile(data_ov006_02160156, NULL);
        self->state++;
    } else if (state == 15) {
        if (loader->GetTaskStatus(self->taskId) == 0) return;
        GameResources* res = func_ov017_0218b5b0();
        self->modelAlloc.CreateTypeA(res->allocator_array_38[0].Allocate(0x8000), 0x8000);
        self->modelAlloc.Reset();
        _Z25RestorePairTables0207df90Pc(res->unknown_2cc);
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        if (data != NULL && self->modelAlloc.GetSignedAllocator() != NULL) {
            self->objs[3].Initialize();
            ObjectArchiveLoadInfo info;
            info.fileData = data;
            info.unk_8 = size;
            info.allocator = &self->modelAlloc;
            info.unk_10 = 1;
            self->objs[3].LoadFromCHRArchive(&info);
            self->objs[3].SetScale(&self->objs[1].GetScale());
            CopyVec3ToField0x44((struct Target02059f38*)&self->objs[3], (struct Vec3_02059f38*)&self->objs[1].position_);
            self->objs[3].StopCurrentAnimation();
        }
        _Z24BackupPairTables0207dfacPc(res->unknown_2cc);
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
    } else if (state == 16) {
        self->taskId = loader->QueueLoadFile(data_ov006_02160172, NULL);
        self->state++;
    } else if (state == 17) {
        if (loader->GetTaskStatus(self->taskId) == 0) return;
        void* data;
        unsigned int size;
        loader->GetLoadedFileByID(self->taskId, &data, &size);
        if (data != NULL) {
            GameResources* res = (GameResources*)GetWord0x0((int*)GameState::GetInstance());
            SafeAllocator* alloc = GetAllocator(res, 0);
            _Z25RestorePairTables0207df90Pc(res->unknown_2cc);
            ObjectArchiveLoadInfo info;
            info.fileData = data;
            info.unk_8 = size;
            info.allocator = alloc;
            info.unk_10 = 1;
            Object3D* obj = &self->objs[4];
            obj->LoadFromCCHROrCMOTArchive(&info, NULL);
            obj->MaybeSetBCFGAnimation(0, 0);
            _Z24BackupPairTables0207dfacPc(res->unknown_2cc);
            obj->SetScale(0x10a, 0x10a, 0x10a);
            CopyVec3ToField0x44((struct Target02059f38*)obj, (struct Vec3_02059f38*)&self->objs[1].position_);
            obj->StopCurrentAnimation();
            obj->MaybeSetRegularAnimation(data_ov006_02160080, 9);
            obj->DisableFlag(0x1000);
            for (int i = 0; i < 3; i++) {
                data_ov006_02160380[i] = -1;
            }
            Model3D* model = self->objs[4].pModel_;
            if (model != NULL) {
                data_ov006_02160380_dup[0] = model->GetBoneIndex(data_ov006_0216018b);
                data_ov006_02160380_dup[1] = model->GetBoneIndex(data_ov006_02160190);
                data_ov006_02160380_dup[2] = model->GetBoneIndex(data_ov006_02160195);
                ModelRenderContext* context;
                if (!model->unknown_flags_a8_0_) {
                    context = NULL;
                } else {
                    context = &model->renderContext_;
                }
                if (context != NULL) {
                    SetModelRenderContextRenderCommandHook(context, (void (*)(RenderCommandHandler*))_Z30ProcessPendingCommands0215426cP11Obj0215426c, 0, 6, 3);
                }
            }
        }
        loader->RemoveTask(self->taskId);
        self->taskId = -1;
        self->state++;
    } else if (state == 18) {
        self->objs[1].StopCurrentAnimation();
        self->objs[2].StopCurrentAnimation();
        self->objs[1].MaybeSetBCFGAnimation(0, 0);
        self->objs[2].MaybeSetBCFGAnimation(0, 0);
        GameState* gs = GameState::GetInstance();
        self->field1a0 = GetFieldIfFlag4((char*)gs);
        _Z23InitCombatEntry021542f4Pv(self->entry);
        SetField0x3b0Value(gs, (int)self->entry);
        struct Manager0207f7f0* mgr = self->mgr;
        mgr->lists = self->lists;
        mgr->mode = 2;
        _Z21InitNodeChain0207f7f0P15Manager0207f7f0P12Node0207f7f0i(self->mgr, (struct Node0207f7f0*)self->nodes, 1);
        self->mgr->active = 1;
        volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
        *dispcnt = (*dispcnt & ~0x1f00) | 0x1f00;
        ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 4, 1, 10, 6);
        self->flags = self->flags | 0x1000;
        self->flags = self->flags & ~0x40;
        GameResources* res = (GameResources*)GetWord0x0((int*)gs);
        _Z17BeginTask020dbf18P18BattleTask020dbf18iiii(&self->task, (int)data_ov006_0216019a, (int)&self->allocs[5],
                          (int)res->unknown_2cc, 0x18);
        self->state++;
    } else if (state == 19) {
        if (self->task.status == 2) {
            self->result = 1;
            self->state = 0;
        }
    }
}
