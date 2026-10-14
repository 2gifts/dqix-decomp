#include <globaldefs.h>
#pragma define_section initcode ".init" RX

void InitTwoSubObjectsWithCallbacks0203a878(void* obj);
class Container0203a54c;
void InitSubObjectArraysReturnSelf_0203a8d4(Container0203a54c* obj);

struct Node0200efd0 {
    struct Node0200efd0* next;
    int b;
    int c;
};

extern "C" void __register_global_object(int c, int b, struct Node0200efd0* node);

extern int data_02104b6c;
extern struct Node0200efd0 data_02104b60;

// USA: func_020e5c00  (semantic: InitEntries020e5c00)
extern "C" __declspec(initcode) ARM void __sinit_020e5c00(void) {
    InitTwoSubObjectsWithCallbacks0203a878(&data_02104b6c);
    __register_global_object((int)&data_02104b6c, (int)InitSubObjectArraysReturnSelf_0203a8d4, &data_02104b60);
}
