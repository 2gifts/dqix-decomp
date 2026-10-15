#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/MapDisplay.h"

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0205a198
void Init0205a198(Struct0205a198 *p) {
    memset(p, 0, 8);
    p->copy = 0;
    p->field0c = p->field10 = 0x1000;
    p->field14 = p->field18 = 0;
    p->field1c = 0;
    p->index = 0;
    p->field20 = 0;
    p->firstCell = 0;
    p->field23 = 0;
    p->field24 = 0;
    int d = p->field24 - 1;
    p->field25 = d;
    p->field26 = d;
}
