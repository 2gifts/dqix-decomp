#include <globaldefs.h>

struct Struct_02026f08 {
    char pad[0x558];
    unsigned char flag;
};

// USA: func_02026f08
ARM void SetBoolFlagAt558_02026f08(unsigned char* base, int index, int value) {
    ((struct Struct_02026f08*)(base + index))->flag = value != 0;
}
