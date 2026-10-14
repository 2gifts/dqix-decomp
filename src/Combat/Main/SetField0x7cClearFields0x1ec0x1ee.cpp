#include <globaldefs.h>

// USA: func_0202e874
ARM void SetField0x7cClearFields0x1ec0x1ee_0202e874(unsigned char* obj, unsigned short val) {
    *(unsigned short*)(obj + 0x7c) = val;
    *(unsigned short*)(obj + 0x1ec) = 0;
    *(unsigned short*)(obj + 0x1ee) = 0;
}
