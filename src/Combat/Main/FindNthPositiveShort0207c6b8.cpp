#include <globaldefs.h>

void* GetPointerFromArray0xbd0_0207c5f8(unsigned char* obj, unsigned int index);
signed short GetShortFromArray0xc10_0207c620(unsigned char* obj, unsigned int index);

// USA: func_0207c6b8
ARM int FindNthPositiveShort0207c6b8(unsigned char* obj, unsigned int index, int target) {
    signed short* arr = (signed short*)GetPointerFromArray0xbd0_0207c5f8(obj, index);
    if (arr == NULL) {
        return -1;
    }
    signed short j;
    j = 0;
    int count = GetShortFromArray0xc10_0207c620(obj, index);
    for (unsigned int i = 0; i < (unsigned int)count; i++) {
        signed short v = *arr;
        if (v > 0) {
            if (target == j) {
                return v;
            }
            j++;
        }
        arr++;
    }
    return -1;
}
