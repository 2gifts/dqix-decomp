#include <globaldefs.h>

struct CallbackEntry020d2960 { void (*fn)(int); int arg; unsigned char count; };
extern struct CallbackEntry020d2960 data_02114260[];

// USA: func_020d2960
ARM void IncrementCallbackCount_020d2960(int idx) {
    struct CallbackEntry020d2960* e = &data_02114260[idx];
    e->count++;
}
