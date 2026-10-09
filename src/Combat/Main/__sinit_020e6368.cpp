#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_020f1708[8];
extern float data_02109bcc[8];

extern "C" void _Z21BlankFunction0209cdf8v(void);
extern "C" void _Z31ResetWordListReturnSelf0209ce00P16WordList0209cbb8(void* list);
ARM void BlankFunction0209cdfc(void);
extern "C" void __register_global_object(void* obj, void* func, void* node);

extern int data_02109bf4;
extern int data_02109be8;
extern int data_02109be0;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020e6368
extern "C" __declspec(initcode) ARM void __sinit_020e6368(void) {
    float t;
    float a;
    data_02109bcc[1] = data_020f1708[0] + (data_020f1708[1] + (data_020f1708[2] + data_020f1708[3]));
    t = data_02109bcc[0] + data_020f1708[2];
    a = data_020f1708[3];
    data_02109bcc[4] = t;
    t = t + a;
    data_02109bcc[3] = t;
    t = t + data_020f1708[1];
    data_02109bcc[2] = t;
    ((void(*)(void*))_Z21BlankFunction0209cdf8v)(&data_02109bf4);
    __register_global_object(&data_02109bf4, (void*)BlankFunction0209cdfc, &data_02109be8);
    _Z31ResetWordListReturnSelf0209ce00P16WordList0209cbb8(&data_02109be0);
}