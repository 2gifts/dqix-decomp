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
EntryList_203dce4* GetGlobalPtr021075f4();
extern "C" Zone3D* func_02012fe4();
extern "C" NodeList02058564* func_02057924();
extern "C" int* func_0202ae18();
GameResources* GetWord0x0(int*);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc*, int);
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);
int GetByteField0x254(void*);
int GetField0x3acValue(GameState*);
extern "C" void _Z23ComputeAndCall_021a1178Pci(char*, int);
void SetBoolFlag0x254(unsigned char*, int);
extern "C" void func_0204500c(void*, unsigned char*, int, int);
extern "C" void _Z24ReinitController02043204Pc(char*);
void SetField0x98Bit0(unsigned char*);
extern "C" void func_0203e0a0(EntryList_203dce4*, unsigned short);
void SetBitsInWord(unsigned int*, unsigned int);
extern "C" void func_020a0cc4(unsigned int);
void* AllocateAligned4(AllocatorUnion*, unsigned int);
extern "C" void func_020a0c0c();
extern "C" void _Z33ResetOverlayAndAllocator_0219bf74v();
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(Foo0207df50*);
extern "C" void func_ov017_0219b938(GameResources*);
extern "C" int _Z19IsIdInRange020981e4ii(int, int);
extern "C" void func_ov017_021a316c(GameResources*);
void PushInputLogA(int);
void PushInputLogB(int);
extern "C" void func_ov023_021e2dd8(Plugin021a1284*);
extern "C" void __clear(void*, unsigned int);
int CopyOutRegion0x5718(char*, void*);
GameObject* GetCombatantWithFlag0x100(GameState*, int);
extern "C" void _Z24CopyBytesToInts_021e31b0P11Obj021e31b0Phi(Obj021e31b0*, unsigned char*, int);
extern "C" int func_ov017_021959b4();
extern "C" void _Z26SetFlagt_021e338c_021e338cPc(char*);
extern "C" void func_ov023_021e3030(Plugin021a1284*);
extern "C" void func_ov017_021a18c8(TransferEvent021a1284*);
extern "C" void func_ov017_0219b624(GameResources*);
void ClearField0x98Bit0(unsigned char*);
extern "C" void _Z28ReleaseRosterEntries0203de2cP14Roster0203de2c(Roster0203de2c*);
extern "C" void _Z35ProcessCombatantsIfFlagged_0218f79cPv(void*);
void ProcessSlotField58_021a2840(GameResources*);
extern "C" void _Z23CleanupNodeList02058564P16NodeList02058564(NodeList02058564*);
void SetField0x1e28(void*, void*);
extern "C" void _Z25RestorePairTables0207df90Pc(char*);
extern "C" void func_020432c4(void*);
extern "C" void _Z24BackupPairTables0207dfacPc(char*);
extern "C" int func_ov017_0218f5a4(GameResources*, int, int, int, int);
int CheckField0NonZero(int*);
int ArrayContainsByte(ArrayContainsByteStruct*, int);
extern "C" void func_ov017_021c3fb4(int, int);
extern "C" void func_ov017_021c4418(int, int);
void ClearBitsInWord(unsigned int*, unsigned int);
extern "C" void func_ov017_0219ba0c(GameResources*, int);
int IsField0Null(void**);
void CallFuncForEachOfFour();
extern "C" void func_ov017_0219bd1c(int, int, int, int);
void ClearBitsInField4(unsigned int*, unsigned int);
void SetBitsInField4(unsigned int*, unsigned int);
unsigned char* GetFieldIfFlag4(char*);
void ClearFlagBits(unsigned char*, int);
void SetByteField0x253(void*);
extern AllocatorUnion data_02114e20;

// USA: func_ov017_021a1284
extern "C" ARM void func_ov017_021a1284(TransferEvent021a1284* self, void* unused) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    Zone3D* zone = func_02012fe4();
    EntryList_203dce4* entries = GetGlobalPtr021075f4();
    NodeList02058564* nodes = func_02057924();
    int* search = func_0202ae18();
    GameObject* player = game->GetUnknownGameObject();
    GameResources* resources = GetWord0x0((int*)game);
    void* global = _Z26GetGlobalField0x1c020421a0v();
    _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)player, 1);
    ((PlayerTransfer021a1284*)player)->field_b2 = 0;
    if (self->stage == 0) {
        SetBrightness(resources, -16, 15);
        self->stage = 1;
    } else if (self->stage == 1) {
        if (!IsBrightnessTransitionActive(resources)) self->stage = 2;
    } else if (self->stage == 2) {
        if (loader->GetNumQueuedTasks() > 0) return;
        if (GetByteField0x254(player)) {
            player->obj3D_.unknown_2_ = -1;
            ((PlayerTransfer021a1284*)player)->field_b0 = 0x324;
            ((PlayerTransfer021a1284*)player)->field_b4 = 0x189;
            player->obj3D_.SetHeight(0x1800);
            player->obj3D_.SetRadius(0x1000);
            _Z23ComputeAndCall_021a1178Pci((char*)resources, GetField0x3acValue(game));
            SetBoolFlag0x254((unsigned char*)player, 0);
        }
        unsigned char flag = 0;
        func_0204500c(global, &flag, 0, 0xe3);
        _Z24ReinitController02043204Pc((char*)global);
        SetField0x98Bit0((unsigned char*)entries);
        func_0203e0a0(entries, zone->currentZoneID_);
        SetBitsInWord((unsigned int*)resources, 0x10);
        func_020a0cc4(0x17600);
        void* buffer = AllocateAligned4(&data_02114e20, 0x17600);
        if (!buffer) {
            func_020a0c0c();
            self->stage = 4;
            return;
        }
        self->allocator.CreateTypeA(buffer, 0x17600);
        self->allocator.Reset();
        _Z33ResetOverlayAndAllocator_0219bf74v();
        SafeAllocator* current;
        SafeAllocator* primary = &resources->allocator_array_38[0];
        InternalResource021a1284* internal = &((ResourceTransfer021a1284*)resources)->initial;
        primary->Reset();
        _Z26CopyInternalFields0207df50P11Foo0207df50((Foo0207df50*)internal);
        func_ov017_0219b938(resources);
        SafeAllocator* secondary = &resources->allocator_array_38[5];
        secondary->Reset();
        current = primary;
        if (((ZoneTransfer021a1284*)zone)->range && _Z19IsIdInRange020981e4ii((int)((ZoneTransfer021a1284*)zone)->range, zone->currentZoneID_)) {
            func_ov017_021a316c(resources);
            current = &resources->allocator_array_38[7];
            current->Reset();
        }
        PushInputLogA(5);
        PushInputLogB(1);
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
            int count = CopyOutRegion0x5718((char*)game, roster);
            for (int i = 0; i < count; ++i) {
                GameObject* combatant = GetCombatantWithFlag0x100(game, roster[i]);
                if (!combatant) continue;
                SettingsTransfer021a1284* settings = (SettingsTransfer021a1284*)((PlayerTransfer021a1284*)combatant)->settings;
                int blocked;
                if (settings) blocked = settings->unavailable ? 1 : 0;
                else blocked = 0;
                if (!blocked) selected[selectedCount++] = roster[i];
            }
            _Z24CopyBytesToInts_021e31b0P11Obj021e31b0Phi((Obj021e31b0*)self->plugin, selected, selectedCount);
        }
        self->stage = 3;
    } else if (self->stage == 3) {
        if (func_ov017_021959b4()) _Z26SetFlagt_021e338c_021e338cPc((char*)self->plugin);
        func_ov023_021e3030(self->plugin);
        if (self->plugin->result < 0) self->stage = 4;
    } else if (self->stage == 4) {
        func_ov017_021a18c8(self);
        func_ov017_021a316c(resources);
        resources->allocator_array_38[7].Reset();
        func_ov017_0219b624(resources);
        ClearField0x98Bit0((unsigned char*)entries);
        _Z28ReleaseRosterEntries0203de2cP14Roster0203de2c((Roster0203de2c*)entries);
        _Z35ProcessCombatantsIfFlagged_0218f79cPv(resources);
        ProcessSlotField58_021a2840(resources);
        _Z23CleanupNodeList02058564P16NodeList02058564(nodes);
        SetField0x1e28(global, ((ResourceTransfer021a1284*)resources)->restored);
        _Z26CopyInternalFields0207df50P11Foo0207df50((Foo0207df50*)((ResourceTransfer021a1284*)resources)->restored);
        _Z25RestorePairTables0207df90Pc(((ResourceTransfer021a1284*)resources)->restored);
        func_020432c4(global);
        _Z24BackupPairTables0207dfacPc(((ResourceTransfer021a1284*)resources)->restored);
        ArrayContainsByteStruct* party = (ArrayContainsByteStruct*)GetPtrField0x2a04(game);
        for (int i = 0; i < 4; ++i) {
            if (func_ov017_0218f5a4(resources, i, 0, 0, 0) && CheckField0NonZero(search) && ArrayContainsByte(party, i)) {
                func_ov017_021c3fb4(i, 1);
                func_ov017_021c4418(i, -1);
            }
        }
        ClearBitsInWord((unsigned int*)resources, 0x10);
        func_ov017_0219ba0c(resources, 0);
        self->stage = 5;
    } else if (self->stage == 5) {
        if (!IsField0Null(((ResourceTransfer021a1284*)resources)->pending)) return;
        CallFuncForEachOfFour();
        func_ov017_0219bd1c(1, 0, 0, 0);
        if (zone->currentZoneID_ == 0x2710 || zone->currentZoneID_ == 0x2774) {
            ClearBitsInField4((unsigned int*)resources, 0x601fe);
            SetBitsInField4((unsigned int*)resources, 0x10004);
        } else ClearBitsInField4((unsigned int*)resources, 0x601fe);
        self->stage = 6;
    } else if (self->stage == 6) {
        if (((ZoneTransfer021a1284*)func_02012fe4())->pending) return;
        ClearFlagBits(GetFieldIfFlag4((char*)game), 3);
        self->stage = 7;
    } else if (self->stage == 7) {
        if (self->mode == 3) SetByteField0x253(player);
        self->inactive = 1;
    }
}
