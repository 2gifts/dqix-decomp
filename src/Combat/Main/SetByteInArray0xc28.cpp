#include <globaldefs.h>
// USA: func_0207c6a8
ARM void SetByteInArray0xc28_0207c6a8(unsigned char* base, unsigned int index, unsigned char value) {
    if (index <= 7) {
        *(base + index + 0xc28) = value;
    }
}
