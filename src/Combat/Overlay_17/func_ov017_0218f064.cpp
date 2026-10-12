#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>

struct Foo0207df50;
struct S021a11b4;
struct Obj02048104;
struct Obj02054664;
struct State020415d8;
struct Bytes02033b88;
struct T020545b8 {
    short id;
    unsigned short index;
    char pad_4[0x5d4];
    SafeAllocator allocator;
};
struct InternalBlock0218f064 { char bytes[0x70]; };
struct InternalOwner0218f064 { char pad_0[0x2cc]; InternalBlock0218f064 blocks[22]; };
struct DisposableOwner0218f064 { char pad_0[0x4334]; Object3D* first; Object3D* second; Object3D* third; Object3D* fourth; };
struct ZoneSpecial0218f064 { char pad_0[0xb58]; T020545b8* special; char* companion; };
struct ZoneOwner0218f064 { char pad_0[0x1840]; ZoneSpecial0218f064 tail; };
static inline ZoneSpecial0218f064* ZoneSpecials0218f064(Zone3D* zone) { ZoneSpecial0218f064* tail = &((ZoneOwner0218f064*)zone)->tail; return tail; }
struct Ticket0218f064 { char pad_0[0x10]; Vector3i position; short rotation; };
struct Combatant0218f064 {
    Object3D object;
    char pad_ac[4];
    unsigned short field_b0, field_b2, field_b4;
    char pad_b6[0x9e];
    T020545b8* entry;
    char pad_158[0x17a];
    unsigned char sequence;
};
struct Components0218f064 { Object3D objects[11]; };
Ticket0218f064* GetField0x3f8Address(GameState*);
extern "C" Zone3D* func_02012fe4();
extern "C" void func_0202ae18();
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(Foo0207df50*);
extern "C" void _Z25DestroyAllocators020545b8P9T020545b8(T020545b8*);
extern "C" void func_020542b4(T020545b8*, SafeAllocator*, InternalBlock0218f064*);
extern "C" int func_ov017_021925e0();
extern "C" T020545b8* _Z26FindNegativeEntry_021a11b4P9S021a11b4(S021a11b4*);
extern "C" void func_02054464(T020545b8*, SafeAllocator*, InternalBlock0218f064*);
extern "C" void func_02037d10(Combatant0218f064*);
extern "C" void _Z20SetFlag0x20002048104P11Obj02048104(Obj02048104*);
extern "C" void _Z27ResetSelectionState02054664P11Obj02054664(Obj02054664*);
extern "C" int _Z34GetMaxFieldPlus1_02192548_02192548v();
extern "C" void _Z18ResetState020415d8P13State020415d8(State020415d8*);
extern "C" void func_020c9be0();
void RegisterCombatantSlot(GameState*, int, GameObject*);
void StoreVec3AtField0x50(unsigned char*, int, int, int);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
extern "C" void _Z24SetPointerFields02053c4cPcS_(char*, char*);
extern "C" void _Z35RegisterOrAllocateCombatant02053c74Pci(char*, int);
extern "C" void _Z24SetLowNibble56b_0218f57cPvi(void*, int);
extern "C" int func_ov017_0218f5a4(GameResources*, int, int, int, int);
extern const char data_ov017_021d73a4[];

static inline InternalBlock0218f064* InternalBlocks0218f064(GameResources* resources) { InternalBlock0218f064* blocks = ((InternalOwner0218f064*)resources)->blocks; return blocks; }

// USA: func_ov017_0218f064
extern "C" ARM void func_ov017_0218f064(GameResources* resources, int id, int kind, int registerEffect, int mode) {
    GameState* game = GameState::GetInstance();
    Zone3D* zone;
    Ticket0218f064* ticket = GetField0x3f8Address(game);
    zone = func_02012fe4();
    func_0202ae18();
    int initialize = 1;
    SafeAllocator* allocator;
    T020545b8* entry;
    if (kind == 0x4000) {
        entry = ZoneSpecials0218f064(zone)->special;
        if (!entry) return;
        SafeAllocator* primaryAllocators = resources->allocator_array_1a0;
        SafeAllocator* specialAllocator = &primaryAllocators[3];
        allocator = &entry->allocator;
        InternalBlock0218f064* blocks = InternalBlocks0218f064(resources);
        specialAllocator->Reset();
        InternalBlock0218f064* block = &blocks[21];
        _Z26CopyInternalFields0207df50P11Foo0207df50((Foo0207df50*)block);
        _Z25DestroyAllocators020545b8P9T020545b8(entry);
        func_020542b4(entry, specialAllocator, block);
    } else {
        if (func_ov017_021925e0()) {
            for (int i = 0; i < 4; ++i) {
                if (((T020545b8*)&resources->substruct_array_12c8[i])->id == id) return;
            }
        }
        entry = _Z26FindNegativeEntry_021a11b4P9S021a11b4((S021a11b4*)resources);
        if (!entry) return;
        allocator = &entry->allocator;
        int index = entry->index + 1;
        SafeAllocator* primary = &resources->allocator_array_38[index];
        InternalBlock0218f064* block = &((InternalOwner0218f064*)resources)->blocks[index];
        _Z25DestroyAllocators020545b8P9T020545b8(entry);
        if (kind == 4) func_02054464(entry, primary, block);
        else func_020542b4(entry, primary, block);
    }
    DisposableOwner0218f064* disposable = (DisposableOwner0218f064*)resources;
    if (disposable->first) { disposable->first->Destroy(); disposable->first = 0; }
    if (disposable->second) { disposable->second->Destroy(); disposable->second = 0; }
    if (disposable->third) { disposable->third->Destroy(); disposable->third = 0; }
    if (disposable->fourth) { disposable->fourth->Destroy(); disposable->fourth = 0; }
    allocator->Reset();
    Combatant0218f064* combatant = 0;
    if (kind == 0x800) {
        combatant = (Combatant0218f064*)allocator->Allocate(0x2d0);
        func_02037d10(combatant);
    } else if (kind == 0x200) {
        combatant = (Combatant0218f064*)allocator->Allocate(0x2d0);
        _Z20SetFlag0x20002048104P11Obj02048104((Obj02048104*)combatant);
    } else if (kind == 0x1000) {
        combatant = (Combatant0218f064*)allocator->Allocate(0x2d4);
        _Z27ResetSelectionState02054664P11Obj02054664((Obj02054664*)combatant);
        if (combatant) combatant->sequence = _Z34GetMaxFieldPlus1_02192548_02192548v();
    } else if (kind == 0x4000) {
        combatant = (Combatant0218f064*)allocator->Allocate(0x2f8);
        _Z18ResetState020415d8P13State020415d8((State020415d8*)combatant);
    } else if (kind == 4) {
        combatant = (Combatant0218f064*)allocator->Allocate(0x2d4);
        _Z27ResetSelectionState02054664P11Obj02054664((Obj02054664*)combatant);
        if (combatant) combatant->sequence = _Z34GetMaxFieldPlus1_02192548_02192548v();
        initialize = 0;
    }
    if (!combatant) func_020c9be0();
    combatant->object.unknown_4_ = (short)id;
    combatant->entry = entry;
    entry->id = (short)id;
    RegisterCombatantSlot(game, id, (GameObject*)combatant);
    if (initialize) {
        Components0218f064* components = (Components0218f064*)allocator->Allocate(0x764);
        if (!components) func_020c9be0();
        components->objects[0].Initialize();
        components->objects[2].Initialize();
        components->objects[1].Initialize();
        components->objects[3].Initialize();
        components->objects[4].Initialize();
        components->objects[5].Initialize();
        Object3D* sixth = &components->objects[6];
        sixth->Initialize();
        Object3D* seventh = &components->objects[7];
        seventh->Initialize();
        components->objects[8].Initialize();
        Object3D* ninth = &components->objects[9];
        ninth->Initialize();
        Object3D* tenth = &components->objects[10];
        tenth->Initialize();
        int base = id * 12;
        RegisterCombatantSlot(game, base + 0x13, (GameObject*)&components->objects[0]);
        RegisterCombatantSlot(game, base + 0x14, (GameObject*)&components->objects[1]);
        RegisterCombatantSlot(game, base + 0x15, (GameObject*)&components->objects[2]);
        RegisterCombatantSlot(game, base + 0x16, (GameObject*)&components->objects[3]);
        RegisterCombatantSlot(game, base + 0x17, (GameObject*)&components->objects[5]);
        RegisterCombatantSlot(game, base + 0x18, (GameObject*)sixth);
        RegisterCombatantSlot(game, base + 0x19, (GameObject*)seventh);
        RegisterCombatantSlot(game, base + 0x1a, (GameObject*)&components->objects[8]);
        RegisterCombatantSlot(game, base + 0x1b, (GameObject*)&components->objects[4]);
        RegisterCombatantSlot(game, base + 0x1c, (GameObject*)ninth);
        RegisterCombatantSlot(game, base + 0x1d, (GameObject*)tenth);
    }
    combatant->field_b0 = 0x324;
    combatant->field_b4 = 0x189;
    combatant->object.SetHeight(0x1800);
    combatant->object.SetRadius(0x1000);
    combatant->object.MaybeSetRegularAnimation(data_ov017_021d73a4, 0);
    combatant->object.position_ = ticket->position;
    StoreVec3AtField0x50((unsigned char*)combatant, combatant->object.rotation_.x, ticket->rotation, combatant->object.rotation_.z);
    SetByte0xbeShiftPrev((Bytes02033b88*)combatant, 0);
    if (kind == 0x4000) {
        char* companion = ZoneSpecials0218f064(zone)->companion;
        if (companion) _Z24SetPointerFields02053c4cPcS_((char*)combatant, companion);
    } else _Z35RegisterOrAllocateCombatant02053c74Pci((char*)combatant, id);
    if (mode > 0) _Z24SetLowNibble56b_0218f57cPvi(combatant, mode);
    if (registerEffect) func_ov017_0218f5a4(resources, id, 0, 0, 0);
}
