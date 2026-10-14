#include <globaldefs.h>

extern char data_021015a0;
void SetField0x48UnlessState9Or10_0202c848(int);

// USA: func_0202d614
ARM void SetState9DispatchOrInvokeCallback_0202d614(unsigned short* obj) {
    void (*cb)(unsigned short*);
    if (obj[1] != 0) {
        *(int*)(&data_021015a0 + 0x10) = 9;
        SetField0x48UnlessState9Or10_0202c848(obj[1]);
        return;
    }
    cb = *(void (**)(unsigned short*))(&data_021015a0 + 0x18);
    if (cb != NULL) cb(obj);
    *(int*)(&data_021015a0 + 0x10) = 1;
}
