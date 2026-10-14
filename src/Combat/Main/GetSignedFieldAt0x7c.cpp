#include <globaldefs.h>

struct S_e820 {
    char pad[0x7c];
    short field7c;
};

// USA: func_0201e820
ARM int GetSignedFieldAt0x7c_0201e820(struct S_e820* p) {
    return p->field7c;
}
