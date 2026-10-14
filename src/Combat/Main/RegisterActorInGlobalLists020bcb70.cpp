#include <globaldefs.h>

int EnqueueEvent0x0C_020d1ee4(int a, int b, int c, int d);
struct NodeCEE54;
struct NodeCEE68;
void PrependToGlobalList02111804_020cef34(struct NodeCEE54*);
void AppendToGlobalList02111800_020cef4c(struct NodeCEE68*);

struct Actor020bcb70 {
    char pad0[8];
    char node54[0xc];
    char node68[0x10];
    int field24;
    char pad28[0x18];
    int field40;
    int field44;
};

// USA: func_020bcb70
ARM void RegisterActorInGlobalLists020bcb70(struct Actor020bcb70* obj) {
    EnqueueEvent0x0C_020d1ee4(obj->field44, 0, 1 << obj->field40, 0);
    if ((obj->field24 << 30) >> 31) return;
    PrependToGlobalList02111804_020cef34((struct NodeCEE54*)&obj->node54);
    AppendToGlobalList02111800_020cef4c((struct NodeCEE68*)&obj->node68);
    obj->field24 |= 2;
}
