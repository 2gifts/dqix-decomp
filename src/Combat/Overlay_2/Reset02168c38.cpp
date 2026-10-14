#include <globaldefs.h>
#include "std_library_functions.h"

struct Foo02168c38 {
    unsigned int a;
    void* ptr;
    unsigned int c;
    char pad[0x38];
#if defined(jpn)
    char buf[0x118];
#else
    char buf[0x200];
#endif
};

// USA: func_ov002_02168c38
ARM void Reset02168c38(struct Foo02168c38* dst) {
    dst->a &= ~0x1ff;
    dst->a &= 0xfffc01ff;
    dst->a &= 0xf803ffff;
    dst->a &= ~0x38000000;
    dst->a &= ~0xc0000000;
    dst->ptr = NULL;
    dst->c = 0;
    memset(dst->pad, 0, 0x38);
    memset(dst->buf, 0, sizeof(dst->buf));
    dst->ptr = dst->buf;
}
