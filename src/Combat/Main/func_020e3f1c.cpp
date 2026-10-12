#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"

struct Vec3 {
    int x;
    int y;
    int z;
};

struct Zone02012fe4 {
    char pad[0x23ec];
    ActiveGrottoClass activeGrotto;
};

struct ActorFlags0xc1 {
    unsigned char mode : 2;
    unsigned char rest : 6;
};

struct ActorInfo020e3f1c {
    char pad[0x10];
    unsigned short id;
};

struct Actor020e3f1c {
    char pad0[0x44];
    struct Vec3 position;
    char pad50[0xb2 - 0x50];
    short fb2;
    char padb4[0xc1 - 0xb4];
    struct ActorFlags0xc1 flagsC1;
    char padc2[0x134 - 0xc2];
    char* name;
    char pad138[0x17d - 0x138];
    unsigned char flags17d;
    char pad17e[0x180 - 0x17e];
    struct ActorInfo020e3f1c* info;
};

struct PartyOrder020e3f1c {
    char pad[0xf78];
    unsigned char order[4];
    unsigned char count;
};

struct Camera020e3f1c {
    char pad[0x10];
    struct Vec3 target;
};

struct Display020e3f1c {
    char pad0[0x998];
    int busy;
    int active;
    char pad9a0[0x19b2 - 0x9a0];
    unsigned char visible;
};

struct BattleIntro020e3f1c {
    char pad0[0x8];
    unsigned short monsterIndex;
    unsigned char state;
    char padb;
    short taskId;
    unsigned char cameraMode;
};

struct Struct020dfc40 {
    unsigned char pad[0x14];
    int field_14;
};

struct Obj02076b58;
struct Bytes02033b88;
struct Obj020397cc;
struct Struct020338d4;
struct GlobalObj0202e6a8;
struct Vec3Target0202e5c0;
struct Obj0202ea4c;
struct Obj020d7aa0;
struct Obj02046574;
struct Container020e0310;

extern "C" struct Display020e3f1c* _Z26GetGlobalField0x1c020421a0v();
void* GetGlobal02109400();
extern "C" struct Zone02012fe4* func_02012fe4();
int GetFieldIfFlag4(char* obj);
extern "C" int func_ov017_021959b4();
extern "C" void _Z32StartBattleTimerSequence020e4524Pc(char* obj);
extern "C" void func_ov004_0216fa48(void* obj);
extern "C" void _Z33TickActorAndDispatchPhase02076b58P11Obj02076b58(struct Obj02076b58* actor);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v();
void OrBitsIntoField0(unsigned int* word, unsigned int mask);
void SetByte0xbeShiftPrev(struct Bytes02033b88* obj, int value);
extern "C" void func_02037d88(GameObject* obj);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(struct Obj020397cc* obj, int arg);
extern "C" void func_020531f0(GameObject* obj);
void ClearIntAt0x23c(unsigned char* obj);
int GetSignedByte0x1c9(void* obj);
extern "C" void _Z21AimAndSetVecY020338d4P14Struct020338d4P4Vec3(struct Struct020338d4* self, struct Vec3* target);
extern "C" void _Z30ClearBytesAndZeroBlock02039d24Ph(unsigned char* obj);
extern "C" void _Z26ComputeAndDispatch020338b0Phi(unsigned char* obj, int target);
void ApplyField0x70Tail(struct GlobalObj0202e6a8* obj, int value);
int GetField0x78(void* obj);
void SetVec3At0x4(struct Vec3Target0202e5c0* obj, int x, int y, int z);
extern "C" void _Z34ComputeAngleHeightDistance0202ea4cP11Obj0202ea4c(struct Obj0202ea4c* obj);
extern "C" void func_0202e0a4(struct Camera020e3f1c* camera);
extern "C" struct Obj020d7aa0* _Z25GetGlobalResetObj020d7a50v();
extern "C" void _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(struct Obj020d7aa0* obj);
extern "C" void _Z21BlankFunction02094b34v(void* mgr, int a, int b, int c, int d);
extern "C" void func_ov017_021c3e18(int arg);
extern "C" int _Z18AlwaysTrue02094b4cv(void* mgr);
extern "C" int sprintf(char* buf, const char* fmt, ...);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void* _Z26ResetAndReturnSelf020dfc2cPv(void* p);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(struct Struct020dfc40* p);
extern "C" void func_020dfec0(void* dest, void* allocator, void* fileData, unsigned int size);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310* c, int key);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion* alloc, void* ptr);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(struct Obj02046574* obj, int index, char* name);
extern "C" void func_0204500c(void* global, void* entry, int a, int b);
extern "C" void func_02043124(void* global);

extern AllocatorUnion data_02114e20;
extern const char data_020f2cd4[];
extern const char data_020f2ce4[];

static inline int FxMul(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

// USA: func_020e3f1c
extern "C" ARM void func_020e3f1c(struct BattleIntro020e3f1c* intro) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameState* gs = GameState::GetInstance();
    struct Display020e3f1c* display = _Z26GetGlobalField0x1c020421a0v();
    void* mgr = GetGlobal02109400();
    ActiveGrottoClass* grotto = &func_02012fe4()->activeGrotto;
    struct Camera020e3f1c* camera = (struct Camera020e3f1c*)GetFieldIfFlag4((char*)gs);
    struct Actor020e3f1c* leader = (struct Actor020e3f1c*)gs->GetUnknownGameObject();
    GameResources* res = func_ov017_0218b5b0();

    if (func_ov017_021959b4()) {
        _Z32StartBattleTimerSequence020e4524Pc((char*)intro);
        return;
    }

    short bossId = -1;
    if (grotto != NULL) {
        DetailedTreasureMapData* map = grotto->GetDetailedData();
        if (map != NULL) {
            if (map->mapType_ == 1) {
                bossId = map->regular_.bossMonsterID_;
            } else if (map->mapType_ == 2) {
                bossId = map->legacy_.bossMonsterID_;
            }
        }
    }

    struct Actor020e3f1c* monster = (struct Actor020e3f1c*)gs->GetMaybeFieldMonsterByIndex(intro->monsterIndex);
    if (monster == NULL) {
        func_ov004_0216fa48(intro);
        return;
    }
    _Z33TickActorAndDispatchPhase02076b58P11Obj02076b58((struct Obj02076b58*)monster);
    OrBitsIntoField0((unsigned int*)_Z27GetDataPtr02114e04_020d6c00v(), 2);

    int i;
    for (i = 0; i < 4; i++) {
        GameObject* member = gs->GetPartyMemberByIndex(i);
        if (member != NULL) {
            member->obj3D_.EnableFlag(0x1000000);
            member->obj3D_.DisableFlag(0x1020);
            ((struct Actor020e3f1c*)member)->flagsC1.mode |= 2;
            if (((struct Actor020e3f1c*)member)->fb2 > 0) {
                SetByte0xbeShiftPrev((struct Bytes02033b88*)member, 1);
            } else {
                SetByte0xbeShiftPrev((struct Bytes02033b88*)member, 0);
            }
            func_02037d88(member);
        }
    }

    if (intro->state == 0) {
        if (leader != NULL) {
            _Z27CancelPendingAction020397ccP11Obj020397cci((struct Obj020397cc*)leader, 1);
            leader->fb2 = 0;
        }
        for (int j = 0; j < 4; j++) {
            GameObject* member = gs->GetPartyMemberByIndex(j);
            if (member != NULL) {
                func_020531f0(member);
            }
        }
        ClearIntAt0x23c((unsigned char*)camera);
        SetMainBrightness(res, -16, 0x1e);
        if (monster->info->id == 0x133) {
            intro->cameraMode = 2;
        } else if (monster->flags17d & 4) {
            intro->cameraMode = 1;
        }
        intro->state = 1;
    } else if (intro->state == 1) {
        if (IsMainBrightnessTransitionActive(res)) {
            return;
        }
        struct Vec3 pos = monster->position;
        struct PartyOrder020e3f1c* party = (struct PartyOrder020e3f1c*)GetPtrField0x2a04(gs);
        for (int k = 0; k < party->count; k++) {
            struct Actor020e3f1c* member = (struct Actor020e3f1c*)gs->GetPartyMemberByIndex(party->order[k]);
            if (member != NULL) {
                if (GetSignedByte0x1c9(member) > 0) {
                    ((GameObject*)member)->obj3D_.SetInheritedAlpha(0);
                }
                member->position.x = pos.x;
                member->position.y = pos.y;
                member->position.z = pos.z + 0x3000;
                _Z21AimAndSetVecY020338d4P14Struct020338d4P4Vec3((struct Struct020338d4*)member, &monster->position);
                _Z30ClearBytesAndZeroBlock02039d24Ph((unsigned char*)member);
            }
        }
        _Z26ComputeAndDispatch020338b0Phi((unsigned char*)monster, (int)&leader->position);
        ApplyField0x70Tail((struct GlobalObj0202e6a8*)camera, 0);
        int dist = GetField0x78(camera);
        struct Vec3 target = camera->target;
        if (intro->cameraMode == 1) {
            int dz = FxMul(dist, 0xddb);
            int dy = FxMul(dist, 0x599);
            SetVec3At0x4((struct Vec3Target0202e5c0*)camera, target.x, target.y + dy, target.z + dz);
            _Z34ComputeAngleHeightDistance0202ea4cP11Obj0202ea4c((struct Obj0202ea4c*)camera);
        } else if (intro->cameraMode == 2) {
            SetVec3At0x4((struct Vec3Target0202e5c0*)camera, target.x, target.y + 0x2000, target.z + 0xd800);
            _Z34ComputeAngleHeightDistance0202ea4cP11Obj0202ea4c((struct Obj0202ea4c*)camera);
        }
        func_0202e0a4(camera);
        _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(_Z25GetGlobalResetObj020d7a50v());
        _Z21BlankFunction02094b34v(mgr, 0x74, 0x20e, 0, 0);
        func_ov017_021c3e18(0);
        intro->state = 2;
    } else if (intro->state == 2) {
        SetMainBrightness(res, 0, 0x3c);
        intro->state = 3;
    } else if (intro->state == 3) {
        if (IsMainBrightnessTransitionActive(res)) {
            return;
        }
        if (!_Z18AlwaysTrue02094b4cv(mgr)) {
            return;
        }
        char fileName[16];
        sprintf(fileName, data_020f2cd4, bossId);
        intro->taskId = loader->QueueLoadFileInGP2(data_020f2ce4, fileName, NULL);
        intro->state = 4;
    } else if (intro->state == 4) {
        if (!loader->GetTaskStatus(intro->taskId)) {
            return;
        }
        if (loader->GetDetailedTaskStatus(intro->taskId) != 2) {
            func_ov004_0216fa48(intro);
            return;
        }
        void* fileData;
        unsigned int size;
        loader->GetLoadedFileByID(intro->taskId, &fileData, &size);
        if (fileData == NULL) {
            func_ov004_0216fa48(intro);
            return;
        }
        void* buf = AllocateAligned4(&data_02114e20, 0x500);
        if (buf == NULL) {
            func_ov004_0216fa48(intro);
            return;
        }
        SafeAllocator alloc;
        alloc.ResetAllocatorPointer();
        alloc.CreateTypeA(buf, 0x500);
        struct Struct020dfc40 table;
        _Z26ResetAndReturnSelf020dfc2cPv(&table);
        _Z19ResetStruct020dfc40P14Struct020dfc40(&table);
        func_020dfec0(&table, &alloc, fileData, size);
        loader->RemoveTask(intro->taskId);
        intro->taskId = -1;
        void* entry = (void*)_Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310*)&table, bossId);
        if (entry == NULL) {
            alloc.Destroy();
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, buf);
            func_ov004_0216fa48(intro);
            return;
        }
        display->visible = 1;
        display->active = 1;
        _Z22SetIndexedName02046574P11Obj02046574iPc((struct Obj02046574*)display, 0, leader->name);
        func_0204500c(display, entry, 0, 0xe3);
        display->busy = 1;
        alloc.Destroy();
        _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, buf);
        intro->state = 5;
    } else if (intro->state == 5) {
        display->active = 1;
        if (display->busy == 0) {
            display->active = 0;
            func_02043124(display);
            func_ov004_0216fa48(intro);
        }
    }
}
