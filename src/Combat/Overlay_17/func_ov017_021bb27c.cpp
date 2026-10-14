#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"
#include "Memory/AllocatorUnion.h"

struct Flags02033fdc;
struct Foo02033b58;
struct Obj02033874;
struct FlagWord020466f4;
struct ListHead02046b60;
struct Actor021bb27c {
    Object3D object; char padac[0x15]; unsigned char state:2, rest:6;
    char padc2[0x1e]; unsigned char flags;
#if defined(jpn)
    char pade1[0x180 - 0xe1];
#else
    char pade1[0x18c - 0xe1];
#endif
    unsigned int field18c;
};
struct PartyState021bb27c { char pad0[0xf78]; unsigned char indices[4], count; };
struct Zone021bb27c {
#if defined(jpn)
    char pad0[0x2816];
#else
    char pad0[0x27d6];
#endif
    unsigned short key;
};
struct Encounter021bb27c { unsigned short key; unsigned char active; char pad3[0xb]; unsigned char fieldE; };
struct Detail021bb27c { unsigned short field0; unsigned char field2; };
struct Event021bb27c {
    char pad0[8]; unsigned short zone, mode; char padc[5]; unsigned char resetActor, resetAll;
    char pad13[3]; unsigned short kind, key;
#if defined(jpn)
    char pad1a[0x78 - 0x1a];
#else
    char pad1a[0x7c - 0x1a];
#endif
    SafeAllocator allocator;
    char pad90[0xa]; unsigned char field9a; char pad9b[0x34]; unsigned char fieldcf;
    char padd0[0x2d]; unsigned char fieldfd; char padfe; unsigned char fieldff;
    char pad100[4]; unsigned char field104; char pad105[3]; unsigned char field108;
    char pad109[3]; unsigned char field10c; char pad10d[9]; signed char actorIndex;
    char pad117[0xd]; SafeAllocator nestedAllocator; SafeAllocator* externalAllocator;
    char pad13c[0x38]; unsigned char actorMask, restoreMask;
};
struct ResourceKey021bb27c {
#if defined(jpn)
    char pad0[0x41fc];
#else
    char pad0[0x44ac];
#endif
    unsigned short key;
};
struct Bounds021bb27c { int zone; Vector3fix origin, extent, destination; };
int GetFieldIfFlag4_020100f8(char*);
extern "C" int* func_0202ae18();
extern "C" Zone021bb27c* func_02012fe4();
unsigned int GetBitsInField0_0203b4c4(unsigned int*, unsigned int);
void DestroyActiveAllocators_0215aa5c();
void ClearFlag0x4At0xe0(Flags02033fdc*);
void SetByteSavingPrevious(Foo02033b58*, unsigned char);
int GetByte0x26c_02039d7c(char*);
void SetVecYFromValue02033874(Obj02033874*, int);
int CheckField0NonZero_0202b7d8(int*);
void SetField0x158_02053ec8(void*, int);
void ResetTransformState02053f04(void*);
int GetField0x397cValue_020100b0(GameState*);
void ClearBitsInField4_0203b4e8(unsigned int*, unsigned int);
void ClearBitsInWord_0203b4b0(unsigned int*, unsigned int);
void TailForward02012da4(AllocatorUnion*, void*);
FlagWord020466f4* GetDataPtr02114e04_020d6c00();
void ClearFlags020466f4(FlagWord020466f4*, unsigned int);
extern "C" void func_ov017_02191fec(GameResources*, int);
void* GetField0x3f8Address_0200fd0c(GameState*);
int ListContainsId(ListHead02046b60*, int);
void SetCombatModeFromCase020dc2d0(int);
extern "C" void func_ov017_02190264(GameResources*, int);
extern "C" void func_ov017_0218f5a4(GameResources*, int, int, int, int);
void SetByteField0x253_020397c0(void*);
void SetField0x23cTrue_020a27ac(void*);
extern "C" void func_ov017_021921fc(const Vector3fix*, int, int);
void EnqueueEventTag150_021d035c(unsigned char, unsigned char, unsigned char);
int GetByteFieldMasked0x1ce_02039790(void*, int);
extern "C" void func_ov017_021bd4d0(Event021bb27c*, unsigned char, int, int);
#if defined(jpn)
#define data_ov017_021d7d6c data_ov017_021d8544
#define data_ov017_021d7d72 data_ov017_021d854a
#define data_ov017_021d6c20 data_ov017_021d7018
#endif
extern const char data_ov017_021d7d6c[], data_ov017_021d7d72[];
extern AllocatorUnion data_02114e20;
extern const Bounds021bb27c data_ov017_021d6c20[3];

static inline Detail021bb27c* GetEncounterDetail(GameResources* resources) {
    return (Detail021bb27c*)resources->unknown_ptr_3718;
}

// USA: func_ov017_021bb27c
extern "C" ARM void func_ov017_021bb27c(Event021bb27c* self) {
    int* search;
    GameState* game = GameState::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    ListHead02046b60* list = (ListHead02046b60*)resources->unknown_ptr_array_36fc[0];
    Detail021bb27c* detail = GetEncounterDetail(resources);
    GameObject* leader = game->GetUnknownGameObject();
    void* controlled = (void*)GetFieldIfFlag4_020100f8((char*)game);
    search = func_0202ae18();
    Zone021bb27c* zone = func_02012fe4();
    if (!GetBitsInField0_0203b4c4(&resources->brightnessFlags_0, 0x1000)) {
        DestroyActiveAllocators_0215aa5c();
    }
    if (self->zone == 0x7343 || self->zone == 0x7346 || self->zone == 0x7349) zone->key = self->zone;
    for (int i = 0; i < 4; i++) {
        GameObject* actor = game->GetPartyMemberByIndex(i);
        if (!actor) continue;
        ClearFlag0x4At0xe0((Flags02033fdc*)actor);
        SetByteSavingPrevious((Foo02033b58*)actor, 0);
        if (!GetByte0x26c_02039d7c((char*)actor) || GetFieldPtrAt0x26c_020399a8(actor)->command != 2) {
                actor->obj3D_.MaybeSetRegularAnimation(data_ov017_021d7d6c, 0x10);
        } else if (self->resetActor) {
                ((Actor021bb27c*)actor)->flags &= ~1;
                actor->obj3D_.DisableFlag(0x1180);
                InitBlock02038508(GetFieldPtrAt0x26c_020399a8(actor));
                actor->obj3D_.MaybeSetRegularAnimation(data_ov017_021d7d6c, 0x10);
        } else actor->obj3D_.MaybeSetRegularAnimation(data_ov017_021d7d72, 0);
        SetVecYFromValue02033874((Obj02033874*)actor, actor->obj3D_.rotation_.y);
        actor->obj3D_.DisableFlag(0x10);
    }
    if (CheckField0NonZero_0202b7d8(search)) {
        PartyState021bb27c* party = (PartyState021bb27c*)GetPtrField0x2a04_02010828(game);
        for (int i = 0; i < party->count; i++) {
            Actor021bb27c* actor = (Actor021bb27c*)GetCombatantWithFlag0x100_0200ff1c(game, party->indices[i]);
            if (actor) { SetField0x158_02053ec8(actor, 0); ResetTransformState02053f04(actor); }
        }
        if (self->resetAll) {
            GetField0x397cValue_020100b0(game);
            for (int i = 0; i < 4; i++) {
                Actor021bb27c* actor = (Actor021bb27c*)GetCombatantWithFlag0x100_0200ff1c(game, i);
                if (actor) {
                    actor->state &= ~1; actor->state &= ~2; actor->field18c &= ~2;
                }
            }
        }
        if (self->actorIndex >= 0) {
            Actor021bb27c* actor = (Actor021bb27c*)GetCombatantWithFlag0x100_0200ff1c(game, self->actorIndex);
            if (actor) {
                actor->state &= ~1; actor->state &= ~2; actor->field18c &= ~2;
            }
        }
    }
    if (resources) {
        ClearBitsInField4_0203b4e8(&resources->brightnessFlags_0, 0x1040);
        ClearBitsInWord_0203b4b0(&resources->brightnessFlags_0, 0x10);
        ClearBitsInWord_0203b4b0(&resources->brightnessFlags_0, 0x800);
        ClearBitsInWord_0203b4b0(&resources->brightnessFlags_0, 0x4000);
    }
    void* allocation = self->nestedAllocator.GetSignedAllocator();
    if (allocation) { self->nestedAllocator.Destroy(); self->allocator.Free(allocation); }
    if (!GetBitsInField0_0203b4c4(&resources->brightnessFlags_0, 0x1000)) {
        allocation = self->allocator.GetSignedAllocator();
        if (allocation) { self->allocator.Destroy(); TailForward02012da4(&data_02114e20, allocation); }
    }
    if (self->externalAllocator) {
        allocation = self->externalAllocator->GetSignedAllocator();
        if (allocation) { self->externalAllocator->Destroy(); TailForward02012da4(&data_02114e20, allocation); }
        self->externalAllocator = 0;
    }
    ClearFlags020466f4(GetDataPtr02114e04_020d6c00(), 0x20000);
    for (int i = 0; i < 4; i++) func_ov017_02191fec(resources, i);
    ClearFlags020466f4(GetDataPtr02114e04_020d6c00(), 0x400f);
    Encounter021bb27c* encounter = (Encounter021bb27c*)GetField0x3f8Address_0200fd0c(game);
    if (self->field104 && !detail->field2 && (!encounter->active || self->field10c) &&
        !ListContainsId(list, 10) && !(self->kind == 1 && self->fieldcf == 2)) {
        SetCombatModeFromCase020dc2d0(0);
    }
    self->fieldff = 1;
    for (int i = 0; i < 4; i++) {
        if (self->actorMask & (1 << i)) func_ov017_02190264(resources, i);
        if (self->restoreMask & (1 << i)) func_ov017_0218f5a4(resources, i, 0, 0, 1);
    }
    if (leader) SetByteField0x253_020397c0(leader);
    if (controlled) SetField0x23cTrue_020a27ac(controlled);
    const Bounds021bb27c* bounds = data_ov017_021d6c20;
    for (int i = 0; i < 3; i++, bounds++) {
        if (bounds->zone != self->zone) continue;
        GameObject* actor = game->GetUnknownGameObject();
        Vector3fix position = actor->obj3D_.position_;
        if (fix32abs(position.x - bounds->origin.x) > bounds->extent.x) break;
        if (fix32abs(position.y - bounds->origin.y) > bounds->extent.y) break;
        if (fix32abs(position.z - bounds->origin.z) > bounds->extent.z) break;
        func_ov017_021921fc(&bounds->destination, actor->obj3D_.rotation_.y, 0); break;
    }
    self->fieldcf = 0xff; self->field9a = 0;
    ResourceKey021bb27c* resourceKey = (ResourceKey021bb27c*)resources;
    if (self->key == resourceKey->key) resourceKey->key = 0;
    if (CheckField0NonZero_0202b7d8(search)) {
        if (self->mode <= 2 && self->fieldfd) return;
        Encounter021bb27c* encounter = (Encounter021bb27c*)GetField0x3f8Address_0200fd0c(game);
        if (encounter->active && self->field108) encounter->fieldE = 1;
        else EnqueueEventTag150_021d035c(0, GetField0x397cValue_020100b0(game), self->field108);
        for (int i = 0; i < 4; i++) {
            GameObject* actor = game->GetPartyMemberByIndex(i);
            if (actor && GetByteFieldMasked0x1ce_02039790(actor, 0x20)) func_ov017_021bd4d0(self, i, 0, 0);
        }
    }
}
