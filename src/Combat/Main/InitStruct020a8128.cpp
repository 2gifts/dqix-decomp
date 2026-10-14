#include <globaldefs.h>

struct Struct0x10;
void ZeroStruct0x10_020a810c(struct Struct0x10*);

// USA: func_020a8128
ARM void InitStruct020a8128(unsigned char* obj) {
    obj[0] = 0;
    obj[1] = 0xff;
    obj[2] = 0;
    *(int*)(obj + 4) = 0;
    *(short*)(obj + 0x18) = 0;
    ZeroStruct0x10_020a810c((struct Struct0x10*)(obj + 8));
    *(short*)(obj + 0x1a) = 0;
    *(short*)(obj + 0x1c) = 0;
    *(int*)(obj + 0x20) = 0;
    *(int*)(obj + 0x24) = 0;
    *(int*)(obj + 0x28) = 0;
}
