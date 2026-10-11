#include <globaldefs.h>

extern char data_020fe9cc;

// USA: func_0202ad4c
extern "C" ARM void func_0202ad4c(int a, int b, int c, char* buf) {
    int i = a;
    while (*buf != 0) {
        *(unsigned short*)((&data_020fe9cc + (b << 6)) + i * 2) =
            (unsigned short)(signed char)*buf | (unsigned short)(c << 12);
        i++;
        if (i >= 0x100) {
            return;
        }
        buf = buf + 1;
    }
}