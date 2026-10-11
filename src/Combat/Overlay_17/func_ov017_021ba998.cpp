#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct Obj020397cc;
struct List0206f7f4;
struct Dialog { char pad0[0x5a0]; signed char selection_; char pad5A1[0x5c0 - 0x5a1]; };
struct DialogTask {
    unsigned char field0_; unsigned char finished_; char pad2[6];
    SafeAllocator allocator_;
    Dialog* dialog_;
    unsigned char mode_; signed char selection_; unsigned char phase_;
};
unsigned int* GetWord0x0(int*);
unsigned char* GetFieldIfFlag4(char*);
void SetBitsInField4(unsigned int*, unsigned int);
void ClearBitsInField4(unsigned int*, unsigned int);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc*, int);
void SetFlagsAt0x244(unsigned char*, unsigned char);
void ClearFlagBits(unsigned char*, int);
extern "C" void func_020a0cc4(unsigned int);
void* AllocateAligned4(AllocatorUnion*, unsigned int);
extern "C" void func_020a0c0c();
void PushInputLogA(int);
List0206f7f4* GetData02108d18();
short GetHalfwordChecked(List0206f7f4*, int);
extern "C" void func_ov003_02158bb8(Dialog*);
extern "C" void _Z20SetField587_02159174Pvh(void*, unsigned char);
extern "C" void func_ov003_02158a84(Dialog*, SafeAllocator*);
extern "C" int func_ov017_021959b4();
extern "C" void _Z19SetFlag8At_02159240Pv(void*);
extern "C" int func_ov003_02158e94(Dialog*, int);
extern "C" void func_ov017_02191108(void*, int, int, int, int);
extern "C" void func_ov003_02158d4c(Dialog*);
extern "C" int _Z19GetField94_0215916cPv(void*);
void SetByteField0x253(void*);
extern "C" void func_ov017_021ba94c(DialogTask*);
extern AllocatorUnion data_02114e20;
#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)

// USA: func_ov017_021ba998
extern "C" ARM void func_ov017_021ba998(DialogTask* self) {
    GameState* state = GameState::GetInstance();
    unsigned int* flags = GetWord0x0((int*)state);
    GameObject* actor = state->GetUnknownGameObject();
    unsigned char* field = GetFieldIfFlag4((char*)state);
    SetBitsInField4(flags, 0xc0);
    _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)actor, 1);
    SetFlagsAt0x244(field, 3);
    int ticks = state->GetTickCount();
    if (ticks < 0) ticks = 1;
    if (self->phase_ == 0) {
        func_020a0cc4(0x16e00);
        void* buffer = AllocateAligned4(&data_02114e20, 0x16e00);
        if (!buffer) {
            func_020a0c0c(); self->finished_ = 1;
            return;
        }
        self->allocator_.CreateTypeA(buffer, 0x16e00);
        self->allocator_.Reset();
        self->dialog_ = (Dialog*)self->allocator_.Allocate(0x5c0);
        if (!self->dialog_) {
            func_020a0c0c(); self->finished_ = 1;
            return;
        }
        PushInputLogA(3);
        short selected;
        if (self->mode_) selected = self->selection_ - 1;
        else selected = GetHalfwordChecked(GetData02108d18(), 0) - 1;
        if (selected < 0) selected = 0;
        self->selection_ = selected;
        func_ov003_02158bb8(self->dialog_);
        _Z20SetField587_02159174Pvh(self->dialog_, self->mode_);
        self->dialog_->selection_ = self->selection_;
        func_ov003_02158a84(self->dialog_, &self->allocator_);
        ++self->phase_;
    } else if (self->phase_ == 1) {
        if (func_ov017_021959b4()) _Z19SetFlag8At_02159240Pv(self->dialog_);
        if (func_ov003_02158e94(self->dialog_, ticks)) ++self->phase_;
    } else if (self->phase_ == 2) {
        func_ov017_02191108(func_ov017_0218b5b0(), 1, 1, 1, 1);
        func_ov003_02158d4c(self->dialog_);
        ++self->phase_;
    } else if (self->phase_ == 3) {
        int displayMode = _Z19GetField94_0215916cPv(self->dialog_);
        REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | displayMode << 8;
        ClearBitsInField4(flags, 0xc0);
        SetByteField0x253(actor);
        ClearFlagBits(field, 3);
        func_ov017_021ba94c(self);
        func_020a0c0c();
        self->finished_ = 1;
    }
}
