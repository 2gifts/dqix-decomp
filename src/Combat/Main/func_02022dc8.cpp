#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/MapDisplay.h"
#include "Combat/CombatantRecovery.h"

struct State_1f9b8 {
    int hp;
    int mp;
    int currentHP;
    int currentMP;
    int index;
    unsigned char tableValue;
    unsigned char field_0x15[3];
    int status;
    unsigned char statsChanged;
    unsigned char stateChanged;
    unsigned char reset;
    unsigned char field_0x1f;
};
struct Stopwatch0201f9e8 { unsigned char fields[0x14]; };
struct CombatData02022dc8 {
#if defined(jpn)
    unsigned char unknown[0x8b8];
#else
    unsigned char unknown[0x950];
#endif
    int index;
};
struct PartyMember02022dc8 : GameObject {
#if defined(jpn)
    unsigned char unknown13c[0x144 - 0x13c];
#else
    unsigned char unknown13c[0x150 - 0x13c];
#endif
    CombatData02022dc8* data;
    unsigned char unknownAfterData[0x38];
    unsigned int recoveryFlags;
};
struct FlagWord02046708;
struct Obj020214f0;
extern State_1f9b8 data_020fdcb0[4];
extern Stopwatch0201f9e8 data_020fdc60[4];
extern "C" void _Z19InitStruct_0201f9b8P11State_1f9b8(State_1f9b8*);
extern "C" void InitStopwatch0201f9e8(Stopwatch0201f9e8*);
unsigned short GetTableValue(void*);
extern "C" FlagWord02046708* _Z27GetDataPtr02114e04_020d6c00v(void);
extern "C" int _Z17TestFlags02046708P16FlagWord02046708j(FlagWord02046708*, unsigned int);
#if defined(jpn)
extern "C" void func_02022644(MapDisplay*);
#else
extern "C" void func_02022bb0(MapDisplay*);
#endif
extern "C" void func_020e0688(MapDisplay*);
extern "C" void _Z25HandleQueuedEntry02026694Pc(char*);
extern "C" void _Z27HandleStateDispatch020214f0P11Obj020214f0(Obj020214f0*);
extern "C" void func_02026bdc(MapDisplay*, int);

// USA: func_02022dc8
extern "C" ARM void func_02022dc8(MapDisplay* receiver) {
    GameState* game = GameState::GetInstance();
    for (int i = 0; i < 4; ++i) {
        if (!game->GetPartyMemberByIndex(i)) _Z19InitStruct_0201f9b8P11State_1f9b8(&data_020fdcb0[i]);
    }
    int memberCount = receiver->field75c;
    if (memberCount) {
        for (int i = memberCount; i < 4; ++i) InitStopwatch0201f9e8(&data_020fdc60[i]);
    }
    for (int i = 0; i < receiver->field75c; ++i) {
        int index = receiver->flags758[i];
        unsigned char mask = 1 << index;
        State_1f9b8* state = &data_020fdcb0[index];
        PartyMember02022dc8* member = (PartyMember02022dc8*)game->GetPartyMemberByIndex(index);
        if (!member || !(receiver->mask55d & mask)) continue;
        int hp = member->combatFields_.savedState_130_->hp;
        int currentHP = member->baseStats_->primaryStats.maxHP;
        int mp = member->combatFields_.savedState_130_->mp;
        int currentMP = member->baseStats_->primaryStats.maxMP;
        int valueIndex = member->data->index;
        unsigned char value = GetTableValue(member);
        int status = member->combatFields_.savedState_130_->flags;
        state->stateChanged |= state->index != valueIndex;
        state->stateChanged |= state->tableValue != value;
        state->stateChanged |= state->status != status;
        if (state->hp >= 0) {
            state->statsChanged |= state->stateChanged;
            state->statsChanged |= state->hp != hp;
            state->statsChanged |= state->mp != mp;
            state->statsChanged |= state->currentHP != currentHP;
            state->statsChanged |= state->currentMP != currentMP;
        }
        state->hp = hp;
        state->mp = mp;
        state->currentHP = currentHP;
        state->currentMP = currentMP;
        state->index = valueIndex;
        state->tableValue = value;
        state->status = status;
        if (state->hp > 0) member->recoveryFlags &= ~1;
        if (state->reset) {
            state->statsChanged = 0;
            state->reset = 0;
        }
    }
    if (_Z17TestFlags02046708P16FlagWord02046708j(_Z27GetDataPtr02114e04_020d6c00v(), 1)) {
#if defined(jpn)
        func_02022644(receiver);
#else
        func_02022bb0(receiver);
#endif
    } else {
        if (receiver->field9c5 && receiver->field764) func_020e0688(receiver);
        if (receiver->field9b8) _Z25HandleQueuedEntry02026694Pc((char*)receiver);
        if (receiver->field9c3) _Z27HandleStateDispatch020214f0P11Obj020214f0((Obj020214f0*)receiver);
        else func_02026bdc(receiver, 1);
    }
}
