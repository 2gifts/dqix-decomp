#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Sub {
    unsigned char pad[0xc68];
    unsigned char slots[5];
};

unsigned char CopyOutRegion0x571d_020114ec(char* obj, void* dst);
extern "C" void func_ov002_02154c30(void* p);

// USA: func_ov002_02154f4c
ARM int BuildFlaggedCombatantSlotList_02154f4c(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    unsigned char buf[8];
    unsigned char n = CopyOutRegion0x571d_020114ec((char*)battle, buf);
    unsigned char count = 0;
    unsigned char i;

    buf[n] = 4;
    for (i = 0; i < n; i++) {
        if (battle->GetPartyMemberByIndex(buf[i]) != NULL) {
            ((Sub*)(obj + count + 0x1000))->slots[0] = buf[i];
            count = count + 1;
        }
    }
    ((Sub*)(obj + count + 0x1000))->slots[0] = 4;
    obj[0x1000 + 0xc6d] = count;

    int j;
    for (j = 0; j < 4; j++) {
        memset(obj + 0xa70 + 0x1000 + j * 16, 0, 4);
    }
    func_ov002_02154c30(obj + 0xa70 + 0x1000);
    return 0;
}
