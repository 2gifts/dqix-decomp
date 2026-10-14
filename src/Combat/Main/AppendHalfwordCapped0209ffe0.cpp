#include <globaldefs.h>

struct S_9ffe0 {
    char pad[0x68];
    short count;
    unsigned short items[0x32];
};

// USA: func_0209ffe0
ARM void AppendHalfwordCapped0209ffe0(S_9ffe0* s, short value) {
    short count = s->count;
    if (count < 0x32) {
        s->count = count + 1;
        s->items[count] = value;
    }
}
