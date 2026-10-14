#include <globaldefs.h>

struct CallbackEntry020d2930 { void (*fn)(int); int arg; unsigned char count; };
extern struct CallbackEntry020d2930 data_02114260[8];

// USA: func_020d2930
ARM void ClearCallbackTable_020d2930() {
    int i = 0;
    struct CallbackEntry020d2930* e = data_02114260;
    do {
        e->fn = 0;
        e->arg = 0;
        e->count = 0;
        i++;
        e++;
    } while (i < 8);
}
