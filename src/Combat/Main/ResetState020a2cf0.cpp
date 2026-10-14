#include <globaldefs.h>

extern "C" void func_0202df68(void*);
void SetBitsInField0_0202e08c(unsigned int*, unsigned int);

struct Struct020A2CF0 {
    char pad[0x218];
    int field218;
};

// USA: func_020a2cf0
ARM void ResetState020a2cf0(struct Struct020A2CF0* obj) {
    func_0202df68(obj);
    SetBitsInField0_0202e08c((unsigned int*)obj, 2);
    obj->field218 = 0;
}
