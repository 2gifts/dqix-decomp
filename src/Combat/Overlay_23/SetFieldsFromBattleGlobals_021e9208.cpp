#include <globaldefs.h>
#include "GameState/GameState.h"

int GetField5cb0Value_0201079c(char* obj);
int GetField5cb4Value_020107d0(char* obj);
extern "C" void func_ov017_021d6134(void*, unsigned int);

// USA: func_ov023_021e9208
ARM int SetFieldsFromBattleGlobals_021e9208(void* obj) {
    char* bs = (char*)GameState::GetInstance();
    func_ov017_021d6134(obj, GetField5cb0Value_0201079c(bs));
    func_ov017_021d6134((char*)obj + 0x8, GetField5cb4Value_020107d0(bs));
    return 1;
}
