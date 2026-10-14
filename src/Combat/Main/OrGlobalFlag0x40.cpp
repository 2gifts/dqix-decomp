#include <globaldefs.h>

unsigned int* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0_020466e4(unsigned int* p, unsigned int mask);

// USA: func_020dc2bc
ARM void OrGlobalFlag0x40_020dc2bc(void) {
    OrBitsIntoField0_020466e4(GetDataPtr02114e04_020d6c00(), 0x40);
}
