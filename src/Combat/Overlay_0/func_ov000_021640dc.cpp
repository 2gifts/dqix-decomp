#include <globaldefs.h>
#include "GameState/GameState.h"

void SetCombatWorkFlags0x55f4(void* work, int mask);
int GetCombatWorkFlags0x55f4(void* work, int mask);
extern "C" int func_ov017_02195658(GameResources* res);
int TestBitAt0x34(unsigned char* obj, unsigned int index);
void ClearBitAt0x34(unsigned char* obj, int index);

extern "C" void _Z27EnqueueEventTag122_021c8b78t(unsigned short tag);
int GetField0x3acValue(GameState* battleStruct);
extern "C" void func_ov000_0215f03c(struct BattleData021640dc* data);
extern "C" void func_ov000_021663a0(struct BattleScene021640dc* scene);
extern "C" void func_ov000_02164d74(struct BattleScene021640dc* scene);
extern "C" void _Z31ProcessFlagits021674f4_021674f4Phi(unsigned char* scene, int flag);
unsigned char* GetData02108f0c(void);
void SetField0xacMinusOneClearField0xb0(unsigned char* obj);
void SetFieldsAndSignalData02184220(void* p, int val);
extern "C" void func_ov000_021750e4(void* obj);
extern "C" void _Z31UpdateCombatantFlagByte021760d4Pv(void* obj);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);

struct Formation021640dc {
    unsigned char field_0x0;
    unsigned char field_0x1_0 : 4;
    unsigned char field_0x1_4 : 4;
};

struct BattleData021640dc {
    char pad_0[0x81b0];
    struct Formation021640dc formation;
};

struct BattleConfig021640dc {
    char pad_0[8];
    unsigned short eventTag;
    char pad_a[2];
    int field_0xc;
    char pad_10[0x2a - 0x10];
    signed char partyId;
    char pad_2b;
    int field_0x2c;
    int field_0x30;
};

struct TurnState021640dc {
    char pad_0[0x1b];
    signed char partyId;
    char pad_1c[4];
    int field_0x20;
    unsigned short eventTag;
};

struct BattleScene021640dc {
    char pad_0[0x29c];
    struct BattleData021640dc* data;
    struct BattleConfig021640dc* config;
    char pad_2a4[0x3760 - 0x2a4];
    struct TurnState021640dc turn;
    char pad_3788[0x54bc - 0x3788];
    unsigned char field_0x54bc;
};

static inline void ClearPartyBit(unsigned char* obj, unsigned char index) {
    ClearBitAt0x34(obj, index);
}

static inline struct Formation021640dc* GetFormation(struct BattleData021640dc* data) {
    return &data->formation;
}

// USA: func_ov000_021640dc
extern "C" ARM void func_ov000_021640dc(struct BattleScene021640dc* scene) {
    GameState* gs = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    if (res->unknown_flag_42e2 != 0) {
        SetCombatWorkFlags0x55f4(scene, 0x2000000);
        return;
    }
    struct BattleConfig021640dc* config = scene->config;
    int partyId = func_ov017_02195658(res);
    if (TestBitAt0x34((unsigned char*)config, (unsigned char)partyId)) {
        if (config->partyId == partyId) {
            SetCombatWorkFlags0x55f4(scene, 0x2000000);
            _Z27EnqueueEventTag122_021c8b78t(config->eventTag);
        }
        ClearPartyBit((unsigned char*)config, partyId);
        return;
    }
    if (!GetCombatWorkFlags0x55f4(scene, 4)) {
        return;
    }
    if (!GetCombatWorkFlags0x55f4(scene, 0x200000)) {
        return;
    }
    if (scene->config->partyId != GetField0x3acValue(gs)) {
        func_ov000_0215f03c(scene->data);
    }
    func_ov000_021663a0(scene);
    func_ov000_02164d74(scene);
    scene->config->field_0x30 = 0;
    _Z31ProcessFlagits021674f4_021674f4Phi((unsigned char*)scene, scene->config->field_0x2c == 0);
    SetField0xacMinusOneClearField0xb0(GetData02108f0c());
    SetFieldsAndSignalData02184220(scene, 7);
    SetCombatWorkFlags0x55f4(scene, 0x10000);
    SetCombatWorkFlags0x55f4(scene, 0x40000000);
    scene->turn.eventTag = scene->config->eventTag;
    scene->field_0x54bc = GetFormation(scene->data)->field_0x1_0;
    scene->turn.field_0x20 = scene->config->field_0xc;
    scene->turn.partyId = scene->config->partyId;
    func_ov000_021750e4(&scene->turn);
    _Z31UpdateCombatantFlagByte021760d4Pv(&scene->turn);
    ClearBitsInWord(&res->brightnessFlags_0, 0x10);
}
