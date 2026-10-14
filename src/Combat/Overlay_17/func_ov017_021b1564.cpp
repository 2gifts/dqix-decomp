#include <globaldefs.h>
#include <GameState/GameState.h>
#include <World/Zone3D.h>
#include <System/Cache.h>
#include <std_library_functions.h>

struct Actor0209c678;
struct Actor0209c3b4;
struct Obj020397cc;
struct Obj020979c0;
struct SubBgControlBackup02074b64;
struct Struct02074bd0;
struct Struct02074bf4;
struct Foo0207df50;
struct TailList020469b4;
struct TailNode020469b4;
struct Transition021b1564 {
    unsigned char kind, inactive;
    char pad_2[6];
    SafeAllocator allocator;
    Obj020979c0* plugin;
    char displayBackup[0x10];
    unsigned char mainFlag, subFlag;
    char pad_32[2];
    unsigned int mainDisplay, subDisplay;
    unsigned int savedFlags, savedFlags4, savedFlags8;
    unsigned char stage, alternate, result;
};
struct Controller021b1564 {
#if defined(jpn)
    char pad_0[0x28];
#else
    char pad_0[0x5c];
#endif
    signed char* action;
#if defined(jpn)
    char pad_60[0x868 - 0x2c];
#else
    char pad_60[0x998 - 0x60];
#endif
    int busy;
};
struct Overlay006021b1564 { char pad_0[0x394]; unsigned short flags; char pad_396[0x9e]; unsigned char result; };
struct BufferTail021b1564 { char pad_0[0x1000]; char work[1]; };
struct Buffer021b1564 { char pad_0[0x820]; BufferTail021b1564 tail; };
struct PlayerView021b1564 { char pad_0[0xae]; short angle; };
struct ResourceBlock021b1564 { char initial[0x5b0]; char restored[1]; };
struct EntryNode021b1564 { char pad_0[0x114]; void* entry; char pad_118[0xc]; int id; char pad_128[0x11]; unsigned char active; };
GameResources* GetWord0x0_0200fb8c(int*);
unsigned int* GetDataPtr02114e04_020d6c00();
Controller021b1564* GetGlobalField0x1c020421a0();
unsigned char* GetFieldIfFlag4_020100f8(char*);
void ClearIntAt0x23c_020a27b8(unsigned char*);
unsigned int GetWord_0203b498(unsigned int*);
unsigned int GetField4_0203b4d0(unsigned int*);
unsigned int GetField8_0203b508(unsigned int*);
void SetBitsInField4_0203b4d8(unsigned int*, unsigned int);
void CancelPendingAction020397cc(Obj020397cc*, int);
#if defined(jpn)
extern "C" void func_0204500c(void*, signed char*, int);
#define func_ov006_021576a0 func_ov006_02158ca8
enum { TransitionArenaSize = 0x3b000, TransitionAllocationSize = 0x3c820 };
#else
extern "C" void func_0204500c(void*, signed char*, int, int);
enum { TransitionArenaSize = 0x3cc00, TransitionAllocationSize = 0x3e420 };
#endif
void ReinitController02043204(char*);
extern "C" int func_020457e0(void*);
void SetField0x23cTrue_020a27ac(void*);
void SetBrightness(GameResources*, int, int);
void DispatchContextByState0209c678(Actor0209c678*, int);
void OrBitsIntoField0_020466e4(unsigned int*, unsigned int);
int IsBrightnessTransitionActive(GameResources*);
void OrGlobalFlag0x40_020dc2bc();
extern "C" void func_020a0cc4(unsigned int);
void* AllocateAligned4_02012d88(AllocatorUnion*, unsigned int);
extern "C" void func_020a0c0c();
extern "C" void func_02043124(void*);
void PushInputLogA_020a1df8(int);
void PushInputLogB_020a1ef0(int);
void SetPowCnt1Bit15_021b1ca8(int);
void InitStruct020979c0(Obj020979c0*, unsigned char);
extern "C" void func_ov006_02157a60(Overlay006021b1564*);
extern "C" void func_ov006_021576a0(Overlay006021b1564*, SafeAllocator*, void*);
extern "C" int func_02097a04(Obj020979c0*);
extern "C" void func_02074af4(void*);
void BackupSubBgControlRegisters(SubBgControlBackup02074b64*);
void* GetGlobalPtr021075f4_0203cf4c();
extern "C" Zone3D* func_02012fe4();
extern "C" void func_0203e0a0(void*, unsigned short);
void ResetOverlayAndAllocator_0219bf74();
int IsIdInRange020981e4(int, int);
extern "C" void func_ov017_021a316c(GameResources*);
void SetField0x98Bit0_0203d008(unsigned char*);
void SetBitsInWord_0203b4a0(unsigned int*, unsigned int);
extern "C" int func_ov006_02157d7c(Overlay006021b1564*, unsigned int);
extern "C" void func_ov006_02157cc0(Overlay006021b1564*);
extern "C" void func_02097b34(Obj020979c0*);
extern "C" void func_ov017_021b14ec(Transition021b1564*);
void SetStateAndDispatch0209c3b4(Actor0209c3b4*, int);
void ClearFlag0x10IfSet(Struct02074bd0*);
void ClearFlag0x11IfSet(Struct02074bf4*);
extern "C" void LoadToMainBG1CharacterData(void*, int, unsigned int);
extern "C" void LoadToMainBG2CharacterData(void*, int, unsigned int);
extern "C" void LoadToMainBG1ScreenData(void*, int, unsigned int);
extern "C" void LoadToMainBG2ScreenData(void*, int, unsigned int);
void TailForward02012da4(AllocatorUnion*, void*);
void ClearBitsInWord_0203b4b0(unsigned int*, unsigned int);
void ClearBitsInField4_0203b4e8(unsigned int*, unsigned int);
void ClearBitsInField8_0203b520(unsigned int*, unsigned int);
void SetBitsInField8_0203b510(unsigned int*, unsigned int);
void ProcessCombatantsIfFlagged_0218f79c(void*);
void SetAndLockMainBrightness(GameResources*, int, int);
extern "C" void func_ov017_021921fc(Vector3i*, short, int);
extern "C" void func_ov017_0219bd1c(int, int, int, int);
extern "C" void func_ov017_021a2fa0(GameResources*);
extern "C" void func_ov017_0219b624(GameResources*);
extern "C" void func_ov017_0219ba0c(GameResources*, int);
void CopyInternalFields0207df50(Foo0207df50*);
void RestorePairTables0207df90(char*);
extern "C" void func_020432c4(void*);
void BackupPairTables0207dfac(char*);
void UnlockAndSetMainBrightness(GameResources*, int, int);
int* FindEntryPointerByKey0203df78(void*, int);
void* GetField0x8_02040528(int*);
extern "C" void func_ov017_021b8d1c(EntryNode021b1564*);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
void SetByteField0x253_020397c0(void*);
extern char data_02109bf4[];
extern AllocatorUnion data_02114e20;
extern Overlay006021b1564* data_ov017_021d83ec;
#define REG_MAIN_DISPLAY (*(volatile unsigned int*)0x04000000)
#define REG_SUB_DISPLAY (*(volatile unsigned int*)0x04001000)

static inline int CurrentZone021b1564(Zone3D* zone) { SDK_NULL_ASSERT(zone); return zone->currentZoneID_; }

// USA: func_ov017_021b1564
extern "C" ARM void func_ov017_021b1564(Transition021b1564* self, TailList020469b4* list) {
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetWord0x0_0200fb8c((int*)game);
    unsigned int* global = GetDataPtr02114e04_020d6c00();
    Controller021b1564* controller = GetGlobalField0x1c020421a0();
    unsigned char* field = GetFieldIfFlag4_020100f8((char*)game);
    GameObject* player = game->GetUnknownGameObject();
    if (field) ClearIntAt0x23c_020a27b8(field);
    if (self->stage == 0) {
        self->savedFlags = GetWord_0203b498((unsigned int*)resources);
        self->savedFlags4 = GetField4_0203b4d0((unsigned int*)resources);
        self->savedFlags8 = GetField8_0203b508((unsigned int*)resources);
        SetBitsInField4_0203b4d8((unsigned int*)resources, 0x40);
        if (!self->alternate) {
            GameObject* current = game->GetUnknownGameObject();
            if (current) CancelPendingAction020397cc((Obj020397cc*)current, 1);
            if (*controller->action) {
#if defined(jpn)
                func_0204500c(controller, controller->action, 0);
#else
                func_0204500c(controller, controller->action, 0, 0xe3);
#endif
                controller->busy = 1;
            } else ReinitController02043204((char*)controller);
            self->stage = 100;
            return;
        }
        ++self->stage;
        return;
    } else if (self->stage == 100) {
        if (controller->busy) return;
        if (func_020457e0(controller) == 1) {
            ReinitController02043204((char*)controller);
            self->inactive = 1;
            if (field) SetField0x23cTrue_020a27ac(field);
            return;
        }
        ReinitController02043204((char*)controller);
        SetBrightness(resources, -16, 16);
        DispatchContextByState0209c678((Actor0209c678*)data_02109bf4, 15);
        OrBitsIntoField0_020466e4(global, 1);
        self->stage = 1;
        return;
    } else if (self->stage == 1) {
        if (IsBrightnessTransitionActive(resources)) return;
        OrGlobalFlag0x40_020dc2bc();
        ++self->stage;
        return;
    } else if (self->stage == 2) {
        func_020a0cc4(TransitionAllocationSize);
        Buffer021b1564* buffer = (Buffer021b1564*)AllocateAligned4_02012d88(&data_02114e20, TransitionAllocationSize);
        if (!buffer) {
            func_020a0c0c();
            self->inactive = 1;
            if (field) SetField0x23cTrue_020a27ac(field);
            return;
        }
        BufferTail021b1564* tail = &buffer->tail;
        Controller021b1564* current = GetGlobalField0x1c020421a0();
        ReinitController02043204((char*)current);
        func_02043124(current);
        self->allocator.CreateTypeA(buffer, TransitionArenaSize);
        self->allocator.Reset();
        self->plugin = (Obj020979c0*)self->allocator.Allocate(0x20);
        data_ov017_021d83ec = (Overlay006021b1564*)self->allocator.Allocate(0x438);
        if (!self->plugin || !data_ov017_021d83ec) {
            func_020a0c0c();
            self->inactive = 1;
            if (field) SetField0x23cTrue_020a27ac(field);
            return;
        }
        PushInputLogA_020a1df8(6);
        PushInputLogB_020a1ef0(1);
        SetPowCnt1Bit15_021b1ca8(1);
        InitStruct020979c0(self->plugin, 2);
        func_ov006_02157a60(data_ov017_021d83ec);
        if (self->alternate) data_ov017_021d83ec->flags |= 2;
        func_ov006_021576a0(data_ov017_021d83ec, &self->allocator, tail->work);
        ++self->stage;
        return;
    } else if (self->stage == 3) {
        if (!func_02097a04(self->plugin)) return;
        ++self->stage;
        self->mainFlag = 0;
        self->subFlag = 0;
        func_02074af4(self->displayBackup);
        self->mainDisplay = (REG_MAIN_DISPLAY & 0x1f00) >> 8;
        BackupSubBgControlRegisters((SubBgControlBackup02074b64*)self->displayBackup);
        self->subDisplay = (REG_SUB_DISPLAY & 0x1f00) >> 8;
        SetBitsInField4_0203b4d8((unsigned int*)resources, 0x8de);
        void* entries = GetGlobalPtr021075f4_0203cf4c();
        Zone3D* zone = func_02012fe4();
        func_0203e0a0(entries, zone->currentZoneID_);
        ResetOverlayAndAllocator_0219bf74();
        if (IsIdInRange020981e4((int)zone->unk_840, CurrentZone021b1564(zone))) {
            func_ov017_021a316c(resources);
            resources->allocator_array_38[7].Reset();
        }
        SetField0x98Bit0_0203d008((unsigned char*)entries);
        SetBitsInWord_0203b4a0((unsigned int*)resources, 16);
        return;
    } else if (self->stage == 4) {
        SetField0x98Bit0_0203d008((unsigned char*)GetGlobalPtr021075f4_0203cf4c());
        unsigned int ticks = GameState::GetInstance()->GetTickCount();
        if (!func_ov006_02157d7c(data_ov017_021d83ec, ticks)) return;
        self->result = data_ov017_021d83ec->result;
        ++self->stage;
        return;
    } else if (self->stage == 5) {
        if (self->alternate) {
            func_ov006_02157cc0(data_ov017_021d83ec);
            func_02097b34(self->plugin);
            func_ov017_021b14ec(self);
            func_020a0c0c();
            self->inactive = 1;
            if (field) SetField0x23cTrue_020a27ac(field);
            return;
        }
        SetStateAndDispatch0209c3b4((Actor0209c3b4*)data_02109bf4, 7);
        func_ov006_02157cc0(data_ov017_021d83ec);
        data_ov017_021d83ec = 0;
        SetPowCnt1Bit15_021b1ca8(0);
        func_02097b34(self->plugin);
        ClearFlag0x10IfSet((Struct02074bd0*)self->displayBackup);
        REG_MAIN_DISPLAY = (REG_MAIN_DISPLAY & ~0x1f00) | (self->mainDisplay << 8);
        ClearFlag0x11IfSet((Struct02074bf4*)self->displayBackup);
        REG_SUB_DISPLAY = (REG_SUB_DISPLAY & ~0x1f00) | (self->subDisplay << 8);
        void* empty = AllocateAligned4_02012d88(&data_02114e20, 0x800);
        if (empty) {
            memset(empty, 0, 0x800);
            CleanInvalidateCacheRange(empty, 0x20);
            LoadToMainBG1CharacterData(empty, 0, 0x20);
            LoadToMainBG2CharacterData(empty, 0, 0x20);
            CleanInvalidateCacheRange(empty, 0x800);
            LoadToMainBG1ScreenData(empty, 0, 0x800);
            LoadToMainBG2ScreenData(empty, 0, 0x800);
            TailForward02012da4(&data_02114e20, empty);
        }
        ClearBitsInWord_0203b4b0((unsigned int*)resources, ~0u);
        ClearBitsInField4_0203b4e8((unsigned int*)resources, ~0u);
        ClearBitsInField8_0203b520((unsigned int*)resources, ~0u);
        SetBitsInWord_0203b4a0((unsigned int*)resources, self->savedFlags);
        SetBitsInField4_0203b4d8((unsigned int*)resources, self->savedFlags4);
        SetBitsInField8_0203b510((unsigned int*)resources, self->savedFlags8);
        ProcessCombatantsIfFlagged_0218f79c(resources);
        SetAndLockMainBrightness(resources, -16, 1);
        func_ov017_021921fc(&player->obj3D_.position_, ((PlayerView021b1564*)player)->angle, 1);
        func_ov017_0219bd1c(1, 0, 0, 0);
        func_ov017_021a2fa0(resources);
        func_ov017_0219b624(resources);
        func_ov017_0219ba0c(resources, 0);
        ResourceBlock021b1564* block = (ResourceBlock021b1564*)resources->unknown_2cc;
        Controller021b1564* current = GetGlobalField0x1c020421a0();
        CopyInternalFields0207df50((Foo0207df50*)block->restored);
        RestorePairTables0207df90(block->restored);
        func_020432c4(current);
        BackupPairTables0207dfac(block->restored);
        ++self->stage;
        return;
    } else if (self->stage == 6) {
        func_ov017_021b14ec(self);
        if (self->alternate) SetBrightness(resources, 0, 8);
        ++self->stage;
        return;
    } else if (self->stage == 7) {
        int finished = 0;
        if (self->alternate) {
            if (!IsBrightnessTransitionActive(resources)) finished = 1;
        } else {
            UnlockAndSetMainBrightness(resources, 0, 15);
            finished = 1;
            if (!self->result) {
                int* entry = FindEntryPointerByKey0203df78(GetGlobalPtr021075f4_0203cf4c(), 100);
                void* info;
                if (entry) info = GetField0x8_02040528(entry);
                EntryNode021b1564* node = (EntryNode021b1564*)resources->unknown_ptr_array_36fc[5];
                func_ov017_021b8d1c(node);
                node->entry = info;
                node->id = 0xc4;
                node->active = 1;
                AppendNodeToTail(list, (TailNode020469b4*)node);
            }
        }
        if (!finished) return;
        GameObject* current = game->GetUnknownGameObject();
        if (current) SetByteField0x253_020397c0(current);
        func_020a0c0c();
        self->inactive = 1;
    }
}
