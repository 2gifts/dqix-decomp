#if defined(jpn)
#define R(j,u) (j)
#define _Z23EmptyDestructor0205cb60Pv func_0205deb8
#define _Z25ResetDisplayState02155480P11Obj02155480 func_ov006_02156b68
#define data_ov011_021889a0 data_ov011_02189700
#define data_ov013_02187dd8 data_ov013_02188cf0
#define func_ov006_02154fe4 func_ov006_02156730
#define func_ov006_021570fc func_ov006_02158704
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void func_ov005_02155544(void* self);

// USA: func_ov005_021551d4  (semantic: Trans_021551d4)
extern "C" ARM void func_ov005_021551d4(void* p) {
    char* self = (char*)p;
    func_ov005_02155544(self);
    *(unsigned int*)(self + R(0x3d44,0x3dcc)) |= 0x20;
    *(unsigned char*)(self + R(0x3d21,0x3da9)) = 0;
}
