#include <globaldefs.h>

struct UpdateStateStruct;

unsigned char* GetElementStride0x24(unsigned char* p, int i);
void UpdateActivationState(UpdateStateStruct* p, int h, int i1, int i2);
extern "C" void* func_02012fe4(void* self);

struct Obj021cfda0 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned char field8;
};

// USA: func_ov017_021cfda0
ARM void UpdateActivationIfMatch_021cfda0(void* self, Obj021cfda0* obj) {
    unsigned char* ptr = (unsigned char*)func_02012fe4(self);
    if (obj->field4 != *(unsigned short*)ptr) return;
    unsigned char* stride = GetElementStride0x24(ptr, obj->field6);
    if (!stride) return;
    UpdateActivationState((struct UpdateStateStruct*)stride, obj->field8, 0, 0);
}
