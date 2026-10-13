#include <globaldefs.h>

struct Node021d6148 { unsigned int type; Node021d6148* link; };
void SetLinkIfType3_021d6148(Node021d6148* o, unsigned int v);
typedef void (*SetLinkFloatFn021d6148)(Node021d6148*, float);

extern "C" float func_ov017_021d6110(void*);
extern "C" double func_02009598(double, double);

// USA: func_ov001_0215af8c  (semantic: Func_0215af8c)
extern "C" ARM int func_ov001_0215af8c(void* obj) {
    float a = func_ov017_021d6110(obj);
    float b = func_ov017_021d6110((char*)obj + 0x8);
    double da = (double)a;
    double db = (double)b;
    float c = (float)func_02009598(da, db);
    ((SetLinkFloatFn021d6148)SetLinkIfType3_021d6148)((Node021d6148*)((char*)obj + 0x10), c);
    return 1;
}
