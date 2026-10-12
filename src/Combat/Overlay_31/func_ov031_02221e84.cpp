#include <globaldefs.h>

struct Md5Ctx02221e84 {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
};

// USA: func_ov031_02221e84
extern "C" THUMB void func_ov031_02221e84(Md5Ctx02221e84* p) {
    p->f = 0;
    p->e = 0;
    p->a = 0x67452301;
    p->b = 0xefcdab89;
    p->c = 0x98badcfe;
    p->d = 0x10325476;
}