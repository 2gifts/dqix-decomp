#include <globaldefs.h>

// USA: func_02058658
ARM void* GetInlineRecordByBattleId_02058658(void* obj, int id) {
    int index = id - 0xd0;
    if (index < 0 || index >= 0x10) {
        return 0;
    }
    return (char*)obj + 0x8 + index * 0xd4;
}
