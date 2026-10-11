#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

void SetByte0x4(char* obj, unsigned char value);
void SetByte0x7f70(void* obj, unsigned char value);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_0216d6dc  (semantic: SetBattleByte9AndNotify_0216d6dc)
extern "C" ARM int func_ov004_0216d6dc(void* obj) {
    GameState* battle = GameState::GetInstance();
    SetByte0x4((char*)battle, 9);
    SetByte0x7f70(battle, 0);
    func_ov011_021848a0(obj, 0x3e7);
    return 0;
}
