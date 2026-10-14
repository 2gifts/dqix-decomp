#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "System/Cache.h"
#include "System/Graphics.h"
#include "System/LoadToVRAM.h"
#include "System/OverlayId.h"
#include "System/VRAM.h"

#if defined(jpn)
enum { kRegionValue6C_8C = 0x8c };
enum { kRegionValue3A39C_37EDC = 0x37edc };
enum { kRegionValueDB8_D90 = 0xd90 };
enum { kRegionValue964_8CC = 0x8cc };
enum { kRegionValueD88_D4C = 0xd4c };
enum { kRegionValue508_608 = 0x608 };
enum { kRegionValueD9C_D60 = 0xd60 };
enum { kRegionValue424_444 = 0x444 };
#else
enum { kRegionValue6C_8C = 0x6c };
enum { kRegionValue3A39C_37EDC = 0x3a39c };
enum { kRegionValueDB8_D90 = 0xdb8 };
enum { kRegionValue964_8CC = 0x964 };
enum { kRegionValueD88_D4C = 0xd88 };
enum { kRegionValue508_608 = 0x508 };
enum { kRegionValueD9C_D60 = 0xd9c };
enum { kRegionValue424_444 = 0x424 };
#endif

struct Obj020397cc;
struct ListHead02046b60;
struct Foo0207df50;
struct S_e830;
struct SubBgControlBackup02074b64;
struct Struct02074bd0;
struct Struct02074bf4;
struct NodeList02058564;

struct GXDispCnt {
    unsigned int low : 24;
    unsigned int bgCharBase : 3;
    unsigned int bgScrBase : 3;
    unsigned int extPltt : 2;
};

struct SceneSwap0217e6b0 {
    char pad0;
    unsigned char done;
    char pad2[6];
    SafeAllocator allocator;
    void* scene;
    int state;
    char controlBackup[0x10];
    unsigned char b34;
    unsigned char b35;
    char pad36[2];
    int visiblePlanes;
    int subVisiblePlanes;
    int bgBanks;
    int subBgBanks;
    int objBanks;
    int subObjBanks;
    int textureBanks;
    int paletteBanks;
    int bgScrBase;
    int bgCharBase;
    int dispCntFlags;
    int subDispCntFlags;
    int pairTable[10];
    int globalPair[2];
    unsigned int textureSize;
    unsigned int paletteSize;
    unsigned short clearColor;
    char padA2[2];
    int word;
    int field4;
    int field8;
    void* fieldB0;
    unsigned char sceneArg;
};

void CancelPendingAction020397cc(Obj020397cc* obj, int arg1);
int IsField0Null_02046b08(void** obj);
void SetBitsInWord_0203b4a0(unsigned int* obj, unsigned int mask);
void SetBitsInField4_0203b4d8(unsigned int* obj, unsigned int mask);
void SetBitsInField8_0203b510(unsigned int* obj, unsigned int mask);
void ClearBitsInWord_0203b4b0(unsigned int* obj, unsigned int mask);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);
void ClearBitsInField8_0203b520(unsigned int* obj, unsigned int mask);
int GetWord_0203b498(unsigned int* obj);
int GetField4_0203b4d0(unsigned int* obj);
int GetField8_0203b508(unsigned int* obj);
void SetBrightness(GameResources* resources, int brightness, int duration);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void func_02074af4(void* obj);
void BackupSubBgControlRegisters(SubBgControlBackup02074b64* backup);
void BackupPairTableToBuffer_020bb700(int* buffer);
void RestorePairTableFromBuffer_020bb740(int* buffer);
void ReadGlobalPair020bb910(int* pair);
extern "C" void* func_02012fe4(void);
unsigned short GetFieldAt0x7e_0201e830(S_e830* obj);
void ResetOverlayAndAllocator_0219bf74(void);
void CopyInternalFields0207df50(Foo0207df50* p);
extern "C" void func_020a1940(unsigned int id);
void PushInputLogB_020a1ef0(int id);
extern "C" void func_ov009_0218454c(void* scene, int a, int b);
extern "C" void func_ov008_021842a0(void* scene, SafeAllocator* alloc);
extern "C" void func_02082828(void* obj);
void SetField0x3b0Value_020100c4(GameState* gs, int v);
void SetPowCnt1Bit15_0217eea8(int enable);
void LockStagedTextureVRAMCopying(void);
void UnlockStagedTextureVRAMCopying(void);
void UpdateVRAMStagingVRAMBanks(void);
void ConfigurePairMode020bb48c(unsigned int mode, int flag);
void SetDispcntModeAndFlags020c391c(int a, int b, int c);
void SetSubBgMode_020c3984(unsigned int mode);
void Set3DClearColor_020c5588(int color, int alpha, int depth, int polygonId, int fog);
void SetFogState_020c54a4(int enable, unsigned int mode, unsigned int shift, unsigned short offset);
extern "C" void* func_0203bd08(void);
void InitBattleContext0203bd24(char* ctx);
int* GetGlobalPtr02105244_0203bd14(void);
extern "C" int func_0203be4c(void* ctx);
extern "C" void func_0203c35c(int* ptr);
extern "C" int func_ov009_02184a18(void* scene);
void ClearFlag0x10IfSet(Struct02074bd0* obj);
void ClearFlag0x11IfSet(Struct02074bf4* obj);
void GetFieldAt0x150_02053c6c(unsigned char* obj);
void ProcessCombatantsIfFlagged_0218f79c(void* res);
void ProcessSlotField58_021a2840(GameResources* res);
extern "C" void* func_02057924(void);
void CleanupNodeList02058564(NodeList02058564* list);
extern "C" void func_ov017_0219b624(GameResources* res);
extern "C" void func_ov017_0219ba0c(GameResources* res, int v);
int GetGlobalField0x1c020421a0(void);
void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);
extern "C" void func_020432c4(void* controller);
void AppendNode_021b66b8(char* obj);
void SetNodeStatus2_021b66f0(unsigned char* obj);
extern "C" void func_ov003_0217e67c(void* self);
extern "C" void func_ov017_0219bd1c(int a, int b, int c, int d);
void CallHelperFourTimesWithSelf_0218f758(void* res);
int ListContainsId(ListHead02046b60* list, int id);
void SetByteField0x253_020397c0(void* obj);

enum GXOBJVRamMode {
    GX_OBJVRAMMODE_DEFAULT = 0
};

static inline void GX_SetOBJVRamMode(GXOBJVRamMode mode) {
    DISPCNT = (unsigned int)((DISPCNT & ~0x300010) | mode);
}

static inline void GXS_SetOBJVRamMode(GXOBJVRamMode mode) {
    DISPCNTSUB = (unsigned int)((DISPCNTSUB & ~0x300010) | mode);
}

static inline GXDispCnt GX_GetDispCnt(void) {
    return *(volatile GXDispCnt*)&DISPCNT;
}

// USA: func_ov003_0217e6b0
extern "C" ARM void func_ov003_0217e6b0(SceneSwap0217e6b0* self) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    GameObject* leader = gs->GetUnknownGameObject();
    CancelPendingAction020397cc((Obj020397cc*)leader, 1);

    if (self->state == 0) {
        if (!IsField0Null_02046b08((void**)res->unknown_ptr_array_36fc[1])) {
            return;
        }
        SetBitsInWord_0203b4a0((unsigned int*)res, 0x10);
        SetBitsInField4_0203b4d8((unsigned int*)res, 0xc0);
        SetBrightness(res, -0x10, 0xf);
        self->state++;
    } else if (self->state == 1) {
        if (IsBrightnessTransitionActive(res)) {
            return;
        }
        self->b34 = 0;
        self->b35 = 0;
        func_02074af4(self->controlBackup);
        self->visiblePlanes = (DISPCNT & 0x1f00) >> 8;
        BackupSubBgControlRegisters((SubBgControlBackup02074b64*)self->controlBackup);
        self->subVisiblePlanes = (DISPCNTSUB & 0x1f00) >> 8;
        self->bgBanks = GetMainBGVRAMBanks();
        self->subBgBanks = GetSubBGVRAMBanks();
        self->objBanks = GetMainObjVRAMBanks();
        self->subObjBanks = GetSubObjVRAMBanks();
        self->textureBanks = GetTextureImageVRAMBanks();
        self->paletteBanks = GetTexturePaletteVRAMBanks();
        self->textureSize = GetTextureImageAssignedVRAMSize();
        self->paletteSize = GetTexturePaletteAssignedVRAMSize();
        BackupPairTableToBuffer_020bb700(self->pairTable);
        ReadGlobalPair020bb910(self->globalPair);
        GXDispCnt dispCnt = GX_GetDispCnt();
        self->bgScrBase = dispCnt.bgScrBase;
        self->bgCharBase = dispCnt.bgCharBase;
        self->dispCntFlags = DISPCNT & 0x300010;
        self->subDispCntFlags = DISPCNTSUB & 0x300010;
        self->clearColor = GetFieldAt0x7e_0201e830((S_e830*)((char*)func_02012fe4() + kRegionValue6C_8C));
        self->word = GetWord_0203b498((unsigned int*)res);
        self->field4 = GetField4_0203b4d0((unsigned int*)res);
        self->field8 = GetField8_0203b508((unsigned int*)res);
        SetBitsInWord_0203b4a0((unsigned int*)res, 4);
        SetBitsInField4_0203b4d8((unsigned int*)res, 0x8de);
        ResetOverlayAndAllocator_0219bf74();
        res->allocator_array_38[0].Reset();
        CopyInternalFields0207df50((Foo0207df50*)res->unknown_2cc);
        self->allocator.CreateTypeA(res->allocator_array_38[0].Allocate(kRegionValue3A39C_37EDC), kRegionValue3A39C_37EDC);
        self->allocator.Reset();
        self->scene = self->allocator.Allocate(kRegionValueDB8_D90);
        func_020a1940(OVERLAY_ID(9));
        PushInputLogB_020a1ef0(1);
        func_ov009_0218454c(self->scene, self->sceneArg, 1);
        func_ov008_021842a0(self->scene, &self->allocator);
        void* extra = self->allocator.Allocate(kRegionValue964_8CC);
        if (extra) {
            func_02082828(extra);
            *(void**)((char*)self->scene + kRegionValueD88_D4C) = extra;
        }
        self->fieldB0 = GetField0x3b0Value_020100bc(gs);
        SetPowCnt1Bit15_0217eea8(1);
        self->state++;
    } else if (self->state == 2) {
        LockStagedTextureVRAMCopying();
        DisableSubBGVRAMBanks();
        DisableMainObjVRAMBanks();
        DisableSubObjVRAMBanks();
        DisableTextureImageVRAMBanks();
        MapVRAMBanksToTextureImage(1);
        ConfigurePairMode020bb48c(1, 1);
        MapVRAMBanksToSubBG(4);
        MapVRAMBanksToMainObj(0x20);
        DISPCNT = (DISPCNT & 0xffcfffef) | 0x10;
        MapVRAMBanksToSubObj(8);
        DISPCNTSUB = (DISPCNTSUB & 0xffcfffef) | 0x10;
        UpdateVRAMStagingVRAMBanks();
        UnlockStagedTextureVRAMCopying();
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1f00;
        SetDispcntModeAndFlags020c391c(1, 0, 1);
        BG1CNT = (BG1CNT & 0x43) | 0x1d00;
        BG2CNT = (BG2CNT & 0x43) | 0x1e08;
        BG3CNT = (BG3CNT & 0x43) | 0x1f0c;
        BG0CNT = (BG0CNT & ~3) | 2;
        BG1CNT = (BG1CNT & ~3) | 3;
        BG2CNT = (BG2CNT & ~3) | 1;
        BG3CNT = BG3CNT & ~3;
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1700;
        SetSubBgMode_020c3984(0);
        BG0CNTSUB = (BG0CNTSUB & 0x43) | 0x1d00;
        BG1CNTSUB = (BG1CNTSUB & 0x43) | 0x1e10;
        BG2CNTSUB = (BG2CNTSUB & 0x43) | 0x1f18;
        BG0CNTSUB = (BG0CNTSUB & ~3) | 2;
        BG1CNTSUB = (BG1CNTSUB & ~3) | 1;
        BG2CNTSUB = BG2CNTSUB & ~3;
        Set3DClearColor_020c5588(0, 0, 0x7fff, 0, 0);
        SetFogState_020c54a4(0, 0, 0, 0);
        char* context = (char*)func_0203bd08();
        InitBattleContext0203bd24(context);
        *(int*)context = 0;
        int* global = GetGlobalPtr02105244_0203bd14();
        *global = func_0203be4c(context) + 0x200;
        func_0203c35c(global);
        global[kRegionValue508_608 / 4] = 0x7000;
        self->state++;
    } else if (self->state == 3) {
        if (func_ov009_02184a18(self->scene)) {
            self->state++;
        }
    } else if (self->state == 4) {
        SetPowCnt1Bit15_0217eea8(0);
        DisableSubBGVRAMBanks();
        DisableMainObjVRAMBanks();
        DisableSubObjVRAMBanks();
        DisableTextureImageVRAMBanks();
        MapVRAMBanksToSubBG(self->subBgBanks);
        MapVRAMBanksToMainObj(self->objBanks);
        MapVRAMBanksToSubObj(self->subObjBanks);
        MapVRAMBanksToTextureImage(self->textureBanks);
        ConfigurePairMode020bb48c((unsigned short)(self->textureSize >> 17), 1);
        RestorePairTableFromBuffer_020bb740(self->pairTable);
        GX_SetOBJVRamMode((GXOBJVRamMode)self->dispCntFlags);
        GXS_SetOBJVRamMode((GXOBJVRamMode)self->subDispCntFlags);
        DISPCNT = (DISPCNT & ~0x1f00) | (self->visiblePlanes << 8);
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | (self->subVisiblePlanes << 8);
        ClearFlag0x10IfSet((Struct02074bd0*)self->controlBackup);
        ClearFlag0x11IfSet((Struct02074bf4*)self->controlBackup);
        Set3DClearColor_020c5588(self->clearColor, 0x10, 0x7fff, 0, 0);
        char blank[0x20];
        memset(blank, 0, 0x20);
        CleanInvalidateCacheRange(blank, 0x20);
        LoadToMainBG1CharacterData(blank, 0, 0x20);
        ClearBitsInWord_0203b4b0((unsigned int*)res, -1);
        ClearBitsInField4_0203b4e8((unsigned int*)res, -1);
        ClearBitsInField8_0203b520((unsigned int*)res, -1);
        SetBitsInWord_0203b4a0((unsigned int*)res, self->word);
        SetBitsInField4_0203b4d8((unsigned int*)res, self->field4);
        SetBitsInField8_0203b510((unsigned int*)res, self->field8);
        SetBitsInWord_0203b4a0((unsigned int*)res, 4);
        SetBitsInField4_0203b4d8((unsigned int*)res, 2);
        GetFieldAt0x150_02053c6c((unsigned char*)gs->GetProtagonist());
        ProcessCombatantsIfFlagged_0218f79c(res);
        ProcessSlotField58_021a2840(res);
        CleanupNodeList02058564((NodeList02058564*)func_02057924());
        SetField0x3b0Value_020100c4(gs, (int)self->fieldB0);
        func_ov017_0219b624(res);
        func_ov017_0219ba0c(res, 0);
        char* fields = res->unknown_2cc;
        void* controller = (void*)GetGlobalField0x1c020421a0();
        CopyInternalFields0207df50((Foo0207df50*)(fields + 0x5b0));
        RestorePairTables0207df90(fields + 0x5b0);
        func_020432c4(controller);
        BackupPairTables0207dfac(fields + 0x5b0);
        self->state++;
    } else if (self->state == 5) {
        if (*(int*)((char*)self->scene + kRegionValueD9C_D60) & 0x400) {
            AppendNode_021b66b8((char*)res);
        } else {
            SetNodeStatus2_021b66f0((unsigned char*)res);
        }
        func_ov003_0217e67c(self);
        ClearBitsInWord_0203b4b0((unsigned int*)res, 0x10);
        func_ov017_0219bd1c(1, 0, 0, 0);
        self->state++;
    } else if (self->state == 6) {
        if (*(int*)((char*)func_02012fe4() + kRegionValue424_444) != 0) {
            return;
        }
        ClearBitsInField4_0203b4e8((unsigned int*)res, 2);
        CallHelperFourTimesWithSelf_0218f758(res);
        SetMainBrightness(res, 0, 0xf);
        self->state++;
    } else {
        if (IsBrightnessTransitionActive(res)) {
            return;
        }
        self->done = 1;
        if (ListContainsId((ListHead02046b60*)res->unknown_ptr_array_36fc[0], 0x17)) {
            return;
        }
        SetByteField0x253_020397c0(leader);
        ClearBitsInField4_0203b4e8((unsigned int*)res, 0xc0);
        return;
    }
    CancelPendingAction020397cc((Obj020397cc*)leader, 1);
}
