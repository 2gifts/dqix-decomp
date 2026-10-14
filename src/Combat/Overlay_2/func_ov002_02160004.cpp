#include <globaldefs.h>

struct Container020e0310;

int GetFieldByKey020e0434(struct Container020e0310 *c, int key);
int AppendString02042058(char *dst, const char *src);

struct S {
    char pad[0x6c];
    int id;
    int cur;
};

// USA: func_ov002_02160004
extern "C" ARM void func_ov002_02160004(char *p, char *dst) {
    if (dst == NULL) {
        return;
    }

    struct S *s = (struct S *) (p + 0x2c8 + 0xc00);
    int *q      = &s->id;
    short cur   = q[1];
    short id    = q[0];
    if (cur == *(signed char *) (p + 0x1c00 + 0x73)) {
        return;
    }

    int name = GetFieldByKey020e0434((struct Container020e0310 *) (p + 0x20), (short) (id + 0xfbe));
    AppendString02042058(dst, (const char *) name);
}
