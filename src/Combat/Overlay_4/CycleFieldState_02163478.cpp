#include <globaldefs.h>

struct MenuSelection {
#if defined(jpn)
    char unknown0[0x19fa];
#else
    char unknown0[0x18fa];
#endif
    unsigned char current;
    unsigned char previous;
};

// USA: func_ov004_02163478
extern "C" ARM void func_ov004_02163478(MenuSelection* selection) {
    selection->previous = selection->current;
    unsigned char current = selection->current;
    if (current == 0) { selection->current = 1; return; }
    if (current == 1) { selection->current = 2; return; }
    if (current == 2) { selection->current = 0; return; }
}
