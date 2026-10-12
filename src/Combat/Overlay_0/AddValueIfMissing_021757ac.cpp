#include <globaldefs.h>

struct Struct0217f8c0 {
    char pad0[0x10];
    unsigned short values[5];
    signed char count;
};

// USA: func_ov000_021757ac  (semantic: AddValueIfMissing_021757ac)
extern "C" ARM void func_ov000_021757ac(Struct0217f8c0* self, unsigned short value) {
    int found = 0;
    unsigned short* values = self->values;
    signed char i;
    signed char count = self->count;
    for (i = 0; i < count; i++) {
        if (value == values[i]) {
            found = 1;
        }
    }
    if (!found) {
        values[self->count++] = value;
    }
}
