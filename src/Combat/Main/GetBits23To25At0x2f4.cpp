#include <globaldefs.h>

// USA: func_02085748
ARM int GetBits23To25At0x2f4_02085748(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return (((unsigned int)*(int*)(obj + 0x2f4)) << 6) >> 29;
}
