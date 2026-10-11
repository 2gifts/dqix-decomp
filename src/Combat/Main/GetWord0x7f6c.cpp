#include <globaldefs.h>

// USA: func_0201201c
ARM int GetWord0x7f6c(void* obj) {
    unsigned char* base = (unsigned char*)obj;
#if defined(jpn)
    return *(int*)(base + 0x7c98);
#else
    return *(int*)(base + 0x7f6c);
#endif
}
