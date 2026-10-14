#include <globaldefs.h>
#include "GameState/GameState.h"

struct Random;
struct S_10088;
struct Combatant_2088660;
struct Obj02088674;

struct CombatantAilments {
    char unk0[0x22];
    unsigned short unk22_0 : 9;
    unsigned short breathKind : 3;
    unsigned short unk22_c : 4;
    char unk24[0xa];
    short casterId;
    char unk30[0xb];
    unsigned char unk3b_0 : 1;
    unsigned char sleepPending : 1;
    unsigned char unk3b_2 : 6;
    unsigned char flags3c;
    char unk3d[0x41];
    unsigned char turns7e;
    char unk7f[3];
    unsigned char turns82;
    unsigned char turns83;
    unsigned char turns84;
    unsigned char turns85;
    unsigned char turns86;
    unsigned char turns87;
    char unk88;
    unsigned char turns89;
    unsigned char turns8a;
    char unk8b[2];
    unsigned char turns8d;
    unsigned char turns8e;
    unsigned char turns8f;
    unsigned char turns90;
    unsigned char turns91;
    unsigned char turns92;
    unsigned char turns93;
    unsigned char turns94;
    unsigned char turns95;
    unsigned char turns96;
    unsigned char turns97;
    unsigned char turns98;
    unsigned char turns99;
    unsigned char turns9a;
    unsigned char turns9b;
    unsigned char turns9c;
    char unk9d;
    unsigned char turns9e;
    char unk9f;
    unsigned char turnsa0;
    unsigned char turnsa1;
};

#define AILMENTS(combatant) ((struct CombatantAilments*)(combatant)->currentStats_)

int NextRandomMax(struct Random* random, int max);

extern "C" void* func_ov000_0215e958(struct Random* random);
extern "C" void func_ov000_021584e8(struct Random* random, void* entry, GameObject* combatant, int arg3, int kind, int param);

void ClearFlag0x80000AndBits0x3c(unsigned char* stats);
int IsFlag0x18Bit0x1000Set(GameObject* combatant);
int IsFlag10088Set(struct S_10088* obj);
int IsFlag0x18Bit0x2000Set(GameObject* combatant);
void ClearFlag0x1000AndBytes7eA1(unsigned char* stats);
void SetBool0x180Clear0x17f(unsigned char* combatant, int value);
int IsField0x18Flag0x80Set(struct Combatant_2088660* stats);
void ResetFlag0x80AndState(struct Obj02088674* stats);
void UpdateCombatantAttack(int random, int combatantId);
void UpdateCombatantDefense(int random, int combatantId);
void UpdateCombatantAgility(int random, int combatantId);
void UpdateCombatantCharm(int random, int combatantId);
void UpdateCombatantMagicalMight(int random, int combatantId);
void UpdateCombatantMagicalMending(int random, int combatantId);
int IsFlag0x14Bit0x40Set(GameObject* combatant);
extern "C" void _Z29ClearFlag0x40AndBytes02088874Ph(unsigned char* stats);
int IsCombatantFlag0x100Set(GameObject* combatant);
void ClearFlag0x100AndBytes(unsigned char* stats);
int IsCombatantFlag0x200Set(GameObject* combatant);
void ClearFlag0x200AndBytes(unsigned char* stats);
int IsFlag0x14Bit0x8000000Set(GameObject* combatant);
void ClearFlag0x8000000AndBytes(void* stats);
int IsCombatantFlag0x10000000Set(GameObject* combatant);
void ClearFlag0x10000000AndBytes(void* stats);
int IsCombatantFlag0x20000000Set(GameObject* combatant);
void ClearFlag0x20000000AndBytes0x64And0x87(unsigned char* stats);
int IsCombatantFlag0x4000000Set(GameObject* combatant);
void ClearFlag0x4000000AndBytes(unsigned char* stats);
int IsCombatantFlag0x400000Set(GameObject* combatant);
void ClearFlag0x400000AndBytes(unsigned char* stats);
int IsFlag0x18Bit0x8Set(GameObject* combatant);
void ClearFlag0x8AndBytes(unsigned char* stats);
int IsFlag0x18Bit0x10Set(GameObject* combatant);
void ClearFlag0x10AndBytes(unsigned char* stats);
int IsCombatantFlag2_0x2Set(GameObject* combatant);
void ClearFlag0x2AndBytes(unsigned char* stats);
int IsCombatantFlag2_0x4Set(GameObject* combatant);
void ClearFlag0x4AndBytes(unsigned char* stats);
int IsCombatantFlag0x400Set(GameObject* combatant);
extern "C" void _Z35ClearBattleFlags0x14And0x5802087838Pv(void* stats);
int IsCombatantFlag0x800Set(GameObject* combatant);
extern "C" void _Z35ClearBattleFlags0x14And0x580208792cPv(void* stats);
int IsCombatantFlag0x1000Set(GameObject* combatant);
extern "C" void _Z35ClearBattleFlags0x14And0x5802087a20Pv(void* stats);
int IsCombatantFlag0x2000Set(GameObject* combatant);
extern "C" void _Z35ClearBattleFlags0x14And0x5802087b14Pv(void* stats);
int IsCombatantFlag0x4000Set(GameObject* combatant);
extern "C" void _Z35ClearBattleFlags0x14And0x5802087c08Pv(void* stats);
int IsCombatantFlag0x8000Set(GameObject* combatant);
void ClearBattleFlags0x14And0x58(void* stats);
int IsCombatantModStatsFlag0x10000Set(GameObject* combatant);
void ClearFlagsAndBytes(void* stats);
int IsCombatantModStatsFlag0x20000Set(GameObject* combatant);
void ClearFlags0x14And0x58AndBytes(unsigned char* stats);
int IsFlag0x18Bit0x1Set(GameObject* combatant);
void ClearBattleFlags0x18And0x58(void* stats);
int IsFlag0x14Bit0x2000000Set(GameObject* combatant);
void ClearFlags0x14And0x58(void* stats);
int IsFlag0x18Bit0x200Set(GameObject* combatant);
void ClearFlag0x200ClearByte0x78(unsigned char* stats);
int IsFlag0x18Bit0x400Set(GameObject* combatant);
void ClearFlag0x400AndBytes79And9c(unsigned char* stats);
int IsCombatantModStatsFlag0x100Set(GameObject* combatant);
void ClearFlag0x100AndBytes7dA0(unsigned char* stats);

extern float data_ov000_02182ad4[];
extern float data_ov000_02182bd4[];

// USA: func_ov000_0215858c
extern "C" ARM void func_ov000_0215858c(struct Random* random, int combatantId, int arg2) {
    struct CombatantAilments* ailments;
    GameObject* combatant = GameState::GetInstance()->GetCombatantByIndex(combatantId);
    if (combatant == 0) {
        return;
    }

    float roll = (float)NextRandomMax(random, 100) / 100.0f;
    ailments = AILMENTS(combatant);

    if (ailments->sleepPending != 0) {
        ClearFlag0x80000AndBits0x3c((unsigned char*)combatant->currentStats_);
        AILMENTS(combatant)->flags3c |= 0x40;
    }
    if (IsFlag0x18Bit0x1000Set(combatant) != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        if (ailments->turns7e != 0) {
            ailments->turns7e = ailments->turns7e - 1;
            if (ailments->turns7e == 0) {
                ailments->turns7e = 0;
                ailments->turnsa1 = 1;
            }
        }

        int wake = 0;
        short casterId = AILMENTS(combatant)->casterId;
        GameState* state = GameState::GetInstance();
        GameObject* caster = state->GetCombatantByIndex(casterId);
        if (caster == 0) {
            wake = 1;
        }
        if (caster != 0 && IsFlag10088Set((struct S_10088*)caster) != 0) {
            wake = 1;
        }
        if (caster != 0 && IsFlag0x18Bit0x2000Set(caster) != 0) {
            wake = 1;
        }
        if (wake != 0) {
            ailments->turnsa1 = 0;
            ClearFlag0x1000AndBytes7eA1((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x164, 0);
        } else if (ailments->turnsa1 != 0) {
            int remaining = ailments->turnsa1 - 1;
            float chance = data_ov000_02182ad4[remaining & 0xff];
            float limit = roll;
            ailments->turnsa1 = remaining;
            if (chance > limit) {
                ailments->turnsa1 = 0;
                ClearFlag0x1000AndBytes7eA1((unsigned char*)combatant->currentStats_);
                int isPlayerSlot = (combatantId >= 0 && combatantId <= 3);
                if (isPlayerSlot == 0) {
                    SetBool0x180Clear0x17f((unsigned char*)combatant, 1);
                }
                func_ov000_021584e8(random, entry, combatant, arg2, 0x164, 0);
            }
        }
    }

    if (IsFlag0x14Bit0x40Set(combatant) != 0 && ailments->turns82 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns82 = ailments->turns82 - 1;
        if (data_ov000_02182bd4[ailments->turns82] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns82 = 0;
            _Z29ClearFlag0x40AndBytes02088874Ph((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1c7, 0);
        }
    }

    if (IsCombatantFlag0x100Set(combatant) != 0 && ailments->turns83 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns83 = ailments->turns83 - 1;
        if (data_ov000_02182ad4[ailments->turns83] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns83 = 0;
            ClearFlag0x100AndBytes((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1d6, 0x2d);
        }
    }

    if (IsCombatantFlag0x200Set(combatant) != 0 && ailments->turns84 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns84 = ailments->turns84 - 1;
        if (data_ov000_02182ad4[ailments->turns84] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns84 = 0;
            ClearFlag0x200AndBytes((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1c3, 0);
        }
    }

    if (IsFlag0x14Bit0x8000000Set(combatant) != 0 && ailments->turns85 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns85 = ailments->turns85 - 1;
        if (data_ov000_02182bd4[ailments->turns85] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns85 = 0;
            ClearFlag0x8000000AndBytes(combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1c9, 0x28);
        }
    }

    if (IsCombatantFlag0x10000000Set(combatant) != 0 && ailments->turns86 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns86 = ailments->turns86 - 1;
        if (data_ov000_02182bd4[ailments->turns86] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns86 = 0;
            ClearFlag0x10000000AndBytes(combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1d7, 0);
        }
    }

    if (IsCombatantFlag0x20000000Set(combatant) != 0 && ailments->turns87 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns87 = ailments->turns87 - 1;
        if (data_ov000_02182bd4[ailments->turns87] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns87 = 0;
            ClearFlag0x20000000AndBytes0x64And0x87((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1d8, 0);
        }
    }

    if (IsCombatantFlag0x4000000Set(combatant) != 0 && ailments->turns89 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns89 = ailments->turns89 - 1;
        if (data_ov000_02182ad4[ailments->turns89] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns89 = 0;
            ClearFlag0x4000000AndBytes((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1c4, 0);
        }
    }

    if (IsCombatantFlag0x400000Set(combatant) != 0 && ailments->turns8a != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns8a = ailments->turns8a - 1;
        if (data_ov000_02182ad4[ailments->turns8a] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns8a = 0;
            ClearFlag0x400000AndBytes((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1cb, 0);
        }
    }

    if (IsField0x18Flag0x80Set((struct Combatant_2088660*)combatant->currentStats_) != 0 && ailments->turns8d != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns8d = ailments->turns8d - 1;
        if (data_ov000_02182bd4[ailments->turns8d] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns8d = 0;
            unsigned int breathKind = AILMENTS(combatant)->breathKind;
            ResetFlag0x80AndState((struct Obj02088674*)combatant->currentStats_);
            switch (breathKind) {
            case 1:
                func_ov000_021584e8(random, entry, combatant, arg2, 0x219, 0);
                break;
            case 2:
                func_ov000_021584e8(random, entry, combatant, arg2, 0x21a, 0);
                break;
            case 3:
                func_ov000_021584e8(random, entry, combatant, arg2, 0x21b, 0);
                break;
            case 4:
                func_ov000_021584e8(random, entry, combatant, arg2, 0x21c, 0);
                break;
            case 5:
                func_ov000_021584e8(random, entry, combatant, arg2, 0x21d, 0);
                break;
            }
        }
    }

    if (IsFlag0x18Bit0x8Set(combatant) != 0 && ailments->turns8e != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns8e = ailments->turns8e - 1;
        if (data_ov000_02182ad4[ailments->turns8e] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns8e = 0;
            ClearFlag0x8AndBytes((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x25d, 0);
        }
    }

    if (IsFlag0x18Bit0x10Set(combatant) != 0 && ailments->turns9e != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns9e = ailments->turns9e - 1;
        if (data_ov000_02182ad4[ailments->turns9e] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns9e = 0;
            ClearFlag0x10AndBytes((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x25e, 0);
        }
    }

    if (IsCombatantFlag2_0x2Set(combatant) != 0 && ailments->turns8f != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns8f = ailments->turns8f - 1;
        if (data_ov000_02182ad4[ailments->turns8f] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns8f = 0;
            ClearFlag0x2AndBytes((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1cc, 0);
        }
    }

    if (IsCombatantFlag2_0x4Set(combatant) != 0 && ailments->turns90 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns90 = ailments->turns90 - 1;
        if (data_ov000_02182ad4[ailments->turns90] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns90 = 0;
            ClearFlag0x4AndBytes((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1cd, 0);
        }
    }

    if (IsCombatantFlag0x400Set(combatant) != 0 && ailments->turns91 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns91 = ailments->turns91 - 1;
        if (data_ov000_02182ad4[ailments->turns91] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns91 = 0;
            _Z35ClearBattleFlags0x14And0x5802087838Pv(combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1ce, 0);
            UpdateCombatantAttack((int)random, combatantId);
        }
    }

    if (IsCombatantFlag0x800Set(combatant) != 0 && ailments->turns92 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns92 = ailments->turns92 - 1;
        if (data_ov000_02182ad4[ailments->turns92] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns92 = 0;
            _Z35ClearBattleFlags0x14And0x580208792cPv(combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1cf, 0);
            UpdateCombatantDefense((int)random, combatantId);
        }
    }

    if (IsCombatantFlag0x1000Set(combatant) != 0 && ailments->turns93 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns93 = ailments->turns93 - 1;
        if (data_ov000_02182ad4[ailments->turns93] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns93 = 0;
            _Z35ClearBattleFlags0x14And0x5802087a20Pv(combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1db, 0);
            UpdateCombatantAgility((int)random, combatantId);
        }
    }

    if (IsCombatantFlag0x2000Set(combatant) != 0 && ailments->turns94 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns94 = ailments->turns94 - 1;
        if (data_ov000_02182ad4[ailments->turns94] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns94 = 0;
            _Z35ClearBattleFlags0x14And0x5802087b14Pv(combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1d0, 0);
            UpdateCombatantCharm((int)random, combatantId);
        }
    }

    if (IsCombatantFlag0x4000Set(combatant) != 0 && ailments->turns95 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns95 = ailments->turns95 - 1;
        if (data_ov000_02182ad4[ailments->turns95] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns95 = 0;
            _Z35ClearBattleFlags0x14And0x5802087c08Pv(combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1d1, 0);
            UpdateCombatantMagicalMight((int)random, combatantId);
        }
    }

    if (IsCombatantFlag0x8000Set(combatant) != 0 && ailments->turns96 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns96 = ailments->turns96 - 1;
        if (data_ov000_02182ad4[ailments->turns96] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns96 = 0;
            ClearBattleFlags0x14And0x58(combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1d2, 0);
            UpdateCombatantMagicalMending((int)random, combatantId);
        }
    }

    if (IsCombatantModStatsFlag0x10000Set(combatant) != 0 && ailments->turns97 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns97 = ailments->turns97 - 1;
        if (data_ov000_02182bd4[ailments->turns97] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns97 = 0;
            ClearFlagsAndBytes(combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1d3, 0);
        }
    }

    if (IsCombatantModStatsFlag0x20000Set(combatant) != 0 && ailments->turns98 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns98 = ailments->turns98 - 1;
        if (data_ov000_02182ad4[ailments->turns98] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns98 = 0;
            ClearFlags0x14And0x58AndBytes((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1d4, 0);
        }
    }

    if (IsFlag0x18Bit0x1Set(combatant) != 0 && ailments->turns99 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns99 = ailments->turns99 - 1;
        if (data_ov000_02182bd4[ailments->turns99] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns99 = 0;
            ClearBattleFlags0x18And0x58(combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1d5, 0);
        }
    }

    if (IsFlag0x14Bit0x2000000Set(combatant) != 0 && ailments->turns9a != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns9a = ailments->turns9a - 1;
        if (data_ov000_02182bd4[ailments->turns9a] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns9a = 0;
            ClearFlags0x14And0x58(combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1d9, 0);
        }
    }

    if (IsFlag0x18Bit0x200Set(combatant) != 0 && ailments->turns9b != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns9b = ailments->turns9b - 1;
        if (data_ov000_02182bd4[ailments->turns9b] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns9b = 0;
            ClearFlag0x200ClearByte0x78((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1c5, 0);
        }
    }

    if (IsFlag0x18Bit0x400Set(combatant) != 0 && ailments->turns9c != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turns9c = ailments->turns9c - 1;
        if (data_ov000_02182bd4[ailments->turns9c] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turns9c = 0;
            ClearFlag0x400AndBytes79And9c((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x1da, 0);
        }
    }

    if (IsCombatantModStatsFlag0x100Set(combatant) != 0 && ailments->turnsa0 != 0) {
        void* entry = func_ov000_0215e958(random);
        if (entry == 0) {
            return;
        }
        ailments->turnsa0 = ailments->turnsa0 - 1;
        if (data_ov000_02182ad4[ailments->turnsa0] > (float)NextRandomMax(random, 100) / 100.0f) {
            ailments->turnsa0 = 0;
            ClearFlag0x100AndBytes7dA0((unsigned char*)combatant->currentStats_);
            func_ov000_021584e8(random, entry, combatant, arg2, 0x24b, 0);
        }
    }
}
