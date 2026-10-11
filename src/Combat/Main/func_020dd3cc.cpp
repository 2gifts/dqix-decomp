#include <globaldefs.h>
#if defined(jpn)
enum { kIntrinsicOffset = 0x144, kTableIndexOffset = 0x8b8 };
#else
enum { kIntrinsicOffset = 0x150, kTableIndexOffset = 0x950 };
#endif
#include "GameState/GameState.h"

int TestBitInArray0x8ec(unsigned char* obj, int index);
extern "C" int _Z20GetTableByte020dd11cjj(unsigned int a, unsigned int b);
int CountMatchingRoundedShorts(int mask);
extern unsigned short data_020f29f4[];

// USA: func_020dd3cc
extern "C" ARM int func_020dd3cc(int combatantId) {
    GameState* gameState = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100(gameState, combatantId);
    if (combatant == 0) {
        return 0;
    }
    unsigned int result = 0;
    for (unsigned short i = 0; i <= 0xb; i++) {
        if (TestBitInArray0x8ec(*(unsigned char**)((char*)combatant + kIntrinsicOffset), data_020f29f4[i])) {
            result |= 1u << i;
        }
    }
    unsigned char* obj = *(unsigned char**)((char*)combatant + kIntrinsicOffset);
    unsigned char a = (unsigned char)*(int*)(obj + kTableIndexOffset);
    for (unsigned char j = 0; j < 4; j++) {
        unsigned int v = _Z20GetTableByte020dd11cjj(a, j);
        if (v == 0) {
            continue;
        }
        if (v >= 1 && v <= 12) {
            result |= 1u << (unsigned char)(v - 1);
        }
    }
    for (unsigned int k = 0; k <= 0xb; k++) {
        unsigned int bit = 1u << k;
        if (result & bit) {
            unsigned int ret = CountMatchingRoundedShorts(bit);
            if (ret == 0) {
                result &= ~bit;
            }
        }
    }
    return result;
}