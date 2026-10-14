#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "World/Zone3D.h"
#include "std_library_functions.h"

#if defined(jpn)
#define data_020f1b50 data_020f1cc8
#define data_020f1b52 data_020f1cca
#endif

struct Actor020a6728 {
    Object3D object;
    char pad_ac[4];
    unsigned short slot;
    unsigned short field_b2;
    unsigned short field_b4;
    unsigned short field_b6;
    char pad_b8[0x28];
    unsigned char flags;
    char pad_e1[0x63];
    Vector3i homePosition;
    char pad_150[0x20];
};
struct SearchTable;
struct SearchEntry020a6728;
struct PointerField32c_ffc0;
struct Obj02033874;
struct Flags02033fdc;
struct ActorAllocation020a6728 { SafeAllocator* allocator; char* tables; };
SearchTable* GetPtrField0x468(void*);
SearchEntry020a6728* FindEntryByHalfwordKey(SearchTable*, int);
void* GetPointerAt0x32c(PointerField32c_ffc0*);
void* LoadFileIntoNewAllocation(const char*, SafeAllocator&, unsigned int*);
extern "C" void _Z17InitActor020a75a0Pc(char*);
extern "C" void _Z25RestorePairTables0207df90Pc(char*);
extern "C" void _Z24BackupPairTables0207dfacPc(char*);
extern "C" Zone3D* func_02012fe4();
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(Obj02033874*, int);
void ClearFlag0x4At0xe0(Flags02033fdc*);
void RegisterCombatantSlot(GameState*, int, GameObject*);
extern "C" void _Z37ResetContainerAndHandleFields020da1acPv(void*);
extern "C" void func_020a72ac(Zone3D*, int);
extern char data_020f1b50[];
extern char data_020f1b52[];
extern ActorAllocation020a6728 data_ov017_021d82fc;

// USA: func_020a6728
// JPN: func_020a84cc
// KEEP-NAME
extern "C" ARM void func_020a6728(GameResources* self, int id) {
    GameState* state = GameState::GetInstance();
    SearchEntry020a6728* entry = FindEntryByHalfwordKey(GetPtrField0x468(state), id);
    const char* name = 0;
    if (entry != 0) name = (const char*)entry + 5;
    if (id != 10000 && id != 10100) {
        if (id < 20000 || id > 29999 || name == 0 || strstr(name, data_020f1b50) != 0)
            return;
    }
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    SafeAllocator* allocator = &self->allocator_array_38[7];
    char* tables = (char*)&self->unknown_2cc + 0x310;
    GetPointerAt0x32c((PointerField32c_ffc0*)state);
    if (loader->GetNumQueuedTasks() > 0) return;
    unsigned int length;
    void* file = LoadFileIntoNewAllocation(data_020f1b52, *allocator, &length);
    if (file == 0) return;
    Actor020a6728* actor = (Actor020a6728*)allocator->Allocate(0x170);
    if (actor == 0) return;
    _Z17InitActor020a75a0Pc((char*)actor);
    ObjectArchiveLoadInfo loadInfo;
    loadInfo.unk_0 = 0;
    loadInfo.fileData = 0;
    loadInfo.unk_8 = 0;
    loadInfo.allocator = 0;
    loadInfo.unk_10 = 0;
    loadInfo.unk_14 = 0;
    loadInfo.unk_18 = 0;
    loadInfo.packageID = 0;
    _Z25RestorePairTables0207df90Pc(tables);
    loadInfo.fileData = file;
    loadInfo.unk_8 = length;
    loadInfo.allocator = allocator;
    actor->object.LoadFromCHRArchive(&loadInfo);
    _Z24BackupPairTables0207dfacPc(tables);
    Zone3D* zone = func_02012fe4();
    state->GetUnknownGameObject();
    ZoneSavedActorState* saved = zone->GetSavedActorState();
    actor->object.position_ = saved->position;
    saved = zone->GetSavedActorState();
    actor->homePosition = saved->position;
    actor->object.SetScale(0xa0, 0xa0, 0xa0);
    _Z24SetVecYFromValue02033874P11Obj02033874i((Obj02033874*)actor, zone->savedActor_.rotationY);
    actor->slot = 0xc9;
    actor->field_b4 = 0x106;
    actor->field_b6 = 10;
    actor->object.MakeVisible();
    ClearFlag0x4At0xe0((Flags02033fdc*)actor);
    actor->flags &= ~1;
    actor->object.DisableFlag(0x180);
    actor->object.EnableFlag(0x400000);
    RegisterCombatantSlot(state, 0xc9, (GameObject*)actor);
    if (id == 10000) {
        SafeAllocator* extraAllocator = (SafeAllocator*)allocator->Allocate(0x14);
        extraAllocator->ResetAllocatorPointer();
        void* buffer = allocator->Allocate(0x3c00);
        extraAllocator->CreateTypeA(buffer, 0x3c00);
        _Z37ResetContainerAndHandleFields020da1acPv(&data_ov017_021d82fc);
        data_ov017_021d82fc.allocator = extraAllocator;
        data_ov017_021d82fc.tables = tables;
    }
    func_020a72ac(func_02012fe4(), 0);
}
