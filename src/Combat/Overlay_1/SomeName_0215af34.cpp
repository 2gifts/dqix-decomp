#include <globaldefs.h>

struct Node021d6148 { unsigned int type; Node021d6148* link; };
void SetLinkIfType3_021d6148(Node021d6148* o, unsigned int v);
typedef void (*SetLinkFloatFn021d6148)(Node021d6148*, float);

extern "C" float func_ov017_021d6110(void*);
extern "C" double func_02009424(double);

// USA: func_ov001_0215af34  (semantic: SomeName_0215af34)
extern "C" ARM int func_ov001_0215af34(void* obj) {
    float a = func_ov017_021d6110(obj);
    float c = (float)func_02009424((double)(a));
    ((SetLinkFloatFn021d6148)SetLinkIfType3_021d6148)((Node021d6148*)((char*)obj + 0x8), c);
    return 1;
}
