#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/TextQueue.h"

struct EffectParam020708c8;
struct AxisFloats0203b57c;
struct FlagWord02046708;

struct BattleScene021b86f8 {
    char unk_0[0x24];
    unsigned short activeCombatantId;
    char unk_26[0x6ac - 0x26];
    void* field_0x6ac;
    char unk_6b0[0x6b4 - 0x6b0];
    unsigned short state;
    unsigned short flags;
};

extern char data_02109bf4[];
#if defined(jpn)
extern char data_ov017_021d83e7[];
#endif

void GetGlobalField0x1c020421a0(void);
int GetField0x3acValue(GameState* gs);
GameObject* GetCombatantChecked(GameState* battleStruct, int combatantId);
extern "C" EffectParam020708c8* func_020704fc(void);
FlagWord02046708* GetDataPtr02114e04_020d6c00(void);
extern "C" void* func_02012fe4(void);
void* GetGlobalResetObj020d7a50(void);
int CallFunc020e0434With02153694(int value);
void* GetOffsetPtr02160f08(void* obj);
extern "C" void func_ov000_02172850(void* obj);
float GetIntAt0xc(unsigned char* obj);
void SetScaledEffectParam020708c8(EffectParam020708c8* obj, unsigned int value);
int GetAxisIntValue(AxisFloats0203b57c* s, int axis);
extern "C" int abs(int x);
void SetMainBrightness(GameResources* res, int level, int b);
int TestFlags02046708(FlagWord02046708* word, unsigned int mask);
struct FlagWord020466f4;
void ClearFlags020466f4(FlagWord020466f4* word, unsigned int bits);
void SetCombatModeFromCase020dc2d0(int mode);
int GetState0209ca68(char* p);
extern "C" void func_0209c530(void* p);
void ClearBitsInField4(unsigned int* word, unsigned int bits);
void ClearBitsInWord(unsigned int* word, unsigned int bits);
extern "C" void func_ov017_021c9c64(unsigned short a, int b);
void SetFieldForMatchingCombatant_021c98f4(int target, int flag);

// JPN: func_ov017_021b8c08
// USA: func_ov017_021b86f8
extern "C" ARM void func_ov017_021b86f8(BattleScene021b86f8* self, int combatantId, int showMessage, int arg3) {
    if (self->field_0x6ac == NULL) return;
    if (combatantId != self->activeCombatantId || self->state != 2) return;
    GameState* gs = GameState::GetInstance();
    GetGlobalField0x1c020421a0();
    GameObject* combatant = GetCombatantChecked(gs, GetField0x3acValue(gs));
    GameResources* res = func_ov017_0218b5b0();
    EffectParam020708c8* effect = func_020704fc();
    FlagWord02046708* flagWord = GetDataPtr02114e04_020d6c00();
    func_02012fe4();
    if (combatant != NULL) {
        if (showMessage) {
#if defined(jpn)
            func_020d7e10(GetGlobalResetObj020d7a50(), data_ov017_021d83e7, 0, 0, 1);
#else
            func_020d7e10(GetGlobalResetObj020d7a50(), (void*)CallFunc020e0434With02153694(0x23), 0, 0, 1
#if !defined(jpn)
                , 1
#endif
            );
#endif

        }
        func_ov000_02172850(GetOffsetPtr02160f08(self->field_0x6ac));
    }
    if ((int)GetIntAt0xc((unsigned char*)effect) > 0x1e) {
        SetScaledEffectParam020708c8(effect, 0x1e);
    }
    if (abs(GetAxisIntValue((AxisFloats0203b57c*)res, 0)) == 0x10) {
        SetMainBrightness(res, 0, 0x1e);
    }
    if (TestFlags02046708(flagWord, 1)) {
        ClearFlags020466f4((FlagWord020466f4*)flagWord, 1);
        SetCombatModeFromCase020dc2d0(0);
    }
    if (GetState0209ca68(data_02109bf4) == 2) {
        func_0209c530(data_02109bf4);
    }
    ClearFlags020466f4((FlagWord020466f4*)flagWord, 0x200);
    ClearBitsInField4(&res->brightnessFlags_0, 0x40);
    ClearBitsInField4(&res->brightnessFlags_0, 4);
    ClearBitsInField4(&res->brightnessFlags_0, 0x10);
    ClearBitsInField4(&res->brightnessFlags_0, 2);
    ClearBitsInWord(&res->brightnessFlags_0, 4);
    self->flags |= 0x2000;
    self->state = 3;
    func_ov017_021c9c64(combatantId, arg3);
    SetFieldForMatchingCombatant_021c98f4(combatantId, 1);
}
