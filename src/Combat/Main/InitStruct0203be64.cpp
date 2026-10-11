#include <globaldefs.h>

#if defined(jpn)
extern "C" void func_0203b8e4(char* obj);
#define InitStruct0203be8c func_0203b8e4
#else
void InitStruct0203be8c(char* obj);
#endif

// USA: func_0203be64
ARM char* InitStruct0203be64(char* obj) {
    InitStruct0203be8c(obj);
    return obj;
}
