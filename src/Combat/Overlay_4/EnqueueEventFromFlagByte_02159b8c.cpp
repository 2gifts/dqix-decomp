#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct021707d8_02159b8c { char pad[8]; char* ptr; };
extern Struct021707d8_02159b8c data_ov004_021707d8;

extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_02159b8c
#pragma optimize_for_size off
ARM int EnqueueEventFromFlagByte_02159b8c(void* obj) {
    GetPtrField0x2a04_02010828(GameState::GetInstance());
    short v = *(short*)(data_ov004_021707d8.ptr + 0x3a);
    int arg = 0x38d;
    arg += v & 0xff;
    func_ov011_021848a0(obj, arg);
    return 0;
}
