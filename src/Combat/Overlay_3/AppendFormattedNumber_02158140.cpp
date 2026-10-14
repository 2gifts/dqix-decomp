#include <globaldefs.h>
#include "std_library_functions.h"

int StringLength_020d2ff0(const char* s);
extern char data_ov003_0217fce0;

struct Obj02158140 {
    char pad[0xc];
    char buf[0x38];
};

// USA: func_ov003_02158140
ARM void AppendFormattedNumber_02158140(struct Obj02158140* obj, int param1) {
    if (param1 == 0) return;
    memset(obj->buf, 0, 0x38);
    sprintf(obj->buf + StringLength_020d2ff0(obj->buf), &data_ov003_0217fce0, param1);
}
