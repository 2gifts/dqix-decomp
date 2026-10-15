#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"
#include "Grotto/Main/TreasureMapMetadata.h"
#include "Filesystem/FileIO.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"
#include "Resource/FontBankLoader.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
struct Struct_ov017_44C8;
struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};
struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};

int GetGlobalField0x1c020421a0();
extern "C" void* func_02012fe4(void);
extern "C" void* func_0202ae18();
void* GetDataPtr02114e04_020d6c00(void);
extern "C" void func_ov003_0216d8d4(char* obj, int keyA, int p3, int p4, int p5);
extern "C" int func_020457e0(char* obj);
void ReinitController02043204(char* obj);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
void TailForward02012da4(AllocatorUnion*, void*);
void ResetState02170d38(char*);
class Base021714a0;
extern "C" int func_ov003_021714a0(Base021714a0* obj);
extern "C" void func_ov003_02173c40(char* obj);
extern "C" void func_ov003_021726f8(char* obj, SafeAllocator* allocator);
extern "C" void VectorizedMemset(void*, int, int);
extern "C" void VectorizedInvertedMemcpy(void* dst, void* src, int size);
extern "C" int func_020aad1c(int a, int b, int c, int d);

extern "C" void func_ov003_02170d88(void* p);
extern "C" int func_ov003_021727c8(char* obj);
extern "C" void func_ov003_02173d40(char* obj);

void CopyToRegion0x6482IfDst_020119f8(char*, void*);
int CheckField0NonZero_0202b7d8(int*);
void StoreInvalidTreasureMapMetadata_02011a40(char*);
void* GetFieldAt0x150_02053c6c(unsigned char*);
struct GameState;
int ReadBattleField0x64f4Byte_02011804(GameState*);
void SetByte0x6480_020119d8(void*);
extern "C" void func_ov017_021a9ff0(int flag);
void InitNodeAndInsertAt_021c1798_021c1798(GameResources* p, unsigned char v);
int IsBrightnessTransitionActive(void* word);
struct Obj020397cc;
void CancelPendingAction020397cc(Obj020397cc*, int);
void OrBitsIntoField0_020466e4(unsigned int* word, unsigned int mask);
void SetMainBrightness(void* obj, int a, int b);
void SetSubBrightness(void* obj, int a, int b);
struct FlagWord020466f4;
void ClearFlags020466f4(FlagWord020466f4*, unsigned int);
struct Struct020a9ea4;
void ClearStruct020a9ea4(Struct020a9ea4*);
extern "C" void func_0209c2e0(void* obj, int a, int b);
struct Actor0209c3b4;
void SetStateAndDispatch0209c3b4(struct Actor0209c3b4* actor, int val);
struct Target02059f38;
struct Vec3_02059f38;
void CopyVec3ToField0x44(Target02059f38*, Vec3_02059f38*);
struct Obj02033874;
void SetVecYFromValue02033874(Obj02033874*, int);
struct Foo0207df50;
void CopyInternalFields0207df50(struct Foo0207df50* p);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);
int GetByteField28_021b1fa8(void* p);
int GetByteField29_021b1fb0(void* p);
void* GetPtrField2a_021b1fb8(void* p);
int LoadBattleBlock020ac4c0(void* dst);
struct S_a03f8;
void AddClamped14BitFieldMidAt0x10_020a03f8(S_a03f8*, unsigned int);
void CopyInBattleField0x7540_020ac494(void* p);
void CopyOutBattleRegion0x64f4_020ac760(void* p);
void CopyToBattleRegion0x64f4_020ac734(void* p);
const char* CallFunc020e0434With02153694_020e51cc(int key);
struct Src02011818;
void SetNameEntries02011818(void*, Src02011818*);
void ClearRegion0x649e_02011ab8(char*);
void CopyStringToField0x649e_02011a74(char*, unsigned int, char const*);

extern int data_02109bf4;
extern AllocatorUnion data_02114e20;
extern unsigned char data_0211e33c[];
extern char data_ov003_021801e0[];
extern char data_ov003_021801f8[];
extern char data_ov003_021801fc[];
extern char data_ov003_02180201[];

struct S88 { char pad[0x414]; unsigned char b0:1; };
struct EntBlk { char pad0[0x44]; };
struct Stat950 { char pad[0x950]; int f950; };
struct Mem150 { char pad[0x150]; struct Stat950* f150; };
struct Ent { char pad0[0x44]; struct EntBlk blk[2]; };
static inline struct S88* GetEntFlags(struct Ent* ent, int i) {
    return (struct S88*)&ent->blk[i];
}
struct Rec5400 { unsigned int _p0:21, b21:4, b25:1, b26:1; int _p1:19, v:11; };
struct Sub29c { char pad[0x5400]; struct Rec5400 rec; };
struct Battle29c { char pad[0x29c]; struct Sub29c sub; };
static inline struct Sub29c* GetSub29c(void* b) { return &((struct Battle29c*)b)->sub; }
struct B7 { char pad[0xd]; unsigned char v:7; };
struct Name10 { char c[10]; };
struct Vec3 { int x, y, z; ~Vec3() {} };
struct ObjA64 { char pad[0xa64]; struct TreasureMapMetadata meta; };
#define META(o) (&((struct ObjA64*)(o))->meta)
static inline int IsKind5(char* obj) {
    return *(unsigned char*)(obj + 0x1000 + 8) == 5;
}

struct Save840 { char pad[0x1b34]; int fb34; char pad1b38[0x1b60 - 0x1b38]; unsigned char fb60; };
struct Ctx840 { char pad[0x840]; struct Save840 save; };
static inline struct Save840* GetSave(void* c) { return &((struct Ctx840*)c)->save; }
static inline int GetB34(struct Save840* s) { return s->fb34; }
static inline void SetB34(struct Save840* s, int v) { s->fb34 = v; }
static inline unsigned char GetB60(struct Save840* s) { return s->fb60; }
static inline void SetB60(struct Save840* s, unsigned char v) { s->fb60 = v; }
// USA: func_ov003_0216c00c
extern "C" ARM void func_ov003_0216c00c(char* obj) {
    struct BattleStruct* battle = (BattleStruct*)GameState::GetInstance();
    GameResources* ov17 = func_ov017_0218b5b0();
    char* g = (char*)GetGlobalField0x1c020421a0();
    void* ctx = func_02012fe4();
    void* w = func_0202ae18();
    void* dataPtr0 = GetDataPtr02114e04_020d6c00();

    short subreq = *(short*)(obj + 0xa);
    if (subreq == 1) {
        func_ov003_0216d8d4(obj, 0x41, -1, -1, -1);
        *(unsigned char*)(g + 0x1000 + 0x9b2) = 1;
        *(int*)(g + 0x99c) = 2;
        *(int*)(g + 0x998) = 1;
        *(short*)(obj + 6) = 3;
        *(short*)(obj + 0xa) = 0;
    } else if (subreq == 2) {
        struct TreasureMapMetadata local10c;
        CopyToRegion0x6482IfDst_020119f8((char*)battle, &local10c);
        if (local10c.GetMapType() != 0) {
            func_ov003_0216d8d4(obj, 0x4a, -1, -1, -1);
        } else {
            func_ov003_0216d8d4(obj, 0x43, -1, -1, -1);
        }
        *(short*)(obj + 6) = 0x12c;
        *(unsigned char*)(g + 0x1000 + 0x9b2) = 1;
        *(int*)(g + 0x99c) = 2;
        *(int*)(g + 0x998) = 1;
        *(short*)(obj + 0xa) = 0;
    }

    short state = *(short*)(obj + 6);
    if (state == 0) {
        if (GetB60(GetSave(ctx)) == 0) {
            func_ov003_0216d8d4(obj, 0x47, -1, -1, -1);
            *(short*)(obj + 6) = 0x63;
        } else if (CheckField0NonZero_0202b7d8((int*)w) != 0) {
            func_ov003_0216d8d4(obj, 0x3f, -1, -1, -1);
            *(short*)(obj + 6) = 0x63;
        } else {
            func_ov003_0216d8d4(obj, 0x2b, -1, -1, -1);
            *(short*)(obj + 6) = 1;
            StoreInvalidTreasureMapMetadata_02011a40((char*)battle);
        }
    } else if (state == 1) {
        if (*(int*)(g + 0x9a0) != 3) return;
        if ((&((struct Battle29c*)battle)->sub.rec)->b26 != 0) {
            func_ov003_0216d8d4(obj, 0x2d, -1, -1, -1);
            *(short*)(obj + 6) = 3;
        } else {
            func_ov003_0216d8d4(obj, 0x2c, -1, -1, -1);
            *(short*)(obj + 6) = 2;
        }
    } else if (state == 2) {
        if (*(int*)(g + 0x9a0) != 0) return;
        if (func_020457e0(g) == 1) {
            *(int*)(g + 0x998) = 1;
            func_ov003_0216d8d4(obj, 0x40, -1, -1, -1);
            *(short*)(obj + 6) = 3;
            struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetProtagonist();
            if (c != 0) {
                struct S88* fp = GetEntFlags((struct Ent*)GetFieldAt0x150_02053c6c((unsigned char*)c), 1);
                struct Rec5400* fl = &((struct Battle29c*)battle)->sub.rec;
                fl->b25 = fp->b0;
                fl->b21 = fp->b0;
                struct Rec5400* rec = &GetSub29c(battle)->rec;
                int base = 20700;
                if (fp->b0 == 1) base += 50;
                rec->v = base - 20000 + ((struct Mem150*)c)->f150->f950;
            }
        } else {
            ReinitController02043204(g);
            *(short*)(obj + 4) = 7;
            *(short*)(obj + 6) = 0;
            InitNodeAndInsertAt_021c1798_021c1798(ov17, 0);
        }
    } else if (state == 3) {
        if (*(int*)(g + 0x9a0) != 0) return;
        *(int*)(g + 0x998) = 1;
        if (func_020457e0(g) == 1) {
            if (ReadBattleField0x64f4Byte_02011804((GameState*)battle) != 0) {
                func_ov003_0216d8d4(obj, 0x4c, -1, -1, -1);
                *(short*)(obj + 6) = 0x64;
            } else {
                func_ov003_0216d8d4(obj, 0x5e, -1, -1, -1);
                *(short*)(obj + 6) = 0x12c;
            }
        } else {
            func_ov003_0216d8d4(obj, 0x2f, -1, -1, -1);
            *(short*)(obj + 6) = 0x67;
        }
    } else if (state == 0x67) {
        if (*(int*)(g + 0x9a0) != 3) return;
        *(int*)(g + 0x998) = 1;
        if (ReadBattleField0x64f4Byte_02011804((GameState*)battle) != 0) {
            func_ov003_0216d8d4(obj, 0x4d, -1, -1, -1);
            *(short*)(obj + 6) = 0x64;
        } else {
            func_ov003_0216d8d4(obj, 0x5e, -1, -1, -1);
            *(short*)(obj + 6) = 0x12c;
        }
    } else if (state == 0x64) {
        if (*(int*)(g + 0x9a0) != 0) return;
        *(int*)(g + 0x998) = 1;
        if (func_020457e0(g) == 1) {
            func_ov003_0216d8d4(obj, 0x48, -1, -1, -1);
            *(short*)(obj + 6) = 0x12c;
        } else {
            func_ov003_0216d8d4(obj, 0x49, -1, -1, -1);
            *(short*)(obj + 6) = 0x65;
        }
    } else if (state == 4) {
        if (*(int*)(g + 0x9a0) != 0) return;
        *(int*)(g + 0x998) = 1;
        if (func_020457e0(g) == 1) {
            func_ov003_0216d8d4(obj, 0x32, -1, -1, -1);
            *(short*)(obj + 6) = 0x63;
        } else if (ReadBattleField0x64f4Byte_02011804((GameState*)battle) != 0) {
            func_ov003_0216d8d4(obj, 0x39, -1, -1, -1);
            *(short*)(obj + 6) = 0x65;
        } else {
            func_ov003_0216d8d4(obj, 0x30, -1, -1, -1);
            *(short*)(obj + 6) = 5;
        }
    } else if (state == 0x65) {
        *(unsigned char*)(g + 0x1000 + 0x9ae) = 0;
        if (*(int*)(g + 0x9a0) != 0) return;
        ReinitController02043204(g);
        *(short*)(obj + 4) = 7;
        *(short*)(obj + 6) = 0;
        SetByte0x6480_020119d8(battle);
        func_ov017_021a9ff0(0);
    } else if (state == 0x66) {
        if (*(int*)(g + 0x9a0) != 0) return;
        *(int*)(g + 0x998) = 1;
        if (func_020457e0(g) == 1) {
            func_ov003_0216d8d4(obj, 0x32, -1, -1, -1);
            *(short*)(obj + 6) = 0x63;
        } else {
            func_ov003_0216d8d4(obj, 0x30, -1, -1, -1);
            *(short*)(obj + 6) = 5;
        }
    } else if (state == 5) {
        *(unsigned char*)(g + 0x1000 + 0x9ae) = 0;
        *(int*)(obj + 0x1000 + 0x408) += (int)((GameState*)battle)->GetTickCount();
        if (*(int*)(g + 0x9a0) != 0) {
            if (*(int*)(obj + 0x1000 + 0x408) < 0x12c) return;
        }
        *(int*)(obj + 0x1000 + 0x408) = 0;
        ReinitController02043204(g);
        func_0209c2e0(&data_02109bf4, 0, 0x12);
        func_ov003_02170d88(obj + 0x7e0);
        struct TreasureMapMetadata localF0;
        CopyToRegion0x6482IfDst_020119f8((char*)battle, &localF0);
        int mapType = localF0.GetMapType();
        if (mapType != 0) {
            *(unsigned char*)(obj + 0x9ad) = 1;
            META(obj)->DiscoveryStateAndMapTypeAndUnknown = localF0.DiscoveryStateAndMapTypeAndUnknown;
            *(struct Name10*)META(obj)->DiscoveredBy = *(struct Name10*)localF0.DiscoveredBy;
            *(struct Name10*)META(obj)->ClearedBy = *(struct Name10*)localF0.ClearedBy;
            META(obj)->Location = localF0.Location;
            META(obj)->TreasureDiscoveryFlags = localF0.TreasureDiscoveryFlags;
            META(obj)->QualityOrLegacyBossID = localF0.QualityOrLegacyBossID;
            META(obj)->LegacyBossLevel = localF0.LegacyBossLevel;
            META(obj)->SeedOrMinTurns = localF0.SeedOrMinTurns;
        } else {
            *(unsigned char*)(obj + 0x9ad) = 0;
        }
        void* mem = AllocateAligned4_02012d88(&data_02114e20, 0x13800);
        ((SafeAllocator*)(obj + 0x2d4 + 0x1000))->CreateTypeA(mem, 0x13800);
        func_ov003_02173c40(obj + 0x31c + 0xc00);
        func_ov003_021726f8(obj + 0x31c + 0xc00, (SafeAllocator*)(obj + 0x2d4 + 0x1000));
        Base021714a0* base7e0 = (Base021714a0*)(obj + 0x7e0);
        if (base7e0 != 0) {
            *(Base021714a0**)(obj + 0xfec) = base7e0;
        }
        OrBitsIntoField0_020466e4((unsigned int*)GetDataPtr02114e04_020d6c00(), 0x10080);
        SetMainBrightness(ov17, -16, 0x24);
        SetSubBrightness(ov17, -16, 0x24);
        *(short*)(obj + 6) = 6;
    } else if (state == 6) {
        int r;
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetUnknownGameObject();
        CancelPendingAction020397cc((Obj020397cc*)c, 1);
        if (IsBrightnessTransitionActive(ov17) != 0) {
            if (IsKind5(obj) == 0) return;
        }
        if (*(int*)(obj + 0x1000 + 0x3f0) > 0) {
            *(int*)(obj + 0x1000 + 0x3f0) -= 1;
        }
        if (IsKind5(obj) == 0 && *(int*)(obj + 0x1000 + 0x3f0) == 0) {
            r = func_ov003_021714a0((Base021714a0*)(obj + 0x7e0));
            *(unsigned char*)(obj + 0x1000 + 0x3eb) = (unsigned char)r;
            if ((r & 0xff) == 0) {
                *(int*)(obj + 0x1000 + 0x3f0) = 0xb4;
            }
        }
        if (func_ov003_021727c8(obj + 0x31c + 0xc00) == 0) {
        *(unsigned char*)(obj + 0x1000 + 0x3eb) = 1;
        ClearFlags020466f4((FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x10080);
        *(unsigned char*)(obj + 0x1000 + 0x3ee) = 0;
        *(unsigned char*)(obj + 0x1000 + 0x3ee) = *(unsigned char*)(obj + 0xff0);
        int flag = *(unsigned char*)(obj + 0xf13);
        *(unsigned char*)(obj + 0x1000 + 0x3ed) = *(unsigned char*)(obj + 0xfe0);
        ResetState02170d38(obj + 0x7e0);
        func_ov003_02173d40(obj + 0x31c + 0xc00);
        void* sig = ((SafeAllocator*)(obj + 0x2d4 + 0x1000))->GetSignedAllocator();
        if (sig != 0) {
            ((SafeAllocator*)(obj + 0x2d4 + 0x1000))->Destroy();
            TailForward02012da4(&data_02114e20, sig);
        }
        int battleBlock[0x2c];
        LoadBattleBlock020ac4c0(battleBlock);
        AddClamped14BitFieldMidAt0x10_020a03f8((S_a03f8*)battleBlock, *(unsigned char*)(obj + 0x1000 + 0x3ee));
        CopyInBattleField0x7540_020ac494(battleBlock);
        SetB34(GetSave(ctx), *(unsigned char*)(obj + 0x1000 + 0x3ed) + GetB34(GetSave(ctx)));
        if (flag != 0) {
            struct CombatantStruct* cc = (CombatantStruct*)((GameState*)battle)->GetUnknownGameObject();
            int i;
            for (i = 0; i < 4; i++) {
                if (i == *(short*)((char*)cc + 4)) {
                    Vec3 pos = *(Vec3*)((char*)cc + 0x44);
                    Vec3 rot = *(Vec3*)((char*)cc + 0x50);
                    pos.z += 0x1800;
                    CopyVec3ToField0x44((Target02059f38*)cc, (Vec3_02059f38*)&pos);
                    SetVecYFromValue02033874((Obj02033874*)cc, 0);
                } else {
                    void* r = ((GameState*)battle)->GetPartyMemberByIndex(i);
                    if (r != 0) {
                        ((Object3D*)r)->MakeHidden();
                    }
                }
            }
            *(short*)(obj + 6) = 0xd;
        } else {
            *(short*)(obj + 6) = 0xc;
        }
        }
    } else if (state == 7) {
        if (*(int*)(g + 0x9a0) != 3) return;
        unsigned char v3ee = *(unsigned char*)(obj + 0x1000 + 0x3ee);
        func_ov003_0216d8d4(obj, 0x35, -1, -1, v3ee);
        *(short*)(obj + 6) = 0x62;
    } else if (state == 8) {
        if (*(int*)(g + 0x9a0) != 3) return;
        if (*(unsigned char*)(obj + 0x1000 + 0x3ed) != 0) {
            *(unsigned char*)(obj + 0x1000 + 0x3ed) = 0;
            func_ov003_0216d8d4(obj, 0x42, -1, -1, -1);
        } else {
            unsigned char v3ee = *(unsigned char*)(obj + 0x1000 + 0x3ee);
            func_ov003_0216d8d4(obj, 0x35, -1, -1, v3ee);
        }
        *(short*)(obj + 6) = 0x62;
    } else if (state == 9) {
        if (*(int*)(g + 0x9a0) != 3) return;
        func_ov003_0216d8d4(obj, 0x36, -1, -1, -1);
        *(short*)(obj + 6) = 0x62;
    } else if (state == 0xa) {
        if (*(int*)(g + 0x9a0) != 3) return;
        func_ov003_0216d8d4(obj, 0x37, -1, -1, -1);
        *(short*)(obj + 6) = 8;
    } else if (state == 0xb) {
        if (*(int*)(g + 0x9a0) != 3) return;
        func_ov003_0216d8d4(obj, 0x38, -1, -1, -1);
        *(short*)(obj + 6) = 8;
    } else if (state == 0xc) {
        FontBankLoader* actor = GetGlobal02109400_02094a00();
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetUnknownGameObject();
        if (c != 0) {
            CancelPendingAction020397cc((Obj020397cc*)c, 1);
        }
        BlankFunction02094b34(actor, 0x1f5, 0x66, 0, 0);
        if (AlwaysTrue02094b4c(actor) == 0) return;
        if (IsBrightnessTransitionActive(ov17) != 0) return;
        void* p8 = *(void**)((char*)ctx + 8);
        int val = ((struct B7*)p8)->v;
        SetStateAndDispatch0209c3b4((struct Actor0209c3b4*)&data_02109bf4, val);
        func_0209c2e0(&data_02109bf4, 0x7f, 0);
        if (*(unsigned char*)(obj + 0x1000 + 0x3e9) != 0) {
            *(int*)(g + 0x998) = 1;
            func_ov003_0216d8d4(obj, 0x4b, -1, -1, -1);
            *(short*)(obj + 6) = 0x62;
            return;
        }
        *(int*)(g + 0x998) = 1;
        func_ov003_0216d8d4(obj, 0x33, -1, -1, -1);
        unsigned char v3ee = *(unsigned char*)(obj + 0x1000 + 0x3ee);
        if (v3ee == 0) {
            *(short*)(obj + 6) = 9;
            goto phase2;
        }
        if (v3ee < 3) {
            SetB60(GetSave(ctx), 0);
            *(short*)(obj + 6) = 0xa;
        } else {
            SetB60(GetSave(ctx), 0);
            *(short*)(obj + 6) = 0xb;
        }
    }

phase2:;
    state = *(short*)(obj + 6);
    if (state == 0x12c) {
        if (*(int*)(g + 0x9a0) != 0) return;
        *(int*)(g + 0x998) = 1;
        if (func_020457e0(g) == 1) {
            func_ov003_0216d8d4(obj, 0x32, -1, -1, -1);
            *(short*)(obj + 6) = 0x63;
        } else {
            ClearStruct020a9ea4((Struct020a9ea4*)(obj + 0xc + 0x1400));
            func_ov003_0216d8d4(obj, 0xc8, -1, -1, -1);
            *(short*)(obj + 6) = 0x12e;
            OrBitsIntoField0_020466e4((unsigned int*)dataPtr0, 0x80);
        }
        return;
    } else if (state == 0x12e) {
        *(unsigned char*)(g + 0x1000 + 0x9ae) = 0;
        *(unsigned char*)(obj + 0x1000 + 0x3ec) |= 4;
        BackgroundLoader::AddLockGlobal();
        if (func_020aad1c((int)(obj + 0xc + 0x1400), (int)data_0211e33c, 8, 0) == 1) {
            *(unsigned char*)(obj + 0x1000 + 0x3ec) &= ~4;
            func_ov003_0216d8d4(obj, 0xc9, -1, -1, -1);
            *(short*)(obj + 6) = 0x12f;
            BackgroundLoader::RemoveLockGlobal();
        }
        return;
    } else if (state == 0x12f) {
        ClearFlags020466f4((FlagWord020466f4*)dataPtr0, 0x80);
        if (*(int*)(g + 0x9a0) != 3) return;
        func_ov003_0216d8d4(obj, 0x30, -1, -1, -1);
        *(short*)(obj + 6) = 5;
        return;
    } else if (state == 0x130) {
        func_ov003_0216d8d4(obj, 0x30, -1, -1, -1);
        *(short*)(obj + 6) = 5;
        return;
    } else if (state == 0xd) {
        *(short*)(obj + 8) = 0;
        *(unsigned char*)(obj + 0x1000 + 0x3ec) |= 1;
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetUnknownGameObject();
        if (c != 0) {
            CancelPendingAction020397cc((Obj020397cc*)c, 1);
        }
        *(unsigned char*)(obj + 0x1000 + 0x3e9) = 1;
        *(short*)(obj + 6) = 0xe;
        return;
    } else if (state == 0xe) {
        ((SafeAllocator*)(obj + 0x2e8 + 0x1000))->ResetAllocatorPointer();
        void* mem = AllocateAligned4_02012d88(&data_02114e20, 0xc800);
        ((SafeAllocator*)(obj + 0x2e8 + 0x1000))->CreateTypeA(mem, 0xc800);
        ((SafeAllocator*)(obj + 0x2e8 + 0x1000))->Reset();
        unsigned int fileSize;
        void* fileData = LoadFileIntoNewAllocation(data_ov003_021801e0, *(SafeAllocator*)(obj + 0x2e8 + 0x1000), &fileSize);
        if (fileData == 0) {
            *(short*)(obj + 6) = 0xf;
            return;
        }
        struct Foo0207df50* fields = (struct Foo0207df50*)((char (*)[0x70])ov17->unknown_2cc)[0x1c];
        CopyInternalFields0207df50(fields);
        RestorePairTables0207df90((char*)fields);
        struct ObjectArchiveLoadInfo loadInfo;
        loadInfo.unk_0 = 0;
        loadInfo.unk_14 = 0;
        loadInfo.unk_18 = 0;
        loadInfo.packageID = 0;
        loadInfo.unk_10 = 0;
        loadInfo.allocator = (SafeAllocator*)(obj + 0x2e8 + 0x1000);
        loadInfo.fileData = fileData;
        loadInfo.unk_8 = fileSize;
        ((Object3D*)(obj + 0x33c + 0x1000))->LoadFromCHRArchive(&loadInfo);
        BackupPairTables0207dfac((char*)fields);
        *(unsigned char*)(obj + 0x1000 + 0x3e8) = 1;
        ((Object3D*)(obj + 0x33c + 0x1000))->MaybeSetRegularAnimation(data_ov003_021801f8, 1);
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetUnknownGameObject();
        CopyVec3ToField0x44((Target02059f38*)(obj + 0x33c + 0x1000), (Vec3_02059f38*)((char*)c + 0x44));
        ((Object3D*)(obj + 0x33c + 0x1000))->SetScale(&((Object3D*)c)->GetScale());
        SetBrightness(ov17, 0, 0xa);
        *(short*)(obj + 6) = 0xf;
        return;
    } else if (state == 0xf) {
        if (IsBrightnessTransitionActive(ov17) != 0) return;
        ((Object3D*)(obj + 0x33c + 0x1000))->AdvanceEffects();
        if (((Object3D*)(obj + 0x33c + 0x1000))->HasAnimationStopped() == 0) return;
        void* sig = ((SafeAllocator*)(obj + 0x2e8 + 0x1000))->GetSignedAllocator();
        if (sig != 0) {
            ((SafeAllocator*)(obj + 0x2e8 + 0x1000))->Destroy();
            TailForward02012da4(&data_02114e20, sig);
        }
        *(unsigned char*)(obj + 0x1000 + 0x3e8) = 0;
        void* combatant2 = *(void**)((char*)ov17 + 0x3b48);
        *(int*)(g + 0x998) = 1;
        int byte28 = GetByteField28_021b1fa8(combatant2);
        int byte29 = GetByteField29_021b1fb0(combatant2);
        func_ov003_0216d8d4(obj, 0x4f, byte28 + 0x64, byte29, -1);
        *(short*)(obj + 6) = 0x10;
        return;
    } else if (state == 0x10) {
        if (*(int*)(g + 0x998) != 0) return;
        SetBrightness(ov17, -16, 0x1e);
        *(short*)(obj + 6) = 0x11;
        return;
    } else if (state == 0x11) {
        if (IsBrightnessTransitionActive(ov17) != 0) return;
        struct CombatantStruct* c = (CombatantStruct*)((GameState*)battle)->GetUnknownGameObject();
        int i;
        for (i = 0; i < 4; i++) {
            if (i == *(short*)((char*)c + 4)) {
                Vec3 pos = *(Vec3*)((char*)c + 0x44);
                Vec3 rot = *(Vec3*)((char*)c + 0x50);
                pos.z -= 0x1800;
                CopyVec3ToField0x44((Target02059f38*)c, (Vec3_02059f38*)&pos);
                SetVecYFromValue02033874((Obj02033874*)c, 0x323d);
            } else {
                void* r = ((GameState*)battle)->GetPartyMemberByIndex(i);
                if (r != 0) {
                    ((Object3D*)r)->MakeVisible();
                }
            }
        }
        SetBrightness(ov17, 0, 0x1e);
        *(short*)(obj + 6) = 0x12;
        return;
    } else if (state == 0x12) {
        void* c2 = func_02012fe4();
        int val = (*(struct B7**)((char*)c2 + 8))->v;
        SetStateAndDispatch0209c3b4((struct Actor0209c3b4*)&data_02109bf4, val);
        func_0209c2e0(&data_02109bf4, 0x7f, 0);
        if ((unsigned int)ReadBattleField0x64f4Byte_02011804((GameState*)battle) >= 0x63) {
            *(short*)(obj + 6) = 0x13;
            char* g2 = (char*)GetGlobalField0x1c020421a0();
            *(int*)(g2 + 0x998) = 1;
            func_ov003_0216d8d4(obj, 0x72, -1, -1, -1);
            *(int*)(g + 0x2c8) = 1;
        } else {
            void* mb = func_ov017_0218b5b0();
            struct CombatantStruct* c3 = *(struct CombatantStruct**)((char*)mb + 0x3000 + 0xb48);
            struct {
                unsigned char count;
                char pad;
                struct TreasureMapMetadata maps[99];
            } region;
            CopyOutBattleRegion0x64f4_020ac760(&region);
            unsigned char idx = region.count;
            struct TreasureMapMetadata* slot = &region.maps[idx];
            VectorizedMemset(slot, 0, sizeof(struct TreasureMapMetadata));
            int b28 = GetByteField28_021b1fa8(c3);
            int b29 = GetByteField29_021b1fb0(c3);
            slot->InitialiseAsLegacyBossMap(b28, b29);
            void* p2a = GetPtrField2a_021b1fb8(c3);
            VectorizedInvertedMemcpy(p2a, (char*)slot + 1, 8);
            region.count += 1;
            CopyToBattleRegion0x64f4_020ac734(&region);
            *(short*)(obj + 6) = 0xc;
        }
        return;
    } else if (state == 0x13) {
        char* g2 = (char*)GetGlobalField0x1c020421a0();
        if (*(int*)(g2 + 0x998) != 0) return;
        int fr = func_020457e0(g2);
        if (fr == 0) {
            *(short*)(obj + 6) = 0xc;
            return;
        }
        if (fr != 1) return;
        void* mb = func_ov017_0218b5b0();
        struct CombatantStruct* c4 = *(struct CombatantStruct**)((char*)mb + 0x3000 + 0xb48);
        char nameBuf[0x28];
        VectorizedMemset(nameBuf, 0, 0x28);
        nameBuf[7] = 0;
        nameBuf[0x13] = 0;
        nameBuf[6] = 0;
        *(int*)(nameBuf + 0x20) = -1;
        nameBuf[0] = 2;
        nameBuf[1] = (char)GetByteField28_021b1fa8(c4);
        nameBuf[2] = (char)GetByteField29_021b1fb0(c4);
        *(short*)(nameBuf + 4) = 0;
        nameBuf[6] = 1;
        void* p2a = GetPtrField2a_021b1fb8(c4);
        strcpy(nameBuf + 7, (char*)p2a);
        SetNameEntries02011818(battle, (Src02011818*)nameBuf);
        const char* lvPrefix = CallFunc020e0434With02153694_020e51cc(1011);
        int level = GetByteField29_021b1fb0(c4);
        char lvlString[0x20];
        sprintf(lvlString, data_ov003_021801fc, lvPrefix, level);
        ClearRegion0x649e_02011ab8((char*)battle);
        short itemID = (short)(GetByteField28_021b1fa8(c4) + 0x45);
        const char* itemName = CallFunc020e0434With02153694_020e51cc(itemID);
        char popup[0x40];
        sprintf(popup, data_ov003_02180201, itemName, lvlString);
        CopyStringToField0x649e_02011a74((char*)battle, 0, popup);
        func_ov017_021a9ff0(1);
        *(short*)(obj + 6) = 0x14;
        return;
    } else if (state == 0x14) {
        void* mb = func_ov017_0218b5b0();
        void* p = *(void**)((char*)mb + 0x3000 + 0xb4c);
        if (*((unsigned char*)p + 2) == 0) {
            *(short*)(obj + 6) = 0xc;
        }
        return;
    } else if (state == 0x63) {
        if (*(int*)(g + 0x9a0) != 3) return;
        *(int*)(g + 0x998) = 1;
        func_ov003_0216d8d4(obj, 0x29, -1, -1, -1);
        *(short*)(obj + 6) = 0;
        *(short*)(obj + 4) = 2;
        *(short*)(obj + 6) = 0;
        return;
    } else if (state == 0x62) {
        if (*(int*)(g + 0x9a0) != 0 || *(int*)(g + 0x998) != 0) return;
        ReinitController02043204(g);
        *(short*)(obj + 4) = 7;
        *(short*)(obj + 6) = 0;
    }
}
