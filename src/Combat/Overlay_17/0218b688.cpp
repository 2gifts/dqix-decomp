#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "World/ZoneLootableRecord.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "System/OverlayId.h"
#include "Resource/ActionDataTables.h"

struct GameResources;
struct AllocatorUnion;

unsigned int* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0(unsigned int* word, unsigned int bits);
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(unsigned int* word, unsigned int bits);
int GetWord0x7f6c(void* gs);
void SetWord0x7f6c(void* gs, int value);
extern "C" unsigned char _Z18GetByteField0x63d6P20FieldBlock63d6_115a8(void* gs);
extern "C" void _Z15ClearByte0x63d6P20FieldBlock63d6_115c0(void* gs);
void DispatchWithGlobalContext020daf9c(int a, int b, int c, int d);
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void* res, int level, int b);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void* res, int level, int b);
extern "C" void _Z10SetWord0x0Pii(void* gs, int value);
extern "C" char* func_02012fe4();
void* GetField0x3f8Address(GameState* gs);
extern "C" void _Z12Init0201133cPc(void* gs);
void* GetData02109dcc();
void ClearBuffer020a6180(void* p);
void RunScriptIfAvailable020a6194(void* p);
void* GetData02105254();
extern "C" void _Z25ClearThreeRegions0203b634Pc(void* p);
extern "C" void* func_0203bd08();
extern "C" void _Z25InitBattleContext0203bd24Pc(void* p);
void* GetGlobalPtr021075f4();
extern "C" void _Z30InitWithExtendedRegion0203cf58P15Struct_0203cf58(void* p);
extern "C" void* func_0202ae18();
extern "C" void func_0202aec0(void* p);
extern "C" void _Z13SetBitsInWordPjj(void* word, unsigned int bits);
void* GetData02100044();
extern "C" void func_0205e22c(void* p);
void* GetPtrField0x468(void* gs);
extern "C" void _Z20ClearFirstThreeWordsPj(void* p);
extern "C" void _Z12Init021b2f64Ph(void* p);
extern "C" void* _ZN24LootableContainerManager15GetMainInstanceEv();
extern "C" void _ZN24LootableContainerManager5ResetEv(void* mgr);
extern "C" void* func_0208e0a8();
extern "C" void _Z13Reset0208e4bcPc(void* p);
void* GetData02153637();
extern "C" void _Z21InitSlotTable020e3004P17SlotTable020e3004(void* p);
void* GetData02153660();
extern "C" void _Z23ResetEntryArray020e3814P13Entry020e3840(void* p);
void* GetData02153634();
extern "C" void _Z23ClearThreeBytes020e358cP13Bytes020e358c(void* p);
extern "C" char* func_0205ec34();
char* GetGlobal02109418();
extern "C" unsigned char _Z10GetByte0x4Pc(void* gs);
extern "C" void _Z10SetByte0x4Pch(void* gs, unsigned char value);
void ResetState0205facc(void* p);
extern "C" void _Z12Init02095518Pc(void* p);
void ClearBattleRegion0x7ac4();
extern "C" void func_02096524(void* p);
extern "C" void* func_020704fc();
extern "C" void _Z18ClearState02070508P13State02070508(void* p);
extern "C" void func_0209c2e0(void* p, int a, int b);
extern "C" void func_0205e944(void* p, int a);
void* GetGlobalResetObj020d7a50();
extern "C" void _Z26ResetAndClearFlags020d7a5cP16ResetObj020d7a5c(void* p);
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
extern "C" int _Z18CheckField0NonZeroPi(void* p);
void SetField0x3acValue(GameState* gs, int value);
unsigned char GetField0x3acValue(GameState* gs);
extern "C" int _Z30GetSearchStructCurrentArrEntryP20SearchStruct0202c1a4(void* p);
extern "C" void _Z19CallWithAddr4000330i(void* table);
extern "C" void func_ov017_021a02f0(void* self);
extern "C" void _Z24ClearFourRegions02079870Pc(void* p);
extern "C" void _Z24ClearFourRegions020798b8Pc(void* p);
extern "C" void _Z25RunBufferedScript020998c4P11Obj020995c0(void* p);
void* GetGlobalWordList();
extern "C" void _Z21ResetWordList0209cbb8P16WordList0209cbb8(void* p);
void RunScriptIfAvailable0209cbcc(void* p);
void* GetGlobal02109a54();
extern "C" void _Z35PrepareAndRunBufferedScript02099f6cPc(void* p);
void ResetAllocatorSlots020e5058();
extern "C" void* _Z16AllocateAligned4P14AllocatorUnionj(void* alloc, unsigned int size);
void CreateAndResetAllocator020e50ec(void* buf, unsigned int size);
void ResetAndLoadAllocatorSlots020e5114();
extern "C" void func_0207de48(void* p, int a, int b);
void InitStruct02013718(char* p, int a, int b);
extern "C" void func_0202df68(void* p);
extern "C" void _Z18ResetState020a2cf0P14Struct020A2CF0(void* p);
void InitCombatController020a2010(void* p);
void SetField0x3b0Value(GameState* gs, int value);
extern "C" void _Z17ClearListHeadTailP12List02046958(void* list);
extern "C" void func_ov017_021a124c(void* p);
extern "C" void func_ov017_0218f064(void* self, int id, int mask, int b, int extra);
int GetLowNibbleAt0x56b(void* gs, int id);
void* GetCombatantWithFlag0x1000(GameState* gs, int id);
void SetField0x2d0(void* p, unsigned char value);
extern "C" char* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState* gs, int id);
extern "C" char* _Z15GetFieldAt0x150Ph(void* p);
extern "C" int func_020aaf84(void* buf, int a, int b, int c);
int VerifyAndApplySaveBuffer(int flag);
int CheckSaveBufferStatus(int flag);
int AllocateAndProcessScratchBuffer020abca8();
extern "C" void _Z17SetFlag0x5cccBit0P19StateBits5ccc_11544(void* gs);
extern "C" int _Z17GetFlag0x5cccBit0P19StateBits5ccc_11570(void* gs);
void* GetData02109020();
extern "C" void func_0208ea10(void* p, int a);
unsigned long long GetCurrentTimestamp();
extern "C" char* _Z17GetPtrField0x2a04P9GameState(GameState* gs);
extern "C" int _Z19CopyOutRegion0x5718PcPv(void* gs, void* out);
extern "C" int func_020dcd40();
extern "C" void func_ov017_02191108(void* self, int a, int b, int c, int d);
extern "C" void func_020897b4(int a, int b, int c, int d, int e, int f, int g, int h, int i);
extern "C" void func_0201099c(void* gs);
extern "C" void func_0201229c(void* p);
extern "C" void _Z18InitStruct02070378Pc(void* p);
extern "C" void _Z26SetField5cb0AndRecordByte0Pci(void* gs, int v);
extern "C" void _Z26SetField5cb4AndRecordByte1Pci(void* gs, int v);
extern "C" void _Z19SetSlotByte020107dcPci(void* gs, int v);
void SetOrClearBitInArray(void* p, unsigned char* arr, int bit, int set);
extern "C" void func_020120f0(void* gs);
extern "C" int _Z12TestFlagMaskPti(void* flags, int mask);
extern "C" int func_02032370(int n);
void CopyToBattleField02039768(int obj, void* dst);
short GetField0x397cValue(GameState* gs);
void SetField0x21c(void* p, short v);
extern "C" int rand();
void SetWord0x71f8(void* gs, int v);
extern "C" void func_0206dfe8(void* p, int a, int b);
extern "C" void* func_02057924();
extern "C" void _Z18InitStruct02057930P11Foo02057930(void* p);
extern "C" void _Z36ClearCombatantsAndInitStruct02057978P11Foo02057930(void* p);
void* GetEntryTableBase();
#if defined(jpn)
extern "C" void _Z19InitEntries02028894P11Big02028894PcS1_(void* p, void* a);
#else
extern "C" void _Z19InitEntries02028894P11Big02028894PcS1_(void* p, void* a, void* b);
#endif
extern "C" void func_020287b4(void* p);
void* GetData02104b6c();
void ResetBattleArrays02039e7c(void* p);
extern "C" void _Z28ProcessAllSubObjects0203a54cP17Container0203a54c(void* p);
void* GetGlobalField0x1c020421a0();
extern "C" void func_02042c68(void* c);
extern "C" void func_02043124(void* c);
void SetField0x1e28(void* c, void* p);
extern "C" void func_ov017_0219b624(void* self);
extern "C" void func_ov017_0219ba0c(void* self, int a);
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(void* p);
extern "C" void _Z25RestorePairTables0207df90Pc(void* p);
extern "C" void func_020432c4(void* c);
extern "C" void _Z24BackupPairTables0207dfacPc(void* p);
extern "C" void func_02020554(void* p);
void* GetGlobal02109030();
extern "C" void func_020938f0(void* p);
void ReleaseHandleField340(void* p);
extern "C" void _Z23ClearTwoRegions0206ebf4Pc(void* p);
void* GetData02108ea8();
extern "C" void _Z23InitStructArray0207d798P12Init0207d7c0(void* p);
extern "C" char* _ZN15LightingManager11GetInstanceEv();
int TestBitInByteArray(int p, unsigned char* arr, int bit);
extern "C" void func_ov017_0219bfb4(int a, int b);
extern "C" void _Z27InitAndResetHeader_0219e310Phi(void* p, int a);
extern "C" void _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(void* list, void* node);
extern "C" void _Z32ClearIfMatchAndFinalize_021a3498P11Ctx021a3498(void* p);
extern "C" void func_ov017_021baedc(void* p, int a);
extern "C" void _Z21InitObjState_021b2174Ph(void* p);
extern "C" void _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc(void* p, void* name);
void SetFields30And34_021b2bd0(void* p, int a, int b);
extern "C" int GetMainBGAssignedVRAMSize();
extern "C" void func_020ca458(unsigned int value, void* dest, int count);
void DelayThenSyncBit0();
void RestoreDisplayMode();
extern "C" void _Z18InitFields02010124P10S_02010124(void* gs);
void SetActiveDmaChannel020c3a0c(int ch);
extern "C" int _Z23GetHeadNodeIdOrMinusOnePP16HeadNode02046b24(void* p);
extern "C" void func_0206e424(void* p, int a);
extern "C" void _Z15InitObj021bdbf0Ph(void* p);
void ClearBuffer0202ad30();
void FlushAndClearBuffer0202adf0();
extern "C" int _Z15GetBitsInField0Pjj(void* p, unsigned int bits);
extern "C" int _Z15GetBitsInField4Pjj(void* p, unsigned int bits);
void InitCombatSubsystems02012efc();
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void* res);
extern "C" int _Z12IsField0NullPPv(void* p);
extern "C" void _ZN8Vector3iaSERKS_(void* dst, const void* src);
extern "C" int _Z19IsHalfword0x63d8SetP20FieldBlock63d8_115d0(void* gs);
int GetHalfword0x63d8(void* gs);
void ClearHalfword0x63d8(void* gs);
extern "C" int _Z29RunScriptByValueRange02071574jP11Obj02071488(unsigned int v, void* out);
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
extern "C" void _Z24NotifyAllEntries0203dd94Pc(void* p);
void NoOp_0219a188(void* self);
void NoOp_021a63cc(void* self);
void WriteControlAndToggle020d86d0(int a, int b);
void ForwardObjAndField0_021a4358(int p);
extern "C" void _Z22SyncMainSubOam0203bdb0P11Obj0203bdb0(void* p);
extern "C" int* _Z19GetField1c_021a193cPi(void* p);
extern "C" void func_020439b0(void* c, int a);
extern "C" void _Z19ForEachNode020579ecPP12Node020579ec(void* p);
extern "C" void func_ov017_021a63d0(void* self);
extern "C" void func_ov017_0219a18c(void* self);
extern "C" void func_0203ba74(void* p);
extern "C" void func_02027438(void* p);
extern "C" void _Z30UpdateTimedBufferState020275e4P11Obj020275e4(void* p);
extern "C" int _Z14GetShortAt0xb4P23ShortField0xb4_0205eac8(void* p);
void SetupContextForMode0205ea20(void* p, int mode);
extern "C" void _Z24InitActorContext0209c20cP13Actor0209c20c(void* p);
extern "C" void _Z27RefreshDisplayState0205e8ecP12Obj_0205e8ec(void* p);
extern "C" void func_ov017_021a3ef0(void* p);
extern "C" void _Z12Init0203cfb4P15Struct_0203cfb4(void* p);
extern "C" void func_ov017_021a316c(void* self);
extern "C" void _Z20InitControllerObjectPc(void* c);
void CallHelperFourTimes_02190238(void* self);
void ResetBigStruct02013750(void* p, int a);
extern "C" void _Z24ForwardFirstWord020998acPi(void* p);
extern "C" void _Z26FreeWordListBuffer0209cd24P16WordList0209cbb8(void* p);
extern "C" void func_ov017_0219b938(void* self);
extern "C" void _Z26ResetOverlayState_0219bc50Ph(void* self);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(void* alloc, void* p);
extern "C" void _Z35DestroyAllocatorsFromTable_021a0790Pc(void* self);
extern "C" void _Z35DestroyAllocatorsFromTable_021a0964Pc(void* self);
extern "C" void _Z35DestroyAllocatorsFromTable_021a0ba8Pc(void* self);
extern "C" void _Z35DestroyAllocatorsFromTable_021a0f40Pc(void* self);
extern "C" void _Z35DestroyAllocatorsFromTable_021a1114Pc(void* self);
extern "C" void _Z35DestroyAllocatorsFromTable_021a0d6cPc(void* self);
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
    unsigned char field = _Z18GetByteField0x63d6P20FieldBlock63d6_115a8(gs);
    if (mode != 5 && field != 4 && field != 8 && field != 0xc) {
        DispatchWithGlobalContext020daf9c(1, 0, 1, 0);
    }
    _Z17SetMainBrightnessP13GameResourcesii(self, -16, 0);
    _Z16SetSubBrightnessP13GameResourcesii(self, -16, 0);
    _Z10SetWord0x0Pii(gs, (int)self);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char* bigStruct = func_02012fe4();
    Request3f8* request = (Request3f8*)GetField0x3f8Address(gs);
    loader->MaybeReset();
    _Z12Init0201133cPc(gs);
    void* scriptBuf = GetData02109dcc();
    ClearBuffer020a6180(scriptBuf);
    RunScriptIfAvailable020a6194(scriptBuf);
    void* regions3 = GetData02105254();
    _Z25ClearThreeRegions0203b634Pc(regions3);
    void* oam = func_0203bd08();
    _Z25InitBattleContext0203bd24Pc(oam);
    void* extRegion = GetGlobalPtr021075f4();
    _Z30InitWithExtendedRegion0203cf58P15Struct_0203cf58(extRegion);
    void* search = func_0202ae18();
    func_0202aec0(search);
    _Z13SetBitsInWordPjj(self, 2);
    func_0205e22c(GetData02100044());
    void* buffered = GetPtrField0x468(gs);
    _Z20ClearFirstThreeWordsPj(buffered);
    for (int i = 0; i < 4; i++) {
        _Z12Init021b2f64Ph(&self->slots[i]);
    }
    _ZN24LootableContainerManager5ResetEv(_ZN24LootableContainerManager15GetMainInstanceEv());
    _Z13Reset0208e4bcPc(func_0208e0a8());
    _Z21InitSlotTable020e3004P17SlotTable020e3004(GetData02153637());
    _Z23ResetEntryArray020e3814P13Entry020e3840(GetData02153660());
    _Z23ClearThreeBytes020e358cP13Bytes020e358c(GetData02153634());
    char* bits = func_0205ec34();
    char* global418 = GetGlobal02109418();
    if (_Z18GetByteField0x63d6P20FieldBlock63d6_115a8(gs) == 0) {
        if (GetWord0x7f6c(gs) == 5 || _Z10GetByte0x4Pc(gs) == 4) {
            ResetState0205facc(bits);
            _Z12Init02095518Pc(global418);
            ClearBattleRegion0x7ac4();
        }
        func_02096524(global418);
    }
    *(int*)(bits + 0x480) = 0;
    *(int*)(bits + 0x47c) = 0;
    _Z18ClearState02070508P13State02070508(func_020704fc());
    func_0209c2e0(&data_02109bf4, 0x7f, 0);
    func_0205e944(&data_02108760, 0x7f);
    data_02109bf4.flagsC8 &= ~4;
    _Z26ResetAndClearFlags020d7a5cP16ResetObj020d7a5c(GetGlobalResetObj020d7a50());
    if (GetWord0x7f6c(gs) == 5 && _Z10GetByte0x4Pc(gs) != 9) {
        _Z10SetByte0x4Pch(gs, 6);
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
    if (_Z18CheckField0NonZeroPi(search) == 0) {
        SetField0x3acValue(GameState::GetInstance(), 0);
    } else {
        GameState* inst = GameState::GetInstance();
        SetField0x3acValue(inst, _Z30GetSearchStructCurrentArrEntryP20SearchStruct0202c1a4(search));
    }
    _Z19CallWithAddr4000330i(&data_ov017_021d615c);
    func_ov017_021a02f0(self);
    _Z18ClearFlags020466f4P16FlagWord020466f4j(flagWord, 0x100);
    ActionDataTables* regions4 = GetData02108e10();
    _Z24ClearFourRegions02079870Pc(regions4);
    func_02079900(regions4, (SafeAllocator*)self->data150);
    _Z25RunBufferedScript020998c4P11Obj020995c0(buffered);
    void* wordList = GetGlobalWordList();
    _Z21ResetWordList0209cbb8P16WordList0209cbb8(wordList);
    RunScriptIfAvailable0209cbcc(wordList);
    _Z35PrepareAndRunBufferedScript02099f6cPc(GetGlobal02109a54());
    func_0204719c(&self->entries[11]);
    int ownAllocator = 0;
#if !defined(jpn)
    ResetAllocatorSlots020e5058();
    void* slotBuf = _Z16AllocateAligned4P14AllocatorUnionj(&data_02114e20, 0x1866);
    if (slotBuf != 0) {
        CreateAndResetAllocator020e50ec(slotBuf, 0x1866);
    }
    ResetAndLoadAllocatorSlots020e5114();
#endif
    if (_Z10GetByte0x4Pc(gs) == 9) {
        ownAllocator = 1;
        self->allocator.CreateTypeA(_Z16AllocateAligned4P14AllocatorUnionj(&data_02114e20, 0x30000), 0x30000);
        func_0207de48(self->dataF0c, 0x10, 0x10);
    }
    InitStruct02013718(bigStruct, (int)self->data38, (int)self->data2cc);
    func_0202df68(combatCtrl);
    _Z18ResetState020a2cf0P14Struct020A2CF0(combatCtrl);
    InitCombatController020a2010(combatCtrl);
    SetField0x3b0Value(gs, (int)combatCtrl);
    _Z17ClearListHeadTailP12List02046958(self->nodeList);
    _Z17ClearListHeadTailP12List02046958(self->list700);
    _Z17ClearListHeadTailP12List02046958(self->list704);
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

    if (_Z10GetByte0x4Pc(gs) != 6 && _Z10GetByte0x4Pc(gs) != 9) {
        if (_Z18GetByteField0x63d6P20FieldBlock63d6_115a8(gs) != 0) {
            loaded = 1;
        } else {
            if (_Z10GetByte0x4Pc(gs) == 0 || _Z10GetByte0x4Pc(gs) == 5) {
                int isFive = _Z10GetByte0x4Pc(gs) == 5;
                loaded = fresh = 1;
                newGame = !isFive;
                if (GetWord0x7f6c(gs) == 6) {
                    ok = 0;
                    if (func_020aaf84(saveInfo, 0, isFive, 0) != 0) {
                        if (VerifyAndApplySaveBuffer(newGame == 0) != 0) {
                            ok = 1;
                            if (isFive != 0 && CheckSaveBufferStatus(0) == 0 &&
                                AllocateAndProcessScratchBuffer020abca8() == 0) {
                                _Z17SetFlag0x5cccBit0P19StateBits5ccc_11544(gs);
                                ok = 0;
                            }
                        } else {
                            _Z17SetFlag0x5cccBit0P19StateBits5ccc_11544(gs);
                        }
                    }
                    if (ok == 0) {
                        fresh = 0;
                        loaded = fresh;
                        newGame = fresh;
                    }
                }
            }
            if (_Z10GetByte0x4Pc(gs) != 5) {
                func_0208ea10(GetData02109020(), 1);
            }
            *(unsigned long long*)((char*)gs + 0x3e8) = GetCurrentTimestamp();
            *(unsigned long long*)((char*)gs + 0x3f0) = GetCurrentTimestamp();
        }

        if (loaded != 0) {
            char* save = _Z17GetPtrField0x2a04P9GameState(gs);
            int count = _Z19CopyOutRegion0x5718PcPv(gs, ids);
            unsigned char* id;
            if (_Z18GetByteField0x63d6P20FieldBlock63d6_115a8(gs) != 0) {
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
                char* member = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, cur);
                if (member != 0) {
                    char* info = _Z15GetFieldAt0x150Ph(member);
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
                if (_Z10GetByte0x4Pc(gs) == 0) {
                    _Z18InitStruct02070378Pc(request);
                    request->id = 100;
                    _Z26SetField5cb0AndRecordByte0Pci(gs, 3);
                    _Z26SetField5cb4AndRecordByte1Pci(gs, 1);
                    _Z19SetSlotByte020107dcPci(gs, 1);
                    SetOrClearBitInArray(bits, (unsigned char*)(bits + 0x8c), 0xaed, 1);
                    func_020120f0(gs);
                    GameObject* hero = gs->GetProtagonist();
                    if (hero != 0) {
                        Party150* party = (Party150*)_Z15GetFieldAt0x150Ph(hero);
                        if (party != 0) {
                            if (_Z12TestFlagMaskPti(&data_02114e30, 0x100)) {
                                party->active = 0;
                            } else if (_Z12TestFlagMaskPti(&data_02114e30, 0x200)) {
                                party->active = 1;
                            } else {
                                party->active = (unsigned char)func_02032370(2);
                            }
                        }
                    }
                } else if (_Z10GetByte0x4Pc(gs) == 2) {
                    _Z18InitStruct02070378Pc(request);
                    request->id = 0x1905;
                    request->value20 = 0x53fc;
                    _Z26SetField5cb0AndRecordByte0Pci(gs, 1);
                    _Z26SetField5cb4AndRecordByte1Pci(gs, 1);
                    _Z19SetSlotByte020107dcPci(gs, 1);
                    func_020120f0(gs);
                    char* member = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, 0);
                    if (member != 0) {
                        char* info = _Z15GetFieldAt0x150Ph(member);
                        if (info != 0) {
                            *(unsigned short*)(info + 0x496) = 0x4e24;
                        }
                    }
                    showIntro = 1;
                } else {
                    _Z18InitStruct02070378Pc(request);
                    request->id = 1;
                    request->flag7 = 1;
                    request->dir = 0;
                    request->pos[0] = 0;
                    request->pos[1] = 0;
                    request->pos[2] = 0;
                    _Z26SetField5cb0AndRecordByte0Pci(gs, 1);
                    _Z26SetField5cb4AndRecordByte1Pci(gs, 1);
                    _Z19SetSlotByte020107dcPci(gs, 1);
                    func_020120f0(gs);
                }
            }
            if (fresh != 0) {
                char* save = _Z17GetPtrField0x2a04P9GameState(gs);
                GameObject* hero = gs->GetProtagonist();
                if (hero != 0) {
                    CopyToBattleField02039768((int)hero, save + 0x2c8d);
                }
            }
        }
        func_ov017_02191108(self, 1, 1, 1, 1);
    }

    SetField0x21c(combatCtrl, GetField0x397cValue(gs));
    if (_Z18GetByteField0x63d6P20FieldBlock63d6_115a8(gs) == 0) {
        SetWord0x71f8(gs, rand());
        if (_Z10GetByte0x4Pc(gs) != 5) {
            func_0206dfe8(bits, 0x79e, 0x2bc);
        }
    }
    void* combatants = func_02057924();
    _Z18InitStruct02057930P11Foo02057930(combatants);
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
    _Z26CopyInternalFields0207df50P11Foo0207df50(self->pairTables);
    _Z25RestorePairTables0207df90Pc(self->pairTables);
    func_020432c4(controller);
    _Z24BackupPairTables0207dfacPc(self->pairTables);
    if (_Z10GetByte0x4Pc(gs) != 6 && _Z10GetByte0x4Pc(gs) != 9) {
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
    _Z23ClearTwoRegions0206ebf4Pc(self->regions);
    void* structArray = GetData02108ea8();
    _Z23InitStructArray0207d798P12Init0207d7c0(structArray);
    char* lighting = _ZN15LightingManager11GetInstanceEv();
    *(float*)(lighting + 0x94) = gs->GetDayTimer();
    *(int*)(lighting + 0x98) = gs->GetTimeOfDay();
    if (_Z10GetByte0x4Pc(gs) != 6 && _Z10GetByte0x4Pc(gs) != 9) {
        char* flagBits = func_0205ec34();
        if (TestBitInByteArray((int)flagBits, (unsigned char*)(flagBits + 0x8c), 0x1142) != 0) {
            newGame = 0;
        }
        if (newGame == 1) {
            func_ov017_0219bfb4(1, 0);
        } else {
            _Z27InitAndResetHeader_0219e310Phi(self->header70c, 0);
            _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(self->nodeList, self->header70c);
            _Z32ClearIfMatchAndFinalize_021a3498P11Ctx021a3498(self->nodeList);
            if (TestBitInByteArray((int)flagBits, (unsigned char*)(flagBits + 0x8c), 0x1142) != 0) {
                func_ov017_021baedc(self->node734, 1);
                *(unsigned short*)(self->node734 + 8) = 0x730a;
                _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(self->nodeList, self->node734);
            }
        }
    }
    if (_Z10GetByte0x4Pc(gs) == 6 || _Z10GetByte0x4Pc(gs) == 9) {
        void* node = self->node3b4c;
        _Z21InitObjState_021b2174Ph(node);
        if (_Z10GetByte0x4Pc(gs) == 6) {
            _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc(node, &data_ov017_021d736c);
            SetFields30And34_021b2bd0(node, (int)func_ov004_0216e9cc, OVERLAY_ID(4));
        } else if (_Z10GetByte0x4Pc(gs) == 9) {
            _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc(node, &data_ov017_021d7378);
            SetFields30And34_021b2bd0(node, (int)func_ov004_0216f854, OVERLAY_ID(4));
        }
        _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(self->nodeList, node);
    }
    func_020ca458(0, (void*)0x6000000, GetMainBGAssignedVRAMSize());
    DelayThenSyncBit0();
    RestoreDisplayMode();
    *(volatile unsigned int*)0x4001000 |= 0x10000;
    _Z18InitFields02010124P10S_02010124(gs);
    SetActiveDmaChannel020c3a0c(0);
    unsigned long long last = GetCurrentTimestamp();
    void* list = self->list700;
    while (_Z23GetHeadNodeIdOrMinusOnePP16HeadNode02046b24(list) == 0x13) {
        loader->RemoveAllLocks();
        _Z32ClearIfMatchAndFinalize_021a3498P11Ctx021a3498(list);
    }
    func_0206e424(bits, 0);
    if (showIntro != 0) {
        _Z15InitObj021bdbf0Ph(self->node3b60);
        self->node3b60[0x11] = 2;
        _Z16AppendNodeToTailP16TailList020469b4P16TailNode020469b4(self->nodeList, self->node3b60);
    }
    if (_Z18GetByteField0x63d6P20FieldBlock63d6_115a8(gs) != 0) {
        _Z15ClearByte0x63d6P20FieldBlock63d6_115c0(gs);
    }
    FontBankLoader* global400 = GetGlobal02109400();
    ClearBuffer0202ad30();
    FlushAndClearBuffer0202adf0();

    for (;;) {
        int flag4000 = 0;
        if (_Z15GetBitsInField0Pjj(self, 0x4000) != 0) {
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
        if (_Z17GetFlag0x5cccBit0P19StateBits5ccc_11570(gs) != 0) {
            if (_Z28IsBrightnessTransitionActiveP13GameResources(self) == 0) {
                quit = 1;
            }
        }
        if (_Z18GetByteField0x63d6P20FieldBlock63d6_115a8(gs) != 0 && _Z12IsField0NullPPv(self->nodeList) != 0) {
            quit = 1;
            _Z18InitStruct02070378Pc(request);
            request->id = *(unsigned short*)bigStruct;
            request->flag7 = quit;
            GameObject* obj = gs->GetUnknownGameObject();
            if (obj != 0) {
                _ZN8Vector3iaSERKS_(request->pos, (char*)obj + 0x44);
                request->dir = *(int*)((char*)obj + 0x54);
            }
            if (_Z19IsHalfword0x63d8SetP20FieldBlock63d8_115d0(gs) != 0) {
                request->value20 = GetHalfword0x63d8(gs);
                ClearHalfword0x63d8(gs);
                if (_Z29RunScriptByValueRange02071574jP11Obj02071488((unsigned short)request->value20, scriptOut) != 0) {
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
            if (_Z10GetByte0x4Pc(gs) != 2) {
                DispatchToActiveEntries020bc028(0);
            }
            BlankFunction020d84e0();
            Forward0202aff4(search);
            _Z17SetMainBrightnessP13GameResourcesii(self, -16, 0);
            _Z16SetSubBrightnessP13GameResourcesii(self, -16, 0);
            if (_Z10GetByte0x4Pc(gs) == 8) {
                _Z17SetMainBrightnessP13GameResourcesii(self, 16, 0);
                _Z16SetSubBrightnessP13GameResourcesii(self, 16, 0);
            }
            break;
        }
        func_02043368(controller);
        func_ov017_0218cbd4(self);
        func_ov017_02191cc0(self);
        if (data_ov017_021d82e0.paused == 0 && _Z15GetBitsInField4Pjj(self, 1) == 0) {
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
        _Z24NotifyAllEntries0203dd94Pc(extRegion);
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
        _Z22SyncMainSubOam0203bdb0P11Obj0203bdb0(oam);
        int allow = 1;
        if (_Z23GetHeadNodeIdOrMinusOnePP16HeadNode02046b24(self->nodeList) == 2) {
            Holder021a193c* holder = (Holder021a193c*)_Z19GetField1c_021a193cPi(self->list708);
            if (holder != 0 && IS_OBJ_FLAG2_SET(holder)) {
                allow = 0;
            }
        }
        func_020439b0(controller, allow);
        _Z19ForEachNode020579ecPP12Node020579ec(combatants);
        func_ov017_021a63d0(self);
        func_ov017_0219a18c(self);
        func_0203ba74(regions3);
        func_02027438(self->timedBuffer);
#if !defined(jpn)
        _Z30UpdateTimedBufferState020275e4P11Obj020275e4(self->timedBuffer);
#endif
        if (flag4000 != 0) {
            DispatchByFlag020d9834(1);
        }
    }

    if (_Z17GetFlag0x5cccBit0P19StateBits5ccc_11570(gs) != 0) {
        _Z17SetMainBrightnessP13GameResourcesii(self, -16, 0);
        _Z16SetSubBrightnessP13GameResourcesii(self, -16, 0);
    }
    if (_Z10GetByte0x4Pc(gs) != 2) {
        if (_Z14GetShortAt0xb4P23ShortField0xb4_0205eac8(&data_02108760) != 100) {
            SetupContextForMode0205ea20(&data_02108760, 100);
        }
        _Z24InitActorContext0209c20cP13Actor0209c20c(&data_02109bf4);
        _Z27RefreshDisplayState0205e8ecP12Obj_0205e8ec(&data_02108760);
        func_020bbd9c();
    }
    data_02109bf4.flagsC8 &= ~4;
    func_ov017_021a3ef0(self->nodeList);
    _Z12Init0203cfb4P15Struct_0203cfb4(extRegion);
    func_ov017_021a316c(self);
    for (int i = 0; i < 0x12; i++) {
        MaybeInvoke0204719c(&self->entries[i]);
    }
    _Z24ClearFourRegions020798b8Pc(regions4);
    _Z20InitControllerObjectPc(controller);
    ReleaseHandleField340(handle);
    _Z28ProcessAllSubObjects0203a54cP17Container0203a54c(battleArrays);
    _Z36ClearCombatantsAndInitStruct02057978P11Foo02057930(combatants);
    func_020287b4(entryTable);
    CallHelperFourTimes_02190238(self);
    ResetBigStruct02013750(bigStruct, 1);
    _Z24ForwardFirstWord020998acPi(buffered);
    _Z26FreeWordListBuffer0209cd24P16WordList0209cbb8(wordList);
    _Z23InitStructArray0207d798P12Init0207d7c0(structArray);
    func_ov017_0219b938(self);
    _Z26ResetOverlayState_0219bc50Ph(self);
    if (_Z10GetByte0x4Pc(gs) == 9 && ownAllocator == 1) {
        void* signedAlloc = self->allocator.GetSignedAllocator();
        if (signedAlloc != 0) {
            self->allocator.Destroy();
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, signedAlloc);
        }
        _Z10SetByte0x4Pch(gs, 6);
        SetWord0x7f6c(gs, 2);
    }
    int tableMode = self->tableMode;
    if (tableMode == 0) {
        _Z35DestroyAllocatorsFromTable_021a0790Pc(self);
    } else if (tableMode == 1) {
        _Z35DestroyAllocatorsFromTable_021a0964Pc(self);
    } else if (tableMode == 2) {
        _Z35DestroyAllocatorsFromTable_021a0ba8Pc(self);
    } else if (tableMode == 3) {
        _Z35DestroyAllocatorsFromTable_021a0f40Pc(self);
    } else if (tableMode == 4) {
        _Z35DestroyAllocatorsFromTable_021a1114Pc(self);
    } else if (tableMode == 5) {
        _Z35DestroyAllocatorsFromTable_021a0d6cPc(self);
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
    _Z10SetWord0x0Pii(gs, 0);
    InitCombatController020a2010(combatCtrl);
    _Z18ResetState020a2cf0P14Struct020A2CF0(combatCtrl);
    func_0202df68(combatCtrl);
}
