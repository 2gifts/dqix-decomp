#include <globaldefs.h>

// USA: func_0202053c
ARM unsigned short GetTableValue(void* obj) {
#if defined(jpn)
    char* p = *(char**)((char*)obj + 0x144);
#else
    char* p = *(char**)((char*)obj + 0x150);
#endif
#if defined(jpn)
    int index = *(int*)(p + 0x8b8);
#else
    int index = *(int*)(p + 0x950);
#endif
    return *(unsigned short*)(p + index * 2 + 0x16c);
}
