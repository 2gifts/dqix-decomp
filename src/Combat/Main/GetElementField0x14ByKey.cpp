#include <globaldefs.h>

struct List0208d994;

struct ElemFields0208dadc {
    char pad[0x14];
    int w14;
};

extern struct ElemFields0208dadc* FindElementByKey0208d994(struct List0208d994* l, int key);

// USA: func_0208dadc
ARM int GetElementField0x14ByKey_0208dadc(struct List0208d994* l, int key) {
    struct ElemFields0208dadc* e = FindElementByKey0208d994(l, key);
    return e ? e->w14 : 0;
}
