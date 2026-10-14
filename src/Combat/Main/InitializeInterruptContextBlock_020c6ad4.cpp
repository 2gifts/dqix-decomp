#include <globaldefs.h>

struct InterruptContextBlock_027e0060 { int a; int b; };
extern InterruptContextBlock_027e0060 data_027e0060;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c6ad4
ARM void InitializeInterruptContextBlock_020c6ad4(void) {
    data_027e0060.b = 0;
    data_027e0060.a = 0;
}
