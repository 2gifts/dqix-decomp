#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x7c8
#else
#define REGION_OFFSET_0 0x5d8
#endif

#include "GameState/GameState.h"

extern "C" void* func_02057924(void* p);
int CollectMappedValuesFromNodeList02162908(void* obj, int idx, int* out);
int CollectEntriesMatchingField0xd802058680(char* base, int value, void** out, int limit);

// USA: func_ov000_02162954
ARM int CheckCombatantStatusOrTable_02162954(void* self) {
    GameState* bs = GameState::GetInstance();
    void* base = func_02057924(bs);
    int idx = *(int*)((char*)self + 0x5000 + REGION_OFFSET_0);
    int localArray[12];
    int count = CollectMappedValuesFromNodeList02162908(self, idx, localArray);
    int i = 0;
    while (i < count) {
        GameObject* c = bs->GetCombatantByIndex(localArray[i]);
        if (c != NULL) {
            if (*((unsigned char*)c + 0xbe) == 4) {
                return 1;
            }
        }
        i++;
    }
    return CollectEntriesMatchingField0xd802058680((char*)base, 2, NULL, 0) > 0;
}
