#include <globaldefs.h>
#include "std_library_functions.h"

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Buf021d0ef8 {
    unsigned char f0;
    unsigned char f1;
    unsigned char len : 7;
    unsigned char notClamped : 1;
    unsigned char data[12];
};

struct Msg021d0ef8 {
    unsigned char tag;
    unsigned char pad[3];
    Buf021d0ef8 buf;
};

// USA: func_ov017_021d0ef8
extern "C" ARM void func_ov017_021d0ef8(int a1, unsigned char* a2, int a3, int a4, int* outLen) {
    void* data = GetData02100044_0202ae24();

    Msg021d0ef8 msg;
    Buf021d0ef8* buf = &msg.buf;
    buf->f0 = (unsigned char)a1;
    msg.tag = 0xab;
    int len = a3 - a4;

    *outLen = len;
    if (len > 12) {
        *outLen = 12;
    } else {
        buf->notClamped = 1;
    }
    buf->len = (unsigned char)*outLen;
    buf->f1 = (unsigned char)a4;
    memcpy(buf->data, a2 + a4, *outLen);

    func_0205e330(data, &msg, 0);
}
