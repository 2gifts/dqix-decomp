#include <globaldefs.h>

struct S_e828 {
    char pad[0x7e];
    short field7e;
};

// USA: func_0201e828
ARM void SetFieldAt0x7e(S_e828* p, unsigned short v) {
    p->field7e = v;
}
