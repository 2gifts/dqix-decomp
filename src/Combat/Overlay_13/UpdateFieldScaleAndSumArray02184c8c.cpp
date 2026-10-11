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

int GetFieldAt0x150(unsigned char* obj);

// USA: func_ov013_02184c8c  (semantic: UpdateFieldScaleAndSumArray02184c8c)
extern "C" ARM void func_ov013_02184c8c(unsigned char* obj, unsigned char* other) {
    if (other == 0 || *(unsigned char*)(obj + R(0x5ec,0x664)) == 0) return;

    unsigned char* fieldPtr = (unsigned char*)GetFieldAt0x150(other);
    *(unsigned short*)(fieldPtr + 0x564) = *(int*)(obj + R(0x5f4,0x66c));

    for (int i = 0; i < 5; i++) {
        unsigned char* bytePtr = obj + i;
        unsigned char idx = bytePtr[R(0x631,0x6a9)];
        int sum = *(int*)(obj + R(0x5fc,0x674) + i * 4) + *(int*)(obj + R(0x610,0x688) + i * 4);
        *(unsigned char*)(fieldPtr + idx + 0x464) = (unsigned char)sum;
    }
}
