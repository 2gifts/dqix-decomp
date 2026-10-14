#include <globaldefs.h>

struct ClearFields0And8And0x20Struct {
    int field0;
    int field4;
    int field8;
    char padc[0x14];
    int field20;
};

// USA: func_020c93bc
ARM void ClearFields0And8And0x20_020c93bc(struct ClearFields0And8And0x20Struct* p) {
    p->field0 = 0;
    p->field8 = 0;
    p->field20 = 0;
}
