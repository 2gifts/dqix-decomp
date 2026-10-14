#include <globaldefs.h>

struct Struct_203cdd8 {
    char pad[0x64];
    int value;
};

// USA: func_0203cdd8
ARM void SetField0x64RoundedTo256_0203cdd8(struct Struct_203cdd8* obj, int value) {
    int rounded = value & ~0xff;
    obj->value = value;
    if ((unsigned int)(value & 0xff) >= (unsigned int)-128) {
        rounded += 0x100;
    }
    obj->value = rounded;
}
