#include "Resource/ActionDataTables.h"
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"
#include "Resource/MessageSystem.h"

#if defined(jpn)
#define data_ov010_02184a80 data_ov010_02185b40
#define data_ov010_02184aa6 data_ov010_02185b54
#endif

extern AllocatorUnion data_02114e20;
extern int data_02108760;
extern const char data_ov010_02184a80[];
extern const char data_ov010_02184a95[];
extern const char data_ov010_02184aa6[];

struct Struct021842d8;
void ResetStateAndCleanup021842d8(struct Struct021842d8* obj);

struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);

struct List020727d8 {
    void* entries;
    short capacity;
    short count;
};
void ResetListHeader020727d8(struct List020727d8* list);
extern "C" void func_020728ac(void* list, void* alloc, void* buffer, int length, int a4, int a5, int a6);

struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
void SetForwardAndStore0205ebc0(void* obj, int a, int b);
void DispatchIfField0xc4NonNeg_0205ebfc(void* obj, int a, int b);
void ForwardField0xc0_0205ebec(void* obj);

struct ColorHolder0204bd7c;
unsigned short ConvertColorToDecimalOffset30000(struct ColorHolder0204bd7c* obj);

struct SearchEntry {
    unsigned short key;
    unsigned char pad2[0xc];
    unsigned char lowPair : 2;
    unsigned char kind : 4;
    unsigned char highPair : 2;
    unsigned char padf;
};
struct SearchTable;
struct SearchEntry* FindEntryByHalfwordKey(struct SearchTable* table, int key);

void* GetPtrField0x114(void* obj);
void* GetPtrField0x468(void* obj);
int GetField0x3acValue(GameState* b);
void* GetField0x74deForValidIndex(char* base, unsigned int index);
unsigned char GetField0x397cValue(GameState* battleStruct);

struct Flags020340b4;
void SetFlag0x80At0xc2(struct Flags020340b4* p);

void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);
extern "C" void func_02046380(void* global);
extern "C" int func_020457e0(void* global);

struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);

struct NodeList02057de0;
extern "C" void* func_02057924(void);
int CreateAndRegisterNode02057de0(struct NodeList02057de0* list, int a1, SafeAllocator* alloc, int a2, int a3);
int FindNodeAndProcess02057fb4(void* list, int id, int params);

struct Vector3i;

void* SearchBothTables02079e2c(char* p, int key);

struct Obj02048350;
int ConsumeCounter02048350(struct Obj02048350* obj, int amount);

extern "C" void* func_0202ae18(void);
extern "C" void* func_02012fe4(void);
extern "C" int func_0202c508(void* obj);

struct Vec3s02184354 { short x; short y; short z; };
extern "C" void func_ov017_021d360c(int a, unsigned char b, int c, struct Vec3s02184354 d);

struct MoveRecord02184354 {
    unsigned short id;
    unsigned char pad2[6];
    struct MoveInfo02184354* info;
};
struct MoveInfo02184354 {
    unsigned char pad0[0xc];
    unsigned char category : 4;
    unsigned char categoryHi : 4;
    unsigned char pad0d;
    unsigned char flagsLow : 6;
    unsigned char isSelfTargeting : 1;
    unsigned char flagHi : 1;
};

struct Actor02184354 {
    unsigned char pad0[0xc];
    unsigned char combatantId;
};
MessageSystem* GetGlobalField0x1c020421a0(void);

struct TableEntry02184354 {
    unsigned char pad0[8];
    unsigned int amount : 8;
    unsigned int amountHi : 24;
};

struct Vec3i02184354 { int x; int y; int z; };

struct Params02078484 {
    unsigned char f00;
    unsigned char pad01[0xf];
    unsigned char f10;
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
    short f12;
    short f14;
    short f16;
    short f18;
    short f1a;
    short f1c;
    short pad1e;
    int f20; int f24; int f28;
    int f2c; int f30; int f34;
    int f38; int f3c; int f40;
    int f44; int f48; int f4c;
};

struct Ctx02184354 {
    unsigned char state;
    unsigned char visible;
    unsigned short waitFrames;
    int taskId;
    int nodeId;
    struct List020727d8 list;
    SafeAllocator alloc;
};

// USA: func_ov010_02184354
extern "C" ARM int func_ov010_02184354(struct Ctx02184354* obj) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    MessageSystem* presenter = GetGlobalField0x1c020421a0();
    GameState* bs = GameState::GetInstance();
    GameObject* caster;
    struct MoveRecord02184354* move;
#if defined(jpn)
    struct Actor02184354* actorInfo = *(Actor02184354**)((char*)func_ov017_0218b5b0() + 0x3988);
#else
    struct Actor02184354* actorInfo = *(Actor02184354**)((char*)func_ov017_0218b5b0() + 0x3ba8);
#endif
    caster = bs->GetPartyMemberByIndex(actorInfo->combatantId);
    GameObject* active = bs->GetPartyMemberByIndex(GetField0x397cValue(bs));
    void* scene = func_0202ae18();
    void* ov17 = func_ov017_0218b5b0();
    move = (struct MoveRecord02184354*)func_02012fe4();
#if defined(jpn)
    char message[200];
#endif

    if (caster == NULL || active == NULL) {
        ResetStateAndCleanup021842d8((struct Struct021842d8*)obj);
        return 1;
    }

    unsigned char state = obj->state;
    if (state == 0) {
        CancelPendingAction020397cc((struct Obj020397cc*)active, 1);
        void* buffer = AllocateAligned4(&data_02114e20, 0x7800);
        if (buffer == NULL) {
            ResetStateAndCleanup021842d8((struct Struct021842d8*)obj);
            return 1;
        }
        obj->alloc.CreateTypeA(buffer, 0x7800);
#if defined(jpn)
        obj->taskId = loader->QueueLoadFile(data_ov010_02184a80, NULL);
#else
        obj->taskId = loader->QueueLoadFileInGP2(data_ov010_02184a80, data_ov010_02184a95, NULL);
#endif
        obj->state = 1;
    } else if (state == 1) {
        if (loader->GetTaskStatus(obj->taskId) == 0) return 0;
        if (loader->GetDetailedTaskStatus(obj->taskId) != 2) {
            ResetStateAndCleanup021842d8((struct Struct021842d8*)obj);
            return 1;
        }
        void* filePtr;
        unsigned int fileLen;
        loader->GetLoadedFileByID(obj->taskId, &filePtr, &fileLen);
        ResetListHeader020727d8(&obj->list);
        func_020728ac(&obj->list, &obj->alloc, filePtr, fileLen, 0, 0, 0);
        loader->RemoveTask(obj->taskId);

        unsigned short* slot = (unsigned short*)GetField0x74deForValidIndex((char*)bs, GetField0x3acValue(bs));
        if (slot == NULL) {
            ResetStateAndCleanup021842d8((struct Struct021842d8*)obj);
            return 1;
        }
        struct MoveInfo02184354* info = move->info;
        if (info == NULL) {
            ResetStateAndCleanup021842d8((struct Struct021842d8*)obj);
            return 1;
        }

        unsigned char visible = 1;
        obj->visible = visible;
        if (info->category == 0) {
            void* colour = GetPtrField0x114(caster);
            if (colour != NULL) {
                struct SearchTable* table = (struct SearchTable*)GetPtrField0x468(bs);
                struct SearchEntry* entry = FindEntryByHalfwordKey(table,
                    ConvertColorToDecimalOffset30000((struct ColorHolder0204bd7c*)colour));
                if (entry != NULL) {
                    if (entry->kind != 0) obj->visible = 0;
                }
            }
        } else {
            struct MoveInfo02184354* self = move->info;
            if (self != NULL) {
                if (self->isSelfTargeting == 0) visible = 0;
                obj->visible = visible;
            }
        }

        int key;
        if (obj->visible == 0) {
            obj->state = 3;
            key = 2;
        } else if (*slot != 0) {
            obj->state = 2;
            key = 1;
        } else {
            key = 0;
            obj->state = 4;
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0x64, key);
        }

        void* entry = FindEntryByKey((struct TableA68*)&obj->list, (short)key);
#if defined(jpn)
        sprintf(message, (const char*)entry, *(char**)((char*)caster + 0x134));
        func_0204500c(presenter, message, 0);
        *(int*)((char*)presenter + 0x868) = 1;
#else
        struct Vec3i02184354 casterObj;
        InitObjFromCombatantId020e4bf4(&casterObj, actorInfo->combatantId);
        func_02046380(presenter);
        *(void**)presenter = &casterObj;
        func_0204500c(presenter, (const char*)entry, 0, (void*)0xe3);
        *(int*)((char*)presenter + 0x998) = 1;
#endif
    } else if (state == 2) {
#if defined(jpn)
        if (*(int*)((char*)presenter + 0x868) != 0) return 0;
#else
        if (*(int*)((char*)presenter + 0x998) != 0) return 0;
#endif
        if (func_020457e0(presenter) == 0) {
            void* entry = FindEntryByKey((struct TableA68*)&obj->list, 0);
#if defined(jpn)
            sprintf(message, (const char*)entry, *(char**)((char*)caster + 0x134));
            func_0204500c(presenter, message, 0);
            *(int*)((char*)presenter + 0x868) = 1;
#else
            struct Vec3i02184354 casterObj;
            InitObjFromCombatantId020e4bf4(&casterObj, actorInfo->combatantId);
            func_02046380(presenter);
            *(void**)presenter = &casterObj;
            func_0204500c(presenter, (const char*)entry, 0, (void*)0xe3);
            *(int*)((char*)presenter + 0x998) = 1;
#endif
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0x64, 0);
            unsigned short* slot = (unsigned short*)GetField0x74deForValidIndex((char*)bs, GetField0x3acValue(bs));
            if (slot != NULL) *slot = 0;
            obj->state = 4;
        } else {
            ResetStateAndCleanup021842d8((struct Struct021842d8*)obj);
            return 1;
        }
    } else if (state == 4) {
        obj->taskId = loader->QueueLoadFile(data_ov010_02184aa6, NULL);
        obj->state = 5;
        obj->waitFrames = 0;
    } else if (state == 5) {
        if (loader->GetTaskStatus(obj->taskId) == 0) return 0;
        if (loader->GetDetailedTaskStatus(obj->taskId) != 2) {
            ResetStateAndCleanup021842d8((struct Struct021842d8*)obj);
            return 1;
        }
        if (obj->waitFrames < 0xf) {
            obj->waitFrames = obj->waitFrames + 1;
            return 0;
        }
        SetForwardAndStore0205ebc0(&data_02108760, 0x74, 0x74);
        DispatchIfField0xc4NonNeg_0205ebfc(&data_02108760, 0, 0);

        void* filePtr;
        unsigned int fileLen;
        loader->GetLoadedFileByID(obj->taskId, &filePtr, &fileLen);

#if defined(jpn)
        char* stage = (char*)ov17 + 0x27c;
#else
        char* stage = (char*)ov17 + 0x2cc;
#endif
        struct Vec3i02184354 pos = *(struct Vec3i02184354*)((char*)caster + 0x44);
        CopyInternalFields0207df50((struct Foo0207df50*)(stage + 0xc40));
        RestorePairTables0207df90(stage + 0xc40);
        void* nodes = func_02057924();
        CreateAndRegisterNode02057de0((struct NodeList02057de0*)nodes, 0x11, &obj->alloc,
                                      (int)filePtr, (int)fileLen);
        BackupPairTables0207dfac(stage + 0xc40);

        struct Vec3i02184354 scale;
        scale.x = 0x10a;
        scale.y = 0x10a;
        scale.z = 0x10a;

        struct Params02078484 params;
        params.f00 = 0;
        params.f10 = 1;
        params.f12 = 0;
        params.f14 = -1;
        params.f16 = -1;
        params.f18 = -1;
        params.f1a = -1;
        params.f1c = -0x1000;
        params.f20 = 0;
        params.f24 = 0;
        params.f28 = 0;
        params.f2c = 0;
        params.f30 = 0;
        params.f34 = 0;
        params.f38 = 0;
        params.f3c = 0;
        params.f40 = 0;
        params.f44 = 0x1000;
        params.f48 = 0x1000;
        params.f4c = 0x1000;
        params.b0 = 0;
        params.b1 = 0;
        params.b2 = 1;
        params.b3 = 0;
        params.b4 = 0;
        params.b5 = 0;
        params.b6 = 0;
        params.b7 = 0;

        *(Vector3i*)&params.f2c = *(Vector3i const*)&pos.x;
        *(Vector3i*)&params.f44 = *(Vector3i const*)&scale.x;
        obj->nodeId = FindNodeAndProcess02057fb4(nodes, 0x11, (int)&params);

        struct Vec3s02184354 anchor;
        anchor.x = (short)(pos.x >> 4);
        anchor.y = (short)(pos.y >> 4);
        anchor.z = (short)(pos.z >> 4);

        if (func_0202c508(scene) != 0) {
            unsigned short* slot = (unsigned short*)GetField0x74deForValidIndex((char*)bs, GetField0x3acValue(bs));
            if (slot != NULL) {
                slot[0] = move->id;
                slot[1] = anchor.x;
                slot[2] = anchor.y;
                slot[3] = anchor.z;
            }
        }

        struct TableEntry02184354* row =
            (struct TableEntry02184354*)SearchBothTables02079e2c((char*)GetData02108e10(), 0xd2);
        if (row != NULL) {
            ConsumeCounter02048350((struct Obj02048350*)caster, row->amount);
        }
        GameObject* target = bs->GetUnknownGameObject();
        if (target != NULL) {
            SetFlag0x80At0xc2((struct Flags020340b4*)target);
        }
        func_ov017_021d360c(0, GetField0x3acValue(bs), move->id, anchor);
        obj->state = 3;
    } else if (state == 3) {
        GameState* now = GameState::GetInstance();
        int finished = 0;
        if (obj->visible != 0) {
#if defined(jpn)
            if (now->GetGameObjectByIndex(obj->nodeId) == NULL && *(int*)((char*)presenter + 0x868) == 0) {
#else
            if (now->GetGameObjectByIndex(obj->nodeId) == NULL && *(int*)((char*)presenter + 0x998) == 0) {
#endif
                finished = 1;
            }
        } else {
#if defined(jpn)
            if (*(int*)((char*)presenter + 0x868) == 0) finished = 1;
#else
            if (*(int*)((char*)presenter + 0x998) == 0) finished = 1;
#endif
        }
        if (finished != 0) {
            ResetStateAndCleanup021842d8((struct Struct021842d8*)obj);
            ForwardField0xc0_0205ebec(&data_02108760);
            return 1;
        }
    }
    return 0;
}
