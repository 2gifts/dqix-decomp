#include <globaldefs.h>

// USA: func_020120b8
ARM int* GetNegativeEntry_020120b8(char* obj, int index) {
#if defined(jpn)
    int* arr = (int*)(obj + 0x5a7c);
#else
    int* arr = (int*)(obj + 0x5cdc);
#endif
    int* p = &arr[index];
    if (((unsigned int)*p >> 31) == 0) {
        p = 0;
    }
    return p;
}
