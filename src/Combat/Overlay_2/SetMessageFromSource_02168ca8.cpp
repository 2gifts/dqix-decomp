#include <globaldefs.h>
#include "std_library_functions.h"

extern int StringLength_020d2ff0(const char* s);
extern char data_ov002_0216d2fc[];

struct CopySrc02168ca8 { int a; char* b; int c; };
struct MsgBuf02168ca8 {
    int a;
    char* b;
    int c;
    char pad[0x38];
#if defined(jpn)
    char buf[0x118];
#else
    char buf[0x200];
#endif
};

// USA: func_ov002_02168ca8  (semantic: SetMessageFromSource_02168ca8)
extern "C" ARM void func_ov002_02168ca8(MsgBuf02168ca8* dst, CopySrc02168ca8* src) {
    if (src == 0) return;
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->b = dst->buf;
    const char* text = src->b;
    if (text == 0) return;
    memset(dst->buf, 0, sizeof(dst->buf));
    sprintf(dst->buf + StringLength_020d2ff0((const char*)dst->buf), data_ov002_0216d2fc, text);
}
