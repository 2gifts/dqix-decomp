#include <globaldefs.h>

// USA: func_02012078
ARM int GetWord0x71f8_02012078(void* obj) {
    return *(int*)((unsigned char*)obj + 0x7000 + 0x1f8);
}
