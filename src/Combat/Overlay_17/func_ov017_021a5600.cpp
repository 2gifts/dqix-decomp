#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)
struct Obj020397cc { char padding[0xb2]; short field_b2; };
struct FlagWord02046708;
struct ListHead02046b60;
struct SceneOptions021a5600 {
    unsigned char flag;
    char padding[3];
    int field4, field8;
};
#if defined(jpn)
enum { SceneDisplayOffset = 0x34, SceneOptionsOffset = 0x2364,
       SceneSize = 0x2378, SceneHeapSize = 0x293b8, SceneReservationSize = 0x2abd8 };
#define func_ov002_0215505c func_ov002_021567dc
#define func_ov002_02154d40 func_ov002_021564c0
#define func_ov002_02155960 func_ov002_021570a0
#define _Z26SetBytes485And486_021556ecPvii func_ov002_02156e40
#else
enum { SceneDisplayOffset = 0x4c, SceneOptionsOffset = 0x253c,
       SceneSize = 0x2550, SceneHeapSize = 0x2a590, SceneReservationSize = 0x2bdb0 };
#endif
struct BattleState021a5600 {
    unsigned char type, complete;
    char padding2[6];
    int state;
    SafeAllocator allocator;
    unsigned char option20, option21;
    char padding22[2];
    SceneOptions021a5600 options;
};
extern "C" void func_0202738c(unsigned char*, int, int, int);
extern "C" void func_02027304(unsigned char*, int);
extern "C" void func_020a0cc4(int);
extern "C" void func_020a0c0c();
extern "C" void func_ov002_0215505c(char*);
extern "C" void func_ov002_02154d40(char*, SafeAllocator*);
extern "C" int func_ov002_02155960(char*, int);
extern "C" void func_ov002_021556fc(char*);
extern "C" void func_ov017_021a55b0(BattleState021a5600*);
extern "C" void func_ov017_02191108(GameResources*, int, int, int, int);
extern "C" FlagWord02046708* _Z27GetDataPtr02114e04_020d6c00v();
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc*, int);
void SetBitsInField4(unsigned int*, unsigned int);
void ClearBitsInField4(unsigned int*, unsigned int);
unsigned char* GetFieldIfFlag4(char*);
void SetFlagsAt0x244(unsigned char*, unsigned char);
void ClearFlagBits(unsigned char*, int);
void ResetOrFindStopwatch(unsigned char*, int);
void* AllocateAligned4(AllocatorUnion*, unsigned int);
void PushInputLogA(int);
void PushInputLogB(int);
extern "C" void _Z26SetBytes485And486_021556ecPvii(void*, int, int);
int ListContainsId(ListHead02046b60*, int);
void SetByteField0x253(void*);
extern "C" void _Z25InitPaletteTables0202ac74v();
extern "C" int _Z17TestFlags02046708P16FlagWord02046708j(FlagWord02046708*, unsigned int);
extern "C" void _Z35SetByteIfDataAndCheckClear_021a01bcPh(unsigned char*);
void CopyByteField0x253To0x252(void*);
extern "C" void _Z30CheckStackAndFinalize_021a5974Pc(char*);
extern AllocatorUnion data_02114e20;
extern char* data_ov017_021d83ac;
// USA: func_ov017_021a5600
extern "C" ARM void func_ov017_021a5600(BattleState021a5600* self) {
    GameState* game = GameState::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    Obj020397cc* actor = (Obj020397cc*)game->GetUnknownGameObject();
    FlagWord02046708* flags = _Z27GetDataPtr02114e04_020d6c00v();
    _Z27CancelPendingAction020397ccP11Obj020397cci(actor, 1);
    actor->field_b2 = 0;
    SetBitsInField4(&resources->brightnessFlags_0, 0xc0);
    unsigned char* action = GetFieldIfFlag4((char*)game);
    SetFlagsAt0x244(action, 3);
    int ticks = game->GetTickCount();
    if (ticks < 0) ticks = 1;
    if (self->state == 0) {
        unsigned char* stopwatch = (unsigned char*)resources->unknown_ptr_36d0;
        ResetOrFindStopwatch(stopwatch, -1);
        func_0202738c(stopwatch, 1, 2, -1);
        func_020a0cc4(SceneReservationSize);
        void* memory = AllocateAligned4(&data_02114e20, SceneHeapSize);
        if (!memory) {
            func_020a0c0c();
            self->complete = 1;
        } else {
            self->allocator.CreateTypeA(memory, SceneHeapSize);
            self->allocator.Reset();
            PushInputLogA(2);
            PushInputLogB(1);
            data_ov017_021d83ac = (char*)self->allocator.Allocate(SceneSize);
            func_ov002_0215505c(data_ov017_021d83ac);
            _Z26SetBytes485And486_021556ecPvii(data_ov017_021d83ac, self->option20, self->option21);
            func_ov002_02154d40(data_ov017_021d83ac, &self->allocator);
            SceneOptions021a5600 options = self->options;
            char* scene = data_ov017_021d83ac;
            *reinterpret_cast<unsigned char*>(scene + SceneOptionsOffset) = options.flag;
            *reinterpret_cast<int*>(scene + SceneOptionsOffset + 4) = options.field4;
            *reinterpret_cast<int*>(scene + SceneOptionsOffset + 8) = options.field8;
            ++self->state;
        }
    } else if (self->state == 1) {
        if (func_ov002_02155960(data_ov017_021d83ac, ticks)) ++self->state;
    } else if (self->state == 2) {
        func_ov002_021556fc(data_ov017_021d83ac);
        FontBankLoader* music = GetGlobal02109400();
        BlankFunction02094b40(music);
        func_02094ab0(music);
        BlankFunction02094b34(music, 5000, 0x6f, 1, 1);
        ++self->state;
    } else if (self->state == 3) {
        unsigned int layer = *reinterpret_cast<unsigned int*>(data_ov017_021d83ac + SceneDisplayOffset);
        REG_DISPCNT = (layer << 8) | (REG_DISPCNT & ~0x1f00);
        data_ov017_021d83ac = 0;
        func_ov017_021a55b0(self);
        int clear = 1;
        ListHead02046b60* list = (ListHead02046b60*)resources->unknown_ptr_array_36fc[0];
        if (list && (ListContainsId(list, 2) || ListContainsId(list, 47))) clear = 0;
        if (clear) {
            ClearFlagBits(action, 3);
            ClearBitsInField4(&resources->brightnessFlags_0, 0xc0);
            SetByteField0x253(actor);
        }
        func_ov017_02191108(resources, 1, 1, 0, 1);
        _Z25InitPaletteTables0202ac74v();
        func_020a0c0c();
        if (!_Z17TestFlags02046708P16FlagWord02046708j(flags, 0x100000)) {
            unsigned char* stopwatch = (unsigned char*)resources->unknown_ptr_36d0;
            func_0202738c(stopwatch, 0, 2, -1);
            func_02027304(stopwatch, -1);
        }
        _Z35SetByteIfDataAndCheckClear_021a01bcPh((unsigned char*)resources);
        SetByteField0x253(actor);
        CopyByteField0x253To0x252(actor);
        self->complete = 1;
        _Z30CheckStackAndFinalize_021a5974Pc((char*)self);
    }
}
