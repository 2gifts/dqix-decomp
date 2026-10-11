#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x800
#define REGION_OFFSET_1 0xc8
#define REGION_OFFSET_2 0xca
#else
#define REGION_OFFSET_0 0x900
#define REGION_OFFSET_1 0x60
#define REGION_OFFSET_2 0x62
#endif

#include "GameState/GameState.h"

int GetFieldAt0x150(unsigned char* obj);
int GetBoundedField156_02171674(void* obj, int index);
int GetBoundedField420_0217199c(void* obj, int index);

// USA: func_ov000_0217aa78  (semantic: FindMatchingFieldIndex_0217aa78)
extern "C" ARM int func_ov000_0217aa78(void* obj, int limit, int flag) {
    if (obj == 0) {
        return 0;
    }
    char combatantId = (char)(*(int*)((char*)obj + 0x4c));
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = bs->GetPartyMemberByIndex(combatantId);
    if (combatant == 0) {
        return 0;
    }
    int field150 = GetFieldAt0x150((unsigned char*)combatant);
    if (field150 == 0) {
        return 0;
    }
    unsigned short baseVal = *(unsigned short*)((char*)field150 + REGION_OFFSET_0 + REGION_OFFSET_1);
    if (flag != 0) {
        baseVal = *(unsigned short*)((char*)field150 + REGION_OFFSET_0 + REGION_OFFSET_2);
    }
    short idx;
    for (idx = 0; idx < limit; idx = (short)(idx + 1)) {
        int* a = (int*)GetBoundedField156_02171674(obj, idx);
        if (flag != 0) {
            a = (int*)GetBoundedField420_0217199c(obj, idx);
        }
        if (a != 0) {
            int b = a[1];
            if (baseVal == (unsigned int)(b << 20) >> 20) {
                return idx;
            }
        }
    }
    if (flag != 0) {
        *(unsigned short*)((char*)field150 + REGION_OFFSET_0 + REGION_OFFSET_2) = 0;
    } else {
        *(unsigned short*)((char*)field150 + REGION_OFFSET_0 + REGION_OFFSET_1) = 0;
    }
    return 0;
}
