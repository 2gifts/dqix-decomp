#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov004_0216794c(short* out0, short* out1, short* out2, unsigned char* out3, int* out4);
int DecrementKeyForCount_02167a0c(void* unused, int count);
int InitAndDispatchEntry_02167a6c(void* a, void* b);

extern short data_ov004_02170012;

// USA: func_ov004_02167adc
extern "C" ARM int func_ov004_02167adc(void* self) {
    short m1, m2, m3;
    unsigned char flag;
    int idx;
    GetPtrField0x2a04_02010828(GameState::GetInstance());
    func_ov004_0216794c(&m1, &m2, &m3, &flag, &idx);
    if (idx < 0) {
        goto end;
    }
    if (m1 + m2 >= m3) {
        DecrementKeyForCount_02167a0c(self, (short)(m3 - m1));
        short v = *(short*)((char*)&data_ov004_02170012 + idx * 4);
        InitAndDispatchEntry_02167a6c(self, (void*)(int)v);
    } else {
        DecrementKeyForCount_02167a0c(self, m2);
    }
end:
    return 0;
}
