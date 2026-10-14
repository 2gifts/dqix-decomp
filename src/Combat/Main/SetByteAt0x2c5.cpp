#include <globaldefs.h>

struct ByteField0x2c5_020a2cbc {
    char pad[0x2c5];
    unsigned char field;
};

// USA: func_020a2cbc
ARM void SetByteAt0x2c5(ByteField0x2c5_020a2cbc* obj, int value) {
    obj->field = value;
}
