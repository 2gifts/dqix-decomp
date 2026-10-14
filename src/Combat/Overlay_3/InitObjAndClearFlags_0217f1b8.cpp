#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov003_0217f118(void* obj);
void SetByteField0x253_020397c0(void* obj);
int GetFieldIfFlag4_020100f8(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);

// USA: func_ov003_0217f1b8
ARM void InitObjAndClearFlags_0217f1b8(unsigned char* obj) {
    GameState* battleStruct = GameState::GetInstance();
    unsigned int* p = (unsigned int*)((int)func_ov017_0218b5b0());
    func_ov003_0217f118(obj);
    SetByteField0x253_020397c0(battleStruct->GetUnknownGameObject());
    int f = GetFieldIfFlag4_020100f8((char*)battleStruct);
    SetField0x23cTrue_020a27ac((void*)f);
    ClearFlagBits_020a28b0((unsigned char*)f, 2);
    ClearBitsInField4_0203b4e8(p, 0xc0);
    obj[1] = 1;
}
