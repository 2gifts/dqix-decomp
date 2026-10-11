#include <globaldefs.h>

ARM int IsChecksumValid_022006a0(void*, unsigned int, void*, unsigned int);
ARM int FindAndRescheduleContext_02202810(int, int);
struct Header0220225c;
extern "C" void func_ov031_0220225c(Header0220225c*, void*, int);
extern "C" void func_ov031_02202334(int, int, int);
extern "C" void func_ov031_0220242c(int, int, int);
extern "C" void func_ov031_02202744(int, int, int);
extern "C" int func_ov031_02201fac(int, int, int, int);

struct Buf0220284c { unsigned char pad[0xc]; unsigned char byte0xc; unsigned char byte0xd; };

// USA: func_ov031_0220284c  (semantic: DispatchByFlagsNibbleAndCode_0220284c)
extern "C" ARM void func_ov031_0220284c(void* c, Buf0220284c* buf, int len) {
    if (IsChecksumValid_022006a0(buf, len, c, 6)) return;

    int v = buf->byte0xc & 0xf0;
    len -= v / 4;
    int code = buf->byte0xd & 0x17;

    if (code <= 0x10) {
        if (code >= 0x10) goto handlerA;
        if (code > 0x2) goto fallback;
        if (code < 0x1) goto fallback;
        if (code == 0x1) goto case1;
        if (code == 0x2) goto case2;
        goto fallback;
    } else {
        if (code > 0x12) goto fallback;
        if (code < 0x11) goto fallback;
        if (code == 0x11) goto handlerA;
        if (code == 0x12) goto case0x12;
        goto fallback;
    }

case2:
    if (buf->byte0xd & 0x28) return;
    func_ov031_0220225c((Header0220225c*)c, buf, len);
    return;

case0x12:
    if (buf->byte0xd & 0x28) return;
    func_ov031_02202334((int)c, (int)buf, len);
    return;

handlerA:
    func_ov031_0220242c((int)c, (int)buf, len);
    return;

case1:
    func_ov031_02202744((int)c, (int)buf, len);
    return;

fallback:
    if (buf->byte0xd & 0x4) {
        FindAndRescheduleContext_02202810((int)c, (int)buf);
    } else {
        func_ov031_02201fac((int)c, (int)buf, len, 0);
    }
}
