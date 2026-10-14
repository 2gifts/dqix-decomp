#include <globaldefs.h>
int SetBattleContextField0xc8IfIdle_020d472c(void*);

extern char data_021015a0;
void SetField0x48UnlessState9Or10_0202c848(int);

// USA: func_0202db08
ARM void PollField0x40OrSetState_0202db08(unsigned short* obj) {
    int r;
    if (obj[1] != 0) {
        SetField0x48UnlessState9Or10_0202c848(obj[1]);
        *(int*)(&data_021015a0 + 0x10) = 0xa;
        return;
    }
    r = SetBattleContextField0xc8IfIdle_020d472c((void*)(*(int*)(&data_021015a0 + 0x40)));
    if (r == 0) {
        *(int*)(&data_021015a0 + 0x10) = 1;
        return;
    }
    SetField0x48UnlessState9Or10_0202c848(r);
    *(int*)(&data_021015a0 + 0x10) = 0xa;
}
