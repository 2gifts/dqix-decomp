#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct _Z20InitDefaults0208e9f4P14Struct0208e9f4;
struct Struct0208e9f4;
ARM void* InitAndReturnSelf0208f4bc(Struct0208e9f4*);
ARM void* InitAndReturnSelf0208f4d0(void* obj);

extern "C" void __register_global_object(int c, int b, void* node);

extern _Z20InitDefaults0208e9f4P14Struct0208e9f4 data_02109020;
extern int data_02109014;

// USA: func_020e62b4
extern "C" __declspec(initcode) ARM void __sinit_020e62b4(void) {
    InitAndReturnSelf0208f4bc((Struct0208e9f4*)&data_02109020);
    __register_global_object((int)&data_02109020, (int)InitAndReturnSelf0208f4d0, &data_02109014);
}
