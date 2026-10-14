#include <globaldefs.h>

// USA: func_02089194
ARM void ClearFlag0x800AndBytes7cAnd9f_02089194(unsigned char* obj) {
    ((int*)obj)[6] &= ~0x800;
    obj[0x7c] = 0;
    obj[0x9f] = 0;
}
