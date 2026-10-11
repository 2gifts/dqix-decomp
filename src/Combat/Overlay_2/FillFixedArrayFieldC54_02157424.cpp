#include <globaldefs.h>
#if defined(jpn)
#define LIST_COUNT 0xb14
#define LIST_DATA 0xb18
#else
#define LIST_COUNT 0xc50
#define LIST_DATA 0xc54
#endif

// USA: func_ov002_02157424  (semantic: FillFixedArrayFieldC54_02157424)
extern "C" ARM void func_ov002_02157424(void* obj, int* arr) {
    if (arr == NULL) return;
    for (int j = 0; j < 7; j++) arr[j] = -1;
    arr[0] = 4;
    int i = 0;
    while (i < *(int*)((char*)obj + 0x1000 + LIST_COUNT)) {
        int v = *(int*)((char*)obj + i * 4 + 0x1000 + LIST_DATA);
        i++;
        arr[i] = v;
    }
}
