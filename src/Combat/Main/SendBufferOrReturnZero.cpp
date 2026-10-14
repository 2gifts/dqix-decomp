#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_02075910(int a0, void* out, int a1, int a2);
extern "C" int func_01ff85b8(void* buf, int size);
extern "C" void func_02075acc(int id, void* buf, int size, int flag);

struct Buf020abae8 {
    int hdr;
    char data[0x50];
};

// USA: func_020abae8
ARM int SendBufferOrReturnZero_020abae8(int flag) {
    int local0;
    if (!func_02075910(0, &local0, 1, 0)) return 0;

    struct Buf020abae8 buf;
    memset(&buf, 0, 0x54);
    buf.hdr = func_01ff85b8((char*)&buf + 4, 0x50);
    func_02075acc(flag ? 0x8024 : 0x24, &buf, 0x54, 0);
    return 1;
}
