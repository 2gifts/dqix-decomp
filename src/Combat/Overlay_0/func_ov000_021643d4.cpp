#include <globaldefs.h>



struct Vector3i {
    int x, y, z;
    Vector3i& operator=(const Vector3i& o);
};
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

struct Blk264 {
    char pad[0xb6];
    unsigned char b;
};

struct Blk2400 {
    char pad[0x2400];
    Blk264 z;
};

struct Obj14 {
    char pad[0x264];
    Blk2400 q;
};

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
    int f2a4;
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
extern "C" int func_ov017_0218b5b0();
extern "C" int _Z28FindEntryByCurrentId02027cb0v();
extern "C" int func_02012fe4();
extern "C" PtrBlock* _Z17GetPtrField0x2a04P9GameState(int gs);
extern "C" Actor* _ZN9GameState14GetProtagonistEv(int gs);
extern "C" Actor* _Z32FindCombatantByField16a_021a278cPvi(int ov, int id);
extern "C" int _ZN9GameState20GetUnknownGameObjectEv(int gs);
extern "C" Actor* _ZN9GameState21GetPartyMemberByIndexEi(int gs, int idx);
extern "C" int _Z13TestBitAt0x34Phj(InfoBlock* info, unsigned int idx);
extern "C" int _Z12GetByte0x26cPc(Actor* a);
extern "C" void _Z24ResetObjectState02039d84P11Obj02039d84(Actor* a);
extern "C" void _Z31EnqueueEventTag60Field_021d440ci(int i);
extern "C" void _Z27ClearField0xc4KeepBit0x8000Ph(Actor* a);
extern "C" void _ZN8Object3D17SetInheritedAlphaEi(Actor* a, int v);
extern "C" void _Z20ClearFlag0x1ceBit0x4Ph(Actor* a);
extern "C" int _Z18GetSignedByte0x1caPv(Actor* a);
extern "C" Actor* _ZN9GameState31GetMaybeWanderingMonsterByIndexEi(int gs, int idx);
extern "C" void Vector3fix_Subtract(const Vec3* a, const Vec3* b, Vec3* out);
extern "C" void Vector3fix_Normalize(Vec3* a, Vec3* out);
extern "C" int Vector3fix_Distance(const Vec3* a, const Vec3* b);
extern "C" int _ZNK8Object3D9GetRadiusEv(Actor* a);
extern "C" void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(const Vec3* v, int s, Vec3* out);
extern "C" Vec3 func_02019210(int a, const Vec3* b, const Vec3* c, int d);
extern "C" int func_02018fbc(int a, Vec3* v);
extern "C" void _Z21AimAndSetVecY020338d4P14Struct020338d4P4Vec3(Actor* a, Vec3* v);
extern "C" void _Z26EnqueueEventTag20_021cee78ih(int id, unsigned char v);
extern "C" int _ZNK8Object3D10GetField06Ev(Actor* a);
extern "C" void _Z13SetField0x158Pvi(Actor* a, int v);
extern "C" int _Z18CheckField0NonZeroPi(int p);
extern "C" int _Z30GetSearchStructCurrentArrEntryP20SearchStruct0202c1a4(int p);
extern "C" void _Z18TrySetMode02076cccPvi(Actor* a, int m);
extern "C" void func_02076a8c(Actor* a);
extern "C" void _ZN8Object3D10MakeHiddenEv(Actor* a);
extern "C" void _Z33ResetOverlayAndAllocator_0219bf74v();
extern "C" void func_ov017_0219bd1c(int a, int b, int c, int d);
extern "C" struct Field3f8* _Z20GetField0x3f8AddressP9GameState(int gs);
extern "C" int _Z18GetField0x3acValueP9GameState(int gs);
extern "C" void _Z29ClearSlotsAndProcess_021a27e8v(int ov);
extern "C" void func_ov017_0219b938(int ov);
extern "C" Actor* _ZN9GameState27GetMaybeFieldMonsterByIndexEi(int gs, int idx);
extern "C" void _ZN8Object3D7DestroyEv(Actor* a);
extern "C" int _Z20GetGlobalPtr021075f4v();
extern "C" int _Z12GetField0x8cPv(int p);
extern "C" void _Z24SetCombatWorkFlags0x55f4Pvi(CombatRoot* c, int f);
extern "C" void _Z12Init0203cfb4P15Struct_0203cfb4(int p);
extern "C" void func_ov017_021a316c(int ov);
extern "C" void _Z15SetBitsInField4Pjj(int ov, unsigned int bits);
extern "C" void _Z13SetBitsInWordPjj(int ov, unsigned int bits);
extern "C" void _Z15SetBitsInField8Pjj(int ov, unsigned int bits);
extern "C" void _Z15ClearBitsInWordPjj(int ov, unsigned int bits);
extern "C" void _Z16GetField02163524Pv(CombatRoot* c);
extern "C" void func_ov000_0216d2d0(void* p);
extern "C" void _Z23SetIntField540_0216f700Pvi(void* p, int v);
extern "C" int _Z18GetField0x3b0ValueP9GameState(int gs);
extern "C" void _Z28SetAngleAndTrigTable0202e9a4P17AngleTrig0202e9a4i(int p, int v);
extern "C" void _Z18SetField0x3b0ValueP9GameStatei(int gs, void* p);
extern "C" void func_020134e0(void* p);
extern "C" void _Z38ResetTaskAndDestroyAllocators_021a050cPc(int ov);
extern "C" int _Z20GetFieldB08_0219e008Pv(int ov);
extern "C" void _Z35DestroyAllocatorsFromTable_021a1114Pc(int ov);
extern "C" void func_ov017_021a07f4(int ov);
extern "C" void _Z20SetFieldB08_0219dffcPvi(int ov, int v);
extern "C" int _ZN13SafeAllocator8AllocateEj(void* a, unsigned int size);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void* a, int buf, unsigned int size);
extern "C" void _ZN13SafeAllocator11CreateTypeBEPvji(void* a, int buf, unsigned int size, int n);
extern "C" void _Z21SetAndClearField0x19cPcP14Field0x19cData(Actor* a, void* d);
extern "C" void func_ov000_02161300(CombatRoot* c, int i);
extern "C" void _Z18SetFlag0x1ceBit0x1Ph(Actor* a);
extern "C" int func_0202c540(int p);
extern "C" void func_ov017_0219c774(int a, int b, int c);
extern "C" Lighting* _ZN15LightingManager11GetInstanceEv();
extern "C" void _Z27EnqueueEventTag147_021cdaa0v();
extern "C" void _ZN9GameState12SetTimeOfDayE9TimeOfDay(int gs, int t);
extern "C" void _Z23LoadBattleBlock020ac4c0Pv(BattleBlk* b);
extern "C" void _Z26AddClamped24BitFieldAt0x3cP7S_a07e0j(BattleBlk* b, unsigned int v);
extern "C" void _Z26AddClamped16BitFieldAt0x10P7S_a00d4j(BlkSub* b, unsigned int v);
extern "C" void _Z23CopyInBattleField0x7540Pv(BattleBlk* b);
extern "C" void _Z19SetField0x5729ValuePch(int gs, unsigned char v);
extern "C" void func_ov017_021c894c(int a);
extern "C" void func_ov017_021c8758(int a);
extern "C" void func_ov017_021c8654();
extern "C" void func_ov017_021c847c();
extern "C" void _Z25ClearGlobalBuffer02107850v();

static inline char* Off264(int o) {
#if defined(jpn)
    return (char*)o + 0x2a4;
#else
    return (char*)o + 0x264;
#endif
}

static inline char* Off2400(char* p) {
    return p + 0x2400;
}

extern SlotTable data_ov000_02183034;
extern float data_ov000_021838e8[5];
extern float data_ov000_0218423c[5];

// USA: func_ov000_021643d4
// JPN: func_ov000_02165b38
extern "C" ARM void func_ov000_021643d4(CombatRoot* c) {
    int gs = _ZN9GameState11GetInstanceEv();
    int search = func_0202ae18(_ZN16BackgroundLoader11GetInstanceEv());
    int ov = func_ov017_0218b5b0();
    EntryInfo* entry = (EntryInfo*)_Z28FindEntryByCurrentId02027cb0v();
    int obj14 = func_02012fe4();
    PtrBlock* pb = _Z17GetPtrField0x2a04P9GameState(gs);
    Actor* hero = _ZN9GameState14GetProtagonistEv(gs);
    Actor* enemy = _Z32FindCombatantByField16a_021a278cPvi(ov, c->info->id8);
    _ZN9GameState20GetUnknownGameObjectEv(gs);
    Actor* leader = _ZN9GameState21GetPartyMemberByIndexEi(gs, c->info->partyIdx);
    c->savedPlanes = (*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8;
    {
        volatile unsigned int* reg = (volatile unsigned int*)0x4001000;
        unsigned int planes = (*reg & 0x1f00) >> 8;
        *reg = (*reg & ~0x1f00) | ((planes & ~0x10) << 8);
    }
    for (int i = 0; i < 4; i++) {
        if (!_Z13TestBitAt0x34Phj(c->info, (unsigned char)i)) continue;
        Actor* m = _ZN9GameState21GetPartyMemberByIndexEi(gs, i);
        if (!m) continue;
        if (_Z12GetByte0x26cPc(m)) {
            _Z24ResetObjectState02039d84P11Obj02039d84(m);
            _Z31EnqueueEventTag60Field_021d440ci(i);
            if (leader) {
                m->pos = leader->pos;
            }
        }
        c->party[i].pos = m->pos;
        c->party[i].angle = m->rot.y;
        _Z27ClearField0xc4KeepBit0x8000Ph(m);
        _ZN8Object3D17SetInheritedAlphaEi(m, 0x1f);
        _Z20ClearFlag0x1ceBit0x4Ph(m);
        if (c->info->modeC == 0x1b) {
            Actor* o = _ZN9GameState21GetPartyMemberByIndexEi(gs, 0);
            if (!o) continue;
            if (**(unsigned int**)((char*)o + 0x130) & 1) {
                o = _ZN9GameState21GetPartyMemberByIndexEi(gs, (short)_Z18GetSignedByte0x1caPv(o));
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
                int r = _ZNK8Object3D9GetRadiusEv(mon);
                int half = (r + _ZNK8Object3D9GetRadiusEv(enemy)) / 2;
                _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&dir, dist - (half + 0x1000), &off);
                mp = func_02019210(obj14, &mp, &off, _ZNK8Object3D9GetRadiusEv(mon) / 2);
                mp.y = func_02018fbc(obj14, &mp);
                mon->pos = mp;
            }
            _Z21AimAndSetVecY020338d4P14Struct020338d4P4Vec3(mon, &ep);
            _Z26EnqueueEventTag20_021cee78ih(id, 0);
        }
    }
    hero->savedPos = hero->pos;
    hero->savedRot = hero->rot;
    hero->f15c = _ZNK8Object3D10GetField06Ev(hero);
    _Z13SetField0x158Pvi(hero, 1);
    if (enemy) {
        if (!_Z18CheckField0NonZeroPi(search) || !_Z30GetSearchStructCurrentArrEntryP20SearchStruct0202c1a4(search)) {
            _Z18TrySetMode02076cccPvi(enemy, 9);
        } else {
            func_02076a8c(enemy);
            _ZN8Object3D10MakeHiddenEv(enemy);
        }
    }
    _Z33ResetOverlayAndAllocator_0219bf74v();
    func_ov017_0219bd1c(0, 4, 1, 0);
    char* f3f8 = (char*)_Z20GetField0x3f8AddressP9GameState(gs);
    int sel = _Z18GetField0x3acValueP9GameState(gs);
    *(Vec3*)(f3f8 + 0x10) = c->party[sel].pos;
    *(short*)(f3f8 + 0x1c) = c->party[sel].angle;
#if defined(jpn)
    unsigned int w = *(unsigned short*)(*(char**)((char*)ov + 0x3000 + 0x508) + 0x600 + 0xc4);
#else
    unsigned int w = *(unsigned short*)(*(char**)((char*)ov + 0x3000 + 0x718) + 0x600 + 0xc4);
#endif
    if (w) {
        char* p = (char*)_Z20GetField0x3f8AddressP9GameState(gs);
        *(unsigned short*)p = w;
        p[0xa] = 0;
    }
    _Z29ClearSlotsAndProcess_021a27e8v(ov);
    func_ov017_0219b938(ov);
    for (int k = 0; k < 12; k++) {
        Actor* fm = _ZN9GameState27GetMaybeFieldMonsterByIndexEi(gs, k + (entry->kind * 12 + 0x70));
        if (fm) _ZN8Object3D7DestroyEv(fm);
    }
    int glob = _Z20GetGlobalPtr021075f4v();
    if (_Z12GetField0x8cPv(glob) > 0) {
        _Z24SetCombatWorkFlags0x55f4Pvi(c, 0x1000);
    }
    _Z12Init0203cfb4P15Struct_0203cfb4(glob);
    func_ov017_021a316c(ov);
    _Z15SetBitsInField4Pjj(ov, 0x80);
    _Z15SetBitsInField4Pjj(ov, 4);
    _Z15SetBitsInField4Pjj(ov, 0x10);
    _Z16GetField02163524Pv(c);
    _Z15SetBitsInField4Pjj(ov, 2);
    _Z13SetBitsInWordPjj(ov, 4);
    _Z13SetBitsInWordPjj(ov, 0x20);
    _Z15SetBitsInField4Pjj(ov, 0x10);
    _Z15SetBitsInField4Pjj(ov, 0x40);
    _Z15SetBitsInField4Pjj(ov, 0x80);
    Off2400(Off264(obj14))[0xb6] = 0;
    _Z15SetBitsInField8Pjj(ov, 4);
    func_ov000_0216d2d0(c->sub_c18);
    _Z23SetIntField540_0216f700Pvi(c->sub_c18, c->f29c);
    c->fe20 = 0x800;
    c->fe24 = 1;
    c->f2a4 = _Z18GetField0x3b0ValueP9GameState(gs);
    if (c->f2a4) {
        _Z28SetAngleAndTrigTable0202e9a4P17AngleTrig0202e9a4i(c->f2a4, 0xf);
    }
    _Z18SetField0x3b0ValueP9GameStatei(gs, c->sub_c18);
#if defined(jpn)
    func_020134e0((char*)c + 0x244 + 0xc00);
#else
    func_020134e0((char*)c + 0x2c8 + 0xc00);
#endif
    _Z38ResetTaskAndDestroyAllocators_021a050cPc(ov);
    if (_Z20GetFieldB08_0219e008Pv(ov) == 4) {
        _Z35DestroyAllocatorsFromTable_021a1114Pc(ov);
        func_ov017_021a07f4(ov);
        _Z20SetFieldB08_0219dffcPvi(ov, 1);
    }
    SlotTable tbl = data_ov000_02183034;
    int size;
    for (int n = 0; (size = tbl.e[n].size) > 0; n++) {
        int idx = tbl.e[n].idx;
        int type = tbl.e[n].type;
        int buf = _ZN13SafeAllocator8AllocateEj((char*)ov + 0x38, size);
        if (type == 0) {
#if defined(jpn)
            _ZN13SafeAllocator11CreateTypeAEPvj((AllocSlot*)((char*)c + 8) + idx, buf, size);
#else
            _ZN13SafeAllocator11CreateTypeAEPvj(&c->allocs[idx], buf, size);
#endif
        } else if (type == 1) {
#if defined(jpn)
            _ZN13SafeAllocator11CreateTypeBEPvji((AllocSlot*)((char*)c + 8) + idx, buf, size, 4);
#else
            _ZN13SafeAllocator11CreateTypeBEPvji(&c->allocs[idx], buf, size, 4);
#endif
        }
    }
    for (int i = 0; i < 4; i++) {
        if (!_Z13TestBitAt0x34Phj(c->info, (unsigned char)i)) continue;
        Actor* m = _ZN9GameState21GetPartyMemberByIndexEi(gs, i);
        if (!m) continue;
        m->savedPos = m->pos;
        m->savedRot = m->rot;
        m->f15c = _ZNK8Object3D10GetField06Ev(m);
        _Z21SetAndClearField0x19cPcP14Field0x19cData(m, &c->fd[i]);
        func_ov000_02161300(c, i);
        _Z18SetFlag0x1ceBit0x1Ph(m);
        if (m->flags & 0x1000) {
            _Z13SetField0x158Pvi(m, 1);
        }
    }
    if (!_Z18CheckField0NonZeroPi(search)) {
        _Z24SetCombatWorkFlags0x55f4Pvi(c, 2);
    } else if (_Z18GetField0x3acValueP9GameState(gs) == c->info->partyIdx) {
        _Z24SetCombatWorkFlags0x55f4Pvi(c, 2);
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
    _Z27EnqueueEventTag147_021cdaa0v();
    if (c->info->modeC == 0x1a) {
        _ZN9GameState12SetTimeOfDayE9TimeOfDay(gs, 3);
        lm->mode = 3;
    }
    _Z15ClearBitsInWordPjj(ov, 0x800);
    BattleBlk blk;
    _Z23LoadBattleBlock020ac4c0Pv(&blk);
    _Z26AddClamped24BitFieldAt0x3cP7S_a07e0j(&blk, 1);
    _Z26AddClamped16BitFieldAt0x10P7S_a00d4j(&blk.sub, 1);
    _Z23CopyInBattleField0x7540Pv(&blk);
    ((GameStateBlk*)gs)->b728 = 0;
    _Z19SetField0x5729ValuePch(gs, 0);
    func_ov017_021c894c(c->info->id8);
    func_ov017_021c8758(c->info->id8);
    func_ov017_021c8654();
    func_ov017_021c847c();
    c->f77f0 = -1;
    _Z25ClearGlobalBuffer02107850v();
    _Z24SetCombatWorkFlags0x55f4Pvi(c, 1);
}
