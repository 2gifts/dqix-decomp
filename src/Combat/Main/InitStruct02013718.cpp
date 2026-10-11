#include <globaldefs.h>

extern "C" void func_020134e0(void* obj);

// USA: func_02013718
ARM void InitStruct02013718(char* obj, int a, int b) {
    func_020134e0(obj);
#if defined(jpn)
    *(int*)(obj + 0x6c) = a;
#else
    *(int*)(obj + 0x4c) = a;
#endif
#if defined(jpn)
    *(int*)(obj + 0x70) = b;
#else
    *(int*)(obj + 0x50) = b;
#endif
#if defined(jpn)
    *(int*)(obj + 0x858) = 0;
#else
    *(int*)(obj + 0x838) = 0;
#endif
#if defined(jpn)
    *(int*)(obj + 0x85c) = 0;
#else
    *(int*)(obj + 0x83c) = 0;
#endif
#if defined(jpn)
    *(short*)(obj + 0x494) = 0;
#else
    *(short*)(obj + 0x474) = 0;
#endif
#if defined(jpn)
    *(int*)(obj + 0x84c) = 0;
#else
    *(int*)(obj + 0x82c) = 0;
#endif
}
