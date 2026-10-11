#include <globaldefs.h>
#include "GameState/GameState.h"

struct ListHead02046b38;
struct ListNode02046b38;
struct PairStruct;
struct Obj02033874;
struct S02076cc4;
struct Bytes02033b88;
struct Dst020795e8;
struct Src020795e8;
struct EntryTable0209bd94 { char storage_[4]; };
struct MonsterDefinition {
    unsigned short id_;
    unsigned short category_ : 2;
    unsigned short unused_ : 14;
#if defined(jpn)
    char pad4[0x5c - 4];
#else
    char pad4[0x60 - 4];
#endif
    EntryTable0209bd94 entries_;
    char pad64[0x304 - 0x64];
    char nodes_[4];
};
struct SubEntry0209be84 { unsigned short id_; short scale_; };
struct MonsterUpdate {
    unsigned char flags_; unsigned char pad1; unsigned short id_;
    unsigned short field4_; unsigned short zone_;
    unsigned short slot_ : 4; unsigned short unused_ : 3; unsigned short variant_ : 9;
    unsigned short monsterId_; unsigned char flagsC_; unsigned char fieldD_;
    unsigned short fieldE_; unsigned short field10_; char pad12[2];
    short angle_; short x_; short y_; short z_; unsigned char mode_;
};
struct MonsterFields {
    Object3D object_;
    char padAC[0xb8 - 0xac]; unsigned short fieldB8_;
    char padBA[0x164 - 0xba];
    unsigned short field164_; unsigned short field166_; unsigned short variant_; unsigned short field16A_;
    char pad16C[0x17d - 0x16c]; unsigned char flags17D_;
};
struct WorldResources { char pad0[0x660]; char field660_[4]; };
struct WorldState {
#if defined(jpn)
    char pad0[0x2980]; WorldResources resources_;
#else
    char pad0[0x2b90]; WorldResources resources_;
#endif
    char pad31F4[0x36fc - 0x31f4]; ListHead02046b38* list_;
    char pad3700[0x3718 - 0x3700]; ListNode02046b38* node_;
};
struct ZoneState { unsigned short zone_; };
extern "C" ZoneState* func_02012fe4();
void* GetEntryTableBase();
extern "C" MonsterDefinition* _Z28FindEntryByCurrentId02027cb0v();
extern "C" void func_02076a8c(GameObject*);
int ListContainsNode(ListHead02046b38*, ListNode02046b38*);
extern "C" PairStruct* _Z30FindCombatantByField2_021a2738Pvi(void*, int);
void CopyPairAndStoreField(PairStruct*, PairStruct*);
extern "C" int func_02018fbc(ZoneState*, Vector3i*);
extern "C" SubEntry0209be84* _Z20FindSubEntry0209be84P18EntryTable0209bd94ji(EntryTable0209bd94*, unsigned int, int);
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(Obj02033874*, int);
void SetField0x16c(S02076cc4*, int);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
extern "C" void _Z18TrySetMode02076cccPvi(void*, int);
extern "C" void func_0207964c(GameObject*);
Src020795e8* FindNodeBySignedId(void*, int);
extern "C" void _Z21CopyBitFields020795e8P11Dst020795e8P11Src020795e8(Dst020795e8*, Src020795e8*);

// JPN: func_ov017_021d4af8
// USA: func_ov017_021d46a4
extern "C" ARM void func_ov017_021d46a4(void*, MonsterUpdate* update) {
    if (!(update->flags_ & 1)) return;
    if (!(update->flags_ & 2)) return;
    update->flags_ = 0;
    update->id_ = 0;
    GameState* state = GameState::GetInstance();
    WorldState* world = (WorldState*)func_ov017_0218b5b0();
    ZoneState* zone = func_02012fe4();
    GetEntryTableBase();
    ListHead02046b38* list = world->list_;
    MonsterDefinition* definition;
    int index;
    GameObject* actor;
    ListNode02046b38* node = world->node_;
    if (update->zone_ != zone->zone_) return;
    definition = _Z28FindEntryByCurrentId02027cb0v();
    if (!definition) return;
    index = definition->category_ * 12 + 0x70 + update->slot_;
    actor = state->GetMaybeFieldMonsterByIndex(index);
    if (!actor) return;
    func_02076a8c(actor);
    if (!ListContainsNode(list, node)) {
        PairStruct* previous = _Z30FindCombatantByField2_021a2738Pvi(world, update->monsterId_);
        if (previous) CopyPairAndStoreField(previous, (PairStruct*)actor);
    }
    Vector3i position;
    position.x = update->x_ << 7;
    position.y = update->y_ << 7;
    position.z = update->z_ << 7;
    if (update->zone_ == zone->zone_) position.y = func_02018fbc(zone, &position);
    int scale = 0x1000;
    SubEntry0209be84* entry = _Z20FindSubEntry0209be84P18EntryTable0209bd94ji(&definition->entries_, update->monsterId_, update->variant_);
    if (entry) scale = entry->scale_;
    scale = (scale * 266LL + 0x800) >> 12;
    actor->obj3D_.unknown_4_ = index;
    actor->obj3D_.unknown_2_ = update->monsterId_;
    actor->obj3D_.SetField06(update->zone_);
    actor->obj3D_.position_ = position;
    _Z24SetVecYFromValue02033874P11Obj02033874i((Obj02033874*)actor, update->angle_);
    actor->obj3D_.SetScale(scale, scale, scale);
    WorldResources* const resources = &world->resources_;
    SetField0x16c((S02076cc4*)actor, (int)resources->field660_);
    MonsterFields* fields = (MonsterFields*)actor;
    fields->field16A_ = update->field4_;
    fields->variant_ = update->variant_;
    SetByte0xbeShiftPrev((Bytes02033b88*)actor, 0);
    fields->flags17D_ |= update->flagsC_;
    fields->fieldB8_ = update->fieldE_;
    fields->field164_ = update->field10_;
    fields->field166_ = update->fieldD_;
    _Z18TrySetMode02076cccPvi(actor, update->mode_);
    func_0207964c(actor);
    Src020795e8* saved = FindNodeBySignedId(definition->nodes_, (short)update->monsterId_);
    if (saved) _Z21CopyBitFields020795e8P11Dst020795e8P11Src020795e8((Dst020795e8*)actor, saved);
}
