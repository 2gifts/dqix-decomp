#include <globaldefs.h>

struct Callback020ce240 { unsigned char pad[0x1c]; int lock; void (*fn)(int, int); int arg; };
extern struct Callback020ce240 data_021117ec;

// USA: func_020ce240
ARM void FirePendingCallback_020ce240(int a) {
    void (*fn)(int, int);
    int arg;
    fn = data_021117ec.fn;
    arg = data_021117ec.arg;
    data_021117ec.lock = 0;
    if (fn == NULL) {
        return;
    }
    data_021117ec.fn = NULL;
    fn(a, arg);
}
