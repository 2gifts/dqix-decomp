#include <globaldefs.h>

extern unsigned char data_02114e54;
void SelectCoordsByFlag0x24_02012a84(unsigned char*, int*, int*);
extern "C" int func_0205bd78(void* p, int b, int c);

// USA: func_0205bea0
ARM int CheckByteFlagAndInvoke0205bea0(void* p) {
    if ((&data_02114e54)[0x55] != 0) {
        int v1;
        int v2;
        SelectCoordsByFlag0x24_02012a84(&data_02114e54, &v1, &v2);
        return (func_0205bd78(p, v1, v2) >= 0) ? 1 : 0;
    }
    return 0;
}
