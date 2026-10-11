#include <globaldefs.h>
#if defined(jpn)
#define func_0205b008 func_0205c3a4
#endif

extern "C" int func_0205b008(int a, void* b, int c, int d, int e, int f);

// USA: func_0205af38
ARM void SetBitfieldStoreBytes0205af38(int a, char* obj, int c, int d) {
    if (obj != 0) {
        if (func_0205b008(a, obj, 0, 0x300, 8, c | (((unsigned int)d << 17) >> 16)) == 0) {
            obj[0x23] = (char)c;
            obj[0x24] = (char)d;
        }
    }
}
