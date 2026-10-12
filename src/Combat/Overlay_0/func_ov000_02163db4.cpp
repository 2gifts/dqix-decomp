#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"

struct EffectParam020708c8;
struct Obj020d7aa0;
extern "C" void* func_0202ae18();
extern "C" EffectParam020708c8* func_020704fc();
void* GetData02100044();
extern "C" void _Z28SetScaledEffectParam020708c8P19EffectParam020708c8j(EffectParam020708c8*, unsigned int);
extern "C" int func_ov017_021959b4();
extern "C" void func_020531f0(GameObject*);
void SetCombatWorkFlags0x55f4(void*, int);
int GetCombatWorkFlags0x55f4(void*, int);
extern "C" int func_ov017_02195658(GameResources*);
int TestBitAt0x34(unsigned char*, unsigned int);
extern "C" void _Z27EnqueueEventTag122_021c8b78t(unsigned short);
void ClearBitAt0x34(unsigned char*, int);
int GetField0x3acValue(GameState*);
int CheckSubstructByte0x7cPositive(signed char*);
int IsField0x180NonNegative(int*);
extern "C" Obj020d7aa0* _Z25GetGlobalResetObj020d7a50v();
extern "C" void _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(Obj020d7aa0*);
extern "C" void func_ov017_021bd5d0(int);
int IsField0Null(void**);
extern "C" void func_ov017_02191234(GameResources*);
void SetBitsInWord(unsigned int*, unsigned int);
extern "C" unsigned int* _Z27GetDataPtr02114e04_020d6c00v();
void OrBitsIntoField0(unsigned int*, unsigned int);
extern "C" void func_02012de8();
extern "C" void func_ov000_02164280(void*);
extern "C" void func_ov000_02166e5c(void*);
extern "C" void func_ov000_021643d4(void*);
extern "C" void func_ov000_02164fac(void*);
extern "C" void func_ov000_02165490(void*);
extern "C" void _Z28InitAndProcessCombat02166880Ph(unsigned char*);
extern "C" void func_ov000_02166978(void*);
extern "C" void _Z27SetupContextForMode0205ea20Pvi(void*, int);
extern "C" void func_ov017_021c812c(int, int);
extern "C" void _Z24EmptyStub_ov017_021c8398v();
extern "C" void _Z13NoOp_021c839cv();
void SetBitsInField4(unsigned int*, unsigned int);
void SetFieldsAndSignalData02184220(void*, int);
extern unsigned char data_02108760;
struct BattleConfig02163db4 {
    char pad_0[8]; unsigned short eventTag; char pad_a[2]; int mode;
    char pad_10[0x2a - 0x10]; signed char partyId; char pad_2b; int field_2c;
    char pad_30[0x40 - 0x30];
};
struct BattleScene02163db4 {
    char pad_0[0x2a0]; BattleConfig02163db4* config;
    char pad_2a4[0xec8 - 0x2a4]; unsigned short field_ec8;
};
#define REG_DISPLAY_CONTROL (*(volatile unsigned int*)0x04000000)
#define REG_BLEND_CONTROL (*(volatile unsigned short*)0x04000050)
static inline void ClearPartyBit(unsigned char* config, unsigned char index) {
    ClearBitAt0x34(config, index);
}

// USA: func_ov000_02163db4
extern "C" ARM void func_ov000_02163db4(BattleScene02163db4* scene) {
    GameState* state = GameState::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    func_0202ae18();
    EffectParam020708c8* effect = func_020704fc();
    GetData02100044();
    SetBrightness(resources, -16, 0);
    _Z28SetScaledEffectParam020708c8P19EffectParam020708c8j(effect, 0);
    if (func_ov017_021959b4()) {
        for (int i = 0; i < 4; i++) {
            GameObject* combatant = GetCombatantWithFlag0x100(state, i);
            if (combatant) func_020531f0(combatant);
        }
        SetCombatWorkFlags0x55f4(scene, 0x2000000);
    }
    BattleConfig02163db4* config = scene->config;
    int partyId = func_ov017_02195658(resources);
    if (TestBitAt0x34((unsigned char*)config, partyId & 0xff)) {
        if (config->partyId == partyId) {
            SetCombatWorkFlags0x55f4(scene, 0x2000000);
            _Z27EnqueueEventTag122_021c8b78t(config->eventTag);
        }
        ClearPartyBit((unsigned char*)config, partyId);
    }
    if (scene->config->partyId != GetField0x3acValue(state) && !GetCombatWorkFlags0x55f4(scene, 2)) return;
    for (int i = 0; i < 4; i++) {
        GameObject* combatant = GetCombatantWithFlag0x100(state, i);
        if (!combatant) continue;
        if (TestBitAt0x34((unsigned char*)scene->config, i & 0xff)) {
            if (CheckSubstructByte0x7cPositive((signed char*)combatant)) func_020531f0(combatant);
        } else {
            if (IsField0x180NonNegative((int*)combatant)) func_020531f0(combatant);
        }
    }
    _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(_Z25GetGlobalResetObj020d7a50v());
    if (scene->config->mode >= 0) func_ov017_021bd5d0(scene->config->mode);
    if (loader->GetNumQueuedTasks() > 0) return;
    if (!IsField0Null((void**)resources->unknown_ptr_array_36fc[1])) return;
    func_ov017_02191234(resources);
    SetBitsInWord(&resources->brightnessFlags_0, 0x10);
    unsigned int* data = _Z27GetDataPtr02114e04_020d6c00v();
    OrBitsIntoField0(data, 1);
    OrBitsIntoField0(data, 2);
    OrBitsIntoField0(data, 0x2000);
    func_02012de8();
    func_ov000_02164280(scene);
    if (scene->config->mode == 0x1a && !state->GetGameObjectByIndex(1)) func_ov000_02166e5c(scene);
    func_02012de8();
    func_ov000_021643d4(scene);
    func_02012de8();
    func_ov000_02164fac(scene);
    func_02012de8();
    func_ov000_02165490(scene);
    func_02012de8();
    _Z28InitAndProcessCombat02166880Ph((unsigned char*)scene);
    func_02012de8();
    func_ov000_02166978(scene);
    func_02012de8();
    _Z27SetupContextForMode0205ea20Pvi(&data_02108760, 0x65);
    REG_DISPLAY_CONTROL = (REG_DISPLAY_CONTROL & ~0x1f00) | 0x1100;
    REG_BLEND_CONTROL = 0;
    if (scene->config->field_2c) {
        func_ov017_021c812c((unsigned char)scene->config->partyId, 1);
        ((void (*)(int, int))_Z24EmptyStub_ov017_021c8398v)((unsigned char)scene->config->partyId, 1);
        ((void (*)(int, int))_Z13NoOp_021c839cv)((unsigned char)scene->config->partyId, 1);
    } else {
        SetCombatWorkFlags0x55f4(scene, 0x200000);
    }
    if (scene->field_ec8 == 0x785d || scene->field_ec8 == 0x77f7 || scene->field_ec8 == 0x77f5) {
        SetBitsInField4(&resources->brightnessFlags_0, 0x200000);
    }
    SetFieldsAndSignalData02184220(scene, 1);
}
