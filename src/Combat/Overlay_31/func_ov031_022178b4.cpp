#include <globaldefs.h>
#include "std_library_functions.h"

int VariadicForward020c7170(int a, int b, int c, ...);
extern "C" int func_ov031_02218604(void* obj, void* key, void* val, int len);
extern "C" int func_ov031_02218528(void* obj, void* key, void* val);
extern "C" int func_02005aa8(void* s);

extern int data_ov031_02249cd4;
extern int data_ov031_02249ce0;
extern int data_ov031_02249ce8;
extern int data_ov031_02249cf0;
extern int data_ov031_02249cf8;
extern int data_ov031_02249d00;
extern int data_ov031_02249d08;
extern int data_ov031_02249d10;
extern int data_ov031_02249d18;
extern int data_ov031_02249d20;
extern int data_ov031_02249d28;
extern int data_ov031_02249d30;
extern int data_ov031_02249d38;
extern int data_ov031_02249d40;
extern int data_ov031_02249d48;
extern int data_ov031_02249d50;
extern int data_ov031_02249d68;
extern int data_ov031_02249d74;

// USA: func_ov031_022178b4  (semantic: ValidateEntryFields_022178b4)
#pragma opt_common_subs off
#pragma optimize_for_size off
extern "C" ARM int func_ov031_022178b4(void* obj, char* str, int flag) {
    char buf[0x24];
    VariadicForward020c7170((int)buf, 0x21, (int)&data_ov031_02249cd4, 0x3, 1);
    if (func_ov031_02218604(obj, &data_ov031_02249ce0, buf, strlen(buf)) != 0) return 0;
    if (func_ov031_02218604(obj, &data_ov031_02249ce8, str, strlen(str)) != 0) return 0;
    if (func_ov031_02218604(obj, &data_ov031_02249cf0, str+0xe, strlen(str+0xe)) != 0) return 0;
    if (func_ov031_02218604(obj, &data_ov031_02249cf8, str+0x41, strlen(str+0x41)) != 0) return 0;
    if (func_ov031_02218604(obj, &data_ov031_02249d00, str+0x6f, strlen(str+0x6f)) != 0) return 0;
    if (func_ov031_02218604(obj, &data_ov031_02249d08, str+0x15, strlen(str+0x15)) != 0) return 0;
    if (func_ov031_02218604(obj, &data_ov031_02249d10, str+0x1a, strlen(str+0x1a)) != 0) return 0;
    if (func_ov031_02218604(obj, &data_ov031_02249d18, str+0x1d, strlen(str+0x1d)) != 0) return 0;
    if (func_ov031_02218604(obj, &data_ov031_02249d20, str+0x1f, strlen(str+0x1f)) != 0) return 0;
    if (func_ov031_02218604(obj, &data_ov031_02249d28, str+0x2c, strlen(str+0x2c)) != 0) return 0;
    if (func_ov031_02218604(obj, &data_ov031_02249d30, str+0x2f, strlen(str+0x2f)) != 0) return 0;
    if (func_ov031_02218604(obj, &data_ov031_02249d38, str+0x34, strlen(str+0x34)) != 0) return 0;
    if (func_ov031_02218604(obj, &data_ov031_02249d40, str+0x7e, func_02005aa8(str+0x7e)*2) != 0) return 0;
    if (flag == 1) {
        if (func_ov031_02218604(obj, &data_ov031_02249d48, str+0x4e, strlen(str+0x4e)) != 0) return 0;
    }
    VariadicForward020c7170((int)buf, 0x21, (int)&data_ov031_02249d50, 0x3, 1);
    if (func_ov031_02218528(obj, &data_ov031_02249d68, buf) != 0) return 0;
    return func_ov031_02218528(obj, &data_ov031_02249d74, str+0x15) == 0;
}
