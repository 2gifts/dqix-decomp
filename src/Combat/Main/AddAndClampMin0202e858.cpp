#include <globaldefs.h>

int UpdateScaledField0x74_0202e808(void*, int);

// USA: func_0202e858
ARM int AddAndClampMin0202e858(void* obj, int n) {
    int base = *(int*)((char*)obj + 0x78);
    n += base;
    if (n < 0x1000) n = 0x1000;
    return UpdateScaledField0x74_0202e808(obj, n);
}
