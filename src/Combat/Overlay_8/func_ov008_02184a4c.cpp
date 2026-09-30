#include <globaldefs.h>
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

extern "C" int _Z12StringLengthPKc(const char* s);

struct List02184a4c {
    void* entries;
    short capacity;
    short count;
};

/* Result of func_ov017_0218b5b0. */
struct Ov17Data02184a4c {
    char pad0[0x2cc];
    char stage[0x87c - 0x2cc];
};

/* The 0xb0-byte block LoadBattleBlock020ac4c0 copies out of the GameState. */
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

static inline char* GetSection104(GameState* gs) { return (char*)gs + 0x104; }
static inline char* GetSection7400(char* section) { return section + 0x7400; }
static inline BattleBlock02184a4c* GetBattleBlock(GameState* gs) {
    return (BattleBlock02184a4c*)(GetSection7400(GetSection104(gs)) + 0x3c);
}

/* Script poller allocated into obj->poller. */
struct Poller02184a4c {
    char pad0[0x68];
    short count;
    short ids[1];
};

/* Message record allocated into obj->message. */
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
    char buf[0x200];

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
    char pad0[0x150];
    Stat02184a4c* stat;
    int GetBit0() { return stat->bit0; }
};

extern "C" void _ZN8Vector3iaSERKS_(Vec3i02184a4c* dst, const Vec3i02184a4c* src);

struct Model02184a4c {
    char pad0[0x44];
    Vec3i02184a4c pos;
    void SetPosition(const Vec3i02184a4c* v) { _ZN8Vector3iaSERKS_(&pos, v); }
};

struct Obj02184a4c {
    SafeAllocator alloc00;
    char pad14[0x28 - 0x14];
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
extern "C" int _Z23LoadBattleBlock020ac4c0Pv(void* dst);
extern "C" int func_0202c508(void* obj);
extern "C" int func_0202c540(void* obj);
extern "C" void _Z23ResetListHeader020727d8P12List020727d8(List02184a4c* list);
extern "C" void _Z28SubmitScriptFromFile020727f8PvPKciS_h(void* list, const char* path, int id, void* out, unsigned char mode);
extern "C" void _Z13Reset0209fe9cPc(void* obj);
extern "C" void _Z37InitManagerAndAllocateBuffers0209fee4P11Obj0209fee4P13SafeAllocatorii(void* obj, SafeAllocator* alloc, void* data, unsigned int size);
extern "C" void _Z12SetIntAt0x60P21IntField0x60_0209ff64i(void* obj, int value);
extern "C" void _Z21PollOv017Task0209ff6cP17TaskState0209ff6c(void* obj);
extern "C" int func_ov008_02185964(void* obj);
extern "C" int _Z17GetGlobal02109400v(void);
extern "C" void _Z21BlankFunction02094b40v(void);
extern "C" void _Z21BlankFunction02094b34v(int a, int b, int c, int d, int e);
extern "C" int _Z18AlwaysTrue02094b4cv(int a);
extern "C" void* ExtractFileFromGP2(const char* gp2, const char* inner, unsigned int* outSize);
extern "C" void func_020dfec0(void* container, SafeAllocator* alloc, void* data, unsigned int size);
extern "C" void _Z24SetWord0x18ClearByte0x1fPhi(void* obj, int value);
extern "C" void func_0204b5b4(void* obj, int a);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(void* obj, int a, int b);
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(void* obj, SafeAllocator* alloc);
extern "C" void _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(void* obj, int count, SafeAllocator* alloc);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(void* c, int key);
extern "C" int _Z18CountActiveEntriesP19ActiveEntry02046900(void* data);
extern "C" void* _Z17FindRecordByIndexP11Rec020467f0iPPvPi(void* data, int index, void** out, int* outSize);
extern "C" void func_0204b174(void* obj, void* rec, SafeAllocator* alloc, int size);
extern "C" void _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(void* obj, unsigned int a, int b, int c, short d, short e, short f, short g, unsigned short h);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(void* obj, void* buf);
extern "C" int func_ov008_02188a54(Obj02184a4c* obj, int a);
extern "C" void _Z18InitStruct0205a444Pc(void* obj);
extern "C" void _Z12Init0205a198P14Struct0205a198(Entry0205a198* obj);
extern "C" void _Z23ClearField0And40205a234P19ClearTarget0205a234(void* obj);
extern "C" int func_0205a528(void* obj, void* data, int size, SafeAllocator* alloc);
extern "C" int func_ov008_02188d74(Obj02184a4c* obj);
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(char* p);
extern "C" void _Z25RestorePairTables0207df90Pc(char* obj);
extern "C" void _Z24BackupPairTables0207dfacPc(char* obj);
extern "C" int _Z18LoadFileIntoMemoryPKcPvPj(const char* path, void* dst, unsigned int* outSize);
extern "C" int _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void* obj, void* info, void* callback);
extern "C" void _ZN8Object3D8SetScaleEPK8Vector3i(void* obj, const Vec3i02184a4c* scale);
extern "C" void _ZN8Object3D21MaybeSetBCFGAnimationEii(void* obj, int a, int b);
extern "C" void _Z28InitCombatController020a2010Pv(void* obj);
extern "C" void _Z12SetVec3At0x4P18Vec3Target0202e5c0iii(void* obj, int x, int y, int z);
extern "C" void _Z19SetFields0x10To0x18Phiii(void* obj, int a, int b, int c);
extern "C" void _Z18SetField0x238FalsePv(void* obj);
extern "C" void _Z18SetField0x3b0ValueP9GameStatei(GameState* gs, void* value);
extern "C" void _Z19ClearStruct020a13c4P9S020a13c4(void* p);
extern "C" void _Z31SetupGlobalAndRunScript020a13e4PvS_ith(void* a, void* b, int c, unsigned short d, unsigned char e);
extern "C" int func_ov023_021ed724(void* obj, short* ids, int count);
extern "C" MessageSrc02184a4c* _Z26FindElementByField020a15bcP13Array020a15bci(void* arr, int id);
extern "C" void func_020e046c(char* buf, void* b, unsigned int c, int idx);
extern "C" int _Z17GetField5cbcValuePc(GameState* gs);
extern "C" int _Z14CompareStringsPKcS0_(const char* a, const char* b);
extern "C" int _Z18CheckField0NonZeroPi(void* obj);
extern "C" void func_ov008_0218712c(Obj02184a4c* obj, int a);
extern "C" void _Z18InitConfig02187664P15Manager02187664i(Obj02184a4c* obj, int a);
extern "C" void func_ov008_02187a70(Obj02184a4c* obj, int a);
extern "C" void func_ov008_02187f6c(Obj02184a4c* obj, int a);
extern "C" Elem0205d81c02184a4c* _Z23FindElementByC40205d81cP15Struct_0205d81ci(void* s, int key);
extern "C" char* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void func_020432c4(char* obj);
extern "C" void _Z27SetStateAndDispatch0209c3b4P13Actor0209c3b4i(void* actor, int val);
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

// USA: func_ov008_02184a4c
extern "C" ARM void func_ov008_02184a4c(Obj02184a4c* obj) {
    GameState* gs = GameState::GetInstance();
    Ov17Data02184a4c* ov17 = (Ov17Data02184a4c*)func_ov017_0218b5b0();
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
        _Z23LoadBattleBlock020ac4c0Pv(&block);
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
                _Z23ResetListHeader020727d8P12List020727d8(&list);
                _Z28SubmitScriptFromFile020727f8PvPKciS_h(&list, data_ov008_0218b400, 1000, path, 2);
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
            _Z13Reset0209fe9cPc(obj->poller);
            _Z37InitManagerAndAllocateBuffers0209fee4P11Obj0209fee4P13SafeAllocatorii(obj->poller, &obj->alloc78, data, size);
            _Z12SetIntAt0x60P21IntField0x60_0209ff64i(obj->poller, 100);
            do {
                _Z21PollOv017Task0209ff6cP17TaskState0209ff6c(obj->poller);
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
        int global = _Z17GetGlobal02109400v();
        _Z21BlankFunction02094b40v();
        _Z21BlankFunction02094b34v(global, 0x6b, 0x1fc, 0, 0);
        obj->b11++;
    } else if (state == 3) {
        if (_Z18AlwaysTrue02094b4cv(_Z17GetGlobal02109400v()) != 0) {
            BackgroundLoader::AddLockGlobal();
            BackgroundLoader::FreeAllocationsGlobal();
            unsigned int size;
            void* data = ExtractFileFromGP2(data_ov008_0218b43c, data_ov008_0218b455, &size);
            obj->alloc28.Reset();
            func_020dfec0(obj->container, &obj->alloc28, data, size);
            BackgroundLoader::RemoveLockGlobal();
            if (obj->b24 != 0) {
                obj->b11 = 5;
            } else {
                _Z24SetWord0x18ClearByte0x1fPhi(obj->list, 0);
                obj->ecLo = 0;
                obj->ecHi = 1;
                func_0204b5b4(obj->list, 3);
                _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(obj->list, 0, 0);
                _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(obj->list, &obj->alloc00);
                _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(obj->list, 1, &obj->alloc00);
                obj->taskId = loader->QueueLoadFile(_Z21GetFieldByKey020e0434P17Container020e0310i(obj->container, 0), NULL);
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
            int count = _Z18CountActiveEntriesP19ActiveEntry02046900(data);
            for (int i = 0; i < count; i++) {
                void* found = _Z17FindRecordByIndexP11Rec020467f0iPPvPi(data, i, &rec, &recSize);
                if (found != NULL) {
                    func_0204b174(obj->list, found, &obj->alloc00, recSize);
                }
            }
            loader->RemoveTask(obj->taskId);
            obj->taskId = -1;
            _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(obj->list, 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(obj->list, NULL);
            obj->b11++;
        }
    } else if (state == 5) {
        if (func_ov008_02188a54(obj, 0) != 0) {
            if (obj->b24 == 0) {
                _Z18InitStruct0205a444Pc(obj->table);
                obj->table->f50 = 0;
                Entry0205a198* entries = obj->GetEntries();
                obj->GetTable()->SetEntries(entries, 0x12);
                obj->table->tail = obj->tail;
                for (int i = 0; i < 0x12; i++) {
                    _Z12Init0205a198P14Struct0205a198(&obj->entries[i]);
                }
                _Z23ClearField0And40205a234P19ClearTarget0205a234(obj->tail);
                const char* inner = _Z21GetFieldByKey020e0434P17Container020e0310i(obj->container, 6);
                obj->taskId = loader->QueueLoadFileInGP2(_Z21GetFieldByKey020e0434P17Container020e0310i(obj->container, 5), inner, NULL);
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
            int count = _Z18CountActiveEntriesP19ActiveEntry02046900(data);
            obj->alloc3c.Reset();
            for (int i = 0; i < count; i++) {
                void* found = _Z17FindRecordByIndexP11Rec020467f0iPPvPi(data, i, &rec, &recSize);
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
        _Z26CopyInternalFields0207df50P11Foo0207df50(stage + 0x230);
        _Z25RestorePairTables0207df90Pc(stage + 0x230);
        BackgroundLoader::AddLockGlobal();
        unsigned int size = 0;
        if (_Z18LoadFileIntoMemoryPKcPvPj(_Z21GetFieldByKey020e0434P17Container020e0310i(obj->container, 10), data_0211e33c, &size) != 0) {
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
            _ZN8Object3D8SetScaleEPK8Vector3i(&obj->model, &scale);
            Vec3i02184a4c pos = data_ov008_0218b334;
            obj->GetModel()->SetPosition(&pos);
            Vec3i02184a4c rot = data_ov008_0218b31c;
            _ZN8Vector3iaSERKS_(&obj->modelRot, &rot);
            _ZN8Object3D21MaybeSetBCFGAnimationEii(&obj->model, 0, 0);
        }
        BackgroundLoader::RemoveLockGlobal();
        _Z24BackupPairTables0207dfacPc(stage + 0x230);
        _Z28InitCombatController020a2010Pv(obj->controller);
        _Z12SetVec3At0x4P18Vec3Target0202e5c0iii(obj->controller, 0, 0x8000, 0x40000);
        _Z19SetFields0x10To0x18Phiii(obj->controller, 0, 0, 0);
        _Z18SetField0x238FalsePv(obj->controller);
        _Z18SetField0x3b0ValueP9GameStatei(gs, obj->controller);
        obj->b11++;
    } else if (state == 9) {
        if (!obj->HasFlag(1)) {
            obj->b11 = 0xff;
        } else if (func_ov008_02185964(obj->poller) != 0) {
            if (obj->poller->count > 0) {
                _Z19ClearStruct020a13c4P9S020a13c4(obj->script);
                _Z31SetupGlobalAndRunScript020a13e4PvS_ith(obj->script, obj->scriptArg8c, 0, 0, 1);
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
                obj->message = (Message02184a4c*)obj->alloc78.Allocate(0x244);
                Message02184a4c* msg = obj->message;
                msg->a = 0;
                msg->b = 0;
                msg->c = 0;
                msg->d = 0;
                msg->e = 0;
                msg->text = NULL;
                msg->f8 = 0;
                memset(msg->name, 0, 0x38);
                memset(msg->buf, 0, 0x200);
                msg->text = msg->buf;
                MessageSrc02184a4c* src = _Z26FindElementByField020a15bcP13Array020a15bci(obj->script, ids[0]);
                msg = obj->message;
                if (src != NULL) {
                    *(unsigned int*)msg = src->word0;
                    msg->text = (char*)src->text;
                    msg->f8 = src->f8;
                    msg->text = msg->buf;
                    const char* text = src->text;
                    if (text != NULL) {
                        memset(msg->buf, 0, 0x200);
                        sprintf(msg->buf + _Z12StringLengthPKc(msg->buf), data_ov008_0218b3e0, text);
                    }
                }
                Member02184a4c* hero = (Member02184a4c*)GameState::GetInstance()->GetProtagonist();
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
            } else {
                obj->alloc78.Reset();
                obj->poller = NULL;
            }
            if (obj->b14 <= 0) {
                int id = _Z17GetField5cbcValuePc(gs);
                if (func_0202c540(scene) != 0) {
                    obj->flags |= 0x100;
                    id = 0x3eb;
                }
                memset(obj->pathBuf, 0, 0x960);
                List02184a4c list;
                _Z23ResetListHeader020727d8P12List020727d8(&list);
                _Z28SubmitScriptFromFile020727f8PvPKciS_h(&list, data_ov008_0218b400, (short)id, obj->pathBuf, 2);
                if (_Z14CompareStringsPKcS0_(obj->pathBuf, data_ov008_0218b48f) == 0) {
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
            _Z13Reset0209fe9cPc(obj->poller);
            _Z37InitManagerAndAllocateBuffers0209fee4P11Obj0209fee4P13SafeAllocatorii(obj->poller, &obj->alloc78, data, size);
            _Z12SetIntAt0x60P21IntField0x60_0209ff64i(obj->poller, 100);
            do {
                _Z21PollOv017Task0209ff6cP17TaskState0209ff6c(obj->poller);
            } while (func_ov008_02185964(obj->poller) == 0);
            loader->RemoveTask(obj->taskId);
            obj->taskId = -1;
            obj->b11++;
        }
    } else if (state == 11) {
        if (obj->poller->count > 0) {
            obj->b14 = obj->poller->ids[0];
            obj->b16 = _Z17GetField5cbcValuePc(gs);
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
            if (_Z18CheckField0NonZeroPi(scene2) != 0) {
                if (func_0202c540(scene2) != 0) {
                    id++;
                }
            }
            memset(obj->pathBuf, 0, 0x960);
            List02184a4c list;
            _Z23ResetListHeader020727d8P12List020727d8(&list);
            _Z28SubmitScriptFromFile020727f8PvPKciS_h(&list, data_ov008_0218b400, id, obj->pathBuf, 2);
            obj->taskId = loader->QueueLoadFile(obj->pathBuf, NULL);
            obj->b11 = 10;
            obj->flags |= 0x100;
        }
    } else if (state == 0xff) {
        func_ov008_0218712c(obj, 0);
        _Z18InitConfig02187664P15Manager02187664i(obj, 0);
        func_ov008_02187a70(obj, 0);
        func_ov008_02187f6c(obj, 0);
        for (int i = 0; i < 6; i++) {
            Elem0205d81c02184a4c* elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci(obj->elems, (unsigned char)i);
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
            char* presenter = _Z26GetGlobalField0x1c020421a0v();
            _Z26CopyInternalFields0207df50P11Foo0207df50(stage + 0x5b0);
            _Z25RestorePairTables0207df90Pc(stage + 0x5b0);
            func_020432c4(presenter);
            _Z24BackupPairTables0207dfacPc(stage + 0x5b0);
            _Z27SetStateAndDispatch0209c3b4P13Actor0209c3b4i(&data_02109bf4, 0x29);
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
