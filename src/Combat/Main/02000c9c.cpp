#include <globaldefs.h>
#include "System/OverlayId.h"
#include "System/Graphics.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"

struct Struct0200fb08;
struct StateBits5ccc_11570;
struct StateBits5ccc_1155c;
struct FieldBlock63d6_115a8;
struct FieldBlock63d6_115b4;
struct FieldBlock63d6_115c0;
struct Obj020128d8;
struct Actor0209c174;
struct Obj_0205e88c;
struct Manager020db0f0;

void* GetPtrField0x2a04(GameState* gs);
void SaveAndClearDisplayMode();
extern "C" void func_02012c34();
extern "C" void func_020a0c0c();
void InitOverlaySystem();
extern "C" void func_020a1940(unsigned int* id);
extern "C" int func_020a1bb4(unsigned int* id);
extern "C" unsigned int func_ov029_021d8e1c(void* start, void* end, int seed);
extern "C" unsigned int func_ov029_021d8f0c(void* start, void* end, int seed);
extern "C" unsigned int func_ov029_021d8ffc(void* start, void* end, int seed);
void PopulateOv33BackgroundLoader(void* buffer, unsigned int size, int count);
void InitStreamAndRegisterHandler0xC0();
Manager020db0f0* GetGlobalContext020daf90();
extern "C" void func_020dafd4();
void LoadObjLoadingGraphicsResources(Manager020db0f0* mgr);
void InitSubstructAndRegisterHandler0x14(void* mgr);
void ResetActor0209c174(Actor0209c174* actor);
void Dispatch0203a974With0x57000(void* actor);
void InitDisplayState0205e88c(Obj_0205e88c* obj);
void SetupContextForMode0205ea20(void* obj, int mode);
extern "C" void func_020421c4(SafeAllocator* alloc);
void InitHalfwords02071688();
char* GetVariantShortTable02109928();
void SetByte0x4(char* gs, unsigned char value);
char GetByte0x4(char* gs);
void SetWord0x7f6c(void* gs, int value);
int GetWord0x7f6c(void* gs);
void CheckAndApplyDebugCode020ac910();
int GetFlag0x5cccBit0(StateBits5ccc_11570* gs);
void ClearFlag0x5cccBit0(StateBits5ccc_1155c* gs);
void* AllocateFromAllocatorUnion(AllocatorUnion* alloc, unsigned int size);
extern "C" void _Z17EmptyStub02012de4v(AllocatorUnion* alloc);
void FreeIfFlag(AllocatorUnion* alloc, void* data, int size);
void InitBigManagerStruct0208660c(char* p);
void PrepareAndRunBufferedScript02099cb8(char* table);
int GetByteField0x63d6(FieldBlock63d6_115a8* gs);
void SetByteField0x63d6(FieldBlock63d6_115b4* gs, unsigned char value);
void ClearByte0x63d6(FieldBlock63d6_115c0* gs);
void GuardedOverlayDispatch020d6cb4();
void ResetObjectState0205e8d4(void* obj);
void FreeAndReinit0203a950(void* obj);
void SaveAndDisableBattlerState020128d8(Obj020128d8* obj);
void InitializeActiveAlarmList();
void SetDataFromIndex_02211c50(int index);
int NormalizeField5_0200fb08(Struct0200fb08* gs);
void ForwardToDataHandler_0222708c(int kind, int value);
int EnableIMEReturnPrev();
extern "C" void func_020c983c();
void ResetSystemAndBoot020c98f0(int mode);
extern "C" void func_02012938(void* obj);
void SetInterruptHandler(unsigned int mask, const void* handler);
void EnableSpecificInterrupts(unsigned int mask);
void EnableIRQInterrupts();
void SetVBlankIrqEnable(int enable);
extern "C" void MapVRAMBanksToMainBG(int banks);
void SetDispcntModeAndFlags020c391c(int mode, int a, int b);
void DelayThenSyncBit0();

extern "C" void func_ov019_0218b5a0(void* scene);
extern "C" void func_ov019_0218b5a8(void* scene);
extern "C" void func_ov019_0218b5a4(void* scene);
extern "C" void func_ov020_0218b5a0(void* scene);
extern "C" void func_ov020_0218b710(void* scene);
extern "C" void func_ov020_0218b700(void* scene);
extern "C" void func_ov016_0218b5a0(void* scene);
extern "C" void func_ov016_0218b5c4(void* scene);
extern "C" void func_ov016_0218b5c0(void* scene);
extern "C" void func_ov021_0218b5a0(void* scene);
extern "C" void func_ov021_0218b5fc(void* scene);
extern "C" void _Z38ResetAllocatorAndClearField40_0218b5c4P11Obj0218b5c4(void* scene);
extern "C" void func_ov015_02193294(void* scene);
extern "C" void func_ov015_021934f8(void* scene);
extern "C" void func_ov015_021933bc(void* scene);

int InvokeCallbackReturnStatus020d6bac(void (*callback)());
void NotifyOverlay0211e33c();
int InvokeCallbackReturnStatus020d6bc8(void (*callback)());
void GuardedNotifyOverlay0211e33c020d6c34();
int InvokeCallbackReturnStatus020d6be4(void (*callback)());
void GuardedNotifyOverlay0211e33c020d6c68();
void InitOverlay17ObjAndBumpBattleCounter02012bd8();

extern AllocatorUnion data_02114e20;
extern char data_0211e33c[];
extern char data_02109bf4[];
extern char data_02108760[];
extern char data_02114ec4[];
extern char data_02114e54[];

#if defined(jpn)
#define TITLE_SCENE_SIZE 0x2d0
#define WORLD_SCENE_SIZE 0x494
#define STARTUP_ALLOCATOR_SIZE 0xb000
#define SCENE_SKIP_MEMBER_INDEX (0x7c9e - 0x6d40)
#define MOVIE_RETURN_FLAG_OFFSET 0x6174
extern "C" int func_ov030_021d9b60(void* callback);
extern "C" int data_ov029_021d9d20_fake(void* callback);
extern "C" int data_ov029_021d9ee0_fake(void* callback);
extern "C" void func_020d8614();
extern "C" void func_020d863c();
extern "C" void func_020d8670();
#else
#define TITLE_SCENE_SIZE 0x2e0
#define WORLD_SCENE_SIZE 0x504
#define STARTUP_ALLOCATOR_SIZE 0x9478
#define SCENE_SKIP_MEMBER_INDEX (0x7f72 - 0x6fc0)
#define MOVIE_RETURN_FLAG_OFFSET 0x63d4
#endif

#define REG_IME (*(volatile unsigned short*)0x04000208)
#define REG_POWCNT1 (*(volatile unsigned short*)0x04000304)

#define RUNTITLE() \
    do { \
        func_020a1940(&OVERLAY_19_ID); \
        void* scene = AllocateFromAllocatorUnion(&data_02114e20, TITLE_SCENE_SIZE); \
        func_ov019_0218b5a0(scene); \
        _Z17EmptyStub02012de4v(&data_02114e20); \
        func_ov019_0218b5a8(scene); \
        func_ov019_0218b5a4(scene); \
        FreeIfFlag(&data_02114e20, scene, TITLE_SCENE_SIZE); \
        func_020a1bb4(&OVERLAY_19_ID); \
    } while (0)

#define RUNOV20() \
    do { \
        func_020a1940(&OVERLAY_20_ID); \
        void* scene = AllocateFromAllocatorUnion(&data_02114e20, WORLD_SCENE_SIZE); \
        func_ov020_0218b5a0(scene); \
        _Z17EmptyStub02012de4v(&data_02114e20); \
        func_ov020_0218b710(scene); \
        func_ov020_0218b700(scene); \
        FreeIfFlag(&data_02114e20, scene, WORLD_SCENE_SIZE); \
        func_020a1bb4(&OVERLAY_20_ID); \
    } while (0)

#define RUNOV16(again16) \
    do { \
        void* scene = AllocateFromAllocatorUnion(&data_02114e20, 0x98); \
        func_ov016_0218b5a0(scene); \
        _Z17EmptyStub02012de4v(&data_02114e20); \
        func_ov016_0218b5c4(scene); \
        again16 = *(int*)((char*)scene + 0x94); \
        func_ov016_0218b5c0(scene); \
        FreeIfFlag(&data_02114e20, scene, 0x98); \
    } while (0)

#define RUNOV21() \
    do { \
        func_020a1940(&OVERLAY_21_ID); \
        void* scene = AllocateFromAllocatorUnion(&data_02114e20, 0xbc); \
        func_ov021_0218b5a0(scene); \
        _Z17EmptyStub02012de4v(&data_02114e20); \
        func_ov021_0218b5fc(scene); \
        _Z38ResetAllocatorAndClearField40_0218b5c4P11Obj0218b5c4(scene); \
        FreeIfFlag(&data_02114e20, scene, 0xbc); \
        func_020a1bb4(&OVERLAY_21_ID); \
    } while (0)

#define RUNOV15() \
    do { \
        func_020a1940(&OVERLAY_15_ID); \
        void* scene = AllocateFromAllocatorUnion(&data_02114e20, 0x358); \
        func_ov015_02193294(scene); \
        _Z17EmptyStub02012de4v(&data_02114e20); \
        func_ov015_021934f8(scene); \
        func_ov015_021933bc(scene); \
        FreeIfFlag(&data_02114e20, scene, 0x358); \
        func_020a1bb4(&OVERLAY_15_ID); \
    } while (0)

#if !defined(jpn)
inline bool IsIntact1() {
    return func_ov029_021d8e1c((void*)InvokeCallbackReturnStatus020d6bac, (void*)NotifyOverlay0211e33c, 0) == 0xffe41136;
}

inline bool IsIntact2() {
    return func_ov029_021d8f0c((void*)InvokeCallbackReturnStatus020d6bc8, (void*)GuardedNotifyOverlay0211e33c020d6c34, 0) == 0xffe412c4;
}

inline bool IsIntact3() {
    return func_ov029_021d8ffc((void*)InvokeCallbackReturnStatus020d6be4, (void*)GuardedNotifyOverlay0211e33c020d6c68, 0) == 0xffe41b51;
}
#endif

inline void ResetWordUnlessTwo(GameState* gs) {
    SetByte0x4((char*)gs, 6);
    if (GetWord0x7f6c(gs) != 2) {
        SetWord0x7f6c(gs, 0);
    }
}

#define RUNOV17() \
    do { \
        func_020a1940(&OVERLAY_17_ID); \
        GuardedOverlayDispatch020d6cb4(); \
        func_020a1bb4(&OVERLAY_17_ID); \
    } while (0)

// USA: func_02000c9c
extern "C" ARM void main() {
    GameState* gs = GameState::GetInstance();
    char* bigManager = (char*)GetPtrField0x2a04(gs);
    SaveAndClearDisplayMode();
    DISPCNTSUB &= ~0x10000;
    func_02012c34();
    func_020a0c0c();
    InitOverlaySystem();
    func_020a1940(&OVERLAY_29_ID);
#if defined(jpn)
    if (!func_ov030_021d9b60((void*)func_020d8614) &&
        !data_ov029_021d9d20_fake((void*)func_020d863c) &&
        !data_ov029_021d9ee0_fake((void*)func_020d8670) &&
        BackgroundLoader::GetInstance() == 0) {
#else
    if (!IsIntact1() && !IsIntact2() && !IsIntact3() && BackgroundLoader::GetInstance() == 0) {
#endif
        func_020a1940(&OVERLAY_33_ID);
        PopulateOv33BackgroundLoader(data_0211e33c, 0x30000, 0x14);
    }
    func_020a1bb4(&OVERLAY_29_ID);
    func_020a1940(&OVERLAY_32_ID);
    InitStreamAndRegisterHandler0xC0();
    Manager020db0f0* ctx = GetGlobalContext020daf90();
    func_020dafd4();
    LoadObjLoadingGraphicsResources(ctx);
    InitSubstructAndRegisterHandler0x14(ctx);
    ResetActor0209c174((Actor0209c174*)data_02109bf4);
    Dispatch0203a974With0x57000(data_02109bf4);
    InitDisplayState0205e88c((Obj_0205e88c*)data_02108760);
    SetupContextForMode0205ea20(data_02108760, 100);
    SafeAllocator allocator;
    allocator.ResetAllocatorPointer();
    allocator.CreateTypeA(data_02114ec4, STARTUP_ALLOCATOR_SIZE);
    allocator.Reset();
    func_020421c4(&allocator);
    InitHalfwords02071688();
    char* table = GetVariantShortTable02109928();
    if (*(int*)0x027ffc20 != 0) {
        SetByte0x4((char*)gs, 6);
        SetWord0x7f6c(gs, 0);
    }
    CheckAndApplyDebugCode020ac910();

    for (;;) {
        if (GetFlag0x5cccBit0((StateBits5ccc_11570*)gs)) {
            ClearFlag0x5cccBit0((StateBits5ccc_1155c*)gs);
            RUNTITLE();
        }
        if (GetWord0x7f6c(gs) != 5) {
            InitBigManagerStruct0208660c(bigManager);
        }
        PrepareAndRunBufferedScript02099cb8(table);

        bool resumed = false;
        if (GetWord0x7f6c(gs) != 5) {
            ResetWordUnlessTwo(gs);
            ResetWordUnlessTwo(gs);
            if (GetByte0x4((char*)gs) != 6) {
                RUNOV20();
            } else if (GetByte0x4((char*)gs) == 6) {
                RUNOV20();
                if (*(unsigned char*)&gs->unk_6fc0[SCENE_SKIP_MEMBER_INDEX] == 0) {
                    SetByteField0x63d6((FieldBlock63d6_115b4*)gs, 1);
                    func_020a1940(&OVERLAY_16_ID);
                    int again16 = 1;
                    while (again16) {
                        RUNOV16(again16);
                    }
                    func_020a1bb4(&OVERLAY_16_ID);
                    ClearByte0x63d6((FieldBlock63d6_115c0*)gs);
                } else {
                    *(unsigned char*)&gs->unk_6fc0[SCENE_SKIP_MEMBER_INDEX] = 0;
                }
            }
            resumed = true;
        }

        switch (GetByte0x4((char*)gs)) {
        case 2:
            SetWord0x7f6c(gs, 0);
            break;
        case 0:
            if (resumed != true) {
                SetWord0x7f6c(gs, 0);
            }
            break;
        case 7:
            SetByte0x4((char*)gs, 0);
            break;
        case 5:
            if (GetWord0x7f6c(gs) != 6) {
                SetWord0x7f6c(gs, 0);
            }
            break;
        }

        bool again = true;
        while (again) {
            again = false;
            switch (GetByte0x4((char*)gs)) {
            case 0:
            case 4:
            case 5:
            case 9:
                RUNOV17();
                if (GetByteField0x63d6((FieldBlock63d6_115a8*)gs)) {
                    SetByte0x4((char*)gs, 3);
                    again = true;
                }
                break;
            case 2:
                RUNOV21();
                if (((unsigned char*)gs)[MOVIE_RETURN_FLAG_OFFSET] != 0) {
                    RUNOV17();
                    if (GetByteField0x63d6((FieldBlock63d6_115a8*)gs)) {
                        SetByte0x4((char*)gs, 3);
                        again = true;
                    }
                }
                break;
            case 1:
                RUNOV15();
                break;
            case 3:
                func_020a1940(&OVERLAY_16_ID);
                int more = 1;
                while (more) {
                    RUNOV16(more);
                }
                func_020a1bb4(&OVERLAY_16_ID);
                if (GetByteField0x63d6((FieldBlock63d6_115a8*)gs)) {
                    SetByte0x4((char*)gs, 0);
                    again = true;
                }
                break;
            case 8:
                ResetObjectState0205e8d4(data_02108760);
                FreeAndReinit0203a950(data_02109bf4);
                SaveAndDisableBattlerState020128d8((Obj020128d8*)data_02114e54);
                func_020a1940(&OVERLAY_27_ID);
                func_020a1940(&OVERLAY_31_ID);
                REG_IME;
                REG_IME = 0;
                InitializeActiveAlarmList();
                SetDataFromIndex_02211c50(2);
#if defined(jpn)
                ForwardToDataHandler_0222708c(0, 0x10);
#else
                switch (NormalizeField5_0200fb08((Struct0200fb08*)gs)) {
                case 1:
                    ForwardToDataHandler_0222708c(1, 0);
                    break;
                case 2:
                    ForwardToDataHandler_0222708c(2, 0);
                    break;
                case 3:
                    ForwardToDataHandler_0222708c(3, 0);
                    break;
                case 4:
                    ForwardToDataHandler_0222708c(4, 0);
                    break;
                case 5:
                    ForwardToDataHandler_0222708c(5, 0);
                    break;
                default:
                    ForwardToDataHandler_0222708c(1, 0);
                    break;
                }
#endif
                EnableIMEReturnPrev();
                func_020c983c();
                ResetSystemAndBoot020c98f0(1);
                func_020a1940(&OVERLAY_32_ID);
                func_02012938(data_02114e54);
                ResetActor0209c174((Actor0209c174*)data_02109bf4);
                Dispatch0203a974With0x57000(data_02109bf4);
                SetInterruptHandler(1, (const void*)InitOverlay17ObjAndBumpBattleCounter02012bd8);
                EnableSpecificInterrupts(1);
                EnableIMEReturnPrev();
                EnableIRQInterrupts();
                SetVBlankIrqEnable(1);
                MapVRAMBanksToMainBG(0x60);
                SetDispcntModeAndFlags020c391c(1, 0, 0);
                DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
                BG0CNT = (BG0CNT & 0x43) | 4;
                BG0CNT &= ~3;
                BG0CNT &= ~0x40;
                REG_POWCNT1 &= ~0x8000;
                DelayThenSyncBit0();
                SetByte0x4((char*)gs, 6);
                SetWord0x7f6c(gs, 1);
                again = false;
                break;
            }
        }
        if (GetFlag0x5cccBit0((StateBits5ccc_11570*)gs)) {
            ClearFlag0x5cccBit0((StateBits5ccc_1155c*)gs);
            RUNTITLE();
        }
    }
}
