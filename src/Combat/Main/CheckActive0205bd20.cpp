#include <globaldefs.h>

extern char data_02114e54;

struct Struct_0205bd20 {
    char pad[0x4c];
    unsigned char field4c;
    unsigned char field4d;
    unsigned char field4e;
};

// USA: func_0205bd20
ARM int CheckActive0205bd20(struct Struct_0205bd20* s, int key) {
    int result = 0;
    if (*(unsigned char*)(&data_02114e54 + 0x55) != 0 && s->field4e == 1 && s->field4c != 0) {
        result = 1;
    }
    return result;
}
