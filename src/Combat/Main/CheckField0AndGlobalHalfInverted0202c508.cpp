#include <globaldefs.h>

unsigned short GetGlobalHalf0x0_0202df58(void);

struct CheckField0AndGlobalHalfStruct0202c508 { int field0; };

// USA: func_0202c508  (semantic: CheckField0AndGlobalHalfInverted0202c508)
extern "C" ARM int func_0202c508(CheckField0AndGlobalHalfStruct0202c508* obj) {
    int cond = obj->field0 != 0;
    if (cond) {
        return GetGlobalHalf0x0_0202df58() == 0;
    }
    return 1;
}
