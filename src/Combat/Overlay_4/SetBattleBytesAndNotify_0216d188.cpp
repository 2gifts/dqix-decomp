#include <globaldefs.h>
#include "GameState/GameState.h"

void SetByte0x4_0200fb94(char* obj, unsigned char value);
void SetByte0x7f70_02012028(void* obj, unsigned char value);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_0216d188
ARM int SetBattleBytesAndNotify_0216d188(void* obj) {
    GameState* battle = GameState::GetInstance();
    SetByte0x4_0200fb94((char*)battle, 2);
    SetByte0x7f70_02012028(battle, 0);
    func_ov011_021848a0(obj, 0x3e7);
    return 0;
}
