#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/MessageUpdate.h"
#include "Resource/MessageSystem.h"
#include "World/Zone3D.h"

#if defined(jpn)
#define func_02022dc8 func_02022848
#define func_ov017_021a624c func_ov017_021a6c40
#define func_02011b68 func_020118e0
#define func_ov017_02196430 func_ov017_02196ff8
#define func_ov017_021a476c func_ov017_021a51e0
#define func_ov017_02192700 func_ov017_021932c8
#define func_ov017_02199f08 func_ov017_0219aab0
#define func_02093b90 func_020944b0
#endif

struct SearchStruct0202c1a4;
struct HeadNode02046b24;
struct Ctx021a3498;
struct Obj0208b088;
struct Obj0203dd20;
struct Foo020579b4;
struct ResetObj020d7a5c;
struct Event020da2fc { char pad_00[0xe]; unsigned char active; };
extern "C" void* func_0202ae18();
extern "C" Zone3D* func_02012fe4();
extern "C" Foo020579b4* func_02057924();
void* GetData02104b6c();
void* GetGlobalPtr021075f4();
void* GetFieldPtrAt0x5ca4(void*);
int GetGlobalField0x1c020421a0();
ResetObj020d7a5c* GetGlobalResetObj020d7a50();
void* GetData02153637();
extern "C" void func_ov017_0218d8cc(GameResources*);
unsigned char GetByte0x4(char*);
int GetWord0x7f6c(void*);
unsigned int GetBitsInField0(unsigned int*, unsigned int);
void Stub(GameResources*);
extern "C" void func_ov017_021941fc(GameResources*);
void CopyByteField0x253To0x252(void*);
void InitObj0219a674(unsigned char*);
extern "C" void func_02015438(void*);
void DispatchByFlag020d9834(int);
extern "C" void func_02022dc8(void*);
extern "C" void func_ov017_021a624c(GameResources*);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
extern "C" void func_ov017_0219a6b8(GameResources*);
extern "C" void func_020966e0(void*);
void ClearIfMatchAndFinalize_021a3498(Ctx021a3498*);
extern "C" void func_020a654c(GameResources*);
extern "C" void func_020ac9ac(GameResources*);
extern "C" void func_02011b68(GameState*);
int GetField0x3b0Value(GameState*);
int GetFlags(int);
void AdvanceActor020a20d8(void*);
extern "C" void func_ov000_0216d464(void*);
extern "C" void func_0204a170(void*);
extern "C" void func_ov017_0218d0ec(GameResources*);
int CheckField0NonZero(int*);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
void ProcessFlaggedCombatants800_021a205c(GameResources*);
extern "C" int func_ov017_02196430(GameResources*);
extern "C" int func_ov017_02196c4c(GameResources*);
extern "C" void func_ov017_021c25ac(GameResources*);
extern "C" void func_ov017_021a476c(GameResources*);
void RunCombatantUpdatePipeline_0219755c(unsigned char*);
extern "C" void func_ov017_021a51a4(GameResources*);
extern "C" void func_ov017_021c05f4(GameResources*, int, int, int);
void* GetData02109020();
extern "C" void func_0208ec78(void*);
void ProcessGrottoTurnEvent0208f4e4(unsigned char*);
void* GetData02108f0c();
void InitCombatantFlagsAndPropagateCapture(Obj0208b088*);
void ApplyScaleToCombatants0203dd20(Obj0203dd20*);
extern "C" void func_ov017_0218d06c(GameResources*);
void DispatchEvent020da2fc(Event020da2fc*);
void ProcessArray020579b4(Foo020579b4*, int);
extern "C" void func_ov017_02192700(GameResources*);
extern "C" void func_020d7b04(ResetObj020d7a5c*);
void TailCallWithState_021d9734();
extern "C" void func_ov017_0219ca88(GameResources*);
void ClearMonsterFlagEntries_02191bdc(unsigned char*, int);
extern "C" void func_ov017_02199f08(GameResources*);
extern "C" void func_ov017_0219aa7c(GameResources*);
int* GetGlobal02109030();
extern "C" void func_02093b90(int*, unsigned int);
void DecrementClampCounter354_021a4e48(unsigned char*);
void UpdateBrightnessTransitions(GameResources*);
extern "C" void func_020e30f0(void*);
void ProcessEntry56_0218d818(unsigned char*);
extern Event020da2fc data_ov017_021d82fc;

// JPN: func_ov017_0218d7b4
// USA: func_ov017_0218cbd4
extern "C" ARM void func_ov017_0218cbd4(GameResources* self) {
    GameState* state = GameState::GetInstance();
    void* search = func_0202ae18();
    Zone3D* world = func_02012fe4();
    Foo020579b4* array = func_02057924();
    GetData02104b6c();
    GameObject* actor = state->GetUnknownGameObject();
    unsigned int ticks = state->GetTickCount();
    Obj0203dd20* scales = (Obj0203dd20*)GetGlobalPtr021075f4();
    void** field = (void**)GetFieldPtrAt0x5ca4(state);
    MessageSystem* message = (MessageSystem*)GetGlobalField0x1c020421a0();
    ResetObj020d7a5c* reset = GetGlobalResetObj020d7a50();
    void* entries = GetData02153637();
    func_ov017_0218d8cc(self);
    int paused = 0;
    if (GetByte0x4((char*)state) == 6 || GetWord0x7f6c(state) == 5) paused = 1;
    int dispatch = 0;
    if (GetBitsInField0(&self->brightnessFlags_0, 0x4000)) dispatch = 1;
    Stub(self);
    func_ov017_021941fc(self);
    if (!paused) {
        CopyByteField0x253To0x252(actor);
        (*(Vector3i*)(self->unknown_432c + 0x1c)) = actor->obj3D_.position_;
    }
    InitObj0219a674(self->interactionSelection);
    if (!GetBitsInField0(&self->brightnessFlags_0, 4)) {
        func_02015438(world);
        if (dispatch) DispatchByFlag020d9834(1);
    }
    if (!paused && *field) func_02015438(*field);
    func_02022dc8(self->unknown_ptr_36d0);
    func_ov017_021a624c(self);
    if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)self->unknown_ptr_array_36fc[0]) != 3)
        func_ov017_0219a6b8(self);
    if (message->active && !((unsigned char*)self->unknown_ptr_array_3afc[13])[2]) {
        Forward020444d4(message, ticks);
    }
    func_020966e0(self->unknown_ptr_4328);
    ClearIfMatchAndFinalize_021a3498((Ctx021a3498*)self->unknown_ptr_array_36fc[0]);
    func_020a654c(self);
    func_020ac9ac(self);
    func_02011b68(state);
    void* animation = (void*)GetField0x3b0Value(state);
    if (animation) {
        if (GetFlags((int)animation) & 4) AdvanceActor020a20d8(animation);
        else if (GetFlags((int)animation) & 8) func_ov000_0216d464(animation);
        else if (GetFlags((int)animation) & 16) func_0204a170(animation);
    }
    func_ov017_0218d0ec(self);
    if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)self->unknown_ptr_array_36fc[0]) != 3) {
        if (!CheckField0NonZero((int*)search) || GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search) == 0)
            ProcessFlaggedCombatants800_021a205c(self);
    }
    int stateA = func_ov017_02196430(self);
    int stateB = func_ov017_02196c4c(self);
    if (stateA == 2 || stateB == 2) self->unknown_42e3[5] = 0;
    if (!paused) {
        func_ov017_021c25ac(self);
        if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)self->unknown_ptr_array_36fc[0]) != 3 &&
            GetHeadNodeIdOrMinusOne((HeadNode02046b24**)self->unknown_ptr_array_36fc[0]) != 2 && !self->fieldButtonState[0]) {
            func_ov017_021a476c(self);
            RunCombatantUpdatePipeline_0219755c((unsigned char*)self);
            func_ov017_021a51a4(self);
            func_ov017_021c05f4(self, 1, 0, 1);
        }
        if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)self->unknown_ptr_array_36fc[0]) != 3) {
            func_0208ec78(GetData02109020());
            ProcessGrottoTurnEvent0208f4e4((unsigned char*)world->unk_2664);
        }
        if (!((unsigned char*)self->unknown_ptr_array_3afc[13])[2]) InitCombatantFlagsAndPropagateCapture((Obj0208b088*)GetData02108f0c());
        ApplyScaleToCombatants0203dd20(scales);
        if (dispatch) DispatchByFlag020d9834(0);
        func_ov017_0218d06c(self);
        if (dispatch) DispatchByFlag020d9834(0);
        if (data_ov017_021d82fc.active) DispatchEvent020da2fc(&data_ov017_021d82fc);
        ProcessArray020579b4(array, ticks);
        if (!world->unknown_424_) func_ov017_02192700(self);
        if (!GetBitsInField0(&self->brightnessFlags_0, 16))
            ClearIfMatchAndFinalize_021a3498((Ctx021a3498*)self->unknown_ptr_array_36fc[1]);
        if (!GetBitsInField0(&self->brightnessFlags_0, 128))
            ClearIfMatchAndFinalize_021a3498((Ctx021a3498*)self->unknown_ptr_array_36fc[2]);
        func_020d7b04(reset);
        if (GetBitsInField0(&self->brightnessFlags_0, 0x1000)) TailCallWithState_021d9734();
        if (dispatch) DispatchByFlag020d9834(1);
    }
    func_ov017_0219ca88(self);
    ClearMonsterFlagEntries_02191bdc((unsigned char*)self, 0);
    if (!paused) {
        func_ov017_02199f08(self);
        func_ov017_0219aa7c(self);
    }
    int* clocks = GetGlobal02109030();
    func_02093b90(clocks, state->GetTickCount());
    DecrementClampCounter354_021a4e48((unsigned char*)self);
    UpdateBrightnessTransitions(self);
    if (dispatch) DispatchByFlag020d9834(0);
    func_020e30f0(entries);
    ProcessEntry56_0218d818((unsigned char*)self);
}
