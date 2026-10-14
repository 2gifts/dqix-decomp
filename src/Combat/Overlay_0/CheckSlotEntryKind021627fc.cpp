#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

void* GetSlotPtr02160f20(void* obj);
int IsMatchingID02163690(int id);

void* SearchBothTables02079e2c(char* p, int key);

// USA: func_ov000_021627fc
ARM int CheckSlotEntryKind021627fc(void* obj) {
    void* slot = GetSlotPtr02160f20(obj);
    if (slot == 0) {
        return 0;
    }
    int id = *(unsigned short*)slot;
    if (IsMatchingID02163690(id)) {
        id = 1;
    }
    ActionDataTables* table = GetData02108e10();
    void* entry = SearchBothTables02079e2c((char*)table, (short)id);
    if (entry == 0) {
        return 0;
    }
    unsigned int kind = *(unsigned int*)((char*)entry + 0x14) >> 0x1c;
    if (kind == 5) {
        return 1;
    }
    return kind == 2;
}
