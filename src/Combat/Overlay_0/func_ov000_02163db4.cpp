#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"

struct EffectParam020708c8;
struct Obj020d7aa0;
extern "C" void* func_0202ae18();
extern "C" EffectParam020708c8* func_020704fc();
void* GetData02100044_0202ae24();
void SetScaledEffectParam020708c8(EffectParam020708c8*, unsigned int);
extern "C" int func_ov017_021959b4();
extern "C" void func_020531f0(GameObject*);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void*, int);
int GetCombatWorkFlags0x55f4_ov000_02160fd4(void*, int);
extern "C" int func_ov017_02195658(GameResources*);
int TestBitAt0x34_020a35e0(unsigned char*, unsigned int);
void EnqueueEventTag122_021c8b78(unsigned short);
void ClearBitAt0x34_020a367c(unsigned char*, int);
int GetField0x3acValue_020100a8(GameState*);
int CheckSubstructByte0x7cPositive_020535c8(signed char*);
int IsField0x180NonNegative_020535e0(int*);
Obj020d7aa0* GetGlobalResetObj020d7a50();
void TeardownAndResetState020d7aa0(Obj020d7aa0*);
extern "C" void func_ov017_021bd5d0(int);
int IsField0Null_02046b08(void**);
extern "C" void func_ov017_02191234(GameResources*);
void SetBitsInWord_0203b4a0(unsigned int*, unsigned int);
unsigned int* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0_020466e4(unsigned int*, unsigned int);
extern "C" void func_02012de8();
extern "C" void func_ov000_02164280(void*);
extern "C" void func_ov000_02166e5c(void*);
extern "C" void func_ov000_021643d4(void*);
extern "C" void func_ov000_02164fac(void*);
extern "C" void func_ov000_02165490(void*);
void InitAndProcessCombat02166880(unsigned char*);
extern "C" void func_ov000_02166978(void*);
void SetupContextForMode0205ea20(void*, int);
extern "C" void func_ov017_021c812c(int, int);
void EmptyStub_ov017_021c8398(int, int);
void NoOp_021c839c(int, int);
void SetBitsInField4_0203b4d8(unsigned int*, unsigned int);
void SetFieldsAndSignalData02184220_ov000_02160d80(void*, int);
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
    ClearBitAt0x34_020a367c(config, index);
}

// USA: func_ov000_02163db4
extern "C" ARM void func_ov000_02163db4(BattleScene02163db4* scene) {
    GameState* state = GameState::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    func_0202ae18();
    EffectParam020708c8* effect = func_020704fc();
    GetData02100044_0202ae24();
    SetBrightness(resources, -16, 0);
    SetScaledEffectParam020708c8(effect, 0);
    if (func_ov017_021959b4()) {
        for (int i = 0; i < 4; i++) {
            GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(state, i);
            if (combatant) func_020531f0(combatant);
        }
        SetCombatWorkFlags0x55f4_ov000_02160fa8(scene, 0x2000000);
    }
    BattleConfig02163db4* config = scene->config;
    int partyId = func_ov017_02195658(resources);
    if (TestBitAt0x34_020a35e0((unsigned char*)config, partyId & 0xff)) {
        if (config->partyId == partyId) {
            SetCombatWorkFlags0x55f4_ov000_02160fa8(scene, 0x2000000);
            EnqueueEventTag122_021c8b78(config->eventTag);
        }
        ClearPartyBit((unsigned char*)config, partyId);
    }
    if (scene->config->partyId != GetField0x3acValue_020100a8(state) && !GetCombatWorkFlags0x55f4_ov000_02160fd4(scene, 2)) return;
    for (int i = 0; i < 4; i++) {
        GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(state, i);
        if (!combatant) continue;
        if (TestBitAt0x34_020a35e0((unsigned char*)scene->config, i & 0xff)) {
            if (CheckSubstructByte0x7cPositive_020535c8((signed char*)combatant)) func_020531f0(combatant);
        } else {
            if (IsField0x180NonNegative_020535e0((int*)combatant)) func_020531f0(combatant);
        }
    }
    TeardownAndResetState020d7aa0(GetGlobalResetObj020d7a50());
    if (scene->config->mode >= 0) func_ov017_021bd5d0(scene->config->mode);
    if (loader->GetNumQueuedTasks() > 0) return;
    if (!IsField0Null_02046b08((void**)resources->unknown_ptr_array_36fc[1])) return;
    func_ov017_02191234(resources);
    SetBitsInWord_0203b4a0(&resources->brightnessFlags_0, 0x10);
    unsigned int* data = GetDataPtr02114e04_020d6c00();
    OrBitsIntoField0_020466e4(data, 1);
    OrBitsIntoField0_020466e4(data, 2);
    OrBitsIntoField0_020466e4(data, 0x2000);
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
    InitAndProcessCombat02166880((unsigned char*)scene);
    func_02012de8();
    func_ov000_02166978(scene);
    func_02012de8();
    SetupContextForMode0205ea20(&data_02108760, 0x65);
    REG_DISPLAY_CONTROL = (REG_DISPLAY_CONTROL & ~0x1f00) | 0x1100;
    REG_BLEND_CONTROL = 0;
    if (scene->config->field_2c) {
        func_ov017_021c812c((unsigned char)scene->config->partyId, 1);
        EmptyStub_ov017_021c8398((unsigned char)scene->config->partyId, 1);
        NoOp_021c839c((unsigned char)scene->config->partyId, 1);
    } else {
        SetCombatWorkFlags0x55f4_ov000_02160fa8(scene, 0x200000);
    }
    if (scene->field_ec8 == 0x785d || scene->field_ec8 == 0x77f7 || scene->field_ec8 == 0x77f5) {
        SetBitsInField4_0203b4d8(&resources->brightnessFlags_0, 0x200000);
    }
    SetFieldsAndSignalData02184220_ov000_02160d80(scene, 1);
}
