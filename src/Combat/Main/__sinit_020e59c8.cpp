#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_020ef0dc[5];
extern float data_020fb3d0[5];
extern int data_020fb3f0;
extern int data_020fb3e4;

extern "C" ARM void func_0201c124(void);
extern "C" void __register_global_object(void* obj, void* func, void* node);
void* InitBigStruct0201c014(void* obj);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020e59c8
extern "C" __declspec(initcode) ARM void __sinit_020e59c8(void) {
    float t;
    float a;
    data_020fb3d0[1] = data_020ef0dc[1] + (data_020ef0dc[0] + (data_020ef0dc[2] + data_020ef0dc[4]));
    t = data_020fb3d0[2] + data_020ef0dc[2];
    a = data_020ef0dc[4];
    data_020fb3d0[4] = t;
    t = t + a;
    data_020fb3d0[0] = t;
    t = t + data_020ef0dc[0];
    data_020fb3d0[3] = t;
    InitBigStruct0201c014(&data_020fb3f0);
    __register_global_object(&data_020fb3f0, (void*)func_0201c124, &data_020fb3e4);
}
