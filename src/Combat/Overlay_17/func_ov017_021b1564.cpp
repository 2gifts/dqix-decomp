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
GameResources* GetWord0x0(int*);
extern "C" unsigned int* _Z27GetDataPtr02114e04_020d6c00v();
extern "C" Controller021b1564* _Z26GetGlobalField0x1c020421a0v();
unsigned char* GetFieldIfFlag4(char*);
void ClearIntAt0x23c(unsigned char*);
unsigned int GetWord(unsigned int*);
unsigned int GetField4(unsigned int*);
unsigned int GetField8(unsigned int*);
void SetBitsInField4(unsigned int*, unsigned int);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc*, int);
#if defined(jpn)
extern "C" void func_0204500c(void*, signed char*, int);
#define func_ov006_021576a0 func_ov006_02158ca8
enum { TransitionArenaSize = 0x3b000, TransitionAllocationSize = 0x3c820 };
#else
extern "C" void func_0204500c(void*, signed char*, int, int);
enum { TransitionArenaSize = 0x3cc00, TransitionAllocationSize = 0x3e420 };
#endif
extern "C" void _Z24ReinitController02043204Pc(char*);
extern "C" int func_020457e0(void*);
void SetField0x23cTrue(void*);
void SetBrightness(GameResources*, int, int);
extern "C" void _Z30DispatchContextByState0209c678P13Actor0209c678i(Actor0209c678*, int);
void OrBitsIntoField0(unsigned int*, unsigned int);
int IsBrightnessTransitionActive(GameResources*);
void OrGlobalFlag0x40();
extern "C" void func_020a0cc4(unsigned int);
void* AllocateAligned4(AllocatorUnion*, unsigned int);
extern "C" void func_020a0c0c();
extern "C" void func_02043124(void*);
void PushInputLogA(int);
void PushInputLogB(int);
extern "C" void _Z24SetPowCnt1Bit15_021b1ca8i(int);
extern "C" void _Z18InitStruct020979c0P11Obj020979c0h(Obj020979c0*, unsigned char);
extern "C" void func_ov006_02157a60(Overlay006021b1564*);
extern "C" void func_ov006_021576a0(Overlay006021b1564*, SafeAllocator*, void*);
extern "C" int func_02097a04(Obj020979c0*);
extern "C" void func_02074af4(void*);
void BackupSubBgControlRegisters(SubBgControlBackup02074b64*);
void* GetGlobalPtr021075f4();
extern "C" Zone3D* func_02012fe4();
extern "C" void func_0203e0a0(void*, unsigned short);
extern "C" void _Z33ResetOverlayAndAllocator_0219bf74v();
extern "C" int _Z19IsIdInRange020981e4ii(int, int);
extern "C" void func_ov017_021a316c(GameResources*);
void SetField0x98Bit0(unsigned char*);
void SetBitsInWord(unsigned int*, unsigned int);
extern "C" int func_ov006_02157d7c(Overlay006021b1564*, unsigned int);
extern "C" void func_ov006_02157cc0(Overlay006021b1564*);
extern "C" void func_02097b34(Obj020979c0*);
extern "C" void func_ov017_021b14ec(Transition021b1564*);
extern "C" void _Z27SetStateAndDispatch0209c3b4P13Actor0209c3b4i(Actor0209c3b4*, int);
void ClearFlag0x10IfSet(Struct02074bd0*);
void ClearFlag0x11IfSet(Struct02074bf4*);
extern "C" void LoadToMainBG1CharacterData(void*, int, unsigned int);
extern "C" void LoadToMainBG2CharacterData(void*, int, unsigned int);
extern "C" void LoadToMainBG1ScreenData(void*, int, unsigned int);
extern "C" void LoadToMainBG2ScreenData(void*, int, unsigned int);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion*, void*);
void ClearBitsInWord(unsigned int*, unsigned int);
void ClearBitsInField4(unsigned int*, unsigned int);
void ClearBitsInField8(unsigned int*, unsigned int);
void SetBitsInField8(unsigned int*, unsigned int);
extern "C" void _Z35ProcessCombatantsIfFlagged_0218f79cPv(void*);
void SetAndLockMainBrightness(GameResources*, int, int);
extern "C" void func_ov017_021921fc(Vector3i*, short, int);
extern "C" void func_ov017_0219bd1c(int, int, int, int);
extern "C" void func_ov017_021a2fa0(GameResources*);
extern "C" void func_ov017_0219b624(GameResources*);
extern "C" void func_ov017_0219ba0c(GameResources*, int);
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(Foo0207df50*);
extern "C" void _Z25RestorePairTables0207df90Pc(char*);
extern "C" void func_020432c4(void*);
extern "C" void _Z24BackupPairTables0207dfacPc(char*);
void UnlockAndSetMainBrightness(GameResources*, int, int);
extern "C" int* _Z29FindEntryPointerByKey0203df78Pvi(void*, int);
void* GetField0x8(int*);
extern "C" void func_ov017_021b8d1c(EntryNode021b1564*);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
void SetByteField0x253(void*);
extern char data_02109bf4[];
extern AllocatorUnion data_02114e20;
extern Overlay006021b1564* data_ov017_021d83ec;
#define REG_MAIN_DISPLAY (*(volatile unsigned int*)0x04000000)
#define REG_SUB_DISPLAY (*(volatile unsigned int*)0x04001000)

static inline int CurrentZone021b1564(Zone3D* zone) { SDK_NULL_ASSERT(zone); return zone->currentZoneID_; }

// USA: func_ov017_021b1564
extern "C" ARM void func_ov017_021b1564(Transition021b1564* self, TailList020469b4* list) {
    GameState* game = GameState::GetInstance();
    GameResources* resources = GetWord0x0((int*)game);
    unsigned int* global = _Z27GetDataPtr02114e04_020d6c00v();
    Controller021b1564* controller = _Z26GetGlobalField0x1c020421a0v();
    unsigned char* field = GetFieldIfFlag4((char*)game);
    GameObject* player = game->GetUnknownGameObject();
    if (field) ClearIntAt0x23c(field);
    if (self->stage == 0) {
        self->savedFlags = GetWord((unsigned int*)resources);
        self->savedFlags4 = GetField4((unsigned int*)resources);
        self->savedFlags8 = GetField8((unsigned int*)resources);
        SetBitsInField4((unsigned int*)resources, 0x40);
        if (!self->alternate) {
            GameObject* current = game->GetUnknownGameObject();
            if (current) _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)current, 1);
            if (*controller->action) {
#if defined(jpn)
                func_0204500c(controller, controller->action, 0);
#else
                func_0204500c(controller, controller->action, 0, 0xe3);
#endif
                controller->busy = 1;
            } else _Z24ReinitController02043204Pc((char*)controller);
            self->stage = 100;
            return;
        }
        ++self->stage;
        return;
    } else if (self->stage == 100) {
        if (controller->busy) return;
        if (func_020457e0(controller) == 1) {
            _Z24ReinitController02043204Pc((char*)controller);
            self->inactive = 1;
            if (field) SetField0x23cTrue(field);
            return;
        }
        _Z24ReinitController02043204Pc((char*)controller);
        SetBrightness(resources, -16, 16);
        _Z30DispatchContextByState0209c678P13Actor0209c678i((Actor0209c678*)data_02109bf4, 15);
        OrBitsIntoField0(global, 1);
        self->stage = 1;
        return;
    } else if (self->stage == 1) {
        if (IsBrightnessTransitionActive(resources)) return;
        OrGlobalFlag0x40();
        ++self->stage;
        return;
    } else if (self->stage == 2) {
        func_020a0cc4(TransitionAllocationSize);
        Buffer021b1564* buffer = (Buffer021b1564*)AllocateAligned4(&data_02114e20, TransitionAllocationSize);
        if (!buffer) {
            func_020a0c0c();
            self->inactive = 1;
            if (field) SetField0x23cTrue(field);
            return;
        }
        BufferTail021b1564* tail = &buffer->tail;
        Controller021b1564* current = _Z26GetGlobalField0x1c020421a0v();
        _Z24ReinitController02043204Pc((char*)current);
        func_02043124(current);
        self->allocator.CreateTypeA(buffer, TransitionArenaSize);
        self->allocator.Reset();
        self->plugin = (Obj020979c0*)self->allocator.Allocate(0x20);
        data_ov017_021d83ec = (Overlay006021b1564*)self->allocator.Allocate(0x438);
        if (!self->plugin || !data_ov017_021d83ec) {
            func_020a0c0c();
            self->inactive = 1;
            if (field) SetField0x23cTrue(field);
            return;
        }
        PushInputLogA(6);
        PushInputLogB(1);
        _Z24SetPowCnt1Bit15_021b1ca8i(1);
        _Z18InitStruct020979c0P11Obj020979c0h(self->plugin, 2);
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
        SetBitsInField4((unsigned int*)resources, 0x8de);
        void* entries = GetGlobalPtr021075f4();
        Zone3D* zone = func_02012fe4();
        func_0203e0a0(entries, zone->currentZoneID_);
        _Z33ResetOverlayAndAllocator_0219bf74v();
        if (_Z19IsIdInRange020981e4ii((int)zone->unk_840, CurrentZone021b1564(zone))) {
            func_ov017_021a316c(resources);
            resources->allocator_array_38[7].Reset();
        }
        SetField0x98Bit0((unsigned char*)entries);
        SetBitsInWord((unsigned int*)resources, 16);
        return;
    } else if (self->stage == 4) {
        SetField0x98Bit0((unsigned char*)GetGlobalPtr021075f4());
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
            if (field) SetField0x23cTrue(field);
            return;
        }
        _Z27SetStateAndDispatch0209c3b4P13Actor0209c3b4i((Actor0209c3b4*)data_02109bf4, 7);
        func_ov006_02157cc0(data_ov017_021d83ec);
        data_ov017_021d83ec = 0;
        _Z24SetPowCnt1Bit15_021b1ca8i(0);
        func_02097b34(self->plugin);
        ClearFlag0x10IfSet((Struct02074bd0*)self->displayBackup);
        REG_MAIN_DISPLAY = (REG_MAIN_DISPLAY & ~0x1f00) | (self->mainDisplay << 8);
        ClearFlag0x11IfSet((Struct02074bf4*)self->displayBackup);
        REG_SUB_DISPLAY = (REG_SUB_DISPLAY & ~0x1f00) | (self->subDisplay << 8);
        void* empty = AllocateAligned4(&data_02114e20, 0x800);
        if (empty) {
            memset(empty, 0, 0x800);
            CleanInvalidateCacheRange(empty, 0x20);
            LoadToMainBG1CharacterData(empty, 0, 0x20);
            LoadToMainBG2CharacterData(empty, 0, 0x20);
            CleanInvalidateCacheRange(empty, 0x800);
            LoadToMainBG1ScreenData(empty, 0, 0x800);
            LoadToMainBG2ScreenData(empty, 0, 0x800);
            _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, empty);
        }
        ClearBitsInWord((unsigned int*)resources, ~0u);
        ClearBitsInField4((unsigned int*)resources, ~0u);
        ClearBitsInField8((unsigned int*)resources, ~0u);
        SetBitsInWord((unsigned int*)resources, self->savedFlags);
        SetBitsInField4((unsigned int*)resources, self->savedFlags4);
        SetBitsInField8((unsigned int*)resources, self->savedFlags8);
        _Z35ProcessCombatantsIfFlagged_0218f79cPv(resources);
        SetAndLockMainBrightness(resources, -16, 1);
        func_ov017_021921fc(&player->obj3D_.position_, ((PlayerView021b1564*)player)->angle, 1);
        func_ov017_0219bd1c(1, 0, 0, 0);
        func_ov017_021a2fa0(resources);
        func_ov017_0219b624(resources);
        func_ov017_0219ba0c(resources, 0);
        ResourceBlock021b1564* block = (ResourceBlock021b1564*)resources->unknown_2cc;
        Controller021b1564* current = _Z26GetGlobalField0x1c020421a0v();
        _Z26CopyInternalFields0207df50P11Foo0207df50((Foo0207df50*)block->restored);
        _Z25RestorePairTables0207df90Pc(block->restored);
        func_020432c4(current);
        _Z24BackupPairTables0207dfacPc(block->restored);
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
                int* entry = _Z29FindEntryPointerByKey0203df78Pvi(GetGlobalPtr021075f4(), 100);
                void* info;
                if (entry) info = GetField0x8(entry);
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
        if (current) SetByteField0x253(current);
        func_020a0c0c();
        self->inactive = 1;
    }
}
