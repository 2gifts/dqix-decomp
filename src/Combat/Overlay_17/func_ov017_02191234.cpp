#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct;

extern "C" SearchStruct* func_0202ae18(void);
int CheckField0NonZero(int* obj);
int TestBitBySignedByteIndex(SearchStruct* search, int index);
int GetField0x3acValue(GameState* battleStruct);
unsigned char* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);
int GetSignedByte0x2d0(void* obj);
extern "C" void _Z21StoreByteList02026348PcPhi(char* obj, unsigned char* src, int count);
void CopyInRegion0x571d(char* obj, int len, void* src);
extern "C" void _Z26WriteBlockWithSize02011468PviS_(void* obj, int size, void* src);

// JPN: func_ov017_02191e18
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

    if (CheckField0NonZero((int*)search)) {
        for (int group = 0; group < 4; group++) {
            if (!TestBitBySignedByteIndex(search, group)) continue;
            list[count++] = group;
            int isCurrent = 0;
            if (group == GetField0x3acValue(battle)) {
                subList[subCount++] = group;
                isCurrent = 1;
            }
            for (int i = 1; i < 4; i++) {
                unsigned char* combatant = GetCombatantWithFlag0x1000(battle, i);
                if (combatant == 0) continue;
                if (group != GetSignedByte0x2d0(combatant)) continue;
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
            unsigned char* combatant = GetCombatantWithFlag0x1000(battle, i);
            if (combatant != 0) {
                list[combatant[regionalOffset0]] = i;
                count++;
                subList[combatant[regionalOffset0]] = i;
                subCount++;
            }
        }
    }
    _Z21StoreByteList02026348PcPhi(*(char**)(obj + regionalOffset1), list, count);
    CopyInRegion0x571d((char*)battle, count, list);
    _Z26WriteBlockWithSize02011468PviS_(battle, subCount, subList);
}
