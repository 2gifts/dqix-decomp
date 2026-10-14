#include <globaldefs.h>

struct SetIntIntShortAt0xcStruct {
    char pad[0xc];
    int a;
    int b;
    short c;
};

// USA: func_02066ce0
ARM void SetIntIntShortAt0xc_02066ce0(struct SetIntIntShortAt0xcStruct* s, int a, int b, short c) {
    s->a = a;
    s->b = b;
    s->c = c;
}
