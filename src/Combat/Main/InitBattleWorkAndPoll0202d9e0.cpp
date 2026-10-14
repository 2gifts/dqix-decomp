#include <globaldefs.h>
#include "System/Memory.h"

extern char data_021015a0;
extern char data_02101640;
extern char data_02101b80;
extern char data_021016e0;
extern char data_02101614;
extern char data_02103400;

void SetState9IfField0x2Is8_0202dae0(unsigned short* obj);
void PollField0x40OrSetState_0202db08(unsigned short* obj);
int CallFunc020d4fa4Zero_020d4f7c(int a, int b, int c);
void SetField0x48UnlessState9Or10_0202c848(int arg);

// USA: func_0202d9e0
ARM int InitBattleWorkAndPoll0202d9e0(void) {
    int result;
    int ok;

    if (*(unsigned short*)(&data_021015a0 + 0xe) != 0) {
        return 0;
    }

    if (*(int*)(&data_021015a0 + 0x40) == 0) {
        *(int*)(&data_021015a0 + 0x40) = (int)&SetState9IfField0x2Is8_0202dae0;
    }

    *(int*)(&data_021015a0 + 0x2c) = 0;
    *(int*)(&data_021015a0 + 0x38) = 0;
    *(int*)(&data_021015a0 + 0x28) = 0;
    *(unsigned short*)(&data_021015a0 + 0x0) = 0;
    *(unsigned short*)(&data_021015a0 + 0xa) = 1;
    *(int*)(&data_021015a0 + 0x48) = 0;
    *(int*)(&data_02101640 + 0x0) = 0;
    *(unsigned short*)(&data_02101640 + 0x4) = 0;

    VectorizedMemset(&data_02101b80, 0, 0x400);
    VectorizedMemset(&data_021016e0, 0, 0xc0);
    VectorizedMemset(&data_02101614, 0, 0x18);

    *(int*)(&data_021015a0 + 0x24) = 0;
    *(int*)(&data_021015a0 + 0x10) = 3;

    result = CallFunc020d4fa4Zero_020d4f7c((int)&data_02103400, (int)&PollField0x40OrSetState_0202db08, 2);
    if (result == 2) {
        ok = 1;
    } else {
        SetField0x48UnlessState9Or10_0202c848(result);
        *(int*)(&data_021015a0 + 0x10) = 0xa;
        ok = 0;
    }

    if (ok == 0) {
        ok = 0;
    } else {
        ok = 1;
        *(unsigned short*)(&data_021015a0 + 0xe) = ok;
    }

    return ok;
}
