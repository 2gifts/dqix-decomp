#include <globaldefs.h>
#include <GameState/GameState.h>

struct SearchStruct;
struct Obj02039fec;
struct FlagWord020466f4;
struct BattleFrame {
    unsigned char field_0x0[0x29c];
    void* random;
    unsigned int field_0x2a0;
    unsigned int field_0x2a4;
    unsigned char action[0xc00];
    int state;
    int nextState;
    unsigned char field_0xeb0[0x18];
    unsigned char elements[0x2898];
    unsigned char turnTimer[0x1e14];
    int mode;
    unsigned char field_0x5578[0x54];
    void* optional;
    unsigned char field_0x55d0[0x24];
    unsigned int flags;
    unsigned char field_0x55f8[0x4b8];
    unsigned char effect[0x1394];
    short slowSpeed;
    unsigned short slowDuration;
    unsigned short slowDelay;
    unsigned char field_0x6e4a[0x1b2];
    unsigned char damping[0x714];
    signed char countdown;
    unsigned char countdownFlag;
    unsigned char field_0x7712[0xbe];
    unsigned char resetDone;
};
struct BattleManager {
    unsigned char field_0x0[0x998];
    int blocked;
};

extern "C" SearchStruct* func_0202ae18();
extern "C" void func_02015438(void*);
extern "C" void func_ov023_021eb43c(void*);
int GetGlobalField0x1c020421a0();
extern "C" void func_ov000_021735d0(void*, unsigned int);
Obj02039fec* GetData02104b6c();
void ProcessSlotDamping02039fec(Obj02039fec*);
void DecrementFieldsAndMaybeReset021824d8(void*);
int PeekInputLogB();
extern "C" void func_ov025_021df794(void*);
extern "C" int func_0202c540(SearchStruct*);
int TestFlagBitAt0xe(SearchStruct*, int);
FlagWord020466f4* GetDataPtr02114e04_020d6c00();
void ClearFlags020466f4(FlagWord020466f4*, unsigned int);
void* GetGlobal02109030();
void ResetAndSetFlag0x3c9Bit0_020939dc(void*);
void ResetEightRegionsAndFlags(char*);
extern "C" void func_02094030(void*, int, int, int);
extern "C" void func_ov000_0215fb04(void*, int);
int CheckThreeFlags_02195550(unsigned char*);
extern "C" void func_ov000_021682ec(BattleFrame*);
extern "C" void func_ov000_02163db4(BattleFrame*);
extern "C" void func_ov000_021640dc(BattleFrame*);
extern "C" void func_ov000_0216873c(BattleFrame*);
extern "C" void func_ov000_021688dc(BattleFrame*);
extern "C" void func_ov026_021d8ba0(BattleFrame*);
void RunCombatTurnCycle02169770(unsigned char*);
extern "C" void func_ov025_021db038(BattleFrame*);
extern "C" void func_ov023_021ed9f8(BattleFrame*);
extern "C" void func_ov023_021f4c04(BattleFrame*);
extern "C" void func_ov026_021db090(BattleFrame*);
void HandleField_02160de4(void*);
void HandleField_02160e94(void*);
void ProcessFlaggedombatants02160fe4_02160fe4();
extern "C" void func_ov025_021e9558(void*);
void ResetInputLogB();
void PushInputLogB(int);
void ForwardField0xc0_0205eb80(void*);
extern int data_ov000_02184220;
extern unsigned char data_02108760[0xd0];

// USA: func_ov000_02160620
extern "C" ARM void func_ov000_02160620(BattleFrame* frame) {
    GameState* game = GameState::GetInstance();
    SearchStruct* search = func_0202ae18();
    unsigned char* context = (unsigned char*)func_ov017_0218b5b0();
    if (frame->flags & 0x200) {
        func_02015438(frame->elements);
        if (frame->optional)
            func_ov023_021eb43c(frame->optional);
        if (frame->mode == 0 && (frame->flags & 0x40000) == 0 && (frame->flags & 0x80000) != 0 &&
                ((BattleManager*)GetGlobalField0x1c020421a0())->blocked == 0)
            func_ov000_021735d0(frame->turnTimer, game->GetTickCount());
        ProcessSlotDamping02039fec(GetData02104b6c());
        DecrementFieldsAndMaybeReset021824d8(frame->damping);
        if (frame->state == 8 && PeekInputLogB() == 4)
            func_ov025_021df794(frame->effect);
        GameObject* object = game->GetGameObjectByIndex(0xc8);
        if (object)
            object->obj3D_.AdvanceEffects();
        if (func_0202c540(search) && TestFlagBitAt0xe(search, 0) && frame->resetDone == 0) {
            ClearFlags020466f4(GetDataPtr02114e04_020d6c00(), 0x8020);
            void* state = GetGlobal02109030();
            ResetAndSetFlag0x3c9Bit0_020939dc(state);
            ResetEightRegionsAndFlags((char*)state);
            func_02094030(state, 4, -1, 0);
            frame->resetDone = 1;
        }
    }
    for (int i = 1; i < 4; ++i) {
        if (TestFlagBitAt0xe(search, i))
            func_ov000_0215fb04(frame->random, i);
    }
    if (CheckThreeFlags_02195550(context) == 0)
        func_ov000_021682ec(frame);
    switch (frame->state) {
    case 0: func_ov000_02163db4(frame); break;
    case 1: func_ov000_021640dc(frame); break;
    case 4: func_ov000_0216873c(frame); break;
    case 6: func_ov000_021688dc(frame); break;
    case 7:
        if (PeekInputLogB() == 3)
            func_ov026_021d8ba0(frame);
        break;
    case 17: RunCombatTurnCycle02169770((unsigned char*)frame); break;
    case 8: func_ov025_021db038(frame); break;
    case 9:
        if (PeekInputLogB() == 1) {
            func_ov023_021ed9f8(frame);
            break;
        }
    case 10:
        if (PeekInputLogB() == 1) {
            func_ov023_021f4c04(frame);
            break;
        }
    case 11:
        if (PeekInputLogB() == 3)
            func_ov026_021db090(frame);
        break;
    case 18: HandleField_02160de4(frame); break;
    case 19: HandleField_02160e94(frame); break;
    }
    if (frame->flags & 0x200)
        ((void (*)(BattleFrame*))ProcessFlaggedombatants02160fe4_02160fe4)(frame);
    if ((frame->flags & 0x2000000) &&
            (frame->state == 8 || frame->state == 7 || frame->state == 1 || frame->state == 0 || frame->state == 9)) {
        if (frame->state == 8)
            func_ov025_021e9558(frame->action);
        frame->flags &= ~0x2000000;
        frame->state = 4;
        frame->nextState = 0;
        data_ov000_02184220 = 1;
    }
    if (data_ov000_02184220) {
        if (frame->state == 7 || frame->state == 11) {
            ResetInputLogB();
            PushInputLogB(3);
        } else if (frame->state == 9 || frame->state == 10) {
            ResetInputLogB();
            PushInputLogB(1);
        }
        data_ov000_02184220 = 0;
    }
    if (frame->slowDuration) {
        unsigned int delta = game->GetEffectiveDeltaTime();
        int speed = game->GetGameSpeed();
        unsigned int elapsed = (unsigned int)((float)delta / ((float)speed / 4096.0f));
        if (elapsed < frame->slowDelay) {
            frame->slowDelay -= elapsed;
        } else if (elapsed < frame->slowDuration) {
            frame->slowDuration -= elapsed;
            game->SetGameSpeed(frame->slowSpeed);
        } else {
            frame->slowDelay = 0;
            frame->slowDuration = 0;
            game->SetGameSpeed(0x1000);
        }
    }
    if (frame->countdown == 0)
        return;
    frame->countdown -= (signed char)game->GetTickCount();
    if (frame->countdown < 0) {
        frame->countdown = 0;
        ForwardField0xc0_0205eb80(data_02108760);
        frame->countdownFlag = 0;
    }
}
