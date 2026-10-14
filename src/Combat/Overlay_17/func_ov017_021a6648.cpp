#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"
#include "std_library_functions.h"

struct Obj020397cc;
struct Foo0207df50 { char storage[0x70]; };
struct BattleStateTable021a6648 {
    Foo0207df50 preceding[0x1c];
    Foo0207df50 transition;
};
struct FlagWord020466f4;
struct Obj020d7aa0;
struct ListHead02046b60;
struct Transition021a6648 {
    char pad_0; unsigned char done; char pad_2[6];
    unsigned char state, timer, reset, skipLists, kind, pad_d; short task;
    SafeAllocator allocator; int backup[10]; int pair[2];
};
struct EventParams021a6648 {
    char name[0x10]; unsigned char enabled;
    unsigned char bit0:1, bit1:1, bit2:1, bit3:1, bit4:1, bit5:1, bit6:1, bit7:1;
    short field_12, field_14, field_16, field_18, field_1a, field_1c, pad_1e;
    int field_20, field_24, field_28; Vector3i position;
    int field_38, field_3c, field_40; Vector3i scale;
};
extern "C" void* func_02057924();
unsigned int* GetDataPtr02114e04_020d6c00();
void CancelPendingAction020397cc(Obj020397cc*, int);
int IsField0Null(void**);
void SetBitsInWord(unsigned int*, unsigned int);
void OrBitsIntoField0(unsigned int*, unsigned int);
extern "C" void func_020a0cc4(unsigned int);
void* AllocateAligned4(AllocatorUnion*, unsigned int);
void CopyInternalFields0207df50(Foo0207df50*);
void BackupPairTableToBuffer(int*);
void ReadGlobalPair020bb910(int*);
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" int func_02057e6c(void*, int, SafeAllocator*, void*, unsigned int, Foo0207df50*);
void FindNodeAndProcess02057fb4(void*, int, int);
void SetForwardAndStore0205ebc0(void*, int, int);
void DispatchIfField0xc4NonNeg_0205ebfc(void*, int, int);
void SetByteField0x253(void*);
void ForwardField0xc0_0205ebec(void*);
void ClearBitsInWord(unsigned int*, unsigned int);
void ClearFlags020466f4(FlagWord020466f4*, unsigned int);
void SetCombatModeFromCase020dc2d0(int);
void RegisterNodeAndNotify_0219593c();
Obj020d7aa0* GetGlobalResetObj020d7a50();
void TeardownAndResetState020d7aa0(Obj020d7aa0*);
int ListContainsId(ListHead02046b60*, int);
extern "C" void func_02046a8c(ListHead02046b60*, void*);
extern "C" void func_ov017_021a6b30(Transition021a6648*);
extern const char* data_ov017_021d771c[3];
extern AllocatorUnion data_02114e20;
extern unsigned char data_ov017_021d6aa8[9];
extern Vector3i data_ov017_021d6ab4;
extern char data_ov017_021d7778[], data_ov017_021d777a[];
extern char data_02108760;
extern unsigned char data_ov017_021d6aa9[9], data_ov017_021d6aaa[9];

// USA: func_ov017_021a6648
extern "C" ARM void func_ov017_021a6648(Transition021a6648* self, ListHead02046b60* list) {
    GameState* game = GameState::GetInstance();
    GameObject* leader = game->GetUnknownGameObject();
    GameResources* resources = func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* manager = func_02057924();
    unsigned int* flags = GetDataPtr02114e04_020d6c00();
    if (self->state == 0) {
        leader->obj3D_.MakeHidden();
        CancelPendingAction020397cc((Obj020397cc*)leader, 1);
        if (!IsField0Null((void**)resources->unknown_ptr_array_36fc[1])) return;
        SetBitsInWord(&resources->brightnessFlags_0, 0x10);
        OrBitsIntoField0(flags, 1);
        func_020a0cc4(0x7000);
        self->task = loader->QueueLoadFile(data_ov017_021d771c[self->kind], 0);
        self->state++;
    } else if (self->state == 1) {
        if (!loader->GetTaskStatus(self->task)) return;
        void* data;
        unsigned int length;
        loader->GetLoadedFileByID(self->task, &data, &length);
        self->allocator.CreateTypeA(AllocateAligned4(&data_02114e20, 0x7000), 0x7000);
        self->allocator.Reset();
        BattleStateTable021a6648* table = (BattleStateTable021a6648*)resources->unknown_2cc;
        Foo0207df50* fields = &table->transition;
        CopyInternalFields0207df50(fields);
        BackupPairTableToBuffer(self->backup);
        ReadGlobalPair020bb910(self->pair);
        void* copy = self->allocator.Allocate(length);
        memcpy(copy, data, length);
        CleanInvalidateCacheRange(copy, length);
        func_02057e6c(manager, 0xc, &self->allocator, copy, length, fields);
        self->state++;
    } else if (self->state == 2) {
        SetMainBrightness(resources, 0, 0x1e);
        self->timer = 0;
        self->state++;
    } else if (self->state == 3) {
        self->timer += game->GetTickCount();
        if (self->timer <= data_ov017_021d6aa8[self->kind * 3]) return;
        loader->RemoveTask(self->task);
        self->task = -1;
        Vector3i scale = data_ov017_021d6ab4;
        EventParams021a6648 params;
        params.name[0] = 0;
        params.enabled = 1;
        params.field_12 = 0;
        params.field_14 = -1; params.field_16 = -1; params.field_18 = -1; params.field_1a = -1;
        params.field_1c = -0x1000;
        params.field_20 = 0; params.field_24 = 0; params.field_28 = 0;
        params.position.x = 0; params.position.y = 0; params.position.z = 0;
        params.field_38 = 0; params.field_3c = 0; params.field_40 = 0;
        params.scale.x = 0x1000; params.scale.y = 0x1000; params.scale.z = 0x1000;
        params.bit0 = 0; params.bit1 = 0; params.bit2 = 1; params.bit3 = 0;
        params.bit4 = 0; params.bit5 = 0; params.bit6 = 0; params.bit7 = 0;
        if (self->kind == 2) sprintf(params.name, data_ov017_021d7778);
        else sprintf(params.name, data_ov017_021d777a);
        params.position = leader->obj3D_.position_;
        params.scale = scale;
        params.enabled = 1;
        FindNodeAndProcess02057fb4(manager, 0xc, (int)&params);
        if (self->kind == 2) {
            SetForwardAndStore0205ebc0(&data_02108760, 0xa3, 0xa3);
            DispatchIfField0xc4NonNeg_0205ebfc(&data_02108760, 5, 0);
        } else {
            SetForwardAndStore0205ebc0(&data_02108760, 0xb2, 0xb2);
            DispatchIfField0xc4NonNeg_0205ebfc(&data_02108760, 2, 0);
        }
        self->timer = 0;
        self->state++;
    } else if (self->state == 4) {
        self->timer += game->GetTickCount();
        if (self->timer < data_ov017_021d6aa9[self->kind * 3]) return;
        leader->obj3D_.MakeVisible();
        self->state++;
    } else if (self->state == 5) {
        self->timer += game->GetTickCount();
        if (self->timer < data_ov017_021d6aaa[self->kind * 3]) return;
        SetByteField0x253(leader);
        ForwardField0xc0_0205ebec(&data_02108760);
        ClearBitsInWord(&resources->brightnessFlags_0, 0x10);
        ClearFlags020466f4((FlagWord020466f4*)flags, 1);
        SetCombatModeFromCase020dc2d0(0);
        if (self->reset) {
            RegisterNodeAndNotify_0219593c();
            TeardownAndResetState020d7aa0(GetGlobalResetObj020d7a50());
        }
        if (!self->skipLists && ListContainsId(list, 0xa)) {
            func_02046a8c(list, resources->unknown_ptr_3718);
            ClearBitsInWord(&resources->brightnessFlags_0, 0x800);
        }
        if (!self->skipLists && ListContainsId(list, 0x40)) func_02046a8c(list, resources->unknown_ptr_array_3afc[0x27]);
        func_ov017_021a6b30(self);
        self->done = 1;
    }
}
