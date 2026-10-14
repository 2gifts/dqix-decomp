#include <globaldefs.h>

struct CallbackEntry020d2980 { void (*fn)(int); int arg; unsigned char count; };
extern struct CallbackEntry020d2980 data_02114260[];

// USA: func_020d2980
ARM unsigned char RegisterCallbackEntry_020d2980(int idx, void (*fn)(int), int arg) {
    struct CallbackEntry020d2980* e = &data_02114260[idx];
    e->fn = fn;
    e->arg = arg;
    return ++e->count;
}
