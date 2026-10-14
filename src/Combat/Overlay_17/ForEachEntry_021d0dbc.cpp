#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044_0202ae24(void);
extern "C" void func_ov017_021d0e00(int val);

// USA: func_ov017_021d0dbc
ARM void ForEachEntry_021d0dbc(void) {
    GetData02100044_0202ae24();
    unsigned char* battle = (unsigned char*)GetPtrField0x2a04_02010828(GameState::GetInstance());
    unsigned char count = battle[0xf7c];
    for (unsigned char i = 0; i < count; i++) {
        signed char v = *(signed char*)(battle + i + 0xf78);
        func_ov017_021d0e00(v);
    }
}
