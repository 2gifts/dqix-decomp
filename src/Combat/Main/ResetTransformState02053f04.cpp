#include <globaldefs.h>

#if defined(jpn)
enum { scalarFieldOffset = 0x150, firstVectorOffset = 0x154, secondVectorOffset = 0x160, defaultValueIndex = 4 };
#else
enum { scalarFieldOffset = 0x15c, firstVectorOffset = 0x160, secondVectorOffset = 0x16c, defaultValueIndex = 1 };
#endif

extern "C" void __clear(void* buf, int n);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern int data_020f0420[];

// USA: func_02053f04
ARM void ResetTransformState02053f04(void* obj) {
    int buf[3];
    __clear(buf, 0xc);
    *(int*)((char*)obj + scalarFieldOffset) = data_020f0420[defaultValueIndex];
    _ZN8Vector3iaSERKS_((int*)((char*)obj + firstVectorOffset), buf);
    _ZN8Vector3iaSERKS_((int*)((char*)obj + secondVectorOffset), buf);
}
