#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/AllocatorUnion.h"
#include "Resource/Brightness.h"

struct Obj020397cc;
struct Base02010834;
struct Foo0207df50 { unsigned int words[28]; };
struct ResourceState021a6c2c { char pad0[0xc40]; Foo0207df50 effectFields; };
struct Dispatcher021a6c2c { unsigned char fields[0xd0]; };
struct Zone021a6c2c {
    unsigned short id;
#if defined(jpn)
    char pad2[0x64 - 2];
#else
    char pad2[0x44 - 2];
#endif
    int originX, originZ;
#if defined(jpn)
    char pad4c[0x27f4 - 0x6c];
#else
    char pad4c[0x27b4 - 0x4c];
#endif
    short field27b4;
    char pad27b6[0x12]; int encounterX, encounterZ;
};
struct Actor021a6c2c {
    Object3D object; char padac[0xe0 - 0xac]; unsigned char flags;
};
struct Encounter021a6c2c {
    unsigned short id; unsigned char active, pad3, field4, field5, field6, field7;
    unsigned char field8, field9, fielda; signed char fieldb; unsigned char fieldc, padd[3];
    int x, y, z; short field1c, field1e; int fields20[4];
    char pad30[0x3c]; short field6c; short pad6e;
};
struct Entry021a6c2c {
    unsigned char kind; char pad1[15]; unsigned char enabled;
    unsigned char bit0:1, bit1:1, bit2:1, bit3:1, bit4:1, bit5:1, bit6:1, bit7:1;
    unsigned short field12; short field14, field16, field18, field1a, field1c, pad1e;
    int fields20[3]; Vector3fix position; int fields38[3]; Vector3fix scale;
};
struct Event021a6c2c {
    unsigned char pad0, done; char pad2[6]; int stage, timer;
    unsigned char special; char pad11[0x1f]; SafeAllocator allocator; int task;
};
extern "C" void* func_02057924();
extern "C" void* func_0202ae18();
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" Zone021a6c2c* func_02012fe4();
extern "C" void func_020a0cc4(unsigned int);
extern "C" void _Z36CheckAndEnqueueTag_021d1cb8_021d1cb8v();
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc*, int);
void* AllocateAligned4(AllocatorUnion*, unsigned int);
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(Foo0207df50*);
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void func_02057e6c(void*, int, SafeAllocator*, void*, unsigned int, Foo0207df50*);
extern "C" void _Z25ForwardField0xc0_0205ebecPv(void*);
extern "C" void _Z34CopyCountedBytesToIntArray02010834P12Base02010834iPiS1_(Base02010834*, int, int*, int*);
extern "C" void _Z26FindNodeAndProcess02057fb4Pvii(void*, int, int);
extern "C" void _Z26SetForwardAndStore0205ebc0Pvii(void*, int, int);
extern "C" void _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(void*, int, int);
int GetByte0x26c(char*);
void* GetField0x3f8Address(GameState*);
#if defined(jpn)
#define func_ov017_021a7280 func_ov017_021a7c28
#define data_ov017_021d777c data_ov017_021d7bb8
#endif
extern "C" void func_ov017_021a7280(Event021a6c2c*);
extern char data_ov017_021d777c[];
extern AllocatorUnion data_02114e20;
extern Dispatcher021a6c2c data_02108760;
static inline ResourceState021a6c2c* ResourceStateBuffer021a6c2c(GameResources* resources) {
    return (ResourceState021a6c2c*)resources->unknown_2cc;
}

// USA: func_ov017_021a6c2c
extern "C" ARM void func_ov017_021a6c2c(Event021a6c2c* self) {
    GameState* game = GameState::GetInstance();
    GameObject* leader = game->GetUnknownGameObject();
    GameResources* resources = func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* manager = func_02057924();
    func_0202ae18();
    _Z26GetGlobalField0x1c020421a0v();
    Zone021a6c2c* zone = func_02012fe4();
    if (self->stage == 0) {
        if (self->special) {
            Vector3fix position = game->GetUnknownGameObject()->obj3D_.position_;
            int id = zone->id;
            if (id >= 0x4e20 && id <= 0x752f) {
                zone->encounterX = position.x + zone->originX;
                zone->encounterZ = position.z + zone->originZ;
            } else {
                zone->encounterX = zone->originX;
                zone->encounterZ = zone->originZ;
            }
        }
        func_020a0cc4(0x7000);
        if (zone->id != 0x4e27) {
            if (zone->id == 0x4e42) zone->field27b4 = 4;
        } else zone->field27b4 = 2;
        _Z36CheckAndEnqueueTag_021d1cb8_021d1cb8v();
        _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)leader, 1);
        self->stage++;
    } else if (self->stage == 1) {
        self->task = loader->QueueLoadFile(data_ov017_021d777c, 0);
        self->stage++;
    } else if (self->stage == 2) {
        if (!loader->GetTaskStatus(self->task)) return;
        void* file; unsigned int length;
        loader->GetLoadedFileByID(self->task, &file, &length);
        self->allocator.CreateTypeA(AllocateAligned4(&data_02114e20, 0x7000), 0x7000);
        self->allocator.Reset();
        Foo0207df50* fields = &ResourceStateBuffer021a6c2c(resources)->effectFields;
        _Z26CopyInternalFields0207df50P11Foo0207df50(fields);
        void* data = self->allocator.Allocate(length);
        memcpy(data, file, length);
        CleanInvalidateCacheRange(data, length);
        func_02057e6c(manager, 13, &self->allocator, data, length, fields);
        loader->RemoveTask(self->task);
        self->task = -1; self->timer = 0; self->stage++;
    } else if (self->stage == 3) {
        self->timer += game->GetTickCount();
        if (self->timer <= 50) return;
        _Z25ForwardField0xc0_0205ebecPv(&data_02108760);
        int ids[4], count;
        _Z34CopyCountedBytesToIntArray02010834P12Base02010834iPiS1_((Base02010834*)game, leader->obj3D_.unknown_4_, ids, &count);
        Entry021a6c2c entries[4];
        for (int i = 0; i < count; i++) {
            GameObject* actor = game->GetGameObjectByIndex(ids[i]);
            if (!actor) continue;
            entries[i].kind = 0; entries[i].enabled = 1; entries[i].field12 = 0;
            entries[i].field14 = -1; entries[i].field16 = -1; entries[i].field18 = -1; entries[i].field1a = -1;
            entries[i].field1c = -0x1000;
            entries[i].fields20[0] = 0; entries[i].fields20[1] = 0; entries[i].fields20[2] = 0;
            entries[i].position.x = 0; entries[i].position.y = 0; entries[i].position.z = 0;
            entries[i].fields38[0] = 0; entries[i].fields38[1] = 0; entries[i].fields38[2] = 0;
            entries[i].scale.x = 0x1000; entries[i].scale.y = 0x1000; entries[i].scale.z = 0x1000;
            Entry021a6c2c* entry = &entries[i];
            Vector3fix* position = &actor->obj3D_.position_;
            entry->bit0 = 0; entry->bit1 = 0; entry->bit2 = 1; entry->bit3 = 0;
            entry->bit4 = 0; entry->bit5 = 0; entry->bit6 = 0; entry->bit7 = 0;
            entry->position = *position;
            entry->scale = actor->obj3D_.GetScale();
            _Z26FindNodeAndProcess02057fb4Pvii(manager, 13, (int)entry);
        }
        _Z26SetForwardAndStore0205ebc0Pvii(&data_02108760, 0xa2, 0xa2);
        _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(&data_02108760, 2, 0);
        self->timer = 0; self->stage++;
    } else if (self->stage == 4) {
        self->timer += game->GetTickCount();
        if (self->timer < 38) return;
        int ids[4], count;
        _Z34CopyCountedBytesToIntArray02010834P12Base02010834iPiS1_((Base02010834*)game, leader->obj3D_.unknown_4_, ids, &count);
        for (int i = 0; i < count; i++) {
            GameObject* actor = game->GetGameObjectByIndex(ids[i]);
            if (actor) actor->obj3D_.MakeHidden();
        }
        self->stage++;
    } else if (self->stage == 5) {
        self->timer += game->GetTickCount();
        if (self->timer < 80) return;
        SetBrightness(resources, -16, 30);
        self->stage++;
    } else if (self->stage == 6) {
        if (IsBrightnessTransitionActive(resources)) return;
        if (GetByte0x26c((char*)leader)) {
            SubBlock02038508* block = GetFieldPtrAt0x26c(leader);
            InitBlock02038508(block);
            ((Actor021a6c2c*)leader)->flags &= ~1;
            leader->obj3D_.DisableFlag(0x1180);
            func_ov017_021d3f00(block, 0, 1);
        }
        Encounter021a6c2c* encounter = (Encounter021a6c2c*)GetField0x3f8Address(game);
        VectorizedMemset(encounter, 0, 0x70);
        encounter->field4 = 1; encounter->field8 = 1; encounter->field9 = 1;
        encounter->fieldb = -1;
        encounter->fields20[0] = -1; encounter->fields20[1] = -1;
        encounter->fields20[2] = -1; encounter->fields20[3] = -1;
        encounter->field1e = -1; encounter->fieldc = 0; encounter->field6c = -1;
        encounter->active = 1; encounter->field7 = 1; encounter->field5 = 1;
        if (self->special) encounter->id = 0x2774;
        else {
            encounter->id = 0x1901; encounter->x = 0x14cc;
            encounter->y = 0x199; encounter->z = -0x1000;
        }
        int ids[4], count;
        _Z34CopyCountedBytesToIntArray02010834P12Base02010834iPiS1_((Base02010834*)game, leader->obj3D_.unknown_4_, ids, &count);
        for (int i = 0; i < count; i++) {
            GameObject* actor = game->GetGameObjectByIndex(ids[i]);
            if (actor) actor->obj3D_.MakeVisible();
        }
        func_ov017_021a7280(self); self->done = 1;
    }
}
