#include <globaldefs.h>
#include "GameState/GameState.h"

void SetField5cb0AndRecordByte0_02010774(char* obj, int v);
void SetField5cb4AndRecordByte1_020107a8(char* obj, int v);
void SetSlotByte020107dc(char* base, int val);

// USA: func_0206df14
ARM void ApplySlotBytesToBattleStruct_0206df14(unsigned char* obj) {
    GameState* bs = GameState::GetInstance();
    SetField5cb0AndRecordByte0_02010774((char*)bs, (obj + obj[0x332] * 0x1c)[0]);
    SetField5cb4AndRecordByte1_020107a8((char*)bs, (obj + obj[0x332] * 0x1c)[1]);
    SetSlotByte020107dc((char*)bs, (obj + obj[0x332] * 0x1c)[2]);
}
