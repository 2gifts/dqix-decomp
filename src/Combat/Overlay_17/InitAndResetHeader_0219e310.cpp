#include <globaldefs.h>
#include "System/Memory.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);

// USA: func_ov017_0219e310
ARM void InitAndResetHeader_0219e310(unsigned char* obj, int flag) {
    ResetByteHeader((ByteHeader0204693c*)obj);
    obj[0x0] = 3;
    obj[0x8] = 0;
    obj[0x9] = 0;
    obj[0xa] = 1;
    obj[0xb] = 0;
    obj[0xc] = 0;
    *(short*)(obj + 0xe) = 0;
    *(short*)(obj + 0x10) = 0;
    obj[0x20] = 0;
    *(short*)(obj + 0x22) = 0;
    *(short*)(obj + 0x24) = 0;
#if !defined(jpn)
    *(int*)(obj + 0x28) = 0;
#endif
    short v = *(short*)(obj + 0x12);
    if (v != 0) {
        if (flag == 0) return;
    }
    VectorizedMemset(obj + 0x12, 0, 0xe);
}
