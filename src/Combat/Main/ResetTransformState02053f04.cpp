#include <globaldefs.h>
#include "System/Matrix.h"

#if defined(jpn)
enum { scalarFieldOffset = 0x150, firstVectorOffset = 0x154, secondVectorOffset = 0x160, defaultValueIndex = 4 };
#else
enum { scalarFieldOffset = 0x15c, firstVectorOffset = 0x160, secondVectorOffset = 0x16c, defaultValueIndex = 1 };
#endif

extern "C" void __clear(void* buf, int n);
extern int data_020f0420[];

// USA: func_02053f04
ARM void ResetTransformState02053f04(void* obj) {
    Vector3i buf;
    __clear(&buf, 0xc);
    *(int*)((char*)obj + scalarFieldOffset) = data_020f0420[defaultValueIndex];
    *(Vector3i*)((char*)obj + firstVectorOffset) = buf;
    *(Vector3i*)((char*)obj + secondVectorOffset) = buf;
}
