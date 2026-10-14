#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#if defined(jpn)
#define REGION_VALUE(j,u) j
#define data_ov008_0218b3e4 data_ov008_0218c064
#define data_ov008_0218b400 data_ov008_0218c080
#define data_ov008_0218b41d data_ov008_0218c09d
#define data_ov008_0218b328 data_ov008_0218bf60
#define data_ov008_0218b334 data_ov008_0218bf6c
#define data_ov008_0218b31c data_ov008_0218bf78
#define data_ov008_0218b3e0 data_ov008_0218c060
#define data_ov008_0218b48f data_ov008_0218c0f0
#define func_ov008_02188d74 func_ov008_02189a9c
#define func_ov008_0218712c func_ov008_02188008
#define func_ov008_02187f6c func_ov008_02188ccc
#else
#define REGION_VALUE(j,u) u
#endif

#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" int sprintf(char* buffer, const char* format, ...);
extern "C" void* __clear(void* dst, int count);

extern const char data_ov008_0218b3e4[];
extern const char data_ov008_0218b400[];
extern const char data_ov008_0218b41d[];
extern const char data_ov008_0218b43c[];
extern const char data_ov008_0218b455[];
extern const char data_ov008_0218b3e0[];
extern const char data_ov008_0218b465[];
extern const char data_ov008_0218b47c[];
extern const char data_ov008_0218b48f[];
extern char data_0211e33c[];
extern int data_02109bf4;

struct Vec3i02184a4c { int x; int y; int z; };
extern const Vec3i02184a4c data_ov008_0218b328;
extern const Vec3i02184a4c data_ov008_0218b334;
extern const Vec3i02184a4c data_ov008_0218b31c;

int StringLength(const char* s);

struct List02184a4c {
    void* entries;
    short capacity;
    short count;
};

struct Ov17Data02184a4c {
    char pad0[REGION_VALUE(0x27c, 0x2cc)];
    char stage[0x87c - REGION_VALUE(0x27c, 0x2cc)];
};

struct BattleTail02184a4c {
    char pad0[0x10];
    unsigned int lo : 23;
    unsigned int scriptId : 9;
    char pad14[0xc];
    unsigned int GetScriptId() { return scriptId; }
};
struct BattleBlock02184a4c {
    char pad0[0x90];
    BattleTail02184a4c tail;
    BattleTail02184a4c* GetTail() { return &tail; }
};

static inline char* GetSection104(GameState* gs) { return (char*)gs + REGION_VALUE(0x2c4, 0x104); }
static inline char* GetSection7400(char* section) { return section + REGION_VALUE(0x7000, 0x7400); }
static inline BattleBlock02184a4c* GetBattleBlock(GameState* gs) {
    return (BattleBlock02184a4c*)(GetSection7400(GetSection104(gs)) + 0x3c);
}

struct Poller02184a4c {
    char pad0[0x68];
    short count;
    short ids[1];
};

struct MessageSrc02184a4c {
    unsigned int word0;
    const char* text;
    int f8;
};
struct Message02184a4c {
    unsigned int a : 9;
    unsigned int b : 9;
    unsigned int c : 9;
    unsigned int d : 3;
    unsigned int e : 2;
    char* text;
    int f8;
    char name[0x38];
    char buf[REGION_VALUE(0x118, 0x200)];

};

struct Entry0205a198 { char pad0[0x28]; };

struct Table0205a44402184a4c {
    char pad0[0x3c];
    void* tail;
    struct Entry0205a198* entries;
    char pad44[0x4c - 0x44];
    short entryCount;
    char pad4e[2];
    unsigned char f50;
    void SetEntries(struct Entry0205a198* list, int count) {
        entries = list;
        entryCount = count;
    }
};

struct Elem0205d81c02184a4c {
    char pad0[0xc2];
    short fc2;
};

struct Stat02184a4c {
    char pad0[0x49c];
    unsigned char bit0 : 1;
    unsigned char hi : 7;
};
struct Member02184a4c {
    char pad0[REGION_VALUE(0x144, 0x150)];
    Stat02184a4c* stat;
    int GetBit0() { return stat->bit0; }
};

struct Model02184a4c {
    char pad0[0x44];
    Vec3i02184a4c pos;
    void SetPosition(const Vec3i02184a4c* v) { *(Vector3i*)&pos = *(Vector3i const*)v; }
};

struct Obj02184a4c {
    SafeAllocator alloc00;
#if defined(jpn)
    SafeAllocator alloc14;
#else
    char pad14[0x28 - 0x14];
#endif
    SafeAllocator alloc28;
    SafeAllocator alloc3c;
    char pad50[0x64 - 0x50];
    SafeAllocator alloc64;
    SafeAllocator alloc78;
    char scriptArg8c[0xa0 - 0x8c];
    char container[0xb8 - 0xa0];
    char* pathBuf;
    char script[0xd0 - 0xbc];
    char list[0xec - 0xd0];
    unsigned char ecLo : 4;
    unsigned char ecHi : 4;
    char pad_ed[0x130 - 0xed];
    char elems[0x730 - 0x130];
    Table0205a44402184a4c* table;
    Entry0205a198* entries;
    void* tail;
    char pad73c[0x790 - 0x73c];
    Model02184a4c model;
    Vec3i02184a4c modelRot;
    char pad7ec[0x83c - 0x7ec];
    char controller[0xb04 - 0x83c];
    Poller02184a4c* poller;
    int b08;
    Message02184a4c* message;
    unsigned char b10;
    unsigned char b11;
    char pad_b12[2];
    short b14;
    short b16;
    unsigned int flags;
    int b1c;
    int taskId;
    int b24;

    Model02184a4c* GetModel() { return &model; }
    Entry0205a198* GetEntries() { return entries; }
    Table0205a44402184a4c* GetTable() { return table; }
    int HasFlag(unsigned int mask) volatile { return (flags & mask) != 0; }
};

extern "C" void* func_0202ae18(void);
extern "C" char* func_0205ec34(void);
extern "C" int _Z18TestBitInByteArrayiPhi(char* unused, char* arr, int index);
int LoadBattleBlock020ac4c0(void* dst);
extern "C" int func_0202c508(void* obj);
extern "C" int func_0202c540(void* obj);
struct List020727d8;
void ResetListHeader020727d8(List020727d8*);
void SubmitScriptFromFile020727f8(void* list, const char* path, int id, void* out, unsigned char mode);
void Reset0209fe9c(char*);
struct Obj0209fee4;
void InitManagerAndAllocateBuffers0209fee4(Obj0209fee4*, SafeAllocator*, int, int);
struct IntField0x60_0209ff64;
void SetIntAt0x60(IntField0x60_0209ff64*, int);
struct TaskState0209ff6c;
void PollOv017Task0209ff6c(TaskState0209ff6c*);
extern "C" int func_ov008_02185964(void* obj);
extern "C" void* ExtractFileFromGP2(const char* gp2, const char* inner, unsigned int* outSize);
extern "C" void func_020dfec0(void* container, SafeAllocator* alloc, void* data, unsigned int size);
void SetWord0x18ClearByte0x1f(unsigned char*, int);
extern "C" void func_0204b5b4(void* obj, int a);
struct Obj0204b5e8;
void DispatchViaTable0204b5e8(Obj0204b5e8*, int, int);
struct AllocTarget0204b12c;
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c*, SafeAllocator*);
struct Foo0204af38;
void AllocateArray0204af38(Foo0204af38*, int, SafeAllocator*);
struct Container020e0310;
const char* GetFieldByKey020e0434(Container020e0310*, int);
struct ActiveEntry02046900;
int CountActiveEntries(ActiveEntry02046900*);
struct Rec020467f0;
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
extern "C" void func_0204b174(void* obj, void* rec, SafeAllocator* alloc, int size);
struct Obj0204b8d0;
void DispatchEntry0204b8d0(Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
struct List0204b0e8;
void FlushAndDispatchList0204b0e8(List0204b0e8*, void*);
extern "C" int func_ov008_02188a54(Obj02184a4c* obj, int a);
void InitStruct0205a444(char*);
struct Struct0205a198;
void Init0205a198(Struct0205a198*);
struct ClearTarget0205a234;
void ClearField0And40205a234(ClearTarget0205a234*);
extern "C" int func_0205a528(void* obj, void* data, int size, SafeAllocator* alloc);
extern "C" int func_ov008_02188d74(Obj02184a4c* obj);
struct Foo0207df50;
void CopyInternalFields0207df50(Foo0207df50*);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);
int LoadFileIntoMemory(const char* path, void* dst, unsigned int* outSize);
extern "C" int _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void* obj, void* info, void* callback);
struct Vector3i;
void InitCombatController020a2010(void* obj);
struct Vec3Target0202e5c0;
void SetVec3At0x4(Vec3Target0202e5c0*, int, int, int);
void SetFields0x10To0x18(unsigned char*, int, int, int);
void SetField0x238False(void* obj);
void SetField0x3b0Value(GameState*, int);
struct S020a13c4;
void ClearStruct020a13c4(S020a13c4*);
void SetupGlobalAndRunScript020a13e4(void* a, void* b, int c, unsigned short d, unsigned char e);
extern "C" int func_ov023_021ed724(void* obj, short* ids, int count);
struct Array020a15bc;
MessageSrc02184a4c* FindElementByField020a15bc(Array020a15bc*, int);
extern "C" void func_020e046c(char* buf, void* b, unsigned int c, int idx);
int GetField5cbcValue(char*);
int CompareStrings(const char* a, const char* b);
int CheckField0NonZero(int*);
extern "C" void func_ov008_0218712c(Obj02184a4c* obj, int a);
struct Manager02187664;
void InitConfig02187664(Manager02187664*, int);
extern "C" void func_ov008_02187a70(Obj02184a4c* obj, int a);
extern "C" void func_ov008_02187f6c(Obj02184a4c* obj, int a);
struct Struct_0205d81c;
Elem0205d81c02184a4c* FindElementByC40205d81c(Struct_0205d81c*, int);
char* GetGlobalField0x1c020421a0(void);
extern "C" void func_020432c4(char* obj);
struct Actor0209c3b4;
void SetStateAndDispatch0209c3b4(Actor0209c3b4*, int);
extern "C" void func_ov008_02186964(Obj02184a4c* obj);

struct ArchiveInfo02184a4c {
    int unk_0;
    const void* fileData;
    int size;
    SafeAllocator* allocator;
    int unk_10;
    int unk_14;
    int unk_18;
    int packageID;
};

#if defined(jpn)
extern const char data_ov008_0218c0bc[];
extern const char data_ov008_0218c0d5[];
extern "C" void func_020e2168(char*, const char*, int, int, int);
#endif

// USA: func_ov008_02184a4c
extern "C" ARM void func_ov008_02184a4c(Obj02184a4c* obj) {
#if defined(jpn)
    Ov17Data02184a4c* ov17;
    GameState* gs = GameState::GetInstance();
    ov17 = (Ov17Data02184a4c*)func_ov017_0218b5b0();
#else
    GameState* gs = GameState::GetInstance();
    Ov17Data02184a4c* ov17 = (Ov17Data02184a4c*)func_ov017_0218b5b0();
#endif
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* scene = func_0202ae18();

    unsigned char state = obj->b11;
    if (state == 0) {
        obj->flags |= 0x200000;
        char* save = func_0205ec34();
        int seen = _Z18TestBitInByteArrayiPhi(save, save + 0x8c, 0x113b);
        if (seen != 0) {
            obj->flags |= 0x80;
            obj->flags &= ~1;
        }
        BattleBlock02184a4c block;
        LoadBattleBlock020ac4c0(&block);
        BattleBlock02184a4c* pb = &block;
        unsigned int scriptId = pb->GetTail()->GetScriptId();
        if (scriptId == 0) {
            if (_Z18TestBitInByteArrayiPhi(save, save + 0x8c, 0x796) != 0) {
                if (func_0202c508(scene) != 0) {
                    obj->flags |= 2;
                }
            }
        } else if (scriptId != 0) {
            obj->flags |= 4;
        }
        if (!obj->HasFlag(1)) {
            if (seen == 0) {
                obj->flags |= 0x20000;
            }
            obj->b11 = 2;
            if (obj->b24 == 1) {
                obj->b11 = 3;
            }
        } else {
            if (obj->HasFlag(2)) {
                obj->taskId = loader->QueueLoadFile(data_ov008_0218b3e4, NULL);
            } else {
                char path[0x80];
                __clear(path, 0x80);
                List02184a4c list;
                ResetListHeader020727d8((List020727d8*)&list);
                SubmitScriptFromFile020727f8(&list, data_ov008_0218b400, 1000, path, REGION_VALUE(1, 2));
                obj->taskId = loader->QueueLoadFile(path, NULL);
                obj->flags |= 0x400;
            }
            obj->b11++;
        }
    } else if (state == 1) {
        if (loader->GetTaskStatus(obj->taskId) != 0) {
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(obj->taskId, &data, &size);
            obj->alloc78.Reset();
            obj->poller = (Poller02184a4c*)obj->alloc78.Allocate(0xd0);
            Reset0209fe9c((char*)obj->poller);
            InitManagerAndAllocateBuffers0209fee4((Obj0209fee4*)obj->poller, &obj->alloc78, (int)data, size);
            SetIntAt0x60((IntField0x60_0209ff64*)obj->poller, 100);
            do {
                PollOv017Task0209ff6c((TaskState0209ff6c*)obj->poller);
            } while (func_ov008_02185964(obj->poller) == 0);
            loader->RemoveTask(obj->taskId);
            obj->taskId = -1;
            obj->b11++;
        }
    } else if (state == 2) {
        if (obj->HasFlag(0x400)) {
            if (obj->poller->count > 0) {
                obj->b14 = obj->poller->ids[0];
                obj->b16 = 1000;
                obj->alloc78.Reset();
                obj->poller = NULL;
                obj->flags &= ~1;
                obj->flags &= ~0x400;
            } else {
                obj->alloc78.Reset();
                obj->poller = NULL;
                obj->flags &= ~0x400;
                obj->taskId = loader->QueueLoadFile(data_ov008_0218b41d, NULL);
                obj->b11 = 1;
                return;
            }
        }
        FontBankLoader* global = GetGlobal02109400();
        BlankFunction02094b40(global);
        BlankFunction02094b34(global, 0x6b, 0x1fc, 0, 0);
        obj->b11++;
    } else if (state == 3) {
        if (AlwaysTrue02094b4c(GetGlobal02109400()) != 0) {
#if defined(jpn)
            obj->alloc14.Reset();
            void* data = obj->alloc14.Allocate(0x2000);
            unsigned int size;
            LoadFileIntoMemory(data_ov008_0218c0bc, data, &size);
            obj->alloc28.Reset();
            func_020dfec0(obj->container, &obj->alloc28, data, size);
            obj->alloc14.Reset();
#else
            BackgroundLoader::AddLockGlobal();
            BackgroundLoader::FreeAllocationsGlobal();
            unsigned int size;
            void* data = ExtractFileFromGP2(data_ov008_0218b43c, data_ov008_0218b455, &size);
            obj->alloc28.Reset();
            func_020dfec0(obj->container, &obj->alloc28, data, size);
            BackgroundLoader::RemoveLockGlobal();
#endif
            if (obj->b24 != 0) {
                obj->b11 = 5;
            } else {
                SetWord0x18ClearByte0x1f((unsigned char*)obj->list, 0);
                obj->ecLo = 0;
                obj->ecHi = 1;
                func_0204b5b4(obj->list, 3);
                DispatchViaTable0204b5e8((Obj0204b5e8*)obj->list, 0, 0);
                AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)obj->list, &obj->alloc00);
                AllocateArray0204af38((Foo0204af38*)obj->list, 1, &obj->alloc00);
                obj->taskId = loader->QueueLoadFile(GetFieldByKey020e0434((Container020e0310*)obj->container, 0), NULL);
                obj->b11++;
            }
        }
    } else if (state == 4) {
        if (loader->GetTaskStatus(obj->taskId) != 0) {
            void* rec;
            void* data;
            unsigned int size;
            int recSize;
            loader->GetLoadedFileByID(obj->taskId, &data, &size);
            int count = CountActiveEntries((ActiveEntry02046900*)data);
            for (int i = 0; i < count; i++) {
                void* found = FindRecordByIndex((Rec020467f0*)data, i, &rec, &recSize);
                if (found != NULL) {
                    func_0204b174(obj->list, found, &obj->alloc00, recSize);
                }
            }
            loader->RemoveTask(obj->taskId);
            obj->taskId = -1;
            DispatchEntry0204b8d0((Obj0204b8d0*)obj->list, 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
            FlushAndDispatchList0204b0e8((List0204b0e8*)obj->list, NULL);
            obj->b11++;
        }
    } else if (state == 5) {
        if (func_ov008_02188a54(obj, 0) != 0) {
            if (obj->b24 == 0) {
                InitStruct0205a444((char*)obj->table);
                obj->table->f50 = 0;
                Entry0205a198* entries = obj->GetEntries();
                obj->GetTable()->SetEntries(entries, 0x12);
                obj->table->tail = obj->tail;
                for (int i = 0; i < 0x12; i++) {
                    Init0205a198((Struct0205a198*)&obj->entries[i]);
                }
                ClearField0And40205a234((ClearTarget0205a234*)obj->tail);
#if defined(jpn)
                obj->taskId = loader->QueueLoadFile(GetFieldByKey020e0434((Container020e0310*)obj->container, 3), NULL);
#else
                const char* inner = GetFieldByKey020e0434((Container020e0310*)obj->container, 6);
                obj->taskId = loader->QueueLoadFileInGP2(GetFieldByKey020e0434((Container020e0310*)obj->container, 5), inner, NULL);
#endif
                obj->b11++;
            } else {
                obj->b11 = 0xff;
            }
        }
    } else if (state == 6) {
        if (loader->GetTaskStatus(obj->taskId) != 0) {
            void* rec;
            void* data;
            unsigned int size;
            int recSize;
            loader->GetLoadedFileByID(obj->taskId, &data, &size);
            int count = CountActiveEntries((ActiveEntry02046900*)data);
            obj->alloc3c.Reset();
            for (int i = 0; i < count; i++) {
                void* found = FindRecordByIndex((Rec020467f0*)data, i, &rec, &recSize);
                if (found != NULL) {
                    func_0205a528(obj->table, found, recSize, &obj->alloc3c);
                }
            }
            obj->flags |= 0x80000;
            loader->RemoveTask(obj->taskId);
            obj->taskId = -1;
            obj->b11++;
        }
    } else if (state == 7) {
        if (func_ov008_02188d74(obj) != 0) {
            if (obj->HasFlag(0x80)) {
                obj->b11 = 9;
            } else {
                obj->b11++;
            }
        }
    } else if (state == 8) {
        char* stage = ov17->stage;
        CopyInternalFields0207df50((Foo0207df50*)(stage + 0x230));
        RestorePairTables0207df90(stage + 0x230);
        BackgroundLoader::AddLockGlobal();
        unsigned int size = 0;
        if (LoadFileIntoMemory(GetFieldByKey020e0434((Container020e0310*)obj->container, 10), data_0211e33c, &size) != 0) {
            ArchiveInfo02184a4c info;
            info.unk_0 = 0;
            info.unk_14 = 0;
            info.unk_18 = 0;
            info.packageID = 0;
            info.allocator = &obj->alloc64;
            info.fileData = data_0211e33c;
            info.size = size;
            info.unk_10 = 1;
            _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(&obj->model, &info, NULL);
            Vec3i02184a4c scale = data_ov008_0218b328;
            ((Object3D*)&obj->model)->SetScale((Vector3i const*)&scale);
            Vec3i02184a4c pos = data_ov008_0218b334;
            obj->GetModel()->SetPosition(&pos);
            Vec3i02184a4c rot = data_ov008_0218b31c;
            *(Vector3i*)&obj->modelRot = *(Vector3i const*)&rot;
            ((Object3D*)&obj->model)->MaybeSetBCFGAnimation(0, 0);
        }
        BackgroundLoader::RemoveLockGlobal();
        BackupPairTables0207dfac(stage + 0x230);
        InitCombatController020a2010(obj->controller);
        SetVec3At0x4((Vec3Target0202e5c0*)obj->controller, 0, 0x8000, 0x40000);
        SetFields0x10To0x18((unsigned char*)obj->controller, 0, 0, 0);
        SetField0x238False(obj->controller);
        SetField0x3b0Value(gs, (int)obj->controller);
        obj->b11++;
    } else if (state == 9) {
        if (!obj->HasFlag(1)) {
            obj->b11 = 0xff;
        } else if (func_ov008_02185964(obj->poller) != 0) {
            if (obj->poller->count > 0) {
                ClearStruct020a13c4((S020a13c4*)obj->script);
                SetupGlobalAndRunScript020a13e4(obj->script, obj->scriptArg8c, 0, 0, 1);
                short ids[50];
                int count = obj->poller->count;
                for (int i = 0; i < count; i++) {
                    ids[i] = obj->poller->ids[i];
                }
                if (func_ov023_021ed724(obj->script, ids, count) & 1) {
                    obj->flags |= 0x8000;
                }
                if (obj->HasFlag(2)) {
                    GetBattleBlock(gs)->GetTail()->scriptId = ids[0];
                    obj->flags |= 4;
                    obj->b16 = 0x3e9;
                } else {
                    obj->b16 = 1000;
                }
                obj->b14 = ids[0];
                obj->alloc78.Reset();
                obj->poller = NULL;
                obj->message = (Message02184a4c*)obj->alloc78.Allocate(REGION_VALUE(0x15c, 0x244));
                Message02184a4c* msg = obj->message;
                msg->a = 0;
                msg->b = 0;
                msg->c = 0;
                msg->d = 0;
                msg->e = 0;
                msg->text = NULL;
                msg->f8 = 0;
                memset(msg->name, 0, 0x38);
                memset(msg->buf, 0, REGION_VALUE(0x118, 0x200));
                msg->text = msg->buf;
                MessageSrc02184a4c* src = FindElementByField020a15bc((Array020a15bc*)obj->script, ids[0]);
                msg = obj->message;
                if (src != NULL) {
                    *(unsigned int*)msg = src->word0;
                    msg->text = (char*)src->text;
                    msg->f8 = src->f8;
                    msg->text = msg->buf;
                    const char* text = src->text;
                    if (text != NULL) {
                        memset(msg->buf, 0, REGION_VALUE(0x118, 0x200));
                        sprintf(msg->buf + StringLength(msg->buf), data_ov008_0218b3e0, text);
                    }
                }
                Member02184a4c* hero = (Member02184a4c*)GameState::GetInstance()->GetProtagonist();
#if defined(jpn)
                int female = hero->GetBit0();
                func_020e2168(obj->message->name, data_ov008_0218c0d5, ids[0], female, 1);
#else
                BackgroundLoader::AddLockGlobal();
                unsigned int size = 0;
                char gp2[0x40];
                __clear(gp2, 0x40);
                char inner[0x20];
                __clear(inner, 0x20);
                int female = hero->GetBit0();
                sprintf(gp2, data_ov008_0218b465, female);
                sprintf(inner, data_ov008_0218b47c, hero->GetBit0());
                void* data = ExtractFileFromGP2(gp2, inner, &size);
                if (data != NULL) {
                    func_020e046c(obj->message->name, data, size, ids[0]);
                }
                BackgroundLoader::RemoveLockGlobal();
#endif
            } else {
                obj->alloc78.Reset();
                obj->poller = NULL;
            }
            if (obj->b14 <= 0) {
                int id = GetField5cbcValue((char*)gs);
                if (func_0202c540(scene) != 0) {
                    obj->flags |= 0x100;
                    id = 0x3eb;
                }
                memset(obj->pathBuf, 0, REGION_VALUE(0x800, 0x960));
                List02184a4c list;
                ResetListHeader020727d8((List020727d8*)&list);
                SubmitScriptFromFile020727f8(&list, data_ov008_0218b400, (short)id, obj->pathBuf, REGION_VALUE(1, 2));
                if (CompareStrings(obj->pathBuf, data_ov008_0218b48f) == 0) {
                    obj->b11 = 0xff;
                } else {
                    obj->taskId = loader->QueueLoadFile(obj->pathBuf, NULL);
                    obj->b11++;
                }
            } else {
                obj->b11 = 0xff;
            }
        }
    } else if (state == 10) {
        if (loader->GetTaskStatus(obj->taskId) != 0) {
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(obj->taskId, &data, &size);
            obj->alloc78.Reset();
            obj->poller = (Poller02184a4c*)obj->alloc78.Allocate(0xd0);
            Reset0209fe9c((char*)obj->poller);
            InitManagerAndAllocateBuffers0209fee4((Obj0209fee4*)obj->poller, &obj->alloc78, (int)data, size);
            SetIntAt0x60((IntField0x60_0209ff64*)obj->poller, 100);
            do {
                PollOv017Task0209ff6c((TaskState0209ff6c*)obj->poller);
            } while (func_ov008_02185964(obj->poller) == 0);
            loader->RemoveTask(obj->taskId);
            obj->taskId = -1;
            obj->b11++;
        }
    } else if (state == 11) {
        if (obj->poller->count > 0) {
            obj->b14 = obj->poller->ids[0];
            obj->b16 = GetField5cbcValue((char*)gs);
            if (obj->HasFlag(0x100)) {
                obj->flags &= ~0x100;
                obj->b16 = 0x3ea;
                if (func_0202c540(scene) != 0) {
                    obj->b16 = 0x3eb;
                }
            }
            obj->alloc78.Reset();
            obj->poller = NULL;
            obj->b11 = 0xff;
        } else if (obj->HasFlag(0x100)) {
            obj->flags &= ~0x100;
            obj->b11 = 0xff;
        } else {
            void* scene2 = func_0202ae18();
            int id = 0x3ea;
            if (CheckField0NonZero((int*)scene2) != 0) {
                if (func_0202c540(scene2) != 0) {
                    id++;
                }
            }
            memset(obj->pathBuf, 0, REGION_VALUE(0x800, 0x960));
            List02184a4c list;
            ResetListHeader020727d8((List020727d8*)&list);
            SubmitScriptFromFile020727f8(&list, data_ov008_0218b400, id, obj->pathBuf, REGION_VALUE(1, 2));
            obj->taskId = loader->QueueLoadFile(obj->pathBuf, NULL);
            obj->b11 = 10;
            obj->flags |= 0x100;
        }
    } else if (state == 0xff) {
        func_ov008_0218712c(obj, 0);
        InitConfig02187664((Manager02187664*)obj, 0);
        func_ov008_02187a70(obj, 0);
        func_ov008_02187f6c(obj, 0);
        for (int i = 0; i < 6; i++) {
            Elem0205d81c02184a4c* elem = FindElementByC40205d81c((Struct_0205d81c*)obj->elems, (unsigned char)i);
            if (elem != NULL) {
                if (!(i != 4 && i != 5)) {
                    elem->fc2 = 1;
                } else {
                    elem->fc2 = 0;
                }
            }
        }
        if (obj->b24 == 0) {
            char* stage = ov17->stage;
            char* presenter = GetGlobalField0x1c020421a0();
            CopyInternalFields0207df50((Foo0207df50*)(stage + 0x5b0));
            RestorePairTables0207df90(stage + 0x5b0);
            func_020432c4(presenter);
            BackupPairTables0207dfac(stage + 0x5b0);
            SetStateAndDispatch0209c3b4((Actor0209c3b4*)&data_02109bf4, 0x29);
            obj->b10 = 3;
            obj->b11 = 0;
            if (obj->message == NULL) {
                obj->flags &= ~0x200000;
                func_ov008_02186964(obj);
            }
        } else {
            obj->flags &= ~0x200000;
            obj->b10 = 4;
            obj->b11 = 0;
        }
    }
}
