#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "World/ZoneLootableRecord.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "System/OverlayId.h"
#include "Resource/ActionDataTables.h"
#include "World/LootableContainer.h"
#include "Graphics/LightingManager.h"

struct GameResources;
struct AllocatorUnion;

unsigned int* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0(unsigned int* word, unsigned int bits);
struct FlagWord020466f4;
void ClearFlags020466f4(FlagWord020466f4*, unsigned int);
int GetWord0x7f6c(void* gs);
void SetWord0x7f6c(void* gs, int value);
struct FieldBlock63d6_115a8;
unsigned char GetByteField0x63d6(FieldBlock63d6_115a8*);
struct FieldBlock63d6_115c0;
void ClearByte0x63d6(FieldBlock63d6_115c0*);
void DispatchWithGlobalContext020daf9c(int a, int b, int c, int d);
void SetMainBrightness(GameResources*, int, int);
void SetSubBrightness(GameResources*, int, int);
void SetWord0x0(int*, int);
extern "C" char* func_02012fe4();
void* GetField0x3f8Address(GameState* gs);
void Init0201133c(char*);
void* GetData02109dcc();
void ClearBuffer020a6180(void* p);
void RunScriptIfAvailable020a6194(void* p);
void* GetData02105254();
void ClearThreeRegions0203b634(char*);
extern "C" void* func_0203bd08();
void InitBattleContext0203bd24(char*);
void* GetGlobalPtr021075f4();
struct Struct_0203cf58;
void InitWithExtendedRegion0203cf58(Struct_0203cf58*);
extern "C" void* func_0202ae18();
extern "C" void func_0202aec0(void* p);
void SetBitsInWord(unsigned int*, unsigned int);
void* GetData02100044();
extern "C" void func_0205e22c(void* p);
void* GetPtrField0x468(void* gs);
void ClearFirstThreeWords(unsigned int*);
void Init021b2f64(unsigned char*);
extern "C" void* func_0208e0a8();
void Reset0208e4bc(char*);
void* GetData02153637();
struct SlotTable020e3004;
void InitSlotTable020e3004(SlotTable020e3004*);
void* GetData02153660();
struct Entry020e3840;
void ResetEntryArray020e3814(Entry020e3840*);
void* GetData02153634();
struct Bytes020e358c;
void ClearThreeBytes020e358c(Bytes020e358c*);
extern "C" char* func_0205ec34();
char* GetGlobal02109418();
unsigned char GetByte0x4(char*);
void SetByte0x4(char*, unsigned char);
void ResetState0205facc(void* p);
void Init02095518(char*);
void ClearBattleRegion0x7ac4();
extern "C" void func_02096524(void* p);
extern "C" void* func_020704fc();
struct State02070508;
void ClearState02070508(State02070508*);
extern "C" void func_0209c2e0(void* p, int a, int b);
extern "C" void func_0205e944(void* p, int a);
void* GetGlobalResetObj020d7a50();
struct ResetObj020d7a5c;
void ResetAndClearFlags020d7a5c(ResetObj020d7a5c*);
void LockStagedTextureVRAMCopying();
void UnlockStagedTextureVRAMCopying();
void UpdateVRAMStagingVRAMBanks();
void Finish3DRendering();
extern "C" unsigned int DisableTextureImageVRAMBanks();
extern "C" unsigned int DisableTexturePaletteVRAMBanks();
extern "C" unsigned int DisableMainBGVRAMBanks();
extern "C" unsigned int DisableSubBGVRAMBanks();
extern "C" unsigned int DisableMainObjVRAMBanks();
extern "C" unsigned int DisableSubObjVRAMBanks();
void ConfigureModeByByte_0218d274_0218d274(void* controller);
extern "C" void MapVRAMBanksToTexturePalette(int value);
extern "C" void MapVRAMBanksToMainBG(int v);
extern "C" void MapVRAMBanksToSubBG(int v);
extern "C" void MapVRAMBanksToMainObj(int mode);
extern "C" void MapVRAMBanksToSubObj(int value);
void SetDispcntModeAndFlags020c391c(int mode, int a, int b);
void SetSubBgMode(unsigned int mode);
extern "C" void func_020c51dc();
void ResetMatrixStacks020c537c();
void InitPaletteTables0202ac74();
void SetStructFieldsFromCode02028d68(int code);
void ConfigurePairMode020bb48c(unsigned int a, int b);
void InitGlobalStateAndInstallHandlers020bb780(void* stack, int flag);
extern "C" void func_0202c288(void* p);
int CheckField0NonZero(int*);
void SetField0x3acValue(GameState* gs, int value);
unsigned char GetField0x3acValue(GameState* gs);
struct SearchStruct0202c1a4;
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
void CallWithAddr4000330(int);
extern "C" void func_ov017_021a02f0(void* self);
void ClearFourRegions02079870(char*);
void ClearFourRegions020798b8(char*);
struct Obj020995c0;
void RunBufferedScript020998c4(Obj020995c0*);
void* GetGlobalWordList();
struct WordList0209cbb8;
void ResetWordList0209cbb8(WordList0209cbb8*);
void RunScriptIfAvailable0209cbcc(void* p);
void* GetGlobal02109a54();
void PrepareAndRunBufferedScript02099f6c(char*);
void ResetAllocatorSlots020e5058();
void* AllocateAligned4(AllocatorUnion*, unsigned int);
void CreateAndResetAllocator020e50ec(void* buf, unsigned int size);
void ResetAndLoadAllocatorSlots020e5114();
extern "C" void func_0207de48(void* p, int a, int b);
void InitStruct02013718(char* p, int a, int b);
extern "C" void func_0202df68(void* p);
struct Struct020A2CF0;
void ResetState020a2cf0(Struct020A2CF0*);
void InitCombatController020a2010(void* p);
void SetField0x3b0Value(GameState* gs, int value);
struct List02046958;
void ClearListHeadTail(List02046958*);
extern "C" void func_ov017_021a124c(void* p);
extern "C" void func_ov017_0218f064(void* self, int id, int mask, int b, int extra);
int GetLowNibbleAt0x56b(void* gs, int id);
void* GetCombatantWithFlag0x1000(GameState* gs, int id);
void SetField0x2d0(void* p, unsigned char value);
char* GetFieldAt0x150(unsigned char*);
extern "C" int func_020aaf84(void* buf, int a, int b, int c);
int VerifyAndApplySaveBuffer(int flag);
int CheckSaveBufferStatus(int flag);
int AllocateAndProcessScratchBuffer020abca8();
struct StateBits5ccc_11544;
void SetFlag0x5cccBit0(StateBits5ccc_11544*);
struct StateBits5ccc_11570;
int GetFlag0x5cccBit0(StateBits5ccc_11570*);
void* GetData02109020();
extern "C" void func_0208ea10(void* p, int a);
unsigned long long GetCurrentTimestamp();
int CopyOutRegion0x5718(char*, void*);
extern "C" int func_020dcd40();
extern "C" void func_ov017_02191108(void* self, int a, int b, int c, int d);
extern "C" void func_020897b4(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern "C" void func_0201099c(void* gs);
extern "C" void func_0201229c(void* p);
void InitStruct02070378(char*);
void SetField5cb0AndRecordByte0(char*, int);
void SetField5cb4AndRecordByte1(char*, int);
void SetSlotByte020107dc(char*, int);
void SetOrClearBitInArray(void* p, unsigned char* arr, int bit, int set);
extern "C" void func_020120f0(void* gs);
int TestFlagMask(unsigned short*, int);
extern "C" int func_02032370(int n);
void CopyToBattleField02039768(int obj, void* dst);
short GetField0x397cValue(GameState* gs);
void SetField0x21c(void* p, short v);
extern "C" int rand();
void SetWord0x71f8(void* gs, int v);
extern "C" void func_0206dfe8(void* p, int a, int b);
extern "C" void* func_02057924();
struct Foo02057930;
void InitStruct02057930(Foo02057930*);
void ClearCombatantsAndInitStruct02057978(Foo02057930*);
void* GetEntryTableBase();
#if defined(jpn)
extern "C" void _Z19InitEntries02028894P11Big02028894PcS1_(void* p, void* a);
#else
extern "C" void _Z19InitEntries02028894P11Big02028894PcS1_(void* p, void* a, void* b);
#endif
extern "C" void func_020287b4(void* p);
void* GetData02104b6c();
void ResetBattleArrays02039e7c(void* p);
struct Container0203a54c;
void ProcessAllSubObjects0203a54c(Container0203a54c*);
void* GetGlobalField0x1c020421a0();
extern "C" void func_02042c68(void* c);
extern "C" void func_02043124(void* c);
void SetField0x1e28(void* c, void* p);
extern "C" void func_ov017_0219b624(void* self);
extern "C" void func_ov017_0219ba0c(void* self, int a);
struct Foo0207df50;
void CopyInternalFields0207df50(Foo0207df50*);
void RestorePairTables0207df90(char*);
extern "C" void func_020432c4(void* c);
void BackupPairTables0207dfac(char*);
extern "C" void func_02020554(void* p);
void* GetGlobal02109030();
extern "C" void func_020938f0(void* p);
void ReleaseHandleField340(void* p);
void ClearTwoRegions0206ebf4(char*);
void* GetData02108ea8();
struct Init0207d7c0;
void InitStructArray0207d798(Init0207d7c0*);
int TestBitInByteArray(int p, unsigned char* arr, int bit);
extern "C" void func_ov017_0219bfb4(int a, int b);
void InitAndResetHeader_0219e310(unsigned char*, int);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
struct Ctx021a3498;
void ClearIfMatchAndFinalize_021a3498(Ctx021a3498*);
extern "C" void func_ov017_021baedc(void* p, int a);
void InitObjState_021b2174(unsigned char*);
struct S021b2ba0;
void SetNameChecked_021b2ba0(S021b2ba0*, char*);
void SetFields30And34_021b2bd0(void* p, int a, int b);
extern "C" int GetMainBGAssignedVRAMSize();
extern "C" void func_020ca458(unsigned int value, void* dest, int count);
void DelayThenSyncBit0();
void RestoreDisplayMode();
struct S_02010124;
void InitFields02010124(S_02010124*);
void SetActiveDmaChannel020c3a0c(int ch);
struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
extern "C" void func_0206e424(void* p, int a);
void InitObj021bdbf0(unsigned char*);
void ClearBuffer0202ad30();
void FlushAndClearBuffer0202adf0();
int GetBitsInField0(unsigned int*, unsigned int);
int GetBitsInField4(unsigned int*, unsigned int);
void InitCombatSubsystems02012efc();
int IsBrightnessTransitionActive(GameResources*);
int IsField0Null(void**);
struct Vector3i;
struct FieldBlock63d8_115d0;
int IsHalfword0x63d8Set(FieldBlock63d8_115d0*);
int GetHalfword0x63d8(void* gs);
void ClearHalfword0x63d8(void* gs);
struct Obj02071488;
int RunScriptByValueRange02071574(unsigned int, Obj02071488*);
int CheckField0x63daNonZero(void* gs);
int GetHalfword0x63da(void* gs);
void ClearHalfword0x63da(void* gs);
void DispatchToActiveEntries020bc028(int a);
void BlankFunction020d84e0();
void Forward0202aff4(void* p);
extern "C" void func_02043368(void* c);
extern "C" void func_ov017_0218cbd4(void* self);
extern "C" void func_ov017_02191cc0(void* self);
extern "C" void func_ov017_02195a20(void* self);
void DispatchByFlag020d9834(int flag);
extern "C" void func_0209c840(void* p);
void ResetXYField0203aa08(void* p);
extern "C" void func_020bbd9c();
extern "C" void _Z33CleanInvalidateOamBuffers0203bd88v(void* p);
void Forward0204359c(void* c, int a);
void NotifyAllEntries0203dd94(char*);
void NoOp_0219a188(void* self);
void NoOp_021a63cc(void* self);
void WriteControlAndToggle020d86d0(int a, int b);
void ForwardObjAndField0_021a4358(int p);
struct Obj0203bdb0;
void SyncMainSubOam0203bdb0(Obj0203bdb0*);
int* GetField1c_021a193c(int*);
extern "C" void func_020439b0(void* c, int a);
struct Node020579ec;
void ForEachNode020579ec(Node020579ec**);
extern "C" void func_ov017_021a63d0(void* self);
extern "C" void func_ov017_0219a18c(void* self);
extern "C" void func_0203ba74(void* p);
extern "C" void func_02027438(void* p);
struct Obj020275e4;
void UpdateTimedBufferState020275e4(Obj020275e4*);
struct ShortField0xb4_0205eac8;
int GetShortAt0xb4(ShortField0xb4_0205eac8*);
void SetupContextForMode0205ea20(void* p, int mode);
struct Actor0209c20c;
void InitActorContext0209c20c(Actor0209c20c*);
struct Obj_0205e8ec;
void RefreshDisplayState0205e8ec(Obj_0205e8ec*);
extern "C" void func_ov017_021a3ef0(void* p);
struct Struct_0203cfb4;
void Init0203cfb4(Struct_0203cfb4*);
extern "C" void func_ov017_021a316c(void* self);
void InitControllerObject(char*);
void CallHelperFourTimes_02190238(void* self);
void ResetBigStruct02013750(void* p, int a);
void ForwardFirstWord020998ac(int*);
void FreeWordListBuffer0209cd24(WordList0209cbb8*);
extern "C" void func_ov017_0219b938(void* self);
void ResetOverlayState_0219bc50(unsigned char*);
void TailForward02012da4(AllocatorUnion*, void*);
void DestroyAllocatorsFromTable_021a0790(char*);
void DestroyAllocatorsFromTable_021a0964(char*);
void DestroyAllocatorsFromTable_021a0ba8(char*);
void DestroyAllocatorsFromTable_021a0f40(char*);
void DestroyAllocatorsFromTable_021a1114(char*);
void DestroyAllocatorsFromTable_021a0d6c(char*);
extern "C" void func_ov017_021a0470(void* self);
void ClearCombatantList(GameState* gs);
void ResetInputLogB();
void ResetInputLogA();
void ResetSlotsAndDestroySafeAllocator020e5094();
extern "C" void func_ov004_0216e9cc();
extern "C" void func_ov004_0216f854();

struct Flags02109bf4 {
    char pad[0xc8];
    unsigned char flagsC8;
};

struct Pause021d82e0 {
    unsigned char paused;
    char pad[3];
    int word4;
};

extern Flags02109bf4 data_02109bf4;
extern char data_02108760;
extern char data_ov017_021d615c;
extern char data_02114e20;
extern unsigned short data_02114e30;
extern char data_ov017_021d736c;
extern char data_ov017_021d7378;
extern Pause021d82e0 data_ov017_021d82e0;
extern int data_02114e50;

struct Request3f8 {
    unsigned short id;
    char pad2[5];
    unsigned char flag7;
    char pad8[8];
    int pos[3];
    unsigned short dir;
    char pad1e[2];
    int value20;
    int pad24;
    int value28;
};

struct Party150 {
    char pad[0x49c];
    unsigned char active : 1;
};

struct Cursor371c {
    char pad[0x24];
    unsigned char index;
    char pad25[3];
    int count;
    int selected;
};

struct Holder021a193c {
    char* obj;
};

struct Slot373c {
    char data[0x48];
};

struct Battle0218b688 {
    char pad0[0x28];
    unsigned char running;
    char pad29[0x38 - 0x29];
    char data38[0xc4 - 0x38];
    SafeAllocator allocator;
    char dataD8[0x150 - 0xd8];
    char data150[0x27c - 0x150];
#if !defined(jpn)
    char data27c[0x2cc - 0x27c];
#endif
    char data2cc[0x87c - 0x2cc];
    char pairTables[0xf0c - 0x87c];
#if defined(jpn)
    char dataF0c[0x28f8 - 0xebc];
#else
    char dataF0c[0x2b08 - 0xf0c];
#endif
    int tableMode;
    char pad2b0c[0x2b90 - 0x2b0c];
    Foo02048004 entries[0x12];
    char pad3520[0x3634 - 0x3520];
    unsigned char colorA[0x12];
    unsigned char colorB[0x12];
    unsigned char colorC[0x12];
    char pad366a[0x36d0 - 0x366a];
    char* timedBuffer;
    char pad36d4[0x36fc - 0x36d4];
    void* nodeList;
    void* list700;
    void* list704;
    void* list708;
    void* header70c;
    char pad3710[0x371c - 0x3710];
    Cursor371c* cursor;
    char pad3720[0x3734 - 0x3720];
    char* node734;
    char pad3738[0x373c - 0x3738];
    Slot373c slots[4];
#if defined(jpn)
    char pad385c[0x3b3c - 0x385c];
#else
    char pad385c[0x3b4c - 0x385c];
#endif
    void* node3b4c;
    char pad3b50[0x3b60 - 0x3b50];
    char* node3b60;
    char pad3b64[0x4324 - 0x3b64];
    int exitRequest;
#if defined(jpn)
    char pad4328[0x4434 - 0x4328];
#else
    char pad4328[0x44c4 - 0x4328];
#endif
    void* regions;
};

#if defined(jpn)
enum { RegionObjectFlags = 0x3d44, RegionMemberFlags = 0x180, RegionControllerMode = 0x10 };
#else
enum { RegionObjectFlags = 0x3dcc, RegionMemberFlags = 0x18c, RegionControllerMode = 0x18 };
#endif
#define IS_OBJ_FLAG2_SET(h) ((h)->obj != 0 ? ((*(int*)((h)->obj + RegionObjectFlags) & 2) ? 1 : 0) : 0)

// USA: func_ov017_0218b688
extern "C" ARM void func_ov017_0218b688(Battle0218b688* self) {
    char combatCtrl[0x2c8];
    char scriptOut[0x68];
    char saveInfo[8];
    unsigned char ids[4];

    SafeAllocator::GetLiveCount();
    unsigned int* flagWord = GetDataPtr02114e04_020d6c00();
    OrBitsIntoField0(flagWord, 0x100);
    GameState* gs = GameState::GetInstance();
    int mode = GetWord0x7f6c(gs);
    unsigned char field = GetByteField0x63d6((FieldBlock63d6_115a8*)gs);
    if (mode != 5 && field != 4 && field != 8 && field != 0xc) {
        DispatchWithGlobalContext020daf9c(1, 0, 1, 0);
    }
    SetMainBrightness((GameResources*)self, -16, 0);
    SetSubBrightness((GameResources*)self, -16, 0);
    SetWord0x0((int*)gs, (int)self);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char* bigStruct = func_02012fe4();
    Request3f8* request = (Request3f8*)GetField0x3f8Address(gs);
    loader->MaybeReset();
    Init0201133c((char*)gs);
    void* scriptBuf = GetData02109dcc();
    ClearBuffer020a6180(scriptBuf);
    RunScriptIfAvailable020a6194(scriptBuf);
    void* regions3 = GetData02105254();
    ClearThreeRegions0203b634((char*)regions3);
    void* oam = func_0203bd08();
    InitBattleContext0203bd24((char*)oam);
    void* extRegion = GetGlobalPtr021075f4();
    InitWithExtendedRegion0203cf58((Struct_0203cf58*)extRegion);
    void* search = func_0202ae18();
    func_0202aec0(search);
    SetBitsInWord((unsigned int*)self, 2);
    func_0205e22c(GetData02100044());
    void* buffered = GetPtrField0x468(gs);
    ClearFirstThreeWords((unsigned int*)buffered);
    for (int i = 0; i < 4; i++) {
        Init021b2f64((unsigned char*)&self->slots[i]);
    }
    LootableContainerManager::GetMainInstance()->Reset();
    Reset0208e4bc((char*)func_0208e0a8());
    InitSlotTable020e3004((SlotTable020e3004*)GetData02153637());
    ResetEntryArray020e3814((Entry020e3840*)GetData02153660());
    ClearThreeBytes020e358c((Bytes020e358c*)GetData02153634());
    char* bits = func_0205ec34();
    char* global418 = GetGlobal02109418();
    if (GetByteField0x63d6((FieldBlock63d6_115a8*)gs) == 0) {
        if (GetWord0x7f6c(gs) == 5 || GetByte0x4((char*)gs) == 4) {
            ResetState0205facc(bits);
            Init02095518((char*)global418);
            ClearBattleRegion0x7ac4();
        }
        func_02096524(global418);
    }
    *(int*)(bits + 0x480) = 0;
    *(int*)(bits + 0x47c) = 0;
    ClearState02070508((State02070508*)func_020704fc());
    func_0209c2e0(&data_02109bf4, 0x7f, 0);
    func_0205e944(&data_02108760, 0x7f);
    data_02109bf4.flagsC8 &= ~4;
    ResetAndClearFlags020d7a5c((ResetObj020d7a5c*)GetGlobalResetObj020d7a50());
    if (GetWord0x7f6c(gs) == 5 && GetByte0x4((char*)gs) != 9) {
        SetByte0x4((char*)gs, 6);
    }

    LockStagedTextureVRAMCopying();
    DisableTextureImageVRAMBanks();
    DisableTexturePaletteVRAMBanks();
    DisableMainBGVRAMBanks();
    DisableSubBGVRAMBanks();
    DisableMainObjVRAMBanks();
    DisableSubObjVRAMBanks();
    ConfigureModeByByte_0218d274_0218d274(self);
    MapVRAMBanksToTexturePalette(0x40);
    MapVRAMBanksToMainBG(0x10);
    *(volatile unsigned int*)0x4000000 &= ~0x7000000;
    *(volatile unsigned int*)0x4000000 &= ~0x38000000;
    *(volatile unsigned short*)0x400000a = (*(volatile unsigned short*)0x400000a & 0x43) | 4;
    *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | 0x1300;
    SetDispcntModeAndFlags020c391c(1, 0, 1);
    SetSubBgMode(0);
    *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & ~0x1f00) | 0x1300;
    MapVRAMBanksToSubBG(0x80);
    unsigned short* subBgcnt = (unsigned short*)0x4001008;
    subBgcnt[0] = (subBgcnt[0] & 0x43) | 0x4e00;
    subBgcnt[1] = (subBgcnt[1] & 0x43) | 0xd00;
    MapVRAMBanksToMainObj(0x20);
    *(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & 0xffcfffef) | 0x10;
    MapVRAMBanksToSubObj(0x100);
    *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & 0xffcfffef) | 0x10;
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
    *(unsigned short*)0x4000304 &= ~0x8000;
    Finish3DRendering();
    func_020c51dc();
    ResetMatrixStacks020c537c();
    unsigned short* subPrio = (unsigned short*)0x4001008;
    *(unsigned short*)0x400000a &= ~3;
    *(unsigned short*)0x4000008 = (*(unsigned short*)0x4000008 & ~3) | 1;
    subPrio[0] = (subPrio[0] & ~3) | 1;
    subPrio[1] = (subPrio[1] & ~3) | 2;
    subPrio[2] = (subPrio[2] & ~3);
    InitPaletteTables0202ac74();
    SetStructFieldsFromCode02028d68(3);
    ConfigurePairMode020bb48c(4, 1);
    InitGlobalStateAndInstallHandlers020bb780((void*)0x4000, 1);

    func_0202c288(search);
    if (CheckField0NonZero((int*)search) == 0) {
        SetField0x3acValue(GameState::GetInstance(), 0);
    } else {
        GameState* inst = GameState::GetInstance();
        SetField0x3acValue(inst, GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search));
    }
    CallWithAddr4000330((int)&data_ov017_021d615c);
    func_ov017_021a02f0(self);
    ClearFlags020466f4((FlagWord020466f4*)flagWord, 0x100);
    ActionDataTables* regions4 = GetData02108e10();
    ClearFourRegions02079870((char*)regions4);
    func_02079900(regions4, (SafeAllocator*)self->data150);
    RunBufferedScript020998c4((Obj020995c0*)buffered);
    void* wordList = GetGlobalWordList();
    ResetWordList0209cbb8((WordList0209cbb8*)wordList);
    RunScriptIfAvailable0209cbcc(wordList);
    PrepareAndRunBufferedScript02099f6c((char*)GetGlobal02109a54());
    func_0204719c(&self->entries[11]);
    int ownAllocator = 0;
#if !defined(jpn)
    ResetAllocatorSlots020e5058();
    void* slotBuf = AllocateAligned4((AllocatorUnion*)&data_02114e20, 0x1866);
    if (slotBuf != 0) {
        CreateAndResetAllocator020e50ec(slotBuf, 0x1866);
    }
    ResetAndLoadAllocatorSlots020e5114();
#endif
    if (GetByte0x4((char*)gs) == 9) {
        ownAllocator = 1;
        self->allocator.CreateTypeA(AllocateAligned4((AllocatorUnion*)&data_02114e20, 0x30000), 0x30000);
        func_0207de48(self->dataF0c, 0x10, 0x10);
    }
    InitStruct02013718(bigStruct, (int)self->data38, (int)self->data2cc);
    func_0202df68(combatCtrl);
    ResetState020a2cf0((Struct020A2CF0*)combatCtrl);
    InitCombatController020a2010(combatCtrl);
    SetField0x3b0Value(gs, (int)combatCtrl);
    ClearListHeadTail((List02046958*)self->nodeList);
    ClearListHeadTail((List02046958*)self->list700);
    ClearListHeadTail((List02046958*)self->list704);
    func_ov017_021a124c(self->list708);
    int loaded;
    int ok;
    int fresh = 0;
    Cursor371c* cursor = self->cursor;
    cursor->index = fresh;
    cursor->count = fresh;
    cursor->selected = fresh - 1;
    loaded = fresh;
    int newGame = fresh;
    int showIntro = fresh;

    if (GetByte0x4((char*)gs) != 6 && GetByte0x4((char*)gs) != 9) {
        if (GetByteField0x63d6((FieldBlock63d6_115a8*)gs) != 0) {
            loaded = 1;
        } else {
            if (GetByte0x4((char*)gs) == 0 || GetByte0x4((char*)gs) == 5) {
                int isFive = GetByte0x4((char*)gs) == 5;
                loaded = fresh = 1;
                newGame = !isFive;
                if (GetWord0x7f6c(gs) == 6) {
                    ok = 0;
                    if (func_020aaf84(saveInfo, 0, isFive, 0) != 0) {
                        if (VerifyAndApplySaveBuffer(newGame == 0) != 0) {
                            ok = 1;
                            if (isFive != 0 && CheckSaveBufferStatus(0) == 0 &&
                                AllocateAndProcessScratchBuffer020abca8() == 0) {
                                SetFlag0x5cccBit0((StateBits5ccc_11544*)gs);
                                ok = 0;
                            }
                        } else {
                            SetFlag0x5cccBit0((StateBits5ccc_11544*)gs);
                        }
                    }
                    if (ok == 0) {
                        fresh = 0;
                        loaded = fresh;
                        newGame = fresh;
                    }
                }
            }
            if (GetByte0x4((char*)gs) != 5) {
                func_0208ea10(GetData02109020(), 1);
            }
            *(unsigned long long*)((char*)gs + 0x3e8) = GetCurrentTimestamp();
            *(unsigned long long*)((char*)gs + 0x3f0) = GetCurrentTimestamp();
        }

        if (loaded != 0) {
            char* save = (char*)GetPtrField0x2a04(gs);
            int count = CopyOutRegion0x5718((char*)gs, ids);
            unsigned char* id;
            if (GetByteField0x63d6((FieldBlock63d6_115a8*)gs) != 0) {
                id = ids;
            } else {
                id = (unsigned char*)(save + 0xf78);
                count = *(unsigned char*)(save + 0xf7c);
            }
            for (int i = 0; i < count; i++, id++) {
                int cur = *id;
                if (cur == GetField0x3acValue(gs)) {
                    func_ov017_0218f064(self, cur, 0x200, 1, 0);
                } else {
                    if (GetLowNibbleAt0x56b(gs, cur) > 0) {
                        func_ov017_0218f064(self, cur, 4, 1, GetLowNibbleAt0x56b(gs, cur));
                    } else {
                        func_ov017_0218f064(self, cur, 0x1000, 1, 0);
                    }
                    void* combatant = GetCombatantWithFlag0x1000(gs, cur);
                    if (combatant != 0) {
                        SetField0x2d0(combatant, GetField0x3acValue(gs));
                    }
                }
                char* member = (char*)GetCombatantWithFlag0x100(gs, cur);
                if (member != 0) {
                    char* info = GetFieldAt0x150((unsigned char*)member);
                    if (info != 0 && (*(int*)(info + 0x18) & 1)) {
                        *(int*)(member + RegionMemberFlags) |= 1;
                    }
                }
            }
            if (func_020dcd40() != 0) {
                func_ov017_02191108(self, 1, 1, 1, 1);
            }
        } else {
            func_ov017_0218f064(self, 0, 0x200, 1, 0);
            if (fresh == 0) {
                func_020897b4(0, 1, 6, 1, 1, 0, 0, 0, 0);
                func_0201099c(gs);
                func_0201229c(&data_02114e30);
                if (GetByte0x4((char*)gs) == 0) {
                    InitStruct02070378((char*)request);
                    request->id = 100;
                    SetField5cb0AndRecordByte0((char*)gs, 3);
                    SetField5cb4AndRecordByte1((char*)gs, 1);
                    SetSlotByte020107dc((char*)gs, 1);
                    SetOrClearBitInArray(bits, (unsigned char*)(bits + 0x8c), 0xaed, 1);
                    func_020120f0(gs);
                    GameObject* hero = gs->GetProtagonist();
                    if (hero != 0) {
                        Party150* party = (Party150*)GetFieldAt0x150((unsigned char*)hero);
                        if (party != 0) {
                            if (TestFlagMask((unsigned short*)&data_02114e30, 0x100)) {
                                party->active = 0;
                            } else if (TestFlagMask((unsigned short*)&data_02114e30, 0x200)) {
                                party->active = 1;
                            } else {
                                party->active = (unsigned char)func_02032370(2);
                            }
                        }
                    }
                } else if (GetByte0x4((char*)gs) == 2) {
                    InitStruct02070378((char*)request);
                    request->id = 0x1905;
                    request->value20 = 0x53fc;
                    SetField5cb0AndRecordByte0((char*)gs, 1);
                    SetField5cb4AndRecordByte1((char*)gs, 1);
                    SetSlotByte020107dc((char*)gs, 1);
                    func_020120f0(gs);
                    char* member = (char*)GetCombatantWithFlag0x100(gs, 0);
                    if (member != 0) {
                        char* info = GetFieldAt0x150((unsigned char*)member);
                        if (info != 0) {
                            *(unsigned short*)(info + 0x496) = 0x4e24;
                        }
                    }
                    showIntro = 1;
                } else {
                    InitStruct02070378((char*)request);
                    request->id = 1;
                    request->flag7 = 1;
                    request->dir = 0;
                    request->pos[0] = 0;
                    request->pos[1] = 0;
                    request->pos[2] = 0;
                    SetField5cb0AndRecordByte0((char*)gs, 1);
                    SetField5cb4AndRecordByte1((char*)gs, 1);
                    SetSlotByte020107dc((char*)gs, 1);
                    func_020120f0(gs);
                }
            }
            if (fresh != 0) {
                char* save = (char*)GetPtrField0x2a04(gs);
                GameObject* hero = gs->GetProtagonist();
                if (hero != 0) {
                    CopyToBattleField02039768((int)hero, save + 0x2c8d);
                }
            }
        }
        func_ov017_02191108(self, 1, 1, 1, 1);
    }

    SetField0x21c(combatCtrl, GetField0x397cValue(gs));
    if (GetByteField0x63d6((FieldBlock63d6_115a8*)gs) == 0) {
        SetWord0x71f8(gs, rand());
        if (GetByte0x4((char*)gs) != 5) {
            func_0206dfe8(bits, 0x79e, 0x2bc);
        }
    }
    void* combatants = func_02057924();
    InitStruct02057930((Foo02057930*)combatants);
    void* entryTable = GetEntryTableBase();
#if defined(jpn)
    _Z19InitEntries02028894P11Big02028894PcS1_(entryTable, self->dataD8);
#else
    _Z19InitEntries02028894P11Big02028894PcS1_(entryTable, self->dataD8, self->data27c);
#endif
    void* battleArrays = GetData02104b6c();
    ResetBattleArrays02039e7c(battleArrays);
    void* controller = GetGlobalField0x1c020421a0();
    func_02042c68(controller);
    func_02043124(controller);
    SetField0x1e28(controller, self->pairTables);
    func_ov017_0219b624(self);
    func_ov017_0219ba0c(self, 0);
    CopyInternalFields0207df50((Foo0207df50*)self->pairTables);
    RestorePairTables0207df90((char*)self->pairTables);
    func_020432c4(controller);
    BackupPairTables0207dfac((char*)self->pairTables);
    if (GetByte0x4((char*)gs) != 6 && GetByte0x4((char*)gs) != 9) {
        self->colorA[0] = 0xd4;
        self->colorB[0] = 8;
        self->colorC[0] = 0;
        self->colorA[1] = 0xc0;
        self->colorB[1] = 8;
        self->colorC[1] = 0;
    }
    func_02020554(self->timedBuffer);
    *(int*)(self->timedBuffer + 0x5a4) |= 1;
    void* handle = GetGlobal02109030();
    func_020938f0(handle);
    ClearTwoRegions0206ebf4((char*)self->regions);
    void* structArray = GetData02108ea8();
    InitStructArray0207d798((Init0207d7c0*)structArray);
    char* lighting = (char*)LightingManager::GetInstance();
    *(float*)(lighting + 0x94) = gs->GetDayTimer();
    *(int*)(lighting + 0x98) = gs->GetTimeOfDay();
    if (GetByte0x4((char*)gs) != 6 && GetByte0x4((char*)gs) != 9) {
        char* flagBits = func_0205ec34();
        if (TestBitInByteArray((int)flagBits, (unsigned char*)(flagBits + 0x8c), 0x1142) != 0) {
            newGame = 0;
        }
        if (newGame == 1) {
            func_ov017_0219bfb4(1, 0);
        } else {
            InitAndResetHeader_0219e310((unsigned char*)self->header70c, 0);
            AppendNodeToTail((TailList020469b4*)self->nodeList, (TailNode020469b4*)self->header70c);
            ClearIfMatchAndFinalize_021a3498((Ctx021a3498*)self->nodeList);
            if (TestBitInByteArray((int)flagBits, (unsigned char*)(flagBits + 0x8c), 0x1142) != 0) {
                func_ov017_021baedc(self->node734, 1);
                *(unsigned short*)(self->node734 + 8) = 0x730a;
                AppendNodeToTail((TailList020469b4*)self->nodeList, (TailNode020469b4*)self->node734);
            }
        }
    }
    if (GetByte0x4((char*)gs) == 6 || GetByte0x4((char*)gs) == 9) {
        void* node = self->node3b4c;
        InitObjState_021b2174((unsigned char*)node);
        if (GetByte0x4((char*)gs) == 6) {
            SetNameChecked_021b2ba0((S021b2ba0*)node, (char*)&data_ov017_021d736c);
            SetFields30And34_021b2bd0(node, (int)func_ov004_0216e9cc, OVERLAY_ID(4));
        } else if (GetByte0x4((char*)gs) == 9) {
            SetNameChecked_021b2ba0((S021b2ba0*)node, (char*)&data_ov017_021d7378);
            SetFields30And34_021b2bd0(node, (int)func_ov004_0216f854, OVERLAY_ID(4));
        }
        AppendNodeToTail((TailList020469b4*)self->nodeList, (TailNode020469b4*)node);
    }
    func_020ca458(0, (void*)0x6000000, GetMainBGAssignedVRAMSize());
    DelayThenSyncBit0();
    RestoreDisplayMode();
    *(volatile unsigned int*)0x4001000 |= 0x10000;
    InitFields02010124((S_02010124*)gs);
    SetActiveDmaChannel020c3a0c(0);
    unsigned long long last = GetCurrentTimestamp();
    void* list = self->list700;
    while (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)list) == 0x13) {
        loader->RemoveAllLocks();
        ClearIfMatchAndFinalize_021a3498((Ctx021a3498*)list);
    }
    func_0206e424(bits, 0);
    if (showIntro != 0) {
        InitObj021bdbf0((unsigned char*)self->node3b60);
        self->node3b60[0x11] = 2;
        AppendNodeToTail((TailList020469b4*)self->nodeList, (TailNode020469b4*)self->node3b60);
    }
    if (GetByteField0x63d6((FieldBlock63d6_115a8*)gs) != 0) {
        ClearByte0x63d6((FieldBlock63d6_115c0*)gs);
    }
    FontBankLoader* global400 = GetGlobal02109400();
    ClearBuffer0202ad30();
    FlushAndClearBuffer0202adf0();

    for (;;) {
        int flag4000 = 0;
        if (GetBitsInField0((unsigned int*)self, 0x4000) != 0) {
            flag4000 = 1;
        }
        InitCombatSubsystems02012efc();
        GameState::GetInstance();
        func_0205ec34();
        AlwaysTrue02094b4c(global400);
        int quit = 0;
        if (self->exitRequest == 1) {
            self->exitRequest = 0;
            quit = 1;
        }
        if (GetFlag0x5cccBit0((StateBits5ccc_11570*)gs) != 0) {
            if (IsBrightnessTransitionActive((GameResources*)self) == 0) {
                quit = 1;
            }
        }
        if (GetByteField0x63d6((FieldBlock63d6_115a8*)gs) != 0 && IsField0Null((void**)self->nodeList) != 0) {
            quit = 1;
            InitStruct02070378((char*)request);
            request->id = *(unsigned short*)bigStruct;
            request->flag7 = quit;
            GameObject* obj = gs->GetUnknownGameObject();
            if (obj != 0) {
                *(Vector3i*)request->pos = *(Vector3i const*)((char*)obj + 0x44);
                request->dir = *(int*)((char*)obj + 0x54);
            }
            if (IsHalfword0x63d8Set((FieldBlock63d8_115d0*)gs) != 0) {
                request->value20 = GetHalfword0x63d8(gs);
                ClearHalfword0x63d8(gs);
                if (RunScriptByValueRange02071574((unsigned short)request->value20, (Obj02071488*)scriptOut) != 0) {
                    request->id = *(unsigned short*)(scriptOut + 0xe);
                    request->flag7 = 0;
                }
            }
            if (CheckField0x63daNonZero(gs) != 0) {
                request->value28 = GetHalfword0x63da(gs);
                ClearHalfword0x63da(gs);
            }
        }
        if (quit != 0) {
            if (GetByte0x4((char*)gs) != 2) {
                DispatchToActiveEntries020bc028(0);
            }
            BlankFunction020d84e0();
            Forward0202aff4(search);
            SetMainBrightness((GameResources*)self, -16, 0);
            SetSubBrightness((GameResources*)self, -16, 0);
            if (GetByte0x4((char*)gs) == 8) {
                SetMainBrightness((GameResources*)self, 16, 0);
                SetSubBrightness((GameResources*)self, 16, 0);
            }
            break;
        }
        func_02043368(controller);
        func_ov017_0218cbd4(self);
        func_ov017_02191cc0(self);
        if (data_ov017_021d82e0.paused == 0 && GetBitsInField4((unsigned int*)self, 1) == 0) {
            func_ov017_02195a20(self);
        }
        if (flag4000 != 0) {
            DispatchByFlag020d9834(1);
        }
        func_0209c840(&data_02109bf4);
        ResetXYField0203aa08(&data_02108760);
        func_020bbd9c();
        _Z33CleanInvalidateOamBuffers0203bd88v(oam);
        Forward0204359c(controller, RegionControllerMode);
        if (flag4000 != 0) {
            DispatchByFlag020d9834(1);
        } else {
            DispatchByFlag020d9834(0);
        }
        loader->RemoveAllLocks();
        NotifyAllEntries0203dd94((char*)extRegion);
        NoOp_0219a188(self);
        NoOp_021a63cc(self);
        if (data_ov017_021d82e0.paused == 0) {
            int speed = *(int*)((char*)gs + 0x3c8);
            for (int f = 1; f < 2 - speed; f++) {
                DelayThenSyncBit0();
            }
            WriteControlAndToggle020d86d0(1, 0);
            self->running = 1;
            DelayThenSyncBit0();
        }
        if (data_ov017_021d82e0.paused != 0) {
            gs->CalculateDeltaTime(0);
        } else {
            unsigned long long now = GetCurrentTimestamp();
            gs->CalculateDeltaTime(((now - last) * 64000) / 33514);
        }
        last = GetCurrentTimestamp();
        data_02114e50++;
        ForwardObjAndField0_021a4358((int)self->nodeList);
        SyncMainSubOam0203bdb0((Obj0203bdb0*)oam);
        int allow = 1;
        if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)self->nodeList) == 2) {
            Holder021a193c* holder = (Holder021a193c*)GetField1c_021a193c((int*)self->list708);
            if (holder != 0 && IS_OBJ_FLAG2_SET(holder)) {
                allow = 0;
            }
        }
        func_020439b0(controller, allow);
        ForEachNode020579ec((Node020579ec**)combatants);
        func_ov017_021a63d0(self);
        func_ov017_0219a18c(self);
        func_0203ba74(regions3);
        func_02027438(self->timedBuffer);
#if !defined(jpn)
        UpdateTimedBufferState020275e4((Obj020275e4*)self->timedBuffer);
#endif
        if (flag4000 != 0) {
            DispatchByFlag020d9834(1);
        }
    }

    if (GetFlag0x5cccBit0((StateBits5ccc_11570*)gs) != 0) {
        SetMainBrightness((GameResources*)self, -16, 0);
        SetSubBrightness((GameResources*)self, -16, 0);
    }
    if (GetByte0x4((char*)gs) != 2) {
        if (GetShortAt0xb4((ShortField0xb4_0205eac8*)&data_02108760) != 100) {
            SetupContextForMode0205ea20(&data_02108760, 100);
        }
        InitActorContext0209c20c((Actor0209c20c*)&data_02109bf4);
        RefreshDisplayState0205e8ec((Obj_0205e8ec*)&data_02108760);
        func_020bbd9c();
    }
    data_02109bf4.flagsC8 &= ~4;
    func_ov017_021a3ef0(self->nodeList);
    Init0203cfb4((Struct_0203cfb4*)extRegion);
    func_ov017_021a316c(self);
    for (int i = 0; i < 0x12; i++) {
        MaybeInvoke0204719c(&self->entries[i]);
    }
    ClearFourRegions020798b8((char*)regions4);
    InitControllerObject((char*)controller);
    ReleaseHandleField340(handle);
    ProcessAllSubObjects0203a54c((Container0203a54c*)battleArrays);
    ClearCombatantsAndInitStruct02057978((Foo02057930*)combatants);
    func_020287b4(entryTable);
    CallHelperFourTimes_02190238(self);
    ResetBigStruct02013750(bigStruct, 1);
    ForwardFirstWord020998ac((int*)buffered);
    FreeWordListBuffer0209cd24((WordList0209cbb8*)wordList);
    InitStructArray0207d798((Init0207d7c0*)structArray);
    func_ov017_0219b938(self);
    ResetOverlayState_0219bc50((unsigned char*)self);
    if (GetByte0x4((char*)gs) == 9 && ownAllocator == 1) {
        void* signedAlloc = self->allocator.GetSignedAllocator();
        if (signedAlloc != 0) {
            self->allocator.Destroy();
            TailForward02012da4((AllocatorUnion*)&data_02114e20, signedAlloc);
        }
        SetByte0x4((char*)gs, 6);
        SetWord0x7f6c(gs, 2);
    }
    int tableMode = self->tableMode;
    if (tableMode == 0) {
        DestroyAllocatorsFromTable_021a0790((char*)self);
    } else if (tableMode == 1) {
        DestroyAllocatorsFromTable_021a0964((char*)self);
    } else if (tableMode == 2) {
        DestroyAllocatorsFromTable_021a0ba8((char*)self);
    } else if (tableMode == 3) {
        DestroyAllocatorsFromTable_021a0f40((char*)self);
    } else if (tableMode == 4) {
        DestroyAllocatorsFromTable_021a1114((char*)self);
    } else if (tableMode == 5) {
        DestroyAllocatorsFromTable_021a0d6c((char*)self);
    }
    func_ov017_021a0470(self);
    ClearCombatantList(gs);
    ResetInputLogB();
    ResetInputLogA();
    *(volatile unsigned int*)0x4000000 &= ~0xe000;
    data_ov017_021d82e0.word4 = 0;
#if !defined(jpn)
    ResetSlotsAndDestroySafeAllocator020e5094();
#endif
    SafeAllocator::GetLiveCount();
    SetWord0x0((int*)gs, 0);
    InitCombatController020a2010(combatCtrl);
    ResetState020a2cf0((Struct020A2CF0*)combatCtrl);
    func_0202df68(combatCtrl);
}
