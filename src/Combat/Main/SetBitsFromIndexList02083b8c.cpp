#include <globaldefs.h>

void SetBitInArray0x910(unsigned char* obj, int index);

#if defined(jpn)
#define SetBitsFromIndexList02083b8c func_020844a0
extern "C" ARM void func_020844a0(unsigned char* obj, unsigned char* list, unsigned int count);
#endif

// USA: func_02083b8c
ARM void SetBitsFromIndexList02083b8c(unsigned char* obj, unsigned char* list, unsigned int count) {
    unsigned int i;
    for (i = 0; i < count; i++) {
        SetBitInArray0x910(obj, list[i]);
    }
}
