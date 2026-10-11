#include <globaldefs.h>

int FindFirstDigitAndParse(signed char* s);
extern "C" int _Z28FormatAbsIntToString02042658Pvi(void* obj, int value);
extern "C" int sprintf(char* buf, const char* fmt, ...);

extern char data_020f08df;
extern char data_020f08e8;
extern char data_020f08f1;

struct Msg02068238 {
    char pad[0x8b0];
    int args[0x10];
    unsigned char pad1;
    unsigned char mode[0x10];
    unsigned char pad2;
    unsigned char flag[0x10];
};

// USA: func_02068238
extern "C" ARM void func_02068238(signed char* s, char** buf, struct Msg02068238* m) {
    int idx = FindFirstDigitAndParse(s) - 1;
    int val = m->args[idx];
    unsigned char flag = m->flag[idx];
    unsigned char mode = m->mode[idx];
    if (flag != 0) {
        int w = (flag << 3) - _Z28FormatAbsIntToString02042658Pvi(0, val);
        switch (mode) {
            case 0:
                *buf += sprintf(*buf, &data_020f08df, val, w);
                break;
            case 1:
                *buf += sprintf(*buf, &data_020f08e8, w, val);
                break;
            default:
                *buf += sprintf(*buf, &data_020f08f1, val);
                break;
        }
    } else {
        *buf += sprintf(*buf, &data_020f08f1, val);
    }
}
