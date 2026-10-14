#include <globaldefs.h>

// USA: func_0202e5c8
ARM void SetFields0x10To0x18_0202e5c8(unsigned char* obj, int a, int b, int c) {
    *(int*)(obj + 0x10) = a;
    *(int*)(obj + 0x14) = b;
    *(int*)(obj + 0x18) = c;
}
