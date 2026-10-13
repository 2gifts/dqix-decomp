#include <globaldefs.h>
#include "System/Graphics.h"

static inline unsigned long ReadDisplay(volatile unsigned int* p) { return *p; }
static inline void WriteDisplay(volatile unsigned int* p, unsigned int value) { *p = value; }

#if defined(jpn)
enum { kGlobalDisplayOffset = 0x608, kControllerBackupOffset = 0x1c4c, kSceneAllocatorSize = 0x48e10, kSceneSize = 0xd90, kSceneSlotOffset = 0xd4c };
#else
enum { kGlobalDisplayOffset = 0x508, kControllerBackupOffset = 0x1e28, kSceneAllocatorSize = 0x4b238, kSceneSize = 0xdb8, kSceneSlotOffset = 0xd88 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "System/OverlayId.h"

struct AllocatorUnion;
struct Foo0207df50;
struct S_02010124;
struct Obj0203bdb0;
struct GameResources;
struct Actor0209c3b4;
struct Actor0209c678;
struct Actor0209c20c;

void PushInputLogA(int value);
void PopStack0AndTrigger(int value);
extern "C" void func_020a1940(unsigned int id);
void SetWord0x0(int* obj, int value);
void EncodeSignFlaggedHalfword(short* reg, int value);
extern "C" void* func_0203bd08(void);
extern "C" void _Z25InitBattleContext0203bd24Pc(char* context);
int* GetGlobalPtr02105244();
extern "C" int func_0203be4c(void* context);
extern "C" void func_0203c35c(int* ptr);
extern "C" void MapVRAMBanksToLCDC(unsigned short mask);
extern "C" void func_020ca458(unsigned int value, void* dest, int count);
extern "C" int DisableLCDCMappedVRAMBanks(void);
void Finish3DRendering();
extern "C" void func_020c51dc();
extern "C" void _Z25ResetMatrixStacks020c537cv();
void LockStagedTextureVRAMCopying();
void UnlockStagedTextureVRAMCopying();
void UpdateVRAMStagingVRAMBanks();
extern "C" void MapVRAMBanksToTextureImage(int handle);
extern "C" void _Z25ConfigurePairMode020bb48cji(unsigned int a, int b);
extern "C" void MapVRAMBanksToTexturePalette(int value);
extern "C" void _Z41InitGlobalStateAndInstallHandlers020bb780Pvi(void* stack, int flag);
extern "C" void MapVRAMBanksToMainBG(int v);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void MapVRAMBanksToMainObj(int mode);
extern "C" void MapVRAMBanksToSubObj(int value);
extern "C" void _Z30SetDispcntModeAndFlags020c391ciii(int mode, int a, int b);
void SetSubBgMode(unsigned int mode);
void Set3DClearColor(int a, int b, int c, int d, int e);
void CallWithAddr4000330(int table);
extern "C" void func_0207de48(void* p, int a, int b);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02042c68(void* controller);
extern "C" void func_02043124(void* obj);
extern "C" void _Z19TailForward020440a4Pv(void* controller);
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(Foo0207df50* obj);
extern "C" void _Z25RestorePairTables0207df90Pc(char* obj);
extern "C" void func_020432c4(void* controller);
extern "C" void _Z24BackupPairTables0207dfacPc(char* obj);
void SetField0x3acValue(GameState* gs, int value);
int GetField0x3acValue(GameState* gs);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_ov009_0218454c(void* scene, int a, int b);
extern "C" void* _Z28FindSlotWithNegShort02010954Pc(char* gs);
extern "C" void func_ov009_021842a0(void* scene, SafeAllocator* allocator);
extern "C" void _Z27SetStateAndDispatch0209c3b4P13Actor0209c3b4i(Actor0209c3b4* actor, int state);
void DelayThenSyncBit0();
void RestoreDisplayMode();
extern "C" void _Z18InitFields02010124P10S_02010124(S_02010124* obj);
int GetByte0x4(char* gs);
extern "C" void _Z28InitCombatSubsystems02012efcv();
extern "C" void func_ov021_0218bb30(void* self);
extern "C" void _Z23ProcessRingJobs020bbcb4v();
extern "C" void func_ov009_02184ca4(void* scene);
extern "C" void _Z22SyncMainSubOam0203bdb0P11Obj0203bdb0(Obj0203bdb0* obj);
void UpdateAndApplyBrightness(GameResources* resources);
extern "C" void func_ov009_02184848(void* scene);
extern "C" void _Z30DispatchContextByState0209c678P13Actor0209c678i(Actor0209c678* actor, int state);
extern "C" void _Z22ScaleAndNotify0203ad88PvS_i(void* a, void* b, int c);
extern "C" void _Z20ResetXYField0203aa08Pv(void* obj);
extern "C" void _Z24InitActorContext0209c20cP13Actor0209c20c(Actor0209c20c* actor);
void InitControllerObject(char* controller);
extern char data_02114e20;
extern char data_02109bf4;
extern int data_02114e50;

struct EdgeColors0218b5fc {
    unsigned short colors[8];
};

extern EdgeColors0218b5fc data_ov021_0218bbc4;

struct Battle0218b5fc {
    char pad0[0x28];
    unsigned char running;
    char pad1[0x2c - 0x29];
    SafeAllocator allocator;
    void* scene;
    char state44[0xb4 - 0x44];
    char* slot;
    int quit;
};

struct Obj0218baf8;
extern "C" void _Z29ReleaseLocksAndReset_0218baf8P11Obj0218baf8(Obj0218baf8* obj);

// USA: func_ov021_0218b5fc
extern "C" ARM void func_ov021_0218b5fc(Battle0218b5fc* self) {
#if !defined(jpn)
    PushInputLogA(3);
#endif
    func_020a1940(OVERLAY_ID(9));
    func_020a1940(OVERLAY_ID(23));
    GameState* gs = GameState::GetInstance();
    SetWord0x0((int*)gs, (int)self);
    EncodeSignFlaggedHalfword((short*)0x400006c, -16);
    EncodeSignFlaggedHalfword((short*)0x400106c, -16);
    BackgroundLoader::GetInstance()->MaybeReset();
    void* context = func_0203bd08();
    _Z25InitBattleContext0203bd24Pc((char*)context);
    *(int*)context = 0;
    int* global = GetGlobalPtr02105244();
    *global = func_0203be4c(context) + 0x200;
    func_0203c35c(global);
    global[kGlobalDisplayOffset / 4] = 0x7000;
    MapVRAMBanksToLCDC(0x1ff);
    func_020ca458(0, (void*)0x6800000, 0xa4000);
    DisableLCDCMappedVRAMBanks();
    Finish3DRendering();
    func_020c51dc();
    _Z25ResetMatrixStacks020c537cv();
    LockStagedTextureVRAMCopying();
    MapVRAMBanksToTextureImage(1);
    _Z25ConfigurePairMode020bb48cji(1, 1);
    MapVRAMBanksToTexturePalette(0x40);
    _Z41InitGlobalStateAndInstallHandlers020bb780Pvi((void*)0x4000, 1);
    MapVRAMBanksToMainBG(0x10);
    MapVRAMBanksToSubBG(4);
    MapVRAMBanksToMainObj(0x20);
    unsigned int display = ReadDisplay(&DISPCNT);
#if defined(jpn)
    display = (display & 0xffcfffef) | 0x10;
#else
    display &= 0xffcfffef;
    display |= 0x10;
#endif
    WriteDisplay(&DISPCNT, display);
    MapVRAMBanksToSubObj(8);
    DISPCNTSUB = (DISPCNTSUB & 0xffcfffef) | 0x10;
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
    display = ReadDisplay(&DISPCNT);
    display = (display & ~0x1f00) | 0x1f00;
    WriteDisplay(&DISPCNT, display);
    _Z30SetDispcntModeAndFlags020c391ciii(1, 0, 1);

    BG1CNT = (BG1CNT & 0x43) | 0x1d00;
    BG2CNT = (BG2CNT & 0x43) | 0x1e08;
    BG3CNT = (BG3CNT & 0x43) | 0x1f0c;
    BG0CNT = (BG0CNT & ~3) | 2;
    BG1CNT = (BG1CNT & ~3) | 3;
    BG2CNT = (BG2CNT & ~3) | 1;
    BG3CNT = BG3CNT & ~3;
    DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1700;
    SetSubBgMode(0);

    BG0CNTSUB = (BG0CNTSUB & 0x43) | 0x1d00;
    BG1CNTSUB = (BG1CNTSUB & 0x43) | 0x1e10;
    BG2CNTSUB = (BG2CNTSUB & 0x43) | 0x1f18;
    BG0CNTSUB = (BG0CNTSUB & ~3) | 2;
    BG1CNTSUB = (BG1CNTSUB & ~3) | 1;
    BG2CNTSUB = BG2CNTSUB & ~3;
    BG3CNTSUB = (BG3CNTSUB & ~3) | 3;
    *(unsigned short*)0x4000304 |= 0x8000;
    Set3DClearColor(0, 0, 0x7fff, 0, 0);

    EdgeColors0218b5fc edges = data_ov021_0218bbc4;
    CallWithAddr4000330((int)&edges);
    func_0207de48(self->state44, 0x4000, 0x40);
    void* controller = _Z26GetGlobalField0x1c020421a0v();
    func_02042c68(controller);
    func_02043124(controller);
    _Z19TailForward020440a4Pv(controller);
    *(char**)((char*)controller + kControllerBackupOffset) = self->state44;
    _Z26CopyInternalFields0207df50P11Foo0207df50((Foo0207df50*)self->state44);
    _Z25RestorePairTables0207df90Pc(self->state44);
    func_020432c4(controller);
    _Z24BackupPairTables0207dfacPc(self->state44);
    SetField0x3acValue(gs, 0);
    self->allocator.CreateTypeA(AllocateAligned4((AllocatorUnion*)&data_02114e20, kSceneAllocatorSize), kSceneAllocatorSize);
    self->allocator.Reset();
    self->scene = self->allocator.Allocate(kSceneSize);
    func_ov009_0218454c(self->scene, 0, 0);
    self->slot = (char*)_Z28FindSlotWithNegShort02010954Pc((char*)gs);
    *(short*)(self->slot + 0x568) = GetField0x3acValue(gs);
    *(char**)((char*)self->scene + kSceneSlotOffset) = self->slot;
    func_ov009_021842a0(self->scene, &self->allocator);
    _Z27SetStateAndDispatch0209c3b4P13Actor0209c3b4i((Actor0209c3b4*)&data_02109bf4, 2);
    DelayThenSyncBit0();
    RestoreDisplayMode();
    DISPCNTSUB |= 0x10000;
    _Z18InitFields02010124P10S_02010124((S_02010124*)gs);

    for (;;) {
        if (GetByte0x4((char*)gs) == 0 || self->quit != 0) {
            break;
        }
        _Z28InitCombatSubsystems02012efcv();
        _Z29ReleaseLocksAndReset_0218baf8P11Obj0218baf8((Obj0218baf8*)self);
        func_ov021_0218bb30(self);
        self->running = 1;
        DelayThenSyncBit0();
        _Z23ProcessRingJobs020bbcb4v();
        func_ov009_02184ca4(self->scene);
        _Z22SyncMainSubOam0203bdb0P11Obj0203bdb0((Obj0203bdb0*)func_0203bd08());
        UpdateAndApplyBrightness((GameResources*)self);
        data_02114e50++;
        gs->CalculateDeltaTime(0x411b);
    }

    func_ov009_02184848(self->scene);
    _Z30DispatchContextByState0209c678P13Actor0209c678i((Actor0209c678*)&data_02109bf4, 0);
    _Z22ScaleAndNotify0203ad88PvS_i(&data_02109bf4, 0, 0);
    _Z20ResetXYField0203aa08Pv(&data_02109bf4);
    _Z24InitActorContext0209c20cP13Actor0209c20c((Actor0209c20c*)&data_02109bf4);
    InitControllerObject((char*)controller);
    _Z26CopyInternalFields0207df50P11Foo0207df50((Foo0207df50*)self->state44);
    SetWord0x0((int*)gs, 0);
#if !defined(jpn)
    PopStack0AndTrigger(1);
#endif
}
