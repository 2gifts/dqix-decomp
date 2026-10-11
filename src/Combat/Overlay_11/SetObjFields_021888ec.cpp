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

extern "C" void func_ov017_021d4cc0(void* obj, void* a, int b);
extern int data_ov011_021889a0;

// USA: func_ov011_021888ec
ARM void SetObjFields_021888ec(void* obj) {
    func_ov017_021d4cc0(obj, &data_ov011_021889a0, R(0x6f,0x73));
}
