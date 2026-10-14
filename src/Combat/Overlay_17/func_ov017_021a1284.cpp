#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <World/Zone3D.h>

struct Foo0207df50;
struct Obj020397cc;
struct Roster0203de2c;
struct NodeList02058564;
struct ArrayContainsByteStruct;
struct Obj021e31b0;
struct Plugin021a1284 {
    char pad_0[4];
    SafeAllocator* primaryAllocator;
    void* internal;
    SafeAllocator* secondaryAllocator;
    SafeAllocator* currentAllocator;
    SafeAllocator* eventAllocator;
    char pad_18[0x4cd];
    signed char mode;
    signed char result;
    char pad_4e7[0x15];
    int parameter;
    char pad_500[0x134];
    unsigned short flags;
};
struct TransferEvent021a1284 {
    char pad_0[1];
    unsigned char inactive;
    char pad_2[6];
    SafeAllocator allocator;
    Plugin021a1284* plugin;
    unsigned char mode;
    unsigned char parameter;
    unsigned char stage;
};
struct InternalResource021a1284 { char bytes[0x5b0]; };
struct ResourceTransfer021a1284 {
    char pad_0[0x2cc];
    InternalResource021a1284 initial;
    char restored[1];
    char pad_87d[0x2e83];
    void** pending;
};
struct ZoneTransfer021a1284 {
    char pad_0[0x424];
    int pending;
    char pad_428[0x418];
    char range[1];
};
struct PlayerTransfer021a1284 {
    char pad_0[0xb0];
    unsigned short field_b0;
    unsigned short field_b2;
    unsigned short field_b4;
    char pad_b6[0x9a];
    void* settings;
};
struct SettingsTransfer021a1284 { char pad_0[0x56b]; unsigned char unavailable : 4; unsigned char reserved : 4; };
struct EntryList_203dce4;
EntryList_203dce4* GetGlobalPtr021075f4_0203cf4c();
extern "C" Zone3D* func_02012fe4();
extern "C" NodeList02058564* func_02057924();
extern "C" int* func_0202ae18();
GameResources* GetWord0x0_0200fb8c(int*);
void* GetGlobalField0x1c020421a0();
void CancelPendingAction020397cc(Obj020397cc*, int);
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
int GetByteField0x254_02039850(void*);
int GetField0x3acValue_020100a8(GameState*);
void ComputeAndCall_021a1178(char*, int);
void SetBoolFlag0x254_0203983c(unsigned char*, int);
extern "C" void func_0204500c(void*, unsigned char*, int, int);
void ReinitController02043204(char*);
void SetField0x98Bit0_0203d008(unsigned char*);
extern "C" void func_0203e0a0(EntryList_203dce4*, unsigned short);
void SetBitsInWord_0203b4a0(unsigned int*, unsigned int);
extern "C" void func_020a0cc4(unsigned int);
void* AllocateAligned4_02012d88(AllocatorUnion*, unsigned int);
extern "C" void func_020a0c0c();
void ResetOverlayAndAllocator_0219bf74();
void CopyInternalFields0207df50(Foo0207df50*);
extern "C" void func_ov017_0219b938(GameResources*);
int IsIdInRange020981e4(int, int);
extern "C" void func_ov017_021a316c(GameResources*);
void PushInputLogA_020a1df8(int);
void PushInputLogB_020a1ef0(int);
extern "C" void func_ov023_021e2dd8(Plugin021a1284*);
extern "C" void __clear(void*, unsigned int);
int CopyOutRegion0x5718_02011494(char*, void*);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState*, int);
void CopyBytesToInts_021e31b0(Obj021e31b0*, unsigned char*, int);
extern "C" int func_ov017_021959b4();
void SetFlagt_021e338c_021e338c(char*);
extern "C" void func_ov023_021e3030(Plugin021a1284*);
extern "C" void func_ov017_021a18c8(TransferEvent021a1284*);
extern "C" void func_ov017_0219b624(GameResources*);
void ClearField0x98Bit0_0203d018(unsigned char*);
void ReleaseRosterEntries0203de2c(Roster0203de2c*);
void ProcessCombatantsIfFlagged_0218f79c(void*);
void ProcessSlotField58_021a2840(GameResources*);
void CleanupNodeList02058564(NodeList02058564*);
void SetField0x1e28_02042b30(void*, void*);
void RestorePairTables0207df90(char*);
extern "C" void func_020432c4(void*);
void BackupPairTables0207dfac(char*);
extern "C" int func_ov017_0218f5a4(GameResources*, int, int, int, int);
int CheckField0NonZero_0202b7d8(int*);
int ArrayContainsByte_02086ef0(ArrayContainsByteStruct*, int);
extern "C" void func_ov017_021c3fb4(int, int);
extern "C" void func_ov017_021c4418(int, int);
void ClearBitsInWord_0203b4b0(unsigned int*, unsigned int);
extern "C" void func_ov017_0219ba0c(GameResources*, int);
int IsField0Null_02046b08(void**);
void CallFuncForEachOfFour_020732a8();
extern "C" void func_ov017_0219bd1c(int, int, int, int);
void ClearBitsInField4_0203b4e8(unsigned int*, unsigned int);
void SetBitsInField4_0203b4d8(unsigned int*, unsigned int);
unsigned char* GetFieldIfFlag4_020100f8(char*);
void ClearFlagBits_020a28b0(unsigned char*, int);
void SetByteField0x253_020397c0(void*);
extern AllocatorUnion data_02114e20;

// USA: func_ov017_021a1284
extern "C" ARM void func_ov017_021a1284(TransferEvent021a1284* self, void* unused) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Zone3D* zone = func_02012fe4();
    EntryList_203dce4* entries = GetGlobalPtr021075f4_0203cf4c();
    NodeList02058564* nodes = func_02057924();
    int* search = func_0202ae18();
    GameObject* player = game->GetUnknownGameObject();
    GameResources* resources = GetWord0x0_0200fb8c((int*)game);
    void* global = GetGlobalField0x1c020421a0();
    CancelPendingAction020397cc((Obj020397cc*)player, 1);
    ((PlayerTransfer021a1284*)player)->field_b2 = 0;
    if (self->stage == 0) {
        SetBrightness(resources, -16, 15);
        self->stage = 1;
    } else if (self->stage == 1) {
        if (!IsBrightnessTransitionActive(resources)) self->stage = 2;
    } else if (self->stage == 2) {
        if (loader->GetNumQueuedTasks() > 0) return;
        if (GetByteField0x254_02039850(player)) {
            player->obj3D_.unknown_2_ = -1;
            ((PlayerTransfer021a1284*)player)->field_b0 = 0x324;
            ((PlayerTransfer021a1284*)player)->field_b4 = 0x189;
            player->obj3D_.SetHeight(0x1800);
            player->obj3D_.SetRadius(0x1000);
            ComputeAndCall_021a1178((char*)resources, GetField0x3acValue_020100a8(game));
            SetBoolFlag0x254_0203983c((unsigned char*)player, 0);
        }
        unsigned char flag = 0;
        func_0204500c(global, &flag, 0, 0xe3);
        ReinitController02043204((char*)global);
        SetField0x98Bit0_0203d008((unsigned char*)entries);
        func_0203e0a0(entries, zone->currentZoneID_);
        SetBitsInWord_0203b4a0((unsigned int*)resources, 0x10);
        func_020a0cc4(0x17600);
        void* buffer = AllocateAligned4_02012d88(&data_02114e20, 0x17600);
        if (!buffer) {
            func_020a0c0c();
            self->stage = 4;
            return;
        }
        self->allocator.CreateTypeA(buffer, 0x17600);
        self->allocator.Reset();
        ResetOverlayAndAllocator_0219bf74();
        SafeAllocator* current;
        SafeAllocator* primary = &resources->allocator_array_38[0];
        InternalResource021a1284* internal = &((ResourceTransfer021a1284*)resources)->initial;
        primary->Reset();
        CopyInternalFields0207df50((Foo0207df50*)internal);
        func_ov017_0219b938(resources);
        SafeAllocator* secondary = &resources->allocator_array_38[5];
        secondary->Reset();
        current = primary;
        if (((ZoneTransfer021a1284*)zone)->range && IsIdInRange020981e4((int)((ZoneTransfer021a1284*)zone)->range, zone->currentZoneID_)) {
            func_ov017_021a316c(resources);
            current = &resources->allocator_array_38[7];
            current->Reset();
        }
        PushInputLogA_020a1df8(5);
        PushInputLogB_020a1ef0(1);
        self->plugin = (Plugin021a1284*)current->Allocate(0x648);
        self->plugin->mode = self->mode;
        self->plugin->parameter = self->parameter;
        func_ov023_021e2dd8(self->plugin);
        self->plugin->primaryAllocator = primary;
        self->plugin->secondaryAllocator = secondary;
        self->plugin->currentAllocator = current;
        self->plugin->eventAllocator = &self->allocator;
        self->plugin->internal = internal;
        self->plugin->flags |= 0x2000;
        if (self->plugin->mode == 3) {
            unsigned char roster[4];
            __clear(roster, 4);
            unsigned char selected[4];
            unsigned char selectedCount = 0;
            for (int i = 0; i < 4; ++i) selected[i] = 0xff;
            int count = CopyOutRegion0x5718_02011494((char*)game, roster);
            for (int i = 0; i < count; ++i) {
                GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(game, roster[i]);
                if (!combatant) continue;
                SettingsTransfer021a1284* settings = (SettingsTransfer021a1284*)((PlayerTransfer021a1284*)combatant)->settings;
                int blocked;
                if (settings) blocked = settings->unavailable ? 1 : 0;
                else blocked = 0;
                if (!blocked) selected[selectedCount++] = roster[i];
            }
            CopyBytesToInts_021e31b0((Obj021e31b0*)self->plugin, selected, selectedCount);
        }
        self->stage = 3;
    } else if (self->stage == 3) {
        if (func_ov017_021959b4()) SetFlagt_021e338c_021e338c((char*)self->plugin);
        func_ov023_021e3030(self->plugin);
        if (self->plugin->result < 0) self->stage = 4;
    } else if (self->stage == 4) {
        func_ov017_021a18c8(self);
        func_ov017_021a316c(resources);
        resources->allocator_array_38[7].Reset();
        func_ov017_0219b624(resources);
        ClearField0x98Bit0_0203d018((unsigned char*)entries);
        ReleaseRosterEntries0203de2c((Roster0203de2c*)entries);
        ProcessCombatantsIfFlagged_0218f79c(resources);
        ProcessSlotField58_021a2840(resources);
        CleanupNodeList02058564(nodes);
        SetField0x1e28_02042b30(global, ((ResourceTransfer021a1284*)resources)->restored);
        CopyInternalFields0207df50((Foo0207df50*)((ResourceTransfer021a1284*)resources)->restored);
        RestorePairTables0207df90(((ResourceTransfer021a1284*)resources)->restored);
        func_020432c4(global);
        BackupPairTables0207dfac(((ResourceTransfer021a1284*)resources)->restored);
        ArrayContainsByteStruct* party = (ArrayContainsByteStruct*)GetPtrField0x2a04_02010828(game);
        for (int i = 0; i < 4; ++i) {
            if (func_ov017_0218f5a4(resources, i, 0, 0, 0) && CheckField0NonZero_0202b7d8(search) && ArrayContainsByte_02086ef0(party, i)) {
                func_ov017_021c3fb4(i, 1);
                func_ov017_021c4418(i, -1);
            }
        }
        ClearBitsInWord_0203b4b0((unsigned int*)resources, 0x10);
        func_ov017_0219ba0c(resources, 0);
        self->stage = 5;
    } else if (self->stage == 5) {
        if (!IsField0Null_02046b08(((ResourceTransfer021a1284*)resources)->pending)) return;
        CallFuncForEachOfFour_020732a8();
        func_ov017_0219bd1c(1, 0, 0, 0);
        if (zone->currentZoneID_ == 0x2710 || zone->currentZoneID_ == 0x2774) {
            ClearBitsInField4_0203b4e8((unsigned int*)resources, 0x601fe);
            SetBitsInField4_0203b4d8((unsigned int*)resources, 0x10004);
        } else ClearBitsInField4_0203b4e8((unsigned int*)resources, 0x601fe);
        self->stage = 6;
    } else if (self->stage == 6) {
        if (((ZoneTransfer021a1284*)func_02012fe4())->pending) return;
        ClearFlagBits_020a28b0(GetFieldIfFlag4_020100f8((char*)game), 3);
        self->stage = 7;
    } else if (self->stage == 7) {
        if (self->mode == 3) SetByteField0x253_020397c0(player);
        self->inactive = 1;
    }
}
