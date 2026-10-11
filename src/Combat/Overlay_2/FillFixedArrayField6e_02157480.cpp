#include <globaldefs.h>
#if defined(jpn)
#define LIST_BASE 0x1b00
#define LIST_COUNT 0x37
#define LIST_DATA 0x32
#else
#define LIST_BASE 0x1c00
#define LIST_COUNT 0x73
#define LIST_DATA 0x6e
#endif

// USA: func_ov002_02157480  (semantic: FillFixedArrayField6e_02157480)
extern "C" ARM void func_ov002_02157480(void* obj, int* arr) {
    if (arr == NULL) return;
    for (int j = 0; j < 4; j++) arr[j] = -1;
    int i = 0;
    while (i < *((signed char*)obj + LIST_BASE + LIST_COUNT)) {
        arr[i] = *((signed char*)obj + i + LIST_BASE + LIST_DATA);
        i++;
    }
}
