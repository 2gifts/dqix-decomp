#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
struct HeadNode02046b24;
struct Ctx021a3498;
struct Obj0208b088;
struct Obj0203dd20;
struct Foo020579b4;
struct ResetObj020d7a5c;
struct Event020da2fc { char pad_00[0xe]; unsigned char active; };
struct World0218cbd4 {
    char pad_00[0x424];
    int paused;
    char pad_428[0x223c];
    unsigned char grotto[1];
};
struct Global0218cbd4 { char pad_00[0x998]; int pending; };
struct Flags0218cbd4 { char pad_00[2]; unsigned char active; };
struct Resources0218cbd4 {
    char pad_00[0x3658];
    unsigned char blocked;
    char pad_3659[0x5b];
    unsigned char initData[1];
    char pad_36b5[0x47b];
    Flags0218cbd4* flags;
    char pad_3b34[0x7b4];
    unsigned char reset;
    char pad_42e9[0x5f];
    Vector3i position;
};
extern "C" void* func_0202ae18();
extern "C" World0218cbd4* func_02012fe4();
extern "C" Foo020579b4* func_02057924();
void* GetData02104b6c();
void* GetGlobalPtr021075f4();
void* GetFieldPtrAt0x5ca4(void*);
extern "C" int _Z26GetGlobalField0x1c020421a0v();
extern "C" ResetObj020d7a5c* _Z25GetGlobalResetObj020d7a50v();
void* GetData02153637();
extern "C" void func_ov017_0218d8cc(GameResources*);
unsigned char GetByte0x4(char*);
int GetWord0x7f6c(void*);
unsigned int GetBitsInField0(unsigned int*, unsigned int);
void Stub(GameResources*);
extern "C" void func_ov017_021941fc(GameResources*);
void CopyByteField0x253To0x252(void*);
extern "C" void _Z15InitObj0219a674Ph(unsigned char*);
extern "C" void func_02015438(void*);
extern "C" void _Z22DispatchByFlag020d9834i(int);
extern "C" void func_02022dc8(void*);
extern "C" void func_ov017_021a624c(GameResources*);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
extern "C" void func_ov017_0219a6b8(GameResources*);
extern "C" void _Z15Forward020444d4v();
typedef void (*ForwardWithTick0218cbd4)(Global0218cbd4*, unsigned int);
extern "C" void func_020966e0(void*);
extern "C" void _Z32ClearIfMatchAndFinalize_021a3498P11Ctx021a3498(Ctx021a3498*);
extern "C" void func_020a654c(GameResources*);
extern "C" void func_020ac9ac(GameResources*);
extern "C" void func_02011b68(GameState*);
int GetField0x3b0Value(GameState*);
int GetFlags(int);
extern "C" void _Z20AdvanceActor020a20d8Pv(void*);
extern "C" void func_ov000_0216d464(void*);
extern "C" void func_0204a170(void*);
extern "C" void func_ov017_0218d0ec(GameResources*);
int CheckField0NonZero(int*);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
extern "C" void _Z36ProcessFlaggedCombatants800_021a205cv();
typedef void (*ProcessFlaggedWithResources0218cbd4)(GameResources*);
extern "C" int func_ov017_02196430(GameResources*);
extern "C" int func_ov017_02196c4c(GameResources*);
extern "C" void func_ov017_021c25ac(GameResources*);
extern "C" void func_ov017_021a476c(GameResources*);
extern "C" void _Z35RunCombatantUpdatePipeline_0219755cPh(unsigned char*);
extern "C" void func_ov017_021a51a4(GameResources*);
extern "C" void func_ov017_021c05f4(GameResources*, int, int, int);
void* GetData02109020();
extern "C" void func_0208ec78(void*);
extern "C" void _Z30ProcessGrottoTurnEvent0208f4e4Ph(unsigned char*);
void* GetData02108f0c();
void InitCombatantFlagsAndPropagateCapture(Obj0208b088*);
extern "C" void _Z30ApplyScaleToCombatants0203dd20P11Obj0203dd20(Obj0203dd20*);
extern "C" void func_ov017_0218d06c(GameResources*);
extern "C" void _Z21DispatchEvent020da2fcP13Event020da2fc(Event020da2fc*);
extern "C" void _Z20ProcessArray020579b4P11Foo020579b4i(Foo020579b4*, int);
extern "C" void func_ov017_02192700(GameResources*);
extern "C" void func_020d7b04(ResetObj020d7a5c*);
extern "C" void _Z26TailCallWithState_021d9734v();
extern "C" void func_ov017_0219ca88(GameResources*);
extern "C" void _Z32ClearMonsterFlagEntries_02191bdcPhi(unsigned char*, int);
extern "C" void func_ov017_02199f08(GameResources*);
extern "C" void func_ov017_0219aa7c(GameResources*);
int* GetGlobal02109030();
extern "C" void func_02093b90(int*, unsigned int);
extern "C" void _Z33DecrementClampCounter354_021a4e48Ph(unsigned char*);
void UpdateBrightnessTransitions(GameResources*);
extern "C" void func_020e30f0(void*);
extern "C" void _Z23ProcessEntry56_0218d818Ph(unsigned char*);
extern Event020da2fc data_ov017_021d82fc;

// USA: func_ov017_0218cbd4
extern "C" ARM void func_ov017_0218cbd4(GameResources* self) {
    GameState* state = GameState::GetInstance();
    void* search = func_0202ae18();
    World0218cbd4* world = func_02012fe4();
    Foo020579b4* array = func_02057924();
    GetData02104b6c();
    GameObject* actor = state->GetUnknownGameObject();
    unsigned int ticks = state->GetTickCount();
    Obj0203dd20* scales = (Obj0203dd20*)GetGlobalPtr021075f4();
    void** field = (void**)GetFieldPtrAt0x5ca4(state);
    Global0218cbd4* global = (Global0218cbd4*)_Z26GetGlobalField0x1c020421a0v();
    ResetObj020d7a5c* reset = _Z25GetGlobalResetObj020d7a50v();
    void* entries = GetData02153637();
    func_ov017_0218d8cc(self);
    int paused = 0;
    if (GetByte0x4((char*)state) == 6 || GetWord0x7f6c(state) == 5) paused = 1;
    int dispatch = 0;
    if (GetBitsInField0(&self->brightnessFlags_0, 0x4000)) dispatch = 1;
    Stub(self);
    func_ov017_021941fc(self);
    Resources0218cbd4* fields = (Resources0218cbd4*)self;
    if (!paused) {
        CopyByteField0x253To0x252(actor);
        fields->position = actor->obj3D_.position_;
    }
    _Z15InitObj0219a674Ph(fields->initData);
    if (!GetBitsInField0(&self->brightnessFlags_0, 4)) {
        func_02015438(world);
        if (dispatch) _Z22DispatchByFlag020d9834i(1);
    }
    if (!paused && *field) func_02015438(*field);
    func_02022dc8(self->unknown_ptr_36d0);
    func_ov017_021a624c(self);
    if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)self->unknown_ptr_array_36fc[0]) != 3)
        func_ov017_0219a6b8(self);
    if (global->pending && !fields->flags->active) {
        ((ForwardWithTick0218cbd4)_Z15Forward020444d4v)(global, ticks);
    }
    func_020966e0(self->unknown_ptr_4328);
    _Z32ClearIfMatchAndFinalize_021a3498P11Ctx021a3498((Ctx021a3498*)self->unknown_ptr_array_36fc[0]);
    func_020a654c(self);
    func_020ac9ac(self);
    func_02011b68(state);
    void* animation = (void*)GetField0x3b0Value(state);
    if (animation) {
        if (GetFlags((int)animation) & 4) _Z20AdvanceActor020a20d8Pv(animation);
        else if (GetFlags((int)animation) & 8) func_ov000_0216d464(animation);
        else if (GetFlags((int)animation) & 16) func_0204a170(animation);
    }
    func_ov017_0218d0ec(self);
    if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)self->unknown_ptr_array_36fc[0]) != 3) {
        if (!CheckField0NonZero((int*)search) || GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search) == 0)
            ((ProcessFlaggedWithResources0218cbd4)_Z36ProcessFlaggedCombatants800_021a205cv)(self);
    }
    int stateA = func_ov017_02196430(self);
    int stateB = func_ov017_02196c4c(self);
    if (stateA == 2 || stateB == 2) fields->reset = 0;
    if (!paused) {
        func_ov017_021c25ac(self);
        if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)self->unknown_ptr_array_36fc[0]) != 3 &&
            GetHeadNodeIdOrMinusOne((HeadNode02046b24**)self->unknown_ptr_array_36fc[0]) != 2 && !fields->blocked) {
            func_ov017_021a476c(self);
            _Z35RunCombatantUpdatePipeline_0219755cPh((unsigned char*)self);
            func_ov017_021a51a4(self);
            func_ov017_021c05f4(self, 1, 0, 1);
        }
        if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)self->unknown_ptr_array_36fc[0]) != 3) {
            func_0208ec78(GetData02109020());
            _Z30ProcessGrottoTurnEvent0208f4e4Ph(world->grotto);
        }
        if (!fields->flags->active) InitCombatantFlagsAndPropagateCapture((Obj0208b088*)GetData02108f0c());
        _Z30ApplyScaleToCombatants0203dd20P11Obj0203dd20(scales);
        if (dispatch) _Z22DispatchByFlag020d9834i(0);
        func_ov017_0218d06c(self);
        if (dispatch) _Z22DispatchByFlag020d9834i(0);
        if (data_ov017_021d82fc.active) _Z21DispatchEvent020da2fcP13Event020da2fc(&data_ov017_021d82fc);
        _Z20ProcessArray020579b4P11Foo020579b4i(array, ticks);
        if (!world->paused) func_ov017_02192700(self);
        if (!GetBitsInField0(&self->brightnessFlags_0, 16))
            _Z32ClearIfMatchAndFinalize_021a3498P11Ctx021a3498((Ctx021a3498*)self->unknown_ptr_array_36fc[1]);
        if (!GetBitsInField0(&self->brightnessFlags_0, 128))
            _Z32ClearIfMatchAndFinalize_021a3498P11Ctx021a3498((Ctx021a3498*)self->unknown_ptr_array_36fc[2]);
        func_020d7b04(reset);
        if (GetBitsInField0(&self->brightnessFlags_0, 0x1000)) _Z26TailCallWithState_021d9734v();
        if (dispatch) _Z22DispatchByFlag020d9834i(1);
    }
    func_ov017_0219ca88(self);
    _Z32ClearMonsterFlagEntries_02191bdcPhi((unsigned char*)self, 0);
    if (!paused) {
        func_ov017_02199f08(self);
        func_ov017_0219aa7c(self);
    }
    int* clocks = GetGlobal02109030();
    func_02093b90(clocks, state->GetTickCount());
    _Z33DecrementClampCounter354_021a4e48Ph((unsigned char*)self);
    UpdateBrightnessTransitions(self);
    if (dispatch) _Z22DispatchByFlag020d9834i(0);
    func_020e30f0(entries);
    _Z23ProcessEntry56_0218d818Ph((unsigned char*)self);
}
