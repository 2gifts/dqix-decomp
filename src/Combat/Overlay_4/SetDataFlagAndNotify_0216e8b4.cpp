#include <globaldefs.h>
#include "GameState/GameState.h"

void SetByte0x7f70(void* obj, unsigned char value);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern unsigned char data_ov004_02171034[];

// USA: func_ov004_0216e8b4  (semantic: SetDataFlagAndNotify_0216e8b4)
extern "C" ARM int func_ov004_0216e8b4(void* obj) {
#if defined(jpn)
    enum { fieldOffset = 0 };
#else
    enum { fieldOffset = 2 };
#endif
    data_ov004_02171034[fieldOffset] = 1;
    SetByte0x7f70(GameState::GetInstance(), 0);
    func_ov011_021848a0(obj, 0x3e7);
    return 0;
}
