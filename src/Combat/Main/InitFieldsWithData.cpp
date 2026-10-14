#include <globaldefs.h>

extern int data_020e91c8;
struct Fields020b1d48;
void InitFields020b1d48(struct Fields020b1d48*, int, int, int, int, int, int);

// USA: func_020b1e94
ARM void InitFieldsWithData_020b1e94(struct Fields020b1d48* s, int a, int b, int c, int d) {
    InitFields020b1d48(s, a, b, c, d, (int)&data_020e91c8, b);
}
