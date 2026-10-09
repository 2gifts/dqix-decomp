#include <globaldefs.h>

struct Source0203c05c {
    char pad[0x22];
    short f22;
};

struct Entry0203c05c {
    unsigned int w;
    unsigned short h;
    unsigned short pad;
};

void BuildPackedEntries0203c05c(struct Source0203c05c* p, struct Entry0203c05c* out,
                                int a3, int a4, int a5, int a6);

struct Sub0203c4d0 {
    unsigned char pad[0xc];
    unsigned int f0c;
    unsigned short f10;
};

struct Obj0203c4d0 {
    struct Entry0203c05c* f0;
    unsigned char pad[0x4fc];
    struct Sub0203c4d0 sub;
};

// USA: func_0203c4d0
extern "C" ARM void func_0203c4d0(void* arg0, short arg1, int arg2, int arg3, int arg4,
                                 int arg5) {
    struct Obj0203c4d0* p = (struct Obj0203c4d0*)arg0;
    int t;

    if (arg1 < 0) {
        return;
    }

    if (p->f0 == 0) {
        return;
    }

    t = (p->sub.f0c >> 5) + arg5;
    t = t & 0xf;

    BuildPackedEntries0203c05c(
        (struct Source0203c05c*)((char*)p + 4 + arg1 * 0x28),
        p->f0 + p->sub.f10,
        arg2, arg3, arg4,
        t & 0xf);

    p->sub.f10 = p->sub.f10 + 4;
    p->sub.f10 = p->sub.f10 & 0x7f;
}