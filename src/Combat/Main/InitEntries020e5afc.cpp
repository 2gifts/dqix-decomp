#include <globaldefs.h>
#pragma define_section initcode ".init" RX

struct __register_global_object {
    struct __register_global_object* next;
    int b;
    int c;
};

void* InitObjectWithCallbacks02028c8c(void* obj);
void* InitObjectArray02028d2c(void* obj);
extern "C" ARM void __register_global_object(int c, int b, struct __register_global_object* node);

extern void* data_020fdd44;
extern void* data_020fdd38;

// USA: func_020e5afc
extern "C" __declspec(initcode) ARM void __sinit_020e5afc(void) {
    InitObjectWithCallbacks02028c8c(&data_020fdd44);
    __register_global_object((int)&data_020fdd44, (int)InitObjectArray02028d2c, (struct __register_global_object*)&data_020fdd38);
}
