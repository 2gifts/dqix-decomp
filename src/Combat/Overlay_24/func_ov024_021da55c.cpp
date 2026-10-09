#include <globaldefs.h>

struct Pair_021da55c {
    unsigned int a;
    unsigned int b;
};
extern struct Pair_021da55c data_020e6d5c;

extern unsigned int data_ov024_02200140;

struct DispatchEntry_021da55c {
    unsigned int fn;
    unsigned int locator;
};
extern struct DispatchEntry_021da55c data_ov024_021ff1e0[0x43];

struct Action_021da55c {
    char unk_0[0x18];
    unsigned int unk_18_0 : 18;
    unsigned int handlerIndex : 9;
    unsigned int unk_18_27 : 5;
};

typedef int (*Handler_021da55c)(void* self, int a2, int a3, unsigned short a4, struct Action_021da55c* action, int fallback);

// USA: func_ov024_021da55c
extern "C" ARM int func_ov024_021da55c(int* obj, int a1, int a2, int a3, unsigned short a4, struct Action_021da55c* action, int fallback) {
    unsigned int flags = data_ov024_02200140;
    if (!(flags & 1)) {
        struct Pair_021da55c nullEntry = data_020e6d5c;
        data_ov024_021ff1e0[0].fn = nullEntry.a;
        data_ov024_021ff1e0[0].locator = nullEntry.b;
        data_ov024_021ff1e0[46].fn = nullEntry.a;
        data_ov024_021ff1e0[46].locator = nullEntry.b;
        data_ov024_021ff1e0[51].fn = nullEntry.a;
        data_ov024_021ff1e0[51].locator = nullEntry.b;
        data_ov024_021ff1e0[53].fn = nullEntry.a;
        data_ov024_021ff1e0[53].locator = nullEntry.b;
        data_ov024_02200140 = flags | 1;
    }
    *obj = a1;
    if (action == NULL) {
        return fallback;
    }
    unsigned int idx = action->handlerIndex;
    if (idx >= 0x43) {
        return fallback;
    }
    if (data_ov024_021ff1e0[idx].fn == 0) {
        return fallback;
    }
    struct DispatchEntry_021da55c* d = &data_ov024_021ff1e0[idx];
    void* base = (char*)obj + ((int)d->locator >> 1);
    Handler_021da55c callback;
    if (d->locator & 1) {
        callback = *(Handler_021da55c*)((char*)*(void**)base + d->fn);
    } else {
        callback = (Handler_021da55c)d->fn;
    }
    return callback(base, a2, a3, a4, action, fallback);
}
