#include <globaldefs.h>

struct List0208d994;

struct ElemFields0208dac4 {
    char pad[0x10];
    int w10;
    int w14;
};

extern struct ElemFields0208dac4* FindElementByKey0208d994(struct List0208d994* l, int key);

// USA: func_0208dac4
ARM int GetElementField0x10ByKey_0208dac4(struct List0208d994* l, int key) {
    struct ElemFields0208dac4* e = FindElementByKey0208d994(l, key);
    return e ? e->w10 : 0;
}
