#include <globaldefs.h>

struct Container020e0310;

extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310 *c, int key);
extern "C" int _Z20AppendString02042058PcPKc(char *dst, const char *src);

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

    int name = _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (p + 0x20), (short) (id + 0xfbe));
    _Z20AppendString02042058PcPKc(dst, (const char *) name);
}
