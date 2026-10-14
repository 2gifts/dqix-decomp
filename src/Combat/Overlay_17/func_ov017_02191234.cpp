#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct;

extern "C" SearchStruct* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);
int TestBitBySignedByteIndex_0202c1c0(SearchStruct* search, int index);
int GetField0x3acValue_020100a8(GameState* battleStruct);
unsigned char* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);
int GetSignedByte0x2d0_020546a8(void* obj);
void StoreByteList02026348(char* obj, unsigned char* src, int count);
void CopyInRegion0x571d_020114c0(char* obj, int len, void* src);
void WriteBlockWithSize02011468(void* obj, int size, void* src);

// USA: func_ov017_02191234
extern "C" ARM void func_ov017_02191234(unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x2c6, regionalOffset1=0x34c0};
#else
 enum {regionalOffset0=0x2d2, regionalOffset1=0x36d0};
#endif
    GameState* battle = GameState::GetInstance();
    SearchStruct* search = func_0202ae18();
    unsigned char count = 0;
    unsigned char subCount = 0;
    unsigned char list[4];
    unsigned char subList[4];

    if (CheckField0NonZero_0202b7d8((int*)search)) {
        for (int group = 0; group < 4; group++) {
            if (!TestBitBySignedByteIndex_0202c1c0(search, group)) continue;
            list[count++] = group;
            int isCurrent = 0;
            if (group == GetField0x3acValue_020100a8(battle)) {
                subList[subCount++] = group;
                isCurrent = 1;
            }
            for (int i = 1; i < 4; i++) {
                unsigned char* combatant = GetCombatantWithFlag0x1000_0200ff58(battle, i);
                if (combatant == 0) continue;
                if (group != GetSignedByte0x2d0_020546a8(combatant)) continue;
                list[combatant[regionalOffset0]] = i;
                count++;
                if (isCurrent) {
                    subList[combatant[regionalOffset0]] = i;
                    subCount++;
                }
            }
        }
    } else {
        list[count++] = 0;
        subList[subCount++] = 0;
        for (int i = 1; i < 4; i++) {
            unsigned char* combatant = GetCombatantWithFlag0x1000_0200ff58(battle, i);
            if (combatant != 0) {
                list[combatant[regionalOffset0]] = i;
                count++;
                subList[combatant[regionalOffset0]] = i;
                subCount++;
            }
        }
    }
    StoreByteList02026348(*(char**)(obj + regionalOffset1), list, count);
    CopyInRegion0x571d_020114c0((char*)battle, count, list);
    WriteBlockWithSize02011468(battle, subCount, subList);
}
