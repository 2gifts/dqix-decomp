#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"

#if defined(jpn)
#define data_020f1c08 data_020f1d74
#define data_020f1c20 data_020f1d8c
#define data_020f1c38 data_020f1da4
#define data_020f1c51 data_020f1dbd
#define data_020e910c data_020e9218
#define data_020e9100 data_020e920c
#endif

typedef char PairTable020aca88[0x70];

struct Prop020aca88 {
    Object3D obj3D;
    char unk_ac[4];
    unsigned short kind_b0;
    char unk_b2[0xe0 - 0xb2];
    unsigned char hidden_e0 : 1;
    unsigned char flags_e0 : 7;
    char unk_e1[0x154 - 0xe1];
    Vector3i homePosition_154;
    char unk_160[0x1b8 - 0x160];
};

struct ArchiveSlot020aca88 {
    SafeAllocator* allocator;
    char* tables;
    char unk_8[0x44 - 8];
};

struct Struct_203dafc;
struct PointerField330_ffd0;
struct Obj02033874;
struct Flags02033fdc;

void* GetPointerAt0x330(struct PointerField330_ffd0* obj);
extern "C" void _Z15InitObj020ad59cPv(void* obj);
void ClearEightWords(struct Struct_203dafc* obj);
extern "C" void _Z25RestorePairTables0207df90Pc(char* tables);
extern "C" void _Z24BackupPairTables0207dfacPc(char* tables);
extern "C" void func_02012fe4();
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(struct Obj02033874* obj, int value);
void ClearFlag0x4At0xe0(struct Flags02033fdc* obj);
void RegisterCombatantSlot(GameState* state, int slot, GameObject* obj);
extern "C" void func_020adfa8(struct Prop020aca88* prop);
extern "C" void _Z37ResetContainerAndHandleFields020da1acPv(void* container);

extern const char data_020f1c08[];
extern const char data_020f1c20[];
extern const char data_020f1c38[];
extern const char data_020f1c51[];
extern const Vector3i data_020e910c;
extern const Vector3i data_020e9100;
extern struct ArchiveSlot020aca88 data_ov017_021d82fc;

// USA: func_020aca88
extern "C" ARM void func_020aca88(GameResources* res, int message) {
    if (message == 0x2774) {
        GameState* state = GameState::GetInstance();
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        SafeAllocator* alloc = &res->allocator_array_38[7];
        char* tables = ((PairTable020aca88*)res->unknown_2cc)[7];
        GetPointerAt0x330((struct PointerField330_ffd0*)state);
        if (loader->GetNumQueuedTasks() > 0) {
            return;
        }

        unsigned int size;
        ObjectArchiveLoadInfo info;
        void* file = LoadFileIntoNewAllocation(data_020f1c08, *alloc, &size);
        if (file == NULL) {
            return;
        }
        struct Prop020aca88* prop = (struct Prop020aca88*)alloc->Allocate(0x1b8);
        if (prop == NULL) {
            return;
        }
        _Z15InitObj020ad59cPv(prop);
        ClearEightWords((struct Struct_203dafc*)&info);
        _Z25RestorePairTables0207df90Pc(tables);
        info.unk_8 = size;
        info.fileData = file;
        info.allocator = alloc;
        prop->obj3D.LoadFromCHRArchive(&info);
        _Z24BackupPairTables0207dfacPc(tables);
        func_02012fe4();

        GameObject* hero = state->GetUnknownGameObject();
        Vector3i pos = hero->obj3D_.position_;
        pos.y += 0xa000;
        Vector3i scale = data_020e910c;
        Vector3i rot = data_020e9100;
        prop->obj3D.rotation_ = rot;
        prop->obj3D.position_ = pos;
        prop->homePosition_154 = pos;
        prop->obj3D.SetScale(&scale);
        _Z24SetVecYFromValue02033874P11Obj02033874i((struct Obj02033874*)prop, 0x3244);
        prop->kind_b0 = 0xc9;
        prop->obj3D.MakeVisible();
        ClearFlag0x4At0xe0((struct Flags02033fdc*)prop);
        prop->hidden_e0 = 0;
        prop->obj3D.EnableFlag(0x80);
        RegisterCombatantSlot(state, 0xca, (GameObject*)prop);
        state->GetGameObjectByIndex(0xcb);

        file = LoadFileIntoNewAllocation(data_020f1c20, *alloc, &size);
        if (file == NULL) {
            return;
        }
        Object3D* obj = (Object3D*)alloc->Allocate(0xac);
        if (obj == NULL) {
            return;
        }
        obj->Initialize();
        ClearEightWords((struct Struct_203dafc*)&info);
        _Z25RestorePairTables0207df90Pc(tables);
        info.unk_8 = size;
        info.fileData = file;
        info.allocator = alloc;
        obj->LoadFromCHRArchive(&info);
        _Z24BackupPairTables0207dfacPc(tables);
        obj->position_ = pos;
        obj->SetScale(&scale);
        obj->MakeVisible();
        obj->EnableFlag(0x180);
        RegisterCombatantSlot(state, 0xcb, (GameObject*)obj);
        state->GetGameObjectByIndex(0xcc);

        file = LoadFileIntoNewAllocation(data_020f1c38, *alloc, &size);
        if (file == NULL) {
            return;
        }
        obj = (Object3D*)alloc->Allocate(0xac);
        if (obj == NULL) {
            return;
        }
        obj->Initialize();
        ClearEightWords((struct Struct_203dafc*)&info);
        _Z25RestorePairTables0207df90Pc(tables);
        info.unk_8 = size;
        info.fileData = file;
        info.allocator = alloc;
        obj->LoadFromCHRArchive(&info);
        _Z24BackupPairTables0207dfacPc(tables);
        pos = hero->obj3D_.position_;
        pos.y = 0;
        scale.y = 0x300;
        scale.x = scale.z = 0x96;
        obj->position_ = pos;
        obj->SetScale(&scale);
        obj->MakeVisible();
        obj->EnableFlag(0x180);
        RegisterCombatantSlot(state, 0xcc, (GameObject*)obj);
        state->GetGameObjectByIndex(0xcd);

        file = LoadFileIntoNewAllocation(data_020f1c51, *alloc, &size);
        if (file == NULL) {
            return;
        }
        obj = (Object3D*)alloc->Allocate(0xac);
        if (obj == NULL) {
            return;
        }
        obj->Initialize();
        ClearEightWords((struct Struct_203dafc*)&info);
        _Z25RestorePairTables0207df90Pc(tables);
        info.unk_8 = size;
        info.fileData = file;
        info.allocator = alloc;
        obj->LoadFromCHRArchive(&info);
        _Z24BackupPairTables0207dfacPc(tables);
        pos = hero->obj3D_.position_;
        pos.y = 0;
        scale.y = 0x300;
        scale.x = scale.z = 0x96;
        obj->position_ = pos;
        obj->SetScale(&scale);
        obj->MakeVisible();
        obj->EnableFlag(0x180);
        RegisterCombatantSlot(state, 0xcd, (GameObject*)obj);

        func_020adfa8(prop);
        SafeAllocator* subAlloc = (SafeAllocator*)alloc->Allocate(0x14);
        subAlloc->ResetAllocatorPointer();
        subAlloc->CreateTypeA(alloc->Allocate(0x3c00), 0x3c00);
        _Z37ResetContainerAndHandleFields020da1acPv(&data_ov017_021d82fc);
        data_ov017_021d82fc.allocator = subAlloc;
        data_ov017_021d82fc.tables = tables;
    }
}
