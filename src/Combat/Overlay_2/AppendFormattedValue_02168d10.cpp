#include <globaldefs.h>
#include "std_library_functions.h"

int StringLength_020d2ff0(const char* s);
extern char data_ov002_0216d2fc[];

// USA: func_ov002_02168d10
ARM void AppendFormattedValue_02168d10(unsigned char* obj, int val) {
    if (val == 0) {
        return;
    }
    memset(obj + 0xc, 0, 0x38);
    int len = StringLength_020d2ff0((const char*)(obj + 0xc));
    sprintf((char*)(obj + 0xc) + len, data_ov002_0216d2fc, val);
}
