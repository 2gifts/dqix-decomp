#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov031_02218528(void* obj, void* a, void* b);
int VariadicForward020c7170(int a, int b, int c, ...);

extern int data_ov031_02249de4;
extern int data_ov031_02249df0;
extern char data_ov031_02249df8;
extern int data_ov031_02249e00;
extern int data_ov031_02249e04;

// USA: func_ov031_02217d1c
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02217d1c(void* obj) {
    if (func_ov031_02218528(obj, &data_ov031_02249de4, &data_ov031_02249df0) != 0) {
        return 1;
    }
    char* found = strstr(*(char**)((char*)obj + 0x1000 + 0x9f8), &data_ov031_02249df8);
    int len = strlen(found + 4);
    if (len != 0) {
        char buf[8];
        VariadicForward020c7170((int)buf, 7, (int)&data_ov031_02249e00, len);
        if (func_ov031_02218528(obj, &data_ov031_02249e04, buf) != 0) {
            return 1;
        }
    }
    return 0;
}
