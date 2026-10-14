#include <globaldefs.h>

int TestFlagMask_02012430(unsigned short* obj, int mask);
extern unsigned short data_02114e30;

extern "C" int func_02075910(int a0, void* out, int a1, int a2);
extern "C" int func_01ff85b8(void* buf, int size);

struct Buf020ab9c0 {
    int hdr;
    unsigned char b4;
    unsigned char b5;
    char pad[14];
};

// USA: func_020ab9c0
ARM int CheckSaveBufferStatus_020ab9c0(int flag) {
    int id = flag ? 0x8010 : 0x10;
    if (TestFlagMask_02012430(&data_02114e30, 0x2000)) {
        return 2;
    }

    struct Buf020ab9c0 buf;
    if (!func_02075910(id, &buf, 0x14, 0)) {
        return 1;
    }
    void* p = &buf;
    if (func_01ff85b8((char*)p + 4, 0x10) != buf.hdr) {
        return 2;
    }
    if (buf.b5 == 0) {
        return 3;
    }
    return (buf.b4 == 1) ? 4 : 0;
}
