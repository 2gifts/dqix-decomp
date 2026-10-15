#include <globaldefs.h>
#include "Combat/CombatantRecovery.h"
#include "GameState/Field3b0.h"
#include "GameState/BattleRecordSnapshot.h"
#include "World/ZoneChest.h"
void SetOrClearBitInArray_0206df6c(void *obj, unsigned char *arr, int idx, int flag);
extern "C" void *func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int *ctx);
struct SearchStruct0202c1a4;
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4 *ctx);
extern "C" void func_ov017_021d0924(int a, int b, int p1, int flag);
void ClearNibble0206ece8(int a, int b, unsigned char *c, unsigned d);
extern "C" int func_0202c508(void *ctx);
extern "C" void *func_02012fe4(void);
void *GetPointerFromArray0x3c_0201e838(unsigned char *arr, unsigned idx);
struct AppendNode;
struct AppendList;
void AppendNodeToListField30_0206445c(int a, AppendNode *msg, AppendList *list);
void EnqueueEventTag147_021cdaa0();
void *GetGlobal02109418_02094d6c(void);
extern "C" int func_020961b0(void *g, int p1);
int TestBitInByteArray_0206dfb0(int obj, unsigned char *arr, int idx);
struct Struct020d9ae8;
void Init020d9ae8(Struct020d9ae8 *node, int mode);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4 *list, TailNode020469b4 *node);
extern "C" void func_0206e164(void *obj, int p1, int mode);
struct FindEntryById02096134Table;
void *FindEntryById02096134(FindEntryById02096134Table *table, int p1);
void SetBitWithOffset0206eb64(unsigned char *obj, int p2, int flag);
extern "C" void func_ov017_021c1a98(void *ctx, int flag);
void SetBitInArray0x8ec_02083acc(unsigned char*, int);
void SetBitInArray0x910_02083b60(unsigned char*, int);
void ToggleElemKey2FlagInMap2010_020ae6e8(int key);
void SetElemFlag8IfOverlayActive020ae730(int key);
void SetElemFlag0x4PairAndNotify17_020ae7d4(int key);
void SetElemFlag0x4QuadAndNotify17_020ae880(int key);
void EnqueueEventTag23Field_021d0d58();
struct ListHead02046b60;
int ListContainsId(ListHead02046b60*, int);
extern "C" void *func_ov017_021b8478(void *node);
int IsField0xcNonNegative_020a3694(int*);
struct Obj021aa16c;
void InitState60_021aa16c(Obj021aa16c*);
struct HeadList020469f8;
struct HeadNode020469f8;
void PrependNodeToHead(HeadList020469f8*, HeadNode020469f8*);
void Something_021a6b9c(void*, int);
void * GetStatFieldPointer02064904(void*, int, unsigned int);
extern "C" void func_ov017_021a5568(void *node);
void SetBytesAt20And21_021a55a4(unsigned char*, unsigned char, unsigned char);
void *GetBTRandom();
struct Random;
int NextRandomBetween(Random*, int, int);
int NextRandomMax(Random*, int);
extern short data_020e7de8[14];
extern "C" void *memmove(void *dst, const void *src, unsigned int n);
struct Src021cd6d8 {
    short f0, f1, f2, f3;
    unsigned char f4;
    short f5;
    signed char f6;
    float f7;
};
void EnqueueEventTag142_021cd6d8(Src021cd6d8 *ev);
void StoreFields0x1e4And0x1e8IfNonZero_0202ea10(unsigned char*, int, int);
void SetFlag0x4At0x168_0202ea3c(unsigned char*);
struct FlagsAndWords0202ea20;
void ClearTwoWordsAndFlag0x4(FlagsAndWords0202ea20*);
void *GetData02108f0c_0208a9b4();
extern "C" void func_0202c288(void);
struct Obj_021b994c;
void ResetFieldsToDefault_021b994c(Obj_021b994c*);
void EnqueueEventTag153_021d079c(unsigned char, unsigned char, unsigned short);
void NotifyElemAndOverlay17OnFlag020ae990(int key);
extern "C" void func_020aea40(int a, int b);
extern "C" void func_ov017_02191484(void *base);
void ResetStruct020d3c08(char*);
struct Obj020d3c28;
void InitAndMaybeStartStream020d3c28(Obj020d3c28*);
void * GetElementCount0xb4Stride0x24_020d3d78(unsigned char*, int);
extern "C" void func_ov017_021913d0(void *base, int field);
struct ElemFlags3Bit0d3d78 { unsigned char field3 : 3; unsigned char rest : 5; };
extern int data_02108844;
void ResetFieldGroup4444_0218b664(char*);
void EnqueueEventTag154_021d0860(int, int, int);
void SetFieldFromHelper491_02198f70(void*, int);
extern "C" void func_ov017_0219c520(void);
void SetName56AndFlag_0218d7b0(unsigned char*, char*);
struct BitFlag17Entry { unsigned int pad : 17; unsigned int flag17 : 1; };

struct PackedNibbleArray0206e120;
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
struct Struct020d9dec;
void Init020d9dec(Struct020d9dec*, int);
struct S020d9fb4;
void SetFlagBit020d9fb4(S020d9fb4*, int);
void * GetPtrField0x2a04_02010828(GameState*);
int GetField5cb0Value_0201079c(char*);
int GetField5cb4Value_020107d0(char*);
int GetField5cb8Value_02010804(char*);
void ClearRegions0206e080(char*, int);
void ClearIndexedEntryFields0206e0d0(char*, int);
void SetKeyedArrayBit0206e348(unsigned char*, int, int);

#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif

struct CmdMsg64 { unsigned short cmd, p1, p2, p3, p4, p5; unsigned short rest[8]; };

struct FlagsField0x2e { unsigned short pad0x2e_lo : 4; unsigned short flagsHi : 12; };

extern "C" void func_020732cc(int p1);
void SetHalfFieldsAndEnqueueIfActive_021d1c2c(unsigned char a, unsigned short b);
void EnqueueEventTagB5_021d1dc0(unsigned short, int, int*, int, int);
extern AllocatorUnion data_02114e20;
void *AllocateAligned4_02012d88(AllocatorUnion *alloc, unsigned int size);
void TailForward02012da4(AllocatorUnion *alloc, void *data);
extern "C" void *func_02086f24(void *p, unsigned char b, SafeAllocator *alloc);
extern "C" void func_020aee04(unsigned short a, unsigned char b);
extern struct Str02109bf4 {
    char unk[0xc8];
    unsigned char low : 2;
    unsigned char foo : 1;
} data_02109bf4;
extern "C" void _Z27InitAndAppendEntity020dac40P12Root020dac40(void);
void * GetFieldAt0x150_02053c6c(unsigned char*);
struct Slots0208386c;
void RemoveSlotShiftDown0208386c(Slots0208386c*, int);
struct KeyMap020a0a08;
void DecrementKeyValue020a0a08(KeyMap020a0a08*, int, int);
void SyncEightElementFlags_020ae9f0(void);
void RegisterSlotA020cf0fc(int p);
void RegisterSlotB020cf1a8(int p);
void ApplySlotConfig02095cfc(int, int);
extern "C" int func_0202c540(void *ctx);
void CopyOutBattleField0x7ac0_020ac0b4(void *dst);
struct SmallRecord020643e0;
void CopyHalfwordAndTwoBytes(SmallRecord020643e0*, SmallRecord020643e0*);
int GetFieldPercentOver307_020a0870(BattleRecordSnapshot* record);
int GetFieldPercentOver448_020a090c(BattleRecordSnapshot* record);
int GetFieldPercentOver232_020a08a4(BattleRecordSnapshot* record);
int GetFieldPercentOver944_020a08d8(BattleRecordSnapshot* record);

struct SnapshotE7 {
    unsigned char head[8];
    unsigned int a_lo : 17;
    unsigned int a_mid : 7;
    unsigned int a_hi : 7;
    unsigned int a_top : 1;
    unsigned int b_lo : 17;
    unsigned int b_mid : 7;
    unsigned int b_hi : 7;
    unsigned int b_top : 1;
    unsigned int c_lo : 9;
    unsigned int c_mid : 14;
    unsigned int c_top : 9;
    unsigned int d_lo : 8;
    unsigned int d_mid : 14;
    unsigned int d_hi : 10;
    unsigned int e_lo : 24;
    unsigned int done : 1;
    unsigned int e_top : 7;
    unsigned int total;
};
struct SrcWord44 { unsigned int v24 : 24; unsigned int hi8 : 8; };
struct SrcWord48 { unsigned int lo : 14; unsigned int v14 : 14; unsigned int hi : 4; };
struct SrcWord4c { unsigned int v9 : 9; unsigned int v14 : 14; unsigned int hi : 9; };
void *GetGlobalPtr021075f4_0203cf4c(void);
void *FindEntryPointerByKey0203df78(void *g, int key);
struct S02040538;
void * GetField0xc02040538(S02040538*);
void RegisterSlotA020cf0fc(int p);
extern "C" int func_020ac2d4(int a, void *p1, void *p2, int flag);
extern "C" void func_020ac104(void *pooled, void *p1, int flag);
extern char data_0211e33c;
void * InitObj021bdbf0(unsigned char*);
void * InitObj021beba4(char*);
struct Base02019508;
void * FindEntryByKeys02019508(Base02019508*, int, int);
extern "C" void func_0206ea8c(void *obj, unsigned char a, short b, int flag);
struct Struct02013380;
void SetFlag0x40AndToggle0x4(Struct02013380*, int, int);
void InitContext020e1154(void *p);
extern "C" void func_ov017_021a9bc4(void *node, unsigned char b);
extern "C" void func_ov017_021a9a9c(void *node, unsigned char a, unsigned char b, unsigned short c, unsigned char d);
extern "C" void func_ov017_021a8614(void *base, short p1, unsigned short p2, unsigned short p3, unsigned short p4, unsigned short p5);
void EnqueueEventTag141_021ce110(int a, unsigned short b, unsigned short c, unsigned char d);
extern "C" void func_0206e748(void *obj, int a, int b, int c, int d);
struct Node64af8;
struct Obj64af8;
void AppendNodeToField494_02064af8(Obj64af8*, Node64af8*);
struct Obj02061bd8;
int CheckField0x56bLowNibble(Obj02061bd8*);
void TryClearFlags0x130_02048418(unsigned char*, unsigned short);
extern "C" void func_ov017_02191108(void *base, int a, int b, int c, int d);
struct Foo02033b58;
void SetByteSavingPrevious(Foo02033b58*, unsigned char);
void *GetEntryTableBase_02027ca4(void);
struct Element0x318_02028bac;
void * GetElementStride0x318(Element0x318_02028bac*, int);
extern "C" void func_ov017_021a23b0(void *base, unsigned short v);
void EnqueueEventTag134_021c9544(int a, int b, int c, int d);
int GetFieldAt0x0_0202ba00(int *ctx);
void UpdatePlayClocks020ac4f8(int flag);
void SetField5cbcValue_02010810(char*, int);
int GetField5cbcValue_0201081c(char*);

// USA: func_02061c04
struct SharedFrame { unsigned int word0; unsigned short h4, h6, h8; };
struct Vec3 { int x, y, z; };
struct Vec3W { int w[3]; };
struct PackedRegSlots7f { unsigned int f0 : 7; unsigned int f1 : 4; unsigned int f2 : 5;
                          unsigned int f3 : 5; unsigned int f4 : 6; };
union SlotEntry { unsigned int w; struct { unsigned int id : 9; unsigned int pad9 : 2; unsigned int slot : 3; } b; };
struct EntryFlags { unsigned int pad0 : 10; unsigned int bit10 : 1; unsigned int pad11 : 21; };
struct Elem2Flags { unsigned short pad0 : 2; unsigned short bit2 : 1; unsigned short rest : 13; };

struct FrameB { short opt; unsigned short flags; unsigned short h4, h6, h8, ha, hc, he; };

static inline char *SubA(void *b) { return (char *)b + REGION_VALUE(0x2c4, 0x104); }
static inline char *SubB(char *a) { return a + REGION_VALUE(0x7000, 0x7400); }
struct Blk7400 { char pad[REGION_VALUE(0x7000, 0x7400)]; };
static inline int GetSlot332(void *obj) { return *((unsigned char *)obj + 0x332); }
static inline int Field134_30(void *c) { return *(unsigned short *)((char *)*(void **)((char *)c + 0x134) + 0x30); }
static inline int AngleMax() { return 0x6488; }
static inline int FxMul(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }
extern "C" ARM int func_02061c04(void *obj, CmdMsg64 *msg, void *param3) {
    char cdLocal[REGION_VALUE(0xa4, 0xb8)];
    struct { int a0, a1, a2, a3; } sa;
    struct { int b0, b1, b2; } sb;
    struct Vec3 halfOut;
    CmdMsg64 m9b;
    CmdMsg64 m9c;
    CmdMsg64 m9d;
    CmdMsg64 m9e;
    CmdMsg64 m9f;
    struct Src021cd6d8 c0Local;
    unsigned short deck[14];
    struct { int a, b, c; } d8Local;
    SafeAllocator dbAlloc;
    struct Vec3 midOut;
    struct Vec3 half;
    struct Vec3 mid;
    struct Vec3 diff;
    struct LowRegion {
        short p1;
        short pad2;
        unsigned int fword0;
        unsigned short fh4, fh6, fh8;
        unsigned char d0, d1;
        short d2;
        unsigned char d3, d4;
        struct FrameB fb;
        struct PackedRegSlots7f packed;
    } lr;
    switch (msg->cmd) {
    case 0x64: {
        SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, msg->p1, 1);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero_0202b7d8((int *)ctx) && !GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(0, 0, msg->p1, 1);
        return 1;
    }
    case 0x65: {
        SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, msg->p1, 0);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero_0202b7d8((int *)ctx) && !GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(0, 0, msg->p1, 0);
        return 1;
    }
    case 0x66: {
        unsigned char slot = *((unsigned char *)obj + 0x332);
        SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + slot * 0x1c + 3, msg->p1, 1);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero_0202b7d8((int *)ctx) && !GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(3, *((unsigned char *)obj + 0x332), msg->p1, 1);
        return 1;
    }
    case 0x67: {
        unsigned char slot = *((unsigned char *)obj + 0x332);
        SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + slot * 0x1c + 3, msg->p1, 0);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero_0202b7d8((int *)ctx) && !GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(3, *((unsigned char *)obj + 0x332), msg->p1, 0);
        return 1;
    }
    case 0x68: {
        unsigned char slot = *((unsigned char *)obj + 0x332);
        SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + slot * 0x1c + 0x10, msg->p1, 1);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero_0202b7d8((int *)ctx) && !GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 1);
        return 1;
    }
    case 0x69: {
        unsigned char slot = *((unsigned char *)obj + 0x332);
        SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + slot * 0x1c + 0x10, msg->p1, 0);
        void *ctx = func_0202ae18();
        if (CheckField0NonZero_0202b7d8((int *)ctx) && !GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx))
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 0);
        return 1;
    }
    case 0x6a: {
        void *p = func_ov017_0218b5b0();
        unsigned char *r5 = *(unsigned char **)((char *)p + 0x4000 + REGION_VALUE(0x214, 0x4c4));
        ClearNibble0206ece8((int)r5, msg->p1, r5, 0x80);
        ClearNibble0206ece8((int)r5, msg->p1, r5 + 0x80, 0x80);
        return 1;
    }
    case 0x6b: {
        void *ctx = func_0202ae18();
        if (func_0202c508(ctx))
            SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, 0x113a, ((unsigned char *)msg)[2] == 0);
        return 1;
    }
    case 0x6c: {
        void *p0 = func_02012fe4();
        void *node = GetPointerFromArray0x3c_0201e838((unsigned char *)((char *)p0 + REGION_VALUE(0x8c, 0x6c)), 2);
        while (node) {
            if (*((unsigned char *)node + 0x2c) == msg->p2 &&
                *((unsigned char *)node + 0x2d) == msg->p3 &&
                *(short *)((char *)node + 0x20) == (short)msg->p1) {
                FlagsField0x2e *f = (FlagsField0x2e *)((char *)node + 0x2e);
                if (!(f->flagsHi & 1))
                    f->flagsHi |= 4;
            }
            node = *(void **)((char *)node + 0x70);
        }
        return 1;
    }
    case 0x6d: {
        Zone3D* p0 = (Zone3D*)func_02012fe4();
        ZoneFeatures::Opcode6aEntry* node = (ZoneFeatures::Opcode6aEntry*)GetPointerFromArray0x3c_0201e838((unsigned char*)&p0->substruct_6c_, 2);
        while (node) {
            if (!(node->unk_2c.type2.unk_2_high & 1) &&
                node->unk_2c.type2.unk_0 == msg->p2 &&
                node->unk_2c.type2.unk_1 == msg->p3 &&
                node->unk_20 == (short)msg->p1) {
                func_02018300(p0, node, 1, 1, 1);
            }
            node = node->pNext;
        }
        return 1;
    }
    case 0x99: {
        Zone3D* p0 = (Zone3D*)func_02012fe4();
        ZoneFeatures::Opcode6aEntry* node = (ZoneFeatures::Opcode6aEntry*)GetPointerFromArray0x3c_0201e838((unsigned char*)&p0->substruct_6c_, 2);
        while (node) {
            if (!(node->unk_2c.type2.unk_2_high & 1) &&
                node->unk_2c.type2.unk_0 == msg->p2 &&
                node->unk_2c.type2.unk_1 == msg->p3 &&
                node->unk_20 == (short)msg->p1) {
                node->unk_2c.type2.unk_2_high |= 0x100;
                func_02018300(p0, node, 0, 1, 1);
            }
            node = node->pNext;
        }
        return 1;
    }
    case 0x6e: {
        GameState *battle = GameState::GetInstance();
        battle->SetTimeOfDay((TimeOfDay)msg->p1);
        LightingManager *d = LightingManager::GetInstance();
        d->dayNightTimer_ = battle->GetDayTimer();
        d->timeOfDayIndex_ = battle->GetTimeOfDay();
        void *ctx = func_0202ae18();
        if (func_0202c508(ctx))
            EnqueueEventTag147_021cdaa0();
        return 1;
    }
    case 0x72:
        msg->p2 = 1;
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x73:
        msg->p2 = 1;
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x74:
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x75:
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x76:
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x77:
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x78:
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x79: case 0x89: case 0xe1:
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x7a:
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x7b:
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x7c:
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x7d: {
        if (func_020961b0(GetGlobal02109418_02094d6c(), msg->p1) == 0)
            return 0;
        if (!TestBitInByteArray_0206dfb0((int)obj, (unsigned char *)obj + 0x8c, 0x119d)) {
            void *p = func_ov017_0218b5b0();
            void *list = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
            SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, 0x119d, 1);
            void *node = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x9a0, 0xbc0));
            Init020d9ae8((Struct020d9ae8 *)node, 1);
            AppendNodeToTail((TailList020469b4 *)list, (TailNode020469b4 *)node);
        }
        return 1;
    }
    case 0x7e: {
        int isTwo = GetPackedNibbleField((PackedNibbleArray0206e120*)obj, msg->p1) == 2;
        if (!isTwo)
            return 1;
        void *p = func_ov017_0218b5b0();
        void *list = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x99c, 0xbbc));
        Init020d9dec((Struct020d9dec*)node, 0);
        SetFlagBit020d9fb4((S020d9fb4*)node, 0);
        *(int *)((char *)node + 0x10) = msg->p1;
        if (*((unsigned char *)node + 2) == 0)
            AppendNodeToTail((TailList020469b4 *)list, (TailNode020469b4 *)node);
        return 1;
    }
    case 0x7f: {
        RegisterSlotA020cf0fc((int)&sa);
        RegisterSlotB020cf1a8((int)&sb);
        lr.packed.f0 = sa.a0;
        lr.packed.f1 = sa.a1;
        lr.packed.f2 = sa.a2;
        lr.packed.f3 = sb.b0;
        lr.packed.f4 = sb.b1;
        void *g = GetGlobal02109418_02094d6c();
        *(unsigned int *)((char *)g + msg->p1 * 4 + 0x178) = *(unsigned int *)&lr.packed;
        ApplySlotConfig02095cfc((int)g, msg->p1);
        return 1;
    }
    case 0x80:
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x81:
        func_0206e164(obj, msg->p1, 1);
        return 1;
    case 0x82: {
        void *ctx = func_0202ae18();
        if (CheckField0NonZero_0202b7d8((int *)ctx)) {
            FindEntryById02096134((FindEntryById02096134Table *)GetGlobal02109418_02094d6c(), msg->p1);
            if (!GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx)) {
                if (msg->p2 < 0x400)
                    func_ov017_021d0924(0, 0, msg->p2, 1);
                SetBitWithOffset0206eb64((unsigned char *)obj, msg->p2, 1);
            } else {
                SetBitWithOffset0206eb64((unsigned char *)obj, msg->p2, 1);
            }
        } else {
            SetBitWithOffset0206eb64((unsigned char *)obj, msg->p2, 1);
        }
        return 1;
    }
    case 0x83: {
        void *ctx = func_0202ae18();
        if (CheckField0NonZero_0202b7d8((int *)ctx)) {
            void *entry = FindEntryById02096134((FindEntryById02096134Table *)GetGlobal02109418_02094d6c(), msg->p1);
            if (!GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx)) {
                if (!(entry != 0 && ((struct EntryFlags *)entry)->bit10 == 1) &&
                    msg->p2 < 0x400)
                    func_ov017_021d0924(0, 0, msg->p2, 0);
                SetBitWithOffset0206eb64((unsigned char *)obj, msg->p2, 0);
            } else {
                if (entry != 0 && ((struct EntryFlags *)entry)->bit10 == 1)
                    SetBitWithOffset0206eb64((unsigned char *)obj, msg->p2, 0);
            }
        } else {
            SetBitWithOffset0206eb64((unsigned char *)obj, msg->p2, 0);
        }
        return 1;
    }
    case 0x84: {
        GameState *battle = GameState::GetInstance();
        lr.fb.ha = GetField5cb0Value_0201079c((char*)battle);
        lr.fb.hc = GetField5cb4Value_020107d0((char*)battle);
        lr.fb.he = GetField5cb8Value_02010804((char*)battle);
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        if (lr.fb.ha != msg->p2)
            ClearRegions0206e080((char*)obj, *((unsigned char *)obj + 0x332));
        if (lr.fb.hc != msg->p3)
            ClearIndexedEntryFields0206e0d0((char*)obj, *((unsigned char *)obj + 0x332));
        return 1;
    }
    case 0x85: case 0x8a: case 0xe2:
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x86: {
        void *ctx = func_0202ae18();
        if (CheckField0NonZero_0202b7d8((int *)ctx))
            EnqueueEventTag141_021ce110((unsigned char)msg->p2, 1, msg->p1, 1);
        switch (msg->p2) {
        case 3:
            SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, msg->p1, 1);
            func_ov017_021d0924(0, 0, msg->p1, 1);
            if (func_0202c540(ctx))
                func_0206e748(obj, 0, 0, msg->p1, 1);
            break;
        case 4: {
            SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 3, msg->p1, 1);
            func_ov017_021d0924(3, *((unsigned char *)obj + 0x332), msg->p1, 1);
            if (func_0202c540(ctx)) {
                int slot1 = GetSlot332(obj);
                func_0206e748(obj, 3, slot1, msg->p1, 1);
            }
            break;
        }
        case 5: {
            SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 0x10, msg->p1, 1);
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 1);
            if (func_0202c540(ctx)) {
                int slot2 = GetSlot332(obj);
                func_0206e748(obj, 5, slot2, msg->p1, 1);
            }
            break;
        }
        default:
            break;
        }
        return 1;
    }
    case 0x87: {
        void *ctx = func_0202ae18();
        if (CheckField0NonZero_0202b7d8((int *)ctx))
            EnqueueEventTag141_021ce110((unsigned char)msg->p2, 0, msg->p1, 1);
        switch (msg->p2) {
        case 3:
            SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, msg->p1, 0);
            func_ov017_021d0924(0, 0, msg->p1, 0);
            if (func_0202c540(ctx))
                func_0206e748(obj, 0, 0, msg->p1, 0);
            break;
        case 4: {
            SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 3, msg->p1, 0);
            func_ov017_021d0924(3, *((unsigned char *)obj + 0x332), msg->p1, 0);
            if (func_0202c540(ctx)) {
                int slot3 = GetSlot332(obj);
                func_0206e748(obj, 3, slot3, msg->p1, 0);
            }
            break;
        }
        case 5: {
            SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + *((unsigned char *)obj + 0x332) * 0x1c + 0x10, msg->p1, 0);
            func_ov017_021d0924(5, *((unsigned char *)obj + 0x332), msg->p1, 0);
            if (func_0202c540(ctx)) {
                int slot4 = GetSlot332(obj);
                func_0206e748(obj, 5, slot4, msg->p1, 0);
            }
            break;
        }
        default:
            break;
        }
        return 1;
    }
    case 0x88: {
        void *p0 = func_02012fe4();
        void *node = GetPointerFromArray0x3c_0201e838((unsigned char *)((char *)p0 + REGION_VALUE(0x8c, 0x6c)), 2);
        while (node) {
            if (*((unsigned char *)node + 0x2c) == msg->p2 &&
                *((unsigned char *)node + 0x2d) == msg->p3 &&
                *(short *)((char *)node + 0x20) == (short)msg->p1) {
                FlagsField0x2e *f = (FlagsField0x2e *)((char *)node + 0x2e);
                f->flagsHi &= ~4;
            }
            node = *(void **)((char *)node + 0x70);
        }
        return 1;
    }
    case 0x8b: {
        GameState *battle = GameState::GetInstance();
        void *p = GetPtrField0x2a04_02010828((GameState*)battle);
        unsigned int v = *(unsigned int *)((char *)p + 0xf6c) + *(unsigned int *)((char *)msg + 4);
        *(unsigned int *)((char *)p + 0xf6c) = v;
        if (v > 9999999)
            *(unsigned int *)((char *)p + 0xf6c) = 9999999;
        return 1;
    }
    case 0x8c: {
        GameState *battle = GameState::GetInstance();
        void *p = GetPtrField0x2a04_02010828((GameState*)battle);
        unsigned int v = *(unsigned int *)((char *)p + 0xf6c);
        unsigned int d = *(unsigned int *)((char *)msg + 4);
        *(unsigned int *)((char *)p + 0xf6c) = (v < d) ? 0 : (v - d);
        return 1;
    }
    case 0x8d:
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x8e:
        SetKeyedArrayBit0206e348((unsigned char*)obj, msg->p1, 1);
        return 1;
    case 0x8f: {
        if (msg->p1 == 2)
            return 1;
        void *base = func_ov017_0218b5b0();
        void *mem = ((SafeAllocator *)((char *)base + 0x164))->Allocate(0x30);
        if (mem) {
            func_02012fe4();
            struct Msg8fExt { short cmd, pad2; int f4, f8, fc, f10; int *f14; } *m = (struct Msg8fExt *)msg;
            char *n = (char *)mem;
            *(short *)(n + 0) = (short)m->f4;
            *(int *)(n + 0x14) = m->f8;
            *(int *)(n + 0x1c) = m->f10;
            *(int *)(n + 0x18) = m->fc;
            int *p14 = m->f14;
            *(int *)(n + 0x20) = p14[1];
            *(int *)(n + 0x28) = p14[3];
            *(int *)(n + 0x24) = p14[2];
            *(short *)(n + 2) = (short)(4096.0f * (3.14159274f * (float)p14[4] / 180.0f));
            short angle = *(short *)(n + 2);
            int lim = 0x6488;
            if (angle > lim)
                *(short *)(n + 2) -= lim;
            else if (angle < 0)
                *(short *)(n + 2) = angle + 0x6488;

                mid.x = (*(int *)(n + 0x14) + *(int *)(n + 0x20)) >> 1;
            mid.y = (*(int *)(n + 0x18) + *(int *)(n + 0x24)) >> 1;
            mid.z = (*(int *)(n + 0x1c) + *(int *)(n + 0x28)) >> 1;
            *(struct Vec3W *)&midOut = *(struct Vec3W *)&mid;
            *(int *)(n + 4) = midOut.x;
            *(int *)(n + 8) = midOut.y;
            *(int *)(n + 0xc) = midOut.z;

            diff.x = *(int *)(n + 0x14) - *(int *)(n + 0x20);
            diff.y = *(int *)(n + 0x18) - *(int *)(n + 0x24);
            diff.z = *(int *)(n + 0x1c) - *(int *)(n + 0x28);
            *(struct Vec3W *)&half = *(struct Vec3W *)&diff;
            *(struct Vec3W *)&halfOut = *(struct Vec3W *)&half;
            int hx = halfOut.x / 2;
            int hy = halfOut.y / 2;
            int sqy = FxMul(hy, hy);
            int sqx = FxMul(hx, hx);
            *(int *)(n + 0x10) = sqx + sqy;
            *(int *)(n + 0x2c) = 0;

            AppendNodeToField494_02064af8((Obj64af8*)obj, (Node64af8*)mem);
        }
        return 1;
    }
    case 0x90: {
        void *ctx = func_0202ae18();
        if (func_0202c540(ctx))
            return 1;
        int isTwo = GetPackedNibbleField((PackedNibbleArray0206e120*)obj, msg->p1) == 2;
        if (!isTwo)
            return 1;
        unsigned int *p = (unsigned int *)((char *)GetGlobal02109418_02094d6c() + 4);
        while (p) {
            union SlotEntry *e = (union SlotEntry *)p;
            if (e->b.id == (unsigned short)msg->p1) {
                e->b.slot = msg->p2;
                break;
            }
            p = (unsigned int *)((char *)p + 0x10);
        }
        return 1;
    }
    case 0x91:
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    case 0x92:
        SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x776, 1);
        return 1;
    case 0x93:
        SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x776, 0);
        return 1;
    case 0x94: {
        GameState *battle = GameState::GetInstance();
        lr.fb.h4 = GetField5cb0Value_0201079c((char*)battle);
        lr.fb.h6 = GetField5cb4Value_020107d0((char*)battle);
        lr.fb.h8 = GetField5cb8Value_02010804((char*)battle);
        msg->p1 = 5;
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    }
    case 0x95: {
        void *p0 = func_02012fe4();
        if (!p0)
            return 0;
        void *entry = FindEntryByKeys02019508((Base02019508*)p0, msg->p1, msg->p2);
        if (!entry) {
            func_0206ea8c(obj, (unsigned char)msg->p1, (short)(msg->p2 + 0x80), 1);
            func_0206ea8c(obj, (unsigned char)msg->p1, (short)msg->p2, 0);
            return 1;
        }
        SetFlag0x40AndToggle0x4((Struct02013380*)entry, msg->p1, 0);
        return 1;
    }
    case 0x96: {
        void *p0 = func_02012fe4();
        if (!p0)
            return 0;
        void *entry = FindEntryByKeys02019508((Base02019508*)p0, msg->p1, msg->p2);
        if (!entry) {
            func_0206ea8c(obj, (unsigned char)msg->p1, (short)(msg->p2 + 0x80), 0);
            func_0206ea8c(obj, (unsigned char)msg->p1, (short)msg->p2, 1);
            return 1;
        }
        SetFlag0x40AndToggle0x4((Struct02013380*)entry, msg->p1, 1);
        return 1;
    }
    case 0x97: {
        void *p = func_ov017_0218b5b0();
        void *list = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x940, 0xb60));
        InitObj021bdbf0((unsigned char*)node);
        *((unsigned char *)node + 0x11) = msg->p1;
        PrependNodeToHead((HeadList020469f8*)list, (HeadNode020469f8*)node);
        return 1;
    }
    case 0x9b: {
        m9b.cmd = 0x68;
        m9b.p1 = msg->p2;
        func_02061c04(obj, &m9b, param3);
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    }
    case 0x9c: {
        m9c.cmd = 0x7f;
        m9c.p1 = msg->p1;
        func_02061c04(obj, &m9c, param3);
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    }
    case 0x9d: {
        switch ((short)msg->p2) {
        case 0: m9d.cmd = 0x7d; break;
        case 2: m9d.cmd = 0x7f; break;
        case 3: m9d.cmd = 0x81; break;
        default: return 0;
        }
        m9d.p1 = msg->p1;
        func_02061c04(obj, &m9d, param3);
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    }
    case 0x9e: {
        m9e.cmd = 0x75;
        m9e.p1 = msg->p1;
        m9e.p2 = msg->p2;
        return func_02061c04(obj, &m9e, param3);
    }
    case 0x9f: {
        m9f.cmd = 0x74;
        m9f.p1 = msg->p1;
        m9f.p2 = msg->p2;
        return func_02061c04(obj, &m9f, param3);
    }
    case 0xa0:
        SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x113f, 1);
        return 1;
    case 0xa1: {
        lr.fb.flags &= ~1;
        lr.fb.opt = -1;
        lr.fb.flags &= ~2;
        lr.fb.flags &= ~0xfffcu;
        lr.p1 = msg->p1;
        if (func_020ac2d4(0, &lr.p1, &lr.fb.opt, 1)) {
            lr.fb.flags |= 2;
            func_020ac104(&data_0211e33c, &lr.fb.opt, 1);
        }
        return 1;
    }
    case 0xa2:
        if (msg->p1 != 0)
            SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, 0x113b, 0);
        else
            SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, 0x113b, 1);
        return 1;
    case 0xc0: {
        GameState *battle = GameState::GetInstance();
        void *p0 = func_02012fe4();
        func_0202ae18();
        c0Local.f0 = 0;
        c0Local.f1 = 0;
        c0Local.f2 = 0;
        c0Local.f3 = 0;
        c0Local.f4 = 0;
        c0Local.f5 = 0;
        c0Local.f7 = 0;
        c0Local.f6 = -1;
        c0Local.f0 = *(unsigned short *)p0;
        c0Local.f1 = msg->p1;
        c0Local.f2 = 0;
        c0Local.f4 = 1;
        c0Local.f3 = -1;
        c0Local.f7 = battle->GetDayTimer();
        EnqueueEventTag142_021cd6d8(&c0Local);
        return 1;
    }
    case 0xa4: {
        void *p = func_ov017_0218b5b0();
        func_ov017_021c1a98(p, 0);
        return 1;
    }
    case 0xa5: {
        GameState *battle = GameState::GetInstance();
        void *combatant = battle->GetGameObjectByIndex(0);
        SetBitInArray0x8ec_02083acc((unsigned char*)(*(void **)((char *)combatant + REGION_VALUE(0x144, 0x150))), msg->p1);
        return 1;
    }
    case 0xa6: {
        GameState *battle = GameState::GetInstance();
        void *combatant = battle->GetGameObjectByIndex(0);
        SetBitInArray0x910_02083b60((unsigned char*)(*(void **)((char *)combatant + REGION_VALUE(0x144, 0x150))), msg->p1);
        return 1;
    }
    case 0xa7: {
        unsigned char b = ((unsigned char *)msg)[2];
        if (b == 0)
            ToggleElemKey2FlagInMap2010_020ae6e8(((unsigned char *)msg)[4]);
        else if (b == 6)
            SetElemFlag8IfOverlayActive020ae730(((unsigned char *)msg)[4]);
        return 1;
    }
    case 0xa8:
        return 1;
    case 0xa9:
        if (((unsigned char *)msg)[2] == 0)
            SetElemFlag0x4PairAndNotify17_020ae7d4(((unsigned char *)msg)[4]);
        return 1;
    case 0xaa:
        SetElemFlag0x4QuadAndNotify17_020ae880((unsigned char)msg->p1);
        return 1;
    case 0xab:
        return 1;
    case 0xac:
        return 1;
    case 0xad:
        return 1;
    case 0xae:
        return 1;
    case 0xaf:
        SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x1136, 0);
        return 1;
    case 0xb0: {
        void *global = GetGlobal02109418_02094d6c();
        BitFlag17Entry *entry = (BitFlag17Entry *)FindEntryById02096134((FindEntryById02096134Table *)global, msg->p1);
        if (entry)
            entry->flag17 = msg->p2;
        return 1;
    }
    case 0xb1: {
        GameState *battle = GameState::GetInstance();
        battle->SetTimeOfDay((TimeOfDay)msg->p2);
        LightingManager *d = LightingManager::GetInstance();
        d->dayNightTimer_ = battle->GetDayTimer();
        d->timeOfDayIndex_ = battle->GetTimeOfDay();
        battle->SetDayTimerRunning(msg->p1 == 0);
        return 1;
    }
    case 0xb2: {
        void *base = func_ov017_0218b5b0();
        void *list = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x948, 0xb68));
        InitContext020e1154((void *)0xbb8);
        func_ov017_021a9bc4(node, ((unsigned char *)msg)[2]);
        func_ov017_021a9a9c(node, ((unsigned char *)msg)[4], ((unsigned char *)msg)[5], msg->p3,
                            ((unsigned char *)msg)[8]);
        AppendNodeToTail((TailList020469b4 *)list, (TailNode020469b4 *)node);
        return 1;
    }
    case 0xb3: {
        GameState *battle = GameState::GetInstance();
        void *p = GetPtrField0x2a04_02010828((GameState*)battle);
        if (msg->p1 != 0) {
            SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, 0x113c, 1);
            *(unsigned int *)((char *)p + 0x2c94) = msg->p2;
        } else {
            SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, 0x113c, 0);
            *(unsigned int *)((char *)p + 0x2c94) = *(unsigned int *)((char *)battle + REGION_VALUE(0x7c34, 0x7e74));
            void *ctx = func_0202ae18();
            if (CheckField0NonZero_0202b7d8((int *)ctx) && !GetSearchStructCurrentArrEntry((SearchStruct0202c1a4 *)ctx))
                EnqueueEventTag23Field_021d0d58();
        }
        return 1;
    }
    case 0xb4: {
        void *base = func_ov017_0218b5b0();
        void *list = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        if (!ListContainsId((ListHead02046b60*)list, 0xa))
            return 1;
        void *node = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x508, 0x718));
        void *r = func_ov017_021b8478(node);
        if (!IsField0xcNonNegative_020a3694((int*)r))
            return 1;
        *(short *)((char *)r + 0x22) = (*(int *)((char *)r + 0xc) == msg->p1) ? msg->p2 : 0;
        return 1;
    }
    case 0xb5:
        return 1;
    case 0xb6:
        return 1;
    case 0xb7:
        return 1;
    case 0xb8: {
        void *base = func_ov017_0218b5b0();
        void *list = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x968, 0xb88));
        InitState60_021aa16c((Obj021aa16c*)node);
        PrependNodeToHead((HeadList020469f8*)list, (HeadNode020469f8*)node);
        return 1;
    }
    case 0xb9: {
        void *base = func_ov017_0218b5b0();
        Something_021a6b9c(base, 0);
        return 1;
    }
    case 0xba:
        SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, 0x1138, msg->p1);
        return 1;
    case 0xbb:
        *(unsigned short *)((char *)obj + 0x2ca) = 0;
        return 1;
    case 0xbc: {
        void *p = GetStatFieldPointer02064904(obj, msg->p1, msg->p2);
        if (p) {
            switch (msg->p4) {
            case 0:
                *(unsigned short *)p = msg->p3;
                break;
            case 1: {
                int v = *(unsigned short *)p + msg->p3;
                if (v >= 0xffff)
                    *(unsigned short *)p = 0xffff;
                else
                    *(unsigned short *)p = v;
                break;
            }
            case 2: {
                int v = *(unsigned short *)p - msg->p3;
                if (v < 0)
                    *(unsigned short *)p = 0;
                else
                    *(unsigned short *)p = v;
                break;
            }
            default:
                break;
            }
        }
        return 1;
    }
    case 0xbd: {
        void *base = func_ov017_0218b5b0();
        void *list = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x50c, 0x71c));
        func_ov017_021a5568(node);
        SetBytesAt20And21_021a55a4((unsigned char*)node, 1, ((unsigned char *)msg)[2]);
        *(unsigned char *)((char *)node + 0x24) = 0;
        *(int *)((char *)node + 0x28) = 0;
        *(int *)((char *)node + 0x2c) = -1;
        AppendNodeToTail((TailList020469b4 *)list, (TailNode020469b4 *)node);
        return 1;
    }
    case 0xbe: {
        if (!FindEntryById02096134((FindEntryById02096134Table *)GetGlobal02109418_02094d6c(), msg->p1))
            break;
        void *p = GetStatFieldPointer02064904(obj, msg->p1, msg->p2);
        if (!p)
            return 0;
        *(unsigned short *)p = NextRandomBetween((Random*)GetBTRandom(), msg->p3, msg->p4);
        return 1;
    }
    case 0xbf: {
        unsigned short count = 14;
        int n = 14;
        unsigned short *dst = deck;
        unsigned short *src = (unsigned short *)data_020e7de8;
        do {
            *dst = *src;
            ++src;
            ++dst;
        } while (--n);
        void *entry = FindEntryById02096134((FindEntryById02096134Table *)GetGlobal02109418_02094d6c(), msg->p1);
        if (!entry)
            break;
        for (int j = 0; j < 5; j++) {
            int idx = NextRandomMax((Random*)GetBTRandom(), count);
            *(short *)((char *)entry + j * 2 + 4) = deck[idx];
            if (idx < count - 1)
                memmove(&deck[idx], &deck[idx + 1], count - (idx + 1));
            count--;
            deck[count] = 0;
        }
        return 1;
    }
    case 0xc1: {
        GameState *battle = GameState::GetInstance();
        void *rec = GetField0x3b0Value_020100bc(battle);
        if (msg->p1 != 0) {
            StoreFields0x1e4And0x1e8IfNonZero_0202ea10((unsigned char*)rec, 0x333, 1);
            SetFlag0x4At0x168_0202ea3c((unsigned char*)rec);
        } else {
            ClearTwoWordsAndFlag0x4((FlagsAndWords0202ea20*)rec);
        }
        return 1;
    }
    case 0xc2: {
        void *d = GetData02108f0c_0208a9b4();
        *(unsigned char *)((char *)d + 0xa8) = msg->p1 * 10;
        return 1;
    }
    case 0xc3:
        func_ov017_0218b5b0();
        return 1;
    case 0xc4:
        return 1;
    case 0xc5: {
        GameState *battle = GameState::GetInstance();
        void *ctx = func_0202ae18();
        int v = GetFieldAt0x0_0202ba00((int *)ctx);
        int byte = *((unsigned char *)ctx + 0x1000 + 0xd);
        int flag = 0;
        if ((v == 5 && byte > 1) || v == 6)
            flag = 1;
        UpdatePlayClocks020ac4f8(flag);
        int cur = GetField5cbcValue_0201081c((char*)battle);
        int newVal = msg->p1;
        int a = cur;
        if (cur >= 0xd && cur <= 0xd) a = cur;
        else if (cur >= 0xe && cur <= 0xf) a = cur;
        else if (cur >= 0x10 && cur <= 0x11) a = cur;
        else if (cur >= 0x12 && cur <= 0x18) a = cur;
        else if (cur >= 0x19 && cur <= 0x1b) a = cur;
        else if (cur >= 0x1c && cur <= 0x21) a = cur;
        else if (cur >= 0x22 && cur <= 0x26) a = cur;
        else if (cur >= 0x28 && cur <= 0x5c) a = cur;
        else if (cur >= 0x5d && cur <= 0x5d) a = cur;
        else if (cur >= 0x5e && cur <= 0x64) a = cur;
        else if (cur >= 0x65 && cur <= 0x68) a = cur;
        else if (cur >= 0x69 && cur <= 0x6b) a = cur;
        else if (cur >= 0x6c && cur <= 0x71) a = cur;
        else if (cur >= 0x7b && cur <= 0x7c) a = cur;
        else if (cur >= 0x7d && cur <= 0x80) a = cur;
        else if (cur >= 0x81 && cur <= 0x85) a = cur;
        else if (cur >= 0x86 && cur <= 0x89) a = cur;
        else if (cur >= 0x8a && cur <= 0x8c) a = cur;
        else if (cur >= 0x8d && cur <= 0x92) a = cur;
        else if (cur >= 0x94 && cur <= 0x94) a = cur;
        int b = newVal;
        if (newVal >= 0xd && newVal <= 0xd) b = newVal;
        else if (newVal >= 0xe && newVal <= 0xf) b = newVal;
        else if (newVal >= 0x10 && newVal <= 0x11) b = newVal;
        else if (newVal >= 0x12 && newVal <= 0x18) b = newVal;
        else if (newVal >= 0x19 && newVal <= 0x1b) b = newVal;
        else if (newVal >= 0x1c && newVal <= 0x21) b = newVal;
        else if (newVal >= 0x22 && newVal <= 0x26) b = newVal;
        else if (newVal >= 0x28 && newVal <= 0x5c) b = newVal;
        else if (newVal >= 0x5d && newVal <= 0x5d) b = newVal;
        else if (newVal >= 0x5e && newVal <= 0x64) b = newVal;
        else if (newVal >= 0x65 && newVal <= 0x68) b = newVal;
        else if (newVal >= 0x69 && newVal <= 0x6b) b = newVal;
        else if (newVal >= 0x6c && newVal <= 0x71) b = newVal;
        else if (newVal >= 0x7b && newVal <= 0x7c) b = newVal;
        else if (newVal >= 0x7d && newVal <= 0x80) b = newVal;
        else if (newVal >= 0x81 && newVal <= 0x85) b = newVal;
        else if (newVal >= 0x86 && newVal <= 0x89) b = newVal;
        else if (newVal >= 0x8a && newVal <= 0x8c) b = newVal;
        else if (newVal >= 0x8d && newVal <= 0x92) b = newVal;
        else if (newVal >= 0x94 && newVal <= 0x94) b = newVal;
        if (a != b) {
            memset(SubB(SubA(battle)) + 0xa4, 0, 0x28);
        }
        SetField5cbcValue_02010810((char*)battle, msg->p1);
        return 1;
    }
    case 0xc6: {
        void *ctx = func_0202ae18();
        func_0202c288();
        int lvl = *((unsigned char *)ctx + 0x100d);
        if (lvl <= 1)
            return 0;
        void *base = func_ov017_0218b5b0();
        void *rec = *(void **)((char *)base + 0x3000 + REGION_VALUE(0x500, 0x710));
        ResetFieldsToDefault_021b994c((Obj_021b994c*)rec);
        *((unsigned char *)rec + 0x130) = 1;
        GameState *battle = GameState::GetInstance();
        int v = *(int *)((char *)battle + 0x5000 + REGION_VALUE(0x4c4, 0x724));
        EnqueueEventTag153_021d079c(4, 0, (unsigned short)v);
        *(int *)((char *)rec + 0x12c) = v;
        return 1;
    }
    case 0xc7:
        NotifyElemAndOverlay17OnFlag020ae990(msg->p1 & 0xff);
        return 1;
    case 0xc8:
        return 1;
    case 0xc9: {
        unsigned char b = ((unsigned char *)msg)[2];
        if (b <= 7)
            func_020aea40(b, ((unsigned char *)msg)[4]);
        return 1;
    }
    case 0xca:
        SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0x1198, 1);
        return 1;
    case 0xcb: {
        GameState *battle = GameState::GetInstance();
        void *base = func_ov017_0218b5b0();
        for (int i = 0; i < 4; i++) {
            GameObject *combatant = GetCombatantWithFlag0x100_0200ff1c(battle, i);
            if (!combatant)
                continue;
            if (!CheckField0x56bLowNibble((Obj02061bd8*)combatant))
                continue;
            int hp = *(unsigned short *)((char *)*(void **)((char *)combatant + 0x130) + 4);
            if (hp > 0)
                continue;
            if (msg->p1 == 0) {
                unsigned short val = *(unsigned short *)((char *)*(void **)((char *)combatant + 0x134) + 0x30);
                ClearFieldBit02053fe4(combatant, val, 1);
            } else if (msg->p1 == 1) {
                int val = Field134_30(combatant);
                ClearFieldBit02053fe4(combatant, val / 2, 1);
            } else {
                ClearFieldBit02053fe4(combatant, 1, 1);
            }
            TryClearFlags0x130_02048418((unsigned char*)combatant, 1);
            func_ov017_02191108(base, 1, 1, 1, 1);
            SetByteSavingPrevious((Foo02033b58*)combatant, 0);
            *(short *)((char *)combatant + 0xb2) = 0;
        }
        return 1;
    }
    case 0xcc:
        func_ov017_02191484(func_ov017_0218b5b0());
        return 1;
    case 0xcd: {
        void *base = func_ov017_0218b5b0();
        ResetStruct020d3c08((char*)cdLocal);
        InitAndMaybeStartStream020d3c28((Obj020d3c28*)cdLocal);
        void *elem = GetElementCount0xb4Stride0x24_020d3d78((unsigned char*)cdLocal, msg->p1);
        if (elem) {
            ElemFlags3Bit0d3d78 *f = (ElemFlags3Bit0d3d78 *)((char *)elem + REGION_VALUE(0xb, 0x10));
            func_ov017_021913d0(base, f->field3);
        }
        return 1;
    }
    case 0xce: {
        SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, 0x79a, 1);
        void *ctx = func_0202ae18();
        if (func_0202c508(ctx)) {
            int rowBase;
            GameState *battle = GameState::GetInstance();
            void *base = func_ov017_0218b5b0();
            void *table = GetEntryTableBase_02027ca4();
            for (int a = 0; a < 4; a++) {
                void *elem = GetElementStride0x318((Element0x318_02028bac*)table, a);
                if (!((struct Elem2Flags *)((char *)elem + 2))->bit2)
                    continue;
                unsigned short val = *(unsigned short *)elem;
                if ((val / 100) * 100 != 400)
                    continue;
                rowBase = a * 0xc + 0x70;
                for (int b = 0; b < 0xc; b++) {
                    void *c2 = battle->GetMaybeFieldMonsterByIndex(b + rowBase);
                    if (!c2)
                        continue;
                    unsigned short v = *(unsigned short *)((char *)c2 + 0x100 + 0x6a);
                    func_ov017_021a23b0(base, v);
                    short p2 = *(short *)((char *)c2 + 2);
                    unsigned short valElem = *(unsigned short *)elem;
                    EnqueueEventTag134_021c9544(valElem, b, p2, -1);
                }
            }
        }
        return 1;
    }
    case 0xcf: {
        void *pool = &data_02108844;
        if (pool)
            SetOrClearBitInArray_0206df6c(pool, (unsigned char *)pool + 0x8c, 0x384, msg->p1);
        void *base = func_ov017_0218b5b0();
        for (int i = 0; i < 4; i++)
            *(unsigned short *)((char *)base + REGION_VALUE(0x4100, 0x4400) + i * 2 + REGION_VALUE(0x9a, 0x4a)) =
                *(unsigned short *)((char *)msg + i * 2 + 4);
        return 1;
    }
    case 0xd0: {
        void *ctx = func_0202ae18();
        if (func_0202c508(ctx)) {
            GameState *battle = GameState::GetInstance();
            void *p = GetPtrField0x2a04_02010828((GameState*)battle);
            *(unsigned int *)((char *)p + 0x2c94) = msg->p1;
            *(unsigned int *)((char *)battle + REGION_VALUE(0x7c34, 0x7e74)) = msg->p1;
            EnqueueEventTag23Field_021d0d58();
        }
        return 1;
    }
    case 0xd1: {
        void *base = func_ov017_0218b5b0();
        void *ctx = func_0202ae18();
        func_0202c288();
        int lvl = *((unsigned char *)ctx + 0x100d);
        if (lvl <= 1)
            return 1;
        ResetFieldGroup4444_0218b664((char*)base);
        GameState::GetInstance();
        signed char b = *((signed char *)base + REGION_VALUE(0x4196, 0x4446));
        EnqueueEventTag154_021d0860(4, 0, b);
        *((unsigned char *)base + REGION_VALUE(0x4198, 0x4448)) = 1;
        b = *((signed char *)base + REGION_VALUE(0x4196, 0x4446));
        *((unsigned char *)base + REGION_VALUE(0x4197, 0x4447)) = b;
        return 0;
    }
    case 0xd2: {
        void *base = func_ov017_0218b5b0();
        SetFieldFromHelper491_02198f70(base, *((signed char *)base + REGION_VALUE(0x4196, 0x4446)));
        return 1;
    }
    case 0xd3: {

        struct Foo
        {
              char unk[0x1840];
            struct Bar {
                char unk[0xb4c];
                unsigned int num;
            } bar;
        };

        struct Sub {
            char unk[0x1000];
            Foo::Bar bar;
        };
        unsigned int mask = 1 << msg->p1;
        ((Sub *)((char *)func_02012fe4() + REGION_VALUE(0x860, 0x840)))->bar.num |= mask;
        return 1;
    }
    case 0xd4:
        func_ov017_0219c520();
        return 1;
    case 0xd5: {
        lr.d0 = 0;
        lr.d1 = 0;
        lr.d2 = 0;
        lr.d3 = 0;
        lr.d4 = 0;
        lr.d0 = (msg->p2 == 0);
        lr.d1 = (msg->p3 == 0);
        lr.d2 = msg->p4;
        lr.d3 = (msg->p5 == 0);
        void *base = func_ov017_0218b5b0();
        SetName56AndFlag_0218d7b0((unsigned char*)base, (char*)&lr.d0);
        return 1;
    }
    case 0xd6: {
        GameState *battle = GameState::GetInstance();
        lr.fh4 = GetField5cb0Value_0201079c((char*)battle);
        lr.fh6 = GetField5cb4Value_020107d0((char*)battle);
        lr.fh8 = GetField5cb8Value_02010804((char*)battle);
        AppendNodeToListField30_0206445c((int)obj, (AppendNode *)msg, (AppendList *)param3);
        return 1;
    }
    case 0xd7: {
        void *base = func_ov017_0218b5b0();
        func_ov017_021a8614(base, (short)msg->p1, msg->p2, msg->p3, msg->p4, msg->p5);
        return 1;
    }
    case 0xd8: {
        int p1 = *(short *)((char *)msg + 2);
        void *ctx = func_0202ae18();
        if (func_0202c508(ctx)) {
            void *p0 = func_02012fe4();
            *(short *)((char *)p0 + 0x2700 + REGION_VALUE(0xf4, 0xb4)) = p1;
            if (CheckField0NonZero_0202b7d8((int *)ctx)) {
                SetHalfFieldsAndEnqueueIfActive_021d1c2c(p1, 0);
                EnqueueEventTagB5_021d1dc0((unsigned short)p1, 0, (int *)&d8Local, 0, 0);
            }
        }
        return 1;
    }
    case 0xd9: {
        void *p = func_ov017_0218b5b0();
        void *list = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
        void *node = *(void **)((char *)p + 0x3000 + REGION_VALUE(0x94c, 0xb6c));
        InitObj021beba4((char*)node);
        AppendNodeToTail((TailList020469b4 *)list, (TailNode020469b4 *)node);
        return 1;
    }
    case 0xda:
        func_020732cc(msg->p1);
        return 1;
    case 0xdb: {
        dbAlloc.ResetAllocatorPointer();
        dbAlloc.ResetAllocatorPointer();
        void *mem = AllocateAligned4_02012d88(&data_02114e20, 0x1000);
        dbAlloc.CreateTypeA(mem, 0x1000);
        dbAlloc.Reset();
        GameState *battle = GameState::GetInstance();
        void *p = GetPtrField0x2a04_02010828((GameState*)battle);
        void *r = func_02086f24(p, (unsigned char)msg->p1, &dbAlloc);
        void *signedAlloc = dbAlloc.GetSignedAllocator();
        if (signedAlloc) {
            dbAlloc.Destroy();
            TailForward02012da4(&data_02114e20, signedAlloc);
        }
        return (int)r;
    }
    case 0xdc:
        func_020aee04(msg->p1, ((unsigned char *)msg)[4]);
        return 1;
    case 0xdd: {
        void *p = func_ov017_0218b5b0();
        func_ov017_021c1a98(p, 1);
        return 1;
    }
    case 0xde: {
        void *p0 = func_02012fe4();
        *((unsigned char *)p0 + 0x2000 + REGION_VALUE(0x810, 0x7d0)) = 0;
        return 1;
    }
    case 0xdf:
        SetOrClearBitInArray_0206df6c(&data_02108844, (unsigned char *)&data_02108844 + 0x8c, 0x799, msg->p1);
        return 1;
    case 0xe0:
        SetOrClearBitInArray_0206df6c(&data_02108844, (unsigned char *)&data_02108844 + 0x8c, 0x798, msg->p1);
        return 1;
    case 0xe3: {
        void *p = func_ov017_0218b5b0();
        (void)p;
        _Z27InitAndAppendEntity020dac40P12Root020dac40();
        return 1;
    }
    case 0xe4: {
        struct BitfieldStruct {
          char unk[0xc8];
            unsigned char low : 2;
            unsigned char foo : 1;
        };
        data_02109bf4.foo = !msg->p1;
        return 1;
    }
    case 0xe5: {
        GameState *battle = GameState::GetInstance();
        unsigned short s5 = *(unsigned short *)((char *)battle + REGION_VALUE(0x6f00, 0x7100) + REGION_VALUE(0x9c, 0xdc));
        short s6 = *(short *)((char *)battle + REGION_VALUE(0x6f00, 0x7100) + REGION_VALUE(0x9e, 0xde));
        short s7 = *(short *)((char *)battle + REGION_VALUE(0x6f00, 0x7100) + REGION_VALUE(0xa0, 0xe0));
        void *p = GetPtrField0x2a04_02010828((GameState*)battle);
        if (s5 == 0)
            return 1;
        if (s6 >= 0 && s6 <= 3) {
            GameObject *combatant = GetCombatantWithFlag0x100_0200ff1c(battle, s6);
            if (!combatant)
                return 1;
            void *field = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
            RemoveSlotShiftDown0208386c((Slots0208386c*)field, (signed char)s7);
        } else {
            DecrementKeyValue020a0a08((KeyMap020a0a08*)p, (short)s5, 1);
        }
        return 1;
    }
    case 0xe6:
        SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, msg->p1 + 0xbea, msg->p2);
        return 1;
    case 0xe7: {
        void *ctx = func_0202ae18();
        if (func_0202c540(ctx))
            return 1;
        SetOrClearBitInArray_0206df6c(obj, (unsigned char *)obj + 0x8c, 0x796, msg->p1);
        char *battle = (char*)GameState::GetInstance();
        BattleRecordSnapshot* st = (BattleRecordSnapshot*)((char *)&((struct Blk7400 *)SubA(battle))[1] + 0x3c);
        BattleRecordCapture* snap = &st->capture;
        if (!snap->captured) {
            void *fields = GetPtrField0x2a04_02010828((GameState*)battle);
            int level = 0;
            void *comb = ((GameState*)battle)->GetProtagonist();
            if (comb)
                level = *(*(unsigned short **)((char *)comb + 0x134) + 0x18);
            lr.fword0 = 0;
            CopyOutBattleField0x7ac0_020ac0b4((void *)&lr.fword0);
            CopyHalfwordAndTwoBytes((SmallRecord020643e0*)&snap->playClock, (SmallRecord020643e0*)&st->clocks.elapsed);
            CopyHalfwordAndTwoBytes((SmallRecord020643e0*)&snap->committedPlayClock, (SmallRecord020643e0*)&st->clocks.committed);
            snap->unknown08_0 = st->unknown08_0;
            snap->unknown08_17 = GetFieldPercentOver307_020a0870(st);
            snap->unknown08_24 = GetFieldPercentOver448_020a090c(st);
            snap->unknown0c_0 = lr.fword0;
            snap->unknown0c_17 = GetFieldPercentOver232_020a08a4(st);
            snap->unknown0c_24 = GetFieldPercentOver944_020a08d8(st);
            snap->unknown10_0 = st->unknown10_0;
            snap->unknown10_9 = st->unknown0c_14;
            snap->unknown14_0 = st->unknown08_24;
            snap->unknown14_8 = st->unknown10_9;
            snap->unknown14_22 = level;
            snap->unknown18_0 = st->unknown40_0;
            snap->unknown1c = *(unsigned int *)((char *)fields + 0xf6c) + *(unsigned int *)((char *)fields + 0xf68);
            snap->captured = 1;
        }
        return 1;
    }
    case 0xe8: {
        void *g = GetGlobalPtr021075f4_0203cf4c();
        void *entry = FindEntryPointerByKey0203df78(g, msg->p1);
        if (!entry)
            return 1;
        void *f = GetField0xc02040538((S02040538*)entry);
        if (!f)
            return 1;
        unsigned char b = *((unsigned char *)f + 0xa);
        b = (b & ~0x38) | (((unsigned char)msg->p2 & 7) << 3);
        *((unsigned char *)f + 0xa) = b;
        return 1;
    }
    case 0xe9:
        SyncEightElementFlags_020ae9f0();
        return 1;
    case 0x6f: case 0x70: case 0x71: case 0x98: case 0x9a: case 0xa3:
        break;
    default:
        break;
    }
    return 0;
}
