#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Graphics/VRAMStaging.h"
#include "Graphics/NSBXX/RenderConfig.h"
#include "System/VRAM.h"
#include "System/Matrix.h"

#if defined(jpn)
enum {
    kWorkData = 0x218,
    kWorkConfig = 0x21c,
    kWorkState = 0x220,
    kResourceNode = 0x34ec,
    kResourceParams = 0x3524,
    kGlobalTransitionFlag = 0x17ee,
    kWorkPlacementFlag = 0x79c2,
    kCombatantRecord = 0x144,
    kWorkPositions = 0x5b00,
    kWorkHeightBase = 0x5b00,
    kCombatantHeightFlag = 0x1a6,
    kCombatantObject = 0x150,
    kCombatantFlags = 0x180,
    kCombatantModel = 0x148,
    kCombatantAppearance = 0x1b8,
    kBattleSelection = 0x6fb4,
    kBattlePosition = 0x6fa4,
    kBattleRotation = 0x6fb0,
    kWorkPartyIds = 0x5788,
    kWorkPartyCount = 0x57a8,
    kResourceListFlags = 0x34fc,
    kWorkStoreParams = 0x7014,
    kWorkParamA = 0x701a,
    kWorkParamB = 0x701b,
    kWorkParamC = 0x701c,
    kWorkOtherParams = 0x7028,
    kWorkHeightOffset = 0xc,
    kDiffuseIndex = 0x2b,
    kAppearanceId = 0xc,
};
#else
enum {
    kWorkData = 0x29c,
    kWorkConfig = 0x2a0,
    kWorkState = 0x2a4,
    kResourceNode = 0x36fc,
    kResourceParams = 0x3734,
    kGlobalTransitionFlag = 0x19be,
    kWorkPlacementFlag = 0x77d2,
    kCombatantRecord = 0x150,
    kWorkPositions = 0x5910,
    kWorkHeightBase = 0x5900,
    kCombatantHeightFlag = 0x1b2,
    kCombatantObject = 0x15c,
    kCombatantFlags = 0x18c,
    kCombatantModel = 0x154,
    kCombatantAppearance = 0x1c4,
    kBattleSelection = 0x71f4,
    kBattlePosition = 0x71e4,
    kBattleRotation = 0x71f0,
    kWorkPartyIds = 0x5598,
    kWorkPartyCount = 0x55b8,
    kResourceListFlags = 0x370c,
    kWorkStoreParams = 0x6e24,
    kWorkParamA = 0x6e2a,
    kWorkParamB = 0x6e2b,
    kWorkParamC = 0x6e2c,
    kWorkOtherParams = 0x6e38,
    kWorkHeightOffset = 0x1c,
    kDiffuseIndex = 0x1b,
    kAppearanceId = 0x11,
};
#endif

#if defined(jpn)
#define func_ov000_021688dc func_ov000_0216a010
#define _Z24GetIndexedEntry_021a11f4Phi func_ov017_021a1c8c
#define _Z26EnqueueEventTag83_021c8c04thi func_ov017_021c90b4
#define _Z25StoreBattleParams0201bf38Phiiit func_0201bcb0
#define data_ov000_02183218 data_ov000_021842c4
#define data_ov000_02183b20 data_ov000_02184c54
#define data_ov000_02183b3b data_ov000_02184c6f
#define data_ov000_02183b55 data_ov000_02184c89
#endif

struct Region4 { unsigned char b[4]; };

extern "C" void* func_0202ae18(void);
extern "C" unsigned short* func_02012fe4(void);
extern "C" void* func_0203bd08(void);
extern "C" void func_02082828(int field150);
extern "C" void func_020542b4(void* a, void* b, void* c);
extern "C" void func_02048b0c(void* obj, int flag);
extern "C" void func_02049c88(void* obj, void* state);
extern "C" void func_02046a8c(void* list, void* node);
extern "C" void func_02076a8c(void* obj);
extern "C" int func_ov000_02163c80(void* work, int flag);
extern "C" void func_ov000_02168284(void* work);
extern "C" void func_02094ab0(int g);
extern "C" void func_02048150(void* combatant, int a, int b);
extern "C" int func_0202c540(void* p);
extern "C" void func_ov017_021917f0(int id, int flag);
extern "C" void func_ov017_02191234(int a);
extern "C" void func_ov017_021baedc(void* node, int flag);
extern "C" void func_ov017_02191108(int ovBase, int c, int d, int e, int flag);
extern "C" void func_ov017_02191aac(int ovBase, int mode, int idx, int mask);
extern "C" void func_ov017_021c9e00(int a, int b, int c, int d);
extern "C" void func_ov017_0219bd1c(int a, int b, int c, int d);
extern "C" void func_ov000_021626a0(void* work, int a, int b);

extern "C" void _Z37ConfigureModeByByte_0218d274_0218d274v(int dead);
extern "C" void _Z34SetupCombatantAllocations_021901acv(int dead);

int GetField0x3acValue(GameState* state);
void* GetField0x3f8Address(GameState* state);
void ClearCombatantSlot(GameState* state, int id);
void SetField0x3b0Value(GameState* state, int value);

struct S_10088;
int IsFlag10088Set(struct S_10088* obj);
void ResetFields14And18KeepFlag0x4(unsigned char* obj, unsigned short val);
int CheckField0NonZero(int* obj);
int TestBitAt0x34(unsigned char* obj, unsigned int index);
int CollectSetBitIndicesAt0x34(unsigned char* obj, short* outArray);

struct ArrayContainsByteStruct {
    char pad[0xf78];
    unsigned char arr[4];
    unsigned char count;
};
int ArrayContainsByte(struct ArrayContainsByteStruct* s, int val);


void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void ClearBitsInField8(unsigned int* obj, unsigned int mask);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);

struct Entry0207d9bc;
extern "C" void _Z23ResetEntryByKey0207da7cP13Entry0207d9bct(struct Entry0207d9bc* arr, unsigned short key);
int GetCombatWorkFlags0x55f4(void* work, int mask);
void SetCombatWorkFlags0x55f4(void* work, int mask);
int GetFieldAt0x150(unsigned char* obj);

struct Entry_02028bd0;
extern "C" struct Entry_02028bd0* _Z28FindEntryByCurrentId02027cb0v(void);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
void* GetData02108ea8(void);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);

extern "C" void* _Z24GetIndexedEntry_021a11f4Phi(unsigned char* base, int idx);
void SetByteField0x253(void* obj);

struct Obj02053f7c;
extern "C" void _Z34SetField0x1b2IfMatchOrFlag02053f7cP11Obj02053f7csi(struct Obj02053f7c* obj, short a, int b);
struct Obj02049f50;
extern "C" void _Z29SetField41AndScaleSub02049f50P11Obj02049f50ii(struct Obj02049f50* obj, int val, int count);
int TestBitInArray0x8ec(unsigned char* obj, int index);
extern "C" void _Z23ClearStateFlags0203400cPh(unsigned char* obj);
void SetFlag0x1ceBit0x4(unsigned char* obj);
void ClearFlag0x1ceBit0x4(unsigned char* obj);
#if defined(jpn)
extern "C" void func_020392fc(unsigned char* obj);
#define ClearFlag0x1ceBit0x1 func_020392fc
#else
void ClearFlag0x1ceBit0x1(unsigned char* obj);
#endif
struct Obj02033874;
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(struct Obj02033874* obj, int arg);
extern "C" int _Z32CallHelperIfCheckPasses_0218fcf8iii(int a, int b, int c);
extern "C" void _Z30ClearBytesAndZeroBlock02039d24Ph(unsigned char* obj);
#if defined(jpn)
extern "C" void func_020391b0(void* obj, int val);
#define SetIntField0x264 func_020391b0
#else
void SetIntField0x264(void* obj, int val);
#endif

struct SearchStruct;
struct SearchStruct0202c1a4;
int GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
int TestBitBySignedByteIndex(struct SearchStruct* obj, int value);
extern "C" void _Z25EnqueueEventTag8_021cc4b8hhi(int a, int b, int c);
void SetField0x158(void* obj, int value);

struct Bytes02033b88;
int SetByte0xbeShiftPrev(struct Bytes02033b88* p, int val);
extern "C" GameObject* _Z32FindCombatantByField16a_021a278cPvi(void* unused, int val);

struct Foo0207df50;
extern "C" void _Z36FormatAndAppendCombatMessage02072d58iPcS_(int combatantId, char* statsBuf, char* outBuf);
struct Obj02061bd8;
int CheckField0x56bLowNibble(struct Obj02061bd8* obj);
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(struct Foo0207df50* p);
extern "C" void _Z25RestorePairTables0207df90Pc(char* obj);
extern "C" void _Z24BackupPairTables0207dfacPc(char* obj);

struct Struct_203dafc;
void ClearEightWords(struct Struct_203dafc* obj);

int GetGlobal02109400(void);
extern "C" void _Z21BlankFunction02094b40v(void);
extern "C" void _Z27SetupContextForMode0205ea20Pvi(void* objRaw, int mode);

struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

extern "C" void _Z25StoreBattleParams0201bf38Phiiit(unsigned char* obj, int set, int a, int b, unsigned short c);
void SetOrClearBit1(unsigned char* obj, int set);
extern "C" void _Z19InitContext020e1154Pv(void* obj);
extern "C" void _Z19SetFlag320_02195530Ph(unsigned char* obj);
struct FlagWord020466f4;
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(struct FlagWord020466f4* word, unsigned int mask);
int ClassifyField0x81fe(char* base);
extern "C" void _Z26CallHelperWithBuf_021907dciiiii(int a, int b, int c, int d, int e);

void* GetData02153634(void);
int GetByte2IfGlobalFlagSet(unsigned char* p);
extern "C" void _Z31ClearBitOrNotifyOverlay020e3798Ph(unsigned char* obj);

extern "C" void _Z25ConfigurePairMode020bb48cji(unsigned int mode, int installHandlers);
extern "C" void _Z26EnqueueEventTag83_021c8c04thi(int a, int b, int c);
extern "C" void _ZN8Object3D10SetField06Et(void* obj, int value);

struct Bits0c1 { unsigned char lo : 2; unsigned char hi : 6; };

extern Region4 data_ov000_02183218;
extern int data_ov000_02183b0c;
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
extern const char data_ov000_02183b20[];
extern const char data_ov000_02183b3b[];
extern const char data_ov000_02183b55[];
extern int data_02108760;

void CopyInRegion0x571d(char* obj, int len, void* src);
struct Slot70 { char data[0x70]; };
static inline SafeAllocator* GetAllocator38(GameResources* res, int i) { return &res->allocator_array_38[i]; }
static inline Slot70* GetSlot2cc(GameResources* res, int i) { return &((Slot70*)res->unknown_2cc)[i]; }

static inline short GetObjectId(GameObject* c) {
    short id = *(short*)((char*)c + 4);
    return id;
}

static inline int IsFlag130Bit0(GameObject* c) {
    return (**(int**)((char*)c + 0x130) & 1) != 0;
}

// USA: func_ov000_021688dc
extern "C" ARM void func_ov000_021688dc(unsigned char* work) {
    if (((BackgroundLoader*)((void*)(int)BackgroundLoader::GetInstance()))->GetNumQueuedTasks() > 0) {
        return;
    }

    GPCReadPair pair;
    char statsName[0xa];
    char outName[0xa];
    char name[0x28];
    ObjectArchiveLoadInfo info;
    ObjectArchiveLoadInfo info2;
    Region4 region;
    short ids[4];
    unsigned int size;

    GameState* battle = GameState::GetInstance();
    int ovBase = (int)func_ov017_0218b5b0();
    struct SearchStruct* search = (struct SearchStruct*)func_0202ae18();
    unsigned short* p30 = func_02012fe4();
    func_0203bd08();

    void* p29c = *(void**)(work + kWorkData);
    struct ArrayContainsByteStruct* arrStruct = (struct ArrayContainsByteStruct*)GetPtrField0x2a04(battle);
    GameObject* prot = battle->GetProtagonist();
    struct Entry_02028bd0* entry = _Z28FindEntryByCurrentId02027cb0v();
    int globalBase = _Z26GetGlobalField0x1c020421a0v();
    void* dataPtr20 = GetData02108ea8();
    void* p1c = *(void**)(ovBase + kResourceNode);
    unsigned char* p18 = *(unsigned char**)(ovBase + kResourceParams);
    _Z27GetDataPtr02114e04_020d6c00v();

    if (*((unsigned char*)p29c + 0x8e97) != 0) {
        GameObject* c = battle->GetPartyMemberByIndex(GetField0x3acValue(battle));
        if (c != NULL && IsFlag10088Set((struct S_10088*)c)) {
            ResetFields14And18KeepFlag0x4(*(unsigned char**)((char*)c + 0x138), 1);
            func_ov017_02191108(ovBase, 1, 1, 1, 1);
        }
    }

    GameObject* c397c = battle->GetUnknownGameObject();

    if (CheckField0NonZero((int*)search)) {
        int allFlagged = 1;
        int k;
        for (k = 0; k < 4; k++) {
            if (TestBitAt0x34(*(unsigned char**)(work + kWorkConfig), (unsigned char)k)) {
                GameObject* c = GetCombatantWithFlag0x100(battle, k);
                if (c != NULL) {
                    if (!IsFlag10088Set((struct S_10088*)c)) {
                        allFlagged = 0;
                        break;
                    }
                }
            }
        }
        if (allFlagged) {
            *(*(unsigned char**)(work + kWorkData) + 0x8e14) = 2;
        }
    }

    _Z37ConfigureModeByByte_0218d274_0218d274v(ovBase);
    ClearBitsInField4((unsigned int*)ovBase, 0x200000);
    _Z23ResetEntryByKey0207da7cP13Entry0207d9bct((struct Entry0207d9bc*)dataPtr20, *(unsigned short*)(*(unsigned char**)(work + kWorkConfig) + 8));
    *(unsigned char*)(globalBase + kGlobalTransitionFlag) = 0;

    if (GetCombatWorkFlags0x55f4(work, 0x400000)) {
        GameObject* c1 = GetCombatantWithFlag0x100(battle, 1);
        if (c1 != NULL) {
            int f150 = GetFieldAt0x150((unsigned char*)c1);
            if (f150 != 0) {
                func_02082828(f150);
            }
        }
        arrStruct->count -= 1;
        ClearCombatantSlot(battle, 1);
        battle->SetTimeOfDay((TimeOfDay)2);

        int regionCount = 1;
        region = data_ov000_02183218;
        CopyInRegion0x571d((char*)battle, regionCount, &region);

        SafeAllocator* alloc3 = GetAllocator38((GameResources*)ovBase, 3);
        Slot70* slot3 = GetSlot2cc((GameResources*)ovBase, 3);
        func_020542b4(_Z24GetIndexedEntry_021a11f4Phi((unsigned char*)ovBase, 2), alloc3, slot3);
        *(int*)((char*)LightingManager::GetInstance() + 0x98) = 2;
    }

    int count = CollectSetBitIndicesAt0x34(*(unsigned char**)(work + kWorkConfig), ids);

    if (c397c != NULL) {
        SetByteField0x253(c397c);
        *((unsigned char*)c397c + 0xc3) = 0xf;
    }

    short leadId = *(short*)((char*)prot + 4);
    if (ArrayContainsByte(arrStruct, 0)) {
        for (int idx = 0; idx < arrStruct->count; idx++) {
            GameObject* c = battle->GetPartyMemberByIndex(arrStruct->arr[idx]);
            if (c != NULL && !IsFlag10088Set((struct S_10088*)c)) {
                if (!IsFlag130Bit0(c)) {
                    leadId = *(short*)((char*)c + 4);
                    break;
                }
            }
        }
    } else {
        leadId = *(short*)((char*)c397c + 4);
    }

    for (int i = 0; i < 4; i++) {
        if (TestBitAt0x34(*(unsigned char**)(work + kWorkConfig), (unsigned char)i)) {
            GameObject* c = battle->GetPartyMemberByIndex(i);
            if (c != NULL) {
                c->obj3D_.MakeVisible();
                _Z34SetField0x1b2IfMatchOrFlag02053f7cP11Obj02053f7csi((struct Obj02053f7c*)c, 0, 0);
                _Z29SetField41AndScaleSub02049f50P11Obj02049f50ii((struct Obj02049f50*)c, 0x1f, 0);
                func_ov017_02191aac(ovBase, 0, i, 2);
                func_ov017_02191aac(ovBase, 0, i, 4);

                if (GetCombatWorkFlags0x55f4(work, 1) && work[kWorkPlacementFlag] != 0) {
                    func_02048b0c(c, TestBitInArray0x8ec(*(unsigned char**)((char*)c + kCombatantRecord), 0x99) ? 1 : 0);
                    _Z23ClearStateFlags0203400cPh((unsigned char*)c);
                }

                if (ArrayContainsByte(arrStruct, GetObjectId(c))) {
                    if (leadId != *(short*)((char*)c + 4)) {
                        SetFlag0x1ceBit0x4((unsigned char*)c);
                    }
                    if (GetCombatWorkFlags0x55f4(work, 1)) {
                        *(Vector3i*)((char*)c + 0x44) = *(Vector3i*)(work + kWorkPositions + leadId * 16);
                        _Z24SetVecYFromValue02033874P11Obj02033874i((struct Obj02033874*)c, *(short*)(work + leadId * 16 + kWorkHeightBase + kWorkHeightOffset));
                    }
                } else {
                    if (GetCombatWorkFlags0x55f4(work, 1)) {
                        *(Vector3i*)((char*)c + 0x44) = *(Vector3i*)(work + kWorkPositions + i * 16);
                        _Z24SetVecYFromValue02033874P11Obj02033874i((struct Obj02033874*)c, *(short*)(work + i * 16 + kWorkHeightBase + kWorkHeightOffset));
                    }
                    if (*(unsigned short*)((char*)c + kCombatantHeightFlag) != 0) {
                        ClearFlag0x1ceBit0x4((unsigned char*)c);
                    }
                }

                *(unsigned short*)((char*)c + 0x9c) = 0;
                c->obj3D_.SetField9e(0);
                _Z32CallHelperIfCheckPasses_0218fcf8iii(ovBase, i, 0);
                _Z30ClearBytesAndZeroBlock02039d24Ph((unsigned char*)c);
                ClearFlag0x1ceBit0x1((unsigned char*)c);
                SetIntField0x264(c, 0);

                if (CheckField0NonZero((int*)search)) {
                    int cur = GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search);
                    if (cur == i) {
                        continue;
                    }
                    if (!TestBitBySignedByteIndex(search, i)) {
                        _Z25EnqueueEventTag8_021cc4b8hhi(i, 0, 8);
                        continue;
                    }
                    _Z25EnqueueEventTag8_021cc4b8hhi(i, i, 8);
                }
                *((unsigned char*)c + 0xe0) |= 0x20;
            }
        }
    }

    for (int j = 0; j < arrStruct->count; j++) {
        GameObject* c = GetCombatantWithFlag0x100(battle, arrStruct->arr[j]);
        if (c != NULL) {
            SetField0x158(c, 0);
            func_ov017_021c9e00(arrStruct->arr[j], 1, 0, 1);
        }
    }

    if (*(int*)(work + kWorkState) != 0) {
        SetField0x3b0Value(battle, *(int*)(work + kWorkState));
    }

    int sp14 = 0;
    if (!CheckField0NonZero((int*)search) ||
        GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search) == 0) {
        GameObject* c6 = _Z32FindCombatantByField16a_021a278cPvi((void*)ovBase,
            *(unsigned short*)(*(unsigned char**)(work + kWorkConfig) + 8));
        if (c6 != NULL) {
            if (func_ov000_02163c80(work, 0) != 0) {
                sp14 = 1;
            } else {
                func_02076a8c(c6);
                c6->obj3D_.MakeHidden();
            }
        }
        if (entry != NULL) {
            *(int*)((char*)entry + 8) = 0;
        }
    }
    for (int k = 0; k < 8; k++) {
        ClearCombatantSlot(battle, k + 0xc0);
    }

    ClearBitsInField4((unsigned int*)ovBase, 0x80);
    ClearBitsInField4((unsigned int*)ovBase, 4);
    ClearBitsInField4((unsigned int*)ovBase, 0x10);
    ClearBitsInField4((unsigned int*)ovBase, 0x40);
    ClearBitsInField4((unsigned int*)ovBase, 2);
    ClearBitsInWord((unsigned int*)ovBase, 0x20);
    ClearBitsInWord((unsigned int*)ovBase, 0x10);
    func_ov000_021626a0(work, 0x26, 1);
    *(volatile unsigned short*)0x04000304 &= ~0x8000;
    LockStagedTextureVRAMCopying();
    MapVRAMBanksToTextureImage(0xf);
    _Z25ConfigurePairMode020bb48cji(4, 1);
    DisableSubBGVRAMBanks();
    MapVRAMBanksToSubBG(0x80);
    MapVRAMBanksToSubObj(0x100);
    *(volatile unsigned int*)0x04001000 = (*(volatile unsigned int*)0x04001000 & 0xffcfffef) | 0x10;
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
    RenderConfig::SetDiffuseAmbientColors(p30[kDiffuseIndex], 0, 0);
    _Z34SetupCombatantAllocations_021901acv(ovBase);

    for (int m = 0; m < count; m++) {
        GameObject* c = GetCombatantWithFlag0x100(battle, ids[m]);
        if (c != NULL) {
            ((Bits0c1*)((char*)c + 0xc1))->lo &= ~3;
            _ZN8Object3D10SetField06Et(c, *(int*)((char*)c + kCombatantObject));
            *(int*)((char*)c + kCombatantObject) = data_ov000_02183b0c;
            if (*(int**)((char*)c + 0x13c) != NULL) {
                **(int**)((char*)c + 0x13c) = 0;
            }
            func_02049c88(c, NULL);
            *((unsigned char*)c + 0xc2) &= ~0x20;
            func_ov017_021917f0(ids[m], 0);
        }
    }

    if (!CheckField0NonZero((int*)search)) {
        if (*(signed char*)(*(unsigned char**)(work + kWorkData) + 0x8e14) != 2) {
            for (int n = 0; n < count; n++) {
                GameObject* c = GetCombatantWithFlag0x100(battle, ids[n]);
                if (c != NULL && IsFlag130Bit0(c)) {
                    *(int*)((char*)c + kCombatantFlags) |= 1;
                    SetByte0xbeShiftPrev((struct Bytes02033b88*)c, 0);
                }
            }
        }
    } else {
        for (int n = 0; n < count; n++) {
            GameObject* c = GetCombatantWithFlag0x100(battle, ids[n]);
            if (c != NULL && IsFlag130Bit0(c)) {
                *(int*)((char*)c + kCombatantFlags) |= 1;
                SetByte0xbeShiftPrev((struct Bytes02033b88*)c, 0);
            }
        }
    }

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    GPCReadPair* pp = &pair;
    unsigned char* buf = data_0211e33c;
    unsigned int capacity = 0x30000;
    ZeroInitGPCPointer(&pp->pGPCFile);
    pp->ZeroInitializeMachine();

    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine,
            data_ov000_02183b20, buf, size, capacity, false, NULL)) {
        buf += size;
        capacity -= size;

        for (int i = 0; i < 4; i++) {
            if (TestBitAt0x34(*(unsigned char**)(work + kWorkConfig), (unsigned char)i)) {
                GameObject* c = GetCombatantWithFlag0x100(battle, i);
                if (c != NULL) {
                    c->obj3D_.MakeVisible();
                    *((unsigned char*)c + 0xc1) &= ~0xf0;
                    unsigned char* model = *(unsigned char**)((char*)c + kCombatantModel);
                    if (model != NULL) {
                        SafeAllocator* alloc;

                        c->obj3D_.RemoveAllAnimationPackages();
                        ((SafeAllocator*)(model + 0x52c))->Reset();
                        ((SafeAllocator*)(model + 0x540))->Reset();
                        _Z36FormatAndAppendCombatMessage02072d58iPcS_(i, statsName, outName);

                        if (CheckField0x56bLowNibble((struct Obj02061bd8*)c)) {
                            c->obj3D_.Destroy();
                            unsigned char* p1c4 = *(unsigned char**)((char*)c + kCombatantAppearance);
                            if (p1c4 != NULL) {
                                sprintf(name, data_ov000_02183b3b, p1c4[kAppearanceId]);
                            }
                            alloc = (SafeAllocator*)(model + 4);
                            alloc->Reset();
                            _Z26CopyInternalFields0207df50P11Foo0207df50((struct Foo0207df50*)(model + 0xcc));
                            _Z25RestorePairTables0207df90Pc((char*)(model + 0xcc));
                            LoadFileIntoMemory(name, data_0211e33c, &size);
                            buf = data_0211e33c;
                        } else {
                            sprintf(name, data_ov000_02183b55, statsName);
                            alloc = (SafeAllocator*)(model + 0x52c);
                            DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buf, size, capacity, name);
                        }

                        if (size != 0) {
                            ClearEightWords((struct Struct_203dafc*)&info);
                            info.allocator = alloc;
                            info.unk_10 = 1;
                            info.packageID = 0;
                            info.unk_8 = size;
                            info.fileData = buf;
                            c->obj3D_.LoadFromCCHROrCMOTArchive(&info, NULL);
                        }

                        if (CheckField0x56bLowNibble((struct Obj02061bd8*)c)) {
                            _Z24BackupPairTables0207dfacPc((char*)(model + 0xcc));
                        } else {
                            sprintf(name, data_ov000_02183b55, outName);
                            if (DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buf, size, capacity, name)) {
                                ClearEightWords((struct Struct_203dafc*)&info2);
                                info2.allocator = (SafeAllocator*)(model + 0x540);
                                info2.unk_8 = size;
                                info2.unk_10 = 1;
                                info2.packageID = 1;
                                info2.fileData = buf;
                                c->obj3D_.LoadFromCCHROrCMOTArchive(&info2, NULL);
                            }
                        }

                        SetByte0xbeShiftPrev((struct Bytes02033b88*)c, 0);
                    }
                }
            }
        }

        pair.Reset();
    }

    if (CheckField0NonZero((int*)search)) {
        _Z26EnqueueEventTag83_021c8c04thi(*(unsigned short*)(*(unsigned char**)(work + kWorkConfig) + 8), sp14, *p30);
    }

    func_ov000_02168284(work);

    LightingManager* lm = LightingManager::GetInstance();
    lm->SetZone((Zone3D*)p30);
    lm->BeginFade(0x1000, 0);

    int g = GetGlobal02109400();
    _Z21BlankFunction02094b40v();
    func_02094ab0(g);

    battle->SetGameSpeed(0x1000);
    SetCombatWorkFlags0x55f4(work, 0x400);
    _Z27SetupContextForMode0205ea20Pvi(&data_02108760, 0x64);

    unsigned char done;
    *(int*)((char*)battle + kBattleSelection) = 0;
    for (done = 0; done < *(short*)(work + kWorkPartyCount); done++) {
        if (p18[3] != 0 || p18[2] != 0) {
            break;
        }
        func_ov017_021baedc(p18, 1);
        *(unsigned short*)(p18 + 8) = *(int*)(work + done * 4 + kWorkPartyIds);
        unsigned short* p = func_02012fe4();
        GameObject* pr = battle->GetProtagonist();
        *(int*)((char*)battle + kBattleSelection) = *p;
        int v54 = *(int*)((char*)pr + 0x54);
        Vector3i pos = *(Vector3i*)((char*)pr + 0x44);
        *(Vector3i*)((char*)battle + kBattlePosition) = pos;
        *(int*)((char*)battle + kBattleRotation) = v54;
        AppendNodeToTail((struct TailList020469b4*)p1c, (struct TailNode020469b4*)p18);
        done = 1;
        break;
    }

    if (done == 0) {
        if (!GetCombatWorkFlags0x55f4(work, 1)) {
            func_ov017_0219bd1c(0, 4, 0, 0);
        }
    } else {
        unsigned char* listFlags = *(unsigned char**)(ovBase + kResourceListFlags);
        if (listFlags[2] != 0) {
            func_02046a8c(p1c, listFlags);
        }
    }

    ClearBitsInWord((unsigned int*)ovBase, 4);

    if (*(int*)(work + kWorkStoreParams) != 0) {
        _Z25StoreBattleParams0201bf38Phiiit((unsigned char*)p30, 1, work[kWorkParamA], work[kWorkParamB], *(unsigned short*)(work + kWorkParamC));
    }
    if (*(int*)(work + kWorkOtherParams) != 0) {
        SetOrClearBit1((unsigned char*)p30, 1);
    }
    if (*(int*)(work + kWorkStoreParams) != 0 || *(int*)(work + kWorkOtherParams) != 0) {
        _Z19InitContext020e1154Pv((void*)0xfa0);
    }
    _Z19SetFlag320_02195530Ph((unsigned char*)ovBase);

    struct FlagWord020466f4* fw = (struct FlagWord020466f4*)_Z27GetDataPtr02114e04_020d6c00v();
    _Z18ClearFlags020466f4P16FlagWord020466f4j(fw, 2);
    _Z18ClearFlags020466f4P16FlagWord020466f4j(fw, 0x200);
    _Z18ClearFlags020466f4P16FlagWord020466f4j(fw, 0x2000);
    ClearBitsInField8((unsigned int*)ovBase, 4);
    _Z18ClearFlags020466f4P16FlagWord020466f4j(fw, 0x40000);

    if (ClassifyField0x81fe((char*)p29c)) {
        GameObject* c0 = GetCombatantWithFlag0x100(battle, 0);
        if (c0 != NULL && *(unsigned short*)(*(unsigned char**)((char*)c0 + 0x130) + 4) == 0) {
            func_02048150(c0, 1, 1);
            *(int*)((char*)c0 + kCombatantFlags) &= ~1;
        }
        *(*(unsigned char**)(work + kWorkData) + 0x8e14) = 1;
    }
    ClearBitsInField4((unsigned int*)ovBase, 0x400);

    if (func_0202c540(search)) {
        _Z26CallHelperWithBuf_021907dciiiii(ovBase, 0, 1, 1, 1);
        func_ov017_02191234(ovBase);
    }
    *(unsigned short*)((char*)GetField0x3f8Address(battle) + 0x1e) = *(int*)(*(unsigned char**)(work + kWorkConfig) + 0xc);

    if (CheckField0NonZero((int*)search)) {
        unsigned char* p4 = (unsigned char*)GetData02153634();
        if (GetByte2IfGlobalFlagSet(p4)) {
            _Z31ClearBitOrNotifyOverlay020e3798Ph(p4);
        }
    }

    BackgroundLoader::RemoveLockGlobal();
    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
}
