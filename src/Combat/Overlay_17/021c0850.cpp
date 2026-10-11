// JPN: func_ov017_021c0df8
#include <globaldefs.h>

#if defined(jpn)
enum { kSceneHeapSize = 0x1e384, kSceneObjectSize = 0xb44, kGlobalColorOffset = 0x8c, kGlobalWordOffset = 0x608, kGlobalStateOffset = 0x228, kGlobalFlagOffset = 0x236 };
#else
enum { kSceneHeapSize = 0x1e388, kSceneObjectSize = 0xb48, kGlobalColorOffset = 0x6c, kGlobalWordOffset = 0x508, kGlobalStateOffset = 0x2d8, kGlobalFlagOffset = 0x2e6 };
#endif

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "System/Cache.h"
#include "System/ColorEffects.h"
#include "System/Graphics.h"
#include "System/LoadToVRAM.h"
#include "System/OverlayId.h"
#include "System/VRAM.h"
#include "World/Object3D.h"

struct AllocatorUnion;
struct Obj020397cc;
struct Obj021c0820;
struct S_e830;
struct SubBgControlBackup02074b64;
struct Struct02074bd0;
struct Struct02074bf4;
struct HeadList020469f8;
struct HeadNode020469f8;

struct GXDispCnt {
    unsigned int low : 24;
    unsigned int bgCharBase : 3;
    unsigned int bgScrBase : 3;
    unsigned int extPltt : 2;
};

struct Scene021c0850 {
    char pad0[0xb13];
    unsigned char kind;
    short x;
    short y;
    union {
        unsigned int flags;
        struct {
            unsigned int bit0 : 1;
            unsigned int bits1 : 17;
            unsigned int bit18 : 1;
            unsigned int rest : 13;
        } bits;
    };
    char padB1c[0xc];
    unsigned char b28;
    unsigned char b29;
};

struct SceneSwap021c0850 {
    char pad0;
    unsigned char done;
    char pad2[6];
    SafeAllocator allocator;
    Scene021c0850* scene;
    int state;
    unsigned char b24;
    unsigned char b25;
    unsigned char b26;
    char pad27;
    short x;
    short y;
    char controlBackup[0x10];
    unsigned char b3c;
    unsigned char b3d;
    char pad3e[2];
    int visiblePlanes;
    int subVisiblePlanes;
    int bgBanks;
    int subBgBanks;
    char pad50[8];
    int textureBanks;
    int paletteBanks;
    int bgScrBase;
    int bgCharBase;
    int dispCntFlags;
    char pad6c[4];
    int pairTable[10];
    int globalPair[2];
    unsigned int textureSize;
    unsigned int paletteSize;
    unsigned short clearColor;
    char padAa[2];
    int word;
    int field4;
    int field8;
    int fieldB8;
    unsigned char bbc;
};

extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc* obj, int arg1);
extern "C" void func_020a0cc4(unsigned int size);
extern "C" void func_020a0c0c(void);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_020a1940(unsigned int id);
void PushInputLogB(int id);
extern "C" void func_ov008_021843f8(void* scene);
extern "C" void func_ov008_021842a0(void* scene, SafeAllocator* alloc);
extern "C" int _Z14GetShortAt0xb8P23ShortField0xb8_0209cae8(void* obj);
extern "C" void _Z30DispatchContextByState0209c678P13Actor0209c678i(void* actor, int arg);
extern "C" void* func_02012fe4(void);
extern void* GetGlobalPtr021075f4(void);
extern "C" void func_0203e0a0(void* g, unsigned short val);
extern "C" int _Z15GetAxisIntValueP18AxisFloats0203b57ci(void* obj, int axis);
void SetBrightness(GameResources* resources, int brightness, int duration);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
int IsBrightnessTransitionActive(GameResources* resources);
extern "C" void func_02074af4(void* obj);
void BackupSubBgControlRegisters(SubBgControlBackup02074b64* backup);
void BackupPairTableToBuffer(int* buffer);
void RestorePairTableFromBuffer(int* buffer);
extern "C" void _Z22ReadGlobalPair020bb910Pi(int* pair);
unsigned short GetFieldAt0x7e(S_e830* obj);
int GetWord(unsigned int* obj);
int GetField4(unsigned int* obj);
int GetField8(unsigned int* obj);
int GetField0x3b0Value(GameState* gs);
void SetField0x3b0Value(GameState* gs, int v);
void LockStagedTextureVRAMCopying(void);
void UnlockStagedTextureVRAMCopying(void);
void UpdateVRAMStagingVRAMBanks(void);
extern "C" void _Z25ConfigurePairMode020bb48cji(unsigned int mode, int flag);
extern "C" void _Z30SetDispcntModeAndFlags020c391ciii(int a, int b, int c);
void SetSubBgMode(unsigned int mode);
void SetBitsInWord(unsigned int* obj, unsigned int mask);
void SetBitsInField4(unsigned int* obj, unsigned int mask);
void SetBitsInField8(unsigned int* obj, unsigned int mask);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void ClearBitsInField8(unsigned int* obj, unsigned int mask);
void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fog);
void SetFogState(int enable, unsigned int mode, unsigned int shift, unsigned short offset);
extern "C" void* func_0203bd08(void);
extern "C" void _Z25InitBattleContext0203bd24Pc(char* ctx);
int* GetGlobalPtr02105244(void);
extern "C" int func_0203be4c(void* ctx);
extern "C" void func_0203c35c(int* ptr);
extern "C" int func_ov017_021959b4(void);
extern "C" void _Z28SetFlagBit_02184a2c_02184a2cPc(void* obj);
extern "C" int func_ov008_02184754(void* obj);
void ClearFlag0x10IfSet(Struct02074bd0* obj);
void ClearFlag0x11IfSet(Struct02074bf4* obj);
extern "C" void* func_ov008_021845ac(void* obj);
extern "C" void _Z35ProcessCombatantsIfFlagged_0218f79cPv(void* res);
extern "C" void func_ov017_0219b624(GameResources* res);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(char* p);
extern "C" void _Z25RestorePairTables0207df90Pc(char* obj);
extern "C" void _Z24BackupPairTables0207dfacPc(char* obj);
extern "C" void func_020432c4(void* controller);
extern "C" void func_ov017_0219bd1c(int a, int b, int c, int d);
extern "C" void _Z36InitAllocatorAndClearFields_021c0820P11Obj021c0820(void* obj);
extern "C" void _Z20InitState40_021c0334P11Obj021c0334(void* obj);
extern "C" void _Z20InitState37_021b14a0P11Obj021b14a0(void* obj);
extern "C" void _Z23SetByteField49_021b1d3cPvi(void* obj, int v);
void PrependNodeToHead(HeadList020469f8* list, HeadNode020469f8* node);
extern "C" void func_ov017_021c0580(void* self, int kind, const char* name, void* handler);
extern "C" int func_0209cd50(int id);
extern "C" void _Z27SetStateAndDispatch0209c3b4P13Actor0209c3b4i(void* actor, int v);
void SetByteField0x253(void* obj);
extern "C" void func_ov017_021c07d0(void* self);
extern "C" int _Z30AllocateAndDispatch20_0215502cP13SafeAllocatori(SafeAllocator* alloc, int arg);
extern "C" int _Z30AllocateAndDispatch14_021560b0P13SafeAllocatori(SafeAllocator* alloc, int arg);
extern "C" int _Z29AllocateAndDispatch8_02156dc8P13SafeAllocatori(SafeAllocator* alloc, int arg);
extern "C" int _Z36AllocateAndCopyHandlerTable_021677b4P13SafeAllocatorPv(SafeAllocator* alloc, void* arg);
extern "C" int _Z29AllocateAndCopyBuf76_0216aa70P13SafeAllocatorPv(SafeAllocator* alloc, void* arg);

extern AllocatorUnion data_02114e20;
extern int data_02109bf4;
extern char data_ov017_021d7f00[];
extern char data_ov017_021d7f07[];
extern char data_ov017_021d7f12[];
extern char data_ov017_021d7f19[];
extern char data_ov017_021d7f22[];

#define POWCNT1 (*(volatile unsigned short*)0x04000304)

static inline void GX_SetDispSelect(int sel) {
    POWCNT1 = (unsigned short)((POWCNT1 & ~0x8000) | (sel << 15));
}

static inline void G2_SetBG3Priority(int priority) {
    BG3CNT = (unsigned short)((BG3CNT & ~3) | priority);
}

static inline void GXS_SetVisiblePlane(int plane) {
    DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | (plane << 8);
}

static inline GXDispCnt GX_GetDispCnt(void) {
    return *(volatile GXDispCnt*)&DISPCNT;
}

// USA: func_ov017_021c0850
extern "C" ARM void func_ov017_021c0850(SceneSwap021c0850* self) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    GameObject* leader = gs->GetUnknownGameObject();
    _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)leader, 1);

    if (self->state == 0) {
        func_020a0cc4(kSceneHeapSize);
        void* buffer = AllocateAligned4(&data_02114e20, kSceneHeapSize);
        if (buffer == NULL) {
            func_020a0c0c();
            self->done = 1;
            return;
        }
        self->allocator.CreateTypeA(buffer, kSceneHeapSize);
        self->allocator.Reset();
        self->scene = (Scene021c0850*)self->allocator.Allocate(kSceneObjectSize);
        if (self->scene == NULL) {
            func_020a0c0c();
            self->done = 1;
            return;
        }
        func_020a1940(OVERLAY_ID(8));
        PushInputLogB(1);
        func_ov008_021843f8(self->scene);
        func_ov008_021842a0(self->scene, &self->allocator);
        self->scene->b28 = self->b24;
        self->scene->b29 = self->b25;
        self->scene->x = self->x;
        self->scene->y = self->y;
        Scene021c0850* scene = self->scene;
        if (self->b26) {
            scene->flags |= 0x40000;
        } else {
            scene->flags &= ~0x40000;
        }
        if (self->bbc) {
            self->scene->flags |= 1;
            if (_Z14GetShortAt0xb8P23ShortField0xb8_0209cae8(&data_02109bf4) != 0x29) {
                _Z30DispatchContextByState0209c678P13Actor0209c678i(&data_02109bf4, 0xf);
            }
        }
        unsigned short* id = (unsigned short*)func_02012fe4();
        func_0203e0a0(GetGlobalPtr021075f4(), *id);
        if (_Z15GetAxisIntValueP18AxisFloats0203b57ci(res, 0) != -0x10
            || _Z15GetAxisIntValueP18AxisFloats0203b57ci(res, 1) != -0x10) {
            SetBrightness(res, -0x10, 0xf);
        }
        self->state++;
    } else if (self->state == 1) {
        if (IsBrightnessTransitionActive(res)) {
            return;
        }
        if (!self->bbc) {
            self->state++;
            return;
        }
        self->b3c = 0;
        self->b3d = 0;
        func_02074af4(self->controlBackup);
        self->visiblePlanes = (DISPCNT & 0x1f00) >> 8;
        BackupSubBgControlRegisters((SubBgControlBackup02074b64*)self->controlBackup);
        self->subVisiblePlanes = (DISPCNTSUB & 0x1f00) >> 8;
        self->bgBanks = GetMainBGVRAMBanks();
        self->subBgBanks = GetSubBGVRAMBanks();
        self->textureBanks = GetTextureImageVRAMBanks();
        self->paletteBanks = GetTexturePaletteVRAMBanks();
        self->textureSize = GetTextureImageAssignedVRAMSize();
        self->paletteSize = GetTexturePaletteAssignedVRAMSize();
        BackupPairTableToBuffer(self->pairTable);
        _Z22ReadGlobalPair020bb910Pi(self->globalPair);
        GXDispCnt dispCnt = GX_GetDispCnt();
        self->bgScrBase = dispCnt.bgScrBase;
        self->bgCharBase = dispCnt.bgCharBase;
        self->dispCntFlags = DISPCNT & 0x300010;
        self->clearColor = GetFieldAt0x7e((S_e830*)((char*)func_02012fe4() + kGlobalColorOffset));
        self->word = GetWord((unsigned int*)res);
        self->field4 = GetField4((unsigned int*)res);
        self->field8 = GetField8((unsigned int*)res);
        self->fieldB8 = GetField0x3b0Value(gs);
        self->state++;
    } else if (self->state == 2) {
        LockStagedTextureVRAMCopying();
        DisableSubBGVRAMBanks();
        DisableSubObjVRAMBanks();
        DisableTextureImageVRAMBanks();
        GX_SetDispSelect(0);
        MapVRAMBanksToTextureImage(1);
        _Z25ConfigurePairMode020bb48cji(1, 1);
        MapVRAMBanksToSubBG(4);
        MapVRAMBanksToSubObj(0x100);
        DISPCNTSUB = (DISPCNTSUB & 0xffcfffef) | 0x10;
        UpdateVRAMStagingVRAMBanks();
        UnlockStagedTextureVRAMCopying();
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1300;
        _Z30SetDispcntModeAndFlags020c391ciii(1, 0, 1);
        BG1CNT = (BG1CNT & 0x43) | 0x1e00;
        BG0CNT = (BG0CNT & ~3) | 1;
        BG1CNT = (BG1CNT & ~3) | 2;
        BG2CNT = (BG2CNT & ~3) | 3;
        G2_SetBG3Priority(0);
        ColorEffect_ConfigureAlphaBlend(0x04000050, 1, 2, 0xf, 0x1f);
        GXS_SetVisiblePlane(0x13);
        SetSubBgMode(0);
        BG0CNTSUB = (BG0CNTSUB & 0x43) | 0xe00;
        BG1CNTSUB = (BG1CNTSUB & 0x43) | 0xf08;
        BG0CNTSUB = (BG0CNTSUB & ~3) | 1;
        BG1CNTSUB = BG1CNTSUB & ~3;
        BG2CNTSUB = (BG2CNTSUB & ~3) | 2;
        BG3CNTSUB = (BG3CNTSUB & ~3) | 3;
        SetBitsInWord((unsigned int*)res, 4);
        SetBitsInField4((unsigned int*)res, 0x8de);
        Set3DClearColor(0, 0, 0x7fff, 0, 0);
        SetFogState(0, 0, 0, 0);
        char* context = (char*)func_0203bd08();
        _Z25InitBattleContext0203bd24Pc(context);
        *(int*)context = 0;
        int* global = GetGlobalPtr02105244();
        *global = func_0203be4c(context) + 0x200;
        func_0203c35c(global);
        global[kGlobalWordOffset / 4] = 0x7000;
        self->state++;
    } else if (self->state == 3) {
        if (func_ov017_021959b4()) {
            _Z28SetFlagBit_02184a2c_02184a2cPc(self->scene);
        }
        if (func_ov008_02184754(self->scene)) {
            self->state++;
        }
    } else if (self->state == 4) {
        LockStagedTextureVRAMCopying();
        DisableSubBGVRAMBanks();
        DisableTextureImageVRAMBanks();
        MapVRAMBanksToSubBG(self->subBgBanks);
        MapVRAMBanksToTextureImage(self->textureBanks);
        _Z25ConfigurePairMode020bb48cji((unsigned short)(self->textureSize >> 17), 1);
        RestorePairTableFromBuffer(self->pairTable);
        UpdateVRAMStagingVRAMBanks();
        UnlockStagedTextureVRAMCopying();
        DISPCNT = (DISPCNT & ~0x1f00) | (self->visiblePlanes << 8);
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | (self->subVisiblePlanes << 8);
        ClearFlag0x10IfSet((Struct02074bd0*)self->controlBackup);
        ClearFlag0x11IfSet((Struct02074bf4*)self->controlBackup);
        Set3DClearColor(self->clearColor, 0x10, 0x7fff, 0, 0);
        func_ov008_021845ac(self->scene);
        char blank[0x20];
        memset(blank, 0, 0x20);
        CleanInvalidateCacheRange(blank, 0x20);
        LoadToMainBG1CharacterData(blank, 0, 0x20);
        ClearBitsInWord((unsigned int*)res, -1);
        ClearBitsInField4((unsigned int*)res, -1);
        ClearBitsInField8((unsigned int*)res, -1);
        SetBitsInWord((unsigned int*)res, self->word);
        SetBitsInField4((unsigned int*)res, self->field4);
        SetBitsInField8((unsigned int*)res, self->field8);
        _Z35ProcessCombatantsIfFlagged_0218f79cPv(res);
        SetField0x3b0Value(gs, self->fieldB8);
        GameState* state = GameState::GetInstance();
        int index = 0x70;
        for (int i = 0; i < 0x30; i++) {
            GameObject* monster = state->GetMaybeFieldMonsterByIndex(index);
            if (monster) {
                ((Object3D*)monster)->StageTextureData();
            }
            index++;
        }
        func_ov017_0219b624(res);
        char* fields = res->unknown_2cc;
        void* controller = (void*)_Z26GetGlobalField0x1c020421a0v();
        _Z26CopyInternalFields0207df50P11Foo0207df50(fields + 0x5b0);
        _Z25RestorePairTables0207df90Pc(fields + 0x5b0);
        func_020432c4(controller);
        _Z24BackupPairTables0207dfacPc(fields + 0x5b0);
        if (self->scene->kind == 0) {
            func_ov017_0219bd1c(1, 0, 0, 0);
        }
        self->state++;
    } else if (self->state == 5) {
        self->b3c = 0;
        self->b3d = 0;
        func_02074af4(self->controlBackup);
        BackupSubBgControlRegisters((SubBgControlBackup02074b64*)self->controlBackup);
        self->b25 = self->scene->b29;
        self->b26 = (self->scene->flags & 0x40000) != 0;
        self->x = self->scene->x;
        self->y = self->scene->y;
        GameResources* res2 = func_ov017_0218b5b0();
        HeadList020469f8* list = (HeadList020469f8*)res2->unknown_ptr_array_36fc[0];
        HeadNode020469f8* node;
        switch (self->scene->kind) {
        case 1:
            _Z36InitAllocatorAndClearFields_021c0820P11Obj021c0820(self);
            self->b24 = 0;
            node = (HeadNode020469f8*)res2->unknown_ptr_array_3afc[15];
            _Z20InitState40_021c0334P11Obj021c0334(node);
            PrependNodeToHead(list, node);
            return;
        case 2:
            func_ov017_021c0580(self, 1, data_ov017_021d7f00, (void*)_Z30AllocateAndDispatch20_0215502cP13SafeAllocatori);
            return;
        case 3:
            func_ov017_021c0580(self, 2, data_ov017_021d7f07, (void*)_Z30AllocateAndDispatch14_021560b0P13SafeAllocatori);
            return;
        case 4:
            _Z36InitAllocatorAndClearFields_021c0820P11Obj021c0820(self);
            self->b24 = 3;
            node = (HeadNode020469f8*)res2->unknown_ptr_array_3afc[18];
            _Z20InitState37_021b14a0P11Obj021b14a0(node);
            _Z23SetByteField49_021b1d3cPvi(node, 1);
            PrependNodeToHead(list, node);
            return;
        case 5:
            func_ov017_021c0580(self, 4, data_ov017_021d7f12, (void*)_Z29AllocateAndDispatch8_02156dc8P13SafeAllocatori);
            return;
        case 6:
            func_ov017_021c0580(self, 5, data_ov017_021d7f19, (void*)_Z36AllocateAndCopyHandlerTable_021677b4P13SafeAllocatorPv);
            return;
        case 7:
            func_ov017_021c0580(self, 6, data_ov017_021d7f22, (void*)_Z29AllocateAndCopyBuf76_0216aa70P13SafeAllocatorPv);
            return;
        case 0: {
            SetMainBrightness(res, 0, 0xf);
            _Z27SetStateAndDispatch0209c3b4P13Actor0209c3b4i(&data_02109bf4, func_0209cd50(*(unsigned short*)func_02012fe4()));
            char* global = (char*)_Z26GetGlobalField0x1c020421a0v();
            *(int*)(global + kGlobalStateOffset) = 0;
            *(unsigned char*)(global + kGlobalFlagOffset) = 1;
            break;
        }
        }
        self->state++;
    } else {
        if (IsBrightnessTransitionActive(res)) {
            return;
        }
        if (self->scene->kind == 0) {
            SetByteField0x253(leader);
        } else {
            _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)leader, 1);
        }
        func_ov017_021c07d0(self);
        func_020a0c0c();
        self->done = 1;
    }
}
