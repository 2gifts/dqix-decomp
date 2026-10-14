#include "Resource/ActionDataTables.h"
#include <globaldefs.h>

void* GetActiveCombatWork(void);
void* GetSlotPtr02160f20(void* obj);
void* SearchBothTables02079e2c(char* p, int key);

// USA: func_ov025_021eba60
ARM void CheckAndSetFlag_021eba60(char* obj) {
    void* slot = GetSlotPtr02160f20(GetActiveCombatWork());
    ActionDataTables* p = GetData02108e10();
    short key = *(short*)slot;
    void* r = SearchBothTables02079e2c((char*)p, key);
    if (r == 0) {
        return;
    }
    unsigned int val = *(unsigned int*)((char*)r + 0x14);
    val = val >> 0x1c;
    if (val == 2) {
        unsigned int v2 = *(unsigned int*)((char*)r + 8);
        v2 = v2 << 0x16;
        v2 = v2 >> 0x1e;
        if (v2 == 1) {
            unsigned int f = *(unsigned int*)(obj + 0x1c4);
            f |= 0x80;
            *(unsigned int*)(obj + 0x1c4) = f;
        }
    }
}
