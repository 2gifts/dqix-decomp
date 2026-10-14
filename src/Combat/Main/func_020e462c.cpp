#include <globaldefs.h>
#include "std_library_functions.h"

int StringLength_020d2ff0(const char* s);
extern "C" int func_02001aec(void* a, void* b, int n);

extern char data_020f2dc8;
extern char data_020f2dcb;
extern char data_020f2dcf;

// USA: func_020e462c
extern "C" ARM char* func_020e462c(char* dst, char* str, char* fmt) {
    if (str != 0 && *str != 0) {
        dst += sprintf(dst, &data_020f2dc8, str);
        int flag;
        if (str == 0) goto setFlag1;
        {
            int len = StringLength_020d2ff0(str);
            if (len <= 3) goto setFlag1;
            flag = func_02001aec(str + (len - 3), &data_020f2dcb, 3);
            goto flagDone;
        }
    setFlag1:
        flag = 1;
    flagDone:
        if (flag != 0) {
            dst += sprintf(dst, &data_020f2dcf);
        }
    }
    dst += sprintf(dst, fmt);
    return dst;
}
