#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldIfFlag4_020100f8(char* obj);
extern "C" float func_ov017_021d6110(void*);
extern "C" int func_ov017_021d60f4(void*);
void SetFields0x1f0And0x1f4_0202f0c4(void* obj, int a, int b);

// USA: func_ov001_021640b4  (semantic: Func_021640b4)
extern "C" ARM int func_ov001_021640b4(void* obj) {
    void* target = (void*)GetFieldIfFlag4_020100f8((char*)GameState::GetInstance());
    float a = func_ov017_021d6110(obj);
    int b = func_ov017_021d60f4((char*)obj + 0x8);
    int fixedA = (int)(4096.0f * a);
    int packedB = (unsigned short)(b * 33);
    SetFields0x1f0And0x1f4_0202f0c4(target, fixedA, packedB);
    return 1;
}
