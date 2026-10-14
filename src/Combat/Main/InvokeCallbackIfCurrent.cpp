#include <globaldefs.h>

struct CallbackEntry020d29b0 { void (*fn)(int); int arg; unsigned char count; };
extern struct CallbackEntry020d29b0 data_02114260[];

// USA: func_020d29b0
ARM void InvokeCallbackIfCurrent_020d29b0(int packed) {
    struct CallbackEntry020d29b0* e = &data_02114260[packed & 0xff];
    if (((packed >> 8) & 0xff) != e->count) return;
    if (e->fn == 0) return;
    e->fn(e->arg);
}
