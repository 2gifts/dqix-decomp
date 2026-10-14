#include <globaldefs.h>
#include "GameState/GameState.h"

void SetField5cb0AndRecordByte0_02010774(char* obj, int v);
void SetField5cb4AndRecordByte1_020107a8(char* obj, int v);
void SetSlotByte020107dc(char* base, int val);

// USA: func_02064b98
ARM void ClassifyPriceCategoryAndNotifyBattle_02064b98(unsigned char* table, int price) {
    unsigned char* entry;
    if ((price >= 0x1068 && price <= 0x106a) || (price >= 0x2328 && price <= 0x2330)) {
        table[0x332] = 1;
        table += 0x1c;
        entry = table;
    } else if ((price >= 0x6a4 && price <= 0x6aa) || (price >= 0x708 && price <= 0x710) ||
               (price >= 0x1770 && price <= 0x1771) || (price >= 0x1e14 && price <= 0x1e1d)) {
        table[0x332] = 2;
        table += 0x38;
        entry = table;
    } else if ((price >= 0xc8 && price <= 0xdb) || (price >= 0x1e7a && price <= 0x1e81)) {
        table[0x332] = 3;
        table += 0x54;
        entry = table;
    } else if ((price >= 0x834 && price <= 0x83d) || (price >= 0x206d && price <= 0x206f)) {
        table[0x332] = 4;
        table += 0x70;
        entry = table;
    } else {
        table[0x332] = 0;
        entry = table;
    }
    GameState* bs = GameState::GetInstance();
    SetField5cb0AndRecordByte0_02010774((char*)bs, entry[0]);
    SetField5cb4AndRecordByte1_020107a8((char*)bs, entry[1]);
    SetSlotByte020107dc((char*)bs, entry[2]);
}
