#include <globaldefs.h>
#include "GameState/GameState.h"

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
struct CombatStats02022dc8 { int status; unsigned short hp; unsigned short mp; };
struct CurrentStats02022dc8 { unsigned char field_0x0[0x30]; unsigned short hp; unsigned short mp; };
struct CombatData02022dc8 { unsigned char field_0x0[0x950]; int index; };
struct PartyMember02022dc8 {
    unsigned char field_0x0[0x130];
    CombatStats02022dc8* stats;
    CurrentStats02022dc8* current;
    unsigned char field_0x138[0x18];
    CombatData02022dc8* data;
    unsigned char field_0x154[0x38];
    unsigned int flags;
};
struct CombatReceiver02022dc8 {
    unsigned char field_0x0[0x55d];
    unsigned char memberMask;
    unsigned char field_0x55e[0x1fa];
    unsigned char memberIndices[4];
    unsigned char memberCount;
    unsigned char field_0x75d[7];
    unsigned char field_0x764;
    unsigned char field_0x765[0x253];
    unsigned char queued;
    unsigned char field_0x9b9[0xa];
    unsigned char active;
    unsigned char field_0x9c4;
    unsigned char field_0x9c5;
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
extern "C" void func_02022bb0(CombatReceiver02022dc8*);
extern "C" void func_020e0688(CombatReceiver02022dc8*);
extern "C" void _Z25HandleQueuedEntry02026694Pc(char*);
extern "C" void _Z27HandleStateDispatch020214f0P11Obj020214f0(Obj020214f0*);
extern "C" void func_02026bdc(CombatReceiver02022dc8*, int);

// USA: func_02022dc8
extern "C" ARM void func_02022dc8(CombatReceiver02022dc8* receiver) {
    GameState* game = GameState::GetInstance();
    for (int i = 0; i < 4; ++i) {
        if (!game->GetPartyMemberByIndex(i)) _Z19InitStruct_0201f9b8P11State_1f9b8(&data_020fdcb0[i]);
    }
    int memberCount = receiver->memberCount;
    if (memberCount) {
        for (int i = memberCount; i < 4; ++i) InitStopwatch0201f9e8(&data_020fdc60[i]);
    }
    for (int i = 0; i < receiver->memberCount; ++i) {
        int index = receiver->memberIndices[i];
        unsigned char mask = 1 << index;
        State_1f9b8* state = &data_020fdcb0[index];
        PartyMember02022dc8* member = (PartyMember02022dc8*)game->GetPartyMemberByIndex(index);
        if (!member || !(receiver->memberMask & mask)) continue;
        int hp = member->stats->hp;
        int currentHP = member->current->hp;
        int mp = member->stats->mp;
        int currentMP = member->current->mp;
        int valueIndex = member->data->index;
        unsigned char value = GetTableValue(member);
        int status = member->stats->status;
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
        if (state->hp > 0) member->flags &= ~1;
        if (state->reset) {
            state->statsChanged = 0;
            state->reset = 0;
        }
    }
    if (_Z17TestFlags02046708P16FlagWord02046708j(_Z27GetDataPtr02114e04_020d6c00v(), 1)) {
        func_02022bb0(receiver);
    } else {
        if (receiver->field_0x9c5 && receiver->field_0x764) func_020e0688(receiver);
        if (receiver->queued) _Z25HandleQueuedEntry02026694Pc((char*)receiver);
        if (receiver->active) _Z27HandleStateDispatch020214f0P11Obj020214f0((Obj020214f0*)receiver);
        else func_02026bdc(receiver, 1);
    }
}
