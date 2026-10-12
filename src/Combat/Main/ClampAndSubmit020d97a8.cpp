#include <globaldefs.h>

#if defined(jpn)
#define data_020f280c data_020f29c8
#define data_020f2800 data_020f29bc
#endif

struct ProcessorContext;
int ClampInt020d9808(int* value, int* lo, int* hi);
extern "C" void _Z15PopulateContextP16ProcessorContextjjjjj(ProcessorContext*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

extern int data_020f280c;
extern int data_020f2800;

#if defined(jpn)
#define ClampAndSubmit020d97a8 func_020db1b4
extern "C" ARM int func_020db1b4(int a, int b, int c, int d, int e, int f);
#endif

// USA: _Z22ClampAndSubmit020d97a8iiiiii
ARM int ClampAndSubmit020d97a8(int a, int b, int c, int d, int e, int f) {
    int v = ClampInt020d9808(&d, &data_020f280c, &data_020f2800);
    int ip = v + 0x10;
    _Z15PopulateContextP16ProcessorContextjjjjj((ProcessorContext*)a, e, f, b + c, c, ip);
    return 1;
}
