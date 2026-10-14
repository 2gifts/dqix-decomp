#include <globaldefs.h>
#include "GameState/GameState.h"

struct Random;

struct CombatantTimers {
    char unk0[0x18];
    unsigned int flags18;
    char unk1c[0x3b - 0x1c];
    unsigned char unk3b_0 : 3;
    unsigned char countdownActive : 1;
    unsigned char countdown : 4;
    char unk3c[0x68 - 0x3c];
    unsigned char turns68;
    unsigned char turns69;
    char unk6a[0x7a - 0x6a];
    unsigned char turns7a;
    char unk7b;
    unsigned char turns7c;
    char unk7d[0x8b - 0x7d];
    unsigned char turns8b;
    unsigned char turns8c;
    char unk8d[0x9d - 0x8d];
    unsigned char turns9d;
    char unk9e;
    unsigned char turns9f;
};

struct IdList16 {
    short v[16];
};

#define TIMERS(combatant) ((struct CombatantTimers*)(combatant)->currentStats_)

extern IdList16 data_ov000_02182cb4;
extern IdList16 data_ov000_02182cd4;
extern float data_ov000_02182ad4[];
extern float data_ov000_02182bd4[];

extern "C" int func_ov000_02153e40(struct Random* random, short* buf, int max, int start);
extern "C" void func_ov000_0215cac8(struct Random* random, short* ids, int count, short action,
                                    unsigned short* values, unsigned char* valueCounts);
extern "C" void __clear(void* dst, unsigned int size);
int NextRandomMax(struct Random* random, int max);
void ClearField0x18Flag0x20_02088dc8(unsigned char* stats);
int IsCombatantFlag0x40000000Set_ov000_0215830c(GameObject* combatant);
void ClearFlag0x40000000AndBytes_02088b84(unsigned char* stats);
int IsCombatantFlag0x80000000Set_ov000_02158324(GameObject* combatant);
void ClearFlag0x80000000AndBytes02088bd4(unsigned char* stats);
int IsFlag0x18Bit0x800Set_ov000_02156af0(GameObject* combatant);
void ClearFlag0x800AndBytes7cAnd9f_02089194(unsigned char* stats);
int IsFlag0x18Bit0x40Set_ov000_02156b08(GameObject* combatant);
void ClearFlag0x40AndBytes_020890a4(unsigned char* stats);
int IsIdOrEffectMatchTarget0215fd24(int unused, int id);

static inline short GetId(short* list, int index) { return list[index]; }

// USA: func_ov000_02157e1c
extern "C" ARM void func_ov000_02157e1c(struct Random* random) {
    IdList16 cured = data_ov000_02182cb4;
    short* curedOut = cured.v;
    short curedCount = 0;
    IdList16 ids = data_ov000_02182cd4;
    short* idList = ids.v;
    int count = func_ov000_02153e40(random, idList, 16, 1);
    struct CombatantTimers* timers;
    unsigned short messages[40];
    unsigned char messageCounts[8];
    unsigned char messageCount;
    int i;
    __clear(messages, sizeof(messages));
    messageCount = 0;
    unsigned short* messageOut = messages;
    __clear(messageCounts, sizeof(messageCounts));
    unsigned char* countOut = messageCounts;
    GameObject* combatant;
    float roll = (float)NextRandomMax(random, 100) / 100.0f;

    for (i = 0; i < count; i++) {
        short id = GetId(idList, i);
        combatant = GameState::GetInstance()->GetCombatantByIndex(id);
        if (combatant == 0) {
            continue;
        }
        countOut[curedCount] = 0;
        unsigned char anyCured = 0;
        if (TIMERS(combatant)->flags18 & 0x20) {
            ClearField0x18Flag0x20_02088dc8((unsigned char*)combatant->currentStats_);
        }
        timers = TIMERS(combatant);

        if (IsCombatantFlag0x40000000Set_ov000_0215830c(combatant)) {
            float r = (float)NextRandomMax(random, 100) / 100.0f;
            if (timers->turns8b != 0) {
                timers->turns8b--;
                if (data_ov000_02182ad4[timers->turns8b] > r) {
                    timers->turns8b = 0;
                    ClearFlag0x40000000AndBytes_02088b84((unsigned char*)combatant->currentStats_);
                    messageOut[messageCount] = 0x1c8;
                    messageCount++;
                    countOut[curedCount]++;
                    anyCured = 1;
                }
            } else if (timers->turns68 != 0) {
                timers->turns68--;
                if (timers->turns68 == 0) {
                    timers->turns68 = 0;
                    timers->turns8b = 4;
                }
            }
        }

        if (IsCombatantFlag0x80000000Set_ov000_02158324(combatant)) {
            float r = (float)NextRandomMax(random, 100) / 100.0f;
            if (timers->turns8c != 0) {
                timers->turns8c--;
                if (data_ov000_02182ad4[timers->turns8c] > r) {
                    timers->turns8c = 0;
                    ClearFlag0x80000000AndBytes02088bd4((unsigned char*)combatant->currentStats_);
                    messageOut[messageCount] = 0x24c;
                    messageCount++;
                    countOut[curedCount]++;
                    anyCured = 1;
                }
            } else if (timers->turns69 != 0) {
                timers->turns69--;
                if (timers->turns69 == 0) {
                    timers->turns69 = 0;
                    timers->turns8c = 4;
                }
            }
        }

        if (IsFlag0x18Bit0x800Set_ov000_02156af0(combatant)) {
            float r = (float)NextRandomMax(random, 100) / 100.0f;
            if (timers->turns9f != 0) {
                timers->turns9f--;
                if (data_ov000_02182ad4[timers->turns9f] > r) {
                    timers->turns9f = 0;
                    ClearFlag0x800AndBytes7cAnd9f_02089194((unsigned char*)combatant->currentStats_);
                    messageOut[messageCount] = 0x249;
                    messageCount++;
                    countOut[curedCount]++;
                    anyCured = 1;
                }
            } else if (timers->turns7c != 0) {
                timers->turns7c--;
                if (timers->turns7c == 0) {
                    timers->turns7c = 0;
                    timers->turns9f = 1;
                }
            }
        }

        if (IsFlag0x18Bit0x40Set_ov000_02156b08(combatant)) {
            if (timers->turns9d != 0) {
                timers->turns9d--;
                if (data_ov000_02182bd4[timers->turns9d] > roll) {
                    timers->turns9d = 0;
                    ClearFlag0x40AndBytes_020890a4((unsigned char*)combatant->currentStats_);
                    messageOut[messageCount] = 0x1c6;
                    messageCount++;
                    countOut[curedCount]++;
                    anyCured = 1;
                }
            } else if (timers->turns7a != 0) {
                timers->turns7a--;
                if (timers->turns7a == 0) {
                    timers->turns7a = 0;
                    timers->turns9d = 1;
                }
            }
        }

        if (TIMERS(combatant)->countdownActive) {
            TIMERS(combatant)->countdown--;
            int remaining = TIMERS(combatant)->countdown;
            if (remaining <= 0) {
                TIMERS(combatant)->countdownActive = 0;
                if (IsIdOrEffectMatchTarget0215fd24((int)random, idList[i])) {
                    messageOut[messageCount] = 0x25b;
                    messageCount++;
                    countOut[curedCount]++;
                    anyCured = 1;
                }
            }
        }

        if (anyCured != 0) {
            curedOut[curedCount] = idList[i];
            curedCount++;
        }
    }

    if (curedCount > 0) {
        func_ov000_0215cac8(random, curedOut, curedCount, 0x3a8, messages, messageCounts);
    }
}
