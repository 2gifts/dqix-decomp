#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0205ec34(void);
int TestBitInByteArray(int unused, unsigned char* arr, int index);
void SetOrClearBitInArray(void* unused, unsigned char* array, int bit, int value);
extern "C" void* func_02097430(void* c, int key);

extern short data_020e90d4[];

// USA: func_020abf60
extern "C" ARM int func_020abf60(void* param) {
    if (param == 0) {
        return 0;
    }
    void* ctx = func_0205ec34();
    if (TestBitInByteArray((int)ctx, (unsigned char*)ctx + 0x8c, 0x796) == 0 ||
        TestBitInByteArray((int)ctx, (unsigned char*)ctx + 0x8c, 0x1143) != 0) {
        return 0;
    }
    SetOrClearBitInArray(ctx, (unsigned char*)ctx + 0x8c, 0x1143, 1);
    int* table = (int*)((char*)GameState::GetInstance() + 0x75f0);
    short* keys = data_020e90d4;
    int i;
    for (i = 0; i < 0x15; i++) {
        short key = *keys;
        keys++;
        short idx = *(short*)((char*)func_02097430(param, key) + 0x1a);
        idx = idx - 1;
        table[idx] |= 0x400;
    }
    return 1;
}
