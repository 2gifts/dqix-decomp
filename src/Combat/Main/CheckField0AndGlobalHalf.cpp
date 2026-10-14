#include <globaldefs.h>

unsigned short GetGlobalHalf0x0_0202df58(void);

struct CheckField0AndGlobalHalfStruct { int field0; };

// USA: func_0202c540  (semantic: CheckField0AndGlobalHalf)
extern "C" ARM int func_0202c540(CheckField0AndGlobalHalfStruct* obj) {
    int cond = obj->field0 != 0;
    if (cond) {
        return GetGlobalHalf0x0_0202df58() != 0;
    }
    return 0;
}
