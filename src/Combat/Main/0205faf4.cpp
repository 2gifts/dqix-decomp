#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Combat/Main/BattleList.h"
#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
extern "C" int func_020e0484(void* list, void* alloc, const char* path, void* entries, unsigned short count, bool lock);
extern "C" int func_ov017_021b2718(void* obj);
extern const char* data_020f2a38;
static inline char* DateConditionBase(void* state) {
    return (char*)state + 0x5c0c;
}
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif

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

struct CondNode0205faf4 {
    unsigned short op;
    unsigned short p2;
    unsigned short p4;
    unsigned short p6;
    unsigned short p8;
    unsigned short pa;
    struct CondNode0205faf4* next;
};

int TestBitInByteArray(int unused, unsigned char* arr, int index);
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void _Z30CollectValidCombatants02010890P9GameStatePiS1_(struct BattleStruct* bs, int* outList, int* outCount);
int GetGlobalField0x1c020421a0(void);
extern "C" int func_020457e0(int);
struct S_020103b4;
extern "C" int _ZNK9GameState21IsMorningDayOrEveningEv(struct S_020103b4* obj);
extern "C" void* _Z17GetPtrField0x2a04P9GameState(struct BattleStruct* battleStruct);
struct Obj02086aec;
short SumCombatantKeyMatches02086aec(struct Obj02086aec* obj, int key);
struct PackedNibbleArray0206e120;
int GetPackedNibbleField(struct PackedNibbleArray0206e120* obj, int index);
int CheckFlagAndThreshold0206e31c(int unused, int index);
struct PackedNibbleArray0206e260;
int GetPackedNibbleFlag0x4(struct PackedNibbleArray0206e260* obj, int index);
extern "C" void* func_0202ae18(void* gs);
int CheckField0NonZero(int* obj);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
int TestBitWithBias0206eb98(unsigned char* obj, int index);
extern "C" void __clear(void* buf, int count);
void* GetGlobal02109418(void);
int TestBitInByteArrayAt0x84(void* obj, int index);
void* GetGlobalPtr021075f4(void);
void* FindEntryPointerByKey0203df78(void* base, int key);
struct S02040538;
void* GetField0xc02040538(struct S02040538* p);
extern "C" struct CombatantStruct* _ZN9GameState20GetUnknownGameObjectEv(struct BattleStruct* battleStruct);
extern "C" struct CombatantStruct* _ZN9GameState20GetGameObjectByIndexEi(struct BattleStruct* battleStruct, int combatantId);
extern "C" int _Z17GetField5cb8ValuePc(char* p);
extern "C" int _Z18GetField0x3acValueP9GameState(struct BattleStruct* battleStruct);
struct Base02010834;
void CopyCountedBytesToIntArray02010834(struct Base02010834* base, int index, int* out, int* outCount);

struct CombatantSub0150_0205faf4 {
    int _f0;
    unsigned int _pad4:10, base:10, _pad4b:12;
    int _f8;
    unsigned int _padc:10, f0:10, f1:10;
    unsigned int f2:10, f3:10, f4:10;
    unsigned int f5:10;
};
extern "C" struct CombatantStruct* _Z25GetCombatantWithFlag0x100P9GameStatei(struct BattleStruct* battleStruct, int combatantId);
void* GetFieldAt0x150(unsigned char* obj);
extern "C" unsigned char _Z19GetField0x397cValueP9GameState(struct BattleStruct* battleStruct);
struct Entry0x194_0205faf4 { char pad[8]; unsigned int _pad18:18, flag:1; };
struct FindEntryById02096134Table;
struct FindEntryById02096134Elem { unsigned int _pad0:9, b9:1, _pad10:5, b15:1, _pad16:2, b18:1; };
struct FindEntryById02096134Elem* FindEntryById02096134(struct FindEntryById02096134Table* t, int id);
extern "C" int func_0206474c(struct BattleStruct* obj, int a1, int a2);
extern "C" int func_0206483c(struct BattleStruct* obj, char* name);
void* GetStatFieldPointer02064904(void* obj, int id, unsigned int statIndex);
extern "C" void* func_ov017_0218b5b0(void);
extern "C" struct CombatantStruct* _ZN9GameState21GetPartyMemberByIndexEi(struct BattleStruct* battleStruct, int combatantId);
extern "C" struct CombatantStruct* _ZN9GameState14GetProtagonistEv(struct BattleStruct* battleStruct);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
void* GetPointerFromArray0xbd0(unsigned char* obj, unsigned int index);
short CountPositiveEntries0207c638(void* base, unsigned int index);
struct EntryList020deb24 { int w[6]; };
struct Entry020deb24 { int f0; int f4; unsigned int _pad9:9, level:3; };
void* ZeroInitReturn020de824(void* obj);
void ZeroInit020de848(void* obj);
struct Entry020deb24* GetEntryByIndex020deb24(struct EntryList020deb24* list, int index);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv(void);
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv(void);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" int func_020de9a4(void* list, void* alloc, void* data, unsigned int size, void* entries, unsigned short count);
struct Obj02061bd8;
int CheckField0x56bLowNibble(struct Obj02061bd8* obj);
int RegisterSlotA020cf0fc(int out);
extern "C" void* func_02012fe4(void);
extern "C" int _ZNK9GameState12GetTimeOfDayEv(struct BattleStruct* battleStruct);
struct ReadClearByte02098ee8;
unsigned char ReadAndClearByte0x1b61(struct ReadClearByte02098ee8* s);
int CheckBitsInField0x63dc(void* obj, int mask);
struct PackedNibbleArray0206e2dc;
int GetPackedNibbleFlag0x8(struct PackedNibbleArray0206e2dc* obj, int index);
extern "C" void* _Z20GetField0x3f8AddressP9GameState(struct BattleStruct* battleStruct);

extern AllocatorUnion data_02114e20;
extern const char* data_020f2a38;
extern const char* data_020f2a30;

struct ExtraStruct0205faf4 {
    int v[16];
};
struct DateSlot0205faf4 { int f0; int f4; int f8; int fc; };
struct Word569c_0205faf4 { unsigned int _pad0:12, a:4, b:5; };
struct Nibble56b_0205faf4 { char pad[0x56b]; unsigned char _lo:4, hi:4; };

#define NIB56B(c) (*(struct Nibble56b_0205faf4**)((char*)(c) + REGION_VALUE(0x144, 0x150)))
#define HasNibble56b(c) (NIB56B(c) != NULL ? (NIB56B(c)->hi != 0 ? 1 : 0) : 0)
#define GetNibble56b(c) (NIB56B(c) != NULL ? NIB56B(c)->hi : 0)

static inline int GetHp0205faf4(void* stat) {
    return *(unsigned short*)((char*)stat + 4);
}
static inline char* Sub569c0205faf4(void* bs) {
    return (char*)bs + REGION_VALUE(0x543c, 0x569c);
}
struct Word56a0_0205faf4 { int _pad0:19, v:11; };
static inline struct Entry0x194_0205faf4* Entry194_0205faf4(struct CombatantStruct* c, unsigned char i) {
    return (struct Entry0x194_0205faf4*)(*(char**)((char*)c + REGION_VALUE(0x144, 0x150)) + 0x194 + i * 0x20);
}

struct Flags1840_0205faf4 { char pad0[0xb3c]; unsigned int fb3c; char pad1[0xb4c - 0xb40]; unsigned int fb4c; };
static inline struct Flags1840_0205faf4* Flags1840_0205faf4(void* p) {
    return (struct Flags1840_0205faf4*)((char*)p + REGION_VALUE(0x1860, 0x1840));
}
#define FLAGS1840(p) Flags1840_0205faf4(p)
#define OBJB ((unsigned char*)obj)
#define CU16(o) (*(unsigned short*)((char*)cmd + (o)))
#define CS16(o) (*(short*)((char*)cmd + (o)))
#define EW(o) (*(int*)((char*)extra + (o)))
#define STAT130(c) (*(void**)((char*)(c) + 0x130))
#define SUB150(c) (*(char**)((char*)(c) + REGION_VALUE(0x144, 0x150)))

static inline int Field950_0205faf4(struct CombatantStruct* c) {
    int v = *(int*)(SUB150(c) + REGION_VALUE(0x8b8, 0x950));
    return v;
}
static inline int Extra24_0205faf4(struct ExtraStruct0205faf4* extra) {
    int v = EW(0x24);
    return v;
}

// USA: func_0205faf4
extern "C" ARM int func_0205faf4(struct BattleStruct* obj, void* cmd, struct ExtraStruct0205faf4* extra) {
    unsigned short op = *(unsigned short*)cmd;
    switch (op) {
    case 0:
        return TestBitInByteArray((int)obj, OBJB + 0x8c, CU16(2));
    case 1:
        return !TestBitInByteArray((int)obj, OBJB + 0x8c, CU16(2));
    case 2: {
        unsigned char id = *(OBJB + 0x332);
        return TestBitInByteArray((int)obj, OBJB + id * 0x1c + 3, CU16(2));
    }
    case 3: {
        unsigned char id = *(OBJB + 0x332);
        return !TestBitInByteArray((int)obj, OBJB + id * 0x1c + 3, CU16(2));
    }
    case 4: {
        unsigned char id = *(OBJB + 0x332);
        return TestBitInByteArray((int)obj, OBJB + id * 0x1c + 0x10, CU16(2));
    }
    case 5: {
        unsigned char id = *(OBJB + 0x332);
        return !TestBitInByteArray((int)obj, OBJB + id * 0x1c + 0x10, CU16(2));
    }
    case 6:
        return CU16(2) == EW(0);
    case 7:
        return CU16(2) == EW(4);
    case 8:
        return CU16(2) == EW(8);
    case 9:
        return CU16(2) == EW(0xc);
    case 10:
        return CU16(2) == EW(0x10);
    case 11:
        return CU16(2) == EW(0x14);
    case 12:
        return CU16(2) == EW(0x18);
    case 13: {
        int outList[4]; int outCount;
        _Z30CollectValidCombatants02010890P9GameStatePiS1_((struct BattleStruct*)_ZN9GameState11GetInstanceEv(), outList, &outCount);
        return CU16(2) <= outCount;
    }
    case 14: {
        int outList[4]; int outCount;
        _Z30CollectValidCombatants02010890P9GameStatePiS1_((struct BattleStruct*)_ZN9GameState11GetInstanceEv(), outList, &outCount);
        return CU16(2) >= outCount;
    }
    case 15: {
        int outList[4]; int outCount;
        _Z30CollectValidCombatants02010890P9GameStatePiS1_((struct BattleStruct*)_ZN9GameState11GetInstanceEv(), outList, &outCount);
        return CU16(2) == outCount;
    }
    case 16:
        return CU16(2) == func_020457e0(GetGlobalField0x1c020421a0());
    case 17: {
        struct BattleStruct* bs = (struct BattleStruct*)_ZN9GameState11GetInstanceEv();
        if (CU16(2) == 1) {
            return !_ZNK9GameState21IsMorningDayOrEveningEv((struct S_020103b4*)bs);
        }
        return _ZNK9GameState21IsMorningDayOrEveningEv((struct S_020103b4*)bs);
    }
    case 18:
        return SumCombatantKeyMatches02086aec((struct Obj02086aec*)_Z17GetPtrField0x2a04P9GameState((struct BattleStruct*)_ZN9GameState11GetInstanceEv()), CS16(2)) > 0;
    case 19:
        return SumCombatantKeyMatches02086aec((struct Obj02086aec*)_Z17GetPtrField0x2a04P9GameState((struct BattleStruct*)_ZN9GameState11GetInstanceEv()), CS16(2)) <= 0;
    case 20: {
        int result = 0;
        int match = GetPackedNibbleField((struct PackedNibbleArray0206e120*)obj, CU16(2)) == 2;
        if (match) {
            if (CheckFlagAndThreshold0206e31c((int)obj, CU16(2))) result = 1;
        }
        return result;
    }
    case 21: {
        if (GetPackedNibbleFlag0x4((struct PackedNibbleArray0206e260*)obj, CU16(2))) {
            if (CheckFlagAndThreshold0206e31c((int)obj, CU16(2))) return 1;
        }
        return 0;
    }
    case 22: {
        int result = 0;
        int match = GetPackedNibbleField((struct PackedNibbleArray0206e120*)obj, CU16(2)) == 3;
        if (match) {
            if (CheckFlagAndThreshold0206e31c((int)obj, CU16(2))) result = 1;
        }
        return result;
    }
    case 23: {
        void* g = func_0202ae18(_ZN9GameState11GetInstanceEv());
        int result = 0;
        switch (CU16(2)) {
        case 1:
            if (CheckField0NonZero((int*)g)) result = 1;
            break;
        case 0:
            if (!CheckField0NonZero((int*)g)) result = 1;
            break;
        case 2:
            if (CheckField0NonZero((int*)g)) {
                if (GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)g) == 0) {
                    result = 1;
                    break;
                }
            }
            if (CheckField0NonZero((int*)g) == 0) result = 1;
            break;
        case 3:
            if (CheckField0NonZero((int*)g)) {
                if (GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)g)) result = 1;
            }
            break;
        }
        return result;
    }
    case 25: {
        int result = 0;
        int match = GetPackedNibbleField((struct PackedNibbleArray0206e120*)obj, CU16(2)) == 1;
        if (match) {
            if (CheckFlagAndThreshold0206e31c((int)obj, CU16(2))) result = 1;
        }
        return result;
    }
    case 26:
        return TestBitWithBias0206eb98(OBJB, CU16(2));
    case 27:
        return !TestBitWithBias0206eb98(OBJB, CU16(2));
    case 28: {
        int result = 0;
        int match = GetPackedNibbleField((struct PackedNibbleArray0206e120*)obj, CU16(2)) == 0;
        if (match) {
            if (CheckFlagAndThreshold0206e31c((int)obj, CU16(2))) result = 1;
        }
        return result;
    }
    case 29:
        return CU16(4) == *(unsigned short*)((char*)extra + 0x1c) &&
               CU16(6) == *(unsigned short*)((char*)extra + 0x1e) &&
               CS16(2) == *(short*)((char*)extra + 0x28);
    case 30:
        return CU16(2) == EW(0x20);
    case 31:
        return CS16(2) == *((signed char*)(OBJB + 0x400) + 0x90);
    case 32: {
        int i;
        for (i = 0; i < 4; i++) {
            signed char c = ((signed char*)((int)cmd + 4))[i];
            if (c != 0 && c != ((signed char*)extra + i)[0x2a]) break;
        }
        return i == 4;
    }
    case 33: {
        unsigned char marks[4];
        __clear(marks, 4);
        signed char* p = (signed char*)cmd + 4;
        int i, j;
        for (i = 0; i < 4; i++) {
            signed char c = p[i];
            if (c == 0) continue;
            for (j = 0; j < 4; j++) {
                if (c == ((signed char*)extra + 0x2a)[j] && marks[j] == 0) {
                    marks[j] = 1;
                    break;
                }
            }
            if (j == 4) return 0;
        }
        return 1;
    }
    case 34: {
        void* p = _Z17GetPtrField0x2a04P9GameState((struct BattleStruct*)_ZN9GameState11GetInstanceEv());
        unsigned short v = CU16(2);
        if (v != 0 && *((unsigned char*)p + 0xf7c) > 1) return 1;
        if (v == 0 && *((unsigned char*)p + 0xf7c) <= 1) return 1;
        return 0;
    }
    case 35:
        return CU16(2) == _Z17GetField5cb8ValuePc((char*)_ZN9GameState11GetInstanceEv());
    case 36: {
        struct CombatantStruct* c = _ZN9GameState20GetGameObjectByIndexEi((struct BattleStruct*)_ZN9GameState11GetInstanceEv(), 0);
        unsigned short v = CU16(2);
        if (v != 0 && GetHp0205faf4(STAT130(c)) <= 0) return 1;
        if (v == 0 && GetHp0205faf4(STAT130(c)) > 0) return 1;
        return 0;
    }
    case 37: {
        if (TestBitInByteArrayAt0x84(GetGlobal02109418(), CU16(2))) {
            if (CheckFlagAndThreshold0206e31c((int)obj, CU16(2))) return 1;
        }
        return 0;
    }
    case 38: {
        if (!TestBitInByteArrayAt0x84(GetGlobal02109418(), CU16(2))) {
            if (CheckFlagAndThreshold0206e31c((int)obj, CU16(2))) return 1;
        }
        return 0;
    }
    case 39:
        return TestBitInByteArray((int)obj, OBJB + 0x8c, CU16(2) + 0x776);
    case 40:
        return !TestBitInByteArray((int)obj, OBJB + 0x8c, CU16(2) + 0x776);
    case 41: {
        struct Keys0205faf4 { int hi; int mid; int lo; };
        void* e = FindEntryPointerByKey0203df78(GetGlobalPtr021075f4(), EW(0));
        if (!e) return 0;
        void* base = GetField0xc02040538((struct S02040538*)e);
        if (!base) return 0;
        struct CombatantStruct* c = _ZN9GameState20GetUnknownGameObjectEv((struct BattleStruct*)_ZN9GameState11GetInstanceEv());
        struct Keys0205faf4 k = *(struct Keys0205faf4*)((char*)c + 0x44);
        int* node;
        for (node = *(int**)((char*)base + 0x40); node != NULL; node = (int*)node[5]) {
            if (k.hi < node[1] && k.lo < node[2] && k.hi > node[3] && k.lo > node[4]) return CU16(2) != 0;
        }
        return CU16(2) == 0;
    }
    case 42: {
        struct CombatantStruct* c = _ZN9GameState20GetGameObjectByIndexEi((struct BattleStruct*)_ZN9GameState11GetInstanceEv(), 0);
        return CU16(2) == Field950_0205faf4(c);
    }
    case 43: {
        char* w = Sub569c0205faf4(_ZN9GameState11GetInstanceEv());
        return ((struct Word56a0_0205faf4*)(w + 4))->v == CU16(2);
    }
    case 44: {
        struct BattleStruct* bs = (struct BattleStruct*)_ZN9GameState11GetInstanceEv();
        int outList[4];
        int outCount;
        CopyCountedBytesToIntArray02010834((struct Base02010834*)bs, _Z18GetField0x3acValueP9GameState(bs), outList, &outCount);
        int i;
        for (i = 0; i < outCount; i++) {
            struct CombatantStruct* c = _ZN9GameState20GetGameObjectByIndexEi(bs, outList[i]);
            if (!c) continue;
            void* sub = STAT130(c);
            if (*(int*)sub & 1) continue;
            if (GetHp0205faf4(sub) <= 0) continue;
            if (*(unsigned char*)(SUB150(c) + (unsigned char)CU16(2) + 0x464) >= CU16(4)) return 1;
        }
        return 0;
    }
    case 45: {
        struct CombatantSub0150_0205faf4* p = (struct CombatantSub0150_0205faf4*)SUB150(_ZN9GameState20GetGameObjectByIndexEi((struct BattleStruct*)_ZN9GameState11GetInstanceEv(), 0));
        unsigned short vals[6];
        vals[0] = p->f0; vals[1] = p->f1; vals[2] = p->f2;
        vals[3] = p->f3; vals[4] = p->f4; vals[5] = p->f5;
        unsigned short idx = CU16(2);
        int v = vals[idx];
        int j;
        for (j = 0; j < 6; j++) {
            if (j == idx) continue;
            if (v < vals[j]) return 0;
        }
        return 1;
    }
    case 46: {
        struct CombatantSub0150_0205faf4* p = (struct CombatantSub0150_0205faf4*)SUB150(_ZN9GameState20GetGameObjectByIndexEi((struct BattleStruct*)_ZN9GameState11GetInstanceEv(), 0));
        unsigned short baseline = p->base;
        int y = CU16(4);
        unsigned short z = CU16(2);
        if (CU16(6) != 0) {
            switch (z) {
            case 0: if (y >= (unsigned short)p->f0 - baseline) return 1; break;
            case 1: if (y >= (unsigned short)p->f1 - baseline) return 1; break;
            case 2: if (y >= (unsigned short)p->f2 - baseline) return 1; break;
            case 3: if (y >= (unsigned short)p->f3 - baseline) return 1; break;
            case 4: if (y >= (unsigned short)p->f4 - baseline) return 1; break;
            case 5: if (y >= (unsigned short)p->f5 - baseline) return 1; break;
            }
        } else {
            switch (z) {
            case 0: if (y < (unsigned short)p->f0 - baseline) return 1; break;
            case 1: if (y < (unsigned short)p->f1 - baseline) return 1; break;
            case 2: if (y < (unsigned short)p->f2 - baseline) return 1; break;
            case 3: if (y < (unsigned short)p->f3 - baseline) return 1; break;
            case 4: if (y < (unsigned short)p->f4 - baseline) return 1; break;
            case 5: if (y < (unsigned short)p->f5 - baseline) return 1; break;
            }
        }
        return 0;
    }
    case 47: {
        struct BattleStruct* bs = (struct BattleStruct*)_ZN9GameState11GetInstanceEv();
        struct CombatantStruct* c = _Z25GetCombatantWithFlag0x100P9GameStatei(bs, _Z19GetField0x397cValueP9GameState(bs));
        if (!c) return 0;
        int count = 0;
        int i;
        for (i = 0; i < 0xb; i++) {
            struct Entry0x194_0205faf4* entry = Entry194_0205faf4(c, i);
            if (entry == NULL) continue;
            if (entry->flag) count++;
        }
        if (CU16(2) != 0) {
            if (count >= CU16(4)) return 1;
        } else if (count < CU16(4)) {
            return 1;
        }
        return 0;
    }
    case 48: {
        void* p = _Z17GetPtrField0x2a04P9GameState((struct BattleStruct*)_ZN9GameState11GetInstanceEv());
        if (!p) return 0;
        return SumCombatantKeyMatches02086aec((struct Obj02086aec*)p, CS16(2)) >= CU16(4) ? 1 : 0;
    }
    case 49: {
        struct BattleStruct* bs = (struct BattleStruct*)_ZN9GameState11GetInstanceEv();
        int outList[4];
        int outCount;
        CopyCountedBytesToIntArray02010834((struct Base02010834*)bs, _Z18GetField0x3acValueP9GameState(bs), outList, &outCount);
        int i;
        for (i = 0; i < outCount; i++) {
            struct CombatantStruct* c = _Z25GetCombatantWithFlag0x100P9GameStatei(bs, outList[i]);
            if (!c) continue;
            void* sub = STAT130(c);
            if (*(int*)sub & 1) continue;
            if (CU16(2) != Field950_0205faf4(c)) continue;
            if (GetHp0205faf4(sub) <= 0) continue;
            void* ptr = GetFieldAt0x150((unsigned char*)c);
            if (!ptr) continue;
            if (*(unsigned short*)((char*)ptr + CU16(2) * 2 + 0x16c) >= CU16(4)) return 1;
        }
        return 0;
    }
    case 50:
    case 82: {
        struct BattleStruct* bs = (struct BattleStruct*)_ZN9GameState11GetInstanceEv();
        unsigned char* party = (unsigned char*)_Z17GetPtrField0x2a04P9GameState(bs);
        int count = party[0xf7c];
        int i = 0;
        if (CU16(0) == 0x52) count = 1;
        for (; i < count; i++) {
            struct CombatantStruct* c;
            if (CU16(0) == 0x52) {
                c = _ZN9GameState14GetProtagonistEv(bs);
            } else {
                c = _Z25GetCombatantWithFlag0x100P9GameStatei(bs, *(party + i + 0xf78));
            }
            if (c == NULL) continue;
            if (*(int*)STAT130(c) & 1) continue;
            if (CU16(2) == 1) {
                if (CS16(4) > 0 && CS16(4) != *(short*)(SUB150(c) + 0x1ac)) continue;
                if (CS16(6) > 0 && CS16(6) != *(short*)(SUB150(c) + 0x1cc)) continue;
                if (CS16(8) > 0 && CS16(8) != *(short*)(SUB150(c) + 0x24c)) continue;
                if (CS16(10) > 0 && CS16(10) != *(short*)(SUB150(c) + 0x26c)) continue;
                *(OBJB + 0x492) |= 1 << i;
            } else if (*(OBJB + 0x492) & (1 << i)) {
                if (CS16(4) != 0 && CS16(4) != *(short*)(SUB150(c) + 0x28c)) continue;
                if (CS16(6) != 0 && CS16(6) != *(short*)(SUB150(c) + 0x2ac)) continue;
                if (CS16(8) != 0 && CS16(8) != *(short*)(SUB150(c) + 0x2cc)) continue;
                if (CS16(10) == 0 || CS16(10) == *(short*)(SUB150(c) + 0x2ec)) return 1;
            }
        }
        if (CU16(2) != 1 && i == count) return 0;
        return *(OBJB + 0x492);
    }
    case 51: {
        struct FindEntryById02096134Elem* e = FindEntryById02096134((struct FindEntryById02096134Table*)GetGlobal02109418(), CU16(2));
        if (e != NULL && e->b15) return 1;
        break;
    }
    case 52: {
        struct CondNode0205faf4 sub;
        sub.op = 6; sub.p2 = CU16(2);
        if (!func_0205faf4(obj, &sub, extra)) return 0;
        sub.op = 5; sub.p2 = CU16(4);
        if (!func_0205faf4(obj, &sub, extra)) return 0;
        sub.op = 0x17; sub.p2 = CS16(6);
        return func_0205faf4(obj, &sub, extra) != 0;
    }
    case 53: {
        struct CondNode0205faf4 sub;
        sub.op = 6; sub.p2 = CU16(2);
        if (!func_0205faf4(obj, &sub, extra)) return 0;
        if (!func_0206474c(obj, CU16(4), CS16(6))) return 0;
        sub.op = 0xb; sub.p2 = CU16(8);
        if (!func_0205faf4(obj, &sub, extra)) return 0;
        sub.op = 0x10; sub.p2 = CU16(10);
        return func_0205faf4(obj, &sub, extra) != 0;
    }
    case 54: {
        struct CondNode0205faf4 sub;
        sub.op = 6; sub.p2 = CU16(2);
        if (!func_0205faf4(obj, &sub, extra)) return 0;
        if (!func_0206474c(obj, CU16(4), CS16(6))) return 0;
        sub.op = 0x12; sub.p2 = CU16(8);
        return func_0205faf4(obj, &sub, extra) != 0;
    }
    case 55: {
        struct CondNode0205faf4 sub;
        sub.op = 6; sub.p2 = CU16(2);
        if (!func_0205faf4(obj, &sub, extra)) return 0;
        return func_0206474c(obj, CU16(4), CS16(6)) ? 1 : 0;
    }
    case 56: {
        struct CondNode0205faf4 sub;
        sub.op = 6; sub.p2 = CU16(2);
        if (!func_0205faf4(obj, &sub, extra)) return 0;
        if (!func_0206474c(obj, CU16(4), CS16(6))) return 0;
        sub.op = 0x24; sub.p2 = CU16(8);
        return func_0205faf4(obj, &sub, extra) != 0;
    }
    case 57: {
        struct CondNode0205faf4 sub;
        sub.op = 6; sub.p2 = CU16(2);
        if (!func_0205faf4(obj, &sub, extra)) return 0;
        if (!func_0206474c(obj, CU16(4), CS16(6))) return 0;
        if (!TestBitWithBias0206eb98(OBJB, CU16(8))) return 0;
        sub.op = 0x17; sub.p2 = CU16(10);
        return func_0205faf4(obj, &sub, extra) != 0;
    }
    case 58: {
        struct CondNode0205faf4 sub;
        sub.op = 6; sub.p2 = CU16(2);
        if (!func_0205faf4(obj, &sub, extra)) return 0;
        if (!func_0206474c(obj, CU16(4), CS16(6))) return 0;
        if (TestBitWithBias0206eb98(OBJB, CU16(8))) return 0;
        sub.op = 0x17; sub.p2 = CU16(10);
        return func_0205faf4(obj, &sub, extra) != 0;
    }
    case 59: {
        struct CondNode0205faf4 sub;
        sub.op = 6; sub.p2 = CU16(2);
        if (!func_0205faf4(obj, &sub, extra)) return 0;
        if (!func_0206474c(obj, CU16(4), CS16(6))) return 0;
        return TestBitWithBias0206eb98(OBJB, CU16(8)) ? 1 : 0;
    }
    case 60: {
        struct CondNode0205faf4 sub;
        sub.op = 6; sub.p2 = CU16(2);
        if (!func_0205faf4(obj, &sub, extra)) return 0;
        if (!func_0206474c(obj, CU16(4), CS16(6))) return 0;
        return TestBitWithBias0206eb98(OBJB, CU16(8)) ? 0 : 1;
    }
    case 61: {
        struct CondNode0205faf4 sub;
        sub.op = 6; sub.p2 = CU16(2);
        if (!func_0205faf4(obj, &sub, extra)) return 0;
        if (!func_0206474c(obj, CU16(4), CS16(6))) return 0;
        sub.op = 0x17; sub.p2 = CU16(8);
        return func_0205faf4(obj, &sub, extra) != 0;
    }
    case 62: {
        struct CondNode0205faf4 sub;
        sub.op = 6; sub.p2 = CU16(2);
        if (!func_0205faf4(obj, &sub, extra)) return 0;
        sub.op = 0; sub.p2 = CU16(4);
        if (!func_0205faf4(obj, &sub, extra)) return 0;
        sub.op = 0x17; sub.p2 = CS16(6);
        return func_0205faf4(obj, &sub, extra) != 0;
    }
    case 63: {
        struct CondNode0205faf4 sub;
        sub.op = 6; sub.p2 = CU16(2);
        if (!func_0205faf4(obj, &sub, extra)) return 0;
        sub.op = 1; sub.p2 = CU16(4);
        if (!func_0205faf4(obj, &sub, extra)) return 0;
        sub.op = 0x17; sub.p2 = CS16(6);
        return func_0205faf4(obj, &sub, extra) != 0;
    }
    case 64: {
        struct CondNode0205faf4 sub;
        int i;
        sub.op = 0;
        for (i = 0; i < 4; i++) {
            short v = ((short*)((char*)cmd + 4))[i];
            if (v < 0) continue;
            sub.p2 = v;
            if (!func_0205faf4(obj, &sub, extra)) return 0;
        }
        return 1;
    }
    case 65: {
        struct CondNode0205faf4 sub;
        int i;
        sub.op = 1;
        for (i = 0; i < 4; i++) {
            short v = ((short*)((char*)cmd + 4))[i];
            if (v < 0) continue;
            sub.p2 = v;
            if (!func_0205faf4(obj, &sub, extra)) return 0;
        }
        return 1;
    }
    case 66: {
        int r = SumCombatantKeyMatches02086aec((struct Obj02086aec*)_Z17GetPtrField0x2a04P9GameState((struct BattleStruct*)_ZN9GameState11GetInstanceEv()), CS16(4)) > CU16(6);
        if (CU16(2) != 0) return r;
        return r == 0;
    }
    case 67:
        return TestBitInByteArray((int)obj, OBJB + 0x8c, CU16(2) + 0x1136);
    case 68:
        return !TestBitInByteArray((int)obj, OBJB + 0x8c, CU16(2) + 0x1136);
    case 69: {
        int r = func_0206483c(obj, *(char**)((char*)cmd + 4));
        if (CU16(2) != 0) return r;
        return r == 0;
    }
    case 70: {
        struct FindEntryById02096134Elem* e = FindEntryById02096134((struct FindEntryById02096134Table*)GetGlobal02109418(), CU16(2));
        if (e != NULL) {
            if (CU16(4) != 0) return e->b18;
            return e->b18 == 0;
        }
        return 0;
    }
    case 71:
        return 0;
    case 72:
        return 0;
    case 73: {
        int r = CU16(4) <= *(short*)(OBJB + 0x2ca);
        if (CU16(2) != 0) return r;
        return r == 0;
    }
    case 74: {
        unsigned short v = *(unsigned short*)((char*)_ZN9GameState11GetInstanceEv() + REGION_VALUE(0x6f9c, 0x71dc));
        if (v == 0) return CU16(2) == 0;
        return v == CU16(2);
    }
    case 75: {
        int r = 0;
        if (CU16(4) == Extra24_0205faf4(extra)) r = 1;
        return r;
    }
    case 76: {
        int r = 0;
        if (CU16(4) == Extra24_0205faf4(extra)) r = 1;
        return r;
    }
    case 77: {
        int r = 0;
        if (TestBitInByteArray((int)obj, OBJB + 0x8c, 0x364)) {
            if (TestBitInByteArray((int)obj, OBJB + 0x8c, 0x365)) r = 1;
        }
        return r;
    }
    case 78: {
        unsigned short* p = (unsigned short*)GetStatFieldPointer02064904(obj, CU16(2), CU16(4));
        if (p != NULL) {
            switch (CU16(8)) {
            case 0: return *p >= CU16(6);
            case 1: return *p < CU16(6);
            case 2: return *p == CU16(6);
            }
        }
        return 0;
    }
    case 79: {
        char* p = *(char**)((char*)func_ov017_0218b5b0() + REGION_VALUE(0x3500, 0x3710));
        return *((unsigned char*)cmd + 4) == *(unsigned char*)(p + 0x133) && CU16(2) == *(unsigned short*)(p + 0x134);
    }
    case 80: {
        struct BattleStruct* bs = (struct BattleStruct*)_ZN9GameState11GetInstanceEv();
        int outList[4];
        int outCount;
        CopyCountedBytesToIntArray02010834((struct Base02010834*)bs, _Z18GetField0x3acValueP9GameState(bs), outList, &outCount);
        int i;
        for (i = 0; i < outCount; i++) {
            struct CombatantStruct* c = _ZN9GameState21GetPartyMemberByIndexEi(bs, outList[i]);
            if (!c) continue;
            void* sub = STAT130(c);
            if (*(int*)sub & 1) continue;
            if (GetHp0205faf4(sub) <= 0) continue;
            char* p = SUB150(c);
            if (*(unsigned short*)(p + *(int*)(p + REGION_VALUE(0x8b8, 0x950)) * 2 + 0x16c) >= CU16(2)) return 1;
        }
        return 0;
    }
    case 81: {
        int r = CheckField0NonZero((int*)func_0202ae18(_ZN9GameState11GetInstanceEv()));
        if (CU16(2) != 0) return r;
        return r == 0;
    }
    case 83: {
        void* buf = AllocateAligned4(&data_02114e20, 0xc000);
        if (buf == NULL) return 0;
        SafeAllocator alloc;
        struct EntryList020deb24 list;
        unsigned int size;
        alloc.ResetAllocatorPointer();
        alloc.ResetAllocatorPointer();
        alloc.CreateTypeA(buf, 0xc000);
        unsigned char* party = (unsigned char*)_Z17GetPtrField0x2a04P9GameState((struct BattleStruct*)_ZN9GameState11GetInstanceEv());
        void* entries = GetPointerFromArray0xbd0(party + 0x1d4, CU16(2));
        short n = CountPositiveEntries0207c638(party + 0x1d4, CU16(2));
        ZeroInitReturn020de824(&list);
        ZeroInit020de848(&list);
#if defined(jpn)
        func_020e0484(&list, &alloc, data_020f2a38, entries, n, true);
#else
        _ZN16BackgroundLoader13AddLockGlobalEv();
        size = 0;
        void* data = ExtractFileFromGP2(data_020f2a38, data_020f2a30, &size);
        if (data != NULL) {
            func_020de9a4(&list, &alloc, data, size, entries, n);
        }
        _ZN16BackgroundLoader16RemoveLockGlobalEv();
#endif
        int found = 0;
        signed char i;
        for (i = 0; i < n; i++) {
            struct Entry020deb24* e = GetEntryByIndex020deb24(&list, i);
            if (e == NULL) continue;
            if (e->level >= CU16(4)) {
                found = 1;
                break;
            }
        }
        SignedAllocatorHeader* h = alloc.GetSignedAllocator();
        if (h != NULL) {
            alloc.Destroy();
            TailForward02012da4(&data_02114e20, h);
        }
        return found;
    }
    case 84: {
        func_ov017_0218b5b0();
        unsigned char v = *((unsigned char*)_ZN9GameState11GetInstanceEv() + REGION_VALUE(0x629e, 0x64de));
        return v == CU16(2);
    }
    case 85: {
        char* p = (char*)_Z17GetPtrField0x2a04P9GameState((struct BattleStruct*)_ZN9GameState11GetInstanceEv());
        if (CU16(2) != 0) return *(unsigned int*)(p + 0xf6c) >= *(unsigned int*)((char*)cmd + 4);
        return *(unsigned int*)(p + 0xf6c) < *(unsigned int*)((char*)cmd + 4);
    }
    case 86: {
        struct BattleStruct* bs = (struct BattleStruct*)_ZN9GameState11GetInstanceEv();
        int i;
        for (i = 0; i < 4; i++) {
            struct CombatantStruct* c = _Z25GetCombatantWithFlag0x100P9GameStatei(bs, i);
            if (c == NULL) continue;
            if (!CheckField0x56bLowNibble((struct Obj02061bd8*)c)) continue;
            if (GetHp0205faf4(STAT130(c)) <= 0) return CU16(2) == 0;
            return CU16(2) == 1;
        }
        if (_ZN9GameState20GetGameObjectByIndexEi(bs, 0xce) != NULL) return CU16(2) == 1;
        return CU16(2) == 0;
    }
    case 87: {
        unsigned char v = *(unsigned char*)GetGlobal02109418();
        if (CU16(2) != 0) return v == 8;
        return v < 8;
    }
    case 88:
        if (CU16(2) >= 0x49) return 0;
        return TestBitInByteArray((int)obj, OBJB + 0x8c, CU16(2) + 0x33e);
    case 89:
        if (CU16(2) < 0x49) return !TestBitInByteArray((int)obj, OBJB + 0x8c, CU16(2) + 0x33e);
        return 1;
    case 90: {
        struct DateSlot0205faf4 s;
        RegisterSlotA020cf0fc((int)&s);
        return s.f4 == CU16(2) && s.f8 == CU16(4);
    }
    case 91: {
        char* p = (char*)func_ov017_0218b5b0();
        return *((unsigned char*)cmd + 4) == *(unsigned char*)(p + REGION_VALUE(0x4199, 0x4449)) && CU16(2) == *(signed char*)(p + REGION_VALUE(0x4196, 0x4446));
    }
    case 92: {
        struct FindEntryById02096134Elem* e = FindEntryById02096134((struct FindEntryById02096134Table*)GetGlobal02109418(), CU16(2));
        if (e != NULL) return e->b9 == 0;
        return 0;
    }
    case 93: {
        unsigned int mask = 1 << CU16(2);
        return (FLAGS1840(func_02012fe4())->fb4c & mask) ? 1 : 0;
    }
    case 94:
        return CU16(2) == FLAGS1840(func_02012fe4())->fb3c;
    case 95: {
        unsigned short v = *(unsigned short*)((char*)func_02012fe4() + REGION_VALUE(0x27f4, 0x27b4));
        return CS16(2) == v;
    }
    case 96: {
        struct CombatantStruct* c = _ZN9GameState14GetProtagonistEv((struct BattleStruct*)_ZN9GameState11GetInstanceEv());
        if (c == NULL) return 0;
        int n = 0;
        int i;
        for (i = 0; i < 13; i++) {
            if (*(unsigned short*)(SUB150(c) + (unsigned char)i * 2 + 0x16c) >= 99) n++;
        }
        return n >= CU16(2);
    }
    case 97:
#if defined(jpn)
        return func_ov017_021b2718(*(void**)(DateConditionBase(_ZN9GameState11GetInstanceEv()) + 0x104)) == 0;
#else
        return 0;
#endif
    case 98:
        return *((unsigned char*)func_02012fe4() + REGION_VALUE(0x2810, 0x27d0)) <= CU16(2);
    case 99:
        return *((unsigned char*)func_02012fe4() + REGION_VALUE(0x2810, 0x27d0)) >= CU16(2);
    case 500: {
        struct BattleStruct* bs = (struct BattleStruct*)_ZN9GameState11GetInstanceEv();
        int outList[4];
        int outCount;
        CopyCountedBytesToIntArray02010834((struct Base02010834*)bs, _Z18GetField0x3acValueP9GameState(bs), outList, &outCount);
        int i;
        for (i = 0; i < outCount; i++) {
            struct CombatantStruct* c = _Z25GetCombatantWithFlag0x100P9GameStatei(bs, outList[i]);
            if (c == NULL) continue;
            if (!HasNibble56b(c)) continue;
            if (CU16(2) != GetNibble56b(c)) continue;
            if (*(int*)STAT130(c) & 1) return CU16(4) == 0;
            return CU16(4) == 1;
        }
        return 0;
    }
    case 501:
        return CU16(2) == _ZNK9GameState12GetTimeOfDayEv((struct BattleStruct*)_ZN9GameState11GetInstanceEv());
    case 502:
        return ReadAndClearByte0x1b61((struct ReadClearByte02098ee8*)((char*)func_02012fe4() + REGION_VALUE(0x860, 0x840)));
    case 503:
        if (CU16(2) != 0) return TestBitInByteArray((int)obj, OBJB + 0x8c, 0x798);
        return !TestBitInByteArray((int)obj, OBJB + 0x8c, 0x798);
    case 504: {
        char* bs = (char*)_ZN9GameState11GetInstanceEv();
        struct DateSlot0205faf4 s;
        RegisterSlotA020cf0fc((int)&s);
        struct Word569c_0205faf4* w = (struct Word569c_0205faf4*)(bs + REGION_VALUE(0x543c, 0x569c));
        return s.f4 == w->a && s.f8 == w->b;
    }
    case 505:
        return CheckBitsInField0x63dc(_ZN9GameState11GetInstanceEv(), 1);
    case 506:
        return GetPackedNibbleFlag0x8((struct PackedNibbleArray0206e2dc*)obj, CU16(2));
    case 507:
        return CU16(2) == *(unsigned short*)_Z20GetField0x3f8AddressP9GameState((struct BattleStruct*)_ZN9GameState11GetInstanceEv());
    }
    return 0;
}
