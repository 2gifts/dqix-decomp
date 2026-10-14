#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "World/Zone3D.h"
#include "World/ZoneTerrain.h"

struct GameResources;

typedef Vector3i Vec3;

struct PartyEntry {
    Vec3 pos;
    short angle;
    short pad;
};

struct InfoBlock {
    char pad0[4];
    unsigned char flag4;
    char pad1[2];
    unsigned short id8;
    int modeC;
    char pad2[0x2a - 0x10];
    signed char partyIdx;
};

struct Actor {
    unsigned short flags;
    char pad0[0x44 - 2];
    Vec3 pos;
    Vec3 rot;
#if defined(jpn)
    char pad1[0x150 - 0x5c];
#else
    char pad1[0x15c - 0x5c];
#endif
    int f15c;
    Vec3 savedPos;
    Vec3 savedRot;
};

struct SlotEnt {
    int idx;
    int size;
    int type;
};

struct SlotTable {
#if defined(jpn)
    SlotEnt e[4];
#else
    SlotEnt e[5];
#endif
};

struct EntryInfo {
    unsigned short w0;
    unsigned short kind : 2;
    unsigned short pad : 14;
};

struct PtrBlock {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct InitState0208f7ecStruct {
    int field0;
    int field4;
    char pad8[0xb4 - 8];
    unsigned char b4;
    unsigned char b5;
    signed char b6;
    signed char b7;
    signed char b8;
    char padb9;
    unsigned short ba;
    signed char bc;
    signed char& ByteB6() { return b6; }
};

static inline InitState0208f7ecStruct& GetInitState(Zone3D& zone) {
    return *(InitState0208f7ecStruct*)zone.unk_2664;
}

struct BlkSub {
    char data[0x48];
};

struct BattleBlk {
    char data[0x68];
    BlkSub sub;
};

struct Lighting {
    char pad[0x94];
    float value;
    int mode;
};

struct Overlay {
    char pad0[0x38];
    int alloc;
};

struct GameStateBlk {
#if defined(jpn)
    char pad[0x5000 + 0x4c8];
#else
    char pad[0x5000 + 0x728];
#endif
    unsigned char b728;
};

struct AllocSlot {
    char b[0x14];
};

struct FieldData {
    int w[3];
};

struct CombatRoot {
    unsigned int savedPlanes;
    char pad0[4];
#if defined(jpn)
    char allocatorStorage[0x210];
#else
    AllocSlot allocs[0x21];
#endif
    int f29c;
    InfoBlock* info;
    void* f2a4;
#if defined(jpn)
    char pad1[0xb94 - 0x224];
    char sub_c18[0xd9c - 0xb94];
#else
    char pad1[0xc18 - 0x2a8];
    char sub_c18[0xe20 - 0xc18];
#endif
    int fe20;
    unsigned char fe24;
#if defined(jpn)
    char pad2[0x5918 - 0xda1];
#else
    char pad2[0x5728 - 0xe25];
#endif
    FieldData fd[4];
#if defined(jpn)
    char pad3[0x5b00 - 0x5918 - 0x30];
#else
    char pad3[0x5910 - 0x5728 - 0x30];
#endif
    PartyEntry party[4];
#if defined(jpn)
    char pad4[0x79e0 - 0x5b40];
#else
    char pad4[0x77f0 - 0x5950];
#endif
    int f77f0;
};

extern "C" int _ZN9GameState11GetInstanceEv();
extern "C" int _ZN16BackgroundLoader11GetInstanceEv();
extern "C" int func_0202ae18(int);
extern "C" GameResources* func_ov017_0218b5b0();
int FindEntryByCurrentId02027cb0();
PtrBlock* GetPtrField0x2a04(GameState*);
extern "C" Actor* _ZN9GameState14GetProtagonistEv(int gs);
Actor* FindCombatantByField16a_021a278c(void*, int);
extern "C" int _ZN9GameState20GetUnknownGameObjectEv(int gs);
extern "C" Actor* _ZN9GameState21GetPartyMemberByIndexEi(int gs, int idx);
int TestBitAt0x34(unsigned char*, unsigned int);
int GetByte0x26c(char*);
struct Obj02039d84;
void ResetObjectState02039d84(Obj02039d84*);
void EnqueueEventTag60Field_021d440c(int i);
void ClearField0xc4KeepBit0x8000(unsigned char*);
void ClearFlag0x1ceBit0x4(unsigned char*);
int GetSignedByte0x1ca(void*);
extern "C" Actor* _ZN9GameState31GetMaybeWanderingMonsterByIndexEi(int gs, int idx);
void Vector3fixMultiplyScalar(const Vec3* v, int s, Vec3* out);
extern "C" void _Z21AimAndSetVecY020338d4P14Struct020338d4P4Vec3(Actor* a, Vec3* v);
void EnqueueEventTag20_021cee78(int id, unsigned char v);
void SetField0x158(void*, int);
int CheckField0NonZero(int*);
struct SearchStruct0202c1a4;
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
void TrySetMode02076ccc(void*, int);
extern "C" void func_02076a8c(Actor* a);
void ResetOverlayAndAllocator_0219bf74();
extern "C" void func_ov017_0219bd1c(int a, int b, int c, int d);
struct Field3f8* GetField0x3f8Address(GameState*);
int GetField0x3acValue(GameState*);
void ClearSlotsAndProcess_021a27e8(void* controller);
extern "C" void func_ov017_0219b938(int ov);
extern "C" Actor* _ZN9GameState27GetMaybeFieldMonsterByIndexEi(int gs, int idx);
int GetGlobalPtr021075f4();
int GetField0x8c(void*);
void SetCombatWorkFlags0x55f4(void*, int);
struct Struct_0203cfb4;
void Init0203cfb4(Struct_0203cfb4*);
extern "C" void func_ov017_021a316c(int ov);
void SetBitsInField4(unsigned int*, unsigned int);
void SetBitsInWord(unsigned int*, unsigned int);
void SetBitsInField8(unsigned int*, unsigned int);
void ClearBitsInWord(unsigned int*, unsigned int);
void GetField02163524(void*);
extern "C" void func_ov000_0216d2d0(void* p);
void SetIntField540_0216f700(void* p, int v);
struct AngleTrig0202e9a4;
void SetAngleAndTrigTable0202e9a4(AngleTrig0202e9a4*, int);
void SetField0x3b0Value(GameState*, int);
extern "C" void func_020134e0(void* p);
void ResetTaskAndDestroyAllocators_021a050c(GameResources* resources);
int GetFieldB08_0219e008(void*);
void DestroyAllocatorsFromTable_021a1114(char*);
extern "C" void func_ov017_021a07f4(int ov);
void SetFieldB08_0219dffc(void*, int);
extern "C" int _ZN13SafeAllocator8AllocateEj(void* a, unsigned int size);
struct Field0x19cData;
void SetAndClearField0x19c(char*, Field0x19cData*);
extern "C" void func_ov000_02161300(CombatRoot* c, int i);
void SetFlag0x1ceBit0x1(unsigned char*);
extern "C" int func_0202c540(int p);
extern "C" void func_ov017_0219c774(int a, int b, int c);
extern "C" Lighting* _ZN15LightingManager11GetInstanceEv();
void EnqueueEventTag147_021cdaa0();
extern "C" void _ZN9GameState12SetTimeOfDayE9TimeOfDay(int gs, int t);
void LoadBattleBlock020ac4c0(void*);
struct S_a07e0;
void AddClamped24BitFieldAt0x3c(S_a07e0*, unsigned int);
struct S_a00d4;
void AddClamped16BitFieldAt0x10(S_a00d4*, unsigned int);
void CopyInBattleField0x7540(void*);
void SetField0x5729Value(char*, unsigned char);
extern "C" void func_ov017_021c894c(int a);
extern "C" void func_ov017_021c8758(int a);
extern "C" void func_ov017_021c8654();
extern "C" void func_ov017_021c847c();
void ClearGlobalBuffer02107850();

extern SlotTable data_ov000_02183034;
extern float data_ov000_021838e8[5];
extern float data_ov000_0218423c[5];

// USA: func_ov000_021643d4
extern "C" ARM void func_ov000_021643d4(CombatRoot* c) {
    int gs = _ZN9GameState11GetInstanceEv();
    int search = func_0202ae18(_ZN16BackgroundLoader11GetInstanceEv());
    GameResources* resources = func_ov017_0218b5b0();
    int ov = (int)resources;
    EntryInfo* entry = (EntryInfo*)FindEntryByCurrentId02027cb0();
    Zone3D* obj14 = func_02012fe4();
    PtrBlock* pb = GetPtrField0x2a04((GameState*)gs);
    Actor* hero = _ZN9GameState14GetProtagonistEv(gs);
    Actor* enemy = FindCombatantByField16a_021a278c((void*)ov, c->info->id8);
    _ZN9GameState20GetUnknownGameObjectEv(gs);
    Actor* leader = _ZN9GameState21GetPartyMemberByIndexEi(gs, c->info->partyIdx);
    c->savedPlanes = (*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8;
    {
        volatile unsigned int* reg = (volatile unsigned int*)0x4001000;
        unsigned int planes = (*reg & 0x1f00) >> 8;
        *reg = (*reg & ~0x1f00) | ((planes & ~0x10) << 8);
    }
    for (int i = 0; i < 4; i++) {
        if (!TestBitAt0x34((unsigned char*)c->info, (unsigned char)i)) continue;
        Actor* m = _ZN9GameState21GetPartyMemberByIndexEi(gs, i);
        if (!m) continue;
        if (GetByte0x26c((char*)m)) {
            ResetObjectState02039d84((Obj02039d84*)m);
            EnqueueEventTag60Field_021d440c(i);
            if (leader) {
                m->pos = leader->pos;
            }
        }
        c->party[i].pos = m->pos;
        c->party[i].angle = m->rot.y;
        ClearField0xc4KeepBit0x8000((unsigned char*)m);
        ((Object3D*)m)->SetInheritedAlpha(0x1f);
        ClearFlag0x1ceBit0x4((unsigned char*)m);
        if (c->info->modeC == 0x1b) {
            Actor* o = _ZN9GameState21GetPartyMemberByIndexEi(gs, 0);
            if (!o) continue;
            if (**(unsigned int**)((char*)o + 0x130) & 1) {
                o = _ZN9GameState21GetPartyMemberByIndexEi(gs, (short)GetSignedByte0x1ca(o));
                if (!o) {
                    o = _ZN9GameState21GetPartyMemberByIndexEi(gs, 0);
                }
            }
            c->party[i].pos = o->pos;
            c->party[i].angle = o->rot.y;
            m->pos = o->pos;
            m->rot = o->rot;
        }
    }
    if (enemy) {
        Vec3 ep = enemy->pos;
        for (int j = 0; j < pb->count; j++) {
            int id = pb->ids[j];
            Actor* mon = _ZN9GameState31GetMaybeWanderingMonsterByIndexEi(gs, id);
            if (!mon) continue;
            if (c->info->flag4 == 0) {
                Vec3 mp = mon->pos;
                Vec3 dir, off;
                Vector3fix_Subtract(&ep, &mp, &dir);
                Vector3fix_Normalize(&dir, &dir);
                int dist = Vector3fix_Distance(&ep, &mp);
                int r = ((Object3D*)mon)->GetRadius();
                int half = (r + ((Object3D*)enemy)->GetRadius()) / 2;
                Vector3fixMultiplyScalar(&dir, dist - (half + 0x1000), &off);
                mp = func_02019210(obj14, &mp, &off, ((Object3D*)mon)->GetRadius() / 2);
                mp.y = func_02018fbc(obj14, &mp);
                mon->pos = mp;
            }
            _Z21AimAndSetVecY020338d4P14Struct020338d4P4Vec3(mon, &ep);
            EnqueueEventTag20_021cee78(id, 0);
        }
    }
    hero->savedPos = hero->pos;
    hero->savedRot = hero->rot;
    hero->f15c = ((Object3D*)hero)->GetField06();
    SetField0x158(hero, 1);
    if (enemy) {
        if (!CheckField0NonZero((int*)search) || !GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search)) {
            TrySetMode02076ccc(enemy, 9);
        } else {
            func_02076a8c(enemy);
            ((Object3D*)enemy)->MakeHidden();
        }
    }
    ResetOverlayAndAllocator_0219bf74();
    func_ov017_0219bd1c(0, 4, 1, 0);
    char* f3f8 = (char*)GetField0x3f8Address((GameState*)gs);
    int sel = GetField0x3acValue((GameState*)gs);
    *(Vec3*)(f3f8 + 0x10) = c->party[sel].pos;
    *(short*)(f3f8 + 0x1c) = c->party[sel].angle;
#if defined(jpn)
    unsigned int w = *(unsigned short*)(*(char**)((char*)ov + 0x3000 + 0x508) + 0x600 + 0xc4);
#else
    unsigned int w = *(unsigned short*)(*(char**)((char*)ov + 0x3000 + 0x718) + 0x600 + 0xc4);
#endif
    if (w) {
        char* p = (char*)GetField0x3f8Address((GameState*)gs);
        *(unsigned short*)p = w;
        p[0xa] = 0;
    }
    ClearSlotsAndProcess_021a27e8((void*)ov);
    func_ov017_0219b938(ov);
    for (int k = 0; k < 12; k++) {
        Actor* fm = _ZN9GameState27GetMaybeFieldMonsterByIndexEi(gs, k + (entry->kind * 12 + 0x70));
        if (fm) ((Object3D*)fm)->Destroy();
    }
    int glob = GetGlobalPtr021075f4();
    if (GetField0x8c((void*)glob) > 0) {
        SetCombatWorkFlags0x55f4(c, 0x1000);
    }
    Init0203cfb4((Struct_0203cfb4*)glob);
    func_ov017_021a316c(ov);
    SetBitsInField4((unsigned int*)ov, 0x80);
    SetBitsInField4((unsigned int*)ov, 4);
    SetBitsInField4((unsigned int*)ov, 0x10);
    GetField02163524(c);
    SetBitsInField4((unsigned int*)ov, 2);
    SetBitsInWord((unsigned int*)ov, 4);
    SetBitsInWord((unsigned int*)ov, 0x20);
    SetBitsInField4((unsigned int*)ov, 0x10);
    SetBitsInField4((unsigned int*)ov, 0x40);
    SetBitsInField4((unsigned int*)ov, 0x80);
    GetInitState(*obj14).ByteB6() = 0;
    SetBitsInField8((unsigned int*)ov, 4);
    func_ov000_0216d2d0(c->sub_c18);
    SetIntField540_0216f700(c->sub_c18, c->f29c);
    c->fe20 = 0x800;
    c->fe24 = 1;
    c->f2a4 = GetField0x3b0Value((GameState*)gs);
    if (c->f2a4) {
        SetAngleAndTrigTable0202e9a4((AngleTrig0202e9a4*)((int)c->f2a4), 0xf);
    }
    SetField0x3b0Value((GameState*)gs, (int)c->sub_c18);
#if defined(jpn)
    func_020134e0((char*)c + 0x244 + 0xc00);
#else
    func_020134e0((char*)c + 0x2c8 + 0xc00);
#endif
    ResetTaskAndDestroyAllocators_021a050c(resources);
    if (GetFieldB08_0219e008((void*)ov) == 4) {
        DestroyAllocatorsFromTable_021a1114((char*)ov);
        func_ov017_021a07f4(ov);
        SetFieldB08_0219dffc((void*)ov, 1);
    }
    SlotTable tbl = data_ov000_02183034;
    int size;
    for (int n = 0; (size = tbl.e[n].size) > 0; n++) {
        int idx = tbl.e[n].idx;
        int type = tbl.e[n].type;
        int buf = _ZN13SafeAllocator8AllocateEj((char*)ov + 0x38, size);
        if (type == 0) {
#if defined(jpn)
            ((SafeAllocator*)((AllocSlot*)((char*)c + 8) + idx))->CreateTypeA((void*)buf, size);
#else
            ((SafeAllocator*)&c->allocs[idx])->CreateTypeA((void*)buf, size);
#endif
        } else if (type == 1) {
#if defined(jpn)
            ((SafeAllocator*)((AllocSlot*)((char*)c + 8) + idx))->CreateTypeB((void*)buf, size, 4);
#else
            ((SafeAllocator*)&c->allocs[idx])->CreateTypeB((void*)buf, size, 4);
#endif
        }
    }
    for (int i = 0; i < 4; i++) {
        if (!TestBitAt0x34((unsigned char*)c->info, (unsigned char)i)) continue;
        Actor* m = _ZN9GameState21GetPartyMemberByIndexEi(gs, i);
        if (!m) continue;
        m->savedPos = m->pos;
        m->savedRot = m->rot;
        m->f15c = ((Object3D*)m)->GetField06();
        SetAndClearField0x19c((char*)m, (Field0x19cData*)&c->fd[i]);
        func_ov000_02161300(c, i);
        SetFlag0x1ceBit0x1((unsigned char*)m);
        if (m->flags & 0x1000) {
            SetField0x158(m, 1);
        }
    }
    if (!CheckField0NonZero((int*)search)) {
        SetCombatWorkFlags0x55f4(c, 2);
    } else if (GetField0x3acValue((GameState*)gs) == c->info->partyIdx) {
        SetCombatWorkFlags0x55f4(c, 2);
    }
    if (func_0202c540(search)) {
        func_ov017_0219c774(0, 1, 0);
    }
    Lighting* lm = _ZN15LightingManager11GetInstanceEv();
    float cur = lm->value;
    if (data_ov000_0218423c[3] - data_ov000_021838e8[4] < cur && cur < data_ov000_0218423c[3]) {
        lm->value = data_ov000_0218423c[3];
        lm->mode = 1;
    } else if (data_ov000_0218423c[2] - data_ov000_021838e8[4] < cur && cur < data_ov000_0218423c[2]) {
        lm->value = data_ov000_0218423c[2];
        lm->mode = 2;
    } else if (data_ov000_0218423c[1] - data_ov000_021838e8[4] < cur && cur < data_ov000_0218423c[1]) {
        lm->value = data_ov000_0218423c[1];
        lm->mode = 3;
    } else if ((data_ov000_0218423c[1] + data_ov000_021838e8[1]) - data_ov000_021838e8[4] < cur) {
        lm->value = data_ov000_0218423c[0];
        lm->mode = 0;
    }
    EnqueueEventTag147_021cdaa0();
    if (c->info->modeC == 0x1a) {
        _ZN9GameState12SetTimeOfDayE9TimeOfDay(gs, 3);
        lm->mode = 3;
    }
    ClearBitsInWord((unsigned int*)ov, 0x800);
    BattleBlk blk;
    LoadBattleBlock020ac4c0(&blk);
    AddClamped24BitFieldAt0x3c((S_a07e0*)&blk, 1);
    AddClamped16BitFieldAt0x10((S_a00d4*)&blk.sub, 1);
    CopyInBattleField0x7540(&blk);
    ((GameStateBlk*)gs)->b728 = 0;
    SetField0x5729Value((char*)gs, 0);
    func_ov017_021c894c(c->info->id8);
    func_ov017_021c8758(c->info->id8);
    func_ov017_021c8654();
    func_ov017_021c847c();
    c->f77f0 = -1;
    ClearGlobalBuffer02107850();
    SetCombatWorkFlags0x55f4(c, 1);
}
