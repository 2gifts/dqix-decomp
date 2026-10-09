#include <globaldefs.h>

struct ByteStack0215fb04 {
    unsigned char pad[0x8e44];
    unsigned char data[3];
    unsigned char count;
};

// USA: func_ov000_0215fb04
extern "C" ARM void func_ov000_0215fb04(struct ByteStack0215fb04* obj, unsigned char val) {
    unsigned char* src = obj->data;
    unsigned char* dst = src;
    int kept = 0;
    for (int i = 0; i < obj->count; src++, i++) {
        unsigned char b = *src;
        if (b != val) {
            *dst = b;
            dst++;
            kept++;
        }
    }
    obj->count = kept;
}
